#include "CommonTypes.h"
#include "ReqTypes.h"
#include "ModelFormat.h"
#include "VivaClassTypes.h"

struct sceneLookAt_s;
struct cursorTargetList_s;
struct cursorMainWorkspace_s;
struct cursorControls_s;
struct cursorCamera_s;
struct cursorTarget_s;
////////////////////////////////////////
/* 55 */
enum cursorMarkerMode_e : uint32_t
{
  cursorMarkerMode_BrandSpankingNew = 0x0,
  cursorMarkerMode_Combined = 0x1,
  cursorMarkerMode_Place = 0x2,
  cursorMarkerMode_Carry = 0x3,
  cursorMarkerMode_Outer = 0x4,
  cursorMarkerMode_HeadCam = 0x5,
  cursorMarkerMode_MindMeld = 0x6,
  cursorMarkerMode_Hijacked = 0x7,
  cursorMarkerMode_Processing = 0x8,
  cursorMarkerMode_Accessory = 0x9,
  cursorMarkerMode_BuyFromShop = 0xA,
  cursorMarkerMode_SellToShop = 0xB,
  cursorMarkerMode_FertiliserFromShop = 0xC,
  cursorMarkerMode_DeliverCrate = 0xD,
  cursorMarkerMode_PackCrate = 0xE,
  cursorMarkerMode_UnpackCrate = 0xF,
  cursorMarkerMode_UnpackCrateRemote = 0x10,
  cursorMarkerMode_CallOut = 0x11,
  cursorMarkerMode_SelectAccessoryAnimal = 0x12,
  cursorMarkerMode_Frontend = 0x13,
  cursorMarkerMode_ShuttingDown = 0x14,
  cursorMarkerMode_MAX = 0x15,
};

inline std::string GetCursorModeString(cursorMarkerMode_e mode) {
  switch (mode)
  {
  case cursorMarkerMode_BrandSpankingNew: return "Brand Spanking New";
  case cursorMarkerMode_Combined: return "Combined";
  case cursorMarkerMode_Place: return "Place";
  case cursorMarkerMode_Carry: return "Carry";
  case cursorMarkerMode_Outer: return "Outer";
  case cursorMarkerMode_HeadCam: return "Head Cam";
  case cursorMarkerMode_MindMeld: return "Mind Meld";
  case cursorMarkerMode_Hijacked: return "Hijacked";
  case cursorMarkerMode_Processing: return "Processing";
  case cursorMarkerMode_Accessory: return "Accessory";
  case cursorMarkerMode_BuyFromShop: return "Buy From Shop";
  case cursorMarkerMode_SellToShop: return "Sell To Shop";
  case cursorMarkerMode_FertiliserFromShop: return "Fertiliser From Shop";
  case cursorMarkerMode_DeliverCrate: return "Deliver Crate";
  case cursorMarkerMode_PackCrate: return "Pack Crate";
  case cursorMarkerMode_UnpackCrate: return "Unpack Crate";
  case cursorMarkerMode_UnpackCrateRemote: return "Unpack Crate Remote";
  case cursorMarkerMode_CallOut: return "Call Out";
  case cursorMarkerMode_SelectAccessoryAnimal: return "Select Accessory Animal";
  case cursorMarkerMode_Frontend: return "Frontend";
  case cursorMarkerMode_ShuttingDown: return "Shutting Down";
  case cursorMarkerMode_MAX: return "Max";
  default: return "Unknown";
  }
  return "Unknown";
};

/* 52 */
struct cursorInst_s;

/* 49 */
struct avatarInst_s;

/* 56 */
struct cursorMarker_s_unnamed_tag
{
  avatarInst_s *inner;
  avatarInst_s *outer;
};

/* 57 */
enum actionInterfaceId_e : __int32
{
  actionInterfaceId_Buy = 0x0,
  actionInterfaceId_Crate = 0x1,
  actionInterfaceId_PickedUp = 0x2,
  actionInterfaceId_Selected = 0x3,
  actionInterfaceId_Sell = 0x4,
  actionInterfaceId_Stores = 0x5,
  actionInterfaceId_Directed = 0x6,
  actionInterfaceId_Talk = 0x7,
  actionInterfaceId_HeadCam = 0x8,
  actionInterfaceId_MindMeld = 0x9,
  actionInterfaceId_ShopBuy = 0xA,
  actionInterfaceId_ShopSell = 0xB,
  actionInterfaceId_StartGame = 0xC,
  actionInterfaceId_PostOffice = 0xD,
  actionInterfaceId_Doctor = 0xE,
  actionInterfaceId_Tinker = 0xF,
  actionInterfaceId_Accessory = 0x10,
  actionInterfaceId_CrateUnpack = 0x11,
  actionInterfaceId_Spare19 = 0x12,
  actionInterfaceId_Spare20 = 0x13,
  actionInterfaceId_MAX = 0x14,
};

/* 53 */
struct ShopDisplayBox;

/* 51 */
struct scenePathObject_s;

/* 58 */
struct pinatajuiceFloatIconsUnit_s
{
  dbTexture_s *texture;
  float alpha;
};

/* 59 */
enum pinatajuiceFloatIcon_e : uint32_t
{
  pinatajuiceFloatIcon_NULL = 0xFFFFFFFF,
  pinatajuiceFloatIcon_happy = 0x0,
  pinatajuiceFloatIcon_angry = 0x1,
  pinatajuiceFloatIcon_dizzy = 0x2,
  pinatajuiceFloatIcon_sad = 0x3,
  pinatajuiceFloatIcon_sleepy = 0x4,
  pinatajuiceFloatIcon_sick = 0x5,
  pinatajuiceFloatIcon_randy = 0x6,
  pinatajuiceFloatIcon_heartbroken = 0x7,
  pinatajuiceFloatIcon_overjoyedsweet = 0x8,
  pinatajuiceFloatIcon_doctor = 0x9,
  pinatajuiceFloatIcon_weeder = 0xA,
  pinatajuiceFloatIcon_waterer = 0xB,
  pinatajuiceFloatIcon_groundskeeper = 0xC,
  pinatajuiceFloatIcon_groundskeepernight = 0xD,
  pinatajuiceFloatIcon_harvester = 0xE,
  pinatajuiceFloatIcon_builder = 0xF,
  pinatajuiceFloatIcon_beggar = 0x10,
  pinatajuiceFloatIcon_miner = 0x11,
  pinatajuiceFloatIcon_professor = 0x12,
  pinatajuiceFloatIcon_tinker = 0x13,
  pinatajuiceFloatIcon_tinkerbronze = 0x14,
  pinatajuiceFloatIcon_tinkersilver = 0x15,
  pinatajuiceFloatIcon_tinkergold = 0x16,
  pinatajuiceFloatIcon_costolot = 0x17,
  pinatajuiceFloatIcon_hunter = 0x18,
  pinatajuiceFloatIcon_postoffice = 0x19,
  pinatajuiceFloatIcon_inn = 0x1A,
  pinatajuiceFloatIcon_petshop = 0x1B,
  pinatajuiceFloatIcon_trader = 0x1C,
  pinatajuiceFloatIcon_crate = 0x1D,
  pinatajuiceFloatIcon_MAX = 0x1E,
};

/* 60 */
struct pinatajuiceFloatIcons_s_unnamed_tag
{
  int inMateMinigame;
  float fadeSpeed;
};

/* 61 */
struct pinatajuiceFloatIcons_s
{
  pinatajuiceFloatIconsUnit_s units[33];
  pinatajuiceFloatIcon_e highestPriority;
  pinatajuiceFloatIcon_e prevHighestPriority;
  int fadesHaveCompleted;
  pinatajuiceFloatIcons_s_unnamed_tag mateMinigame;
};

/* 54 */
struct entitySceneControlPinataFrontendInst_s;

/* 62 */
struct cursorMarker_s
{
  cursorMarkerMode_e mode;
  cursorInst_s *cursor;
  int enabled;
  int hidden;
  int spinTokens;
  float alpha;
  cursorMarker_s_unnamed_tag token;
  unsigned char sfx[256];
  unsigned char place[308];
  unsigned char callOut[152];
  unsigned char processing[24];
  float pickUpHeight;
  actionInterfaceId_e interfaceType;
  unsigned char accessory[24];
  int rotating;
  int talkingToTarget;
  ShopDisplayBox *shopDisplayBox;
  unsigned int icon;
  unsigned int starMenu;
  float nonMovingTimer;
  scenePathObject_s *pickedUpPathObject;
  cursorMarker_s_unnamed_tag crate;
  unsigned int digitalObjectIndex;
  pinatajuiceFloatIcons_s floatIcon;
  entitySceneControlPinataFrontendInst_s *frontend;
};


////////////////////////////////////////
struct cursorSurfaceMonitorInst_s;
struct cursorCookieCutterInst_s;

/* 1012 */
enum cursorMode_e : __int32
{
  cursorMode_Idle = 0x0,
  cursorMode_Tool_Using = 0x1,
  cursorMode_Tool_Opening = 0x2,
  cursorMode_Actor_MindMeld = 0x3,
  cursorMode_Actor_Headcam = 0x4,
  cursorMode_Garden_BirdsEyeView = 0x5,
  cursorMode_Garden_Boundary_Crossing = 0x6,
  cursorMode_Garden_Boundary_Crossed = 0x7,
  cursorMode_Garden_Boundary_Crossed_BirdsEyeView = 0x8,
  cursorMode_MAX = 0x9,
};

inline std::string GetCursorModeString(cursorMode_e mode) {
  switch (mode)
  {
  case cursorMode_Idle: return "Idle";
  case cursorMode_Tool_Using: return "Tool Using";
  case cursorMode_Tool_Opening: return "Tool Opening";
  case cursorMode_Actor_MindMeld: return "Actor MindMeld";
  case cursorMode_Actor_Headcam: return "Actor Headcam";
  case cursorMode_Garden_BirdsEyeView: return "Garden BirdsEyeView";
  case cursorMode_Garden_Boundary_Crossing: return "Garden Boundary Crossing";
  case cursorMode_Garden_Boundary_Crossed: return "Garden Boundary Crossed";
  case cursorMode_Garden_Boundary_Crossed_BirdsEyeView: return "Garden Boundary Crossed BirdsEyeView";
  case cursorMode_MAX: return "Max";
  default: return "Unknown";
    }
    return "Unknown";
};

/* 12403 */
struct cursorNetSyncInst_s
{
  mlVec originalPos;
  mlVec wantedPos;
  mlVec overshootPos;
};

/* 12428 */
struct cursorArea_s
{
  mlVec vertices[50];
  unsigned int numVertices;
};

/* 1013 */
enum cursorLock_e : __int32
{
  cursorLock_None = 0x0,
  cursorLock_Position = 0x1,
  cursorLock_DontSuck = 0x2,
  cursorLock_ForceSuck = 0x4,
  cursorLock_Camera_All = 0x10,
  cursorLock_Camera_Yaw = 0x20,
  cursorLock_Camera_Pitch = 0x40,
  cursorLock_Camera_Zoom = 0x80,
  cursorLock_Camera_Position = 0x100,
  cursorLock_BirdsEye = 0x200,
  cursorLock_StartMenu = 0x400,
  cursorLock_MAX = 0xFFFF,
};

/* 11889 */
struct assetDbPackageManagerLoadUnit_s_unnamed_tag
{
  unsigned int acksRemaining;
  float timer;
  char initiatingPlayer;
  unsigned int addressOnInitiator;
  int notifiedInitiatorOfLoadComplete;
};

/* 12442 */
struct cursorInst_s_unnamed_tag
{
  int states[13];
};

/* 11716 */
struct objTagDb_s
{
  char text[64];
};

/* 11892 */
struct gameIdParams_s
{
  int useParams;
  int createdLocally;
  gameIdComplete_s id;
};

/* 11893 */
struct objNetSyncPropertiesAsset_s
{
  unsigned int properties;
};

/* 11894 */
struct objNetSyncDirtyFlagAsset_s
{
  unsigned int dirtyFlags;
};

/* 11895 */
struct objNetSyncDOPropertiesAsset_s
{
  unsigned int properties;
};

/* 11896 */
struct objNetSyncParams_s
{
  objNetSyncPropertiesAsset_s properties;
  objNetSyncDirtyFlagAsset_s dirtyFlags;
  objNetSyncDOPropertiesAsset_s doproperties;
  float updateDelayTimerDefault;
  float updateForcedTimerDefault;
};

/* 11897 */
struct objParams_s
{
  unsigned __int16 size;
  objTagDb_s tag;
  char classId[64];
  sceneMainWorkspace_s *scene;
  assetId_s objParamsAid;
  gameIdParams_s idParams;
  objNetSyncParams_s netSyncParams;
};

/* 12443 */
struct sceneControlNetSyncParams_s
{
  int type;
};

/* 12444 */
struct sceneControlObjParams_s
{
  objParams_s __objParameters;
  sceneControlNetSyncParams_s netSyncParams;
  int disablePause;
  int disableNoControllerTest;
  int disableScreenSaver;
  int disableSerialisation;
};

/* 990 */
enum cursorControlsType_e : __int32
{
  cursorControlsType_Advanced = 0x0,
  cursorControlsType_Basic = 0x1,
  cursorControlsType_MAX = 0x2,
};

/* 12445 */
struct cursorParams_s_unnamed_tag
{
  float clamp;
  float sector;
  float snapDistance;
};

/* 12446 */
struct __declspec(align(4)) cursorParams_s
{
  sceneControlObjParams_s __sceneControlObjParameters;
  cursorControlsType_e controls;
  assetId_s cameraAid;
  assetId_s targetAid;
  assetId_s markerAid;
  cursorParams_s_unnamed_tag suck;
  unsigned char move[4];
  unsigned char turbo[8];
  unsigned char tool[64];
  unsigned char pushout[8];
  unsigned char frontend[8];
  int couchSocial;
  char couchSocialPlayerIndex;
};

/* 12400 */
struct __declspec(align(4)) cursorInst_s
{
  sceneControlObjInst_s __sceneControlObjInstance;
  cursorMainWorkspace_s *workspace;
  cursorMode_e mode;
  char owner;
  cursorNetSyncInst_s netsync;
  cursorControls_s *controls;
  cursorCamera_s *camera;
  cursorTarget_s *target;
  cursorMarker_s *marker;
  cursorArea_s area;
  cursorSurfaceMonitorInst_s *surfaceMonitor;
  cursorCookieCutterInst_s *cookieCutter;
  cursorLock_e locks;
  dsList2_s lockStack;
  cursorTargetList_s *avatarList;
  float timer;
  avatarInst_s *attachedTo;
  avatarInst_s *lastTarget;
  sceneLookAt_s *lookAt;
  unsigned int hijackRefCount;
  int _firstTickBodge;
  int hasPushedPad;
  int couchSocial;
  assetDbPackageManagerLoadUnit_s asyncToolLoadUnit[4];
  cursorInst_s_unnamed_tag deflect;
  unsigned char position[24];
  unsigned char rotation[24];
  unsigned char suck[12];
  unsigned char move[20];
  unsigned char turbo[12];
  unsigned char tool[104];
  unsigned char action[16];
  unsigned char frontend[4];
  cursorParams_s _params;
  netDeadReckoningInst_s deadReckoning;
};

/* 12400 */
struct re_cursorInst_s
{
  unsigned char unk1[224];
  cursorMarker_s *marker;
};



