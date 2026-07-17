#include "crt.h"
#include <cstdint>

inline float to_byteswapped_float(float f) {
    uint32_t i = std::byteswap(*reinterpret_cast<uint32_t*>(&f));
    return *reinterpret_cast<float*>(&i);
}

inline double to_byteswapped_double(double d) {
    uint64_t i = std::byteswap(*reinterpret_cast<uint64_t*>(&d));
    return *reinterpret_cast<double*>(&i);
}

struct dbTriHit_s;
struct dbMirror_s;
struct dbModelTextureUnit_s;
struct dbMoldGeometry_s;
struct dbModelClimbPole_s;
struct dbExtent_s;
struct dbModelJoint_s;
struct dbLight_s;
struct dbLightVolume_s;
struct dbLocator_s;
struct dbScenegraph_s;
struct dbVolume_s;
struct dbModelSwitch_s;

/* 11805 */
struct dbModelRuntime_s
{
  dbTriHit_s *trihits;
  dbMirror_s *mirror;
  struct sgGraph *sg;
  dbModelTextureUnit_s *texpalette;
  struct dbShadowGeometry_s *shadowGeometry;
  dbMoldGeometry_s *moldGeometry;
  const dbModelClimbPole_s *climbPoles;
  const dbExtent_s *extent;
  const dbModelJoint_s *joint;
  const dbLight_s *light;
  const dbLightVolume_s *lightVolume;
  const dbLocator_s *locator;
  const dbScenegraph_s *sceneGraph;
  const dbVolume_s *volume;
  const dbModelSwitch_s *switchMask;
};

/* 1582 */
enum dbModelUnitId_e : uint32_t
{
  dbModelUnitId_Scenegraph = 0x0,
  dbModelUnitId_UNUSED_1 = 0x1,
  dbModelUnitId_Locator = 0x2,
  dbModelUnitId_Light = 0x3,
  dbModelUnitId_Volumes = 0x4,
  dbModelUnitId_Extents = 0x5,
  dbModelUnitId_TriHits = 0x6,
  dbModelUnitId_Textures = 0x7,
  dbModelUnitId_Joints = 0x8,
  dbModelUnitId_AStar = 0x9,
  dbModelUnitId_GardenSetup = 0xA,
  dbModelUnitId_Mirrors = 0xB,
  dbModelUnitId_HeatHaze = 0xC,
  dbModelUnitId_AStarLayer2 = 0xD,
  dbModelUnitId_AStarBreakConnectionLayer1 = 0xE,
  dbModelUnitId_AStarBreakConnectionLayer2 = 0xF,
  dbModelUnitId_ShadowGeometry = 0x10,
  dbModelUnitId_LightVolumes = 0x11,
  dbModelUnitId_ClimbPoles = 0x12,
  dbModelUnitId_MoldGeometry = 0x13,
  dbModelUnitId_HavokData = 0x14,
  dbModelUnitId_VertexPath = 0x15,
  dbModelUnitId_HavokMopp = 0x16,
  dbModelUnitId_HavokMesh = 0x17,
  dbModelUnitId_SwitchMaskNew = 0x18,
  dbModelUnitId_VehicleSkinGeometry = 0x19,
  dbModelUnitId_MAX = 0x1A,
};

/* 11779 */
struct dbModelUnit_s
{
  dbModelUnitId_e id;
  void *data;
};

/* 11806 */
struct dbModel_s
{
  dbModelUnit_s *units;
  unsigned int numUnits;
  unsigned int flags;
  unsigned int headerSize;
  dbModelRuntime_s *runtime;
};

//int __fastcall meInitModel(const dbModel_s *asset)
REX_HOOK_RAW(rex_meInitModel_821FB518){
    dbModel_s asset = reinterpret_cast<dbModel_s*>(0x100000000ull + ctx.r3.u32);
    __imp__rex_meInitModel_821FB518(ctx,base);
}