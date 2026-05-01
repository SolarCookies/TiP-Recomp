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
#pragma pack(push, 1)
struct DiffFileHeader
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
#pragma pack(pop)

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
	void(* callback)(assetFile*, const void*, int);
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
#pragma pack(push, 1)
struct blockInfo
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
#pragma pack(pop)

/* 642 */
#pragma pack(push, 2)
struct _section
{
	unsigned int asset;
	unsigned char* start;
	unsigned int size;
	unsigned char sectionType;
	unsigned char startAlignment;
};
#pragma pack(pop)

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
struct assetFile
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
	void(* notifyComplete)(FSObject_s* const, int, void* const);
	void* notifyContext;
};

/* 597 */
struct dsList2_s
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
	int(* callback)(void*, void*, int);
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
	void(* completedCallback)(const void*, int);
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
struct avatarExtent_s_unnamed_tag_unnamed_tag
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
struct aStarNodeInst_s
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

enum supportPinataTag_e : uint32_t
{
	supportPinataTag_None = 0x0
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
     uint64_t hash64;
     assetDbAsset_s* dbAsset;
     int releaseOnTick;
     dsLinkedListNode_s dumpNode;
	 uint16_t suppressWarning : 1;
     uint16_t refCount : 15;
     int assetComesFromBundle;
 };

 /* 17291 */
struct lightMainDirectionalLight_s
{
  mlVec dir;
  mlV4 col;
};

/* 17292 */
struct lightMainWorkspace_s
{
  mlV4 ambientCol;
  mlV4 modelAmbientCol;
  lightMainDirectionalLight_s dirLight;
  dsList_s *_pointLightListRef;
  int _mainPointLightRef;
  mlV4 fogCol;
  float fogOpacity;
  float fogNearDist;
  float fogFarDist;
  float blueShiftScalar;
  int cubeFogEnabled;
};

//////////////////////////////////////////////////////////

/* 11678 */
struct dsLinkedListNode_cam
{
  int _prevPtr;
  int _nextPtr;
};

/* 12084 */
struct camVirt_s_rotation
{
  mlRot_s pyrR;
  mlQuat quat;
};

/* 1009 */
enum camVirt_Aspect_e : uint32_t
{
  camVirt_Aspect_4_3 = 0x0,
  camVirt_Aspect_16_9 = 0x1,
  camVirt_Aspect_2_35 = 0x2,
  camVirt_Aspect_UseViewport = 0x3,
  camVirt_Aspect_Max = 0x4,
};

/* 12085 */
struct camVirt_s
{
  dsLinkedListNode_cam node;
  mlVec pos;
  camVirt_s_rotation rotation;
  float focalLength;
  float nearDist;
  float farDist;
  camVirt_Aspect_e aspectType;
  char name[33];
  uint8_t flags;
  uint8_t planeIdx;
  uint8_t __pad2[2];
  float screenRatio;
  float screenDist;
  int unk1;
  int unk2;
};

/* 7650 */
struct _D3DVIEWPORT9
{
  unsigned int X;
  unsigned int Y;
  unsigned int Width;
  unsigned int Height;
  float MinZ;
  float MaxZ;
};

/* 11924 */
struct camViewport_s
{
  int x;
  int y;
  int w;
  int h;
};

/* 11922 */
struct plane3d
{
  vec3d n;
  float d;
};

/* 11923 */
struct frustum3d
{
  vec3d verts[6];
  plane3d planes[6];
};

/* 2028 */
enum camManDisplayMode_e : uint32_t
{
  camManDisplayMode_NULL = 0x0,
  camManDisplayMode_SP = 0x1,
  camManDisplayMode_MPHorz = 0x2,
  camManDisplayMode_MPVert = 0x3,
  camManDisplayMode_MPThree = 0x4,
  camManDisplayMode_MPFour = 0x5,
  camManDisplayMode_MAX = 0x6,
};

/* 17546 */
struct camMainWorkspace_s_unnamed_tag
{
  camManDisplayMode_e mode;
  int dummy[3];
};

/* 17547 */
struct camMainWorkspace_s
{
  float viewMtx[4][4];
  float projMtx[4][4];
  float visCamToWorldMtx[4][4];
  camVirt_s defaultVirtCam;
  _D3DVIEWPORT9 FullScreenViewport;
  camVirt_s *virtCam;
  camViewport_s viewport;
  frustum3d clipFrustum;
  mlVec dirVec;
  camViewport_s outputViewport;
  float fovY;
  camVirt_Aspect_e viewportAspect;
  int isOrthoCamera;
  int viewIsDirty;
  int projIsDirty;
  int D3DViewportIsDirty;
  int outputViewportIsDirty;
  camMainWorkspace_s_unnamed_tag xuiViewports;
  uint8_t pad[5];
};

/* 17074 */
struct scenegraphDrawStaticWorkspace_s
{
  mlV4 grassParams;
  float shadowReceivingStrength;
  float shadowKernelScale;
  int isFurEnabled;
  unsigned int isFurEnabledCount;
  int drawMode;
  int enableViewProjectionSetting;
  float grayScaleRemappingValue;
  float globalTessellationValue;
  float globalTessellationScale;
  float globalTessellationOffset;
  int wireframeMode;
  int fadeShadowBufferContribution;
  float basis[4][4];
  float invBasis[4][4];
  float view[4][4];
  float projection[4][4];
  float projDrawModeMtx[4][4];
  mlVec cameraPosition;
  float viewMtxStack[16][4][4];
  float projMtxStack[16][4][4];
  unsigned int viewMtxStackSize;
  unsigned int projMtxStackSize;
  int cullMode;
  int vertexBufferList; //offset
  int indexBufferList; //offset
  int vertexDeclarationList; //offset
  int opaqueAlphaBlend;
  int curShadowBuffer;
  int furLayerJump;
  mlVec furTranslationDelta;
  int currentContextIndex;
  int curRenderTarget;
  int curDepthStencilSurface;
  _D3DVIEWPORT9 curViewport;
  int isUsingFloatingPointDepthBuffer;
  int isStateValid;
  mlV4 uvScaleOffset;
};