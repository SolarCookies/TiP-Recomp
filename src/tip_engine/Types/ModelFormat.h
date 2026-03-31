#pragma once
#include "CommonTypes.h"

/* 11760 */
struct dbTriHitPosArray_s
{
	unsigned char type;
	unsigned char fp;
	unsigned char stride;
	unsigned char __UNUSED;
	unsigned int numPositions;
	void* positions;
};

/* 11761 */
struct dbTriHit_s
{
	unsigned int numParts;
	dbTriHitPosArray_s posArray;
};

/* 11762 */
struct dbMirrorUnit_s
{
	uint16_t numTriangles;
	uint16_t startTriangle;
};

/* 11763 */
struct dbMirror_s
{
	uint16_t numMirrors;
	dbMirrorUnit_s* mirrorList;
	mlVec* vertexList;
	uint16_t* triangleList;
};

/* 11765 */
struct dbModelTextureUnit_s
{
	unsigned int numTextures;
	dbTexture_s** textureHeaders;
	assetId_s** textureAssetId;
};


/* 11766 */
struct dbMoldGeometryVertex_s
{
	vec3d pos;
	float intensity;
};

/* 11767 */
struct dbMoldGeometryTriangle_s
{
	unsigned int idx[3];
	int attribute;
};

/* 11768 */
struct dbMoldGeometry_s
{
	dbMoldGeometryVertex_s* vertices;
	unsigned int numVertices;
	dbMoldGeometryTriangle_s* triangles;
	unsigned int numTriangles;
	vec3d aabbMin;
	vec3d aabbMax;
};

/* 11770 */
struct dbModelClimbPoleUnitNode_s
{
	mlVec wp;
	mlRot_s wr;
	float yaw;
	float height;
	int jointIndex;
	int type;
	float angleLimit;
	float radius;
};

/* 11771 */
struct dbModelClimbPoleUnit_s
{
	int numPathNodes;
	dbModelClimbPoleUnitNode_s* pathNodes;
};

/* 11772 */
struct dbModelClimbPole_s
{
	int numClimbPoles;
	dbModelClimbPoleUnit_s* pathList;
};

/* 11773 */
struct dbExtent_s_unnamed_tag
{
	float radius;
};

/* 11774 */
struct dbExtent_s
{
	dbExtent_s_unnamed_tag proximitySphere;
	char boundingSphere[16];
	char boundingCylinder[20];
	char boundingBox[24];
};

/* 11775 */
struct dbModelJoint_s
{
	unsigned char lookupTable[76];
};

/* 11776 */
struct dbLight_s
{
	unsigned int no;
};

/* 11777 */
struct dbLightVolumeUnit_s
{
	int type;
	vec3d position;
	float radius;
	vec4d colour;
	int jointIndex;
	vec3d direction;
	vec3d up;
	float fov;
	float lightShaftAttenuationRadius;
	int isMainLight;
	int colourTextureIndex;
	int noiseTextureIndex;
	float* keyframedIntensity;
	int keyframedIntensitySize;
	float animationDurationSecs;
	float animationTimestepSecs;
};

/* 11778 */
struct dbLightVolume_s
{
	dbLightVolumeUnit_s* lightVolumeList;
	int lightVolumeListSize;
	dbModelTextureUnit_s lightTextureList;
};

/* 11779 */
struct dbLocator_s
{
	unsigned int numLocators;
};

/* 11783 */
struct dbVolume_s
{
	unsigned int numVolumes;
	float cullRadius;
};

/* 11784 */
struct dbModelSwitch_s
{
	unsigned char numSwitches;
	unsigned char numStatesPerSwitch;
	unsigned char pad_1;
	unsigned char pad_2;
};


/* 11782 */
struct dbScenegraph_s
{
	_ndGroup_s* sgRoot;
	_ndVisGroup_s* visRoot;
	dbModelTextureUnit_s textureList;
	char** textureMapping;
	int textureMappingSize;
	int numJoints;
	struct _blendShapeUnit_s* blendShapeList;
	int blendShapeListSize;
	struct _customShaderConst_s* customVsConstList;
	int customVsConstListSize;
	int vsConstBase;
	struct _customShaderConst_s* customPsConstList;
	int customPsConstListSize;
	int psConstBase;
	char** shaderContextMapping;
	int shaderContextMappingSize;
	int visArraySize;
	char** colourDisplacementNameMapping;
	int colourDisplacementNameMappingSize;
	struct _bitUnit_s* bitUnitList;
	int bitUnitListSize;
	int numExtendedJoints;
	void* vertexBufferList;
	int vertexBufferListSize;
	void* indexBufferList;
	int indexBufferListSize;
	void* vertexDeclarationList;
	int vertexDeclarationListSize;
	int shadersHaveBeenBuilt;
	struct _membraneUnit_s* membraneUnitList;
	int membraneUnitListSize;
	void* _gamesideAllocationPtr;
	int maxNumBlendShapeInfluences;
	unsigned int flags;
	float furPhysicsSphereConstraintOffset;
	float furPhysicsSphereConstraintRadius;
	void* _SPARE_1;
};

/* 11785 */
struct dbModelRuntime_s
{
	dbTriHit_s* trihits;
	dbMirror_s* mirror;
	struct sgGraph* sg;
	dbModelTextureUnit_s* texpalette;
	struct dbShadowGeometry_s* shadowGeometry;
	dbMoldGeometry_s* moldGeometry;
	const dbModelClimbPole_s* climbPoles;
	const dbExtent_s* extent;
	const dbModelJoint_s* joint;
	const dbLight_s* light;
	const dbLightVolume_s* lightVolume;
	const dbLocator_s* locator;
	const dbScenegraph_s* sceneGraph;
	const dbVolume_s* volume;
	const dbModelSwitch_s* switchMask;
};

/* 1581 */
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

/* 11759 */
struct dbModelUnit_s
{
	dbModelUnitId_e id;
	void* data;
};



/* 11786 */
struct dbModel_s
{
	dbModelUnit_s* units;
	unsigned int numUnits;
	unsigned int flags;
	unsigned int headerSize;
	dbModelRuntime_s* runtime;
};

/* 11692 */
struct animPose_s
{
	uint32_t numExtendedJoints : 16;
	uint32_t numJoints : 16;
	int valid;
	int noMtxBuffer;
	unsigned int __pad[1];
};

/* 11787 */
struct glModel_s_unnamed_tag
{
	animPose_s* standard;
	animPose_s* override;
};

/* 11795 */
struct scenegraphDrawContextLookup_s
{
	int mapping[10];
};



/* 11788 */
struct scenegraphInstBlendShapeUnitElement_s
{
	int index;
	float weight;
};

/* 11789 */
struct scenegraphInstBlendShapeUnit_s
{
	scenegraphInstBlendShapeUnitElement_s* sortedTargetList;
	int sortedTargetListSize;
};

/* 11791 */
struct scenegraphInstTextureTable_s
{
	char* name;
	dbTexture_s* currentTexture;
	dbTexture_s* originalTexture;
};

/* 11792 */
struct scenegraphInstBitParams_s
{
	mlVec velocity;
	mlVec positionMS;
	mlVec centreMS;
	mlVec pivotMS;
	float scale;
	int mappedJoint;
	int originalJoint;
	mlRot_s pyr;
	int isAtRest;
	char* identifier;
};

/* 11793 */
struct scenegraphInstColourDisplacement_s
{
	char name[128];
	int doesTargetRequireBaseFurGain;
	float blend;
};

/* 11794 */
struct scenegraphInstLODUnit_s
{
	int lodLevel;
	float tessellationLevel;
};

/* 11796 */
struct scenegraphInst_s
{
	const dbScenegraph_s* sg;
	int nodeCount;
	int* visArray;
	void** nodeArray;
	float blendShapeWeights[52];
	scenegraphInstBlendShapeUnit_s* blendShapeArray;
	int blendShapeArraySize;
	int tickOfLastBlendShapeUpdate;
	mtx44* posePtr;
	int numExtendedJoints;
	int numJoints;
	int vsConstBase;
	unsigned char enableReflectedColour;
	unsigned char solidColourEnabled;
	unsigned char useOpaqueDithering;
	unsigned char __pad3;
	mlColour_s solidColour;
	mlColour_s ambientOverride;
	int isAmbientOverrideEnabled;
	int disableDesaturation;
	float textureBlendVal;
	scenegraphInstTextureTable_s* textureTable;
	int textureTableSize;
	scenegraphInstBitParams_s* bitParams;
	int bitParamsSize;
	int isExploding;
	scenegraphInstColourDisplacement_s* colourDisplacementTable;
	int colourDisplacementTableSize;
	void* dynamicVertexBuffer[2];
	int* dynamicVertexBufferNodeOffsetArray;
	unsigned char parallaxScaleAndBiasPSConst;
	unsigned char perturbationScalePSConst;
	unsigned char grayScaleSolidCutoffPSConst;
	unsigned char defaultColourIndex;
	unsigned char specialAbilityColourIndex;
	unsigned char curVariantColourIndex;
	unsigned char __pad1;
	unsigned char __pad2;
	float grayscaleRemappingValue;
	int** exportVertexBufferArray[2];
	int curVertexBufferExportTargetIdx;
	int curVertexBufferExportSourceIdx;
	int tickOfLastExportUpdate;
	scenegraphInstLODUnit_s* lodUnitArray;
	int useLodDistanceOverride;
	float lodDistanceOverride;
	void* _blockAllocationPtr;
	scenegraphDrawContextLookup_s contextLookup;
};

/* 11797 */
struct glModel_s
{
	const dbModel_s* model;
	const dbModel_s* modelExtras;
	glModel_s_unnamed_tag pose[2];
	unsigned char volume[160];
	unsigned char solidColour[12];
	dbLight_s* lightObj;
	int disableJointWeighting;
	unsigned char switchStateArray[1][16];
	unsigned char switchHitsStateArray[16];
	mlV4 textureBlend;
	int volumeLightList[8];
	int volumeLightListSize;
	int mtxBufferOverride;
	int* visQuery;
	int visQueryIsVisible;
	int visQueryTimer;
	int visQueryNumConsecutiveTestSuccesses;
	int useOpaqueDithering;
	scenegraphInst_s sgInst;
	assetId_s modelAid;
	int isPoseDirty;
};


