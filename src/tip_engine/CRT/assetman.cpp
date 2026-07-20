#include "crt.h"

#include <rex/filesystem.h>
#include <rex/mods.h>
#include "../Log.h"


REXCVAR_DEFINE_BOOL(DumpData, true, "MODS/Data", "Dump Data");
REXCVAR_DEFINE_BOOL(InjectData, true, "MODS/Data", "Inject Data");

REX_EXTERN(__imp__rex_statsCommonGetStatsAidFromTag_821D1890);
REX_EXTERN(__imp__rex_meLoadAsset_821D2120);
REX_EXTERN(__imp__rex_appErrorReportDirtyDisk_821C4C48);
REX_EXTERN(__imp__rex_meSectionVirtualAlloc_821D29C8);

thread_local uint32_t g_lastOpenedAssetVirtualSize = 0;

static std::unordered_map<std::string, uint32_t> g_modGuestAddrs;
static std::mutex g_modAllocMutex;

static const std::vector<std::filesystem::path>& GetDataModDirs() {
    static const std::vector<std::filesystem::path> dirs = [] {
        std::filesystem::path modsDataRoot = REXCVAR_GET(mods_data_root);
        if (modsDataRoot.empty()) { modsDataRoot = rex::filesystem::GetExecutableFolder() / "mods"; }
        std::vector<std::filesystem::path> result;
        for (const auto& modDir : rex::GetEnabledModDirs(modsDataRoot)) {
            result.push_back(modDir / "data");
        }
        return result;
    }();
    return dirs;
}

REX_HOOK_RAW(rex_assetManOpen_821D1C10) {
    const uint32_t aidGuestAddr = ctx.r3.u32;

    if (memcmp(base + aidGuestAddr, "aid_", 4) != 0) {
        ctx.r3.u32 = 0;
        return;
    }

    constexpr uint32_t kFrameSize = 0xE0;
    const uint32_t savedSP = ctx.r1.u32;
    ctx.r1.u32 -= kFrameSize;
    const uint32_t unitPtrAddr = ctx.r1.u32 + 0x50;
    const uint32_t aid1Addr    = ctx.r1.u32 + 0x58;

    *reinterpret_cast<uint32_t*>(base + ctx.r1.u32) = std::byteswap(savedSP);
    *reinterpret_cast<uint32_t*>(base + unitPtrAddr) = 0;

    ctx.r3.u32 = aidGuestAddr;
    ctx.r4.u32 = aid1Addr;
    __imp__rex_statsCommonGetStatsAidFromTag_821D1890(ctx, base);

    ctx.r3.u32 = aid1Addr;
    ctx.r4.u32 = unitPtrAddr;
    ctx.r5.u32 = 0;
    ctx.r6.u32 = 0;
    __imp__rex_meLoadAsset_821D2120(ctx, base);

    const uint32_t unitGuestAddr = std::byteswap(*reinterpret_cast<uint32_t*>(base + unitPtrAddr));

    ctx.r1.u32 = savedSP;

    if (!unitGuestAddr) {
        Log(LogLevel::Error, "assetManOpen: failed to find asset");
        ctx.r3.u32 = 2;
        __imp__rex_appErrorReportDirtyDisk_821C4C48(ctx, base);
        ctx.r3.u32 = 0;
        return;
    }

    const uint32_t dbAssetGuestAddr = std::byteswap(*reinterpret_cast<uint32_t*>(base + unitGuestAddr + 8));

    // virtualData at +0, virtualSize at +4
    const uint32_t virtualData = std::byteswap(*reinterpret_cast<uint32_t*>(base + dbAssetGuestAddr + 0));
    const uint32_t virtualSize = std::byteswap(*reinterpret_cast<uint32_t*>(base + dbAssetGuestAddr + 4));

    g_lastOpenedAssetVirtualSize = virtualSize;

    const char* aidText = reinterpret_cast<const char*>(base + aidGuestAddr);
    const std::string aidStr(aidText);
    static const std::filesystem::path kDumpDir = "dumps/data";
    static std::once_flag s_dumpDirCreated;
    std::call_once(s_dumpDirCreated, []{ std::filesystem::create_directories("dumps/data"); });

    if (REXCVAR_GET(DumpData)) {
      const std::filesystem::path dumpPath = kDumpDir / (aidStr + ".vdat");
      if (!std::filesystem::exists(dumpPath)) {
        if (std::ofstream ofs(dumpPath, std::ios::binary); ofs) {
          ofs.write(reinterpret_cast<const char*>(base + virtualData), virtualSize);
        }
        }
    }

    uint32_t outVirtualData = virtualData;
    if (REXCVAR_GET(InjectData)) {
      const std::string vdatName = aidStr + ".vdat";
      std::filesystem::path modPath;
      for (const auto& dir : GetDataModDirs()) {
        auto candidate = dir / vdatName;
        if (std::filesystem::exists(candidate)) { modPath = std::move(candidate); break; }
      }
      if (!modPath.empty()) {
        const auto modFileSize = static_cast<uint32_t>(std::filesystem::file_size(modPath));
        if (modFileSize <= virtualSize) {
          // overwrite guest buffer and shrink virtualSize in guest dbAsset
          if (std::ifstream ifs(modPath, std::ios::binary); ifs) {
            ifs.read(reinterpret_cast<char*>(base + virtualData), modFileSize);
            *reinterpret_cast<uint32_t*>(base + dbAssetGuestAddr + 4) = std::byteswap(modFileSize);
            g_lastOpenedAssetVirtualSize = modFileSize;
          }
        } else {
          // Mod is larger than the original, allocate from the runtime system heap.
          uint32_t guestAddr = 0;
          {
            std::lock_guard<std::mutex> lk(g_modAllocMutex);
            auto it = g_modGuestAddrs.find(aidStr);
            if (it != g_modGuestAddrs.end()) {
              guestAddr = it->second;
            } else {
              // Call the game's own meSectionVirtualAlloc(size) to get a valid guest ptr.
              ctx.r3.u32 = modFileSize;
              __imp__rex_meSectionVirtualAlloc_821D29C8(ctx, base);
              guestAddr = ctx.r3.u32;
              if (guestAddr) {
                g_modGuestAddrs.emplace(aidStr, guestAddr);
              }
            }
          }
          if (guestAddr) {
            if (std::ifstream ifs(modPath, std::ios::binary); ifs) {
              ifs.read(reinterpret_cast<char*>(base + guestAddr), modFileSize);
              *reinterpret_cast<uint32_t*>(base + dbAssetGuestAddr + 0) = std::byteswap(guestAddr);
              *reinterpret_cast<uint32_t*>(base + dbAssetGuestAddr + 4) = std::byteswap(modFileSize);
              g_lastOpenedAssetVirtualSize = modFileSize;
              outVirtualData = guestAddr;
            }
          }
        }
        }
    }

    ctx.r3.u32 = outVirtualData;
}
