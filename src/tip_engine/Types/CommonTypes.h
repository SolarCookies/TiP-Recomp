#pragma once

/* 11684 */
struct assetId_s
{
	char text[128];
};

/* 746 */
struct assetDbPackageManagerWorkspace_s;

struct assetFile;
/* 635 */
struct tablesInfo
{
	unsigned int size;
	unsigned char* base;
	unsigned int overlap;
	unsigned int loadSize;
	unsigned int compressedSize;
};

/* 636 */
struct assetFileHeader
{
	char identifier[4];
	char versionString[16];
	unsigned int headerSize;
	unsigned int headerHash;
	unsigned int numAssets;
	unsigned int numSections;
	unsigned int numByteswapGroups;
	unsigned int numByteswaps;
	unsigned int numRelocationGroups;
	unsigned int numRelocations;
	unsigned int numMappedByteswapGroups;
	unsigned int numMappedByteswaps;
	unsigned int numMappedRelocationGroups;
	unsigned int numMappedRelocations;
	unsigned int numPoolItems;
	unsigned char byteswapFlags;
	unsigned char numSectionTypes;
	unsigned char compression;
	unsigned char numPools;
	unsigned int sectionTypeNamesBufferLen;
	tablesInfo tables[2];
};

/* 11661 */
struct vec3d
{
	float x;
	float y;
	float z;
};

/* 11729 */
struct mlV4
{
	float x;
	float y;
	float z;
	float w;
};

/* 11659 */
struct vec4d
{
	float x;
	float y;
	float z;
	float w;
};

/* 11660 */
struct mtx44
{
	float m00;
	float m10;
	float m20;
	float m30;
	float m01;
	float m11;
	float m21;
	float m31;
	float m02;
	float m12;
	float m22;
	float m32;
	float m03;
	float m13;
	float m23;
	float m33;
};

/* 11780 */
struct _ndGroup_s
{
	unsigned char type;
	unsigned char passMask;
	uint16_t id;
	_ndGroup_s* child;
	_ndGroup_s* sibling;
	_ndGroup_s* parent;
};

/* 11781 */
struct _ndVisGroup_s
{
	unsigned char type;
	unsigned char __pad;
	uint16_t targetNodeIdListSize;
	uint16_t* targetNodeIdList;
	_ndVisGroup_s* child;
	_ndVisGroup_s* sibling;
	_ndVisGroup_s* parent;
};

/* 637 */
struct __declspec(align(1)) DiffFileHeader
{
	char identifier[4];
	char patchVersion[16];
	char sectionVersion[16];
	unsigned int fileSize;
	unsigned int compressedSize;
	unsigned int numDiffs;
	unsigned int stringTableLen;
	unsigned int diffDataLen;
	unsigned char numSrcSectionTypes;
	unsigned char bigEndian;
	unsigned char compressed;
};

/* 638 */
struct DiffBlock
{
	unsigned char type;
	char* name;
	unsigned int sourceSize;
	unsigned int targetSize;
	unsigned int diffSize;
	unsigned int diffMargin;
	unsigned char* data;
};

/* 639 */
struct SectionLoadHeader
{
	char* filename;
	unsigned int sectorSize;
	unsigned int filePointer;
	int error;
	unsigned int loadFlags;
	void(__cdecl* callback)(assetFile*, const void*, int);
	void* userData;
};

/* 640 */
struct DiffFile
{
	SectionLoadHeader loadHeader;
	DiffFileHeader* header;
	assetFile* asset;
	const char* filename;
	unsigned char* sectionTypeMap;
	unsigned char** diffSourceData;
	DiffBlock* diffs;
	char* stringTable;
	unsigned char* diffData;
	unsigned int diffDataOverlap;
};

/* 641 */
struct __declspec(align(1)) blockInfo
{
	unsigned int nameOffset;
	unsigned char alignment;
	unsigned int poolSection;
	unsigned int size;
	unsigned char* base;
	unsigned int offset;
	unsigned int overlap;
	unsigned int loadSize;
	unsigned int compressedSize;
};

/* 642 */
struct __declspec(align(2)) _section
{
	unsigned int asset;
	unsigned char* start;
	unsigned int size;
	unsigned char sectionType;
	unsigned char startAlignment;
};

/* 643 */
struct _byteswapGroup
{
	unsigned int section;
	unsigned int count;
	unsigned int numItemsToByteswap;
	unsigned int size;
	unsigned int stride;
};

/* 644 */
struct _byteswap
{
	unsigned char* address;
};

/* 645 */
struct _relocationGroup
{
	unsigned int sourceSection;
	unsigned int destinationSection;
	unsigned int count;
};

/* 646 */
struct _relocation
{
	unsigned char* offsetFromSectionStart;
};

/* 602 */
struct __declspec(align(4)) assetFile
{
	SectionLoadHeader loadHeader;
	assetFileHeader* header;
	DiffFile* diffFile;
	void* diffUserReference;
	unsigned int symbolFileNameLength;
	const char* symbolFileName;
	blockInfo* allocationTable;
	char* sectionTypeNames;
	unsigned int stringBufferLength;
	unsigned int* stringBufferOffsetTable;
	char* stringBuffer;
	_section* sectionTable;
	_byteswapGroup* byteswapGroupTable;
	_byteswap* byteswapTable;
	_byteswapGroup* mappedByteswapGroupTable;
	_byteswap* mappedByteswapTable;
	_relocationGroup* relocationGroupTable;
	_relocation* relocationTable;
	_relocationGroup* mappedRelocationGroupTable;
	_relocation* mappedRelocationTable;
	unsigned int numUnprocessedAllocationBlocks;
	unsigned int numUnprocessedTables;
	int iteratorPosition;
	unsigned int poolAssetIndex;
	unsigned char dataSectionType;
	unsigned char lastUsedTable;
	unsigned char rawByteswapped;
	unsigned char mapByteswapped;
	unsigned char rawRelocated;
	unsigned char mapRelocated;
};

/* 592 */
struct dsLinkedListNode_s
{
	dsLinkedListNode_s* _prevPtr;
	dsLinkedListNode_s* _nextPtr;
};

/* 647 */
enum FS_IOMode : uint32_t
{
	FS_IDLE = 0x0,
	FS_BUSY = 0x1,
	FS_TERMINATE = 0x2,
};

/* 181 */
struct _OVERLAPPED_VP
{
	unsigned int Internal;
	unsigned int InternalHigh;
	unsigned int Offset;
	unsigned int OffsetHigh;
	void* hEvent;
};

/* 648 */
struct FSObject_s
{
	dsLinkedListNode_s link;
	void* handle;
	char name[260];
	FS_IOMode mode;
	_OVERLAPPED_VP overlapped;
	void(__cdecl* notifyComplete)(FSObject_s* const, int, void* const);
	void* notifyContext;
};

/* 597 */
struct __declspec(align(4)) dsList2_s
{
	char* base;
	char* top;
	char* max;
	uint16_t blockSize;
	uint16_t allocSize;
	uint16_t listSize;
};

/* 603 */
struct assetSectionFileLoadUnit_s
{
	FSObject_s* file;
	char* filename;
	void* memoryPointer;
	int suppressMemoryCheck;
	int(__cdecl* callback)(void*, void*, int);
	void* callbackReference;
	int runCallback;
	int error;
	int decompressCount;
	void* userContext;
	void* physAlloc;
	unsigned int physSize;
	unsigned int offset;
	dsList2_s asyncReadList;
	int doNotCloseFile;
	void* buffer;
	void* destination;
	unsigned int bufferSize;
	unsigned int dbId;
	void(__cdecl* completedCallback)(const void*, int);
};

/* 784 */
struct assetDbPackageManagerLoadUnit_sl
{
	unsigned int acksRemaining;
	float timer;
	char initiatingPlayer;
	unsigned int addressOnInitiator;
	int notifiedInitiatorOfLoadComplete;
};

/* 598 */
struct dsBinaryTreeNode_s
{
	dsBinaryTreeNode_s* lower;
	dsBinaryTreeNode_s* higher;
	unsigned int comparisonValue;
	uint32_t colour : 1;
	uint32_t dataValue : 31;
};

/* 593 */
struct dsMemoryContainerUnit_s
{
	dsLinkedListNode_s _node;
	unsigned int sizeAllocated;
	void* base;
	void* top;
};

/* 594 */
struct dsMemoryContainer_s
{
	dsMemoryContainerUnit_s firstUnit;
	dsMemoryContainerUnit_s* lastUnit;
	unsigned int allocSize;
	int alwaysClear;
};

/* 591 */
struct dsLinkedQueueNode_s;

/* 595 */
struct dsLinkedQueueSentinel_s
{
	dsLinkedQueueNode_s* first;
	dsLinkedQueueNode_s* last;
};

/* 596 */
struct dsPageList_s
{
	int blockSize;
	int numFreeBlocks;
	dsMemoryContainer_s memoryContainer;
	dsLinkedQueueSentinel_s freeListSentinel;
};

/* 599 */
struct dsBinaryTree_s
{
	dsBinaryTreeNode_s* rootNode;
	dsList2_s nodeStack;
	dsPageList_s nodeMemory;
};

/* 600 */
struct assetIdArray_s
{
	dsList2_s aidList;
	dsBinaryTree_s hashSortedTree;
	int isSortedAlphabetically;
	int keepUnsortedIndex;
};

/* 825 */
struct assetDPackageManagerBundleData_s
{
	assetFile* sectionAsset;
	unsigned int numberAssets;
	assetIdArray_s* aidList;
	unsigned int openedReferenceCount;
	unsigned int openedAssetCount;
	int loaded;
	int common;
	int bundleId;
	unsigned int timestamp;
	dsList2_s memoryList;
};



/* 785 */
struct assetDbPackageManagerLoadUnit_s
{
	assetDbPackageManagerWorkspace_s* workspace;
	int finishedLoading;
	int requiredPackageId;
	unsigned int bundlesLoaded;
	unsigned int bundlesRequired;
	unsigned int packageInfoIndex;
	FSObject_s* file;
	void* headerBuffer;
	dsList2_s requiredBundleList;
	assetFile* sectionAsset;
	assetSectionFileLoadUnit_s sectionLoadUnit;
	int loadingBundleId;
	int isCommon;
	int isLoading;
	unsigned int timestamp;
	unsigned int aidHash;
	int shouldFreeAutomatically;
	int serialiseLoad;
	assetDbPackageManagerLoadUnit_sl netsync;
};


//////////////////////////////////////////////////////////////////////////////////////

struct animEventUnit_s;
struct assetId_s;
struct animMixer_s;
struct padInfo_s;
struct sceneMainWorkspace_s;
struct dsList_s;
struct avatarInst_s;
struct dbLocator_s;
struct dbModel_s;
struct glModel_s;
struct dbLocatorUnit_s;
struct avatarThreadState_s;
struct objFunc_s;
struct avatarAttach_s;
struct avatarAnimManagerWorkspace_s;
struct animTable_s;
struct animJointMap_s;
struct dbCallout_CommonAndSize_s;
struct sceneObjDrawParams_s;
struct supportBlendShapeIndividualMapping_s;
struct scenePathObject_s;
struct skeletonInst_s;
struct skeletonJointMap_s;
struct sceneLookAt_s;
struct dbVertexPath_s;
struct avatarVertexPathBranch_s;
struct avatarVertexPathNode_s;
struct avatarExpressionDatabase_s;
struct avatarExpressionRuntime_s;
struct actorStrategyInst_s;
struct actorMindInst_s;
struct actorBodyInst_s;
struct camVirt_s;
struct sceneRegion_s;

/* 1173 */
enum objDefId_e : uint32_t
{
	objDefId_null = 0x0,
	objDefId_obj = 0x1,
	objDefId_avatar = 0x2,
	objDefId_sceneControlObj = 0x3,
	objDefId_background = 0x4,
	objDefId_actor = 0x5,
	objDefId_actorBody = 0x6,
	objDefId_actorMind = 0x7,
	objDefId_actorStrategy = 0x8,
	objDefId_actorState = 0x9,
	objDefId_actorMove = 0xA,
	objDefId_uiObj = 0xB,
	objDefId_entityAvatarFxExplodeParts = 0xC,
	objDefId_entityAvatarMiscAnimDelete = 0xD,
	objDefId_entityMoveXZGravity = 0xE,
	objDefId_entityMoveXYZnoG = 0xF,
	objDefId_entitySceneControlBootSec = 0x10,
	objDefId_entitySceneControlFx = 0x11,
	objDefId_entitySceneControlUI = 0x12,
	objDefId_pinataactor = 0x13,
	objDefId_pinataactorBody = 0x14,
	objDefId_pinataactorStrategy = 0x15,
	objDefId_pinataavatar = 0x16,
	objDefId_pinatabg = 0x17,
	objDefId_entityAvatarPinataBag = 0x18,
	objDefId_entityAvatarPinataBud = 0x19,
	objDefId_entityAvatarPinataCameraTarget = 0x1A,
	objDefId_entityAvatarPinataCursor = 0x1B,
	objDefId_entityAvatarPinataFruit = 0x1C,
	objDefId_entityAvatarPinataEgg = 0x1D,
	objDefId_entityAvatarPinataHome = 0x1E,
	objDefId_entityAvatarPinataProduce = 0x1F,
	objDefId_entityAvatarPinataProp = 0x20,
	objDefId_entityAvatarPinataSweet = 0x21,
	objDefId_entityAvatarPinataFence = 0x22,
	objDefId_entityAvatarPinataFertiliser = 0x23,
	objDefId_entityAvatarPinataFertiliserPile = 0x24,
	objDefId_entityAvatarPinataBifTree = 0x25,
	objDefId_entityAvatarPinataBifPlant = 0x26,
	objDefId_entityAvatarPinataProjectile = 0x27,
	objDefId_entityAvatarPinataSeed = 0x28,
	objDefId_entityAvatarPinataSeedHole = 0x29,
	objDefId_entityAvatarPinataSpade = 0x2A,
	objDefId_entityAvatarPinataSpadePart = 0x2B,
	objDefId_entityAvatarPinataPacket = 0x2C,
	objDefId_entityAvatarPinataCrate = 0x2D,
	objDefId_entityAvatarPinataMoney = 0x2E,
	objDefId_entityAvatarPinataWateringCan = 0x2F,
	objDefId_entityAvatarPinataPaving = 0x30,
	objDefId_entityAvatarPinataHouseBlock = 0x31,
	objDefId_entityAvatarPinataFlowerHead = 0x32,
	objDefId_entityAvatarPinataSlotMachine = 0x33,
	objDefId_entityAvatarPinataTrap = 0x34,
	objDefId_entityAvatarPinataVegetable = 0x35,
	objDefId_entityAvatarPinataLifeSweet = 0x36,
	objDefId_entityAvatarPinataShopKeeper = 0x37,
	objDefId_entityAvatarPinataContract = 0x38,
	objDefId_entityAvatarPinataSignpost = 0x39,
	objDefId_entityAvatarPinataJournal = 0x3A,
	objDefId_entityAvatarPinataSurface = 0x3B,
	objDefId_entityBodyPinata = 0x3C,
	objDefId_entityBodyPinataAnimal = 0x3D,
	objDefId_entityBodyPincam = 0x3E,
	objDefId_entityMovePinata = 0x3F,
	objDefId_entityMindPinataAnimal = 0x40,
	objDefId_entityMindPinataAnimalIMapCellFormat = 0x41,
	objDefId_entityMindPinataBasic = 0x42,
	objDefId_entityMindPincam = 0x43,
	objDefId_entityMindPadControl = 0x44,
	objDefId_entityStatePinataAnim2Stand = 0x45,
	objDefId_entityStatePinataCutscene2Stand = 0x46,
	objDefId_entityStatePinataClimb = 0x47,
	objDefId_entityStatePinataConcentrate = 0x48,
	objDefId_entityStatePinataEat = 0x49,
	objDefId_entityStatePinataDrink = 0x4A,
	objDefId_entityStatePinataExplode = 0x4B,
	objDefId_entityStatePinataFight = 0x4C,
	objDefId_entityStatePinataFly = 0x4D,
	objDefId_entityStatePinataFlyInto = 0x4E,
	objDefId_entityStatePinataFlyPath = 0x4F,
	objDefId_entityStatePinataGiveDrugs = 0x50,
	objDefId_entityStatePinataHelp = 0x51,
	objDefId_entityStatePinataImpact = 0x52,
	objDefId_entityStatePinataKnockBack = 0x53,
	objDefId_entityStatePinataPath = 0x54,
	objDefId_entityStatePinataPerch = 0x55,
	objDefId_entityStatePinataRest = 0x56,
	objDefId_entityStatePinataSick = 0x57,
	objDefId_entityStatePinataSleep = 0x58,
	objDefId_entityStatePinataStand = 0x59,
	objDefId_entityStatePinataStrafe = 0x5A,
	objDefId_entityStatePinataTurn = 0x5B,
	objDefId_entityStatePinataWalk = 0x5C,
	objDefId_entityStatePinataWalkPath = 0x5D,
	objDefId_entityStatePinataDizzy = 0x5E,
	objDefId_entityStatePinataTiptoe = 0x5F,
	objDefId_entityStatePinataGroom = 0x60,
	objDefId_entityStatePinataSpecialOnTarget = 0x61,
	objDefId_entityStatePinataSquash = 0x62,
	objDefId_entityStatePinataCocoon = 0x63,
	objDefId_entityStatePinataHidden = 0x64,
	objDefId_entityStatePinataTestAnim = 0x65,
	objDefId_entityStatePinataProduceReady = 0x66,
	objDefId_entityStrategyPinataAnimal = 0x67,
	objDefId_entityStrategyPincam = 0x68,
	objDefId_cursor = 0x69,
	objDefId_entitySceneControlPinataAmbientTune = 0x6A,
	objDefId_entitySceneControlPinataAttack = 0x6B,
	objDefId_entitySceneControlPinataBeggarTrader = 0x6C,
	objDefId_entitySceneControlPinataCameraSystem = 0x6D,
	objDefId_entitySceneControlPinataDastardos = 0x6E,
	objDefId_entitySceneControlPinataDedos = 0x6F,
	objDefId_entitySceneControlPinataDoctor = 0x70,
	objDefId_entitySceneControlPinataBuilder = 0x71,
	objDefId_entitySceneControlPinataGarden = 0x72,
	objDefId_entitySceneControlPinataSubGarden = 0x73,
	objDefId_entitySceneControlPinataGenerator2 = 0x74,
	objDefId_entitySceneControlPinataHeadCamera = 0x75,
	objDefId_entitySceneControlPinataHelpers = 0x76,
	objDefId_entitySceneControlPinataHouseInteriorBedroom = 0x77,
	objDefId_entitySceneControlPinataHouseInteriorMateRoom = 0x78,
	objDefId_entitySceneControlPinataHunt = 0x79,
	objDefId_entitySceneControlPinataHunter = 0x7A,
	objDefId_entitySceneControlPinataLive = 0x7B,
	objDefId_entitySceneControlPinataMeet = 0x7C,
	objDefId_entitySceneControlPinataFight2 = 0x7D,
	objDefId_entitySceneControlPinataFactory = 0x7E,
	objDefId_entitySceneControlPinataFightAudience = 0x7F,
	objDefId_entitySceneControlPinataWind = 0x80,
	objDefId_entitySceneControlPinataMate = 0x81,
	objDefId_entitySceneControlPinataRuffians = 0x82,
	objDefId_entitySceneControlPinataSeedos = 0x83,
	objDefId_entitySceneControlPinataStork = 0x84,
	objDefId_entitySceneControlPinataScript = 0x85,
	objDefId_entitySceneControlPinataTinker = 0x86,
	objDefId_entitySceneControlPinataWeatherController = 0x87,
	objDefId_entitySceneControlPinataPlay = 0x88,
	objDefId_entitySceneControlPinataCursorControl = 0x89,
	objDefId_entitySceneControlPinataDigitalObjects = 0x8A,
	objDefId_entitySceneControlPinataStatusBar = 0x8B,
	objDefId_entitySceneControlPinataMateMiniGame = 0x8C,
	objDefId_entitySceneControlPinataHouseInteriorGym = 0x8D,
	objDefId_entitySceneControlPinataSlotMachine = 0x8E,
	objDefId_entitySceneControlPinataChallenges = 0x8F,
	objDefId_entitySceneControlPinataAchievements = 0x90,
	objDefId_entitySceneControlPinataCompetitionLobby = 0x91,
	objDefId_entitySceneControlPinataCompetitionManager = 0x92,
	objDefId_entitySceneControlPinataCompetitionRace = 0x93,
	objDefId_entitySceneControlPinataCompetitionShow = 0x94,
	objDefId_entitySceneControlPinataCredits = 0x95,
	objDefId_entitySceneControlPinataCreditsUnlock = 0x96,
	objDefId_entitySceneControlPinataPestStartFights = 0x97,
	objDefId_entitySceneControlPinataJournal = 0x98,
	objDefId_entitySceneControlPinataFrontend = 0x99,
	objDefId_entitySceneControlPinataLeaderboardsWrite = 0x9A,
	objDefId_entitySceneControlPinataLeaderboardsRead = 0x9B,
	objDefId_entitySceneControlPinataIntroVideo = 0x9C,
	objDefId_entitySceneControlPinataTitleGarden = 0x9D,
	objDefId_entitySceneControlPinataStoryUnlock = 0x9E,
	objDefId_entitySceneControlPinataStore = 0x9F,
	objDefId_bifPart = 0xA0,
	objDefId_bifPartGroup = 0xA1,
	objDefId_bifPartGroupBranch = 0xA2,
	objDefId_bifPartGroupBud = 0xA3,
	objDefId_bifPartPerchPath = 0xA4,
	objDefId_bifPartProdPoint = 0xA5,
	objDefId_bifPartHead = 0xA6,
	objDefId_bifPartVegBoost = 0xA7,
	objDefId_imapCellFormat = 0xA8,
	objDefId_imapCombineCellFormat = 0xA9,
	objDefId_imapUpdatePolicy = 0xAA,
	objDefId_imapUpdatePolicyScratch = 0xAB,
	objDefId_imapUpdatePolicyScratchAStar = 0xAC,
	objDefId_scenePinataIMapCellFormat = 0xAD,
	objDefId_entitySceneControlTestPinataActorPadControl = 0xAE,
	objDefId_MaxClassId = 0xAF,
};

/* 1157 */
enum objTag_e : uint32_t
{
	objTag_Null = 0x0,
	objTag_Actor = 0x1,
	objTag_Actor_Cameron = 0x2,
	objTag_Actor_zzz = 0x3,
	objTag_Avatar = 0x4,
	objTag_Avatar_Fx_AnimEmitter = 0x5,
	objTag_Avatar_Fx_BurnUp = 0x6,
	objTag_Avatar_Fx_Explode = 0x7,
	objTag_Avatar_Fx_MotionBlur = 0x8,
	objTag_Background = 0x9,
	objTag_Body = 0xA,
	objTag_Body_Camera = 0xB,
	objTag_Body_Human = 0xC,
	objTag_Body_Player = 0xD,
	objTag_Camera = 0xE,
	objTag_Collectable = 0xF,
	objTag_Destructible = 0x10,
	objTag_Frontend = 0x11,
	objTag_FxCustom_DustUp = 0x12,
	objTag_FxCustom_Electric = 0x13,
	objTag_FxCustom_FadeOut = 0x14,
	objTag_FxCustom_FadeToColour = 0x15,
	objTag_FxCustom_FadeToGrey = 0x16,
	objTag_FxCustom_Fire = 0x17,
	objTag_FxCustom_MutateHalo = 0x18,
	objTag_FxCustom_Outline = 0x19,
	objTag_FxCustom_SolidFadeIn = 0x1A,
	objTag_Mind = 0x1B,
	objTag_Mind_Cameraman = 0x1C,
	objTag_Mind_Cinema = 0x1D,
	objTag_Mind_Human = 0x1E,
	objTag_Mind_Player = 0x1F,
	objTag_Misc_AnimDelete = 0x20,
	objTag_Misc_AnimatedLight = 0x21,
	objTag_Misc_Prop = 0x22,
	objTag_Move = 0x23,
	objTag_PadHardwareDXDevice = 0x24,
	objTag_PadHardwareDXDevice_Generic = 0x25,
	objTag_PadHardwareDXDevice_Keyboard = 0x26,
	objTag_PadHardwareDXDevice_Mouse = 0x27,
	objTag_Pinata_AAAAAA = 0x28,
	objTag_Pinata_Actor_AAAAAA = 0x29,
	objTag_Pinata_Actor_Animal = 0x2A,
	objTag_Pinata_Actor_Camera = 0x2B,
	objTag_Pinata_Actor_Helper = 0x2C,
	objTag_Pinata_Actor_ZZZZZZ = 0x2D,
	objTag_Pinata_Avatar_AAAAAA = 0x2E,
	objTag_Pinata_Avatar_Accessory = 0x2F,
	objTag_Pinata_Avatar_BifPlant = 0x30,
	objTag_Pinata_Avatar_BifTree = 0x31,
	objTag_Pinata_Avatar_Bud = 0x32,
	objTag_Pinata_Avatar_CameraTarget = 0x33,
	objTag_Pinata_Avatar_Contract = 0x34,
	objTag_Pinata_Avatar_Crate = 0x35,
	objTag_Pinata_Avatar_Cursor = 0x36,
	objTag_Pinata_Avatar_Egg = 0x37,
	objTag_Pinata_Avatar_Fence = 0x38,
	objTag_Pinata_Avatar_Fertiliser = 0x39,
	objTag_Pinata_Avatar_FertiliserPile = 0x3A,
	objTag_Pinata_Avatar_FlowerHead = 0x3B,
	objTag_Pinata_Avatar_Fruit = 0x3C,
	objTag_Pinata_Avatar_Home = 0x3D,
	objTag_Pinata_Avatar_HouseBlock = 0x3E,
	objTag_Pinata_Avatar_Journal = 0x3F,
	objTag_Pinata_Avatar_LifeSweet = 0x40,
	objTag_Pinata_Avatar_Money = 0x41,
	objTag_Pinata_Avatar_Packet = 0x42,
	objTag_Pinata_Avatar_Paving = 0x43,
	objTag_Pinata_Avatar_Produce = 0x44,
	objTag_Pinata_Avatar_Projectile = 0x45,
	objTag_Pinata_Avatar_Prop = 0x46,
	objTag_Pinata_Avatar_Seed = 0x47,
	objTag_Pinata_Avatar_SeedHole = 0x48,
	objTag_Pinata_Avatar_ShopKeeper = 0x49,
	objTag_Pinata_Avatar_SlotMachine = 0x4A,
	objTag_Pinata_Avatar_Spade = 0x4B,
	objTag_Pinata_Avatar_SpadePart = 0x4C,
	objTag_Pinata_Avatar_Surface = 0x4D,
	objTag_Pinata_Avatar_Sweet = 0x4E,
	objTag_Pinata_Avatar_Vegetable = 0x4F,
	objTag_Pinata_Avatar_WateringCan = 0x50,
	objTag_Pinata_Avatar_ZZBag = 0x51,
	objTag_Pinata_Avatar_ZZSignpost = 0x52,
	objTag_Pinata_Avatar_ZZTrap = 0x53,
	objTag_Pinata_Avatar_ZZZZZZ = 0x54,
	objTag_Pinata_Bif_AAAAAA = 0x55,
	objTag_Pinata_Bif_Part = 0x56,
	objTag_Pinata_Bif_Part_Group = 0x57,
	objTag_Pinata_Bif_Part_Group_Branch = 0x58,
	objTag_Pinata_Bif_Part_Group_Bud = 0x59,
	objTag_Pinata_Bif_Part_Head = 0x5A,
	objTag_Pinata_Bif_Part_PerchPath = 0x5B,
	objTag_Pinata_Bif_Part_ProdPoint = 0x5C,
	objTag_Pinata_Bif_Part_VegBoost = 0x5D,
	objTag_Pinata_Bif_ZZZZZZ = 0x5E,
	objTag_Pinata_Body_Animal = 0x5F,
	objTag_Pinata_Body_Helper = 0x60,
	objTag_Pinata_DigitalObjects_Crate = 0x61,
	objTag_Pinata_Imap_CellFormat = 0x62,
	objTag_Pinata_Imap_CombineCellFormat = 0x63,
	objTag_Pinata_Imap_UpdatePolicy = 0x64,
	objTag_Pinata_Imap_UpdatePolicyScratch = 0x65,
	objTag_Pinata_Imap_UpdatePolicyScratchAStar = 0x66,
	objTag_Pinata_Mind_Animal = 0x67,
	objTag_Pinata_Mind_Animal_IMap_CellFormat = 0x68,
	objTag_Pinata_Mind_Basic = 0x69,
	objTag_Pinata_Scene_CellFormat = 0x6A,
	objTag_Pinata_Scene_Cursor = 0x6B,
	objTag_Pinata_Scene_CursorController = 0x6C,
	objTag_Pinata_Scene_DigitalObjects = 0x6D,
	objTag_Pinata_Scene_Weather = 0x6E,
	objTag_Powerup = 0x6F,
	objTag_Props = 0x70,
	objTag_SceneControl = 0x71,
	objTag_Spawn = 0x72,
	objTag_State = 0x73,
	objTag_Strategy = 0x74,
	objTag_Strategy_Bot = 0x75,
	objTag_Strategy_Director = 0x76,
	objTag_Strategy_Human = 0x77,
	objTag_Strategy_Player = 0x78,
	objTag_Weapon = 0x79,
	objTag_MAX = 0x7A,
};



/* 11879 */
struct gameIdComplete_s
{
	uint16_t id;
	char key;
	unsigned char save;
};

/* 11889 */
struct gameIdInst_s
{
	dsLinkedListNode_s node;
	gameIdComplete_s complete;
	void* owner;
};

/* 1579 */
enum objNetSyncOwnershipStatus_e : uint32_t
{
	objNetSyncOwnershipStatus_Error = 0x0,
	objNetSyncOwnershipStatus_Failed = 0x1,
	objNetSyncOwnershipStatus_Pending = 0x2,
	objNetSyncOwnershipStatus_Timeout = 0x3,
	objNetSyncOwnershipStatus_Passed = 0x4,
};

/* 11890 */
struct objNetSyncOwnership_s
{
	objNetSyncOwnershipStatus_e ownershipStatus;
	float ownershipTimeout;
	int sendRequest;
	gameIdComplete_s newGameId;
	int hasNewGameId;
	int blockOwnershipRequest;
};

/* 11891 */
struct objNetSyncInst_s
{
	float lifeTimer;
	float updateDelayTimer;
	float updateForcedTimer;
	float timeSinceLastSentUpdate;
	float timeSinceLastSentUpdatePrev;
	float timeSinceLastReceivedUpdate;
	float timeSinceLastReceivedUpdatePrev;
	float updateDelayTimerDefault;
	float updateForcedTimerDefault;
	int canUpdate;
	int requiresForcedUpdate;
	unsigned int properties;
	unsigned int doProperties;
	unsigned int updateOnDirtyFlags;
	unsigned int actualDirtyFlags;
	objNetSyncOwnership_s ownership;
};

/* 11703 */
struct objInst_s
{
	const objFunc_s* func;
	objDefId_e defId;
	objTag_e tag;
	gameIdInst_s _id;
	objNetSyncInst_s _netsync;
	assetId_s* objParamsAid;
};

/* 11711 */
struct mlVec
{
	float x;
	float y;
	float z;
};

/* 11894 */
struct avatarInst_s_unnamed_tag
{
	float secs;
	float scalar;
};

/* 11773 */
struct mlRot_s
{
	float p;
	float y;
	float r;
};

/* 11895 */
struct mlQuat
{
	float x;
	float y;
	float z;
	float w;
};

/* 11902 */
struct animJointTweakCell_s_unnamed_tag
{
	float fracEffect;
	mlVec magnitude;
};

/* 11903 */
struct animJointTweakCell_s
{
	unsigned int maskTransform;
	int idJoint;
	animJointTweakCell_s_unnamed_tag scale;
	unsigned char rotate[12];
};

/* 11904 */
struct animJointTweak_s
{
	animJointMap_s* jointMap;
	animJointTweakCell_s firstCell;
};

/* 11905 */
struct avatarAnim_s
{
	animTable_s* table;
	int tableIsAsset;
	animMixer_s* mixer;
	animJointMap_s* jointMap;
	void(*eventHandler)(const animEventUnit_s*, unsigned int, float, void*, int);
	animJointTweak_s jointTweak;
	int forceKeepCycle;
	int forceNoTween;
	int applyMoveData;
};


/* 11907 */
struct avatarCallout_s
{
	dbCallout_CommonAndSize_s* head;
	assetId_s aid;
	int padPort;
};

/* 1084 */
enum SurfaceMask_e : uint32_t
{
	SurfaceMask_Attack = 0x1,
	SurfaceMask_Vulnerable = 0x2,
	SurfaceMask_Solid = 0x4,
	SurfaceMask_Floor = 0x8,
	SurfaceMask_KnockBack = 0x10,
	SurfaceMask_Trigger = 0x20,
	SurfaceMask_Breakable = 0x40,
	SurfaceMask_Effects = 0x80,
	SurfaceMask_BreakableWeapon = 0x100,
	SurfaceMask_Visibility = 0x200,
	SurfaceMask_Interact = 0x400,
	SurfaceMask_Fire = 0x800,
	SurfaceMask_AStar = 0x1000,
	SurfaceMask_Cloth = 0x2000,
	SurfaceMask_PlayerOnly = 0x4000,
	SurfaceMask_DeadEnd = 0x8000,
	SurfaceMask_Water = 0x10000,
	SurfaceMask_Defensive = 0x20000,
	SurfaceMask_GhouliesOnly = 0x40000,
	SurfaceMask_CameraOnly = 0x80000,
	SurfaceMask_NotCarriedWeapons = 0x100000,
	SurfaceMask_Shield = 0x200000,
	SurfaceMask_Max = 0x40000000,
	SurfaceMask_None = 0x0,
};

/* 1386 */
enum avatarDeflect_Priority_e : uint32_t
{
	avatarDeflect_Priority_Min = 0x0,
	avatarDeflect_Priority_Low = 0x19,
	avatarDeflect_Priority_Default = 0x32,
	avatarDeflect_Priority_High = 0x4B,
	avatarDeflect_Priority_Max = 0x64,
};

/* 11908 */
struct avatarDeflect_s
{
	SurfaceMask_e surfaceMask;
	SurfaceMask_e backupSurfaceMask;
	avatarInst_s* stickyAvatar;
	avatarDeflect_Priority_e priority;
	dsList_s* ignoreList;
	int remoteAvatarSoIgnoreHits;
};

/* 11909 */
struct avatarDrawCamera_s
{
	dsLinkedListNode_s listNode;
	float distanceSqr;
};

/* 11794 */
struct mlColour_s
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
};

/* 11915 */
struct avatarDraw_s_unnamed_tag
{
	void(*preDraw)(avatarInst_s*, const sceneObjDrawParams_s*, void*);
	void(*postDraw)(avatarInst_s*, const sceneObjDrawParams_s*, void*);
	void* data;
};

/* 11916 */
struct avatarDraw_s
{
	avatarDrawCamera_s camera[3][1];
	unsigned char cullPlaneIndex[3][1];
	unsigned int visibilityFlags;
	unsigned int flags;
	int hide;
	mlColour_s colour;
	mlColour_s blend;
	int useOpaqueDithering;
	avatarDraw_s_unnamed_tag callbacks;
};

/* 11917 */
struct avatarEmitter_s
{
	dsLinkedListNode_s activeList;
	dsLinkedListNode_s insertList;
	uint16_t uniqueId;
	uint16_t PAD;
};

/* 11918 */
struct __declspec(align(4)) avatarExtent_s_unnamed_tag_unnamed_tag
{
	mlVec base;
	int isValid;
	unsigned char loadBalanceKey;
};

/* 11919 */
struct avatarExtent_s_unnamed_tag
{
	mlVec base;
	mlVec offset;
	float radius;
	float above;
	float below;
	avatarExtent_s_unnamed_tag_unnamed_tag cachedObjectSpace;
	float boundingSphereRadius;
};

/* 11920 */
struct avatarExtent_s
{
	float proximitySphereScaler;
	float proximitySphereRadius;
	avatarExtent_s_unnamed_tag animatedCylinder;
};

/* 11921 */
struct avatarFx_s
{
	float blurTimer;
	int didExplosionLeadToItsRemoval;
};

/* 11922 */
struct avatarHit_s
{
	SurfaceMask_e hitMask;
	SurfaceMask_e backupHitMask;
};

/* 11923 */
struct avatarLookAt_s
{
	dsLinkedListNode_s listSentinel;
};

/* 11924 */
struct avatarMarker_s
{
	uint16_t uniqueId;
	uint16_t childId;
};

/* 11925 */
struct avatarModelMembrane_s
{
	dsList_s* unitList;
	mlVec appliedForce;
	unsigned int cachedMembraneTypeMask;
};

/* 11927 */
struct supportBlendShapeBaseLODMapping_s
{
	supportBlendShapeIndividualMapping_s* mapping;
	int numBaseBlendShapes;
	int numLodLevels;
};

/* 11928 */
struct avatarModel_s
{
	mlVec scale;
	glModel_s* draw;
	const dbModel_s* model;
	const dbLocator_s* locators;
	avatarModelMembrane_s membraneList;
	unsigned int lastTickOfMembraneConstruction;
	int shadowVisibilityCountdown;
	supportBlendShapeBaseLODMapping_s blendShapeMapping;
};

/* 11929 */
struct avatarMtx_s
{
	int isValid;
	unsigned int lastTickBuilt;
	float basis[4][4];
	float invBasis[4][4];
};

/* 1623 */
enum avatarNetSyncUpdateType_e : uint32_t
{
	avatarNetSyncUpdateType_None = 0x0,
	avatarNetSyncUpdateType_Simple = 0x1,
	avatarNetSyncUpdateType_Pos = 0x2,
	avatarNetSyncUpdateType_PosAndRot = 0x3,
	avatarNetSyncUpdateType_Rot = 0x4,
	avatarNetSyncUpdateType_Yaw = 0x5,
	avatarNetSyncUpdateType_PosAndYaw = 0x6,
	avatarNetSyncUpdateType_MAX = 0x7,
};

/* 11930 */
struct avatarNetSync_s
{
	int still;
	avatarNetSyncUpdateType_e type;
};

/* 11754 */
struct PrimUnit_s
{
	unsigned char type;
	unsigned char size;
	unsigned char valid;
	unsigned char __UNUSED;
};

/* 11755 */
struct PrimCylinder_s
{
	PrimUnit_s head;
	mlVec base;
	mlVec axis;
	float radius;
};

/* 11756 */
struct mlIntVec_s
{
	int x;
	int y;
	int z;
};

/* 11757 */
struct scenePartitionInst_s
{
	void* object;
	PrimCylinder_s cylinder;
	mlIntVec_s occupiedMin;
	mlIntVec_s occupiedMax;
	unsigned int listMask;
	int staticObject;
	int iteratorFlag[3];
};

/* 11931 */
struct avatarPartition_s
{
	scenePartitionInst_s instance;
	int spatiallyIrrelevant;
	PrimCylinder_s lastValidCylinder;
};

/* 11936 */
struct avatarPathObject_s
{
	scenePathObject_s* pathObject;
	int deflected;
};

/* 11937 */
struct avatarShadow_s
{
	int type;
};

/* 11819 */
struct audioCueHash_s
{
	unsigned int hash;
};

/* 11820 */
struct sceneSfxUnit_s_unnamed_tag
{
	char variable[16];
	float value;
};

/* 11821 */
struct sceneSfxUnit_s
{
	dsLinkedListNode_s listNode;
	unsigned int sfxRef;
	avatarInst_s* avatar;
	audioCueHash_s cue;
	uint16_t channel;
	int isFirstFrame;
	int is3D;
	mlVec position;
	mlVec direction;
	float distanceSqr;
	float runTimeVolumeScale;
	sceneSfxUnit_s_unnamed_tag rpc;
};

/* 11938 */
struct avatarSfxChannel_s
{
	sceneSfxUnit_s sfxUnit;
	char updatePosition;
	char updateDirection;
	uint16_t jointIndex;
	const dbLocatorUnit_s* locator;
};

/* 11939 */
struct avatarSfx_s
{
	avatarSfxChannel_s channelData[9];
	float volumeScale;
};

/* 11940 */
struct avatarTarget_s
{
	dsLinkedListNode_s listSentinel;
};


/* 11941 */
struct avatarVolume_s
{
	dsList2_s volumeList;
	dsList_s* boundingVolumeList;
	void* volumeData;
	mlVec boxCentre;
	mlVec boxExtents;
	int boxJoint;
	unsigned int lastTickUpdated;
	unsigned int allUnitsMask;
};

/* 1120 */
enum dbSkeletonEffect_e : uint32_t
{
	dbSkeletonEffect_None = 0x0,
	dbSkeletonEffect_LookAt1 = 0x1,
	dbSkeletonEffect_LookAt2 = 0x2,
	dbSkeletonEffect_LookAt3 = 0x4,
	dbSkeletonEffect_LookAt4 = 0x8,
	dbSkeletonEffect_BodyTurn = 0x10,
	dbSkeletonEffect_Freeze = 0x20,
	dbSkeletonEffect_MAX = 0x40,
};

/* 11945 */
struct skeletonLookAtBuild_s
{
	mlVec lookAtPos;
	mlVec lookAtPosLocal;
	int isValid;
};

/* 11946 */
struct skeletonBuildBodyTurn_s
{
	mlVec position;
};

/* 11947 */
struct skeletonBuild_s
{
	skeletonInst_s* skeleton;
	const avatarInst_s* avatar;
	skeletonJointMap_s* activeJointMap;
	dbSkeletonEffect_e resetCurrentRot;
	int resetAnimation;
	float updateSecs;
	float rotSpeedScale;
	dbSkeletonEffect_e blendToAnim;
	skeletonLookAtBuild_s lookAt[4];
	skeletonBuildBodyTurn_s bodyTurn;
	dsList2_s jointRuntimeList;
	dsList2_s keepRotation;
	dsList2_s freezeJoint;
};

/* 1535 */
enum avatarSkeletonLookAtPriority_e : uint32_t
{
	avatarSkeletonLookAtPriority_None = 0x0,
	avatarSkeletonLookAtPriority_Lowest = 0x1,
	avatarSkeletonLookAtPriority_Low = 0x2,
	avatarSkeletonLookAtPriority_Medium = 0x3,
	avatarSkeletonLookAtPriority_High = 0x4,
	avatarSkeletonLookAtPriority_Highest = 0x5,
	avatarSkeletonLookAtPriority_Max = 0x6,
};

/* 11953 */
struct avatarSkeletonLookAt_s
{
	sceneLookAt_s* lookAt;
	avatarSkeletonLookAtPriority_e priority;
	float timer;
	int doHitTest;
};

/* 11954 */
struct avatarSkeleton_s
{
	skeletonBuild_s build;
	skeletonInst_s* skeleton;
	dbSkeletonEffect_e wantedEffectsMask;
	dbSkeletonEffect_e animValidEffects;
	float effectsMaskTimer;
	avatarSkeletonLookAt_s head[4];
	assetId_s skeletonAid;
};

/* 11955 */
struct dsHandle
{
	unsigned int handle;
};

/* 11961 */
struct avatarVertexPath_s
{
	const dbVertexPath_s* vertexPath;
	avatarVertexPathBranch_s* branch;
	int maxBranchId;
	avatarVertexPathNode_s* node;
	dsList_s* perchList;
};

/* 11962 */
struct avatarThreadStateContainer_s
{
	avatarThreadState_s* state;
};

/* 11964 */
struct avatarExpression_s_unnamed_tag
{
	const avatarExpressionDatabase_s* db;
	int count;
	float blendTime;
};

/* 11966 */
struct avatarExpression_s
{
	avatarExpression_s_unnamed_tag data[10];
	avatarExpressionRuntime_s* values;
	int numberOfValues;
	int id[4];
	int forced;
};

/* 11746 */
struct dsTreeNode_s
{
	dsTreeNode_s* _parentPtr;
	dsTreeNode_s* _childPtr;
	dsTreeNode_s* _nextSiblingPtr;
	dsTreeNode_s* _prevSiblingPtr;
};

/* 11748 */
struct avatarInst_s
{
	objInst_s __objectInstance;
	mlVec __position;
	avatarAttach_s* _attach;
	void* _teamData;
	avatarInst_s_unnamed_tag _timer;
	unsigned char _pinata[16];
	mlRot_s __rotation;
	mlQuat __orientation;
	mlVec __scale;
	mlVec __pivot;
	mlVec prevPosition;
	mlVec velocity;
	unsigned int threadRef;
	unsigned int fence;
	int notAddedToTickTree;
	int isMonitored;
	int haveProcessedRemoveMessage;
	int privateFlag;
	sceneMainWorkspace_s* scene;
	avatarAnimManagerWorkspace_s* avatarAnimManager;
	int animManagerList;
	float animDurationScale;
	avatarAnim_s _anim;
	avatarCallout_s _callout;
	avatarDeflect_s _deflect;
	avatarDraw_s _draw;
	avatarEmitter_s _emitter;
	avatarExtent_s _extent;
	avatarFx_s _fx;
	avatarHit_s _hit;
	avatarLookAt_s _lookat;
	avatarMarker_s _marker;
	avatarModel_s _model;
	avatarMtx_s _mtx;
	avatarNetSync_s _netsync;
	avatarPartition_s _partition;
	avatarPathObject_s _pathObject;
	avatarShadow_s _shadow;
	avatarSfx_s _sfx;
	avatarTarget_s _target;
	avatarVolume_s _volume;
	avatarSkeleton_s _skeleton;
	dsHandle _handle;
	avatarVertexPath_s _vertexPath;
	avatarThreadStateContainer_s _threadStateContainer;
	avatarExpression_s _expression;
	dsLinkedListNode_s avatarListNode;
	dsLinkedListNode_s avatarRemoteListNode;
	dsLinkedListNode_s deleteListNode;
	dsLinkedListNode_s dynamicListNode;
	dsLinkedListNode_s netsyncUpdateListNode;
	dsTreeNode_s tickTreeNode;
	avatarInst_s_unnamed_tag _lifetime;
	unsigned int rootEntityAidHash;
	int loadedBundleUsingAidHash;
	int wasRemovedFromVisibleLists;
};

/* 12074 */
struct actorDraw_s
{
	const camVirt_s* hideIfViewedThrough;
};

/* 12079 */
struct actorRegion_s
{
	const sceneRegion_s* boundingRegion;
	const sceneRegion_s* setupExclusionRegion;
	const sceneRegion_s* currentExclusionRegion;
	mlVec lastSafePosition;
	int lastSafeLocked;
};

/* 12080 */
struct actorVPad_s
{
	padInfo_s* info;
	float lastPressed[32];
};

/* 12081 */
struct netDeadReckoningInst_s
{
	mlVec oldPos;
	mlVec newPos;
	mlVec oldVel;
	mlVec newVel;
	mlVec firstPos;
	mlVec secondPos;
	mlVec thirdPos;
	mlVec fourthPos;
	float previousInterval;
	float timer;
	int overshot;
	mlVec updatePos;
};

/* 11705 */
struct mlV2_s
{
	float x;
	float y;
};

/* 12082 */
struct actorNetSync_s_unnamed_tag
{
	int overridePad;
	mlV2_s mainStick;
	mlV2_s subStick;
	unsigned int buttons;
	float triggerLeft;
	float triggerRight;
};

/* 12083 */
struct actorNetSync_s
{
	int requiresProcessing;
	netDeadReckoningInst_s deadReckoning;
	actorNetSync_s_unnamed_tag pad;
	unsigned char state[8];
};

/* 12084 */
struct actorInst_s_unnamed_tag
{
	int markAllAsOccupied;
};

/* 12033 */
struct actorInst_s
{
	avatarInst_s __avatarInstance;
	dsLinkedListNode_s actorListNode;
	actorStrategyInst_s* strategy;
	actorMindInst_s* mind;
	actorBodyInst_s* body;
	actorDraw_s _draw;
	actorRegion_s _region;
	actorVPad_s _vpad;
	actorNetSync_s _netsync;
	mlVec initialPosition;
	mlRot_s initialRotation;
	int cutSceneActive;
	int type;
	int basis;
	int flightModel;
	int threat;
	int playerControlledSometimes;
	actorInst_s_unnamed_tag astar;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* 997 */
enum sceneMode_e : uint32_t
{
	sceneModeStop = 0x0,
	sceneModePlay = 0x1,
	sceneModeStep = 0x2,
	sceneModeTransitionOut = 0x3,
	sceneModeLoading = 0x4,
	sceneModeTransitionIn = 0x5,
	sceneModePause = 0x6,
	sceneModeReset = 0x7,
	sceneModeQuit = 0x8,
	sceneModeKill = 0x9,
	sceneModeNetTransfer = 0xA,
	sceneModeDemoted = 0xB,
	sceneModeEdit = 0xC,
	sceneModeMAX = 0xD,
};

/* 11709 */
struct sceneActionWorkspace_s
{
	int actionDisabled[2];
};

struct aStarData_s;
struct aStarNodeData_s;
struct aStarDataGetNodeSuccessorContextIn_s;

/* 11717 */
struct aStarDataVirtualFuncs_s
{
	void(*freeFn)(aStarData_s*);
	void(*setNodePositionFn)(aStarData_s*, int, const mlVec* const);
	void(*setNodeRadiusFn)(aStarData_s*, int, float);
	const aStarNodeData_s* (*nodeSuccessorFn)(const aStarDataGetNodeSuccessorContextIn_s* const, float* const, int* const, int* const);
	float(*pathCostEstimateFn)(aStarData_s*, int, int);
	float(*pathCostEstimateFromPosFn)(aStarData_s*, const mlVec*, int);
	int(*nodesConnectedFn)(const aStarData_s*, int, int);
	int(*closestNodeToPosFn)(const aStarData_s*, const mlVec* const, int*);
	void(*donutIteratorFn)(aStarData_s*, const mlVec*, float, float, void(__fastcall*)(aStarData_s*, int, const mlVec* const, void*), void*);
	void(*xzBoxIteratorFn)(aStarData_s*, const mlVec*, const mlVec*, void(__fastcall*)(aStarData_s*, int, const mlVec* const, void*), void*);
	void(*lineIteratorFn)(aStarData_s*, const mlVec*, const mlVec*, void(__fastcall*)(aStarData_s*, int, const mlVec* const, void*), void*);
};

/* 11710 */
struct aStarData_s
{
	int type;
	int numberOfNodes;
	unsigned int nodeStride;
	unsigned int dataStride;
	float heuristicScalar;
	unsigned char* nodes;
	uint16_t uniqueLinkIdCounter;
	aStarDataVirtualFuncs_s virtualFns;
};

/* 11718 */
struct __declspec(align(4)) aStarNodeInst_s
{
	dsLinkedListNode_s openNode;
	uint16_t parent;
	uint16_t node;
	float costFromStart;
	float costToGoal;
	float totalCost;
	uint16_t closed;
};

struct sceneMainWorkspace_s;

/* 11720 */
struct sceneAStarWorkspace_s
{
	aStarData_s* data;
	aStarNodeInst_s* nodes;
	unsigned char doorStatus[12];
	sceneMainWorkspace_s* scene;
};

/* 11721 */
struct sceneControlWorkspace_s
{
	dsLinkedListNode_s sentinel;
	dsLinkedListNode_s insertListSentinel;
	dsLinkedListNode_s dynamicListSentinel;
	dsLinkedListNode_s deleteListSentinel;
};

/* 11722 */
struct effectMainInst_s
{
	dsLinkedListNode_s lists[27];
};

/* 11723 */
struct sceneEffectWorkspace_s
{
	sceneMainWorkspace_s* scene;
	effectMainInst_s* effectInst;
};
struct sceneMainWorkspace_s;

/* 11724 */
struct sceneExtentWorkspace_s_unnamed_tag
{
	unsigned char isValid;
	unsigned char hitsValid;
	mlVec min;
	mlVec max;
	mlVec corner[8];
	mlVec hitsMin;
	mlVec hitsMax;
};

/* 11725 */
struct sceneExtentWorkspace_s
{
	sceneMainWorkspace_s* scene;
	sceneExtentWorkspace_s_unnamed_tag bgBound;
	unsigned char walls[4];
};

/* 11726 */
struct sceneFlagsWorkspace_s
{
	unsigned int flags;
};

/* 11732 */
struct sceneLookAtWorkspace_s
{
	sceneMainWorkspace_s* scene;
	dsPageList_s lookAtList;
};

/* 11734 */
struct sceneLightWorkspace_s_unnamed_tag
{
	mlV4 colour;
};

/* 1335 */
enum sceneLightShadowType_e : uint32_t
{
	sceneLightShadowType_None = 0x0,
	sceneLightShadowType_ShadowBuffering = 0x1,
};

/* 11736 */
struct sceneLightWorkspace_s
{
	sceneLightWorkspace_s_unnamed_tag ambient;
	sceneLightWorkspace_s_unnamed_tag modelAmbient;
	unsigned char directional[28];
	float blueShiftScalar;
	sceneLightShadowType_e shadowType;
	unsigned char fog[28];
	int enableCubeFog;
	dsList_s* pointLightList;
	int curRef;
	int mainPointLight;
};


////////////

/* 11737 */
struct sceneDepthOfFieldWorkspace_s
{
	float nearBoundDist;
	float farBoundDist;
	float nearFocusDist;
	float farFocusDist;
};

/* 11738 */
struct sceneMainKillWorkspace_s
{
	sceneMainWorkspace_s* scene;
	int killActive;
};

/* 11739 */
struct sceneMainLoadWorkspace_s
{
	int loadActive;
};

/* 11740 */
struct sceneMainLoadBackgroundWorkspace_s
{
	sceneMainWorkspace_s* scene;
	assetId_s modelAid;
	assetId_s animAid;
	assetId_s animEventsAid;
	assetId_s paramsAid;
};

/* 11741 */
struct sceneMainLoadSceneControlWorkspace_s
{
	assetId_s paramsAids[48];
	int numParams;
};

/* 11742 */
struct markerList_s
{
	unsigned int numMarkers;
	unsigned int size;
};

/* 11743 */
struct sceneMarkerWorkspace_s
{
	markerList_s* list;
	sceneMainWorkspace_s* scene;
};

/* 11744 */
struct padMultiplayer_s
{
	padInfo_s* sentinel;
	char sentinelId[128];
	int numOfPlayers;
	int isPushed;
};

/* 11745 */
struct sceneMultiplayerWorkspace_s
{
	padMultiplayer_s* sentinel;
};

/* 11747 */
struct sceneObjWorkspace_s
{
	dsLinkedListNode_s avatarListSentinel;
	dsLinkedListNode_s avatarRemoteListSentinel;
	dsLinkedListNode_s avatarNetSyncUpdateListSentinel;
	dsLinkedListNode_s cameraListSentinel[3][1];
	dsLinkedListNode_s insertListSentinel;
	dsTreeNode_s tickTreeSentinel;
	dsLinkedListNode_s backgroundListSentinel;
	dsLinkedListNode_s actorListSentinel;
	dsLinkedListNode_s deleteListSentinel;
	dsLinkedListNode_s dynamicListSentinel;
	dsLinkedListNode_s netSyncUpdateListSentinel;
};

/* 11749 */
struct sceneObjDeflectWorkspace_s
{
	sceneMainWorkspace_s* scene;
	int numContactAvatars;
	avatarInst_s* contactAvatars[8];
	mlVec pointsOfContact[8];
};

/* 11750 */
struct HitContactUnit_s
{
	avatarInst_s* avatar;
	dsList_s* hitResultList;
};

/* 11751 */
struct sceneObjHitWorkspace_s
{
	sceneMainWorkspace_s* scene;
	int numContacts;
	HitContactUnit_s contactUnits[32];
	int threadId;
	dsList_s* avatarIgnoreList;
	unsigned int layerMask;
};


/* 11752 */
struct sceneObjHitWorkspaceMain_s
{
	sceneMainWorkspace_s* scene;
	sceneObjHitWorkspace_s hitWorkspace[3];
};

/* 11753 */
struct scenePartitionWorkspace_s
{
	int isReady;
	sceneMainWorkspace_s* scene;
	int isLocked[3];
};

/* 11754 */
struct PrimUnit_s;

/* 11755 */
struct PrimCylinder_s;

/* 11757 */
struct scenePartitionInst_s;

/* 11758 */
struct scenePartitionCubeData_s
{
	unsigned int freeSlots;
	scenePartitionInst_s* partition[30];
	scenePartitionCubeData_s* nextCube;
};

/* 11759 */
struct scenePartitionCubeWorkspace_s
{
	scenePartitionWorkspace_s _common;
	int min[3];
	int max[3];
	int size[3];
	int offset[3];
	scenePartitionCubeData_s** cubeGrid;
	int lastPartitionSearchId;
	dsPageList_s cubeList;
};


////////////

/* 11760 */
struct scenePathObjectWorkspace_s
{
	sceneMainWorkspace_s* scene;
	dsPageList_s pathObjectList;
};

/* 11762 */
struct sceneRegionWorkspace_s
{
	sceneMainWorkspace_s* scene;
	dsList2_s regionList;
	unsigned int allUnitsFlags;
};

struct dbTexture_s;

/* 11802 */
struct glModelTexOverride_s
{
	glModel_s* draw;
	int index;
	dbTexture_s* texture;
	int animMode;
	float clock;
	char name[128];
};

struct sceneSkyDomeLayer_s
{
	glModel_s* draw;
	float drawScale;
	mlRot_s pyr;
	mlRot_s pyrRate;
	int rotating;
	int clampToOrigin;
	int noAmbientLighting;
	glModelTexOverride_s* overrides[2];
};

/* 11804 */
struct sceneSkyDomeWorkspace_s
{
	sceneMainWorkspace_s* scene;
	sceneSkyDomeLayer_s layers[4];
};

/* 11805 */
struct sceneTargetWorkspace_s
{
	dsLinkedListNode_s listSentinel;
};

struct fxNextGenEmitterListUnit_s;
struct fxNextGenEmitterListDrawUnit_s;

/* 11832 */
struct fxNextGenEmitterList_s
{
	int listSize;
	fxNextGenEmitterListUnit_s* emitters;
	fxNextGenEmitterListDrawUnit_s* drawList;
};

/* 11806 */
struct fxNextGenSceneWorkspace_s
{
	fxNextGenEmitterList_s* lists[6];
	int lastRef;
	sceneMainWorkspace_s* scene;
};
////////////

struct sceneMainWorkspace_s;

/* 11833 */
struct sceneTimerWorkspace_s_unnamed_tag
{
	float timer;
	unsigned int tickedOn;
};

/* 11834 */
struct glTickerTimeStep_s
{
	int count;
	float remainder;
};

/* 11835 */
struct sceneTimerWorkspace_s
{
	sceneMainWorkspace_s* scene;
	float scale;
	float elapsedTotalSecs;
	float elapsedSecs;
	sceneTimerWorkspace_s_unnamed_tag gameStats;
	unsigned int elapsedTicks;
	float pauseTimer;
	glTickerTimeStep_s timeStep;
};
//////////////

struct sceneMainWorkspace_s;
struct dbCutscene_s;
struct glModelTexOverride_s;
struct cutsceneMainWorkspace_s;
struct cutsceneEventUnit_s;
struct cutsceneObj_s;
struct backgroundInst_s;
struct cutsceneStackNode_s;

/* 11843 */
struct cutsceneEventsLoopSfxLooper
{
	unsigned int ref;
};

/* 11844 */
struct cutsceneEventsLoopSfxStackNode_s
{
	cutsceneEventsLoopSfxLooper loopers[3];
};

/* 11819 */
struct audioCueHash_s;

/* 11845 */
struct cutsceneEventsStreamStackNode_s
{
	audioCueHash_s cueId;
};

/* 11846 */
struct cutsceneEventsNode_s
{
	cutsceneEventsLoopSfxStackNode_s loopSfxNode;
	cutsceneEventsStreamStackNode_s streamLooping;
	cutsceneEventsStreamStackNode_s streamOneShot;
};

/* 11848 */
struct cutsceneStackNode_s_unnamed_tag
{
	void(*func)(cutsceneStackNode_s*, void*, int);
	void* ptr;
};


/* 11847 */
struct cutsceneStackNode_s
{
	cutsceneMainWorkspace_s* ws;
	mlVec wp;
	mlVec scale;
	mlRot_s pyr;
	cutsceneEventUnit_s* cameraEventList;
	int activeCamera;
	float localTimer;
	float localTimerPrevious;
	float duration;
	float updateTime;
	dbCutscene_s* cutscene;
	int numObjects;
	cutsceneObj_s* objects;
	backgroundInst_s* backgroundObject;
	int backgroundIndex;
	cutsceneEventsNode_s eventsNode;
	cutsceneStackNode_s_unnamed_tag callback;
	assetId_s cutsceneAid;
	unsigned char pause[16];
	unsigned int flags;
	unsigned char saved[36];
	glModelTexOverride_s* texOverride;
	int isFakeCutscene;
};



/* 11836 */
struct cutsceneMainWorkspace_s_unnamed_tag
{
	assetId_s cutscene;
	int interpolateCamera;
};

/* 11837 */
struct cutsceneMainWorkspace_s
{
	sceneMainWorkspace_s* scene;
	cutsceneMainWorkspace_s_unnamed_tag next;
	unsigned char camera[116];
	unsigned char global[12];
	int activeScene;
	cutsceneStackNode_s* stack[4];
	cutsceneStackNode_s* removeMe;
	unsigned char cameraOverlay[8];
	int lockedPause;
};
/////////////

struct weatherComponentBaseInstance_s;

/* 11849 */
struct mlFloatBlend_s
{
	float value;
	float to;
	float from;
	float blendTime;
	float elapsedTime;
	float min;
	float max;
	int wrap;
};

/* 11820 */
struct sceneSfxUnit_s_unnamed_tag;
/* 11821 */
struct sceneSfxUnit_s;

/* 11852 */
struct weatherObject_s
{
	sceneMainWorkspace_s* scene;
	int active;
	mlFloatBlend_s cloudCover;
	mlFloatBlend_s precipitationLevel;
	mlFloatBlend_s windSpeed;
	mlFloatBlend_s windDirection;
	mlVec windVector;
	float lengthOfDayInRealtimeSecs;
	float lengthOfYearInGametimeDays;
	float dailyTimeFrac;
	float annualTimeDays;
	float annualTimeFrac;
	float dailyTimeDelta;
	int componentListSize[16];
	weatherComponentBaseInstance_s* componentList[16];
	float gustXWavelength;
	float gustXOffset;
	float gustXOffsetDelta;
	float gustXAmplitude;
	float gustZWavelength;
	float gustZOffset;
	float gustZOffsetDelta;
	float gustZAmplitude;
	int isBeingReflectedXZ[6];
	float reflectionY[6];
	float viewMtx[6][4][4];
	float projectionMtx[6][4][4];
	int setInstantly;
	unsigned int rainSfxSnd;
	sceneSfxUnit_s rainSfxUnit;
	int isMistOverrideActive;
};
////////////

/* 11854 */
struct skeletonManagerWorkspace_s
{
	dsPageList_s skeletonList;
};
////////////

/* 11855 */
struct sceneSfxListUnit_s
{
	unsigned int sfxLimit;
	dsLinkedListNode_s activeListSentinel;
	dsLinkedListNode_s requestListSentinel;
};

/* 11856 */
struct sceneSfxSoundSource_s
{
	audioCueHash_s cue;
	mlVec position;
	unsigned int sfxRef;
};

/* 11857 */
struct threadSpinLockNested_s
{
	volatile int lockedThread;
	int lockCount;
};

/* 11858 */
struct sceneSfxWorkspace_s
{
	unsigned int workspaceId;
	sceneSfxListUnit_s lists[2];
	int numSoundSources;
	sceneSfxSoundSource_s soundSourceList[10];
	threadSpinLockNested_s lock;
	int isPaused;
};
////////////
// 
/* 11859 */
struct threadSpinLock_s
{
	volatile int lockedThread;
};

/* 11860 */
struct sceneSfxOneShotWorkspace_s
{
	dsLinkedListNode_s sceneSfxOneShotListSentinel;
	threadSpinLock_s lock;
	int isPaused;
};

/* 11861 */
struct dsHandleWorkspace_s
{
	dsPageList_s handleMemory;
};
////////////

/* 11818 */
struct audioCueId_s
{
	char text[128];
};

/* 11862 */
struct sceneStreamUnit_s
{
	audioCueId_s audioCue;
	unsigned int sndRef;
	float runTimeVolumeScale;
	float fadeStartVolume;
	float fadeEndVolume;
	float fadeElapsedTime;
	float fadeDuration;
	unsigned char used;
	unsigned char isActive;
	unsigned char muteAmbient;
	unsigned char muteTune;
	char muteReferenceCount;
	unsigned char pad;
	unsigned char paused;
	unsigned char isSceneIndependant;
};

/* 11863 */
struct sceneStreamStack_s
{
	int stack[8];
	int numItems;
};

/* 11864 */
struct sceneStreamWorkspace_s
{
	sceneStreamUnit_s streamArray[16];
	sceneStreamStack_s ambientStack;
	sceneStreamStack_s tuneStack;
	float musicVolume;
	float ambientVolume;
	int fadeInFromTunePause;
	int guideActiveWhenPaused;
};

/* 11865 */
struct scriptListWorkspace_s
{
	dsList_s* scriptList;
};
////////////

struct D3DCommandBuffer;
struct sceneMainWorkspace_s;
struct avatarInst_s;
struct avatarThreadState_s;

/* 11867 */
struct rendermanagerSystemCommonRenderUnit_s
{
	int isValid;
	avatarInst_s* avatar;
	avatarThreadState_s* threadState;
};

/* 11868 */
struct rendermanagerSystemCommonInst_s_unnamed_tag_unnamed_tag
{
	rendermanagerSystemCommonRenderUnit_s renderUnitList[512];
	int renderUnitListSize;
};

/* 11869 */
struct rendermanagerSystemCommonInst_s_unnamed_tag
{
	D3DCommandBuffer* shadowDualCommandBuffer[2];
	int hasShadowDualCommandBufferBeenRendered[2];
	int isShadowDualPassBeingRendered[2];
	unsigned int shadowDualCommandBufferTickOfGeneration[2];
	unsigned int shadowDualCommandBufferMemoryUsed[2];
	unsigned int shadowDualCommandBufferMemoryRemaining[2];
	D3DCommandBuffer* shadowCubeCommandBuffer[2];
	int hasShadowCubeCommandBufferBeenRendered[2];
	int isShadowCubePassBeingRendered[2];
	unsigned int shadowCubeCommandBufferTickOfGeneration[2];
	unsigned int shadowCubeCommandBufferMemoryUsed[2];
	unsigned int shadowCubeCommandBufferMemoryRemaining[2];
	D3DCommandBuffer* shadowRegularCommandBuffer[2];
	int hasShadowRegularCommandBufferBeenRendered[2];
	int isShadowRegularPassBeingRendered[2];
	unsigned int shadowRegularCommandBufferTickOfGeneration[2];
	unsigned int shadowRegularCommandBufferMemoryUsed[2];
	unsigned int shadowRegularCommandBufferMemoryRemaining[2];
	D3DCommandBuffer* mainCommandBufferOpaque[2];
	int hasMainCommandBufferOpaqueBeenRendered[2];
	int isMainPassOpaqueBeingRendered[2];
	unsigned int mainCommandBufferOpaqueTickOfGeneration[2];
	unsigned int mainCommandBufferOpaqueMemoryUsed[2];
	unsigned int mainCommandBufferOpaqueMemoryRemaining[2];
	D3DCommandBuffer* mainCommandBufferTransparent[2];
	int hasMainCommandBufferTransparentBeenRendered[2];
	int isMainPassTransparentBeingRendered[2];
	unsigned int mainCommandBufferTransparentTickOfGeneration[2];
	unsigned int mainCommandBufferTransparentMemoryUsed[2];
	unsigned int mainCommandBufferTransparentMemoryRemaining[2];
	D3DCommandBuffer* postProcessCommandBuffer[2];
	int hasPostProcessCommandBufferBeenRendered[2];
	int isPostProcessBeingRendered[2];
	unsigned int postProcessCommandBufferTickOfGeneration[2];
	rendermanagerSystemCommonInst_s_unnamed_tag_unnamed_tag mainRenderList[2];
	int haveAllocated;
};

/* 4087 */
union $3F5BD159CB39977520C06306145A6051
{
	unsigned int RawEvent[4];
};


/* 11871 */
struct rendermanagerSystemCommonInst_s
{
	rendermanagerSystemCommonInst_s_unnamed_tag view[1];
	void(*mainPassSetupFunc)(sceneMainWorkspace_s*, int*);
	int haveInitialised;
	int cs;
};

/* 11872 */
struct sceneRenderManagerWorkspace_s
{
	rendermanagerSystemCommonInst_s system;
};

struct sceneAvatarThreadStateWorkspace_s;

////////////
/* 11719 */
struct sceneMainWorkspace_s
{
	assetId_s sceneName;
	sceneMode_e nextSceneMode;
	sceneMode_e mode;
	sceneMode_e wantedMode[8];
	int numModeChanges;
	sceneMode_e lastTickMode;
	int loading;
	int loadingTransitionTicked;
	int sceneDataLoaded;
	int ticksBeforeFadeUp;
	int toggleIndex;
	int poseIndex;
	padInfo_s* fixedPad;
	sceneActionWorkspace_s action;
	sceneAStarWorkspace_s aStar;
	sceneControlWorkspace_s control;
	sceneEffectWorkspace_s* effect;
	sceneExtentWorkspace_s extent;
	sceneFlagsWorkspace_s flags;
	sceneLookAtWorkspace_s lookat;
	sceneLightWorkspace_s* light;
	sceneDepthOfFieldWorkspace_s* dof;
	sceneMainKillWorkspace_s kill;
	sceneMainLoadWorkspace_s load;
	sceneMainLoadBackgroundWorkspace_s* loadbackground;
	sceneMainLoadSceneControlWorkspace_s* loadscenecontrol;
	sceneMarkerWorkspace_s* marker;
	sceneMultiplayerWorkspace_s multiplayer;
	sceneObjWorkspace_s obj;
	sceneObjDeflectWorkspace_s objdeflect;
	sceneObjHitWorkspaceMain_s* objhit;
	scenePartitionCubeWorkspace_s partition;
	scenePathObjectWorkspace_s pathobject;
	sceneRegionWorkspace_s region;
	sceneSkyDomeWorkspace_s skydome;
	sceneTargetWorkspace_s target;
	fxNextGenSceneWorkspace_s fxNextGen;
	sceneTimerWorkspace_s timer;
	cutsceneMainWorkspace_s cutscene;
	weatherObject_s* weather;
	skeletonManagerWorkspace_s* skeletonManager;
	sceneSfxWorkspace_s sfx;
	sceneSfxOneShotWorkspace_s sfxOneShot;
	dsHandleWorkspace_s handleWorkspace;
	sceneStreamWorkspace_s* stream;
	scriptListWorkspace_s scriptList;
	sceneRenderManagerWorkspace_s* renderManager;
	sceneAvatarThreadStateWorkspace_s* avatarThreadState;
	void* game;
	assetDbPackageManagerLoadUnit_s loadUnit;
};

enum dbTextureFormat_e : uint32_t
{
	dbTextureFormat_UNKNOWN = 0x0,
	dbTextureFormat_DXT1 = 0x1,
	dbTextureFormat_DXT3 = 0x2,
	dbTextureFormat_DXT5 = 0x3,
	dbTextureFormat_A8R8G8B8 = 0x4,
	dbTextureFormat_X8R8G8B8 = 0x5,
	dbTextureFormat_LIN_A8R8G8B8 = 0x6,
	dbTextureFormat_LIN_X8R8G8B8 = 0x7,
	dbTextureFormat_L8 = 0x8,
	dbTextureFormat_A8L8 = 0x9,
	dbTextureFormat_R5G6B5 = 0xA,
	dbTextureFormat_A4R4G4B4 = 0xB,
	dbTextureFormat_DXN = 0xC,
	dbTextureFormat_DXT3A = 0xD,
	dbTextureFormat_G8R8 = 0xE,
	dbTextureFormat_MAX = 0xF,
};

struct dbTexture_s
{
	dbTextureFormat_e format;
	int* d3dHeader;
	uint16_t width;
	uint16_t height;
	unsigned char type;
	unsigned char flags;
	unsigned char userDefined;
	unsigned char maxLOD;
	unsigned char framesPerSecond;
	unsigned char numFrames;
	unsigned char currentFrameLoaded;
	unsigned char requiredFrame;
	void* imageDataStart;
	unsigned int sizeOfOneFrame;
};

////////////////////////////////////////////

struct reqAnimal_Structure_s;
struct sceneMainWorkspace_s;
struct avatarInst_s;
struct gardenMainWidth_s;
struct gardenPerimeterBox_s;
struct gardenWayPointHub_s;
struct gardenHiddenItemsItem_s;
struct gardenBudgetClassUnit_s;
struct scenePinataFenceWorkspace_s;
struct scenePinataTriggerWorkspace_s;

struct supportPinataTimeWorkspace_s;

struct supportPinataLabelWorkspace_s;
struct generator2Generator_s;
struct actorInst_s;
struct entitySceneControlPinataStorkInst_s;
struct entitySceneControlPinataSeedosInst_s;
struct entitySceneControlPinataDastardosInst_s;
struct entitySceneControlPinataRuffiansInst_s;
struct entitySceneControlPinataBeggarTraderInst_s;
struct entitySceneControlPinataDedosInst_s;
struct entitySceneControlPinataChallengesRuntime_s;
struct entitySceneControlPinataLeaderboardsReadInst_s;
struct entitySceneControlPinataLeaderboardsWriteInst_s;
struct entitySceneControlPinataHelpersInst_s;
struct entitySceneControlPinataDoctorInst_s;
struct entitySceneControlPinataBuilderInst_s;
struct entitySceneControlPinataTinkerInst_s;
struct entitySceneControlPinataHunterInst_s;
struct entitySceneControlPinataStoreInst_s;
struct supportPinataAnimalEvolveButterfly_s;


/* 11972 */
struct gardenMainWorkspace_s_unnamed_tag
{
	assetId_s descAid;
	assetId_s timeSplineAid;
	int haveDiggableSurface;
	int unlockStuff;
	int unlockBasics;
	int haveTables;
	int startsWithGrass;
};

/* 11666 */
struct dsLinkedListNode_s;

/* 918 */
enum supportPinataAvatarEatMode_e : uint32_t
{
	modeNone = 0x0,
	modeBreakingUp = 0x1,
	modeBeingEaten = 0x2,
	modeFalling = 0x3,
	modeDisappearing = 0x4,
	modeEaten = 0x5,
	modeMAX = 0x6,
};

/* 1052 */
typedef supportPinataAvatarEatMode_e repositioningMode_e;

/* 11973 */
struct gardenPerimeterNumStones_s
{
	int level0_NumStones;
	int level1_NumStones;
	int level2_NumStones;
};

/* 11975 */
struct gardenPerimeterWorkspace_s
{
	dsLinkedListNode_s topEdgeSentinel;
	dsLinkedListNode_s bottomEdgeSentinel;
	dsLinkedListNode_s leftEdgeSentinel;
	dsLinkedListNode_s rightEdgeSentinel;
	int numEdgeStones;
	int prevNumEdgeStones;
	float prevStoneSpacing;
	float stoneSpacing;
	int numStonesWorking;
	float prevCloudCover;
	float prevPrecipitationLevel;
	gardenPerimeterNumStones_s numStones;
	gardenMainWidth_s* widthLevels;
};

/* 11977 */
struct gardenPerimeterBoxWorkspace_s
{
	int listCount;
	gardenPerimeterBox_s* list;
};

/* 11978 */
struct gardenSpaceWorkspace_s
{
	int virtualSpaceOccupiedTimesTen;
};

/* 11980 */
struct gardenWayPointWorkspace_s
{
	int hubCount;
	gardenWayPointHub_s* hubList;
};

/* 11981 */
struct gardenNameWorkspace_s
{
	char name[32];
};

/* 11982 */
struct gardenTotemPoleWorkspace_s
{
	avatarInst_s* base;
};

/* 11984 */
struct gardenHiddenItemsWorkspace_s_unnamed_tag
{
	int _small;
	int medium;
	int large;
};

/* 11818 */
struct audioCueId_s;

/* 11985 */
struct gardenHiddenItemsWorkspace_s
{
	float dimension;
	int maxItems;
	int numItems;
	gardenHiddenItemsItem_s* items;
	float itemRadius;
	float chance[7];
	gardenHiddenItemsWorkspace_s_unnamed_tag cashAmount;
	audioCueId_s sfx;
};

/* 11986 */
struct gardenPavingWorkspace_s
{
	int array[32][32];
};

/* 11987 */
struct gardenGlobalEffectsUnit_s
{
	int refCount;
	float value;
};

/* 11988 */
struct gardenGlobalEffectsWorkspace_s
{
	gardenGlobalEffectsUnit_s types[5];
};

/* 11989 */
struct gardenBudgetUnit_s
{
	unsigned int virtualMemory;
	unsigned int physicalMemory;
	unsigned int dualShadowBuffering;
	unsigned int cubeShadowBuffering;
	unsigned int regularShadowBuffering;
	unsigned int diggableSurfacePreDraw;
	unsigned int mainPassOpaque;
	unsigned int mainPassTransparent;
};

/* 905 */
enum supportPinataTag_e : uint32_t
{
	aRTrigger,
	aNull_0,
	Animal_aaaaaa,
	Animal_ant,
	Animal_beetle,
	Animal_badger,
	Animal_bat,
	Animal_bear,
	Animal_beaver,
	Animal_bee,
	Animal_blackbutterfly,
	Animal_bluebottle,
	Animal_bluebutterfly,
	Animal_boomslang,
	Animal_brownbutterfly,
	Animal_bushbaby,
	Animal_buzzard,
	Animal_spare90,
	Animal_canary,
	Animal_spare89,
	Animal_cat,
	Animal_chameleon,
	Animal_chicken,
	Animal_camel,
	Animal_cow,
	Animal_spare87,
	Animal_crocodile,
	Animal_crow,
	Animal_deer,
	Animal_spare86,
	Animal_dog,
	Animal_spare85,
	Animal_dragon,
	Animal_dragonfly,
	Animal_duck,
	Animal_spare84,
	Animal_eagle,
	Animal_spare83,
	Animal_elephant,
	Animal_firefly,
	Animal_firesalamander,
	Animal_spare81,
	Animal_flyingpig,
	Animal_fox,
	Animal_frog,
	Animal_gecko,
	Animal_gerbil,
	Animal_spare80,
	Animal_spare79,
	Animal_spare78,
	Animal_spare76,
	Animal_spare75,
	Animal_goose,
	Animal_spare74,
	Animal_grasssnake,
	Animal_greenbutterfly,
	Animal_spare73,
	Animal_spare72,
	Animal_hedgehog,
	Animal_hippo,
	Animal_horse,
	Animal_hyena,
	Animal_hydra,
	Animal_lemming,
	Animal_lemmingpest,
	Animal_spare67,
	Animal_spare66,
	Animal_spare65,
	Animal_spare64,
	Animal_lion,
	Animal_spare63,
	Animal_spare62,
	Animal_spare61,
	Animal_mandrill,
	Animal_spare60,
	Animal_mole,
	Animal_spare59,
	Animal_monkey,
	Animal_moose,
	Animal_moth,
	Animal_mouse,
	Animal_newt,
	Animal_spare57,
	Animal_orangebutterfly,
	Animal_ostrich,
	Animal_spare55,
	Animal_spare54,
	Animal_parrot,
	Animal_polarbear,
	Animal_penguin,
	Animal_pig,
	Animal_pigeon,
	Animal_poisonfrog,
	Animal_pinkbutterfly,
	Animal_pony,
	Animal_purplebutterfly,
	Animal_rabbit,
	Animal_raccoon,
	Animal_spare50,
	Animal_spare49,
	Animal_redbutterfly,
	Animal_spare48,
	Animal_spare47,
	Animal_robin,
	Animal_spare45,
	Animal_spare44,
	Animal_salamander,
	Animal_spare43,
	Animal_sheep,
	Animal_scorpion,
	Animal_scorpionpest,
	Animal_spare40,
	Animal_sparrow,
	Animal_spider,
	Animal_squirrel,
	Animal_spare39,
	Animal_spare38,
	Animal_spare37,
	Animal_spare36,
	Animal_swan,
	Animal_spare35,
	Animal_spare34,
	Animal_spare33,
	Animal_spare32,
	Animal_spare31,
	Animal_spare30,
	Animal_unicorn,
	Animal_batpest,
	Animal_spare29,
	Animal_vulture,
	Animal_spare27,
	Animal_whitebutterfly,
	Animal_spare26,
	Animal_wolf,
	Animal_yeti,
	Animal_worm,
	Animal_yak,
	Animal_yellowbutterfly,
	Animal_zebra,
	Animal_slugpest,
	Animal_spare23,
	Animal_spare22,
	Animal_spare21,
	Animal_spare20,
	Animal_spare19,
	Animal_spare18,
	Animal_crowpest,
	Animal_raccoonpest,
	Animal_crocodilepest,
	Animal_spare17,
	Animal_molepest,
	Animal_spare16,
	Animal_spare15,
	Animal_spare14,
	Animal_spare13,
	Animal_wolfpest,
	Animal_mandrillpest,
	Animal_spare12,
	Animal_spare11,
	Animal_snail,
	Animal_snailpest,
	Animal_spare3,
	Animal_spare4,
	Animal_spare5,
	Animal_spare6,
	Animal_spare7,
	Animal_spare8,
	Animal_spare9,
	Animal_graysquirrel,
	Animal_zzzzzz,
	Crate_aaaaaa,
	Crate_regular,
	Crate_received,
	Crate_factory,
	Crate_spare3,
	Crate_spare4,
	Crate_spare5,
	Crate_spare6,
	Crate_spare7,
	Crate_spare8,
	Crate_spare9,
	Crate_spare10,
	Crate_zzzzzz,
	Egg_aaaaaa,
	Egg_ant,
	Egg_spare11,
	Egg_badger,
	Egg_bat,
	Egg_bear,
	Egg_beaver,
	Egg_bee,
	Egg_spare12,
	Egg_bluebottle,
	Egg_bluebutterfly,
	Egg_boomslang,
	Egg_bushbaby,
	Egg_buzzard,
	Egg_spare14,
	Egg_canary,
	Egg_spare15,
	Egg_cat,
	Egg_chameleon,
	Egg_chicken,
	Egg_spare16,
	Egg_spare17,
	Egg_crocodile,
	Egg_crow,
	Egg_deer,
	Egg_spare18,
	Egg_dog,
	Egg_spare19,
	Egg_dragon,
	Egg_dragonfly,
	Egg_duck,
	Egg_spare21,
	Egg_eagle,
	Egg_spare22,
	Egg_elephant,
	Egg_firefly,
	Egg_firesalamander,
	Egg_spare24,
	Egg_flyingpig,
	Egg_fox,
	Egg_frog,
	Egg_spare25,
	Egg_spare26,
	Egg_spare27,
	Egg_spare28,
	Egg_spare29,
	Egg_spare30,
	Egg_spare31,
	Egg_goose,
	Egg_spare32,
	Egg_grasssnake,
	Egg_greenbutterfly,
	Egg_spare33,
	Egg_spare34,
	Egg_hedgehog,
	Egg_hippo,
	Egg_horse,
	Egg_hydra,
	Egg_spare36,
	Egg_spare37,
	Egg_spare38,
	Egg_spare39,
	Egg_spare40,
	Egg_spare41,
	Egg_spare42,
	Egg_lion,
	Egg_spare43,
	Egg_spare44,
	Egg_spare45,
	Egg_mandrill,
	Egg_spare46,
	Egg_mole,
	Egg_spare47,
	Egg_monkey,
	Egg_spare48,
	Egg_moth,
	Egg_mouse,
	Egg_newt,
	Egg_spare49,
	Egg_orangebutterfly,
	Egg_spare50,
	Egg_spare51,
	Egg_spare52,
	Egg_parrot,
	Egg_spare53,
	Egg_spare54,
	Egg_pig,
	Egg_pigeon,
	Egg_poisonfrog,
	Egg_spare55,
	Egg_pony,
	Egg_purplebutterfly,
	Egg_rabbit,
	Egg_raccoon,
	Egg_spare56,
	Egg_spare57,
	Egg_redbutterfly,
	Egg_spare58,
	Egg_spare59,
	Egg_spare60,
	Egg_spare61,
	Egg_spare62,
	Egg_space102,
	Egg_spare63,
	Egg_sheep,
	Egg_spare64,
	Egg_spare65,
	Egg_spare66,
	Egg_sparrow,
	Egg_spider,
	Egg_squirrel,
	Egg_spare67,
	Egg_spare68,
	Egg_spare69,
	Egg_spare70,
	Egg_swan,
	Egg_spare71,
	Egg_spare72,
	Egg_spare73,
	Egg_spare74,
	Egg_spare75,
	Egg_spare76,
	Egg_spare77,
	Egg_unicorn,
	Egg_batpest,
	Egg_spare78,
	Egg_spare79,
	Egg_spare80,
	Egg_whitebutterfly,
	Egg_wolf,
	Egg_spare81,
	Egg_worm,
	Egg_spare82,
	Egg_yellowbutterfly,
	Egg_zebra,
	Egg_spare1,
	Egg_cow,
	Egg_snail,
	Egg_spare2,
	Egg_spare3,
	Egg_spare4,
	Egg_spare5,
	Egg_spare6,
	Egg_spare7,
	Egg_spare8,
	Egg_spare9,
	Egg_spare10,
	Egg_zzzzzz,
	Fruit_aaaaaa,
	Fruit_acorn,
	Fruit_apple,
	Fruit_banana,
	Fruit_cherry,
	Fruit_coconut,
	Fruit_deadlynightshade,
	Fruit_fircone,
	Fruit_gem,
	Fruit_hazelnut,
	Fruit_helper,
	Fruit_monkeynut,
	Fruit_orange,
	Fruit_raspberry,
	Fruit_hollyberry,
	Fruit_blackberry,
	Fruit_gooseberry,
	Fruit_cucumber,
	Fruit_biftreetest,
	Fruit_bluegem,
	Fruit_greengem,
	Fruit_purplegem,
	Fruit_redgem,
	Fruit_yellowgem,
	Fruit_spare7,
	Fruit_spare8,
	Fruit_spare9,
	Fruit_hippyapple,
	Fruit_zzzzzz,
	Helper_aaaaaa,
	Helper_weeder,
	Helper_dedos,
	Helper_beggartrader,
	Helper_stork,
	Helper_waterer,
	Helper_seedos,
	Helper_tinker,
	Helper_miner,
	Helper_ruffian3,
	Helper_ruffian1,
	Helper_ruffian2,
	Helper_ruffian4,
	Helper_doctor,
	Helper_petshopowner,
	Helper_spare15,
	Helper_harvester,
	Helper_groundskeeper,
	Helper_groundskeepernight,
	Helper_jardiniero,
	Helper_builder,
	Helper_dastardos,
	Helper_professor,
	Helper_spare23,
	Helper_spare24,
	Helper_spare25,
	Helper_spare26,
	Helper_spare27,
	Helper_spare28,
	Helper_spare29,
	Helper_spare30,
	Helper_spare31,
	Helper_spare32,
	Helper_spare33,
	Helper_spare34,
	Helper_spare35,
	Helper_spare36,
	Helper_zzzzzz,
	Seed_aaaaaa,
	Seed_carrot,
	Seed_turnip,
	Seed_spare3,
	Seed_pumpkin,
	Seed_chilli,
	Seed_testveg,
	Seed_nstestveg,
	Seed_maize,
	Seed_radish,
	Seed_yam,
	Seed_daisy,
	Seed_buttercup,
	Seed_bluebell,
	Seed_poppy,
	Seed_sunflower,
	Seed_tulip,
	Seed_snapdragon,
	Seed_birdofparadiseplant,
	Seed_orchid,
	Seed_testflower,
	Seed_snowdrop,
	Seed_cactus,
	Seed_spare5,
	Seed_spare6,
	Seed_spare7,
	Seed_spare8,
	Seed_spare9,
	Seed_spare10,
	Seed_blackbuttercup,
	Seed_watercress,
	Seed_waterlily,
	Seed_bulrush,
	Seed_spare12,
	Seed_spare13,
	Seed_spare14,
	Seed_spare15,
	Seed_thistle,
	Seed_poisonivy,
	Seed_toadstool,
	Seed_venusflytrap,
	Seed_tumbleweed,
	Seed_fireweed,
	Seed_spare18,
	Seed_spare19,
	Seed_spare20,
	Seed_spare21,
	Seed_test,
	Seed_apple,
	Seed_hazelnut,
	Seed_oak,
	Seed_fir,
	Seed_blackberrybush,
	Seed_banana,
	Seed_gooseberrybush,
	Seed_gem,
	Seed_helper,
	Seed_monkeynut,
	Seed_nightshadebush,
	Seed_nstest,
	Seed_hippyapple,
	Seed_hollybush,
	Seed_orange,
	Seed_spart25,
	Seed_spare26,
	Seed_workeb1,
	Seed_workeb2,
	Seed_zzzzzz,
	SeedHole_aaaaaa,
	SeedHole,
	SeedHole_zzzzzz,
	Home_aaaaaa,
	Home_ant,
	Home_gym,
	Home_badger,
	Home_bat,
	Home_bear,
	Home_beaver,
	Home_bee,
	Home_beetle,
	Home_bluebottle,
	Home_butterfly,
	Home_boomslang,
	Home_beeshed,
	Home_bushbaby,
	Home_buzzard,
	Home_spare13,
	Home_canary,
	Home_spare14,
	Home_cat,
	Home_chameleon,
	Home_chicken,
	Home_spare15,
	Home_cow,
	Home_cowshed,
	Home_crocodile,
	Home_crow,
	Home_deer,
	Home_spare17,
	Home_dog,
	Home_spare18,
	Home_dragon,
	Home_dragonfly,
	Home_duck,
	Home_spare19,
	Home_eagle,
	Home_spare20,
	Home_elephant,
	Home_firefly,
	Home_firesalamander,
	Home_spare22,
	Home_flyingpig,
	Home_fox,
	Home_frog,
	Home_spare23,
	Home_spare24,
	Home_spare25,
	Home_spare26,
	Home_spare27,
	Home_spare28,
	Home_spare29,
	Home_goose,
	Home_spare30,
	Home_grasssnake,
	Home_spare11,
	Home_spare32,
	Home_spare33,
	Home_hedgehog,
	Home_hippo,
	Home_horse,
	Home_hydra,
	Home_spare35,
	Home_spare36,
	Home_spare37,
	Home_spare38,
	Home_spare39,
	Home_spare40,
	Home_spare41,
	Home_lion,
	Home_spare42,
	Home_spare43,
	Home_spare44,
	Home_mandrill,
	Home_spare45,
	Home_mole,
	Home_spare46,
	Home_monkey,
	Home_spare47,
	Home_moth,
	Home_mouse,
	Home_newt,
	Home_spare48,
	Home_spare49,
	Home_spare50,
	Home_spare51,
	Home_spare52,
	Home_parrot,
	Home_spare53,
	Home_spare54,
	Home_pig,
	Home_pigeon,
	Home_poisonfrog,
	Home_spare55,
	Home_pony,
	Home_spare86,
	Home_rabbit,
	Home_raccoon,
	Home_spare56,
	Home_spare57,
	Home_spare58,
	Home_spare59,
	Home_spare60,
	Home_spare61,
	Home_spare62,
	Home_spare63,
	Home_salamander,
	Home_spare64,
	Home_sheep,
	Home_sheepshed,
	Home_spare66,
	Home_spare67,
	Home_sparrow,
	Home_spider,
	Home_squirrel,
	Home_spare68,
	Home_spare69,
	Home_spare70,
	Home_spare71,
	Home_swan,
	Home_spare72,
	Home_spare73,
	Home_spare74,
	Home_spare75,
	Home_spare76,
	Home_spare77,
	Home_unicorn,
	Home_spare87,
	Home_spare78,
	Home_spare79,
	Home_spare80,
	Home_spare81,
	Home_spare82,
	Home_wolf,
	Home_spare83,
	Home_worm,
	Home_spare84,
	Home_spare85,
	Home_zebra,
	Home_snail,
	Home_helpermine,
	Home_animalgym,
	Home_seedos,
	Home_storkos,
	Home_dastardos,
	Home_dedos,
	Home_helperhomeone,
	Home_spare9,
	Home_spare10,
	Home_zzzzzz,
	Surface_aaaaaa,
	Surface_soil,
	Surface_sand,
	Surface_snow,
	Surface_grass,
	Surface_mud,
	Surface_grasslong,
	Surface_slabs,
	Surface_gravel,
	Surface_boundary,
	Surface_exterior,
	Surface_shallowWater,
	Surface_deepWater,
	Surface_plants,
	Surface_hardsoil,
	Surface_zzzzzz,
	Produce_aaaaaa,
	Produce_honey,
	Produce_milk,
	Produce_wool,
	Produce_dung,
	Produce_goldegg,
	Produce_spare6,
	Produce_rainbowgem,
	Produce_crown,
	Produce_clothes,
	Produce_toffee,
	Produce_cheese,
	Produce_bread,
	Produce_jackolantern,
	Produce_jam,
	Produce_medicine,
	Produce_mushroom,
	Produce_sandwich,
	Produce_sapphire,
	Produce_diamond,
	Produce_minemud,
	Produce_largegoldnugget,
	Produce_smallgoldnugget,
	Produce_gooseberrypie,
	Produce_peanutbutter,
	Produce_bananasplit,
	Produce_bone,
	Produce_carrotcake,
	Produce_toffeeapple,
	Produce_emerald,
	Produce_zzzzzz,
	Prop_aaaaaa,
	Prop_lantern,
	Prop_statue,
	Prop_patioheater,
	Prop_perimeterstone,
	Prop_gravestone,
	Prop_dedoslawn,
	Prop_banjostatue,
	Prop_japaneseornament,
	Prop_plantstunter,
	Prop_birdbath1,
	Prop_birdbath2,
	Prop_watertrough,
	Prop_housestones,
	Prop_surfboard,
	Prop_windchime,
	Prop_haybail,
	Prop_milkchurn,
	Prop_log,
	Prop_smallfountain,
	Prop_fountain1,
	Prop_fountain2,
	Prop_glowrock,
	Prop_lavapool,
	Prop_leafpile,
	Prop_hydrapot,
	Prop_barrel,
	Prop_bamboopole,
	Prop_sword,
	Prop_woodenflower,
	Prop_cartwheel,
	Prop_oillamp,
	Prop_lamppost,
	Prop_glowglobe,
	Prop_jamjarcandle,
	Prop_moonlantern,
	Prop_tombstone,
	Prop_flag1,
	Prop_rainbow2,
	Prop_toxicbarrel,
	Prop_sundial1,
	Prop_sundial2,
	Prop_horselantern,
	Prop_minerslantern,
	Prop_flag2,
	Prop_flag3,
	Prop_flag4,
	Prop_roadsign1,
	Prop_roadsign2,
	Prop_roadsign3,
	Prop_boulders1,
	Prop_boulders2,
	Prop_stonehenge,
	Prop_lolly1,
	Prop_lolly2,
	Prop_lolly3,
	Prop_wirehearts,
	Prop_scarecrow,
	Prop_pantsstatue,
	Prop_sabremanstatue,
	Prop_kameostatue,
	Prop_jetpacstatue,
	Prop_cooperstatue,
	Prop_jinjostatue,
	Prop_chimney,
	Prop_windflower,
	Prop_post1,
	Prop_post2,
	Prop_windturbine,
	Prop_wishingwell,
	Prop_lawnmower,
	Prop_gnome,
	Prop_gift,
	Prop_shoppingbasket,
	Prop_journal,
	Prop_spade,
	Prop_romancesweet,
	Prop_background_prop,
	Prop_gazebo,
	Prop_pot1,
	Prop_gardenjunk80,
	Prop_gardenjunk81,
	Prop_gardenjunk82,
	Prop_gardenjunk83,
	Prop_gardenjunk84,
	Prop_gardenjunk85,
	Prop_gardenjunk86,
	Prop_gardenjunk87,
	Prop_gardenjunk88,
	Prop_gardenjunk89,
	Prop_gardenjunk90,
	Prop_mumbostatue,
	Prop_firtreelog,
	Prop_rainbow,
	Prop_appletreelog,
	Prop_junkdrum,
	Prop_junkskip,
	Prop_junkhomechicken,
	Prop_junkfryingpan,
	Prop_junkhomespider,
	Prop_junkhomemandrill,
	Prop_jamjar,
	Prop_oillmap,
	Prop_vase,
	Prop_windchime2,
	Prop_sword2,
	Prop_gbtgarcademachine,
	Prop_gardenjunk107,
	Prop_gardenjunk108,
	Prop_gardenjunk109,
	Prop_gardenjunk110,
	Prop_gardenjunk111,
	Prop_gardenjunk112,
	Prop_gardenjunk113,
	Prop_gardenjunk114,
	Prop_gardenjunk115,
	Prop_gardenjunk116,
	Prop_gardenjunk117,
	Prop_gardenjunk118,
	Prop_gardenjunk119,
	Prop_perimeterstone1,
	Prop_perimeterstone2,
	Prop_perimeterstone3,
	Prop_perimeterstone4,
	Prop_perimeterstone5,
	Prop_pot2,
	Prop_windsock,
	Prop_sculpture1,
	Prop_sculpture2,
	Prop_logojp,
	Prop_totembase,
	Prop_totembat,
	Prop_totemcrocodile,
	Prop_totemcrow,
	Prop_totemmandrill,
	Prop_totemmole,
	Prop_totemraccoon,
	Prop_totemsnail,
	Prop_totemwolf,
	Prop_logo,
	Prop_zzzzzz,
	WateringCan_aaaaaa,
	WateringCan_1,
	WateringCan_2,
	WateringCan_3,
	WateringCan_4,
	WateringCan_5,
	WateringCan_6,
	WateringCan_7,
	WateringCan_8,
	WateringCan_9,
	WateringCan_10,
	WateringCan_11,
	WateringCan_12,
	WateringCan_13,
	WateringCan_14,
	WateringCan_15,
	WateringCan_16,
	WateringCan_17,
	WateringCan_18,
	WateringCan_19,
	WateringCan_20,
	WateringCan_zzzzzz,
	Packet_aaaaaa,
	Packet_grass,
	Packet_grasslong,
	Packet_sand,
	Packet_snow,
	Packet_5,
	Packet_6,
	Packet_7,
	Packet_8,
	Packet_9,
	Packet_10,
	Packet_11,
	Packet_12,
	Packet_13,
	Packet_14,
	Packet_15,
	Packet_16,
	Packet_17,
	Packet_18,
	Packet_19,
	Packet_20,
	Packet_zzzzzz,
	Fence_aaaaaa,
	Fence_twobar,
	Fence_twobargate,
	Fence_hedge,
	Fence_herringbone,
	Fence_stone,
	Fence_irongate,
	Fence_oakgate,
	Fence_picket,
	Fence_wire,
	Fence_iron,
	Fence_velvetrope,
	Fence_spare10,
	Fence_zzzzzz,
	Money_aaaaaa,
	Money_bronze,
	Money_silver,
	Money_gold,
	Money_biggold,
	Money_spare4,
	Money_spare5,
	Money_spare6,
	Money_spare7,
	Money_spare8,
	Money_spare9,
	Money_spare10,
	Money_zzzzzz,
	BifTree_aaaaaa,
	BifTree_test,
	BifTree_apple,
	BifTree_hazelnut,
	BifTree_oak,
	BifTree_fir,
	BifTree_blackberrybush,
	BifTree_banana,
	BifTree_gooseberrybush,
	BifTree_gem,
	BifTree_helper,
	BifTree_monkeynut,
	BifTree_nightshadebush,
	BifTree_nstest,
	BifTree_hollybush,
	BifTree_orange,
	BifTree_spare1,
	BifTree_spart2,
	BifTree_spare3,
	BifTree_spare4,
	BifTree_spare5,
	BifTree_hippyapple,
	BifTree_spare6,
	BifTree_spare7,
	BifTree_spare8,
	BifTree_spare9,
	BifTree_spare10,
	BifTree_spare11,
	BifTree_spare12,
	BifTree_spare13,
	BifTree_spare14,
	BifTree_zzzzzz,
	CameraTarget_aaaaaa,
	CameraTarget,
	CameraTarget_zzzzzz,
	FruitPoint_aaaaaa,
	FruitPoint,
	FruitPoint_zzzzzz,
	Camera_aaaaaa,
	Camera,
	Camera_zzzzzz,
	Fighter_aaaaaa,
	Fighter,
	Fighter_zzzzzz,
	Background_aaaaaa,
	Background,
	Background_garden,
	Background_zzzzzz,
	BifPlant_aaaaaa,
	BifPlant_carrot,
	BifPlant_turnip,
	BifPlant_spare3,
	BifPlant_pumpkin,
	BifPlant_chilli,
	BifPlant_testveg,
	BifPlant_nstestveg,
	BifPlant_maize,
	BifPlant_radish,
	BifPlant_yam,
	BifPlant_daisy,
	BifPlant_buttercup,
	BifPlant_bluebell,
	BifPlant_poppy,
	BifPlant_sunflower,
	BifPlant_tulip,
	BifPlant_snapdragon,
	BifPlant_birdofparadiseplant,
	BifPlant_orchid,
	BifPlant_testflower,
	BifPlant_snowdrop,
	BifPlant_cactus,
	BifPlant_spare23,
	BifPlant_spare24,
	BifPlant_spare25,
	BifPlant_spare26,
	BifPlant_spare27,
	BifPlant_spare28,
	BifPlant_blackbuttercup,
	BifPlant_watercress,
	BifPlant_waterlily,
	BifPlant_bulrush,
	BifPlant_spare33,
	BifPlant_spare34,
	BifPlant_spare35,
	BifPlant_spare36,
	BifPlant_thistle,
	BifPlant_poisonivy,
	BifPlant_toadstool,
	BifPlant_venusflytrap,
	BifPlant_tumbleweed,
	BifPlant_fireweed,
	BifPlant_spare43,
	BifPlant_spare44,
	BifPlant_spare45,
	BifPlant_spare46,
	BifPlant_zzzzzz,
	Spade_aaaaaa,
	Spade,
	Spade_zzzzzz,
	SpadePart_aaaaaa,
	SpadePart_Head_aaaaaa,
	SpadePart_head1,
	SpadePart_head2,
	SpadePart_head3,
	SpadePart_head4,
	SpadePart_head5,
	SpadePart_head6,
	SpadePart_head7,
	SpadePart_head8,
	SpadePart_head9,
	SpadePart_head10,
	SpadePart_head11,
	SpadePart_head12,
	SpadePart_head13,
	SpadePart_head14,
	SpadePart_head15,
	SpadePart_head16,
	SpadePart_head17,
	SpadePart_head18,
	SpadePart_head19,
	SpadePart_head20,
	SpadePart_Head_zzzzzz,
	SpadePart_Handle_aaaaaa,
	SpadePart_handle1,
	SpadePart_handle2,
	SpadePart_handle3,
	SpadePart_handle4,
	SpadePart_handle5,
	SpadePart_handle6,
	SpadePart_handle7,
	SpadePart_handle8,
	SpadePart_handle9,
	SpadePart_handle10,
	SpadePart_handle11,
	SpadePart_handle12,
	SpadePart_handle13,
	SpadePart_handle14,
	SpadePart_handle15,
	SpadePart_handle16,
	SpadePart_handle17,
	SpadePart_handle18,
	SpadePart_handle19,
	SpadePart_handle20,
	SpadePart_Handle_zzzzzz,
	SpadePart_Extra_aaaaaa,
	SpadePart_extra1,
	SpadePart_extra2,
	SpadePart_extra3,
	SpadePart_extra4,
	SpadePart_extra5,
	SpadePart_extra6,
	SpadePart_extra7,
	SpadePart_extra8,
	SpadePart_extra9,
	SpadePart_extra10,
	SpadePart_extra11,
	SpadePart_extra12,
	SpadePart_extra13,
	SpadePart_extra14,
	SpadePart_extra15,
	SpadePart_extra16,
	SpadePart_extra17,
	SpadePart_extra18,
	SpadePart_extra19,
	SpadePart_extra20,
	SpadePart_Extra_zzzzzz,
	SpadePart_zzzzzz,
	Cursor_aaaaaa,
	Cursor_inner,
	Cursor_outer,
	Cursor_zzzzzz,
	Projectile_aaaaaa,
	Projectile_ant,
	Projectile_beetle,
	Projectile_badger,
	Projectile_bat,
	Projectile_bear,
	Projectile_beaver,
	Projectile_bee,
	Projectile_blackbutterfly,
	Projectile_bluebottle,
	Projectile_bluebutterfly,
	Projectile_boomslang,
	Projectile_brownbutterfly,
	Projectile_bushbaby,
	Projectile_buzzard,
	Projectile_spare90,
	Projectile_canary,
	Projectile_spare89,
	Projectile_cat,
	Projectile_chameleon,
	Projectile_chicken,
	Projectile_camel,
	Projectile_cow,
	Projectile_spare87,
	Projectile_crocodile,
	Projectile_crow,
	Projectile_deer,
	Projectile_spare86,
	Projectile_dog,
	Projectile_spare85,
	Projectile_dragon,
	Projectile_dragonfly,
	Projectile_duck,
	Projectile_spare84,
	Projectile_eagle,
	Projectile_spare83,
	Projectile_elephant,
	Projectile_firefly,
	Projectile_firesalamander,
	Projectile_spare81,
	Projectile_flyingpig,
	Projectile_fox,
	Projectile_frog,
	Projectile_gecko,
	Projectile_gerbil,
	Projectile_spare80,
	Projectile_spare79,
	Projectile_spare78,
	Projectile_spare76,
	Projectile_spare75,
	Projectile_goose,
	Projectile_spare74,
	Projectile_grasssnake,
	Projectile_greenbutterfly,
	Projectile_spare73,
	Projectile_spare72,
	Projectile_hedgehog,
	Projectile_hippo,
	Projectile_horse,
	Projectile_hyena,
	Projectile_hydra,
	Projectile_lemming,
	Projectile_lemmingpest,
	Projectile_spare67,
	Projectile_spare66,
	Projectile_spare65,
	Projectile_spare64,
	Projectile_lion,
	Projectile_spare63,
	Projectile_spare62,
	Projectile_spare61,
	Projectile_mandrill,
	Projectile_spare60,
	Projectile_mole,
	Projectile_spare59,
	Projectile_monkey,
	Projectile_moose,
	Projectile_moth,
	Projectile_mouse,
	Projectile_newt,
	Projectile_spare57,
	Projectile_orangebutterfly,
	Projectile_ostrich,
	Projectile_spare55,
	Projectile_spare54,
	Projectile_parrot,
	Projectile_polarbear,
	Projectile_penguin,
	Projectile_pig,
	Projectile_pigeon,
	Projectile_poisonfrog,
	Projectile_pinkbutterfly,
	Projectile_pony,
	Projectile_purplebutterfly,
	Projectile_rabbit,
	Projectile_raccoon,
	Projectile_spare50,
	Projectile_spare49,
	Projectile_redbutterfly,
	Projectile_spare48,
	Projectile_spare47,
	Projectile_robin,
	Projectile_spare45,
	Projectile_spare44,
	Projectile_salamander,
	Projectile_spare43,
	Projectile_sheep,
	Projectile_scorpion,
	Projectile_scorpionpest,
	Projectile_spare40,
	Projectile_sparrow,
	Projectile_spider,
	Projectile_squirrel,
	Projectile_spare39,
	Projectile_spare38,
	Projectile_spare37,
	Projectile_spare36,
	Projectile_swan,
	Projectile_spare35,
	Projectile_spare34,
	Projectile_spare33,
	Projectile_spare32,
	Projectile_spare31,
	Projectile_spare30,
	Projectile_unicorn,
	Projectile_batpest,
	Projectile_spare29,
	Projectile_vulture,
	Projectile_spare27,
	Projectile_whitebutterfly,
	Projectile_spare26,
	Projectile_wolf,
	Projectile_yeti,
	Projectile_worm,
	Projectile_yak,
	Projectile_yellowbutterfly,
	Projectile_zebra,
	Projectile_slugpest,
	Projectile_spare23,
	Projectile_spare22,
	Projectile_spare21,
	Projectile_spare20,
	Projectile_spare19,
	Projectile_spare18,
	Projectile_crowpest,
	Projectile_raccoonpest,
	Projectile_crocodilepest,
	Projectile_spare17,
	Projectile_molepest,
	Projectile_spare16,
	Projectile_spare15,
	Projectile_spare14,
	Projectile_spare13,
	Projectile_wolfpest,
	Projectile_mandrillpest,
	Projectile_spare12,
	Projectile_spare11,
	Projectile_snail,
	Projectile_snailpest,
	Projectile_spare3,
	Projectile_spare4,
	Projectile_spare5,
	Projectile_spare6,
	Projectile_spare7,
	Projectile_spare8,
	Projectile_spare9,
	Projectile_graysquirrel,
	Projectile_venusflytrap,
	Projectile_loather,
	Projectile_zzzzzz,
	Sweet_aaaaaa,
	Sweet_pinata,
	Sweet_super,
	Sweet_bad,
	Sweet_testdizzy,
	Sweet_testsick,
	Sweet_testangry,
	Sweet_testscared,
	Sweet_testcheered,
	Sweet_testwhacked,
	Sweet_testprice,
	Sweet_testbecomeresident,
	Sweet_testbecomenonresident,
	Sweet_testgrowup,
	Sweet_testexplode,
	Sweet_testsleep,
	Sweet_testeat,
	Sweet_testbecomeyoung,
	Sweet_happy,
	Sweet_joyous,
	Sweet_testpoison,
	Sweet_romance,
	Sweet_spare22,
	Sweet_spare23,
	Sweet_spare24,
	Sweet_spare25,
	Sweet_spare26,
	Sweet_spare27,
	Sweet_spare28,
	Sweet_spare29,
	Sweet_zzzzzz,
	Bud_aaaaaa,
	Bud_test,
	Bud_apple,
	Bud_blackberry,
	Bud_orange,
	Bud_hollybush,
	Bud_spare6,
	Bud_spare7,
	Bud_spare8,
	Bud_spare9,
	Bud_spare10,
	Bud_spare11,
	Bud_spare12,
	Bud_spare13,
	Bud_spare14,
	Bud_spare15,
	Bud_spare16,
	Bud_spare17,
	Bud_spare18,
	Bud_spare19,
	Bud_spare20,
	Bud_spare21,
	Bud_spare22,
	Bud_hazelnut,
	Bud_oak,
	Bud_fir,
	Bud_hippyapple,
	Bud_banana,
	Bud_gooseberrybush,
	Bud_gem,
	Bud_helper,
	Bud_monkeynut,
	Bud_deadlynightshade,
	Bud_zzzzzz,
	Paving_aaaaaa,
	Paving_slab,
	Paving_stone,
	Paving_block,
	Paving_crazy,
	Paving_open,
	Paving_cobble,
	Paving_decking,
	Paving_lillypad,
	Paving_hollywood,
	Paving_octagonal,
	Paving_spare_10,
	Paving_spare_11,
	Paving_spare_12,
	Paving_spare_13,
	Paving_spare_14,
	Paving_spare_15,
	Paving_spare_16,
	Paving_spare_17,
	Paving_spare_18,
	Paving_spare_19,
	Paving_spare_20,
	Paving_zzzzzz,
	HouseBlock_aaaaaa,
	HouseBlock_ant,
	HouseBlock_gym,
	HouseBlock_badger,
	HouseBlock_bat,
	HouseBlock_bear,
	HouseBlock_beaver,
	HouseBlock_bee,
	HouseBlock_beetle,
	HouseBlock_bluebottle,
	HouseBlock_butterfly,
	HouseBlock_boomslang,
	HouseBlock_beeshed,
	HouseBlock_bushbaby,
	HouseBlock_buzzard,
	HouseBlock_spare13,
	HouseBlock_canary,
	HouseBlock_spare14,
	HouseBlock_cat,
	HouseBlock_chameleon,
	HouseBlock_chicken,
	HouseBlock_spare15,
	HouseBlock_cow,
	HouseBlock_cowshed,
	HouseBlock_crocodile,
	HouseBlock_crow,
	HouseBlock_deer,
	HouseBlock_spare17,
	HouseBlock_dog,
	HouseBlock_spare18,
	HouseBlock_dragon,
	HouseBlock_dragonfly,
	HouseBlock_duck,
	HouseBlock_spare19,
	HouseBlock_eagle,
	HouseBlock_spare20,
	HouseBlock_elephant,
	HouseBlock_firefly,
	HouseBlock_firesalamander,
	HouseBlock_spare22,
	HouseBlock_flyingpig,
	HouseBlock_fox,
	HouseBlock_frog,
	HouseBlock_spare23,
	HouseBlock_spare24,
	HouseBlock_spare25,
	HouseBlock_spare26,
	HouseBlock_spare27,
	HouseBlock_spare28,
	HouseBlock_spare29,
	HouseBlock_goose,
	HouseBlock_spare30,
	HouseBlock_grasssnake,
	HouseBlock_spare11,
	HouseBlock_spare32,
	HouseBlock_spare33,
	HouseBlock_hedgehog,
	HouseBlock_hippo,
	HouseBlock_horse,
	HouseBlock_hydra,
	HouseBlock_spare35,
	HouseBlock_spare36,
	HouseBlock_spare37,
	HouseBlock_spare38,
	HouseBlock_spare39,
	HouseBlock_spare40,
	HouseBlock_spare41,
	HouseBlock_lion,
	HouseBlock_spare42,
	HouseBlock_spare43,
	HouseBlock_spare44,
	HouseBlock_mandrill,
	HouseBlock_spare45,
	HouseBlock_mole,
	HouseBlock_spare46,
	HouseBlock_monkey,
	HouseBlock_spare47,
	HouseBlock_moth,
	HouseBlock_mouse,
	HouseBlock_newt,
	HouseBlock_spare48,
	HouseBlock_spare49,
	HouseBlock_spare50,
	HouseBlock_spare51,
	HouseBlock_spare52,
	HouseBlock_parrot,
	HouseBlock_spare53,
	HouseBlock_spare54,
	HouseBlock_pig,
	HouseBlock_pigeon,
	HouseBlock_poisonfrog,
	HouseBlock_spare55,
	HouseBlock_pony,
	HouseBlock_spare86,
	HouseBlock_rabbit,
	HouseBlock_raccoon,
	HouseBlock_spare56,
	HouseBlock_spare57,
	HouseBlock_spare58,
	HouseBlock_spare59,
	HouseBlock_spare60,
	HouseBlock_spare61,
	HouseBlock_spare62,
	HouseBlock_spare63,
	HouseBlock_salamander,
	HouseBlock_spare64,
	HouseBlock_sheep,
	HouseBlock_sheepshed,
	HouseBlock_spare66,
	HouseBlock_spare67,
	HouseBlock_sparrow,
	HouseBlock_spider,
	HouseBlock_squirrel,
	HouseBlock_spare68,
	HouseBlock_spare69,
	HouseBlock_spare70,
	HouseBlock_spare71,
	HouseBlock_swan,
	HouseBlock_spare72,
	HouseBlock_spare73,
	HouseBlock_spare74,
	HouseBlock_spare75,
	HouseBlock_spare76,
	HouseBlock_spare77,
	HouseBlock_unicorn,
	HouseBlock_spare87,
	HouseBlock_spare78,
	HouseBlock_spare79,
	HouseBlock_spare80,
	HouseBlock_spare81,
	HouseBlock_spare82,
	HouseBlock_wolf,
	HouseBlock_spare83,
	HouseBlock_worm,
	HouseBlock_spare84,
	HouseBlock_spare85,
	HouseBlock_zebra,
	HouseBlock_snail,
	HouseBlock_helpermine,
	HouseBlock_animalgym,
	HouseBlock_seedos,
	HouseBlock_storkos,
	HouseBlock_dastardos,
	HouseBlock_dedos,
	HouseBlock_helperhomeone,
	HouseBlock_spare9,
	HouseBlock_spare10,
	HouseBlock_zzzzzz,
	FlowerHead_aaaaaa,
	FlowerHead_daisy,
	FlowerHead_buttercup,
	FlowerHead_bluebell,
	FlowerHead_poppy,
	FlowerHead_sunflower,
	FlowerHead_tulip,
	FlowerHead_snapdragon,
	FlowerHead_birdofparadiseplant,
	FlowerHead_orchid,
	FlowerHead_testflower,
	FlowerHead_watercress,
	FlowerHead_waterlily,
	FlowerHead_bulrush,
	FlowerHead_thistle,
	FlowerHead_poisonivy,
	FlowerHead_toadstool,
	FlowerHead_venusflytrap,
	FlowerHead_blackbuttercup,
	FlowerHead_snowdrop,
	FlowerHead_fireweed,
	FlowerHead_cactus,
	FlowerHead_spare22,
	FlowerHead_spare23,
	FlowerHead_spare24,
	FlowerHead_spare25,
	FlowerHead_spare26,
	FlowerHead_spare27,
	FlowerHead_spare28,
	FlowerHead_spare29,
	FlowerHead_zzzzzz,
	SlotMachine_aaaaaa,
	SlotMachine_generalstore,
	SlotMachine_zzzzzz,
	Vegetable_aaaaaa,
	Vegetable_carrot,
	Vegetable_turnip,
	Vegetable_spare3,
	Vegetable_pumpkin,
	Vegetable_chilli,
	Vegetable_testveg,
	Vegetable_nstestveg,
	Vegetable_maize,
	Vegetable_radish,
	Vegetable_yam,
	Vegetable_spare11,
	Vegetable_zzzzzz,
	LifeSweet_aaaaaa,
	LifeSweet_ant,
	LifeSweet_badger,
	LifeSweet_bat,
	LifeSweet_bear,
	LifeSweet_beaver,
	LifeSweet_bee,
	LifeSweet_blackbutterfly,
	LifeSweet_bluebottle,
	LifeSweet_bluebutterfly,
	LifeSweet_boomslang,
	LifeSweet_brownbutterfly,
	LifeSweet_bushbaby,
	LifeSweet_buzzard,
	LifeSweet_canary,
	LifeSweet_cat,
	LifeSweet_chameleon,
	LifeSweet_chicken,
	LifeSweet_cow,
	LifeSweet_crocodile,
	LifeSweet_crow,
	LifeSweet_deer,
	LifeSweet_dog,
	LifeSweet_dragon,
	LifeSweet_dragonfly,
	LifeSweet_duck,
	LifeSweet_eagle,
	LifeSweet_elephant,
	LifeSweet_firefly,
	LifeSweet_firesalamander,
	LifeSweet_flyingpig,
	LifeSweet_fox,
	LifeSweet_frog,
	LifeSweet_gecko,
	LifeSweet_gerbil,
	LifeSweet_goose,
	LifeSweet_grasssnake,
	LifeSweet_greenbutterfly,
	LifeSweet_hedgehog,
	LifeSweet_hippo,
	LifeSweet_horse,
	LifeSweet_hydra,
	LifeSweet_lion,
	LifeSweet_mandrill,
	LifeSweet_mole,
	LifeSweet_monkey,
	LifeSweet_moth,
	LifeSweet_mouse,
	LifeSweet_newt,
	LifeSweet_orangebutterfly,
	LifeSweet_parrot,
	LifeSweet_pig,
	LifeSweet_pigeon,
	LifeSweet_poisonfrog,
	LifeSweet_pinkbutterfly,
	LifeSweet_pony,
	LifeSweet_purplebutterfly,
	LifeSweet_rabbit,
	LifeSweet_raccoon,
	LifeSweet_redbutterfly,
	LifeSweet_salamander,
	LifeSweet_sheep,
	LifeSweet_sparrow,
	LifeSweet_spider,
	LifeSweet_squirrel,
	LifeSweet_swan,
	LifeSweet_unicorn,
	LifeSweet_batpest,
	LifeSweet_whitebutterfly,
	LifeSweet_wolf,
	LifeSweet_worm,
	LifeSweet_yellowbutterfly,
	LifeSweet_zebra,
	LifeSweet_slugpest,
	LifeSweet_crowpest,
	LifeSweet_raccoonpest,
	LifeSweet_crocodilepest,
	LifeSweet_molepest,
	LifeSweet_wolfpest,
	LifeSweet_mandrillpest,
	LifeSweet_snail,
	LifeSweet_snailpest,
	LifeSweet_graysquirrel,
	LifeSweet_zzzzzz,
	ShopKeeper_aaaaaa,
	ShopKeeper_shopkeeper,
	ShopKeeper_postman,
	ShopKeeper_doctor,
	ShopKeeper_innkeeper,
	ShopKeeper_builder,
	ShopKeeper_petshopowner,
	ShopKeeper_trader,
	ShopKeeper_tinker,
	ShopKeeper_hunter,
	ShopKeeper_spare10,
	ShopKeeper_zzzzzz,
	HomeProp_aaaaaa,
	HomeProp_defaultBed,
	HomeProp_zzzzzz,
	Fertiliser_aaaaaa,
	Fertiliser_red,
	Fertiliser_yellow,
	Fertiliser_blue,
	Fertiliser_green,
	Fertiliser_purple,
	Fertiliser_orange,
	Fertiliser_brown,
	Fertiliser_crocodiletears,
	Fertiliser_beggarsmix,
	Fertiliser_10,
	Fertiliser_11,
	Fertiliser_12,
	Fertiliser_13,
	Fertiliser_14,
	Fertiliser_15,
	Fertiliser_16,
	Fertiliser_17,
	Fertiliser_18,
	Fertiliser_19,
	Fertiliser_20,
	Fertiliser_zzzzzz,
	Contract_aaaaaa,
	Contract_waterer,
	Contract_weeder,
	Contract_groundskeeper,
	Contract_harvester,
	Contract_miner,
	Contract_groundskeepernight,
	Contract_spare7,
	Contract_spare8,
	Contract_spare9,
	Contract_spare10,
	Contract_zzzzzz,
	FertiliserPile_aaaaaa,
	FertiliserPile_red,
	FertiliserPile_yellow,
	FertiliserPile_blue,
	FertiliserPile_green,
	FertiliserPile_purple,
	FertiliserPile_orange,
	FertiliserPile_brown,
	FertiliserPile_crocodiletears,
	FertiliserPile_beggarsmix,
	FertiliserPile_10,
	FertiliserPile_11,
	FertiliserPile_12,
	FertiliserPile_13,
	FertiliserPile_14,
	FertiliserPile_15,
	FertiliserPile_16,
	FertiliserPile_17,
	FertiliserPile_18,
	FertiliserPile_19,
	FertiliserPile_20,
	FertiliserPile_zzzzzz,
	Journal_aaaaaa,
	Journal_default,
	Journal_zzzzzz,
	Accessory_aaaaaa,
	Accessory_cocoon,
	Accessory_afro,
	Accessory_backpack,
	Accessory_sharktoothnecklace,
	Accessory_sunglasses,
	Accessory_trilby,
	Accessory_deerStalker,
	Accessory_spare08,
	Accessory_oldthinmoustache,
	Accessory_oldcurlymoustache,
	Accessory_oldsmallmoustache,
	Accessory_teeth,
	Accessory_oldcolonelmoustache,
	Accessory_cowboyhat,
	Accessory_sombrero,
	Accessory_vikinghelm,
	Accessory_mohawk,
	Accessory_beaniehat,
	Accessory_blondwig,
	Accessory_minershelmet,
	Accessory_gasmask,
	Accessory_partyhorns,
	Accessory_oldhelmet,
	Accessory_bushyeyebrows,
	Accessory_oldstraightmoustache,
	Accessory_costumebathero,
	Accessory_schoolcap,
	Accessory_baseballcap,
	Accessory_oldsoldierhelmet,
	Accessory_tiara,
	Accessory_neattache,
	Accessory_collar,
	Accessory_glasses,
	Accessory_camera,
	Accessory_goldteeth,
	Accessory_bow,
	Accessory_fez,
	Accessory_rosette,
	Accessory_diamondchoker,
	Accessory_eyepatch,
	Accessory_tapshoes,
	Accessory_balletshoes,
	Accessory_crown,
	Accessory_french,
	Accessory_americanfootballhelmet,
	Accessory_armsweetbands,
	Accessory_bangle,
	Accessory_beads,
	Accessory_oldbuckteath,
	Accessory_bowtie,
	Accessory_bracelet,
	Accessory_broach,
	Accessory_bunnyear,
	Accessory_bushy,
	Accessory_chefhat,
	Accessory_colonel,
	Accessory_cowboyboots,
	Accessory_danglyearrings,
	Accessory_diamondnecklace,
	Accessory_workboots,
	Accessory_oldearingbghoop,
	Accessory_earingheart,
	Accessory_earingseashell,
	Accessory_earringsdiamond,
	Accessory_oldeyebrows,
	Accessory_fakelips,
	Accessory_falsenose,
	Accessory_falseteeth,
	Accessory_oldflowercorsage,
	Accessory_footballboots,
	Accessory_furhat,
	Accessory_glowsticknecklace,
	Accessory_pendantnecklace,
	Accessory_halo,
	Accessory_hardhat,
	Accessory_headsweetbands,
	Accessory_wellies,
	Accessory_oldkneehighboots,
	Accessory_medallion,
	Accessory_oldmohican,
	Accessory_monocle,
	Accessory_moonboots,
	Accessory_neckbolt,
	Accessory_nosering,
	Accessory_panama,
	Accessory_olddanglyearings,
	Accessory_pearlnecklace,
	Accessory_oldpedantnecklace,
	Accessory_piratehat,
	Accessory_policehat,
	Accessory_policehelm,
	Accessory_readingglasses,
	Accessory_rednose,
	Accessory_robbersmask,
	Accessory_safetygoggles,
	Accessory_santahat,
	Accessory_scarf,
	Accessory_seashellnecklace,
	Accessory_slippers,
	Accessory_snowshoe,
	Accessory_swimminggoggles,
	Accessory_thin,
	Accessory_tie,
	Accessory_tophat,
	Accessory_trainers,
	Accessory_oldchoker,
	Accessory_dastardosscarf,
	Accessory_bell,
	Accessory_bonnet,
	Accessory_beekeepershat,
	Accessory_buttercup,
	Accessory_daisy,
	Accessory_earingbghoopgold,
	Accessory_earingbghoopsilver,
	Accessory_earingspendant,
	Accessory_pearlbracelet,
	Accessory_poppy,
	Accessory_oldskigoggles,
	Accessory_sunflower,
	Accessory_trafficcone,
	Accessory_okeeyeballssprings,
	Accessory_chainnecklace,
	Accessory_chefhat2,
	Accessory_tailbow,
	Accessory_utilitybelt,
	Accessory_fruithat,
	Accessory_mrpantshat,
	Accessory_sailorhat,
	Accessory_conkerhat,
	Accessory_velawig,
	Accessory_junohelmet,
	Accessory_gruntyhat,
	Accessory_jamjarhat,
	Accessory_binnershat,
	Accessory_princesshat,
	Accessory_vonghoulhat,
	Accessory_sabremanhat,
	Accessory_orthohat,
	Accessory_knighthat,
	Accessory_headphones,
	Accessory_jiggyearrings,
	Accessory_lupusears,
	Accessory_discoshades,
	Accessory_flyinggoggles,
	Accessory_jamjarsunglasses,
	Accessory_romanticflower,
	Accessory_battletoadbracelets,
	Accessory_handcuffs,
	Accessory_sheriffbadge,
	Accessory_clockworkkey,
	Accessory_kameowings,
	Accessory_sharkfin,
	Accessory_flamencoshoes,
	Accessory_ashslippers,
	Accessory_spare155,
	Accessory_spare156,
	Accessory_spare157,
	Accessory_spare158,
	Accessory_spare159,
	Accessory_spare160,
	Accessory_spare161,
	Accessory_spare162,
	Accessory_spare163,
	Accessory_spare164,
	Accessory_spare165,
	Accessory_spare166,
	Accessory_spare167,
	Accessory_spare168,
	Accessory_spare169,
	Accessory_spare170,
	Accessory_spare171,
	Accessory_spare172,
	Accessory_spare173,
	Accessory_spare174,
	Accessory_spare175,
	Accessory_spare176,
	Accessory_spare177,
	Accessory_spare178,
	Accessory_spare179,
	Accessory_spare180,
	Accessory_spare181,
	Accessory_spare182,
	Accessory_spare183,
	Accessory_spare184,
	Accessory_spare185,
	Accessory_spare186,
	Accessory_spare187,
	Accessory_spare188,
	Accessory_spare189,
	Accessory_spare190,
	Accessory_spare191,
	Accessory_spare192,
	Accessory_spare193,
	Accessory_spare194,
	Accessory_spare195,
	Accessory_spare196,
	Accessory_spare197,
	Accessory_spare198,
	Accessory_spare199,
	Accessory_spare200,
	Accessory_spare201,
	Accessory_spare202,
	Accessory_spare203,
	Accessory_spare204,
	Accessory_spare205,
	Accessory_spare206,
	Accessory_spare207,
	Accessory_spare208,
	Accessory_spare209,
	Accessory_spare210,
	Accessory_spare211,
	Accessory_spare212,
	Accessory_spare213,
	Accessory_spare214,
	Accessory_spare215,
	Accessory_spare216,
	Accessory_spare217,
	Accessory_spare218,
	Accessory_spare219,
	Accessory_spare220,
	Accessory_spare221,
	Accessory_spare222,
	Accessory_spare223,
	Accessory_spare224,
	Accessory_spare225,
	Accessory_spare226,
	Accessory_spare227,
	Accessory_spare228,
	Accessory_spare229,
	Accessory_spare230,
	Accessory_spare231,
	Accessory_spare232,
	Accessory_spare233,
	Accessory_spare234,
	Accessory_spare235,
	Accessory_spare236,
	Accessory_spare237,
	Accessory_spare238,
	Accessory_spare239,
	Accessory_spare240,
	Accessory_spare241,
	Accessory_spare242,
	Accessory_spare243,
	Accessory_spare244,
	Accessory_zzzzzz

};


/* 11991 */
struct gardenBudgetWorkspace_s_unnamed_tag
{
	int dirty;
	float cubeShadowBuffering;
	float diggableSurfacePreDraw;
	float dualShadowBuffering;
	float mainPassOpaque;
	float mainPassTransparent;
	float regularShadowBuffering;
	float memory;
	float memoryReally;
	float worstCase;
	unsigned int worstCaseReason;
};

/* 9834 */
struct _DM_MEMORY_STATISTICS
{
	unsigned int cbSize;
	unsigned int TotalPages;
	unsigned int AvailablePages;
	unsigned int StackPages;
	unsigned int VirtualPageTablePages;
	unsigned int SystemPageTablePages;
	unsigned int PoolPages;
	unsigned int VirtualMappedPages;
	unsigned int ImagePages;
	unsigned int FileCachePages;
	unsigned int ContiguousPages;
	unsigned int DebuggerPages;
};

/* 11992 */
struct gardenBudgetWorkspace_s
{
	char Unknown[8316]; //This struct has been changed so much that I have no idea what goes here anymore, but it is 8316 bytes in size, so here we are. (Fix this eventually)
	//gardenBudgetUnit_s total;
	//gardenBudgetUnit_s base;
	//gardenBudgetUnit_s space;
	//gardenBudgetUnit_s peak;
	//gardenBudgetUnit_s max;
	//gardenBudgetUnit_s tick;
	//gardenBudgetUnit_s* tagUnits;
	//unsigned int tagCount[1904];
	//gardenBudgetClassUnit_s* tagClassUnits;
	//unsigned int tagClassCount[43];
	//unsigned int tagClassVarietyCount[43];
	//unsigned int tagWithLampsCount;
	//unsigned int tagGateCount;
	//unsigned int totalTagCount;
	//supportPinataTag_e lastSuccessfulTagQuery;
	//supportPinataTagClass_e lastSuccessfulTagClassQuery;
	//supportPinataTag_e exceptionTag;
	//supportPinataTagClass_e exceptionTagClass;
	//int globalException;
	//supportPinataTag_e lastUnsuccessfulTagQuery;
	//supportPinataTagClass_e lastUnsuccessfulTagClassQuery;
	//unsigned int lastUnsuccessfulTagErrorCode;
	//unsigned int peakAudioVirtual;
	//unsigned int peakAudioPhysical;
	//gardenBudgetWorkspace_s_unnamed_tag occupancyLevels;
	//_DM_MEMORY_STATISTICS memStats;
	//_DM_MEMORY_STATISTICS maxMemStats;
	//unsigned int reloadTickCount;
	//int memoryTestPanic;
};

/* 12086 */
struct entitySceneControlPinataStorkWorkspace_s
{
	entitySceneControlPinataStorkInst_s* storkControllerInst;
};

/* 12092 */
struct entitySceneControlPinataSeedosWorkspace_s
{
	entitySceneControlPinataSeedosInst_s* seedosControllerInst;
};


/* 12095 */
struct entitySceneControlPinataDastardosObstruction_s
{
	mlVec posInFront;
	mlVec posBehind;
};

/* 1049 */
enum dastardosPathState_e : uint32_t
{
	dastardosPathMode_Fail = 0x0,
	dastardosPathMode_Generate = 0x1,
	dastardosPathMode_PathToDestination = 0x2,
	dastardosPathMode_PathToPointInFrontOfObstruction = 0x3,
	dastardosPathMode_PathToPointBehindObstruction = 0x4,
	dastardosPathMode_ReachedDestination = 0x5,
	dastardosPathMode_WalkingThroughObstacle = 0x6,
};

/* 1011 */
enum actorStrategyId_e : uint32_t
{
	__actorStrategyId_MIN = 0x3E7,
	actorStrategyId_Null = 0x3E8,
	actorStrategyId_ActionEnabledDelay = 0x3E9,
	actorStrategyId_Aloof = 0x3EA,
	actorStrategyId_Angry = 0x3EB,
	actorStrategyId_Approach = 0x3EC,
	actorStrategyId_Attack_KnockBack = 0x3ED,
	actorStrategyId_Attack_KnockDown = 0x3EE,
	actorStrategyId_Attack_Special = 0x3EF,
	actorStrategyId_Attack_Special_End = 0x3F0,
	actorStrategyId_ButlersBrew = 0x3F1,
	actorStrategyId_Celebrate = 0x3F2,
	actorStrategyId_CelebrateLoop = 0x3F3,
	actorStrategyId_Coward = 0x3F4,
	actorStrategyId_Crowd = 0x3F5,
	actorStrategyId_Director_BoundedCam = 0x3F6,
	actorStrategyId_Director_CameraShot = 0x3F7,
	actorStrategyId_Director_CouchSocial = 0x3F8,
	actorStrategyId_Director_FollowAvatar = 0x3F9,
	actorStrategyId_Director_FollowPlayer = 0x3FA,
	actorStrategyId_Director_HeadCamera = 0x3FB,
	actorStrategyId_Director_TotemCam = 0x3FC,
	actorStrategyId_Director_WatchFight = 0x3FD,
	actorStrategyId_Dizzy = 0x3FE,
	actorStrategyId_Dodge = 0x3FF,
	actorStrategyId_Drink = 0x400,
	actorStrategyId_DroneAction = 0x401,
	actorStrategyId_Dying = 0x402,
	actorStrategyId_Emerge = 0x403,
	actorStrategyId_Evade = 0x404,
	actorStrategyId_ExitExclusionRegion = 0x405,
	actorStrategyId_Explode = 0x406,
	actorStrategyId_Explore = 0x407,
	actorStrategyId_Far = 0x408,
	actorStrategyId_FetchWeapon = 0x409,
	actorStrategyId_Follow = 0x40A,
	actorStrategyId_ForceAngry = 0x40B,
	actorStrategyId_GetHelp = 0x40C,
	actorStrategyId_GetWeapon = 0x40D,
	actorStrategyId_Help = 0x40E,
	actorStrategyId_HitWall = 0x40F,
	actorStrategyId_Idle = 0x410,
	actorStrategyId_Interactive = 0x411,
	actorStrategyId_KnockedDown = 0x412,
	actorStrategyId_KnockedDown_Wait = 0x413,
	actorStrategyId_Mutated = 0x414,
	actorStrategyId_Near = 0x415,
	actorStrategyId_Observe = 0x416,
	actorStrategyId_PinataAaaaaa = 0x417,
	actorStrategyId_PinataAnimalHit = 0x418,
	actorStrategyId_PinataApproachGarden = 0x419,
	actorStrategyId_PinataApproachRival = 0x41A,
	actorStrategyId_PinataAtHome = 0x41B,
	actorStrategyId_PinataBabyTrapped = 0x41C,
	actorStrategyId_PinataBecomeResident = 0x41D,
	actorStrategyId_PinataBeggarStealingMoney = 0x41E,
	actorStrategyId_PinataBeingDirectedTo = 0x41F,
	actorStrategyId_PinataBeingGivenMoney = 0x420,
	actorStrategyId_PinataBuild = 0x421,
	actorStrategyId_PinataBurning = 0x422,
	actorStrategyId_PinataCheered = 0x423,
	actorStrategyId_PinataClimb = 0x424,
	actorStrategyId_PinataConfirmFightAudience = 0x425,
	actorStrategyId_PinataConjureAlert = 0x426,
	actorStrategyId_PinataCoughUpSweet = 0x427,
	actorStrategyId_PinataDastardosApproachSickAnimal = 0x428,
	actorStrategyId_PinataDastardosAtHome = 0x429,
	actorStrategyId_PinataDastardosCollectSickAnimal = 0x42A,
	actorStrategyId_PinataDastardosGiveOrdersToRuffians = 0x42B,
	actorStrategyId_PinataDastardosInterupted = 0x42C,
	actorStrategyId_PinataDastardosKillPlantsInDastardosGarden = 0x42D,
	actorStrategyId_PinataDastardosKillPlantsInDedosGarden = 0x42E,
	actorStrategyId_PinataDastardosRemovePaintFromDoor = 0x42F,
	actorStrategyId_PinataDastardosReturnHome = 0x430,
	actorStrategyId_PinataDastardosRewardPests = 0x431,
	actorStrategyId_PinataDastardosTalkToRuffians = 0x432,
	actorStrategyId_PinataDastardosTrickSeedos = 0x433,
	actorStrategyId_PinataDastardosVisitGrave = 0x434,
	actorStrategyId_PinataDastardosWalkThroughObstacle = 0x435,
	actorStrategyId_PinataDedosCry = 0x436,
	actorStrategyId_PinataDirected = 0x437,
	actorStrategyId_PinataDisappointed = 0x438,
	actorStrategyId_PinataDistractDastardos = 0x439,
	actorStrategyId_PinataDizzied = 0x43A,
	actorStrategyId_PinataDoctorCallout = 0x43B,
	actorStrategyId_PinataDragonFightProfessor = 0x43C,
	actorStrategyId_PinataDragonLeaveGarden = 0x43D,
	actorStrategyId_PinataEnter = 0x43E,
	actorStrategyId_PinataEscape = 0x43F,
	actorStrategyId_PinataEvolve = 0x440,
	actorStrategyId_PinataExcludedSurfacePanic = 0x441,
	actorStrategyId_PinataExercise = 0x442,
	actorStrategyId_PinataExit = 0x443,
	actorStrategyId_PinataFindPlayMate = 0x444,
	actorStrategyId_PinataFlirtAlone = 0x445,
	actorStrategyId_PinataFlyAround = 0x446,
	actorStrategyId_PinataFlyToPerch = 0x447,
	actorStrategyId_PinataFollow = 0x448,
	actorStrategyId_PinataGather = 0x449,
	actorStrategyId_PinataGetCaught = 0x44A,
	actorStrategyId_PinataGetDrink = 0x44B,
	actorStrategyId_PinataGetFood = 0x44C,
	actorStrategyId_PinataGetRomanceSweets = 0x44D,
	actorStrategyId_PinataGoGym = 0x44E,
	actorStrategyId_PinataGoHome = 0x44F,
	actorStrategyId_PinataGoMining = 0x450,
	actorStrategyId_PinataGoProducing = 0x451,
	actorStrategyId_PinataGoShopping = 0x452,
	actorStrategyId_PinataGoSwimming = 0x453,
	actorStrategyId_PinataGroom = 0x454,
	actorStrategyId_PinataGrowUp = 0x455,
	actorStrategyId_PinataGuard = 0x456,
	actorStrategyId_PinataGuardEgg = 0x457,
	actorStrategyId_PinataHarvest = 0x458,
	actorStrategyId_PinataHarvestVegetables = 0x459,
	actorStrategyId_PinataHatchedCheer = 0x45A,
	actorStrategyId_PinataHelperEnterGarden = 0x45B,
	actorStrategyId_PinataHelperGiveProp = 0x45C,
	actorStrategyId_PinataHelperInteractWithAnimal = 0x45D,
	actorStrategyId_PinataHover = 0x45E,
	actorStrategyId_PinataHumanRocket = 0x45F,
	actorStrategyId_PinataHunt = 0x460,
	actorStrategyId_PinataIMapExplore = 0x461,
	actorStrategyId_PinataIMapFeedingGround = 0x462,
	actorStrategyId_PinataIMapGetFood = 0x463,
	actorStrategyId_PinataIMapSleepingGround = 0x464,
	actorStrategyId_PinataIMapWander = 0x465,
	actorStrategyId_PinataImmobilised = 0x466,
	actorStrategyId_PinataInplayerFocus = 0x467,
	actorStrategyId_PinataInteractWithHelper = 0x468,
	actorStrategyId_PinataInvestigate = 0x469,
	actorStrategyId_PinataLeaveGiftForSeedos = 0x46A,
	actorStrategyId_PinataLeaveHome = 0x46B,
	actorStrategyId_PinataLookInGarden = 0x46C,
	actorStrategyId_PinataMine = 0x46D,
	actorStrategyId_PinataMove = 0x46E,
	actorStrategyId_PinataNap = 0x46F,
	actorStrategyId_PinataNull = 0x470,
	actorStrategyId_PinataPack = 0x471,
	actorStrategyId_PinataPaintFrontDoor = 0x472,
	actorStrategyId_PinataParalysed = 0x473,
	actorStrategyId_PinataParentIsMating = 0x474,
	actorStrategyId_PinataPeek = 0x475,
	actorStrategyId_PinataPerch = 0x476,
	actorStrategyId_PinataPerformTrick = 0x477,
	actorStrategyId_PinataPestAttackHelper = 0x478,
	actorStrategyId_PinataPestAttackPlant = 0x479,
	actorStrategyId_PinataPestBecomeTame = 0x47A,
	actorStrategyId_PinataPestBlowUp = 0x47B,
	actorStrategyId_PinataPestBreakProduce = 0x47C,
	actorStrategyId_PinataPestBurrow = 0x47D,
	actorStrategyId_PinataPestCoughUpSmelly = 0x47E,
	actorStrategyId_PinataPestDryUpPlant = 0x47F,
	actorStrategyId_PinataPestEatEgg = 0x480,
	actorStrategyId_PinataPestEatRomanceSweet = 0x481,
	actorStrategyId_PinataPestEatSeed = 0x482,
	actorStrategyId_PinataPestEatSickAnimal = 0x483,
	actorStrategyId_PinataPestFillInPond = 0x484,
	actorStrategyId_PinataPestKillTheMood = 0x485,
	actorStrategyId_PinataPestPoisonAnimal = 0x486,
	actorStrategyId_PinataPestRemoveSurface = 0x487,
	actorStrategyId_PinataPestRevertVariant = 0x488,
	actorStrategyId_PinataPestRotFruitVeg = 0x489,
	actorStrategyId_PinataPestScareVisitor = 0x48A,
	actorStrategyId_PinataPestSelectBehaviour = 0x48B,
	actorStrategyId_PinataPestStartFight = 0x48C,
	actorStrategyId_PinataPestSting = 0x48D,
	actorStrategyId_PinataPestTrample = 0x48E,
	actorStrategyId_PinataPlantFlowersDastardosGarden = 0x48F,
	actorStrategyId_PinataPlantSeed = 0x490,
	actorStrategyId_PinataPlayCopycat = 0x491,
	actorStrategyId_PinataPlayFight = 0x492,
	actorStrategyId_PinataPlayFollowLeader = 0x493,
	actorStrategyId_PinataPlayLeadTheWay = 0x494,
	actorStrategyId_PinataPlayWaitForLeader = 0x495,
	actorStrategyId_PinataPointToAlert = 0x496,
	actorStrategyId_PinataPointToPoint = 0x497,
	actorStrategyId_PinataProduceReady = 0x498,
	actorStrategyId_PinataProtectBaby = 0x499,
	actorStrategyId_PinataRampage = 0x49A,
	actorStrategyId_PinataReactToNearbyInterest = 0x49B,
	actorStrategyId_PinataReactToSpadeHit = 0x49C,
	actorStrategyId_PinataReactToWateringCan = 0x49D,
	actorStrategyId_PinataReconstructing = 0x49E,
	actorStrategyId_PinataRecreation = 0x49F,
	actorStrategyId_PinataRest = 0x4A0,
	actorStrategyId_PinataReturnFromParty = 0x4A1,
	actorStrategyId_PinataReturnToGarden = 0x4A2,
	actorStrategyId_PinataRoamSubGarden = 0x4A3,
	actorStrategyId_PinataRuffianFreeHelper = 0x4A4,
	actorStrategyId_PinataRuffianParalysed = 0x4A5,
	actorStrategyId_PinataRuffianPickFight = 0x4A6,
	actorStrategyId_PinataRuffianPoison = 0x4A7,
	actorStrategyId_PinataRuffianSteal = 0x4A8,
	actorStrategyId_PinataRuffianVandalise = 0x4A9,
	actorStrategyId_PinataScared = 0x4AA,
	actorStrategyId_PinataSeedLawnBorder = 0x4AB,
	actorStrategyId_PinataSeedosAfterTalk = 0x4AC,
	actorStrategyId_PinataSeedosAtHome = 0x4AD,
	actorStrategyId_PinataSeedosHit = 0x4AE,
	actorStrategyId_PinataSeedosInspectPlants = 0x4AF,
	actorStrategyId_PinataSeedosLookForSeeds = 0x4B0,
	actorStrategyId_PinataSeedosThrowIntoGarden = 0x4B1,
	actorStrategyId_PinataSeedosThrowWeeds = 0x4B2,
	actorStrategyId_PinataSeedosWaitForPlayerTalk = 0x4B3,
	actorStrategyId_PinataSeedosWarpToPerimeter = 0x4B4,
	actorStrategyId_PinataSellSomething = 0x4B5,
	actorStrategyId_PinataSick = 0x4B6,
	actorStrategyId_PinataSleep = 0x4B7,
	actorStrategyId_PinataSpecialAbility = 0x4B8,
	actorStrategyId_PinataSpecialAbilityAuto = 0x4B9,
	actorStrategyId_PinataStand = 0x4BA,
	actorStrategyId_PinataStorkAtHome = 0x4BB,
	actorStrategyId_PinataStorkDeliverEgg = 0x4BC,
	actorStrategyId_PinataSubGardenSelectBehaviour = 0x4BD,
	actorStrategyId_PinataTalkToPlayer = 0x4BE,
	actorStrategyId_PinataTinker = 0x4BF,
	actorStrategyId_PinataTrampled = 0x4C0,
	actorStrategyId_PinataTrampleRuffian = 0x4C1,
	actorStrategyId_PinataTrappedAttract = 0x4C2,
	actorStrategyId_PinataTrappedBreakout = 0x4C3,
	actorStrategyId_PinataTrappedByGate = 0x4C4,
	actorStrategyId_PinataUnpack = 0x4C5,
	actorStrategyId_PinataVisit = 0x4C6,
	actorStrategyId_PinataVisitInvestigate = 0x4C7,
	actorStrategyId_PinataWaitForInterrupt = 0x4C8,
	actorStrategyId_PinataWalkFromEgg = 0x4C9,
	actorStrategyId_PinataWalkthrough = 0x4CA,
	actorStrategyId_PinataWander = 0x4CB,
	actorStrategyId_PinataWater = 0x4CC,
	actorStrategyId_PinataWaterLawnBorder = 0x4CD,
	actorStrategyId_PinataWeed = 0x4CE,
	actorStrategyId_PinataWretched = 0x4CF,
	actorStrategyId_Pinatazzzzzz = 0x4D0,
	actorStrategyId_PostKnockDownCelebrate = 0x4D1,
	actorStrategyId_PreIntro = 0x4D2,
	actorStrategyId_ReturnToSetupPosition = 0x4D3,
	actorStrategyId_Scared = 0x4D4,
	actorStrategyId_Sit = 0x4D5,
	actorStrategyId_Sleep = 0x4D6,
	actorStrategyId_Spin = 0x4D7,
	actorStrategyId_Stall = 0x4D8,
	actorStrategyId_Talking = 0x4D9,
	actorStrategyId_Wait = 0x4DA,
	actorStrategyId_Wake = 0x4DB,
	actorStrategyId_Worried = 0x4DC,
	actorStrategyId_MAX = 0x4DD,
};

/* 12096 */
struct entitySceneControlPinataDastardosInstRuntime_s
{
	int justLoaded;
	int sendDoctorAlert;
	int dastardosDoorHasBeenPainted;
	int dedosDoorHasBeenPainted;
	float currentEnterGardenTime;
	float currentLeaveGardenTime;
	actorInst_s* currentPest;
	actorInst_s* currentSickAnimal;
	entitySceneControlPinataDastardosObstruction_s obstruction;
	mlVec destinationPos;
	int destinationNode;
	int canCollectWhilstInObstacle;
	const avatarInst_s* homeAvatar;
	int numObstructions;
	dastardosPathState_e pathMode;
	dastardosPathState_e pathModePrev;
	actorStrategyId_e savedStrategyId;
	mlVec savedPosition;
	float currentAlphaValue;
	float wantedAlphaValue;
	float startingAlphaValue;
	float fadeDuration;
	float currentFadeTime;
	unsigned int cutsceneHandle;
	int concentrateIsActive;
};

/* 12097 */
struct entitySceneControlPinataDastardosWorkspace_s
{
	entitySceneControlPinataDastardosInst_s* dastardosControllerInst;
	entitySceneControlPinataDastardosInstRuntime_s runtime;
};

/* 12105 */
struct entitySceneControlPinataRuffiansInstRuntime_s
{
	float daysTilNextPossibleVisit;
	supportPinataTag_e currentBestRuffian;
	int randomRuffiansCanBeInGarden;
	int hasJustLoaded;
	int professorIsActive;
	int waitingForCutscene;
	unsigned int cutsceneHandle;
};

/* 12106 */
struct entitySceneControlPinataRuffiansWorkspace_s
{
	entitySceneControlPinataRuffiansInst_s* ruffiansControllerInst;
	entitySceneControlPinataRuffiansInstRuntime_s runtime;
};

/* 12107 */
struct entitySceneControlPinataBeggarTraderRuntime_s
{
	int isBeingIntroduced;
	unsigned int introductionHandle;
	int numTimeLeftGardenDueToHits;
	dsLinkedListNode_s listHits;
	dsLinkedListNode_s listCoins;
	int totalMoney;
	float daysTilNextVisit;
	float timeOfNextVisit;
	float timeToLeaveGarden;
	int shouldLeaveGarden;
	int isBeingWatered;
	int numItemsInStore;
	int needToUpdateStoreItems;
	dsList2_s listMoneyInGarden;
};

/* 12110 */
struct entitySceneControlPinataBeggarTraderWorkspace_s
{
	entitySceneControlPinataBeggarTraderRuntime_s runtime;
	entitySceneControlPinataBeggarTraderInst_s* inst;
};

/* 12112 */
struct entitySceneControlPinataDedosWorkspace_s
{
	entitySceneControlPinataDedosInst_s* dedosControllerInst;
};

/* 12119 */
struct entitySceneControlPinataChallengesWorkspace_s
{
	entitySceneControlPinataChallengesRuntime_s* runtime;
};

/* 12131 */
struct entitySceneControlPinataLeaderboardsWorkspace_s
{
	entitySceneControlPinataLeaderboardsReadInst_s* pstrReadInst;
	entitySceneControlPinataLeaderboardsWriteInst_s* pstrWriteInst;
};

/* 12135 */
struct entitySceneControlPinataHelpersWorkspace_s
{
	entitySceneControlPinataHelpersInst_s* helpersControllerInst;
};

/* 12137 */
struct entitySceneControlPinataDoctorWorkspace_s
{
	entitySceneControlPinataDoctorInst_s* doctorControllerInst;
};

/* 12139 */
struct entitySceneControlPinataBuilderWorkspace_s
{
	entitySceneControlPinataBuilderInst_s* builderControllerInst;
};

/* 12141 */
struct entitySceneControlPinataTinkerWorkspace_s
{
	entitySceneControlPinataTinkerInst_s* tinkerControllerInst;
};

/* 12143 */
struct entitySceneControlPinataHunterWorkspace_s
{
	entitySceneControlPinataHunterInst_s* hunterControllerInst;
};

/* 12145 */
struct entitySceneControlPinataStoreWorkspace_s
{
	entitySceneControlPinataStoreInst_s* storeControllerInst;
};

/* 12149 */
struct supportPinataAnimalEvolveButterflyWorkspace_s
{
	supportPinataAnimalEvolveButterfly_s* table;
	reqAnimal_Structure_s* requirements[9];
};

/* 12150 */
struct uiGameShopParams_s
{
	dsList2_s items;
	int day;
	int saleOn;
	float priceVariation;
	float sellModifier;
	unsigned int lastKnownUnlockablesCount;
};

/* 11993 */
struct gardenMainWorkspace_s
{
	sceneMainWorkspace_s* scene;
	int gardenWidth;
	int gardenHalfWidth;
	float gardenArea;
	int cursorLimitWidth;
	int cursorLimitHalfWidth;
	int perimeterFixedWidth;
	int perimeterFixedHalfWidth;
	int gardenMaxWidth;
	int gardenMaxHalfWidth;
	int forestHalfWidth;
	int cachedGardenValue;
	unsigned int cachedGardenValueTick;
	int bgReset;
	int gardenWidthReset;
	int activeForSave;
	gardenMainWorkspace_s_unnamed_tag params;
	gardenPerimeterWorkspace_s perimeter;
	gardenPerimeterBoxWorkspace_s perimeterBoxes;
	gardenSpaceWorkspace_s space;
	gardenWayPointWorkspace_s wayPoints;
	gardenNameWorkspace_s name;
	gardenTotemPoleWorkspace_s totemPole;
	gardenHiddenItemsWorkspace_s hiddenItems;
	gardenPavingWorkspace_s paving;
	gardenGlobalEffectsWorkspace_s globalEffects;
	gardenBudgetWorkspace_s budget;
	scenePinataFenceWorkspace_s* fence;
	scenePinataTriggerWorkspace_s* trigger;
	supportPinataTimeWorkspace_s* time;
	supportPinataLabelWorkspace_s* label;
	entitySceneControlPinataStorkWorkspace_s stork;
	entitySceneControlPinataSeedosWorkspace_s seedos;
	entitySceneControlPinataDastardosWorkspace_s dastardos;
	entitySceneControlPinataRuffiansWorkspace_s ruffians;
	entitySceneControlPinataBeggarTraderWorkspace_s beggarTrader;
	entitySceneControlPinataDedosWorkspace_s dedos;
	entitySceneControlPinataChallengesWorkspace_s challenges;
	entitySceneControlPinataLeaderboardsWorkspace_s leaderboards;
	entitySceneControlPinataHelpersWorkspace_s helpers;
	entitySceneControlPinataDoctorWorkspace_s doctor;
	entitySceneControlPinataBuilderWorkspace_s builder;
	entitySceneControlPinataTinkerWorkspace_s tinker;
	entitySceneControlPinataHunterWorkspace_s hunter;
	entitySceneControlPinataStoreWorkspace_s store;
	supportPinataAnimalEvolveButterflyWorkspace_s butterfly;
	uiGameShopParams_s shopParams[9];
	unsigned int shopBorder;
	unsigned int shopMenu;
	avatarInst_s* menuTarget;
	unsigned int mateMiniGameBorder;
	float playedSecs;
	int tagTableCache[1904];
	int tagTableCacheDirtyFlag;
	unsigned int tagTableCacheTimeUntilNextUpdate;
};

/* 11999 */
struct supportPinataTime_TimeRate_s
{
	float timeRate[24];
};

/* 12000 */
struct supportPinataTimeWorkspace_s
{
	gardenMainWorkspace_s* garden;
	float time;
	float lastTime;
	float deltaTime;
	float timeScale;
	supportPinataTime_TimeRate_s* timeRate;
	unsigned int daysPassed;
	int enableTime;
	float updateTimer;
	int hasInitialNetSync;
};

struct objFunc_s;

/* 12030 */
struct sceneControlNetSync_s
{
	unsigned char gap0[4];
};

/* 12031 */
struct sceneControlObjInst_s
{
	objInst_s __objInstance;
	sceneControlNetSync_s _netsync;
	sceneMainWorkspace_s* scene;
	dsLinkedListNode_s listNode;
	dsLinkedListNode_s dynamicListNode;
	dsLinkedListNode_s remoteListNode;
	dsLinkedListNode_s deleteListNode;
	float clock;
	int disablePause;
	int disableNoControllerTest;
	int disableScreenSaver;
	int disableSerialisation;
};

/* 1694 */
enum storeSceneControllerState_e : uint32_t
{
	store_Normal = 0x0,
	store_MAX = 0x1,
};

/* 12144 */
struct entitySceneControlPinataStoreInst_s
{
	sceneControlObjInst_s __sceneControlObjInstance;
	unsigned int numStoreSlots;
	unsigned int numItems;
	dsList2_s slotList;
	storeSceneControllerState_e subState;
};

/* 626 */
struct assetDbAsset_s
{
	void* virtualData;
	unsigned int virtualSize;
	unsigned int timeStamp;
	unsigned int dbId;
	unsigned int physicalSize;
	assetFile* assetSection;
	assetSectionFileLoadUnit_s* unit;
};


struct assetManUnit_s // sizeof=0xA0
{
     assetId_s aid;
     unsigned __int64 hash64;
     assetDbAsset_s* dbAsset;
     int releaseOnTick;
     dsLinkedListNode_s dumpNode;
	 uint16_t suppressWarning : 1;
     uint16_t refCount : 15;
     int assetComesFromBundle;
 };
