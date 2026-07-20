ByteAddressBuffer xe_shared_memory_srv : register(t0);
RWByteAddressBuffer xe_shared_memory_uav : register(u0);

cbuffer xe_system_cbuffer : register(b0) {
    uint4 xe_system_consts[29];
};

cbuffer xe_fetch_cbuffer : register(b3) {
    uint4 xe_fetch_constants[48];
};

#define XE_FLAGS (xe_system_consts[0].x)
#define XE_LINE_LOOP_CLOSING_INDEX (xe_system_consts[0].w)
#define XE_VERTEX_INDEX_ENDIAN (xe_system_consts[1].x)
#define XE_VERTEX_INDEX_OFFSET (xe_system_consts[1].y)
#define XE_VERTEX_INDEX_MIN (xe_system_consts[1].z)
#define XE_VERTEX_INDEX_MAX (xe_system_consts[1].w)
#define XE_NDC_SCALE (asfloat(xe_system_consts[8].xyz))
#define XE_NDC_OFFSET (asfloat(xe_system_consts[9].xyz))
#define XE_FLAG_SHARED_MEMORY_IS_UAV 1u
#define XE_FLAG_XY_DIVIDED_BY_W 2u
#define XE_FLAG_Z_DIVIDED_BY_W 4u
#define XE_FLAG_W_NOT_RECIPROCAL 8u

uint XeEndianX(uint v, uint e) {
  if (e == 1u || e == 2u) v = ((v & 0x00FF00FFu) << 8u) | ((v >> 8u) & 0x00FF00FFu);
  if (e == 2u || e == 3u) v = (v << 16u) | (v >> 16u);
  return v;
}

uint3 XeEndian3(uint3 v, uint e) {
  if (e == 1u || e == 2u) v = ((v & 0x00FF00FFu) << 8u) | ((v >> 8u) & 0x00FF00FFu);
  if (e == 2u || e == 3u) v = (v << 16u) | (v >> 16u);
  return v;
}

uint4 XeEndian4(uint4 v, uint e) {
  if (e == 1u || e == 2u) v = ((v & 0x00FF00FFu) << 8u) | ((v >> 8u) & 0x00FF00FFu);
  if (e == 2u || e == 3u) v = (v << 16u) | (v >> 16u);
  return v;
}

struct VSOutput {
#ifdef XE_OUTPUT_INTERP0
    float4 interp0 : TEXCOORD0;
#endif
    float4 position : SV_Position;
};

VSOutput main(uint vertex_id : SV_VertexID)
{
    VSOutput o;
    uint index = vertex_id;
    if (index == XE_LINE_LOOP_CLOSING_INDEX) index = 0u;
    index = XeEndianX(index, XE_VERTEX_INDEX_ENDIAN);
    index = index + XE_VERTEX_INDEX_OFFSET;
    index = index & 0x00FFFFFFu;
    index = max(index, XE_VERTEX_INDEX_MIN);
    index = min(index, XE_VERTEX_INDEX_MAX);
    int vi = (int)round((float)index);
    uint base = xe_fetch_constants[0].x & 0xFFFFFFFCu;
    uint fetchEndian = xe_fetch_constants[0].y & 3u;
    uint addr = uint(vi * 28) + base;
    bool useUav = (XE_FLAGS & XE_FLAG_SHARED_MEMORY_IS_UAV) != 0u;
    uint3 pRaw = useUav ? xe_shared_memory_uav.Load3(addr) : xe_shared_memory_srv.Load3(addr);
    float3 posXYZ = asfloat(XeEndian3(pRaw, fetchEndian));
    uint4 aRaw = useUav ? xe_shared_memory_uav.Load4(addr + 12u) : xe_shared_memory_srv.Load4(addr + 12u);
    float4 attr = asfloat(XeEndian4(aRaw, fetchEndian));
#ifdef XE_OUTPUT_INTERP0
    o.interp0 = attr;
#endif
    float4 pos = float4(posXYZ, 1.0f);
    float w = pos.w;
    if ((XE_FLAGS & XE_FLAG_W_NOT_RECIPROCAL) == 0u) w = 1.0f / w;
    if ((XE_FLAGS & XE_FLAG_XY_DIVIDED_BY_W) != 0u) pos.xy *= w;
    if ((XE_FLAGS & XE_FLAG_Z_DIVIDED_BY_W) != 0u) pos.z *= w;
    pos.xyz = pos.xyz * XE_NDC_SCALE + XE_NDC_OFFSET * w;
    o.position = float4(pos.xyz, w);
    return o;
}
