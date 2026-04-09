#include "retip_init.h"

__attribute__((alias("__imp__sub_82B6D750"))) PPC_WEAK_FUNC(sub_82B6D750);
PPC_FUNC_IMPL(__imp__sub_82B6D750) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82ae15f0
	ctx.lr = 0x82B6D758;
	__savegprlr_14(ctx, base);
	// stwu r1,-1024(r1)
	ea = -1024 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// stw r5,1060(r1)
	PPC_STORE_U32(ctx.r1.u32 + 1060, ctx.r5.u32);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r10,1312(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1312);
	// lwz r11,1392(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1392);
	// cmpwi cr6,r11,2
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 2, ctx.xer);
	// stw r10,628(r1)
	PPC_STORE_U32(ctx.r1.u32 + 628, ctx.r10.u32);
	// beq cr6,0x82b6d788
	if (ctx.cr6.eq) goto loc_82B6D788;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// mr r11,r6
	ctx.r11.u64 = ctx.r6.u64;
	// bne cr6,0x82b6d78c
	if (!ctx.cr6.eq) goto loc_82B6D78C;
loc_82B6D788:
	// li r11,1
	ctx.r11.s64 = 1;
loc_82B6D78C:
	// stw r6,0(r5)
	PPC_STORE_U32(ctx.r5.u32 + 0, ctx.r6.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// stw r6,4(r5)
	PPC_STORE_U32(ctx.r5.u32 + 4, ctx.r6.u32);
	// sth r6,16(r5)
	PPC_STORE_U16(ctx.r5.u32 + 16, ctx.r6.u16);
	// stw r11,600(r1)
	PPC_STORE_U32(ctx.r1.u32 + 600, ctx.r11.u32);
	// lwz r11,616(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 616);
	// stw r11,36(r5)
	PPC_STORE_U32(ctx.r5.u32 + 36, ctx.r11.u32);
	// lwz r10,428(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// stw r10,40(r5)
	PPC_STORE_U32(ctx.r5.u32 + 40, ctx.r10.u32);
	// lwz r9,1164(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1164);
	// stw r9,44(r5)
	PPC_STORE_U32(ctx.r5.u32 + 44, ctx.r9.u32);
	// lhz r7,52(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 52);
	// lhz r9,50(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// subfic r4,r11,2
	ctx.xer.ca = ctx.r11.u32 <= 2;
	ctx.r4.u64 = static_cast<uint64_t>(2) - ctx.r11.u64;
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lhz r8,74(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 74);
	// rlwinm r4,r7,31,1,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// lhz r7,76(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r30,r9,31,1,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r6,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, ctx.r6.u32);
	// stw r6,596(r1)
	PPC_STORE_U32(ctx.r1.u32 + 596, ctx.r6.u32);
	// stw r4,716(r1)
	PPC_STORE_U32(ctx.r1.u32 + 716, ctx.r4.u32);
	// stw r30,636(r1)
	PPC_STORE_U32(ctx.r1.u32 + 636, ctx.r30.u32);
	// stw r10,720(r1)
	PPC_STORE_U32(ctx.r1.u32 + 720, ctx.r10.u32);
	// stw r10,468(r1)
	PPC_STORE_U32(ctx.r1.u32 + 468, ctx.r10.u32);
	// beq cr6,0x82b6d808
	if (ctx.cr6.eq) goto loc_82B6D808;
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stw r10,468(r1)
	PPC_STORE_U32(ctx.r1.u32 + 468, ctx.r10.u32);
loc_82B6D808:
	// mullw r11,r11,r4
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r4.s32);
	// lwz r9,268(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 268);
	// stw r6,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r6.u32);
	// mullw r11,r11,r30
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r30.s32);
	// rlwinm r10,r11,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// stw r9,444(r1)
	PPC_STORE_U32(ctx.r1.u32 + 444, ctx.r9.u32);
	// beq cr6,0x82b73098
	if (ctx.cr6.eq) goto loc_82B73098;
	// rlwinm r11,r8,4,0,27
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r14,108(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// rlwinm r10,r7,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r15,104(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// stw r11,712(r1)
	PPC_STORE_U32(ctx.r1.u32 + 712, ctx.r11.u32);
	// stw r10,724(r1)
	PPC_STORE_U32(ctx.r1.u32 + 724, ctx.r10.u32);
	// b 0x82b6d85c
	goto loc_82B6D85C;
loc_82B6D850:
	// lwz r5,1060(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1060);
	// li r6,0
	ctx.r6.s64 = 0;
	// lwz r30,636(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 636);
loc_82B6D85C:
	// lwz r11,592(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 592);
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// lwz r10,596(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 596);
	// stw r6,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r6.u32);
	// sth r6,18(r5)
	PPC_STORE_U16(ctx.r5.u32 + 18, ctx.r6.u16);
	// stw r11,8(r5)
	PPC_STORE_U32(ctx.r5.u32 + 8, ctx.r11.u32);
	// stw r10,12(r5)
	PPC_STORE_U32(ctx.r5.u32 + 12, ctx.r10.u32);
	// beq cr6,0x82b73040
	if (ctx.cr6.eq) goto loc_82B73040;
loc_82B6D87C:
	// lwz r11,1060(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1060);
	// lwz r16,348(r31)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r31.u32 + 348);
	// lwz r10,628(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 628);
	// addi r9,r10,8
	ctx.r9.s64 = ctx.r10.s64 + 8;
	// lwz r18,0(r11)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// stw r16,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r16.u32);
	// rlwinm r8,r18,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// ld r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// stw r9,628(r1)
	PPC_STORE_U32(ctx.r1.u32 + 628, ctx.r9.u32);
	// stw r18,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r18.u32);
	// lwzx r7,r8,r16
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r16.u32);
	// cmpwi cr6,r7,16384
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 16384, ctx.xer);
	// beq cr6,0x82b72fdc
	if (ctx.cr6.eq) goto loc_82B72FDC;
	// rldicl r11,r11,9,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 9) & 0x1FF;
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82b71834
	if (ctx.cr6.eq) goto loc_82B71834;
	// lwz r11,444(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 444);
	// lwz r10,1060(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1060);
	// lhz r17,50(r31)
	ctx.r17.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// lwz r9,116(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r8,128(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// rlwinm r19,r9,1,0,30
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r6,4(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 4);
	// rlwinm r10,r8,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r11,r7,27,29,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x7;
	// stw r17,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r17.u32);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stw r6,516(r1)
	PPC_STORE_U32(ctx.r1.u32 + 516, ctx.r6.u32);
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// stw r11,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r11.u32);
	// bgt cr6,0x82b70298
	if (ctx.cr6.gt) goto loc_82B70298;
	// rotlwi r11,r11,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 0);
	// lis r12,-32073
	ctx.r12.s64 = -2101936128;
	// addi r12,r12,-9956
	ctx.r12.s64 = ctx.r12.s64 + -9956;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82B6F880;
	case 1:
		goto loc_82B6E35C;
	case 2:
		goto loc_82B6EE4C;
	case 3:
		goto loc_82B6D92C;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82B6D92C:
	// rlwinm r11,r18,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r25,1840(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// clrlwi r20,r10,31
	ctx.r20.u64 = ctx.r10.u32 & 0x1;
	// lwz r24,1836(r31)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// add r28,r11,r16
	ctx.r28.u64 = ctx.r11.u64 + ctx.r16.u64;
	// stw r20,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r20.u32);
	// srawi r21,r17,1
	ctx.xer.ca = (ctx.r17.s32 < 0) & ((ctx.r17.u32 & 0x1) != 0);
	ctx.r21.s64 = ctx.r17.s32 >> 1;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// lwzx r22,r11,r16
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r16.u32);
	// stw r22,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r22.u32);
	// bne cr6,0x82b6d984
	if (!ctx.cr6.eq) goto loc_82B6D984;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82b6d978
	if (ctx.cr6.eq) goto loc_82B6D978;
	// srawi r11,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 1;
	// lwz r10,1304(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1304);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82b6d984
	if (ctx.cr6.eq) goto loc_82B6D984;
loc_82B6D978:
	// li r29,1
	ctx.r29.s64 = 1;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x82b6d98c
	goto loc_82B6D98C;
loc_82B6D984:
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
loc_82B6D98C:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,-32078
	ctx.r10.s64 = -2102263808;
	// lis r9,-32078
	ctx.r9.s64 = -2102263808;
	// stw r30,232(r1)
	PPC_STORE_U32(ctx.r1.u32 + 232, ctx.r30.u32);
	// rlwinm r8,r11,17,0,14
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// stw r30,228(r1)
	PPC_STORE_U32(ctx.r1.u32 + 228, ctx.r30.u32);
	// lis r7,1
	ctx.r7.s64 = 65536;
	// stw r30,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r30.u32);
	// srawi r23,r22,16
	ctx.xer.ca = (ctx.r22.s32 < 0) & ((ctx.r22.u32 & 0xFFFF) != 0);
	ctx.r23.s64 = ctx.r22.s32 >> 16;
	// stw r30,388(r1)
	PPC_STORE_U32(ctx.r1.u32 + 388, ctx.r30.u32);
	// addi r6,r10,12136
	ctx.r6.s64 = ctx.r10.s64 + 12136;
	// stw r30,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, ctx.r30.u32);
	// addi r5,r9,12416
	ctx.r5.s64 = ctx.r9.s64 + 12416;
	// stw r23,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r23.u32);
	// subf r4,r8,r7
	ctx.r4.u64 = ctx.r7.u64 - ctx.r8.u64;
	// stw r6,1744(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1744, ctx.r6.u32);
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
	// stw r5,1748(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1748, ctx.r5.u32);
	// mr r26,r30
	ctx.r26.u64 = ctx.r30.u64;
	// stw r4,392(r1)
	PPC_STORE_U32(ctx.r1.u32 + 392, ctx.r4.u32);
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// beq cr6,0x82b6da58
	if (ctx.cr6.eq) goto loc_82B6DA58;
	// addi r11,r18,-1
	ctx.r11.s64 = ctx.r18.s64 + -1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r25,r11
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// lhzx r9,r24,r11
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r24.u32 + ctx.r11.u32);
	// sth r10,144(r1)
	PPC_STORE_U16(ctx.r1.u32 + 144, ctx.r10.u16);
	// sth r9,146(r1)
	PPC_STORE_U16(ctx.r1.u32 + 146, ctx.r9.u16);
	// lwz r4,144(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b6da58
	if (ctx.cr6.eq) goto loc_82B6DA58;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6da38
	if (ctx.cr6.eq) goto loc_82B6DA38;
	// stw r4,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, ctx.r4.u32);
	// rotlwi r11,r6,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6DA2C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r3.u32);
	// li r26,1
	ctx.r26.s64 = 1;
	// b 0x82b6da54
	goto loc_82B6DA54;
loc_82B6DA38:
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,224(r1)
	PPC_STORE_U32(ctx.r1.u32 + 224, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6DA4C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,384(r1)
	PPC_STORE_U32(ctx.r1.u32 + 384, ctx.r3.u32);
	// li r27,1
	ctx.r27.s64 = 1;
loc_82B6DA54:
	// li r30,1
	ctx.r30.s64 = 1;
loc_82B6DA58:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x82b6db7c
	if (!ctx.cr6.eq) goto loc_82B6DB7C;
	// subf r29,r17,r18
	ctx.r29.u64 = ctx.r18.u64 - ctx.r17.u64;
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r24,r11
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r24.u32 + ctx.r11.u32);
	// lhzx r9,r25,r11
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// sth r10,146(r1)
	PPC_STORE_U16(ctx.r1.u32 + 146, ctx.r10.u16);
	// sth r9,144(r1)
	PPC_STORE_U16(ctx.r1.u32 + 144, ctx.r9.u16);
	// lwz r4,144(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b6dae4
	if (ctx.cr6.eq) goto loc_82B6DAE4;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r15,r30,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6dabc
	if (ctx.cr6.eq) goto loc_82B6DABC;
	// addi r10,r1,384
	ctx.r10.s64 = ctx.r1.s64 + 384;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r15,r10
	PPC_STORE_U32(ctx.r15.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6DAB0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// b 0x82b6dadc
	goto loc_82B6DADC;
loc_82B6DABC:
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r15,r10
	PPC_STORE_U32(ctx.r15.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6DAD4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,384
	ctx.r9.s64 = ctx.r1.s64 + 384;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
loc_82B6DADC:
	// stwx r3,r15,r9
	PPC_STORE_U32(ctx.r15.u32 + ctx.r9.u32, ctx.r3.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_82B6DAE4:
	// cmpwi cr6,r21,1
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 1, ctx.xer);
	// ble cr6,0x82b6db7c
	if (!ctx.cr6.gt) goto loc_82B6DB7C;
	// addi r11,r17,-2
	ctx.r11.s64 = ctx.r17.s64 + -2;
	// cmpw cr6,r19,r11
	ctx.cr6.compare<int32_t>(ctx.r19.s32, ctx.r11.s32, ctx.xer);
	// addi r11,r29,2
	ctx.r11.s64 = ctx.r29.s64 + 2;
	// bne cr6,0x82b6db00
	if (!ctx.cr6.eq) goto loc_82B6DB00;
	// addi r11,r29,-2
	ctx.r11.s64 = ctx.r29.s64 + -2;
loc_82B6DB00:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r24,r11
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r24.u32 + ctx.r11.u32);
	// lhzx r9,r25,r11
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// sth r10,146(r1)
	PPC_STORE_U16(ctx.r1.u32 + 146, ctx.r10.u16);
	// sth r9,144(r1)
	PPC_STORE_U16(ctx.r1.u32 + 144, ctx.r9.u16);
	// lwz r4,144(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b6db7c
	if (ctx.cr6.eq) goto loc_82B6DB7C;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r30,r30,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6db58
	if (ctx.cr6.eq) goto loc_82B6DB58;
	// addi r10,r1,384
	ctx.r10.s64 = ctx.r1.s64 + 384;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r30,r10
	PPC_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6DB4C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,224
	ctx.r9.s64 = ctx.r1.s64 + 224;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// b 0x82b6db78
	goto loc_82B6DB78;
loc_82B6DB58:
	// addi r10,r1,224
	ctx.r10.s64 = ctx.r1.s64 + 224;
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r30,r10
	PPC_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6DB70;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,384
	ctx.r9.s64 = ctx.r1.s64 + 384;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
loc_82B6DB78:
	// stwx r3,r30,r9
	PPC_STORE_U32(ctx.r30.u32 + ctx.r9.u32, ctx.r3.u32);
loc_82B6DB7C:
	// add r11,r26,r27
	ctx.r11.u64 = ctx.r26.u64 + ctx.r27.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x82b6dd00
	if (!ctx.cr6.gt) goto loc_82B6DD00;
	// lhz r11,234(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 234);
	// lhz r10,230(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 230);
	// lhz r9,226(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 226);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// extsh r29,r10
	ctx.r29.s64 = ctx.r10.s16;
	// lhz r8,232(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 232);
	// extsh r25,r9
	ctx.r25.s64 = ctx.r9.s16;
	// lhz r7,228(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 228);
	// lhz r6,224(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 224);
	// extsh r24,r8
	ctx.r24.s64 = ctx.r8.s16;
	// lhz r5,394(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 394);
	// extsh r23,r7
	ctx.r23.s64 = ctx.r7.s16;
	// extsh r22,r6
	ctx.r22.s64 = ctx.r6.s16;
	// lhz r4,390(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 390);
	// subf r10,r25,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r25.u64;
	// lhz r11,386(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 386);
	// subf r9,r30,r29
	ctx.r9.u64 = ctx.r29.u64 - ctx.r30.u64;
	// lhz r8,392(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 392);
	// extsh r18,r5
	ctx.r18.s64 = ctx.r5.s16;
	// lhz r6,388(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 388);
	// subf r7,r25,r30
	ctx.r7.u64 = ctx.r30.u64 - ctx.r25.u64;
	// lhz r21,384(r1)
	ctx.r21.u64 = PPC_LOAD_U16(ctx.r1.u32 + 384);
	// xor r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// extsh r17,r4
	ctx.r17.s64 = ctx.r4.s16;
	// subf r20,r22,r23
	ctx.r20.u64 = ctx.r23.u64 - ctx.r22.u64;
	// subf r19,r24,r23
	ctx.r19.u64 = ctx.r23.u64 - ctx.r24.u64;
	// subf r4,r22,r24
	ctx.r4.u64 = ctx.r24.u64 - ctx.r22.u64;
	// extsh r16,r11
	ctx.r16.s64 = ctx.r11.s16;
	// xor r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// xor r9,r19,r20
	ctx.r9.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r5,r4,r20
	ctx.r5.u64 = ctx.r4.u64 ^ ctx.r20.u64;
	// extsh r14,r6
	ctx.r14.s64 = ctx.r6.s16;
	// extsh r15,r8
	ctx.r15.s64 = ctx.r8.s16;
	// extsh r21,r21
	ctx.r21.s64 = ctx.r21.s16;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 31;
	// subf r7,r16,r17
	ctx.r7.u64 = ctx.r17.u64 - ctx.r16.u64;
	// subf r20,r21,r14
	ctx.r20.u64 = ctx.r14.u64 - ctx.r21.u64;
	// subf r6,r18,r17
	ctx.r6.u64 = ctx.r17.u64 - ctx.r18.u64;
	// subf r19,r15,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r15.u64;
	// subf r5,r21,r15
	ctx.r5.u64 = ctx.r15.u64 - ctx.r21.u64;
	// subf r4,r16,r18
	ctx.r4.u64 = ctx.r18.u64 - ctx.r16.u64;
	// xor r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// xor r19,r19,r20
	ctx.r19.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r20,r5,r20
	ctx.r20.u64 = ctx.r5.u64 ^ ctx.r20.u64;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// xor r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// srawi r7,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 31;
	// stw r5,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// and r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 & ctx.r25.u64;
	// lwz r25,112(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// stw r6,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// srawi r6,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r4.s32 >> 31;
	// srawi r5,r19,31
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r19.s32 >> 31;
	// srawi r4,r20,31
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r20.s32 >> 31;
	// lwz r20,120(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// andc r30,r30,r20
	ctx.r30.u64 = ctx.r30.u64 & ~ctx.r20.u64;
	// and r8,r8,r22
	ctx.r8.u64 = ctx.r8.u64 & ctx.r22.u64;
	// andc r25,r24,r25
	ctx.r25.u64 = ctx.r24.u64 & ~ctx.r25.u64;
	// or r24,r7,r6
	ctx.r24.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 | ctx.r10.u64;
	// and r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 & ctx.r29.u64;
	// or r22,r5,r4
	ctx.r22.u64 = ctx.r5.u64 | ctx.r4.u64;
	// or r8,r25,r8
	ctx.r8.u64 = ctx.r25.u64 | ctx.r8.u64;
	// and r9,r9,r23
	ctx.r9.u64 = ctx.r9.u64 & ctx.r23.u64;
	// and r6,r6,r16
	ctx.r6.u64 = ctx.r6.u64 & ctx.r16.u64;
	// andc r30,r18,r24
	ctx.r30.u64 = ctx.r18.u64 & ~ctx.r24.u64;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 | ctx.r9.u64;
	// and r4,r4,r21
	ctx.r4.u64 = ctx.r4.u64 & ctx.r21.u64;
	// andc r29,r15,r22
	ctx.r29.u64 = ctx.r15.u64 & ~ctx.r22.u64;
	// or r9,r30,r6
	ctx.r9.u64 = ctx.r30.u64 | ctx.r6.u64;
	// and r8,r7,r17
	ctx.r8.u64 = ctx.r7.u64 & ctx.r17.u64;
	// and r6,r5,r14
	ctx.r6.u64 = ctx.r5.u64 & ctx.r14.u64;
	// or r7,r29,r4
	ctx.r7.u64 = ctx.r29.u64 | ctx.r4.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// or r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// lwz r17,164(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// lwz r18,160(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// lwz r16,100(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r23,108(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r20,104(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r22,96(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// sth r5,486(r1)
	PPC_STORE_U16(ctx.r1.u32 + 486, ctx.r5.u16);
	// sth r4,484(r1)
	PPC_STORE_U16(ctx.r1.u32 + 484, ctx.r4.u16);
	// sth r11,478(r1)
	PPC_STORE_U16(ctx.r1.u32 + 478, ctx.r11.u16);
	// sth r10,476(r1)
	PPC_STORE_U16(ctx.r1.u32 + 476, ctx.r10.u16);
	// b 0x82b6dd30
	goto loc_82B6DD30;
loc_82B6DD00:
	// bne cr6,0x82b6dd18
	if (!ctx.cr6.eq) goto loc_82B6DD18;
	// lwz r11,224(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 224);
	// lwz r10,384(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 384);
	// stw r11,484(r1)
	PPC_STORE_U32(ctx.r1.u32 + 484, ctx.r11.u32);
	// stw r10,476(r1)
	PPC_STORE_U32(ctx.r1.u32 + 476, ctx.r10.u32);
	// b 0x82b6dd30
	goto loc_82B6DD30;
loc_82B6DD18:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stw r3,484(r1)
	PPC_STORE_U32(ctx.r1.u32 + 484, ctx.r3.u32);
	// rlwinm r9,r11,17,0,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// subf r8,r9,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r9.u64;
	// stw r8,476(r1)
	PPC_STORE_U32(ctx.r1.u32 + 476, ctx.r8.u32);
loc_82B6DD30:
	// lwz r11,1396(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6dd4c
	if (ctx.cr6.eq) goto loc_82B6DD4C;
	// cmpw cr6,r27,r26
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r26.s32, ctx.xer);
	// ble cr6,0x82b6dd58
	if (!ctx.cr6.gt) goto loc_82B6DD58;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82b6dd5c
	if (!ctx.cr6.eq) goto loc_82B6DD5C;
loc_82B6DD4C:
	// lwz r11,1400(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6dd5c
	if (ctx.cr6.eq) goto loc_82B6DD5C;
loc_82B6DD58:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82B6DD5C:
	// clrlwi r11,r23,31
	ctx.r11.u64 = ctx.r23.u32 & 0x1;
	// lwz r9,476(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 476);
	// xor r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r11.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82b6dd74
	if (!ctx.cr6.eq) goto loc_82B6DD74;
	// lwz r9,484(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 484);
loc_82B6DD74:
	// rlwinm r10,r11,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lhz r8,62(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 62);
	// lhz r7,66(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 66);
	// add r11,r17,r18
	ctx.r11.u64 = ctx.r17.u64 + ctx.r18.u64;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// extsh r10,r8
	ctx.r10.s64 = ctx.r8.s16;
	// stw r6,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r6.u32);
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// lhz r4,146(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 146);
	// extsh r9,r4
	ctx.r9.s64 = ctx.r4.s16;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lhz r3,144(r1)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r1.u32 + 144);
	// mr r9,r8
	ctx.r9.u64 = ctx.r8.u64;
	// add r8,r10,r22
	ctx.r8.u64 = ctx.r10.u64 + ctx.r22.u64;
	// rlwinm r30,r11,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// and r7,r8,r5
	ctx.r7.u64 = ctx.r8.u64 & ctx.r5.u64;
	// rlwinm r29,r18,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r6,r9,r7
	ctx.r6.u64 = ctx.r7.u64 - ctx.r9.u64;
	// extsh r9,r3
	ctx.r9.s64 = ctx.r3.s16;
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// sth r5,2(r28)
	PPC_STORE_U16(ctx.r28.u32 + 2, ctx.r5.u16);
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// lwz r10,1836(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// add r4,r30,r10
	ctx.r4.u64 = ctx.r30.u64 + ctx.r10.u64;
	// sth r5,2(r4)
	PPC_STORE_U16(ctx.r4.u32 + 2, ctx.r5.u16);
	// add r11,r11,r16
	ctx.r11.u64 = ctx.r11.u64 + ctx.r16.u64;
	// lwz r10,1836(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// add r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 + ctx.r10.u64;
	// lhz r3,2(r10)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// sth r3,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r3.u16);
	// lwz r10,1836(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// add r8,r29,r10
	ctx.r8.u64 = ctx.r29.u64 + ctx.r10.u64;
	// lhzx r7,r30,r10
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r30.u32 + ctx.r10.u32);
	// sth r7,2(r8)
	PPC_STORE_U16(ctx.r8.u32 + 2, ctx.r7.u16);
	// lwz r10,1836(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// add r10,r29,r10
	ctx.r10.u64 = ctx.r29.u64 + ctx.r10.u64;
	// lhz r6,2(r10)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// sth r6,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r6.u16);
	// lhz r5,68(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 68);
	// lwz r4,1836(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// lhz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r31.u32 + 64);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lhzx r9,r29,r4
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r29.u32 + ctx.r4.u32);
	// extsh r8,r5
	ctx.r8.s64 = ctx.r5.s16;
	// add r7,r10,r23
	ctx.r7.u64 = ctx.r10.u64 + ctx.r23.u64;
	// extsh r14,r9
	ctx.r14.s64 = ctx.r9.s16;
	// and r5,r7,r8
	ctx.r5.u64 = ctx.r7.u64 & ctx.r8.u64;
	// stw r14,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r14.u32);
	// subf r4,r3,r5
	ctx.r4.u64 = ctx.r5.u64 - ctx.r3.u64;
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// sth r3,0(r28)
	PPC_STORE_U16(ctx.r28.u32 + 0, ctx.r3.u16);
	// lwz r10,1840(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// sth r3,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r3.u16);
	// lwz r10,1840(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// lhz r9,2(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// sth r9,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
	// lwz r10,1840(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// add r8,r29,r10
	ctx.r8.u64 = ctx.r29.u64 + ctx.r10.u64;
	// lhzx r7,r30,r10
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r30.u32 + ctx.r10.u32);
	// sth r7,2(r8)
	PPC_STORE_U16(ctx.r8.u32 + 2, ctx.r7.u16);
	// lwz r10,1840(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + ctx.r29.u64;
	// lhz r6,2(r10)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// sth r6,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r6.u16);
	// lwz r5,1840(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// lhzx r4,r5,r29
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r5.u32 + ctx.r29.u32);
	// extsh r15,r4
	ctx.r15.s64 = ctx.r4.s16;
	// lwz r3,0(r28)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// stw r3,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r3.u32);
	// stw r3,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r3.u32);
	// stw r3,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r3.u32);
	// lhz r27,50(r31)
	ctx.r27.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// srawi r23,r27,1
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x1) != 0);
	ctx.r23.s64 = ctx.r27.s32 >> 1;
	// lwz r26,1848(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// lwz r25,1844(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// stw r15,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r15.u32);
	// bne cr6,0x82b6deec
	if (!ctx.cr6.eq) goto loc_82B6DEEC;
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6dee0
	if (ctx.cr6.eq) goto loc_82B6DEE0;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// lwz r10,1304(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1304);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82b6deec
	if (ctx.cr6.eq) goto loc_82B6DEEC;
loc_82B6DEE0:
	// li r24,1
	ctx.r24.s64 = 1;
	// li r19,0
	ctx.r19.s64 = 0;
	// b 0x82b6def4
	goto loc_82B6DEF4;
loc_82B6DEEC:
	// li r19,0
	ctx.r19.s64 = 0;
	// mr r24,r19
	ctx.r24.u64 = ctx.r19.u64;
loc_82B6DEF4:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r17,1
	ctx.r17.s64 = 65536;
	// lwz r10,1372(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1372);
	// mr r21,r19
	ctx.r21.u64 = ctx.r19.u64;
	// rlwinm r9,r11,17,0,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// stw r19,264(r1)
	PPC_STORE_U32(ctx.r1.u32 + 264, ctx.r19.u32);
	// stw r19,260(r1)
	PPC_STORE_U32(ctx.r1.u32 + 260, ctx.r19.u32);
	// mr r22,r19
	ctx.r22.u64 = ctx.r19.u64;
	// subf r8,r9,r17
	ctx.r8.u64 = ctx.r17.u64 - ctx.r9.u64;
	// stw r19,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r19.u32);
	// stw r19,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, ctx.r19.u32);
	// mr r28,r19
	ctx.r28.u64 = ctx.r19.u64;
	// stw r19,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r19.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r8,360(r1)
	PPC_STORE_U32(ctx.r1.u32 + 360, ctx.r8.u32);
	// stw r21,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r21.u32);
	// bne cr6,0x82b6df4c
	if (!ctx.cr6.eq) goto loc_82B6DF4C;
	// lis r11,-32078
	ctx.r11.s64 = -2102263808;
	// lis r10,-32078
	ctx.r10.s64 = -2102263808;
	// addi r9,r11,11448
	ctx.r9.s64 = ctx.r11.s64 + 11448;
	// addi r8,r10,11856
	ctx.r8.s64 = ctx.r10.s64 + 11856;
	// b 0x82b6df5c
	goto loc_82B6DF5C;
loc_82B6DF4C:
	// lis r11,-32078
	ctx.r11.s64 = -2102263808;
	// lis r10,-32078
	ctx.r10.s64 = -2102263808;
	// addi r9,r11,11576
	ctx.r9.s64 = ctx.r11.s64 + 11576;
	// addi r8,r10,11512
	ctx.r8.s64 = ctx.r10.s64 + 11512;
loc_82B6DF5C:
	// lwz r11,116(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// stw r8,1748(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1748, ctx.r8.u32);
	// rlwinm r20,r11,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,1744(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1744, ctx.r9.u32);
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// beq cr6,0x82b6dfec
	if (ctx.cr6.eq) goto loc_82B6DFEC;
	// addi r11,r18,-1
	ctx.r11.s64 = ctx.r18.s64 + -1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r25,r11
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// lhzx r9,r26,r11
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r26.u32 + ctx.r11.u32);
	// sth r10,154(r1)
	PPC_STORE_U16(ctx.r1.u32 + 154, ctx.r10.u16);
	// sth r9,152(r1)
	PPC_STORE_U16(ctx.r1.u32 + 152, ctx.r9.u16);
	// lwz r4,152(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b6dfec
	if (ctx.cr6.eq) goto loc_82B6DFEC;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6dfcc
	if (ctx.cr6.eq) goto loc_82B6DFCC;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6DFBC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r21,1
	ctx.r21.s64 = 1;
	// stw r3,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r3.u32);
	// stw r21,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r21.u32);
	// b 0x82b6dfe8
	goto loc_82B6DFE8;
loc_82B6DFCC:
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,256(r1)
	PPC_STORE_U32(ctx.r1.u32 + 256, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6DFE0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,352(r1)
	PPC_STORE_U32(ctx.r1.u32 + 352, ctx.r3.u32);
	// li r22,1
	ctx.r22.s64 = 1;
loc_82B6DFE8:
	// li r28,1
	ctx.r28.s64 = 1;
loc_82B6DFEC:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// bne cr6,0x82b6e118
	if (!ctx.cr6.eq) goto loc_82B6E118;
	// subf r24,r27,r18
	ctx.r24.u64 = ctx.r18.u64 - ctx.r27.u64;
	// rlwinm r11,r24,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r25,r11
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// lhzx r9,r26,r11
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r26.u32 + ctx.r11.u32);
	// sth r10,154(r1)
	PPC_STORE_U16(ctx.r1.u32 + 154, ctx.r10.u16);
	// sth r9,152(r1)
	PPC_STORE_U16(ctx.r1.u32 + 152, ctx.r9.u16);
	// lwz r4,152(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b6e07c
	if (ctx.cr6.eq) goto loc_82B6E07C;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r18,r28,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6e054
	if (ctx.cr6.eq) goto loc_82B6E054;
	// addi r10,r1,352
	ctx.r10.s64 = ctx.r1.s64 + 352;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r18,r10
	PPC_STORE_U32(ctx.r18.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6E044;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// addi r9,r1,256
	ctx.r9.s64 = ctx.r1.s64 + 256;
	// stw r21,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r21.u32);
	// b 0x82b6e074
	goto loc_82B6E074;
loc_82B6E054:
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r18,r10
	PPC_STORE_U32(ctx.r18.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6E06C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,352
	ctx.r9.s64 = ctx.r1.s64 + 352;
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
loc_82B6E074:
	// stwx r3,r18,r9
	PPC_STORE_U32(ctx.r18.u32 + ctx.r9.u32, ctx.r3.u32);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_82B6E07C:
	// cmpwi cr6,r23,1
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 1, ctx.xer);
	// ble cr6,0x82b6e118
	if (!ctx.cr6.gt) goto loc_82B6E118;
	// addi r11,r27,-2
	ctx.r11.s64 = ctx.r27.s64 + -2;
	// cmpw cr6,r20,r11
	ctx.cr6.compare<int32_t>(ctx.r20.s32, ctx.r11.s32, ctx.xer);
	// addi r11,r24,2
	ctx.r11.s64 = ctx.r24.s64 + 2;
	// bne cr6,0x82b6e098
	if (!ctx.cr6.eq) goto loc_82B6E098;
	// addi r11,r24,-2
	ctx.r11.s64 = ctx.r24.s64 + -2;
loc_82B6E098:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r25,r11
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// lhzx r9,r26,r11
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r26.u32 + ctx.r11.u32);
	// sth r10,154(r1)
	PPC_STORE_U16(ctx.r1.u32 + 154, ctx.r10.u16);
	// sth r9,152(r1)
	PPC_STORE_U16(ctx.r1.u32 + 152, ctx.r9.u16);
	// lwz r4,152(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 152);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b6e118
	if (ctx.cr6.eq) goto loc_82B6E118;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r28,r28,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6e0f4
	if (ctx.cr6.eq) goto loc_82B6E0F4;
	// addi r10,r1,352
	ctx.r10.s64 = ctx.r1.s64 + 352;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r28,r10
	PPC_STORE_U32(ctx.r28.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6E0E4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// addi r9,r1,256
	ctx.r9.s64 = ctx.r1.s64 + 256;
	// stw r21,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r21.u32);
	// b 0x82b6e114
	goto loc_82B6E114;
loc_82B6E0F4:
	// addi r10,r1,256
	ctx.r10.s64 = ctx.r1.s64 + 256;
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r28,r10
	PPC_STORE_U32(ctx.r28.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6E10C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,352
	ctx.r9.s64 = ctx.r1.s64 + 352;
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
loc_82B6E114:
	// stwx r3,r28,r9
	PPC_STORE_U32(ctx.r28.u32 + ctx.r9.u32, ctx.r3.u32);
loc_82B6E118:
	// add r11,r22,r21
	ctx.r11.u64 = ctx.r22.u64 + ctx.r21.u64;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x82b6e290
	if (!ctx.cr6.gt) goto loc_82B6E290;
	// lhz r11,266(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 266);
	// lhz r10,262(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 262);
	// lhz r9,258(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 258);
	// extsh r28,r11
	ctx.r28.s64 = ctx.r11.s16;
	// extsh r27,r10
	ctx.r27.s64 = ctx.r10.s16;
	// lhz r8,264(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 264);
	// extsh r26,r9
	ctx.r26.s64 = ctx.r9.s16;
	// lhz r7,260(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 260);
	// lhz r6,256(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 256);
	// extsh r25,r8
	ctx.r25.s64 = ctx.r8.s16;
	// lhz r5,362(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 362);
	// extsh r24,r7
	ctx.r24.s64 = ctx.r7.s16;
	// extsh r23,r6
	ctx.r23.s64 = ctx.r6.s16;
	// lhz r4,358(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 358);
	// subf r10,r26,r27
	ctx.r10.u64 = ctx.r27.u64 - ctx.r26.u64;
	// lhz r11,354(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 354);
	// subf r9,r28,r27
	ctx.r9.u64 = ctx.r27.u64 - ctx.r28.u64;
	// lhz r8,360(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 360);
	// extsh r18,r5
	ctx.r18.s64 = ctx.r5.s16;
	// lhz r6,356(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 356);
	// subf r7,r26,r28
	ctx.r7.u64 = ctx.r28.u64 - ctx.r26.u64;
	// lhz r21,352(r1)
	ctx.r21.u64 = PPC_LOAD_U16(ctx.r1.u32 + 352);
	// xor r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// extsh r17,r4
	ctx.r17.s64 = ctx.r4.s16;
	// subf r20,r23,r24
	ctx.r20.u64 = ctx.r24.u64 - ctx.r23.u64;
	// subf r19,r25,r24
	ctx.r19.u64 = ctx.r24.u64 - ctx.r25.u64;
	// subf r4,r23,r25
	ctx.r4.u64 = ctx.r25.u64 - ctx.r23.u64;
	// extsh r16,r11
	ctx.r16.s64 = ctx.r11.s16;
	// xor r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// xor r9,r19,r20
	ctx.r9.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r5,r4,r20
	ctx.r5.u64 = ctx.r4.u64 ^ ctx.r20.u64;
	// extsh r14,r6
	ctx.r14.s64 = ctx.r6.s16;
	// extsh r15,r8
	ctx.r15.s64 = ctx.r8.s16;
	// extsh r21,r21
	ctx.r21.s64 = ctx.r21.s16;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 31;
	// subf r20,r21,r14
	ctx.r20.u64 = ctx.r14.u64 - ctx.r21.u64;
	// subf r19,r15,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r15.u64;
	// subf r5,r21,r15
	ctx.r5.u64 = ctx.r15.u64 - ctx.r21.u64;
	// xor r19,r19,r20
	ctx.r19.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r20,r5,r20
	ctx.r20.u64 = ctx.r5.u64 ^ ctx.r20.u64;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// subf r7,r16,r17
	ctx.r7.u64 = ctx.r17.u64 - ctx.r16.u64;
	// stw r5,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// subf r6,r18,r17
	ctx.r6.u64 = ctx.r17.u64 - ctx.r18.u64;
	// subf r4,r16,r18
	ctx.r4.u64 = ctx.r18.u64 - ctx.r16.u64;
	// xor r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// xor r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// srawi r7,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 31;
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// and r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 & ctx.r26.u64;
	// stw r6,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// srawi r6,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r4.s32 >> 31;
	// srawi r5,r19,31
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r19.s32 >> 31;
	// srawi r4,r20,31
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r20.s32 >> 31;
	// lwz r20,120(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// andc r28,r28,r20
	ctx.r28.u64 = ctx.r28.u64 & ~ctx.r20.u64;
	// lwz r26,112(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// and r8,r8,r23
	ctx.r8.u64 = ctx.r8.u64 & ctx.r23.u64;
	// or r10,r28,r10
	ctx.r10.u64 = ctx.r28.u64 | ctx.r10.u64;
	// andc r26,r25,r26
	ctx.r26.u64 = ctx.r25.u64 & ~ctx.r26.u64;
	// or r25,r7,r6
	ctx.r25.u64 = ctx.r7.u64 | ctx.r6.u64;
	// and r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 & ctx.r27.u64;
	// or r23,r5,r4
	ctx.r23.u64 = ctx.r5.u64 | ctx.r4.u64;
	// or r8,r26,r8
	ctx.r8.u64 = ctx.r26.u64 | ctx.r8.u64;
	// and r9,r9,r24
	ctx.r9.u64 = ctx.r9.u64 & ctx.r24.u64;
	// and r6,r6,r16
	ctx.r6.u64 = ctx.r6.u64 & ctx.r16.u64;
	// andc r28,r18,r25
	ctx.r28.u64 = ctx.r18.u64 & ~ctx.r25.u64;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 | ctx.r9.u64;
	// and r4,r4,r21
	ctx.r4.u64 = ctx.r4.u64 & ctx.r21.u64;
	// andc r27,r15,r23
	ctx.r27.u64 = ctx.r15.u64 & ~ctx.r23.u64;
	// or r9,r28,r6
	ctx.r9.u64 = ctx.r28.u64 | ctx.r6.u64;
	// and r8,r7,r17
	ctx.r8.u64 = ctx.r7.u64 & ctx.r17.u64;
	// and r6,r5,r14
	ctx.r6.u64 = ctx.r5.u64 & ctx.r14.u64;
	// or r7,r27,r4
	ctx.r7.u64 = ctx.r27.u64 | ctx.r4.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// or r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// lwz r15,104(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r14,108(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r21,96(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// sth r5,522(r1)
	PPC_STORE_U16(ctx.r1.u32 + 522, ctx.r5.u16);
	// sth r4,520(r1)
	PPC_STORE_U16(ctx.r1.u32 + 520, ctx.r4.u16);
	// sth r11,526(r1)
	PPC_STORE_U16(ctx.r1.u32 + 526, ctx.r11.u16);
	// sth r10,524(r1)
	PPC_STORE_U16(ctx.r1.u32 + 524, ctx.r10.u16);
	// b 0x82b6e2bc
	goto loc_82B6E2BC;
loc_82B6E290:
	// bne cr6,0x82b6e2a8
	if (!ctx.cr6.eq) goto loc_82B6E2A8;
	// lwz r11,256(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 256);
	// lwz r10,352(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 352);
	// stw r11,520(r1)
	PPC_STORE_U32(ctx.r1.u32 + 520, ctx.r11.u32);
	// stw r10,524(r1)
	PPC_STORE_U32(ctx.r1.u32 + 524, ctx.r10.u32);
	// b 0x82b6e2bc
	goto loc_82B6E2BC;
loc_82B6E2A8:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// stw r19,520(r1)
	PPC_STORE_U32(ctx.r1.u32 + 520, ctx.r19.u32);
	// rlwinm r10,r11,17,0,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// subf r9,r10,r17
	ctx.r9.u64 = ctx.r17.u64 - ctx.r10.u64;
	// stw r9,524(r1)
	PPC_STORE_U32(ctx.r1.u32 + 524, ctx.r9.u32);
loc_82B6E2BC:
	// lwz r11,1396(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6e2d8
	if (ctx.cr6.eq) goto loc_82B6E2D8;
	// cmpw cr6,r22,r21
	ctx.cr6.compare<int32_t>(ctx.r22.s32, ctx.r21.s32, ctx.xer);
	// ble cr6,0x82b6e2e4
	if (!ctx.cr6.gt) goto loc_82B6E2E4;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82b6e2e8
	if (!ctx.cr6.eq) goto loc_82B6E2E8;
loc_82B6E2D8:
	// lwz r11,1400(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6e2e8
	if (ctx.cr6.eq) goto loc_82B6E2E8;
loc_82B6E2E4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82B6E2E8:
	// lwz r11,524(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 524);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82b6e2f8
	if (!ctx.cr6.eq) goto loc_82B6E2F8;
	// lwz r11,520(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 520);
loc_82B6E2F8:
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// lwz r9,1844(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// stw r11,152(r1)
	PPC_STORE_U32(ctx.r1.u32 + 152, ctx.r11.u32);
	// add r9,r30,r9
	ctx.r9.u64 = ctx.r30.u64 + ctx.r9.u64;
	// lhz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 100);
	// lhz r11,102(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 102);
	// sth r11,2(r9)
	PPC_STORE_U16(ctx.r9.u32 + 2, ctx.r11.u16);
	// lwz r8,1844(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// sthx r11,r30,r8
	PPC_STORE_U16(ctx.r30.u32 + ctx.r8.u32, ctx.r11.u16);
	// lwz r9,1844(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// add r7,r29,r9
	ctx.r7.u64 = ctx.r29.u64 + ctx.r9.u64;
	// sth r11,2(r7)
	PPC_STORE_U16(ctx.r7.u32 + 2, ctx.r11.u16);
	// lwz r6,1844(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// sthx r11,r29,r6
	PPC_STORE_U16(ctx.r29.u32 + ctx.r6.u32, ctx.r11.u16);
	// lwz r11,1848(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// add r5,r30,r11
	ctx.r5.u64 = ctx.r30.u64 + ctx.r11.u64;
	// sth r10,2(r5)
	PPC_STORE_U16(ctx.r5.u32 + 2, ctx.r10.u16);
	// lwz r4,1848(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// sthx r10,r30,r4
	PPC_STORE_U16(ctx.r30.u32 + ctx.r4.u32, ctx.r10.u16);
	// lwz r11,1848(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// add r3,r29,r11
	ctx.r3.u64 = ctx.r29.u64 + ctx.r11.u64;
	// sth r10,2(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2, ctx.r10.u16);
	// lwz r11,1848(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// sthx r10,r29,r11
	PPC_STORE_U16(ctx.r29.u32 + ctx.r11.u32, ctx.r10.u16);
	// b 0x82b70298
	goto loc_82B70298;
loc_82B6E35C:
	// rlwinm r11,r18,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r25,1840(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// clrlwi r20,r10,31
	ctx.r20.u64 = ctx.r10.u32 & 0x1;
	// lwz r24,1836(r31)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// add r28,r11,r16
	ctx.r28.u64 = ctx.r11.u64 + ctx.r16.u64;
	// stw r20,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r20.u32);
	// srawi r21,r17,1
	ctx.xer.ca = (ctx.r17.s32 < 0) & ((ctx.r17.u32 & 0x1) != 0);
	ctx.r21.s64 = ctx.r17.s32 >> 1;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// lwzx r23,r11,r16
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r16.u32);
	// lwz r11,4(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 4);
	// stw r23,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r23.u32);
	// stw r11,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r11.u32);
	// bne cr6,0x82b6e3bc
	if (!ctx.cr6.eq) goto loc_82B6E3BC;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82b6e3b0
	if (ctx.cr6.eq) goto loc_82B6E3B0;
	// srawi r11,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 1;
	// lwz r10,1304(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1304);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82b6e3bc
	if (ctx.cr6.eq) goto loc_82B6E3BC;
loc_82B6E3B0:
	// li r29,1
	ctx.r29.s64 = 1;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x82b6e3c4
	goto loc_82B6E3C4;
loc_82B6E3BC:
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
loc_82B6E3C4:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,-32078
	ctx.r10.s64 = -2102263808;
	// lis r9,-32078
	ctx.r9.s64 = -2102263808;
	// stw r30,296(r1)
	PPC_STORE_U32(ctx.r1.u32 + 296, ctx.r30.u32);
	// rlwinm r8,r11,17,0,14
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// stw r30,292(r1)
	PPC_STORE_U32(ctx.r1.u32 + 292, ctx.r30.u32);
	// lis r7,1
	ctx.r7.s64 = 65536;
	// stw r30,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, ctx.r30.u32);
	// srawi r22,r23,16
	ctx.xer.ca = (ctx.r23.s32 < 0) & ((ctx.r23.u32 & 0xFFFF) != 0);
	ctx.r22.s64 = ctx.r23.s32 >> 16;
	// stw r30,196(r1)
	PPC_STORE_U32(ctx.r1.u32 + 196, ctx.r30.u32);
	// addi r6,r10,12136
	ctx.r6.s64 = ctx.r10.s64 + 12136;
	// stw r30,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r30.u32);
	// addi r5,r9,12416
	ctx.r5.s64 = ctx.r9.s64 + 12416;
	// stw r22,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r22.u32);
	// subf r4,r8,r7
	ctx.r4.u64 = ctx.r7.u64 - ctx.r8.u64;
	// stw r6,1744(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1744, ctx.r6.u32);
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
	// stw r5,1748(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1748, ctx.r5.u32);
	// mr r26,r30
	ctx.r26.u64 = ctx.r30.u64;
	// stw r4,200(r1)
	PPC_STORE_U32(ctx.r1.u32 + 200, ctx.r4.u32);
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// beq cr6,0x82b6e490
	if (ctx.cr6.eq) goto loc_82B6E490;
	// addi r11,r18,-1
	ctx.r11.s64 = ctx.r18.s64 + -1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r24
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r24.u32);
	// lhzx r9,r11,r25
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r25.u32);
	// sth r10,142(r1)
	PPC_STORE_U16(ctx.r1.u32 + 142, ctx.r10.u16);
	// sth r9,140(r1)
	PPC_STORE_U16(ctx.r1.u32 + 140, ctx.r9.u16);
	// lwz r4,140(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b6e490
	if (ctx.cr6.eq) goto loc_82B6E490;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6e470
	if (ctx.cr6.eq) goto loc_82B6E470;
	// stw r4,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r4.u32);
	// rotlwi r11,r6,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6E464;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, ctx.r3.u32);
	// li r26,1
	ctx.r26.s64 = 1;
	// b 0x82b6e48c
	goto loc_82B6E48C;
loc_82B6E470:
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,288(r1)
	PPC_STORE_U32(ctx.r1.u32 + 288, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6E484;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,192(r1)
	PPC_STORE_U32(ctx.r1.u32 + 192, ctx.r3.u32);
	// li r27,1
	ctx.r27.s64 = 1;
loc_82B6E48C:
	// li r30,1
	ctx.r30.s64 = 1;
loc_82B6E490:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x82b6e5b4
	if (!ctx.cr6.eq) goto loc_82B6E5B4;
	// subf r29,r17,r18
	ctx.r29.u64 = ctx.r18.u64 - ctx.r17.u64;
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r24
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r24.u32);
	// lhzx r9,r11,r25
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r25.u32);
	// sth r10,142(r1)
	PPC_STORE_U16(ctx.r1.u32 + 142, ctx.r10.u16);
	// sth r9,140(r1)
	PPC_STORE_U16(ctx.r1.u32 + 140, ctx.r9.u16);
	// lwz r4,140(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b6e51c
	if (ctx.cr6.eq) goto loc_82B6E51C;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r15,r30,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6e4f4
	if (ctx.cr6.eq) goto loc_82B6E4F4;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r15,r10
	PPC_STORE_U32(ctx.r15.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6E4E8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// b 0x82b6e514
	goto loc_82B6E514;
loc_82B6E4F4:
	// addi r10,r1,288
	ctx.r10.s64 = ctx.r1.s64 + 288;
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r15,r10
	PPC_STORE_U32(ctx.r15.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6E50C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
loc_82B6E514:
	// stwx r3,r15,r9
	PPC_STORE_U32(ctx.r15.u32 + ctx.r9.u32, ctx.r3.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_82B6E51C:
	// cmpwi cr6,r21,1
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 1, ctx.xer);
	// ble cr6,0x82b6e5b4
	if (!ctx.cr6.gt) goto loc_82B6E5B4;
	// addi r11,r17,-2
	ctx.r11.s64 = ctx.r17.s64 + -2;
	// cmpw cr6,r19,r11
	ctx.cr6.compare<int32_t>(ctx.r19.s32, ctx.r11.s32, ctx.xer);
	// addi r11,r29,2
	ctx.r11.s64 = ctx.r29.s64 + 2;
	// bne cr6,0x82b6e538
	if (!ctx.cr6.eq) goto loc_82B6E538;
	// addi r11,r29,-2
	ctx.r11.s64 = ctx.r29.s64 + -2;
loc_82B6E538:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r24
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r24.u32);
	// lhzx r9,r11,r25
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r25.u32);
	// sth r10,142(r1)
	PPC_STORE_U16(ctx.r1.u32 + 142, ctx.r10.u16);
	// sth r9,140(r1)
	PPC_STORE_U16(ctx.r1.u32 + 140, ctx.r9.u16);
	// lwz r4,140(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 140);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b6e5b4
	if (ctx.cr6.eq) goto loc_82B6E5B4;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r30,r30,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6e590
	if (ctx.cr6.eq) goto loc_82B6E590;
	// addi r10,r1,192
	ctx.r10.s64 = ctx.r1.s64 + 192;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r30,r10
	PPC_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6E584;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,288
	ctx.r9.s64 = ctx.r1.s64 + 288;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// b 0x82b6e5b0
	goto loc_82B6E5B0;
loc_82B6E590:
	// addi r10,r1,288
	ctx.r10.s64 = ctx.r1.s64 + 288;
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r30,r10
	PPC_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6E5A8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,192
	ctx.r9.s64 = ctx.r1.s64 + 192;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
loc_82B6E5B0:
	// stwx r3,r30,r9
	PPC_STORE_U32(ctx.r30.u32 + ctx.r9.u32, ctx.r3.u32);
loc_82B6E5B4:
	// add r11,r26,r27
	ctx.r11.u64 = ctx.r26.u64 + ctx.r27.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x82b6e738
	if (!ctx.cr6.gt) goto loc_82B6E738;
	// lhz r11,298(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 298);
	// lhz r10,294(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 294);
	// lhz r9,290(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 290);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// extsh r29,r10
	ctx.r29.s64 = ctx.r10.s16;
	// lhz r8,296(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 296);
	// extsh r25,r9
	ctx.r25.s64 = ctx.r9.s16;
	// lhz r7,292(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 292);
	// lhz r6,288(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 288);
	// extsh r24,r8
	ctx.r24.s64 = ctx.r8.s16;
	// lhz r5,202(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 202);
	// extsh r23,r7
	ctx.r23.s64 = ctx.r7.s16;
	// extsh r22,r6
	ctx.r22.s64 = ctx.r6.s16;
	// lhz r4,198(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 198);
	// subf r10,r25,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r25.u64;
	// lhz r11,194(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 194);
	// subf r9,r30,r29
	ctx.r9.u64 = ctx.r29.u64 - ctx.r30.u64;
	// lhz r8,200(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 200);
	// extsh r18,r5
	ctx.r18.s64 = ctx.r5.s16;
	// lhz r6,196(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 196);
	// subf r7,r25,r30
	ctx.r7.u64 = ctx.r30.u64 - ctx.r25.u64;
	// lhz r21,192(r1)
	ctx.r21.u64 = PPC_LOAD_U16(ctx.r1.u32 + 192);
	// xor r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// extsh r17,r4
	ctx.r17.s64 = ctx.r4.s16;
	// subf r20,r22,r23
	ctx.r20.u64 = ctx.r23.u64 - ctx.r22.u64;
	// subf r19,r24,r23
	ctx.r19.u64 = ctx.r23.u64 - ctx.r24.u64;
	// subf r4,r22,r24
	ctx.r4.u64 = ctx.r24.u64 - ctx.r22.u64;
	// xor r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// extsh r16,r11
	ctx.r16.s64 = ctx.r11.s16;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// xor r9,r19,r20
	ctx.r9.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r5,r4,r20
	ctx.r5.u64 = ctx.r4.u64 ^ ctx.r20.u64;
	// extsh r15,r8
	ctx.r15.s64 = ctx.r8.s16;
	// extsh r14,r6
	ctx.r14.s64 = ctx.r6.s16;
	// extsh r21,r21
	ctx.r21.s64 = ctx.r21.s16;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 31;
	// subf r20,r21,r14
	ctx.r20.u64 = ctx.r14.u64 - ctx.r21.u64;
	// subf r19,r15,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r15.u64;
	// subf r5,r21,r15
	ctx.r5.u64 = ctx.r15.u64 - ctx.r21.u64;
	// xor r19,r19,r20
	ctx.r19.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r20,r5,r20
	ctx.r20.u64 = ctx.r5.u64 ^ ctx.r20.u64;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// subf r7,r16,r17
	ctx.r7.u64 = ctx.r17.u64 - ctx.r16.u64;
	// stw r5,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// subf r6,r18,r17
	ctx.r6.u64 = ctx.r17.u64 - ctx.r18.u64;
	// subf r4,r16,r18
	ctx.r4.u64 = ctx.r18.u64 - ctx.r16.u64;
	// xor r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// xor r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// srawi r7,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 31;
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// and r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 & ctx.r25.u64;
	// stw r6,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// srawi r6,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r4.s32 >> 31;
	// srawi r5,r19,31
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r19.s32 >> 31;
	// srawi r4,r20,31
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r20.s32 >> 31;
	// lwz r20,120(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// andc r30,r30,r20
	ctx.r30.u64 = ctx.r30.u64 & ~ctx.r20.u64;
	// lwz r25,112(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// and r8,r8,r22
	ctx.r8.u64 = ctx.r8.u64 & ctx.r22.u64;
	// or r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 | ctx.r10.u64;
	// andc r25,r24,r25
	ctx.r25.u64 = ctx.r24.u64 & ~ctx.r25.u64;
	// or r24,r7,r6
	ctx.r24.u64 = ctx.r7.u64 | ctx.r6.u64;
	// and r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 & ctx.r29.u64;
	// or r22,r5,r4
	ctx.r22.u64 = ctx.r5.u64 | ctx.r4.u64;
	// or r8,r25,r8
	ctx.r8.u64 = ctx.r25.u64 | ctx.r8.u64;
	// and r9,r9,r23
	ctx.r9.u64 = ctx.r9.u64 & ctx.r23.u64;
	// and r7,r7,r17
	ctx.r7.u64 = ctx.r7.u64 & ctx.r17.u64;
	// andc r30,r18,r24
	ctx.r30.u64 = ctx.r18.u64 & ~ctx.r24.u64;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 | ctx.r9.u64;
	// and r4,r4,r21
	ctx.r4.u64 = ctx.r4.u64 & ctx.r21.u64;
	// andc r29,r15,r22
	ctx.r29.u64 = ctx.r15.u64 & ~ctx.r22.u64;
	// or r9,r30,r7
	ctx.r9.u64 = ctx.r30.u64 | ctx.r7.u64;
	// and r8,r6,r16
	ctx.r8.u64 = ctx.r6.u64 & ctx.r16.u64;
	// and r6,r5,r14
	ctx.r6.u64 = ctx.r5.u64 & ctx.r14.u64;
	// or r7,r29,r4
	ctx.r7.u64 = ctx.r29.u64 | ctx.r4.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// or r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// lwz r23,96(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r22,108(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r20,104(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r16,100(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r18,160(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// lwz r17,164(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// sth r5,458(r1)
	PPC_STORE_U16(ctx.r1.u32 + 458, ctx.r5.u16);
	// sth r4,456(r1)
	PPC_STORE_U16(ctx.r1.u32 + 456, ctx.r4.u16);
	// sth r11,466(r1)
	PPC_STORE_U16(ctx.r1.u32 + 466, ctx.r11.u16);
	// sth r10,464(r1)
	PPC_STORE_U16(ctx.r1.u32 + 464, ctx.r10.u16);
	// b 0x82b6e768
	goto loc_82B6E768;
loc_82B6E738:
	// bne cr6,0x82b6e750
	if (!ctx.cr6.eq) goto loc_82B6E750;
	// lwz r11,288(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 288);
	// lwz r10,192(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 192);
	// stw r11,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r11.u32);
	// stw r10,464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 464, ctx.r10.u32);
	// b 0x82b6e768
	goto loc_82B6E768;
loc_82B6E750:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stw r3,456(r1)
	PPC_STORE_U32(ctx.r1.u32 + 456, ctx.r3.u32);
	// rlwinm r9,r11,17,0,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// subf r8,r9,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r9.u64;
	// stw r8,464(r1)
	PPC_STORE_U32(ctx.r1.u32 + 464, ctx.r8.u32);
loc_82B6E768:
	// lwz r11,1396(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6e784
	if (ctx.cr6.eq) goto loc_82B6E784;
	// cmpw cr6,r27,r26
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r26.s32, ctx.xer);
	// ble cr6,0x82b6e790
	if (!ctx.cr6.gt) goto loc_82B6E790;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82b6e794
	if (!ctx.cr6.eq) goto loc_82B6E794;
loc_82B6E784:
	// lwz r11,1400(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6e794
	if (ctx.cr6.eq) goto loc_82B6E794;
loc_82B6E790:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82B6E794:
	// clrlwi r11,r22,31
	ctx.r11.u64 = ctx.r22.u32 & 0x1;
	// xor r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r11.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r10,464(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 464);
	// bne cr6,0x82b6e7ac
	if (!ctx.cr6.eq) goto loc_82B6E7AC;
	// lwz r10,456(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 456);
loc_82B6E7AC:
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lhz r8,62(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 62);
	// lhz r7,66(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 66);
	// rlwinm r30,r18,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// stw r6,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r6.u32);
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// lhz r3,142(r1)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r1.u32 + 142);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// lhz r8,140(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 140);
	// add r7,r10,r23
	ctx.r7.u64 = ctx.r10.u64 + ctx.r23.u64;
	// add r11,r17,r18
	ctx.r11.u64 = ctx.r17.u64 + ctx.r18.u64;
	// and r6,r7,r5
	ctx.r6.u64 = ctx.r7.u64 & ctx.r5.u64;
	// rlwinm r29,r11,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r5,r4,r6
	ctx.r5.u64 = ctx.r6.u64 - ctx.r4.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// add r11,r11,r16
	ctx.r11.u64 = ctx.r11.u64 + ctx.r16.u64;
	// sth r4,2(r28)
	PPC_STORE_U16(ctx.r28.u32 + 2, ctx.r4.u16);
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// lwz r10,1836(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// add r3,r29,r10
	ctx.r3.u64 = ctx.r29.u64 + ctx.r10.u64;
	// sth r4,2(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2, ctx.r4.u16);
	// lwz r10,1836(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// add r10,r29,r10
	ctx.r10.u64 = ctx.r29.u64 + ctx.r10.u64;
	// lhz r9,2(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// extsh r8,r8
	ctx.r8.s64 = ctx.r8.s16;
	// sth r9,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r9.u16);
	// lwz r10,1836(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// add r7,r30,r10
	ctx.r7.u64 = ctx.r30.u64 + ctx.r10.u64;
	// lhzx r6,r29,r10
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r29.u32 + ctx.r10.u32);
	// sth r6,2(r7)
	PPC_STORE_U16(ctx.r7.u32 + 2, ctx.r6.u16);
	// lwz r10,1836(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// add r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 + ctx.r10.u64;
	// lhz r5,2(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// sth r5,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r5.u16);
	// lhz r3,68(r31)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r31.u32 + 68);
	// lwz r7,1836(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// lhz r4,64(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 64);
	// extsh r10,r4
	ctx.r10.s64 = ctx.r4.s16;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// extsh r9,r3
	ctx.r9.s64 = ctx.r3.s16;
	// add r5,r10,r22
	ctx.r5.u64 = ctx.r10.u64 + ctx.r22.u64;
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// lhzx r4,r30,r7
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r30.u32 + ctx.r7.u32);
	// and r3,r5,r9
	ctx.r3.u64 = ctx.r5.u64 & ctx.r9.u64;
	// extsh r14,r4
	ctx.r14.s64 = ctx.r4.s16;
	// subf r10,r6,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r6.u64;
	// stw r14,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r14.u32);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// sth r9,0(r28)
	PPC_STORE_U16(ctx.r28.u32 + 0, ctx.r9.u16);
	// lwz r10,1840(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// add r8,r10,r29
	ctx.r8.u64 = ctx.r10.u64 + ctx.r29.u64;
	// sth r9,2(r8)
	PPC_STORE_U16(ctx.r8.u32 + 2, ctx.r9.u16);
	// lwz r10,1840(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// add r10,r10,r29
	ctx.r10.u64 = ctx.r10.u64 + ctx.r29.u64;
	// lhz r7,2(r10)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// sth r7,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r7.u16);
	// lwz r10,1840(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// add r6,r30,r10
	ctx.r6.u64 = ctx.r30.u64 + ctx.r10.u64;
	// lhzx r5,r29,r10
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r29.u32 + ctx.r10.u32);
	// sth r5,2(r6)
	PPC_STORE_U16(ctx.r6.u32 + 2, ctx.r5.u16);
	// lwz r10,1840(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// add r10,r10,r30
	ctx.r10.u64 = ctx.r10.u64 + ctx.r30.u64;
	// lhz r4,2(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// sth r4,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r4.u16);
	// lwz r3,1840(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// lhzx r10,r3,r30
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + ctx.r30.u32);
	// extsh r15,r10
	ctx.r15.s64 = ctx.r10.s16;
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// stw r9,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r9.u32);
	// lwz r24,1844(r31)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// stw r15,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r15.u32);
	// lhz r27,50(r31)
	ctx.r27.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// lwz r25,1848(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// srawi r23,r27,1
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x1) != 0);
	ctx.r23.s64 = ctx.r27.s32 >> 1;
	// bne cr6,0x82b6e928
	if (!ctx.cr6.eq) goto loc_82B6E928;
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6e91c
	if (ctx.cr6.eq) goto loc_82B6E91C;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// lwz r10,1304(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1304);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82b6e928
	if (ctx.cr6.eq) goto loc_82B6E928;
loc_82B6E91C:
	// li r26,1
	ctx.r26.s64 = 1;
	// li r28,0
	ctx.r28.s64 = 0;
	// b 0x82b6e930
	goto loc_82B6E930;
loc_82B6E928:
	// li r28,0
	ctx.r28.s64 = 0;
	// mr r26,r28
	ctx.r26.u64 = ctx.r28.u64;
loc_82B6E930:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r9,172(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// mr r21,r28
	ctx.r21.u64 = ctx.r28.u64;
	// rlwinm r8,r11,17,0,14
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// lwz r7,1372(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1372);
	// srawi r19,r9,16
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFF) != 0);
	ctx.r19.s64 = ctx.r9.s32 >> 16;
	// stw r28,328(r1)
	PPC_STORE_U32(ctx.r1.u32 + 328, ctx.r28.u32);
	// subf r6,r8,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r8.u64;
	// stw r28,324(r1)
	PPC_STORE_U32(ctx.r1.u32 + 324, ctx.r28.u32);
	// stw r28,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, ctx.r28.u32);
	// mr r22,r28
	ctx.r22.u64 = ctx.r28.u64;
	// stw r28,212(r1)
	PPC_STORE_U32(ctx.r1.u32 + 212, ctx.r28.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// stw r28,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r28.u32);
	// stw r19,480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 480, ctx.r19.u32);
	// stw r6,216(r1)
	PPC_STORE_U32(ctx.r1.u32 + 216, ctx.r6.u32);
	// stw r21,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r21.u32);
	// bne cr6,0x82b6e990
	if (!ctx.cr6.eq) goto loc_82B6E990;
	// lis r11,-32078
	ctx.r11.s64 = -2102263808;
	// lis r10,-32078
	ctx.r10.s64 = -2102263808;
	// addi r9,r11,11448
	ctx.r9.s64 = ctx.r11.s64 + 11448;
	// addi r8,r10,11856
	ctx.r8.s64 = ctx.r10.s64 + 11856;
	// b 0x82b6e9a0
	goto loc_82B6E9A0;
loc_82B6E990:
	// lis r11,-32078
	ctx.r11.s64 = -2102263808;
	// lis r10,-32078
	ctx.r10.s64 = -2102263808;
	// addi r9,r11,11576
	ctx.r9.s64 = ctx.r11.s64 + 11576;
	// addi r8,r10,11512
	ctx.r8.s64 = ctx.r10.s64 + 11512;
loc_82B6E9A0:
	// lwz r11,116(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// stw r8,1748(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1748, ctx.r8.u32);
	// rlwinm r20,r11,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r9,1744(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1744, ctx.r9.u32);
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// beq cr6,0x82b6ea30
	if (ctx.cr6.eq) goto loc_82B6EA30;
	// addi r11,r18,-1
	ctx.r11.s64 = ctx.r18.s64 + -1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r24
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r24.u32);
	// lhzx r9,r11,r25
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r25.u32);
	// sth r10,138(r1)
	PPC_STORE_U16(ctx.r1.u32 + 138, ctx.r10.u16);
	// sth r9,136(r1)
	PPC_STORE_U16(ctx.r1.u32 + 136, ctx.r9.u16);
	// lwz r4,136(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b6ea30
	if (ctx.cr6.eq) goto loc_82B6EA30;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6ea10
	if (ctx.cr6.eq) goto loc_82B6EA10;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6EA00;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r21,1
	ctx.r21.s64 = 1;
	// stw r3,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, ctx.r3.u32);
	// stw r21,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r21.u32);
	// b 0x82b6ea2c
	goto loc_82B6EA2C;
loc_82B6EA10:
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,320(r1)
	PPC_STORE_U32(ctx.r1.u32 + 320, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6EA24;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,208(r1)
	PPC_STORE_U32(ctx.r1.u32 + 208, ctx.r3.u32);
	// li r22,1
	ctx.r22.s64 = 1;
loc_82B6EA2C:
	// li r28,1
	ctx.r28.s64 = 1;
loc_82B6EA30:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// bne cr6,0x82b6eb5c
	if (!ctx.cr6.eq) goto loc_82B6EB5C;
	// subf r26,r27,r18
	ctx.r26.u64 = ctx.r18.u64 - ctx.r27.u64;
	// rlwinm r11,r26,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r24
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r24.u32);
	// lhzx r9,r11,r25
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r25.u32);
	// sth r10,138(r1)
	PPC_STORE_U16(ctx.r1.u32 + 138, ctx.r10.u16);
	// sth r9,136(r1)
	PPC_STORE_U16(ctx.r1.u32 + 136, ctx.r9.u16);
	// lwz r4,136(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b6eac0
	if (ctx.cr6.eq) goto loc_82B6EAC0;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r18,r28,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6ea98
	if (ctx.cr6.eq) goto loc_82B6EA98;
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r18,r10
	PPC_STORE_U32(ctx.r18.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6EA88;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// addi r9,r1,320
	ctx.r9.s64 = ctx.r1.s64 + 320;
	// stw r21,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r21.u32);
	// b 0x82b6eab8
	goto loc_82B6EAB8;
loc_82B6EA98:
	// addi r10,r1,320
	ctx.r10.s64 = ctx.r1.s64 + 320;
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r18,r10
	PPC_STORE_U32(ctx.r18.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6EAB0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
loc_82B6EAB8:
	// stwx r3,r18,r9
	PPC_STORE_U32(ctx.r18.u32 + ctx.r9.u32, ctx.r3.u32);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_82B6EAC0:
	// cmpwi cr6,r23,1
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 1, ctx.xer);
	// ble cr6,0x82b6eb5c
	if (!ctx.cr6.gt) goto loc_82B6EB5C;
	// addi r11,r27,-2
	ctx.r11.s64 = ctx.r27.s64 + -2;
	// cmpw cr6,r20,r11
	ctx.cr6.compare<int32_t>(ctx.r20.s32, ctx.r11.s32, ctx.xer);
	// addi r11,r26,2
	ctx.r11.s64 = ctx.r26.s64 + 2;
	// bne cr6,0x82b6eadc
	if (!ctx.cr6.eq) goto loc_82B6EADC;
	// addi r11,r26,-2
	ctx.r11.s64 = ctx.r26.s64 + -2;
loc_82B6EADC:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r24
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r24.u32);
	// lhzx r9,r11,r25
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r25.u32);
	// sth r10,138(r1)
	PPC_STORE_U16(ctx.r1.u32 + 138, ctx.r10.u16);
	// sth r9,136(r1)
	PPC_STORE_U16(ctx.r1.u32 + 136, ctx.r9.u16);
	// lwz r4,136(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b6eb5c
	if (ctx.cr6.eq) goto loc_82B6EB5C;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r28,r28,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6eb38
	if (ctx.cr6.eq) goto loc_82B6EB38;
	// addi r10,r1,208
	ctx.r10.s64 = ctx.r1.s64 + 208;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r28,r10
	PPC_STORE_U32(ctx.r28.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6EB28;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// addi r9,r1,320
	ctx.r9.s64 = ctx.r1.s64 + 320;
	// stw r21,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r21.u32);
	// b 0x82b6eb58
	goto loc_82B6EB58;
loc_82B6EB38:
	// addi r10,r1,320
	ctx.r10.s64 = ctx.r1.s64 + 320;
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r28,r10
	PPC_STORE_U32(ctx.r28.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6EB50;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,208
	ctx.r9.s64 = ctx.r1.s64 + 208;
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
loc_82B6EB58:
	// stwx r3,r28,r9
	PPC_STORE_U32(ctx.r28.u32 + ctx.r9.u32, ctx.r3.u32);
loc_82B6EB5C:
	// add r11,r21,r22
	ctx.r11.u64 = ctx.r21.u64 + ctx.r22.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x82b6ecd8
	if (!ctx.cr6.gt) goto loc_82B6ECD8;
	// lhz r11,330(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 330);
	// lhz r10,326(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 326);
	// lhz r9,322(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 322);
	// extsh r28,r11
	ctx.r28.s64 = ctx.r11.s16;
	// extsh r27,r10
	ctx.r27.s64 = ctx.r10.s16;
	// lhz r8,328(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 328);
	// extsh r26,r9
	ctx.r26.s64 = ctx.r9.s16;
	// lhz r7,324(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 324);
	// lhz r6,320(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 320);
	// extsh r25,r8
	ctx.r25.s64 = ctx.r8.s16;
	// lhz r5,218(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 218);
	// extsh r24,r7
	ctx.r24.s64 = ctx.r7.s16;
	// extsh r23,r6
	ctx.r23.s64 = ctx.r6.s16;
	// lhz r4,214(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 214);
	// subf r10,r26,r27
	ctx.r10.u64 = ctx.r27.u64 - ctx.r26.u64;
	// lhz r11,210(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 210);
	// subf r9,r28,r27
	ctx.r9.u64 = ctx.r27.u64 - ctx.r28.u64;
	// lhz r6,212(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 212);
	// extsh r18,r5
	ctx.r18.s64 = ctx.r5.s16;
	// lhz r8,216(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 216);
	// subf r7,r26,r28
	ctx.r7.u64 = ctx.r28.u64 - ctx.r26.u64;
	// lhz r21,208(r1)
	ctx.r21.u64 = PPC_LOAD_U16(ctx.r1.u32 + 208);
	// xor r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// extsh r17,r4
	ctx.r17.s64 = ctx.r4.s16;
	// subf r20,r23,r24
	ctx.r20.u64 = ctx.r24.u64 - ctx.r23.u64;
	// subf r19,r25,r24
	ctx.r19.u64 = ctx.r24.u64 - ctx.r25.u64;
	// extsh r16,r11
	ctx.r16.s64 = ctx.r11.s16;
	// subf r4,r23,r25
	ctx.r4.u64 = ctx.r25.u64 - ctx.r23.u64;
	// xor r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// extsh r14,r6
	ctx.r14.s64 = ctx.r6.s16;
	// xor r9,r19,r20
	ctx.r9.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r5,r4,r20
	ctx.r5.u64 = ctx.r4.u64 ^ ctx.r20.u64;
	// extsh r15,r8
	ctx.r15.s64 = ctx.r8.s16;
	// extsh r21,r21
	ctx.r21.s64 = ctx.r21.s16;
	// subf r7,r16,r17
	ctx.r7.u64 = ctx.r17.u64 - ctx.r16.u64;
	// subf r6,r18,r17
	ctx.r6.u64 = ctx.r17.u64 - ctx.r18.u64;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// subf r4,r16,r18
	ctx.r4.u64 = ctx.r18.u64 - ctx.r16.u64;
	// srawi r8,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 31;
	// xor r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// subf r20,r21,r14
	ctx.r20.u64 = ctx.r14.u64 - ctx.r21.u64;
	// subf r19,r15,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r15.u64;
	// subf r5,r21,r15
	ctx.r5.u64 = ctx.r15.u64 - ctx.r21.u64;
	// xor r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// srawi r7,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 31;
	// xor r19,r19,r20
	ctx.r19.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// xor r20,r5,r20
	ctx.r20.u64 = ctx.r5.u64 ^ ctx.r20.u64;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r6,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// srawi r6,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r4.s32 >> 31;
	// stw r5,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// srawi r5,r19,31
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r19.s32 >> 31;
	// srawi r4,r20,31
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r20.s32 >> 31;
	// and r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 & ctx.r26.u64;
	// and r8,r8,r23
	ctx.r8.u64 = ctx.r8.u64 & ctx.r23.u64;
	// and r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 & ctx.r27.u64;
	// or r23,r5,r4
	ctx.r23.u64 = ctx.r5.u64 | ctx.r4.u64;
	// and r9,r9,r24
	ctx.r9.u64 = ctx.r9.u64 & ctx.r24.u64;
	// and r4,r4,r21
	ctx.r4.u64 = ctx.r4.u64 & ctx.r21.u64;
	// andc r27,r15,r23
	ctx.r27.u64 = ctx.r15.u64 & ~ctx.r23.u64;
	// lwz r20,120(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r26,112(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// andc r28,r28,r20
	ctx.r28.u64 = ctx.r28.u64 & ~ctx.r20.u64;
	// andc r26,r25,r26
	ctx.r26.u64 = ctx.r25.u64 & ~ctx.r26.u64;
	// or r25,r7,r6
	ctx.r25.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r10,r28,r10
	ctx.r10.u64 = ctx.r28.u64 | ctx.r10.u64;
	// or r8,r26,r8
	ctx.r8.u64 = ctx.r26.u64 | ctx.r8.u64;
	// and r7,r7,r17
	ctx.r7.u64 = ctx.r7.u64 & ctx.r17.u64;
	// andc r28,r18,r25
	ctx.r28.u64 = ctx.r18.u64 & ~ctx.r25.u64;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 | ctx.r9.u64;
	// or r9,r28,r7
	ctx.r9.u64 = ctx.r28.u64 | ctx.r7.u64;
	// and r8,r6,r16
	ctx.r8.u64 = ctx.r6.u64 & ctx.r16.u64;
	// and r6,r5,r14
	ctx.r6.u64 = ctx.r5.u64 & ctx.r14.u64;
	// or r7,r27,r4
	ctx.r7.u64 = ctx.r27.u64 | ctx.r4.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// or r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// lwz r19,480(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 480);
	// lwz r14,108(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r15,104(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r21,96(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// sth r5,514(r1)
	PPC_STORE_U16(ctx.r1.u32 + 514, ctx.r5.u16);
	// sth r4,512(r1)
	PPC_STORE_U16(ctx.r1.u32 + 512, ctx.r4.u16);
	// sth r11,474(r1)
	PPC_STORE_U16(ctx.r1.u32 + 474, ctx.r11.u16);
	// sth r10,472(r1)
	PPC_STORE_U16(ctx.r1.u32 + 472, ctx.r10.u16);
	// b 0x82b6ed08
	goto loc_82B6ED08;
loc_82B6ECD8:
	// bne cr6,0x82b6ecf0
	if (!ctx.cr6.eq) goto loc_82B6ECF0;
	// lwz r11,320(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 320);
	// lwz r10,208(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 208);
	// stw r11,512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 512, ctx.r11.u32);
	// stw r10,472(r1)
	PPC_STORE_U32(ctx.r1.u32 + 472, ctx.r10.u32);
	// b 0x82b6ed08
	goto loc_82B6ED08;
loc_82B6ECF0:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stw r3,512(r1)
	PPC_STORE_U32(ctx.r1.u32 + 512, ctx.r3.u32);
	// rlwinm r9,r11,17,0,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// subf r8,r9,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r9.u64;
	// stw r8,472(r1)
	PPC_STORE_U32(ctx.r1.u32 + 472, ctx.r8.u32);
loc_82B6ED08:
	// lwz r11,1396(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6ed24
	if (ctx.cr6.eq) goto loc_82B6ED24;
	// cmpw cr6,r22,r21
	ctx.cr6.compare<int32_t>(ctx.r22.s32, ctx.r21.s32, ctx.xer);
	// ble cr6,0x82b6ed30
	if (!ctx.cr6.gt) goto loc_82B6ED30;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82b6ed34
	if (!ctx.cr6.eq) goto loc_82B6ED34;
loc_82B6ED24:
	// lwz r11,1400(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6ed34
	if (ctx.cr6.eq) goto loc_82B6ED34;
loc_82B6ED30:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82B6ED34:
	// clrlwi r11,r19,31
	ctx.r11.u64 = ctx.r19.u32 & 0x1;
	// xor r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r11.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r10,472(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 472);
	// bne cr6,0x82b6ed4c
	if (!ctx.cr6.eq) goto loc_82B6ED4C;
	// lwz r10,512(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 512);
loc_82B6ED4C:
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lhz r9,62(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 62);
	// lhz r8,66(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 66);
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r11,1844(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// extsh r10,r9
	ctx.r10.s64 = ctx.r9.s16;
	// lwz r6,172(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// stw r7,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r7.u32);
	// add r5,r29,r11
	ctx.r5.u64 = ctx.r29.u64 + ctx.r11.u64;
	// extsh r4,r8
	ctx.r4.s64 = ctx.r8.s16;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lhz r11,138(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 138);
	// lhz r9,136(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 136);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r8,r11,r6
	ctx.r8.u64 = ctx.r11.u64 + ctx.r6.u64;
	// and r7,r8,r4
	ctx.r7.u64 = ctx.r8.u64 & ctx.r4.u64;
	// subf r6,r3,r7
	ctx.r6.u64 = ctx.r7.u64 - ctx.r3.u64;
	// sth r6,2(r5)
	PPC_STORE_U16(ctx.r5.u32 + 2, ctx.r6.u16);
	// lwz r11,1844(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lhz r3,2(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// sth r3,0(r11)
	PPC_STORE_U16(ctx.r11.u32 + 0, ctx.r3.u16);
	// lwz r11,1844(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// add r10,r11,r30
	ctx.r10.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lhzx r8,r11,r29
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r29.u32);
	// sth r8,2(r10)
	PPC_STORE_U16(ctx.r10.u32 + 2, ctx.r8.u16);
	// lwz r11,1844(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lhz r7,2(r11)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// sth r7,0(r11)
	PPC_STORE_U16(ctx.r11.u32 + 0, ctx.r7.u16);
	// lhz r6,68(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 68);
	// lwz r10,1848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// lwz r3,1844(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// lhz r5,64(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 64);
	// extsh r11,r5
	ctx.r11.s64 = ctx.r5.s16;
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// add r11,r11,r19
	ctx.r11.u64 = ctx.r11.u64 + ctx.r19.u64;
	// add r7,r29,r10
	ctx.r7.u64 = ctx.r29.u64 + ctx.r10.u64;
	// and r8,r11,r4
	ctx.r8.u64 = ctx.r11.u64 & ctx.r4.u64;
	// subf r6,r5,r8
	ctx.r6.u64 = ctx.r8.u64 - ctx.r5.u64;
	// lhzx r5,r30,r3
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r30.u32 + ctx.r3.u32);
	// extsh r10,r5
	ctx.r10.s64 = ctx.r5.s16;
	// sth r6,2(r7)
	PPC_STORE_U16(ctx.r7.u32 + 2, ctx.r6.u16);
	// lwz r11,1848(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// add r11,r29,r11
	ctx.r11.u64 = ctx.r29.u64 + ctx.r11.u64;
	// lhz r3,2(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// sth r3,0(r11)
	PPC_STORE_U16(ctx.r11.u32 + 0, ctx.r3.u16);
	// lwz r11,1848(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// add r9,r11,r30
	ctx.r9.u64 = ctx.r11.u64 + ctx.r30.u64;
	// lhzx r8,r11,r29
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r29.u32);
	// sth r8,2(r9)
	PPC_STORE_U16(ctx.r9.u32 + 2, ctx.r8.u16);
	// lwz r11,1848(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// lhz r7,2(r11)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// sth r7,0(r11)
	PPC_STORE_U16(ctx.r11.u32 + 0, ctx.r7.u16);
	// lwz r6,1848(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// stw r10,608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 608, ctx.r10.u32);
	// lhzx r5,r30,r6
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r30.u32 + ctx.r6.u32);
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// stw r4,616(r1)
	PPC_STORE_U32(ctx.r1.u32 + 616, ctx.r4.u32);
	// b 0x82b70298
	goto loc_82B70298;
loc_82B6EE4C:
	// rlwinm r11,r18,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r25,1848(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// clrlwi r20,r10,31
	ctx.r20.u64 = ctx.r10.u32 & 0x1;
	// lwz r24,1844(r31)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// add r28,r11,r16
	ctx.r28.u64 = ctx.r11.u64 + ctx.r16.u64;
	// stw r20,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r20.u32);
	// srawi r21,r17,1
	ctx.xer.ca = (ctx.r17.s32 < 0) & ((ctx.r17.u32 & 0x1) != 0);
	ctx.r21.s64 = ctx.r17.s32 >> 1;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// lwzx r22,r11,r16
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r16.u32);
	// stw r22,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r22.u32);
	// bne cr6,0x82b6eea4
	if (!ctx.cr6.eq) goto loc_82B6EEA4;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82b6ee98
	if (ctx.cr6.eq) goto loc_82B6EE98;
	// srawi r11,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r10.s32 >> 1;
	// lwz r10,1304(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1304);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82b6eea4
	if (ctx.cr6.eq) goto loc_82B6EEA4;
loc_82B6EE98:
	// li r29,1
	ctx.r29.s64 = 1;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x82b6eeac
	goto loc_82B6EEAC;
loc_82B6EEA4:
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
loc_82B6EEAC:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r9,1372(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1372);
	// srawi r23,r22,16
	ctx.xer.ca = (ctx.r22.s32 < 0) & ((ctx.r22.u32 & 0xFFFF) != 0);
	ctx.r23.s64 = ctx.r22.s32 >> 16;
	// rlwinm r8,r11,17,0,14
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// stw r30,248(r1)
	PPC_STORE_U32(ctx.r1.u32 + 248, ctx.r30.u32);
	// stw r30,244(r1)
	PPC_STORE_U32(ctx.r1.u32 + 244, ctx.r30.u32);
	// mr r27,r30
	ctx.r27.u64 = ctx.r30.u64;
	// subf r7,r8,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r8.u64;
	// stw r30,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, ctx.r30.u32);
	// stw r30,276(r1)
	PPC_STORE_U32(ctx.r1.u32 + 276, ctx.r30.u32);
	// mr r26,r30
	ctx.r26.u64 = ctx.r30.u64;
	// stw r30,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r30.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// stw r23,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r23.u32);
	// stw r7,280(r1)
	PPC_STORE_U32(ctx.r1.u32 + 280, ctx.r7.u32);
	// bne cr6,0x82b6ef04
	if (!ctx.cr6.eq) goto loc_82B6EF04;
	// lis r11,-32078
	ctx.r11.s64 = -2102263808;
	// lis r10,-32078
	ctx.r10.s64 = -2102263808;
	// addi r9,r11,11448
	ctx.r9.s64 = ctx.r11.s64 + 11448;
	// addi r8,r10,11856
	ctx.r8.s64 = ctx.r10.s64 + 11856;
	// b 0x82b6ef14
	goto loc_82B6EF14;
loc_82B6EF04:
	// lis r11,-32078
	ctx.r11.s64 = -2102263808;
	// lis r10,-32078
	ctx.r10.s64 = -2102263808;
	// addi r9,r11,11576
	ctx.r9.s64 = ctx.r11.s64 + 11576;
	// addi r8,r10,11512
	ctx.r8.s64 = ctx.r10.s64 + 11512;
loc_82B6EF14:
	// stw r8,1748(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1748, ctx.r8.u32);
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// stw r9,1744(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1744, ctx.r9.u32);
	// beq cr6,0x82b6ef98
	if (ctx.cr6.eq) goto loc_82B6EF98;
	// addi r11,r18,-1
	ctx.r11.s64 = ctx.r18.s64 + -1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r24,r11
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r24.u32 + ctx.r11.u32);
	// lhzx r9,r25,r11
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// sth r10,134(r1)
	PPC_STORE_U16(ctx.r1.u32 + 134, ctx.r10.u16);
	// sth r9,132(r1)
	PPC_STORE_U16(ctx.r1.u32 + 132, ctx.r9.u16);
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b6ef98
	if (ctx.cr6.eq) goto loc_82B6EF98;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6ef78
	if (ctx.cr6.eq) goto loc_82B6EF78;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6EF6C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, ctx.r3.u32);
	// li r26,1
	ctx.r26.s64 = 1;
	// b 0x82b6ef94
	goto loc_82B6EF94;
loc_82B6EF78:
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,240(r1)
	PPC_STORE_U32(ctx.r1.u32 + 240, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6EF8C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,272(r1)
	PPC_STORE_U32(ctx.r1.u32 + 272, ctx.r3.u32);
	// li r27,1
	ctx.r27.s64 = 1;
loc_82B6EF94:
	// li r30,1
	ctx.r30.s64 = 1;
loc_82B6EF98:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x82b6f0bc
	if (!ctx.cr6.eq) goto loc_82B6F0BC;
	// subf r29,r17,r18
	ctx.r29.u64 = ctx.r18.u64 - ctx.r17.u64;
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r24,r11
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r24.u32 + ctx.r11.u32);
	// lhzx r9,r25,r11
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// sth r10,134(r1)
	PPC_STORE_U16(ctx.r1.u32 + 134, ctx.r10.u16);
	// sth r9,132(r1)
	PPC_STORE_U16(ctx.r1.u32 + 132, ctx.r9.u16);
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b6f024
	if (ctx.cr6.eq) goto loc_82B6F024;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r15,r30,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6effc
	if (ctx.cr6.eq) goto loc_82B6EFFC;
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r15,r10
	PPC_STORE_U32(ctx.r15.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6EFF0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// b 0x82b6f01c
	goto loc_82B6F01C;
loc_82B6EFFC:
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r15,r10
	PPC_STORE_U32(ctx.r15.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6F014;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
loc_82B6F01C:
	// stwx r3,r15,r9
	PPC_STORE_U32(ctx.r15.u32 + ctx.r9.u32, ctx.r3.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_82B6F024:
	// cmpwi cr6,r21,1
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 1, ctx.xer);
	// ble cr6,0x82b6f0bc
	if (!ctx.cr6.gt) goto loc_82B6F0BC;
	// addi r11,r17,-2
	ctx.r11.s64 = ctx.r17.s64 + -2;
	// cmpw cr6,r19,r11
	ctx.cr6.compare<int32_t>(ctx.r19.s32, ctx.r11.s32, ctx.xer);
	// addi r11,r29,2
	ctx.r11.s64 = ctx.r29.s64 + 2;
	// bne cr6,0x82b6f040
	if (!ctx.cr6.eq) goto loc_82B6F040;
	// addi r11,r29,-2
	ctx.r11.s64 = ctx.r29.s64 + -2;
loc_82B6F040:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r24,r11
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r24.u32 + ctx.r11.u32);
	// lhzx r9,r25,r11
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r25.u32 + ctx.r11.u32);
	// sth r10,134(r1)
	PPC_STORE_U16(ctx.r1.u32 + 134, ctx.r10.u16);
	// sth r9,132(r1)
	PPC_STORE_U16(ctx.r1.u32 + 132, ctx.r9.u16);
	// lwz r4,132(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b6f0bc
	if (ctx.cr6.eq) goto loc_82B6F0BC;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r30,r30,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6f098
	if (ctx.cr6.eq) goto loc_82B6F098;
	// addi r10,r1,272
	ctx.r10.s64 = ctx.r1.s64 + 272;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r30,r10
	PPC_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6F08C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,240
	ctx.r9.s64 = ctx.r1.s64 + 240;
	// addi r26,r26,1
	ctx.r26.s64 = ctx.r26.s64 + 1;
	// b 0x82b6f0b8
	goto loc_82B6F0B8;
loc_82B6F098:
	// addi r10,r1,240
	ctx.r10.s64 = ctx.r1.s64 + 240;
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r30,r10
	PPC_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6F0B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,272
	ctx.r9.s64 = ctx.r1.s64 + 272;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
loc_82B6F0B8:
	// stwx r3,r30,r9
	PPC_STORE_U32(ctx.r30.u32 + ctx.r9.u32, ctx.r3.u32);
loc_82B6F0BC:
	// add r11,r26,r27
	ctx.r11.u64 = ctx.r26.u64 + ctx.r27.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x82b6f240
	if (!ctx.cr6.gt) goto loc_82B6F240;
	// lhz r11,250(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 250);
	// lhz r10,246(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 246);
	// lhz r9,242(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 242);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// extsh r29,r10
	ctx.r29.s64 = ctx.r10.s16;
	// lhz r8,248(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 248);
	// extsh r25,r9
	ctx.r25.s64 = ctx.r9.s16;
	// lhz r7,244(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 244);
	// lhz r6,240(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 240);
	// extsh r24,r8
	ctx.r24.s64 = ctx.r8.s16;
	// lhz r5,282(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 282);
	// extsh r23,r7
	ctx.r23.s64 = ctx.r7.s16;
	// extsh r22,r6
	ctx.r22.s64 = ctx.r6.s16;
	// lhz r4,278(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 278);
	// subf r10,r25,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r25.u64;
	// lhz r11,274(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 274);
	// subf r9,r30,r29
	ctx.r9.u64 = ctx.r29.u64 - ctx.r30.u64;
	// lhz r6,276(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 276);
	// extsh r18,r5
	ctx.r18.s64 = ctx.r5.s16;
	// lhz r8,280(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 280);
	// subf r7,r25,r30
	ctx.r7.u64 = ctx.r30.u64 - ctx.r25.u64;
	// lhz r21,272(r1)
	ctx.r21.u64 = PPC_LOAD_U16(ctx.r1.u32 + 272);
	// xor r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// extsh r17,r4
	ctx.r17.s64 = ctx.r4.s16;
	// subf r20,r22,r23
	ctx.r20.u64 = ctx.r23.u64 - ctx.r22.u64;
	// subf r19,r24,r23
	ctx.r19.u64 = ctx.r23.u64 - ctx.r24.u64;
	// extsh r16,r11
	ctx.r16.s64 = ctx.r11.s16;
	// subf r4,r22,r24
	ctx.r4.u64 = ctx.r24.u64 - ctx.r22.u64;
	// xor r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// extsh r14,r6
	ctx.r14.s64 = ctx.r6.s16;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// xor r9,r19,r20
	ctx.r9.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r5,r4,r20
	ctx.r5.u64 = ctx.r4.u64 ^ ctx.r20.u64;
	// extsh r15,r8
	ctx.r15.s64 = ctx.r8.s16;
	// extsh r21,r21
	ctx.r21.s64 = ctx.r21.s16;
	// subf r7,r16,r17
	ctx.r7.u64 = ctx.r17.u64 - ctx.r16.u64;
	// subf r6,r18,r17
	ctx.r6.u64 = ctx.r17.u64 - ctx.r18.u64;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// subf r4,r16,r18
	ctx.r4.u64 = ctx.r18.u64 - ctx.r16.u64;
	// srawi r8,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 31;
	// xor r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// subf r20,r21,r14
	ctx.r20.u64 = ctx.r14.u64 - ctx.r21.u64;
	// subf r19,r15,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r15.u64;
	// subf r5,r21,r15
	ctx.r5.u64 = ctx.r15.u64 - ctx.r21.u64;
	// xor r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// srawi r7,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 31;
	// xor r19,r19,r20
	ctx.r19.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// xor r20,r5,r20
	ctx.r20.u64 = ctx.r5.u64 ^ ctx.r20.u64;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r6,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// srawi r6,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r4.s32 >> 31;
	// stw r5,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// srawi r5,r19,31
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r19.s32 >> 31;
	// srawi r4,r20,31
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r20.s32 >> 31;
	// and r10,r10,r25
	ctx.r10.u64 = ctx.r10.u64 & ctx.r25.u64;
	// and r8,r8,r22
	ctx.r8.u64 = ctx.r8.u64 & ctx.r22.u64;
	// and r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 & ctx.r29.u64;
	// or r22,r5,r4
	ctx.r22.u64 = ctx.r5.u64 | ctx.r4.u64;
	// and r9,r9,r23
	ctx.r9.u64 = ctx.r9.u64 & ctx.r23.u64;
	// and r4,r4,r21
	ctx.r4.u64 = ctx.r4.u64 & ctx.r21.u64;
	// andc r29,r15,r22
	ctx.r29.u64 = ctx.r15.u64 & ~ctx.r22.u64;
	// lwz r20,120(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r25,112(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// andc r30,r30,r20
	ctx.r30.u64 = ctx.r30.u64 & ~ctx.r20.u64;
	// andc r25,r24,r25
	ctx.r25.u64 = ctx.r24.u64 & ~ctx.r25.u64;
	// or r24,r7,r6
	ctx.r24.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 | ctx.r10.u64;
	// or r8,r25,r8
	ctx.r8.u64 = ctx.r25.u64 | ctx.r8.u64;
	// and r6,r6,r16
	ctx.r6.u64 = ctx.r6.u64 & ctx.r16.u64;
	// andc r30,r18,r24
	ctx.r30.u64 = ctx.r18.u64 & ~ctx.r24.u64;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 | ctx.r9.u64;
	// or r9,r30,r6
	ctx.r9.u64 = ctx.r30.u64 | ctx.r6.u64;
	// and r8,r7,r17
	ctx.r8.u64 = ctx.r7.u64 & ctx.r17.u64;
	// and r6,r5,r14
	ctx.r6.u64 = ctx.r5.u64 & ctx.r14.u64;
	// or r7,r29,r4
	ctx.r7.u64 = ctx.r29.u64 | ctx.r4.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// or r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// lwz r23,108(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// lwz r20,104(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r22,96(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r16,100(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r18,160(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// lwz r17,164(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// sth r5,506(r1)
	PPC_STORE_U16(ctx.r1.u32 + 506, ctx.r5.u16);
	// sth r4,504(r1)
	PPC_STORE_U16(ctx.r1.u32 + 504, ctx.r4.u16);
	// sth r11,490(r1)
	PPC_STORE_U16(ctx.r1.u32 + 490, ctx.r11.u16);
	// sth r10,488(r1)
	PPC_STORE_U16(ctx.r1.u32 + 488, ctx.r10.u16);
	// b 0x82b6f270
	goto loc_82B6F270;
loc_82B6F240:
	// bne cr6,0x82b6f258
	if (!ctx.cr6.eq) goto loc_82B6F258;
	// lwz r11,240(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 240);
	// lwz r10,272(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 272);
	// stw r11,504(r1)
	PPC_STORE_U32(ctx.r1.u32 + 504, ctx.r11.u32);
	// stw r10,488(r1)
	PPC_STORE_U32(ctx.r1.u32 + 488, ctx.r10.u32);
	// b 0x82b6f270
	goto loc_82B6F270;
loc_82B6F258:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stw r3,504(r1)
	PPC_STORE_U32(ctx.r1.u32 + 504, ctx.r3.u32);
	// rlwinm r9,r11,17,0,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// subf r8,r9,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r9.u64;
	// stw r8,488(r1)
	PPC_STORE_U32(ctx.r1.u32 + 488, ctx.r8.u32);
loc_82B6F270:
	// lwz r11,1396(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6f28c
	if (ctx.cr6.eq) goto loc_82B6F28C;
	// cmpw cr6,r27,r26
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r26.s32, ctx.xer);
	// ble cr6,0x82b6f298
	if (!ctx.cr6.gt) goto loc_82B6F298;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82b6f29c
	if (!ctx.cr6.eq) goto loc_82B6F29C;
loc_82B6F28C:
	// lwz r11,1400(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6f29c
	if (ctx.cr6.eq) goto loc_82B6F29C;
loc_82B6F298:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82B6F29C:
	// clrlwi r11,r23,31
	ctx.r11.u64 = ctx.r23.u32 & 0x1;
	// lwz r9,488(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 488);
	// xor r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r11.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82b6f2b4
	if (!ctx.cr6.eq) goto loc_82B6F2B4;
	// lwz r9,504(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 504);
loc_82B6F2B4:
	// rlwinm r10,r11,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lhz r8,62(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 62);
	// lhz r7,66(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 66);
	// add r11,r17,r18
	ctx.r11.u64 = ctx.r17.u64 + ctx.r18.u64;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// stw r6,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r6.u32);
	// extsh r5,r7
	ctx.r5.s64 = ctx.r7.s16;
	// lhz r3,134(r1)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r1.u32 + 134);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// mr r4,r8
	ctx.r4.u64 = ctx.r8.u64;
	// lhz r8,132(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 132);
	// add r7,r10,r22
	ctx.r7.u64 = ctx.r10.u64 + ctx.r22.u64;
	// rlwinm r30,r11,1,0,30
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// and r6,r7,r5
	ctx.r6.u64 = ctx.r7.u64 & ctx.r5.u64;
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// subf r5,r4,r6
	ctx.r5.u64 = ctx.r6.u64 - ctx.r4.u64;
	// rlwinm r29,r18,1,0,30
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// sth r4,2(r28)
	PPC_STORE_U16(ctx.r28.u32 + 2, ctx.r4.u16);
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// lwz r10,1844(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// add r3,r30,r10
	ctx.r3.u64 = ctx.r30.u64 + ctx.r10.u64;
	// sth r4,2(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2, ctx.r4.u16);
	// add r11,r11,r16
	ctx.r11.u64 = ctx.r11.u64 + ctx.r16.u64;
	// lwz r10,1844(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// add r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 + ctx.r10.u64;
	// lhz r8,2(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// sth r8,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r8.u16);
	// lwz r10,1844(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// add r7,r10,r29
	ctx.r7.u64 = ctx.r10.u64 + ctx.r29.u64;
	// lhzx r6,r10,r30
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r30.u32);
	// sth r6,2(r7)
	PPC_STORE_U16(ctx.r7.u32 + 2, ctx.r6.u16);
	// lwz r10,1844(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// add r10,r29,r10
	ctx.r10.u64 = ctx.r29.u64 + ctx.r10.u64;
	// lhz r5,2(r10)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// sth r5,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r5.u16);
	// lhz r8,68(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 68);
	// lhz r3,64(r31)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r31.u32 + 64);
	// extsh r10,r3
	ctx.r10.s64 = ctx.r3.s16;
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r4,1844(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// add r5,r10,r23
	ctx.r5.u64 = ctx.r10.u64 + ctx.r23.u64;
	// mr r6,r3
	ctx.r6.u64 = ctx.r3.u64;
	// and r3,r5,r7
	ctx.r3.u64 = ctx.r5.u64 & ctx.r7.u64;
	// lhzx r8,r29,r4
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r29.u32 + ctx.r4.u32);
	// extsh r14,r8
	ctx.r14.s64 = ctx.r8.s16;
	// subf r10,r6,r3
	ctx.r10.u64 = ctx.r3.u64 - ctx.r6.u64;
	// stw r14,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r14.u32);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// sth r9,0(r28)
	PPC_STORE_U16(ctx.r28.u32 + 0, ctx.r9.u16);
	// lwz r10,1848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// add r7,r30,r10
	ctx.r7.u64 = ctx.r30.u64 + ctx.r10.u64;
	// sth r9,2(r7)
	PPC_STORE_U16(ctx.r7.u32 + 2, ctx.r9.u16);
	// lwz r10,1848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// add r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 + ctx.r10.u64;
	// lhz r6,2(r10)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// sth r6,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r6.u16);
	// lwz r10,1848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// add r5,r10,r29
	ctx.r5.u64 = ctx.r10.u64 + ctx.r29.u64;
	// lhzx r4,r10,r30
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r30.u32);
	// sth r4,2(r5)
	PPC_STORE_U16(ctx.r5.u32 + 2, ctx.r4.u16);
	// lwz r10,1848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// add r10,r29,r10
	ctx.r10.u64 = ctx.r29.u64 + ctx.r10.u64;
	// lhz r3,2(r10)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// sth r3,0(r10)
	PPC_STORE_U16(ctx.r10.u32 + 0, ctx.r3.u16);
	// lwz r10,1848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// lhzx r8,r29,r10
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r29.u32 + ctx.r10.u32);
	// extsh r15,r8
	ctx.r15.s64 = ctx.r8.s16;
	// lwz r9,0(r28)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// stw r9,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r9.u32);
	// stw r9,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r9.u32);
	// stw r9,4(r28)
	PPC_STORE_U32(ctx.r28.u32 + 4, ctx.r9.u32);
	// stw r15,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r15.u32);
	// lhz r27,50(r31)
	ctx.r27.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// lwz r26,1840(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// lwz r25,1836(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// srawi r23,r27,1
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x1) != 0);
	ctx.r23.s64 = ctx.r27.s32 >> 1;
	// bne cr6,0x82b6f430
	if (!ctx.cr6.eq) goto loc_82B6F430;
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6f424
	if (ctx.cr6.eq) goto loc_82B6F424;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// lwz r10,1304(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1304);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82b6f430
	if (ctx.cr6.eq) goto loc_82B6F430;
loc_82B6F424:
	// li r24,1
	ctx.r24.s64 = 1;
	// li r19,0
	ctx.r19.s64 = 0;
	// b 0x82b6f438
	goto loc_82B6F438;
loc_82B6F430:
	// li r19,0
	ctx.r19.s64 = 0;
	// mr r24,r19
	ctx.r24.u64 = ctx.r19.u64;
loc_82B6F438:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,-32078
	ctx.r10.s64 = -2102263808;
	// lwz r9,116(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lis r8,-32078
	ctx.r8.s64 = -2102263808;
	// rlwinm r7,r11,17,0,14
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// stw r19,312(r1)
	PPC_STORE_U32(ctx.r1.u32 + 312, ctx.r19.u32);
	// lis r17,1
	ctx.r17.s64 = 65536;
	// stw r19,308(r1)
	PPC_STORE_U32(ctx.r1.u32 + 308, ctx.r19.u32);
	// addi r6,r10,12136
	ctx.r6.s64 = ctx.r10.s64 + 12136;
	// stw r19,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, ctx.r19.u32);
	// addi r5,r8,12416
	ctx.r5.s64 = ctx.r8.s64 + 12416;
	// stw r19,340(r1)
	PPC_STORE_U32(ctx.r1.u32 + 340, ctx.r19.u32);
	// subf r4,r7,r17
	ctx.r4.u64 = ctx.r17.u64 - ctx.r7.u64;
	// stw r6,1744(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1744, ctx.r6.u32);
	// mr r21,r19
	ctx.r21.u64 = ctx.r19.u64;
	// stw r5,1748(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1748, ctx.r5.u32);
	// rlwinm r20,r9,1,0,30
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// stw r19,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r19.u32);
	// stw r4,344(r1)
	PPC_STORE_U32(ctx.r1.u32 + 344, ctx.r4.u32);
	// mr r22,r19
	ctx.r22.u64 = ctx.r19.u64;
	// stw r21,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r21.u32);
	// mr r28,r19
	ctx.r28.u64 = ctx.r19.u64;
	// cmpwi cr6,r20,0
	ctx.cr6.compare<int32_t>(ctx.r20.s32, 0, ctx.xer);
	// beq cr6,0x82b6f510
	if (ctx.cr6.eq) goto loc_82B6F510;
	// addi r11,r18,-1
	ctx.r11.s64 = ctx.r18.s64 + -1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r25
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r25.u32);
	// lhzx r9,r11,r26
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r26.u32);
	// sth r10,158(r1)
	PPC_STORE_U16(ctx.r1.u32 + 158, ctx.r10.u16);
	// sth r9,156(r1)
	PPC_STORE_U16(ctx.r1.u32 + 156, ctx.r9.u16);
	// lwz r4,156(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b6f510
	if (ctx.cr6.eq) goto loc_82B6F510;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6f4f0
	if (ctx.cr6.eq) goto loc_82B6F4F0;
	// stw r4,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r4.u32);
	// rotlwi r11,r6,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 0);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6F4E0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r21,1
	ctx.r21.s64 = 1;
	// stw r3,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, ctx.r3.u32);
	// stw r21,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r21.u32);
	// b 0x82b6f50c
	goto loc_82B6F50C;
loc_82B6F4F0:
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,304(r1)
	PPC_STORE_U32(ctx.r1.u32 + 304, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6F504;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,336(r1)
	PPC_STORE_U32(ctx.r1.u32 + 336, ctx.r3.u32);
	// li r22,1
	ctx.r22.s64 = 1;
loc_82B6F50C:
	// li r28,1
	ctx.r28.s64 = 1;
loc_82B6F510:
	// cmpwi cr6,r24,0
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 0, ctx.xer);
	// bne cr6,0x82b6f63c
	if (!ctx.cr6.eq) goto loc_82B6F63C;
	// subf r24,r27,r18
	ctx.r24.u64 = ctx.r18.u64 - ctx.r27.u64;
	// rlwinm r11,r24,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r25
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r25.u32);
	// lhzx r9,r11,r26
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r26.u32);
	// sth r10,158(r1)
	PPC_STORE_U16(ctx.r1.u32 + 158, ctx.r10.u16);
	// sth r9,156(r1)
	PPC_STORE_U16(ctx.r1.u32 + 156, ctx.r9.u16);
	// lwz r4,156(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b6f5a0
	if (ctx.cr6.eq) goto loc_82B6F5A0;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r18,r28,2,0,29
	ctx.r18.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6f578
	if (ctx.cr6.eq) goto loc_82B6F578;
	// addi r10,r1,336
	ctx.r10.s64 = ctx.r1.s64 + 336;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r18,r10
	PPC_STORE_U32(ctx.r18.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6F568;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// addi r9,r1,304
	ctx.r9.s64 = ctx.r1.s64 + 304;
	// stw r21,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r21.u32);
	// b 0x82b6f598
	goto loc_82B6F598;
loc_82B6F578:
	// addi r10,r1,304
	ctx.r10.s64 = ctx.r1.s64 + 304;
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r18,r10
	PPC_STORE_U32(ctx.r18.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6F590;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,336
	ctx.r9.s64 = ctx.r1.s64 + 336;
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
loc_82B6F598:
	// stwx r3,r18,r9
	PPC_STORE_U32(ctx.r18.u32 + ctx.r9.u32, ctx.r3.u32);
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_82B6F5A0:
	// cmpwi cr6,r23,1
	ctx.cr6.compare<int32_t>(ctx.r23.s32, 1, ctx.xer);
	// ble cr6,0x82b6f63c
	if (!ctx.cr6.gt) goto loc_82B6F63C;
	// addi r11,r27,-2
	ctx.r11.s64 = ctx.r27.s64 + -2;
	// cmpw cr6,r20,r11
	ctx.cr6.compare<int32_t>(ctx.r20.s32, ctx.r11.s32, ctx.xer);
	// addi r11,r24,2
	ctx.r11.s64 = ctx.r24.s64 + 2;
	// bne cr6,0x82b6f5bc
	if (!ctx.cr6.eq) goto loc_82B6F5BC;
	// addi r11,r24,-2
	ctx.r11.s64 = ctx.r24.s64 + -2;
loc_82B6F5BC:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r25
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r25.u32);
	// lhzx r9,r11,r26
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r26.u32);
	// sth r10,158(r1)
	PPC_STORE_U16(ctx.r1.u32 + 158, ctx.r10.u16);
	// sth r9,156(r1)
	PPC_STORE_U16(ctx.r1.u32 + 156, ctx.r9.u16);
	// lwz r4,156(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 156);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b6f63c
	if (ctx.cr6.eq) goto loc_82B6F63C;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r28,r28,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6f618
	if (ctx.cr6.eq) goto loc_82B6F618;
	// addi r10,r1,336
	ctx.r10.s64 = ctx.r1.s64 + 336;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r28,r10
	PPC_STORE_U32(ctx.r28.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6F608;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// addi r9,r1,304
	ctx.r9.s64 = ctx.r1.s64 + 304;
	// stw r21,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r21.u32);
	// b 0x82b6f638
	goto loc_82B6F638;
loc_82B6F618:
	// addi r10,r1,304
	ctx.r10.s64 = ctx.r1.s64 + 304;
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r28,r10
	PPC_STORE_U32(ctx.r28.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B6F630;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,336
	ctx.r9.s64 = ctx.r1.s64 + 336;
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
loc_82B6F638:
	// stwx r3,r28,r9
	PPC_STORE_U32(ctx.r28.u32 + ctx.r9.u32, ctx.r3.u32);
loc_82B6F63C:
	// add r11,r21,r22
	ctx.r11.u64 = ctx.r21.u64 + ctx.r22.u64;
	// mr r3,r19
	ctx.r3.u64 = ctx.r19.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x82b6f7b4
	if (!ctx.cr6.gt) goto loc_82B6F7B4;
	// lhz r11,314(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 314);
	// lhz r10,310(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 310);
	// lhz r9,306(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 306);
	// extsh r28,r11
	ctx.r28.s64 = ctx.r11.s16;
	// extsh r27,r10
	ctx.r27.s64 = ctx.r10.s16;
	// lhz r8,312(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 312);
	// extsh r26,r9
	ctx.r26.s64 = ctx.r9.s16;
	// lhz r7,308(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 308);
	// lhz r6,304(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 304);
	// extsh r25,r8
	ctx.r25.s64 = ctx.r8.s16;
	// lhz r5,346(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 346);
	// extsh r24,r7
	ctx.r24.s64 = ctx.r7.s16;
	// extsh r23,r6
	ctx.r23.s64 = ctx.r6.s16;
	// lhz r4,342(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 342);
	// subf r10,r26,r27
	ctx.r10.u64 = ctx.r27.u64 - ctx.r26.u64;
	// lhz r11,338(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 338);
	// subf r9,r28,r27
	ctx.r9.u64 = ctx.r27.u64 - ctx.r28.u64;
	// lhz r6,340(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 340);
	// extsh r18,r5
	ctx.r18.s64 = ctx.r5.s16;
	// lhz r8,344(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 344);
	// subf r7,r26,r28
	ctx.r7.u64 = ctx.r28.u64 - ctx.r26.u64;
	// lhz r21,336(r1)
	ctx.r21.u64 = PPC_LOAD_U16(ctx.r1.u32 + 336);
	// xor r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// extsh r17,r4
	ctx.r17.s64 = ctx.r4.s16;
	// subf r20,r23,r24
	ctx.r20.u64 = ctx.r24.u64 - ctx.r23.u64;
	// subf r19,r25,r24
	ctx.r19.u64 = ctx.r24.u64 - ctx.r25.u64;
	// extsh r16,r11
	ctx.r16.s64 = ctx.r11.s16;
	// subf r4,r23,r25
	ctx.r4.u64 = ctx.r25.u64 - ctx.r23.u64;
	// xor r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// extsh r14,r6
	ctx.r14.s64 = ctx.r6.s16;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// xor r9,r19,r20
	ctx.r9.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r5,r4,r20
	ctx.r5.u64 = ctx.r4.u64 ^ ctx.r20.u64;
	// extsh r15,r8
	ctx.r15.s64 = ctx.r8.s16;
	// extsh r21,r21
	ctx.r21.s64 = ctx.r21.s16;
	// subf r7,r16,r17
	ctx.r7.u64 = ctx.r17.u64 - ctx.r16.u64;
	// subf r6,r18,r17
	ctx.r6.u64 = ctx.r17.u64 - ctx.r18.u64;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// subf r4,r16,r18
	ctx.r4.u64 = ctx.r18.u64 - ctx.r16.u64;
	// srawi r8,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 31;
	// xor r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// subf r20,r21,r14
	ctx.r20.u64 = ctx.r14.u64 - ctx.r21.u64;
	// subf r19,r15,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r15.u64;
	// subf r5,r21,r15
	ctx.r5.u64 = ctx.r15.u64 - ctx.r21.u64;
	// xor r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// srawi r7,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 31;
	// xor r19,r19,r20
	ctx.r19.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// xor r20,r5,r20
	ctx.r20.u64 = ctx.r5.u64 ^ ctx.r20.u64;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r6,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r6.u32);
	// srawi r6,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r4.s32 >> 31;
	// stw r5,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r5.u32);
	// srawi r5,r19,31
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r19.s32 >> 31;
	// srawi r4,r20,31
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r20.s32 >> 31;
	// and r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 & ctx.r26.u64;
	// and r8,r8,r23
	ctx.r8.u64 = ctx.r8.u64 & ctx.r23.u64;
	// and r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 & ctx.r27.u64;
	// or r23,r5,r4
	ctx.r23.u64 = ctx.r5.u64 | ctx.r4.u64;
	// and r9,r9,r24
	ctx.r9.u64 = ctx.r9.u64 & ctx.r24.u64;
	// and r4,r4,r21
	ctx.r4.u64 = ctx.r4.u64 & ctx.r21.u64;
	// andc r27,r15,r23
	ctx.r27.u64 = ctx.r15.u64 & ~ctx.r23.u64;
	// lwz r20,120(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r26,112(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// andc r28,r28,r20
	ctx.r28.u64 = ctx.r28.u64 & ~ctx.r20.u64;
	// andc r26,r25,r26
	ctx.r26.u64 = ctx.r25.u64 & ~ctx.r26.u64;
	// or r25,r7,r6
	ctx.r25.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r10,r28,r10
	ctx.r10.u64 = ctx.r28.u64 | ctx.r10.u64;
	// or r8,r26,r8
	ctx.r8.u64 = ctx.r26.u64 | ctx.r8.u64;
	// and r6,r6,r16
	ctx.r6.u64 = ctx.r6.u64 & ctx.r16.u64;
	// andc r28,r18,r25
	ctx.r28.u64 = ctx.r18.u64 & ~ctx.r25.u64;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 | ctx.r9.u64;
	// or r9,r28,r6
	ctx.r9.u64 = ctx.r28.u64 | ctx.r6.u64;
	// and r8,r7,r17
	ctx.r8.u64 = ctx.r7.u64 & ctx.r17.u64;
	// and r6,r5,r14
	ctx.r6.u64 = ctx.r5.u64 & ctx.r14.u64;
	// or r7,r27,r4
	ctx.r7.u64 = ctx.r27.u64 | ctx.r4.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// or r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// lwz r21,96(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r15,104(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r14,108(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// sth r5,510(r1)
	PPC_STORE_U16(ctx.r1.u32 + 510, ctx.r5.u16);
	// sth r4,508(r1)
	PPC_STORE_U16(ctx.r1.u32 + 508, ctx.r4.u16);
	// sth r11,498(r1)
	PPC_STORE_U16(ctx.r1.u32 + 498, ctx.r11.u16);
	// sth r10,496(r1)
	PPC_STORE_U16(ctx.r1.u32 + 496, ctx.r10.u16);
	// b 0x82b6f7e0
	goto loc_82B6F7E0;
loc_82B6F7B4:
	// bne cr6,0x82b6f7cc
	if (!ctx.cr6.eq) goto loc_82B6F7CC;
	// lwz r11,304(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 304);
	// lwz r10,336(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 336);
	// stw r11,508(r1)
	PPC_STORE_U32(ctx.r1.u32 + 508, ctx.r11.u32);
	// stw r10,496(r1)
	PPC_STORE_U32(ctx.r1.u32 + 496, ctx.r10.u32);
	// b 0x82b6f7e0
	goto loc_82B6F7E0;
loc_82B6F7CC:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// stw r19,508(r1)
	PPC_STORE_U32(ctx.r1.u32 + 508, ctx.r19.u32);
	// rlwinm r10,r11,17,0,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// subf r9,r10,r17
	ctx.r9.u64 = ctx.r17.u64 - ctx.r10.u64;
	// stw r9,496(r1)
	PPC_STORE_U32(ctx.r1.u32 + 496, ctx.r9.u32);
loc_82B6F7E0:
	// lwz r11,1396(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6f7fc
	if (ctx.cr6.eq) goto loc_82B6F7FC;
	// cmpw cr6,r22,r21
	ctx.cr6.compare<int32_t>(ctx.r22.s32, ctx.r21.s32, ctx.xer);
	// ble cr6,0x82b6f808
	if (!ctx.cr6.gt) goto loc_82B6F808;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82b6f80c
	if (!ctx.cr6.eq) goto loc_82B6F80C;
loc_82B6F7FC:
	// lwz r11,1400(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b6f80c
	if (ctx.cr6.eq) goto loc_82B6F80C;
loc_82B6F808:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82B6F80C:
	// lwz r11,496(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 496);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82b6f81c
	if (!ctx.cr6.eq) goto loc_82B6F81C;
	// lwz r11,508(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 508);
loc_82B6F81C:
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// lwz r9,1836(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// stw r11,156(r1)
	PPC_STORE_U32(ctx.r1.u32 + 156, ctx.r11.u32);
	// add r9,r30,r9
	ctx.r9.u64 = ctx.r30.u64 + ctx.r9.u64;
	// lhz r11,102(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 102);
	// lhz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 100);
	// sth r11,2(r9)
	PPC_STORE_U16(ctx.r9.u32 + 2, ctx.r11.u16);
	// lwz r8,1836(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// sthx r11,r30,r8
	PPC_STORE_U16(ctx.r30.u32 + ctx.r8.u32, ctx.r11.u16);
	// lwz r9,1836(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// add r7,r29,r9
	ctx.r7.u64 = ctx.r29.u64 + ctx.r9.u64;
	// sth r11,2(r7)
	PPC_STORE_U16(ctx.r7.u32 + 2, ctx.r11.u16);
	// lwz r6,1836(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// sthx r11,r29,r6
	PPC_STORE_U16(ctx.r29.u32 + ctx.r6.u32, ctx.r11.u16);
	// lwz r11,1840(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// sth r10,2(r5)
	PPC_STORE_U16(ctx.r5.u32 + 2, ctx.r10.u16);
	// lwz r4,1840(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// sthx r10,r4,r30
	PPC_STORE_U16(ctx.r4.u32 + ctx.r30.u32, ctx.r10.u16);
	// lwz r11,1840(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// add r3,r11,r29
	ctx.r3.u64 = ctx.r11.u64 + ctx.r29.u64;
	// sth r10,2(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2, ctx.r10.u16);
	// lwz r11,1840(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// sthx r10,r11,r29
	PPC_STORE_U16(ctx.r11.u32 + ctx.r29.u32, ctx.r10.u16);
	// b 0x82b70298
	goto loc_82B70298;
loc_82B6F880:
	// lwz r28,1368(r31)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// bne cr6,0x82b6f894
	if (!ctx.cr6.eq) goto loc_82B6F894;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82b6f89c
	goto loc_82B6F89C;
loc_82B6F894:
	// lhz r11,52(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 52);
	// mullw r11,r11,r17
	ctx.r11.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r17.s32);
loc_82B6F89C:
	// lwz r10,1392(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1392);
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// beq cr6,0x82b6f8b4
	if (ctx.cr6.eq) goto loc_82B6F8B4;
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// li r27,0
	ctx.r27.s64 = 0;
	// bne cr6,0x82b6f8b8
	if (!ctx.cr6.eq) goto loc_82B6F8B8;
loc_82B6F8B4:
	// li r27,1
	ctx.r27.s64 = 1;
loc_82B6F8B8:
	// add r9,r11,r18
	ctx.r9.u64 = ctx.r11.u64 + ctx.r18.u64;
	// lwz r7,376(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 376);
	// li r11,0
	ctx.r11.s64 = 0;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,0
	ctx.r10.s64 = 0;
	// add r6,r8,r7
	ctx.r6.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lwzx r8,r8,r7
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r7.u32);
	// mr r5,r8
	ctx.r5.u64 = ctx.r8.u64;
	// srawi r8,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 16;
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// cmpwi cr6,r4,16384
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 16384, ctx.xer);
	// beq cr6,0x82b6ffe4
	if (ctx.cr6.eq) goto loc_82B6FFE4;
	// add r9,r17,r9
	ctx.r9.u64 = ctx.r17.u64 + ctx.r9.u64;
	// lwz r5,4(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 4);
	// rlwinm r6,r28,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r30,r8,31
	ctx.r30.u64 = ctx.r8.u32 & 0x1;
	// add r9,r9,r7
	ctx.r9.u64 = ctx.r9.u64 + ctx.r7.u64;
	// addi r29,r6,-1
	ctx.r29.s64 = ctx.r6.s64 + -1;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// srawi r7,r5,16
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFFFF) != 0);
	ctx.r7.s64 = ctx.r5.s32 >> 16;
	// extsh r5,r5
	ctx.r5.s64 = ctx.r5.s16;
	// lwz r3,4(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 4);
	// lwz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// mr r30,r3
	ctx.r30.u64 = ctx.r3.u64;
	// mr r6,r9
	ctx.r6.u64 = ctx.r9.u64;
	// srawi r9,r9,16
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 16;
	// extsh r6,r6
	ctx.r6.s64 = ctx.r6.s16;
	// srawi r3,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 16;
	// extsh r30,r30
	ctx.r30.s64 = ctx.r30.s16;
	// beq cr6,0x82b6f954
	if (ctx.cr6.eq) goto loc_82B6F954;
	// add r11,r29,r8
	ctx.r11.u64 = ctx.r29.u64 + ctx.r8.u64;
	// lwz r14,560(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 560);
	// lwz r15,528(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 528);
	// srawi r19,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r19.s64 = ctx.r11.s32 >> 1;
	// stw r4,544(r1)
	PPC_STORE_U32(ctx.r1.u32 + 544, ctx.r4.u32);
	// li r11,1
	ctx.r11.s64 = 1;
	// stw r19,576(r1)
	PPC_STORE_U32(ctx.r1.u32 + 576, ctx.r19.u32);
	// b 0x82b6f970
	goto loc_82B6F970;
loc_82B6F954:
	// mr r15,r4
	ctx.r15.u64 = ctx.r4.u64;
	// lwz r4,544(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 544);
	// srawi r14,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r14.s64 = ctx.r8.s32 >> 1;
	// lwz r19,576(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 576);
	// stw r15,528(r1)
	PPC_STORE_U32(ctx.r1.u32 + 528, ctx.r15.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r14,560(r1)
	PPC_STORE_U32(ctx.r1.u32 + 560, ctx.r14.u32);
loc_82B6F970:
	// clrlwi r8,r7,31
	ctx.r8.u64 = ctx.r7.u32 & 0x1;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82b6f9a8
	if (ctx.cr6.eq) goto loc_82B6F9A8;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r1,544
	ctx.r4.s64 = ctx.r1.s64 + 544;
	// add r7,r29,r7
	ctx.r7.u64 = ctx.r29.u64 + ctx.r7.u64;
	// addi r25,r1,576
	ctx.r25.s64 = ctx.r1.s64 + 576;
	// srawi r7,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwx r5,r8,r4
	PPC_STORE_U32(ctx.r8.u32 + ctx.r4.u32, ctx.r5.u32);
	// stwx r7,r8,r25
	PPC_STORE_U32(ctx.r8.u32 + ctx.r25.u32, ctx.r7.u32);
	// lwz r4,544(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 544);
	// lwz r19,576(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 576);
	// b 0x82b6f9cc
	goto loc_82B6F9CC;
loc_82B6F9A8:
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r26,r1,528
	ctx.r26.s64 = ctx.r1.s64 + 528;
	// addi r21,r1,560
	ctx.r21.s64 = ctx.r1.s64 + 560;
	// srawi r7,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r5,r8,r26
	PPC_STORE_U32(ctx.r8.u32 + ctx.r26.u32, ctx.r5.u32);
	// stwx r7,r8,r21
	PPC_STORE_U32(ctx.r8.u32 + ctx.r21.u32, ctx.r7.u32);
	// lwz r15,528(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 528);
	// lwz r14,560(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 560);
loc_82B6F9CC:
	// clrlwi r8,r9,31
	ctx.r8.u64 = ctx.r9.u32 & 0x1;
	// lwz r26,564(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 564);
	// lwz r20,568(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 568);
	// lwz r5,532(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 532);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// lwz r21,536(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 536);
	// lwz r24,548(r1)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 548);
	// lwz r23,584(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 584);
	// lwz r22,580(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 580);
	// lwz r25,552(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 552);
	// beq cr6,0x82b6fa34
	if (ctx.cr6.eq) goto loc_82B6FA34;
	// add r4,r29,r9
	ctx.r4.u64 = ctx.r29.u64 + ctx.r9.u64;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r7,r1,544
	ctx.r7.s64 = ctx.r1.s64 + 544;
	// addi r9,r1,576
	ctx.r9.s64 = ctx.r1.s64 + 576;
	// srawi r4,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwx r6,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r6.u32);
	// stwx r4,r8,r9
	PPC_STORE_U32(ctx.r8.u32 + ctx.r9.u32, ctx.r4.u32);
	// lwz r4,544(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 544);
	// lwz r25,552(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 552);
	// lwz r24,548(r1)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 548);
	// lwz r23,584(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 584);
	// lwz r22,580(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 580);
	// lwz r19,576(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 576);
	// b 0x82b6fa68
	goto loc_82B6FA68;
loc_82B6FA34:
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r5,r1,560
	ctx.r5.s64 = ctx.r1.s64 + 560;
	// addi r7,r1,528
	ctx.r7.s64 = ctx.r1.s64 + 528;
	// srawi r9,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r9,r8,r5
	PPC_STORE_U32(ctx.r8.u32 + ctx.r5.u32, ctx.r9.u32);
	// stwx r6,r8,r7
	PPC_STORE_U32(ctx.r8.u32 + ctx.r7.u32, ctx.r6.u32);
	// lwz r20,568(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 568);
	// lwz r21,536(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 536);
	// lwz r5,532(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 532);
	// lwz r15,528(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 528);
	// lwz r26,564(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 564);
	// lwz r14,560(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 560);
loc_82B6FA68:
	// clrlwi r9,r3,31
	ctx.r9.u64 = ctx.r3.u32 & 0x1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82b6fab0
	if (ctx.cr6.eq) goto loc_82B6FAB0;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,544
	ctx.r8.s64 = ctx.r1.s64 + 544;
	// add r7,r29,r3
	ctx.r7.u64 = ctx.r29.u64 + ctx.r3.u64;
	// addi r6,r1,576
	ctx.r6.s64 = ctx.r1.s64 + 576;
	// srawi r4,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 1;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// stwx r30,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r30.u32);
	// stwx r4,r9,r6
	PPC_STORE_U32(ctx.r9.u32 + ctx.r6.u32, ctx.r4.u32);
	// lwz r25,552(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 552);
	// lwz r24,548(r1)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 548);
	// lwz r4,544(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 544);
	// lwz r23,584(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 584);
	// lwz r22,580(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 580);
	// lwz r19,576(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 576);
	// b 0x82b6fae4
	goto loc_82B6FAE4;
loc_82B6FAB0:
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r1,528
	ctx.r8.s64 = ctx.r1.s64 + 528;
	// addi r7,r1,560
	ctx.r7.s64 = ctx.r1.s64 + 560;
	// srawi r6,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r3.s32 >> 1;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// stwx r30,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r30.u32);
	// stwx r6,r9,r7
	PPC_STORE_U32(ctx.r9.u32 + ctx.r7.u32, ctx.r6.u32);
	// lwz r5,532(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 532);
	// lwz r21,536(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 536);
	// lwz r15,528(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 528);
	// lwz r20,568(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 568);
	// lwz r26,564(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 564);
	// lwz r14,560(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 560);
loc_82B6FAE4:
	// cmpw cr6,r11,r10
	ctx.cr6.compare<int32_t>(ctx.r11.s32, ctx.r10.s32, ctx.xer);
	// ble cr6,0x82b6fd50
	if (!ctx.cr6.gt) goto loc_82B6FD50;
	// cmpwi cr6,r11,3
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 3, ctx.xer);
	// subf r11,r4,r24
	ctx.r11.u64 = ctx.r24.u64 - ctx.r4.u64;
	// bne cr6,0x82b6fb68
	if (!ctx.cr6.eq) goto loc_82B6FB68;
	// subf r10,r25,r24
	ctx.r10.u64 = ctx.r24.u64 - ctx.r25.u64;
	// subf r9,r4,r25
	ctx.r9.u64 = ctx.r25.u64 - ctx.r4.u64;
	// subf r8,r19,r22
	ctx.r8.u64 = ctx.r22.u64 - ctx.r19.u64;
	// subf r7,r23,r22
	ctx.r7.u64 = ctx.r22.u64 - ctx.r23.u64;
	// xor r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// subf r5,r19,r23
	ctx.r5.u64 = ctx.r23.u64 - ctx.r19.u64;
	// xor r3,r9,r11
	ctx.r3.u64 = ctx.r9.u64 ^ ctx.r11.u64;
	// xor r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// srawi r11,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 31;
	// xor r8,r5,r8
	ctx.r8.u64 = ctx.r5.u64 ^ ctx.r8.u64;
	// srawi r10,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 31;
	// or r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 | ctx.r10.u64;
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// and r5,r10,r4
	ctx.r5.u64 = ctx.r10.u64 & ctx.r4.u64;
	// andc r4,r25,r7
	ctx.r4.u64 = ctx.r25.u64 & ~ctx.r7.u64;
	// and r10,r8,r19
	ctx.r10.u64 = ctx.r8.u64 & ctx.r19.u64;
	// andc r3,r23,r6
	ctx.r3.u64 = ctx.r23.u64 & ~ctx.r6.u64;
	// or r8,r4,r5
	ctx.r8.u64 = ctx.r4.u64 | ctx.r5.u64;
	// or r6,r3,r10
	ctx.r6.u64 = ctx.r3.u64 | ctx.r10.u64;
	// and r5,r9,r22
	ctx.r5.u64 = ctx.r9.u64 & ctx.r22.u64;
	// and r7,r11,r24
	ctx.r7.u64 = ctx.r11.u64 & ctx.r24.u64;
	// or r10,r6,r5
	ctx.r10.u64 = ctx.r6.u64 | ctx.r5.u64;
	// or r11,r8,r7
	ctx.r11.u64 = ctx.r8.u64 | ctx.r7.u64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r8,r29,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r29.u64;
	// b 0x82b6ffec
	goto loc_82B6FFEC;
loc_82B6FB68:
	// subf r10,r24,r25
	ctx.r10.u64 = ctx.r25.u64 - ctx.r24.u64;
	// subf r9,r25,r4
	ctx.r9.u64 = ctx.r4.u64 - ctx.r25.u64;
	// srawi r11,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 31;
	// subf r8,r24,r4
	ctx.r8.u64 = ctx.r4.u64 - ctx.r24.u64;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// subf r7,r25,r24
	ctx.r7.u64 = ctx.r24.u64 - ctx.r25.u64;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// subf r6,r4,r25
	ctx.r6.u64 = ctx.r25.u64 - ctx.r4.u64;
	// srawi r8,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 31;
	// srawi r7,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 31;
	// srawi r6,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 31;
	// not r3,r8
	ctx.r3.u64 = ~ctx.r8.u64;
	// not r5,r11
	ctx.r5.u64 = ~ctx.r11.u64;
	// not r8,r7
	ctx.r8.u64 = ~ctx.r7.u64;
	// not r7,r6
	ctx.r7.u64 = ~ctx.r6.u64;
	// and r30,r4,r5
	ctx.r30.u64 = ctx.r4.u64 & ctx.r5.u64;
	// and r26,r24,r3
	ctx.r26.u64 = ctx.r24.u64 & ctx.r3.u64;
	// not r6,r10
	ctx.r6.u64 = ~ctx.r10.u64;
	// and r21,r24,r8
	ctx.r21.u64 = ctx.r24.u64 & ctx.r8.u64;
	// and r20,r25,r7
	ctx.r20.u64 = ctx.r25.u64 & ctx.r7.u64;
	// and r7,r30,r7
	ctx.r7.u64 = ctx.r30.u64 & ctx.r7.u64;
	// and r30,r26,r6
	ctx.r30.u64 = ctx.r26.u64 & ctx.r6.u64;
	// not r15,r9
	ctx.r15.u64 = ~ctx.r9.u64;
	// lwz r9,556(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 556);
	// and r8,r25,r8
	ctx.r8.u64 = ctx.r25.u64 & ctx.r8.u64;
	// and r3,r4,r3
	ctx.r3.u64 = ctx.r4.u64 & ctx.r3.u64;
	// and r5,r21,r5
	ctx.r5.u64 = ctx.r21.u64 & ctx.r5.u64;
	// and r26,r20,r6
	ctx.r26.u64 = ctx.r20.u64 & ctx.r6.u64;
	// or r7,r7,r30
	ctx.r7.u64 = ctx.r7.u64 | ctx.r30.u64;
	// and r8,r8,r15
	ctx.r8.u64 = ctx.r8.u64 & ctx.r15.u64;
	// or r5,r5,r26
	ctx.r5.u64 = ctx.r5.u64 | ctx.r26.u64;
	// and r3,r3,r15
	ctx.r3.u64 = ctx.r3.u64 & ctx.r15.u64;
	// or r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 | ctx.r8.u64;
	// or r7,r5,r3
	ctx.r7.u64 = ctx.r5.u64 | ctx.r3.u64;
	// subf r5,r8,r9
	ctx.r5.u64 = ctx.r9.u64 - ctx.r8.u64;
	// subf r3,r9,r7
	ctx.r3.u64 = ctx.r7.u64 - ctx.r9.u64;
	// subf r26,r7,r8
	ctx.r26.u64 = ctx.r8.u64 - ctx.r7.u64;
	// xor r6,r11,r6
	ctx.r6.u64 = ctx.r11.u64 ^ ctx.r6.u64;
	// xor r30,r11,r15
	ctx.r30.u64 = ctx.r11.u64 ^ ctx.r15.u64;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// srawi r5,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r3.s32 >> 31;
	// srawi r3,r26,31
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r26.s32 >> 31;
	// eqv r5,r5,r11
	ctx.r5.u64 = ~(ctx.r5.u64 ^ ctx.r11.u64);
	// eqv r3,r3,r11
	ctx.r3.u64 = ~(ctx.r3.u64 ^ ctx.r11.u64);
	// xor r11,r10,r15
	ctx.r11.u64 = ctx.r10.u64 ^ ctx.r15.u64;
	// or r10,r5,r3
	ctx.r10.u64 = ctx.r5.u64 | ctx.r3.u64;
	// and r4,r30,r4
	ctx.r4.u64 = ctx.r30.u64 & ctx.r4.u64;
	// and r6,r6,r24
	ctx.r6.u64 = ctx.r6.u64 & ctx.r24.u64;
	// and r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 & ctx.r3.u64;
	// andc r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 & ~ctx.r10.u64;
	// and r7,r5,r9
	ctx.r7.u64 = ctx.r5.u64 & ctx.r9.u64;
	// or r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 | ctx.r4.u64;
	// or r4,r10,r8
	ctx.r4.u64 = ctx.r10.u64 | ctx.r8.u64;
	// and r5,r11,r25
	ctx.r5.u64 = ctx.r11.u64 & ctx.r25.u64;
	// or r10,r4,r7
	ctx.r10.u64 = ctx.r4.u64 | ctx.r7.u64;
	// or r11,r6,r5
	ctx.r11.u64 = ctx.r6.u64 | ctx.r5.u64;
	// subf r3,r19,r22
	ctx.r3.u64 = ctx.r22.u64 - ctx.r19.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r9,r22,r23
	ctx.r9.u64 = ctx.r23.u64 - ctx.r22.u64;
	// srawi r8,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 1;
	// subf r7,r23,r19
	ctx.r7.u64 = ctx.r19.u64 - ctx.r23.u64;
	// addze r11,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r10,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r7.s32 >> 31;
	// not r6,r9
	ctx.r6.u64 = ~ctx.r9.u64;
	// not r5,r8
	ctx.r5.u64 = ~ctx.r8.u64;
	// xor r4,r10,r6
	ctx.r4.u64 = ctx.r10.u64 ^ ctx.r6.u64;
	// xor r3,r10,r5
	ctx.r3.u64 = ctx.r10.u64 ^ ctx.r5.u64;
	// subf r8,r22,r19
	ctx.r8.u64 = ctx.r19.u64 - ctx.r22.u64;
	// subf r7,r23,r22
	ctx.r7.u64 = ctx.r22.u64 - ctx.r23.u64;
	// and r3,r3,r19
	ctx.r3.u64 = ctx.r3.u64 & ctx.r19.u64;
	// and r4,r4,r22
	ctx.r4.u64 = ctx.r4.u64 & ctx.r22.u64;
	// xor r30,r9,r5
	ctx.r30.u64 = ctx.r9.u64 ^ ctx.r5.u64;
	// subf r26,r19,r23
	ctx.r26.u64 = ctx.r23.u64 - ctx.r19.u64;
	// srawi r9,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r8.s32 >> 31;
	// srawi r8,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r7.s32 >> 31;
	// or r4,r4,r3
	ctx.r4.u64 = ctx.r4.u64 | ctx.r3.u64;
	// and r3,r30,r23
	ctx.r3.u64 = ctx.r30.u64 & ctx.r23.u64;
	// srawi r7,r26,31
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r26.s32 >> 31;
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// not r30,r9
	ctx.r30.u64 = ~ctx.r9.u64;
	// lwz r9,588(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 588);
	// not r7,r7
	ctx.r7.u64 = ~ctx.r7.u64;
	// and r26,r19,r10
	ctx.r26.u64 = ctx.r19.u64 & ctx.r10.u64;
	// and r25,r22,r30
	ctx.r25.u64 = ctx.r22.u64 & ctx.r30.u64;
	// not r8,r8
	ctx.r8.u64 = ~ctx.r8.u64;
	// and r24,r23,r7
	ctx.r24.u64 = ctx.r23.u64 & ctx.r7.u64;
	// and r7,r26,r7
	ctx.r7.u64 = ctx.r26.u64 & ctx.r7.u64;
	// and r30,r19,r30
	ctx.r30.u64 = ctx.r19.u64 & ctx.r30.u64;
	// and r26,r25,r6
	ctx.r26.u64 = ctx.r25.u64 & ctx.r6.u64;
	// and r25,r23,r8
	ctx.r25.u64 = ctx.r23.u64 & ctx.r8.u64;
	// and r30,r30,r5
	ctx.r30.u64 = ctx.r30.u64 & ctx.r5.u64;
	// and r6,r24,r6
	ctx.r6.u64 = ctx.r24.u64 & ctx.r6.u64;
	// and r8,r22,r8
	ctx.r8.u64 = ctx.r22.u64 & ctx.r8.u64;
	// and r5,r25,r5
	ctx.r5.u64 = ctx.r25.u64 & ctx.r5.u64;
	// or r7,r7,r26
	ctx.r7.u64 = ctx.r7.u64 | ctx.r26.u64;
	// and r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 & ctx.r10.u64;
	// or r6,r6,r30
	ctx.r6.u64 = ctx.r6.u64 | ctx.r30.u64;
	// or r8,r7,r5
	ctx.r8.u64 = ctx.r7.u64 | ctx.r5.u64;
	// or r7,r6,r10
	ctx.r7.u64 = ctx.r6.u64 | ctx.r10.u64;
	// subf r6,r8,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r8.u64;
	// subf r5,r9,r7
	ctx.r5.u64 = ctx.r7.u64 - ctx.r9.u64;
	// subf r30,r7,r8
	ctx.r30.u64 = ctx.r8.u64 - ctx.r7.u64;
	// srawi r10,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r6.s32 >> 31;
	// srawi r6,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r5.s32 >> 31;
	// srawi r5,r30,31
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r30.s32 >> 31;
	// eqv r6,r6,r10
	ctx.r6.u64 = ~(ctx.r6.u64 ^ ctx.r10.u64);
	// eqv r5,r5,r10
	ctx.r5.u64 = ~(ctx.r5.u64 ^ ctx.r10.u64);
	// and r10,r6,r9
	ctx.r10.u64 = ctx.r6.u64 & ctx.r9.u64;
	// or r9,r6,r5
	ctx.r9.u64 = ctx.r6.u64 | ctx.r5.u64;
	// and r8,r5,r8
	ctx.r8.u64 = ctx.r5.u64 & ctx.r8.u64;
	// andc r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 & ~ctx.r9.u64;
	// or r6,r4,r3
	ctx.r6.u64 = ctx.r4.u64 | ctx.r3.u64;
	// or r5,r7,r8
	ctx.r5.u64 = ctx.r7.u64 | ctx.r8.u64;
	// or r10,r5,r10
	ctx.r10.u64 = ctx.r5.u64 | ctx.r10.u64;
	// add r4,r10,r6
	ctx.r4.u64 = ctx.r10.u64 + ctx.r6.u64;
	// srawi r3,r4,1
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r4.s32 >> 1;
	// addze r10,r3
	temp.s64 = ctx.r3.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r3.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r8,r29,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r29.u64;
	// b 0x82b6ffec
	goto loc_82B6FFEC;
loc_82B6FD50:
	// li r29,0
	ctx.r29.s64 = 0;
	// cmpwi cr6,r10,2
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 2, ctx.xer);
	// bne cr6,0x82b6fd80
	if (!ctx.cr6.eq) goto loc_82B6FD80;
	// add r11,r5,r15
	ctx.r11.u64 = ctx.r5.u64 + ctx.r15.u64;
	// add r10,r26,r14
	ctx.r10.u64 = ctx.r26.u64 + ctx.r14.u64;
	// srawi r9,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 1;
	// addze r11,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r8,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 1;
	// addze r10,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r8,r29,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r29.u64;
	// b 0x82b6ffec
	goto loc_82B6FFEC;
loc_82B6FD80:
	// cmpwi cr6,r10,3
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 3, ctx.xer);
	// subf r11,r15,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r15.u64;
	// bne cr6,0x82b6fdfc
	if (!ctx.cr6.eq) goto loc_82B6FDFC;
	// subf r10,r21,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r21.u64;
	// subf r9,r15,r21
	ctx.r9.u64 = ctx.r21.u64 - ctx.r15.u64;
	// subf r8,r14,r26
	ctx.r8.u64 = ctx.r26.u64 - ctx.r14.u64;
	// subf r7,r20,r26
	ctx.r7.u64 = ctx.r26.u64 - ctx.r20.u64;
	// xor r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 ^ ctx.r11.u64;
	// subf r4,r14,r20
	ctx.r4.u64 = ctx.r20.u64 - ctx.r14.u64;
	// xor r3,r9,r11
	ctx.r3.u64 = ctx.r9.u64 ^ ctx.r11.u64;
	// xor r9,r7,r8
	ctx.r9.u64 = ctx.r7.u64 ^ ctx.r8.u64;
	// srawi r11,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 31;
	// xor r8,r4,r8
	ctx.r8.u64 = ctx.r4.u64 ^ ctx.r8.u64;
	// srawi r10,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 31;
	// or r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 | ctx.r8.u64;
	// and r5,r5,r11
	ctx.r5.u64 = ctx.r5.u64 & ctx.r11.u64;
	// andc r4,r21,r7
	ctx.r4.u64 = ctx.r21.u64 & ~ctx.r7.u64;
	// and r11,r26,r9
	ctx.r11.u64 = ctx.r26.u64 & ctx.r9.u64;
	// andc r3,r20,r6
	ctx.r3.u64 = ctx.r20.u64 & ~ctx.r6.u64;
	// and r10,r10,r15
	ctx.r10.u64 = ctx.r10.u64 & ctx.r15.u64;
	// or r9,r4,r5
	ctx.r9.u64 = ctx.r4.u64 | ctx.r5.u64;
	// or r7,r3,r11
	ctx.r7.u64 = ctx.r3.u64 | ctx.r11.u64;
	// and r6,r14,r8
	ctx.r6.u64 = ctx.r14.u64 & ctx.r8.u64;
	// or r11,r9,r10
	ctx.r11.u64 = ctx.r9.u64 | ctx.r10.u64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r8,r29,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r29.u64;
	// b 0x82b6ffec
	goto loc_82B6FFEC;
loc_82B6FDFC:
	// subf r10,r5,r21
	ctx.r10.u64 = ctx.r21.u64 - ctx.r5.u64;
	// subf r9,r21,r15
	ctx.r9.u64 = ctx.r15.u64 - ctx.r21.u64;
	// srawi r11,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 31;
	// subf r8,r5,r15
	ctx.r8.u64 = ctx.r15.u64 - ctx.r5.u64;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// subf r7,r21,r5
	ctx.r7.u64 = ctx.r5.u64 - ctx.r21.u64;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// subf r6,r15,r21
	ctx.r6.u64 = ctx.r21.u64 - ctx.r15.u64;
	// srawi r8,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 31;
	// srawi r7,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 31;
	// srawi r6,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r6.s32 >> 31;
	// not r4,r11
	ctx.r4.u64 = ~ctx.r11.u64;
	// not r3,r7
	ctx.r3.u64 = ~ctx.r7.u64;
	// not r7,r6
	ctx.r7.u64 = ~ctx.r6.u64;
	// and r30,r15,r4
	ctx.r30.u64 = ctx.r15.u64 & ctx.r4.u64;
	// not r6,r9
	ctx.r6.u64 = ~ctx.r9.u64;
	// lwz r9,540(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 540);
	// and r25,r21,r3
	ctx.r25.u64 = ctx.r21.u64 & ctx.r3.u64;
	// and r4,r5,r4
	ctx.r4.u64 = ctx.r5.u64 & ctx.r4.u64;
	// not r8,r8
	ctx.r8.u64 = ~ctx.r8.u64;
	// and r23,r21,r7
	ctx.r23.u64 = ctx.r21.u64 & ctx.r7.u64;
	// not r24,r10
	ctx.r24.u64 = ~ctx.r10.u64;
	// and r7,r30,r7
	ctx.r7.u64 = ctx.r30.u64 & ctx.r7.u64;
	// and r30,r25,r6
	ctx.r30.u64 = ctx.r25.u64 & ctx.r6.u64;
	// and r4,r4,r3
	ctx.r4.u64 = ctx.r4.u64 & ctx.r3.u64;
	// and r25,r5,r8
	ctx.r25.u64 = ctx.r5.u64 & ctx.r8.u64;
	// and r3,r15,r8
	ctx.r3.u64 = ctx.r15.u64 & ctx.r8.u64;
	// and r23,r23,r24
	ctx.r23.u64 = ctx.r23.u64 & ctx.r24.u64;
	// or r8,r7,r30
	ctx.r8.u64 = ctx.r7.u64 | ctx.r30.u64;
	// and r7,r25,r24
	ctx.r7.u64 = ctx.r25.u64 & ctx.r24.u64;
	// and r3,r3,r6
	ctx.r3.u64 = ctx.r3.u64 & ctx.r6.u64;
	// or r4,r23,r4
	ctx.r4.u64 = ctx.r23.u64 | ctx.r4.u64;
	// or r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 | ctx.r7.u64;
	// or r7,r4,r3
	ctx.r7.u64 = ctx.r4.u64 | ctx.r3.u64;
	// subf r4,r8,r9
	ctx.r4.u64 = ctx.r9.u64 - ctx.r8.u64;
	// subf r3,r9,r7
	ctx.r3.u64 = ctx.r7.u64 - ctx.r9.u64;
	// xor r30,r24,r11
	ctx.r30.u64 = ctx.r24.u64 ^ ctx.r11.u64;
	// xor r25,r6,r11
	ctx.r25.u64 = ctx.r6.u64 ^ ctx.r11.u64;
	// subf r24,r7,r8
	ctx.r24.u64 = ctx.r8.u64 - ctx.r7.u64;
	// srawi r11,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 31;
	// srawi r4,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r3.s32 >> 31;
	// srawi r3,r24,31
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r24.s32 >> 31;
	// eqv r4,r4,r11
	ctx.r4.u64 = ~(ctx.r4.u64 ^ ctx.r11.u64);
	// eqv r3,r3,r11
	ctx.r3.u64 = ~(ctx.r3.u64 ^ ctx.r11.u64);
	// xor r11,r6,r10
	ctx.r11.u64 = ctx.r6.u64 ^ ctx.r10.u64;
	// or r10,r4,r3
	ctx.r10.u64 = ctx.r4.u64 | ctx.r3.u64;
	// and r9,r9,r4
	ctx.r9.u64 = ctx.r9.u64 & ctx.r4.u64;
	// and r6,r11,r21
	ctx.r6.u64 = ctx.r11.u64 & ctx.r21.u64;
	// and r5,r30,r5
	ctx.r5.u64 = ctx.r30.u64 & ctx.r5.u64;
	// andc r4,r7,r10
	ctx.r4.u64 = ctx.r7.u64 & ~ctx.r10.u64;
	// or r11,r6,r5
	ctx.r11.u64 = ctx.r6.u64 | ctx.r5.u64;
	// and r10,r25,r15
	ctx.r10.u64 = ctx.r25.u64 & ctx.r15.u64;
	// or r9,r4,r9
	ctx.r9.u64 = ctx.r4.u64 | ctx.r9.u64;
	// and r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 & ctx.r3.u64;
	// or r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 | ctx.r10.u64;
	// or r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 | ctx.r8.u64;
	// subf r7,r14,r26
	ctx.r7.u64 = ctx.r26.u64 - ctx.r14.u64;
	// add r6,r10,r11
	ctx.r6.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r5,r26,r20
	ctx.r5.u64 = ctx.r20.u64 - ctx.r26.u64;
	// srawi r4,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r6.s32 >> 1;
	// subf r3,r20,r14
	ctx.r3.u64 = ctx.r14.u64 - ctx.r20.u64;
	// addze r11,r4
	temp.s64 = ctx.r4.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r4.u32;
	ctx.r11.s64 = temp.s64;
	// srawi r10,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 31;
	// srawi r9,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 31;
	// srawi r8,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r3.s32 >> 31;
	// not r6,r9
	ctx.r6.u64 = ~ctx.r9.u64;
	// not r5,r8
	ctx.r5.u64 = ~ctx.r8.u64;
	// xor r4,r6,r10
	ctx.r4.u64 = ctx.r6.u64 ^ ctx.r10.u64;
	// xor r3,r5,r9
	ctx.r3.u64 = ctx.r5.u64 ^ ctx.r9.u64;
	// and r7,r4,r26
	ctx.r7.u64 = ctx.r4.u64 & ctx.r26.u64;
	// subf r9,r26,r14
	ctx.r9.u64 = ctx.r14.u64 - ctx.r26.u64;
	// and r4,r3,r20
	ctx.r4.u64 = ctx.r3.u64 & ctx.r20.u64;
	// subf r8,r20,r26
	ctx.r8.u64 = ctx.r26.u64 - ctx.r20.u64;
	// xor r3,r5,r10
	ctx.r3.u64 = ctx.r5.u64 ^ ctx.r10.u64;
	// subf r30,r14,r20
	ctx.r30.u64 = ctx.r20.u64 - ctx.r14.u64;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// srawi r8,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 31;
	// or r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 | ctx.r7.u64;
	// and r3,r3,r14
	ctx.r3.u64 = ctx.r3.u64 & ctx.r14.u64;
	// srawi r7,r30,31
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r30.s32 >> 31;
	// not r10,r10
	ctx.r10.u64 = ~ctx.r10.u64;
	// not r8,r8
	ctx.r8.u64 = ~ctx.r8.u64;
	// not r7,r7
	ctx.r7.u64 = ~ctx.r7.u64;
	// and r25,r14,r10
	ctx.r25.u64 = ctx.r14.u64 & ctx.r10.u64;
	// and r10,r26,r10
	ctx.r10.u64 = ctx.r26.u64 & ctx.r10.u64;
	// and r24,r20,r8
	ctx.r24.u64 = ctx.r20.u64 & ctx.r8.u64;
	// not r30,r9
	ctx.r30.u64 = ~ctx.r9.u64;
	// lwz r9,572(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 572);
	// and r23,r20,r7
	ctx.r23.u64 = ctx.r20.u64 & ctx.r7.u64;
	// and r7,r25,r7
	ctx.r7.u64 = ctx.r25.u64 & ctx.r7.u64;
	// and r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 & ctx.r8.u64;
	// and r25,r24,r5
	ctx.r25.u64 = ctx.r24.u64 & ctx.r5.u64;
	// and r26,r26,r30
	ctx.r26.u64 = ctx.r26.u64 & ctx.r30.u64;
	// and r24,r23,r6
	ctx.r24.u64 = ctx.r23.u64 & ctx.r6.u64;
	// and r8,r14,r30
	ctx.r8.u64 = ctx.r14.u64 & ctx.r30.u64;
	// and r6,r26,r6
	ctx.r6.u64 = ctx.r26.u64 & ctx.r6.u64;
	// or r7,r7,r25
	ctx.r7.u64 = ctx.r7.u64 | ctx.r25.u64;
	// and r8,r8,r5
	ctx.r8.u64 = ctx.r8.u64 & ctx.r5.u64;
	// or r10,r24,r10
	ctx.r10.u64 = ctx.r24.u64 | ctx.r10.u64;
	// or r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r6,r10,r8
	ctx.r6.u64 = ctx.r10.u64 | ctx.r8.u64;
	// subf r5,r7,r9
	ctx.r5.u64 = ctx.r9.u64 - ctx.r7.u64;
	// subf r8,r9,r6
	ctx.r8.u64 = ctx.r6.u64 - ctx.r9.u64;
	// subf r30,r6,r7
	ctx.r30.u64 = ctx.r7.u64 - ctx.r6.u64;
	// srawi r10,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 31;
	// srawi r5,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 31;
	// srawi r8,r30,31
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r30.s32 >> 31;
	// eqv r5,r5,r10
	ctx.r5.u64 = ~(ctx.r5.u64 ^ ctx.r10.u64);
	// eqv r10,r8,r10
	ctx.r10.u64 = ~(ctx.r8.u64 ^ ctx.r10.u64);
	// and r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 & ctx.r5.u64;
	// or r8,r5,r10
	ctx.r8.u64 = ctx.r5.u64 | ctx.r10.u64;
	// and r7,r7,r10
	ctx.r7.u64 = ctx.r7.u64 & ctx.r10.u64;
	// andc r5,r6,r8
	ctx.r5.u64 = ctx.r6.u64 & ~ctx.r8.u64;
	// or r6,r4,r3
	ctx.r6.u64 = ctx.r4.u64 | ctx.r3.u64;
	// or r4,r5,r9
	ctx.r4.u64 = ctx.r5.u64 | ctx.r9.u64;
	// or r10,r4,r7
	ctx.r10.u64 = ctx.r4.u64 | ctx.r7.u64;
	// add r3,r10,r6
	ctx.r3.u64 = ctx.r10.u64 + ctx.r6.u64;
	// srawi r10,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r3.s32 >> 1;
	// addze r10,r10
	temp.s64 = ctx.r10.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r10.u32;
	ctx.r10.s64 = temp.s64;
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r8,r29,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r29.u64;
	// b 0x82b6ffec
	goto loc_82B6FFEC;
loc_82B6FFE4:
	// li r8,0
	ctx.r8.s64 = 0;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82B6FFEC:
	// clrlwi r9,r8,31
	ctx.r9.u64 = ctx.r8.u32 & 0x1;
	// lwz r10,1788(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1788);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82b7000c
	if (ctx.cr6.eq) goto loc_82B7000C;
	// rlwinm r9,r28,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// subfic r9,r9,1
	ctx.xer.ca = ctx.r9.u32 <= 1;
	ctx.r9.u64 = static_cast<uint64_t>(1) - ctx.r9.u64;
	// subf r8,r9,r8
	ctx.r8.u64 = ctx.r8.u64 - ctx.r9.u64;
	// b 0x82b70010
	goto loc_82B70010;
loc_82B7000C:
	// li r9,0
	ctx.r9.s64 = 0;
loc_82B70010:
	// lwz r7,1460(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1460);
	// srawi r8,r8,1
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 1;
	// mullw r6,r11,r10
	ctx.r6.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// cmpw cr6,r27,r7
	ctx.cr6.compare<int32_t>(ctx.r27.s32, ctx.r7.s32, ctx.xer);
	// addi r7,r10,-256
	ctx.r7.s64 = ctx.r10.s64 + -256;
	// beq cr6,0x82b700a4
	if (ctx.cr6.eq) goto loc_82B700A4;
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// mullw r10,r8,r10
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// beq cr6,0x82b70060
	if (ctx.cr6.eq) goto loc_82B70060;
	// mullw r11,r7,r11
	ctx.r11.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r11.s32);
	// mullw r8,r8,r7
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// addi r7,r6,255
	ctx.r7.s64 = ctx.r6.s64 + 255;
	// addi r6,r10,255
	ctx.r6.s64 = ctx.r10.s64 + 255;
	// addi r5,r11,255
	ctx.r5.s64 = ctx.r11.s64 + 255;
	// srawi r11,r7,9
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1FF) != 0);
	ctx.r11.s64 = ctx.r7.s32 >> 9;
	// addi r4,r8,255
	ctx.r4.s64 = ctx.r8.s64 + 255;
	// srawi r3,r6,9
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1FF) != 0);
	ctx.r3.s64 = ctx.r6.s32 >> 9;
	// srawi r7,r5,9
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1FF) != 0);
	ctx.r7.s64 = ctx.r5.s32 >> 9;
	// srawi r8,r4,9
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x1FF) != 0);
	ctx.r8.s64 = ctx.r4.s32 >> 9;
	// b 0x82b70120
	goto loc_82B70120;
loc_82B70060:
	// mullw r5,r7,r11
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r11.s32);
	// mullw r11,r8,r7
	ctx.r11.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// addi r8,r6,64
	ctx.r8.s64 = ctx.r6.s64 + 64;
	// addi r7,r10,64
	ctx.r7.s64 = ctx.r10.s64 + 64;
	// addi r6,r5,64
	ctx.r6.s64 = ctx.r5.s64 + 64;
	// addi r5,r11,64
	ctx.r5.s64 = ctx.r11.s64 + 64;
	// rlwinm r4,r8,1,0,30
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r3,r7,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r5,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r11,r4,8
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFF) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 8;
	// srawi r6,r3,8
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFF) != 0);
	ctx.r6.s64 = ctx.r3.s32 >> 8;
	// srawi r7,r10,8
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 8;
	// srawi r5,r8,8
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 8;
	// rlwinm r10,r6,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r5,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// b 0x82b70128
	goto loc_82B70128;
loc_82B700A4:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x82b700f4
	if (ctx.cr6.eq) goto loc_82B700F4;
	// mullw r5,r8,r10
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// mullw r4,r7,r11
	ctx.r4.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r11.s32);
	// mullw r3,r8,r7
	ctx.r3.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// rlwinm r11,r6,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r5,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r4,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r3,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
	// addi r10,r10,255
	ctx.r10.s64 = ctx.r10.s64 + 255;
	// addi r8,r8,255
	ctx.r8.s64 = ctx.r8.s64 + 255;
	// addi r6,r7,255
	ctx.r6.s64 = ctx.r7.s64 + 255;
	// srawi r11,r11,9
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1FF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 9;
	// srawi r5,r10,9
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1FF) != 0);
	ctx.r5.s64 = ctx.r10.s32 >> 9;
	// srawi r7,r8,9
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x1FF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 9;
	// srawi r4,r6,9
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1FF) != 0);
	ctx.r4.s64 = ctx.r6.s32 >> 9;
	// rlwinm r10,r5,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r4,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// b 0x82b70128
	goto loc_82B70128;
loc_82B700F4:
	// mullw r10,r8,r10
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// mullw r11,r7,r11
	ctx.r11.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r11.s32);
	// mullw r8,r8,r7
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// addi r7,r6,128
	ctx.r7.s64 = ctx.r6.s64 + 128;
	// addi r6,r10,128
	ctx.r6.s64 = ctx.r10.s64 + 128;
	// addi r5,r11,128
	ctx.r5.s64 = ctx.r11.s64 + 128;
	// srawi r11,r7,8
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFF) != 0);
	ctx.r11.s64 = ctx.r7.s32 >> 8;
	// addi r4,r8,128
	ctx.r4.s64 = ctx.r8.s64 + 128;
	// srawi r3,r6,8
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFF) != 0);
	ctx.r3.s64 = ctx.r6.s32 >> 8;
	// srawi r7,r5,8
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFF) != 0);
	ctx.r7.s64 = ctx.r5.s32 >> 8;
	// srawi r8,r4,8
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0xFF) != 0);
	ctx.r8.s64 = ctx.r4.s32 >> 8;
loc_82B70120:
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r10,r3,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
loc_82B70128:
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r10,r18,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 2) & 0xFFFFFFFC;
	// add r5,r8,r9
	ctx.r5.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r9,r10,r16
	ctx.r9.u64 = ctx.r10.u64 + ctx.r16.u64;
	// extsh r4,r11
	ctx.r4.s64 = ctx.r11.s16;
	// add r8,r17,r18
	ctx.r8.u64 = ctx.r17.u64 + ctx.r18.u64;
	// extsh r3,r6
	ctx.r3.s64 = ctx.r6.s16;
	// rlwinm r11,r8,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// sth r4,2(r9)
	PPC_STORE_U16(ctx.r9.u32 + 2, ctx.r4.u16);
	// mr r30,r7
	ctx.r30.u64 = ctx.r7.u64;
	// rlwinm r10,r18,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r16
	ctx.r8.u64 = ctx.r8.u64 + ctx.r16.u64;
	// lwz r6,1836(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// add r7,r11,r6
	ctx.r7.u64 = ctx.r11.u64 + ctx.r6.u64;
	// sth r4,2(r7)
	PPC_STORE_U16(ctx.r7.u32 + 2, ctx.r4.u16);
	// lwz r7,1836(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// lhz r6,2(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// sth r6,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, ctx.r6.u16);
	// lwz r7,1836(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// add r4,r10,r7
	ctx.r4.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lhzx r7,r11,r7
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r7.u32);
	// sth r7,2(r4)
	PPC_STORE_U16(ctx.r4.u32 + 2, ctx.r7.u16);
	// lwz r7,1836(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// add r7,r10,r7
	ctx.r7.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lhz r6,2(r7)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// sth r6,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, ctx.r6.u16);
	// lwz r4,1836(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// lhzx r6,r10,r4
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r4.u32);
	// extsh r14,r6
	ctx.r14.s64 = ctx.r6.s16;
	// sth r3,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r3.u16);
	// lwz r7,1840(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// add r4,r7,r11
	ctx.r4.u64 = ctx.r7.u64 + ctx.r11.u64;
	// sth r3,2(r4)
	PPC_STORE_U16(ctx.r4.u32 + 2, ctx.r3.u16);
	// lwz r7,1840(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// add r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lhz r3,2(r7)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// sth r3,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, ctx.r3.u16);
	// lwz r7,1840(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// add r6,r10,r7
	ctx.r6.u64 = ctx.r10.u64 + ctx.r7.u64;
	// lhzx r4,r11,r7
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r7.u32);
	// sth r4,2(r6)
	PPC_STORE_U16(ctx.r6.u32 + 2, ctx.r4.u16);
	// lwz r7,1840(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// add r7,r7,r10
	ctx.r7.u64 = ctx.r7.u64 + ctx.r10.u64;
	// lhz r3,2(r7)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r7.u32 + 2);
	// sth r3,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, ctx.r3.u16);
	// lwz r7,1840(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// lwz r6,0(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lhzx r4,r7,r10
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r10.u32);
	// extsh r15,r4
	ctx.r15.s64 = ctx.r4.s16;
	// stw r6,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r6.u32);
	// stw r6,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r6.u32);
	// stw r6,4(r9)
	PPC_STORE_U32(ctx.r9.u32 + 4, ctx.r6.u32);
	// lwz r9,1844(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// add r3,r11,r9
	ctx.r3.u64 = ctx.r11.u64 + ctx.r9.u64;
	// sth r30,2(r3)
	PPC_STORE_U16(ctx.r3.u32 + 2, ctx.r30.u16);
	// lwz r9,1844(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lhz r8,2(r9)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + 2);
	// sth r8,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r8.u16);
	// lwz r9,1844(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lhzx r6,r9,r11
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r11.u32);
	// sth r6,2(r7)
	PPC_STORE_U16(ctx.r7.u32 + 2, ctx.r6.u16);
	// lwz r9,1844(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lhz r4,2(r9)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r9.u32 + 2);
	// sth r4,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r4.u16);
	// lwz r3,1844(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// lwz r9,1848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lhzx r8,r10,r3
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r3.u32);
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// sth r5,2(r9)
	PPC_STORE_U16(ctx.r9.u32 + 2, ctx.r5.u16);
	// lwz r9,1848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// add r9,r11,r9
	ctx.r9.u64 = ctx.r11.u64 + ctx.r9.u64;
	// lhz r6,2(r9)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r9.u32 + 2);
	// sth r6,0(r9)
	PPC_STORE_U16(ctx.r9.u32 + 0, ctx.r6.u16);
	// lwz r9,1848(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lhzx r4,r9,r11
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r11.u32);
	// stw r7,608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 608, ctx.r7.u32);
	// sth r4,2(r5)
	PPC_STORE_U16(ctx.r5.u32 + 2, ctx.r4.u16);
	// lwz r11,1848(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lhz r3,2(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// sth r3,0(r11)
	PPC_STORE_U16(ctx.r11.u32 + 0, ctx.r3.u16);
	// lwz r11,1848(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// lhzx r10,r10,r11
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r11.u32);
	// extsh r9,r10
	ctx.r9.s64 = ctx.r10.s16;
	// stw r9,616(r1)
	PPC_STORE_U32(ctx.r1.u32 + 616, ctx.r9.u32);
loc_82B70298:
	// lwz r10,600(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 600);
	// clrlwi r9,r15,31
	ctx.r9.u64 = ctx.r15.u32 & 0x1;
	// slw r11,r14,r10
	ctx.r11.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r14.u32 << (ctx.r10.u8 & 0x3F));
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82b702d4
	if (ctx.cr6.eq) goto loc_82B702D4;
	// lwz r9,468(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 468);
	// slw r8,r15,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r15.u32 << (ctx.r10.u8 & 0x3F));
	// subf r7,r9,r8
	ctx.r7.u64 = ctx.r8.u64 - ctx.r9.u64;
	// li r29,1
	ctx.r29.s64 = 1;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// rlwinm r5,r7,0,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwimi r6,r29,3,31,28
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 3) & 0xFFFFFFFFFFFFFFF9) | (ctx.r6.u64 & 0x6);
	// srawi r4,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r4.s64 = ctx.r6.s32 >> 1;
	// or r10,r4,r5
	ctx.r10.u64 = ctx.r4.u64 | ctx.r5.u64;
	// b 0x82b702ec
	goto loc_82B702EC;
loc_82B702D4:
	// slw r10,r15,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r15.u32 << (ctx.r10.u8 & 0x3F));
	// srawi r9,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 1;
	// rlwinm r8,r10,0,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF8;
	// clrlwi r7,r9,30
	ctx.r7.u64 = ctx.r9.u32 & 0x3;
	// li r29,0
	ctx.r29.s64 = 0;
	// or r10,r7,r8
	ctx.r10.u64 = ctx.r7.u64 | ctx.r8.u64;
loc_82B702EC:
	// lwz r23,128(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// rlwimi r11,r10,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
	// lwz r28,116(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// li r17,0
	ctx.r17.s64 = 0;
	// rlwinm r10,r23,17,0,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 17) & 0xFFFE0000;
	// lwz r9,300(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 300);
	// rlwinm r7,r11,1,15,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x10000;
	// or r8,r10,r28
	ctx.r8.u64 = ctx.r10.u64 | ctx.r28.u64;
	// rlwinm r19,r8,6,0,25
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// subf r10,r7,r19
	ctx.r10.u64 = ctx.r19.u64 - ctx.r7.u64;
	// subf r6,r19,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r19.u64;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r4,r11,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r11.u64;
	// addis r3,r5,128
	ctx.r3.s64 = ctx.r5.s64 + 8388608;
	// addi r3,r3,56
	ctx.r3.s64 = ctx.r3.s64 + 56;
	// or r10,r3,r4
	ctx.r10.u64 = ctx.r3.u64 | ctx.r4.u64;
	// rlwinm r9,r10,0,0,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r9,r9,0,16,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82b70424
	if (ctx.cr6.eq) goto loc_82B70424;
	// lwz r10,1368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// srawi r6,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r11.s32 >> 16;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r4,r28,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r3,r23,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 5) & 0xFFFFFFE0;
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// rlwinm r10,r6,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x4;
	// bne cr6,0x82b7037c
	if (!ctx.cr6.eq) goto loc_82B7037C;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lhz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 52);
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// beq cr6,0x82b70398
	if (ctx.cr6.eq) goto loc_82B70398;
	// li r7,-35
	ctx.r7.s64 = -35;
	// addi r5,r10,3
	ctx.r5.s64 = ctx.r10.s64 + 3;
	// b 0x82b703a0
	goto loc_82B703A0;
loc_82B7037C:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lhz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 52);
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// beq cr6,0x82b70398
	if (ctx.cr6.eq) goto loc_82B70398;
	// li r7,-37
	ctx.r7.s64 = -37;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// b 0x82b703a0
	goto loc_82B703A0;
loc_82B70398:
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// li r7,-36
	ctx.r7.s64 = -36;
loc_82B703A0:
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// srawi r9,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 2;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// cmpwi cr6,r10,-17
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -17, ctx.xer);
	// bge cr6,0x82b703c0
	if (!ctx.cr6.lt) goto loc_82B703C0;
	// li r10,-17
	ctx.r10.s64 = -17;
	// b 0x82b703d4
	goto loc_82B703D4;
loc_82B703C0:
	// lhz r8,50(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// rotlwi r8,r8,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 3);
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// ble cr6,0x82b703d8
	if (!ctx.cr6.gt) goto loc_82B703D8;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_82B703D4:
	// li r30,1
	ctx.r30.s64 = 1;
loc_82B703D8:
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x82b703e8
	if (!ctx.cr6.lt) goto loc_82B703E8;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// b 0x82b70400
	goto loc_82B70400;
loc_82B703E8:
	// cmpw cr6,r9,r5
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x82b703f8
	if (!ctx.cr6.gt) goto loc_82B703F8;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// b 0x82b70400
	goto loc_82B70400;
loc_82B703F8:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x82b70420
	if (ctx.cr6.eq) goto loc_82B70420;
loc_82B70400:
	// subf r8,r4,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r4.u64;
	// subf r9,r3,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r3.u64;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// clrlwi r9,r6,30
	ctx.r9.u64 = ctx.r6.u32 & 0x3;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
loc_82B70420:
	// rlwimi r11,r6,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
loc_82B70424:
	// srawi r15,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r15.s64 = ctx.r11.s32 >> 16;
	// extsh r14,r11
	ctx.r14.s64 = ctx.r11.s16;
	// stw r15,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r15.u32);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r14,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r14.u32);
	// clrlwi r20,r15,30
	ctx.r20.u64 = ctx.r15.u32 & 0x3;
	// beq cr6,0x82b7046c
	if (ctx.cr6.eq) goto loc_82B7046C;
	// lwz r10,1368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r15
	ctx.r11.u64 = ctx.r11.u64 + ctx.r15.u64;
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// srawi r7,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// or r5,r6,r20
	ctx.r5.u64 = ctx.r6.u64 | ctx.r20.u64;
	// subf r11,r9,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r9.u64;
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// b 0x82b70478
	goto loc_82B70478;
loc_82B7046C:
	// srawi r11,r15,3
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r15.s32 >> 3;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// or r11,r10,r20
	ctx.r11.u64 = ctx.r10.u64 | ctx.r20.u64;
loc_82B70478:
	// clrlwi r21,r14,30
	ctx.r21.u64 = ctx.r14.u32 & 0x3;
	// lbz r9,31(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 31);
	// clrlwi r10,r11,30
	ctx.r10.u64 = ctx.r11.u32 & 0x3;
	// addi r8,r21,1
	ctx.r8.s64 = ctx.r21.s64 + 1;
	// addi r7,r10,1
	ctx.r7.s64 = ctx.r10.s64 + 1;
	// srawi r10,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r8.s32 >> 2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// add r6,r10,r14
	ctx.r6.u64 = ctx.r10.u64 + ctx.r14.u64;
	// srawi r10,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r6.s32 >> 1;
	// srawi r9,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r7.s32 >> 2;
	// add r5,r9,r11
	ctx.r5.u64 = ctx.r9.u64 + ctx.r11.u64;
	// srawi r11,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 1;
	// beq cr6,0x82b704ec
	if (ctx.cr6.eq) goto loc_82B704EC;
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82b704cc
	if (ctx.cr6.eq) goto loc_82B704CC;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x82b704c8
	if (!ctx.cr6.gt) goto loc_82B704C8;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// b 0x82b704cc
	goto loc_82B704CC;
loc_82B704C8:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_82B704CC:
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82b704ec
	if (ctx.cr6.eq) goto loc_82B704EC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82b704e8
	if (!ctx.cr6.gt) goto loc_82B704E8;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x82b704ec
	goto loc_82B704EC;
loc_82B704E8:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82B704EC:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x82b70504
	if (ctx.cr6.eq) goto loc_82B70504;
	// lwz r9,1368(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
loc_82B70504:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,516(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 516);
	// clrlwi r8,r10,16
	ctx.r8.u64 = ctx.r10.u32 & 0xFFFF;
	// lwz r7,352(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 352);
	// add r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 + ctx.r29.u64;
	// rlwinm r3,r9,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r11,15,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 15) & 0xFFFF0000;
	// rlwinm r4,r11,16,0,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// or r11,r5,r8
	ctx.r11.u64 = ctx.r5.u64 | ctx.r8.u64;
	// or r8,r4,r8
	ctx.r8.u64 = ctx.r4.u64 | ctx.r8.u64;
	// rlwinm r6,r23,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 16) & 0xFFFF0000;
	// stwx r8,r3,r7
	PPC_STORE_U32(ctx.r3.u32 + ctx.r7.u32, ctx.r8.u32);
	// rlwinm r9,r11,1,15,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x10000;
	// or r10,r6,r28
	ctx.r10.u64 = ctx.r6.u64 | ctx.r28.u64;
	// lis r7,24
	ctx.r7.s64 = 1572864;
	// rlwinm r22,r10,5,0,26
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r10,r9,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r9.u64;
	// ori r16,r7,20
	ctx.r16.u64 = ctx.r7.u64 | 20;
	// add r5,r10,r22
	ctx.r5.u64 = ctx.r10.u64 + ctx.r22.u64;
	// add r3,r5,r16
	ctx.r3.u64 = ctx.r5.u64 + ctx.r16.u64;
	// lwz r6,316(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 316);
	// subf r4,r11,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r11.u64;
	// subf r10,r22,r4
	ctx.r10.u64 = ctx.r4.u64 - ctx.r22.u64;
	// or r9,r3,r10
	ctx.r9.u64 = ctx.r3.u64 | ctx.r10.u64;
	// rlwinm r8,r9,0,0,16
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r8,r8,0,16,0
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82b70604
	if (ctx.cr6.eq) goto loc_82B70604;
	// srawi r9,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 16;
	// lhz r7,52(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 52);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// lhz r5,50(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// rlwinm r10,r28,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 3) & 0xFFFFFFF8;
	// srawi r8,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 2;
	// rotlwi r7,r7,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// srawi r6,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 2;
	// rlwinm r8,r23,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 3) & 0xFFFFFFF8;
	// rotlwi r5,r5,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 + ctx.r8.u64;
	// cmpwi cr6,r10,-8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -8, ctx.xer);
	// bge cr6,0x82b705c0
	if (!ctx.cr6.lt) goto loc_82B705C0;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r6,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r6.u64;
	// b 0x82b705d4
	goto loc_82B705D4;
loc_82B705C0:
	// cmpw cr6,r10,r5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x82b705d4
	if (!ctx.cr6.gt) goto loc_82B705D4;
	// subf r10,r10,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_82B705D4:
	// cmpwi cr6,r8,-9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, -9, ctx.xer);
	// bge cr6,0x82b705ec
	if (!ctx.cr6.lt) goto loc_82B705EC;
	// addi r10,r8,9
	ctx.r10.s64 = ctx.r8.s64 + 9;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// b 0x82b70600
	goto loc_82B70600;
loc_82B705EC:
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// ble cr6,0x82b70600
	if (!ctx.cr6.gt) goto loc_82B70600;
	// subf r10,r8,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r8.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_82B70600:
	// rlwimi r11,r9,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
loc_82B70604:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// srawi r24,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r24.s64 = ctx.r11.s32 >> 16;
	// lwz r11,176(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// extsh r25,r10
	ctx.r25.s64 = ctx.r10.s16;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x82b72fdc
	if (ctx.cr6.gt) goto loc_82B72FDC;
	// lis r12,-32073
	ctx.r12.s64 = -2101936128;
	// addi r12,r12,1588
	ctx.r12.s64 = ctx.r12.s64 + 1588;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82B70A64;
	case 1:
		goto loc_82B70A64;
	case 2:
		goto loc_82B708FC;
	case 3:
		goto loc_82B70644;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82B70644:
	// lhz r11,74(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 74);
	// srawi r9,r15,2
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r15.s32 >> 2;
	// lwz r10,1060(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1060);
	// srawi r8,r14,2
	ctx.xer.ca = (ctx.r14.s32 < 0) & ((ctx.r14.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r14.s32 >> 2;
	// rlwinm r7,r11,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lhz r30,76(r31)
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// srawi r3,r24,2
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r24.s32 >> 2;
	// mullw r7,r7,r9
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// lwz r11,12(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// srawi r9,r25,2
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r25.s32 >> 2;
	// bne cr6,0x82b7068c
	if (!ctx.cr6.eq) goto loc_82B7068C;
	// lwz r6,504(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 504);
	// lwz r5,508(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 508);
	// lwz r4,488(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 488);
	// b 0x82b70698
	goto loc_82B70698;
loc_82B7068C:
	// lwz r6,480(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 480);
	// lwz r5,484(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 484);
	// lwz r4,464(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 464);
loc_82B70698:
	// add r7,r6,r9
	ctx.r7.u64 = ctx.r6.u64 + ctx.r9.u64;
	// lhz r28,90(r31)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r31.u32 + 90);
	// add r6,r5,r9
	ctx.r6.u64 = ctx.r5.u64 + ctx.r9.u64;
	// mullw r9,r3,r30
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// add r29,r6,r9
	ctx.r29.u64 = ctx.r6.u64 + ctx.r9.u64;
	// add r30,r7,r9
	ctx.r30.u64 = ctx.r7.u64 + ctx.r9.u64;
	// lwz r9,560(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 560);
	// add r27,r8,r10
	ctx.r27.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r8,576(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 576);
	// lwz r7,580(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 580);
	// li r6,128
	ctx.r6.s64 = 128;
	// add r26,r9,r10
	ctx.r26.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r23,r8,r11
	ctx.r23.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r22,r7,r11
	ctx.r22.u64 = ctx.r7.u64 + ctx.r11.u64;
	// dcbt r6,r27
	// addi r5,r28,128
	ctx.r5.s64 = ctx.r28.s64 + 128;
	// dcbt r5,r27
	// addi r4,r28,64
	ctx.r4.s64 = ctx.r28.s64 + 64;
	// rlwinm r3,r4,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r3,r27
	// rotlwi r11,r28,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r28.u32, 1);
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r27
	// addi r10,r28,32
	ctx.r10.s64 = ctx.r28.s64 + 32;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r9,r27
	// rotlwi r11,r28,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r28.u32, 2);
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// addi r8,r11,128
	ctx.r8.s64 = ctx.r11.s64 + 128;
	// dcbt r8,r27
	// rotlwi r11,r28,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r28.u32, 1);
	// add r7,r28,r11
	ctx.r7.u64 = ctx.r28.u64 + ctx.r11.u64;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// dcbt r6,r27
	// rotlwi r5,r28,3
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r28.u32, 3);
	// subf r11,r28,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r28.u64;
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// dcbt r4,r27
	// lbz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r31.u32 + 48);
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bne cr6,0x82b707ac
	if (!ctx.cr6.eq) goto loc_82B707AC;
	// addi r11,r21,52
	ctx.r11.s64 = ctx.r21.s64 + 52;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r20
	ctx.r10.u64 = ctx.r11.u64 + ctx.r20.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82B70780;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82b707c8
	if (ctx.cr6.eq) goto loc_82B707C8;
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r8,35(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 35);
	// mr r7,r20
	ctx.r7.u64 = ctx.r20.u64;
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82a3a308
	ctx.lr = 0x82B707A8;
	sub_82A3A308(ctx, base);
	// b 0x82b707c8
	goto loc_82B707C8;
loc_82B707AC:
	// addi r11,r21,56
	ctx.r11.s64 = ctx.r21.s64 + 56;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r20
	ctx.r10.u64 = ctx.r11.u64 + ctx.r20.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82B707C8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82B707C8:
	// lhz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 92);
	// li r11,128
	ctx.r11.s64 = 128;
	// dcbt r11,r30
	// addi r10,r4,128
	ctx.r10.s64 = ctx.r4.s64 + 128;
	// dcbt r10,r30
	// addi r9,r4,64
	ctx.r9.s64 = ctx.r4.s64 + 64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r8,r30
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r30
	// addi r6,r4,32
	ctx.r6.s64 = ctx.r4.s64 + 32;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r5,r30
	// rotlwi r11,r4,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r3,r11,128
	ctx.r3.s64 = ctx.r11.s64 + 128;
	// dcbt r3,r30
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r11,128
	ctx.r10.s64 = ctx.r11.s64 + 128;
	// dcbt r10,r30
	// rotlwi r9,r4,3
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// subf r11,r4,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r4.u64;
	// addi r8,r11,128
	ctx.r8.s64 = ctx.r11.s64 + 128;
	// dcbt r8,r30
	// clrlwi r11,r25,30
	ctx.r11.u64 = ctx.r25.u32 & 0x3;
	// clrlwi r10,r24,30
	ctx.r10.u64 = ctx.r24.u32 & 0x3;
	// addi r6,r11,56
	ctx.r6.s64 = ctx.r11.s64 + 56;
	// li r7,0
	ctx.r7.s64 = 0;
	// rlwinm r11,r6,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// rlwinm r28,r3,2,0,29
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// lwzx r11,r28,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r31.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B7086C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 92);
	// li r10,128
	ctx.r10.s64 = 128;
	// dcbt r10,r29
	// addi r9,r4,128
	ctx.r9.s64 = ctx.r4.s64 + 128;
	// dcbt r9,r29
	// addi r8,r4,64
	ctx.r8.s64 = ctx.r4.s64 + 64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r7,r29
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// dcbt r6,r29
	// addi r5,r4,32
	ctx.r5.s64 = ctx.r4.s64 + 32;
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r3,r29
	// rotlwi r11,r4,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r29
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r10,r4,r11
	ctx.r10.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r11,r10,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// dcbt r9,r29
	// rotlwi r8,r4,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// subf r11,r4,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r4.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r29
	// lwzx r11,r28,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + ctx.r31.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r22
	ctx.r5.u64 = ctx.r22.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B708F8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// b 0x82b72fdc
	goto loc_82B72FDC;
loc_82B708FC:
	// lhz r11,74(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 74);
	// srawi r9,r15,2
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r15.s32 >> 2;
	// lwz r10,1060(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1060);
	// srawi r8,r14,2
	ctx.xer.ca = (ctx.r14.s32 < 0) & ((ctx.r14.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r14.s32 >> 2;
	// rlwinm r7,r11,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lhz r30,76(r31)
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// srawi r3,r24,2
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r24.s32 >> 2;
	// mullw r7,r7,r9
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r9.s32);
	// lwz r11,12(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 12);
	// lwz r10,8(r10)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r10.u32 + 8);
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// srawi r9,r25,2
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r25.s32 >> 2;
	// bne cr6,0x82b70944
	if (!ctx.cr6.eq) goto loc_82B70944;
	// lwz r6,552(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 552);
	// lwz r5,556(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 556);
	// lwz r4,536(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 536);
	// b 0x82b70950
	goto loc_82B70950;
loc_82B70944:
	// lwz r6,528(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 528);
	// lwz r5,532(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 532);
	// lwz r4,512(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 512);
loc_82B70950:
	// add r7,r6,r9
	ctx.r7.u64 = ctx.r6.u64 + ctx.r9.u64;
	// lhz r28,90(r31)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r31.u32 + 90);
	// add r6,r5,r9
	ctx.r6.u64 = ctx.r5.u64 + ctx.r9.u64;
	// mullw r9,r3,r30
	ctx.r9.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r8,r8,r4
	ctx.r8.u64 = ctx.r8.u64 + ctx.r4.u64;
	// add r29,r6,r9
	ctx.r29.u64 = ctx.r6.u64 + ctx.r9.u64;
	// add r30,r7,r9
	ctx.r30.u64 = ctx.r7.u64 + ctx.r9.u64;
	// lwz r9,560(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 560);
	// add r27,r8,r10
	ctx.r27.u64 = ctx.r8.u64 + ctx.r10.u64;
	// lwz r8,576(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 576);
	// lwz r7,580(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 580);
	// li r6,128
	ctx.r6.s64 = 128;
	// add r26,r9,r10
	ctx.r26.u64 = ctx.r9.u64 + ctx.r10.u64;
	// add r23,r8,r11
	ctx.r23.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r22,r7,r11
	ctx.r22.u64 = ctx.r7.u64 + ctx.r11.u64;
	// dcbt r6,r27
	// addi r5,r28,128
	ctx.r5.s64 = ctx.r28.s64 + 128;
	// dcbt r5,r27
	// addi r4,r28,64
	ctx.r4.s64 = ctx.r28.s64 + 64;
	// rlwinm r3,r4,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r3,r27
	// rotlwi r11,r28,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r28.u32, 1);
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r27
	// addi r10,r28,32
	ctx.r10.s64 = ctx.r28.s64 + 32;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r9,r27
	// rotlwi r11,r28,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r28.u32, 2);
	// add r11,r28,r11
	ctx.r11.u64 = ctx.r28.u64 + ctx.r11.u64;
	// addi r8,r11,128
	ctx.r8.s64 = ctx.r11.s64 + 128;
	// dcbt r8,r27
	// rotlwi r11,r28,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r28.u32, 1);
	// add r7,r28,r11
	ctx.r7.u64 = ctx.r28.u64 + ctx.r11.u64;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// dcbt r6,r27
	// rotlwi r5,r28,3
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r28.u32, 3);
	// subf r11,r28,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r28.u64;
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// dcbt r4,r27
	// lbz r3,48(r31)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r31.u32 + 48);
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bne cr6,0x82b707ac
	if (!ctx.cr6.eq) goto loc_82B707AC;
	// addi r11,r21,52
	ctx.r11.s64 = ctx.r21.s64 + 52;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r20
	ctx.r10.u64 = ctx.r11.u64 + ctx.r20.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82B70A38;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82b707c8
	if (ctx.cr6.eq) goto loc_82B707C8;
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r8,35(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 35);
	// mr r7,r20
	ctx.r7.u64 = ctx.r20.u64;
	// mr r6,r21
	ctx.r6.u64 = ctx.r21.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// mr r3,r27
	ctx.r3.u64 = ctx.r27.u64;
	// bl 0x82a3a308
	ctx.lr = 0x82B70A60;
	sub_82A3A308(ctx, base);
	// b 0x82b707c8
	goto loc_82B707C8;
loc_82B70A64:
	// lhz r30,74(r31)
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r31.u32 + 74);
	// srawi r11,r15,2
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r15.s32 >> 2;
	// lwz r18,1060(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1060);
	// srawi r9,r14,2
	ctx.xer.ca = (ctx.r14.s32 < 0) & ((ctx.r14.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r14.s32 >> 2;
	// rlwinm r10,r30,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 31) & 0x7FFFFFFF;
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// lhz r29,76(r31)
	ctx.r29.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// mullw r8,r10,r11
	ctx.r8.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r11.s32);
	// lwz r4,8(r18)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// lwz r10,12(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	// srawi r3,r24,2
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r24.s32 >> 2;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// srawi r11,r25,2
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r25.s32 >> 2;
	// bne cr6,0x82b70aac
	if (!ctx.cr6.eq) goto loc_82B70AAC;
	// lwz r7,504(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 504);
	// lwz r6,508(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 508);
	// lwz r5,488(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 488);
	// b 0x82b70ab8
	goto loc_82B70AB8;
loc_82B70AAC:
	// lwz r7,480(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 480);
	// lwz r6,484(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 484);
	// lwz r5,464(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 464);
loc_82B70AB8:
	// add r8,r7,r11
	ctx.r8.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lwz r27,616(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 616);
	// add r7,r6,r11
	ctx.r7.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r8,r8,r10
	ctx.r8.u64 = ctx.r8.u64 + ctx.r10.u64;
	// mullw r11,r3,r29
	ctx.r11.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r29.s32);
	// add r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// add r28,r10,r11
	ctx.r28.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r29,r8,r11
	ctx.r29.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r26,r9,r4
	ctx.r26.u64 = ctx.r9.u64 + ctx.r4.u64;
	// li r11,128
	ctx.r11.s64 = 128;
	// dcbt r11,r26
	// addi r10,r30,128
	ctx.r10.s64 = ctx.r30.s64 + 128;
	// dcbt r10,r26
	// addi r9,r30,64
	ctx.r9.s64 = ctx.r30.s64 + 64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r8,r26
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r26
	// addi r6,r30,32
	ctx.r6.s64 = ctx.r30.s64 + 32;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r5,r26
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// dcbt r4,r26
	// rlwinm r11,r30,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r30,r11
	ctx.r3.u64 = ctx.r30.u64 + ctx.r11.u64;
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r26
	// rlwinm r10,r30,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r11,r30,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r30.u64;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// dcbt r9,r26
	// lbz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 48);
	// rlwinm r11,r21,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// li r6,16
	ctx.r6.s64 = 16;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// add r11,r11,r20
	ctx.r11.u64 = ctx.r11.u64 + ctx.r20.u64;
	// bne cr6,0x82b70bcc
	if (!ctx.cr6.eq) goto loc_82B70BCC;
	// addi r11,r11,241
	ctx.r11.s64 = ctx.r11.s64 + 241;
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// mr r9,r20
	ctx.r9.u64 = ctx.r20.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// lwzx r11,r3,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r31.u32);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B70B98;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82b70c90
	if (ctx.cr6.eq) goto loc_82B70C90;
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// lbz r9,35(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 35);
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// li r6,16
	ctx.r6.s64 = 16;
	// mr r5,r27
	ctx.r5.u64 = ctx.r27.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bl 0x82a3a0a0
	ctx.lr = 0x82B70BC8;
	sub_82A3A0A0(ctx, base);
	// b 0x82b70c90
	goto loc_82B70C90;
loc_82B70BCC:
	// addi r11,r11,257
	ctx.r11.s64 = ctx.r11.s64 + 257;
	// lbz r9,35(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 35);
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// rlwinm r23,r11,2,0,29
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwzx r11,r23,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + ctx.r31.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B70BF4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r9,35(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 35);
	// lwzx r11,r23,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + ctx.r31.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r27,8
	ctx.r5.s64 = ctx.r27.s64 + 8;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r26,8
	ctx.r3.s64 = ctx.r26.s64 + 8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B70C24;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r11,r30,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// lbz r9,35(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 35);
	// li r10,1
	ctx.r10.s64 = 1;
	// add r26,r11,r26
	ctx.r26.u64 = ctx.r11.u64 + ctx.r26.u64;
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r27,128
	ctx.r5.s64 = ctx.r27.s64 + 128;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// lwzx r11,r23,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + ctx.r31.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B70C5C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r9,35(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 35);
	// lwzx r11,r23,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r23.u32 + ctx.r31.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r27,136
	ctx.r5.s64 = ctx.r27.s64 + 136;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// addi r3,r26,8
	ctx.r3.s64 = ctx.r26.s64 + 8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B70C8C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r23,128(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
loc_82B70C90:
	// lhz r4,76(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// li r11,128
	ctx.r11.s64 = 128;
	// dcbt r11,r29
	// addi r10,r4,128
	ctx.r10.s64 = ctx.r4.s64 + 128;
	// dcbt r10,r29
	// addi r9,r4,64
	ctx.r9.s64 = ctx.r4.s64 + 64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r8,r29
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r29
	// addi r6,r4,32
	ctx.r6.s64 = ctx.r4.s64 + 32;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r5,r29
	// rotlwi r11,r4,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r3,r11,128
	ctx.r3.s64 = ctx.r11.s64 + 128;
	// dcbt r3,r29
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r11,128
	ctx.r10.s64 = ctx.r11.s64 + 128;
	// dcbt r10,r29
	// rotlwi r9,r4,3
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// subf r11,r4,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r4.u64;
	// addi r8,r11,128
	ctx.r8.s64 = ctx.r11.s64 + 128;
	// dcbt r8,r29
	// clrlwi r30,r24,30
	ctx.r30.u64 = ctx.r24.u32 & 0x3;
	// lbz r9,35(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 35);
	// rlwinm r11,r25,2,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xC;
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// clrlwi r26,r25,30
	ctx.r26.u64 = ctx.r25.u32 & 0x3;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r7,r11,257
	ctx.r7.s64 = ctx.r11.s64 + 257;
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// rlwinm r3,r7,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r27,256
	ctx.r5.s64 = ctx.r27.s64 + 256;
	// lwzx r11,r3,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r31.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B70D44;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r4,76(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// li r10,128
	ctx.r10.s64 = 128;
	// dcbt r10,r28
	// addi r9,r4,128
	ctx.r9.s64 = ctx.r4.s64 + 128;
	// dcbt r9,r28
	// addi r8,r4,64
	ctx.r8.s64 = ctx.r4.s64 + 64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r7,r28
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// dcbt r6,r28
	// addi r5,r4,32
	ctx.r5.s64 = ctx.r4.s64 + 32;
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r3,r28
	// rotlwi r11,r4,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r28
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r10,r4,r11
	ctx.r10.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r11,r10,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// dcbt r9,r28
	// rotlwi r8,r4,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// subf r11,r4,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r4.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r28
	// rlwinm r11,r25,2,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xC;
	// lbz r9,35(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 35);
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addi r6,r11,257
	ctx.r6.s64 = ctx.r11.s64 + 257;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r5,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r31.u32);
	// mr r8,r30
	ctx.r8.u64 = ctx.r30.u64;
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r27,320
	ctx.r5.s64 = ctx.r27.s64 + 320;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B70DF0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r10,616(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 616);
	// lwz r8,608(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 608);
	// lwz r9,600(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 600);
	// clrlwi r7,r10,31
	ctx.r7.u64 = ctx.r10.u32 & 0x1;
	// slw r11,r8,r9
	ctx.r11.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r9.u8 & 0x3F));
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x82b70e34
	if (ctx.cr6.eq) goto loc_82B70E34;
	// lwz r8,468(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 468);
	// slw r7,r10,r9
	ctx.r7.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// subf r6,r8,r7
	ctx.r6.u64 = ctx.r7.u64 - ctx.r8.u64;
	// li r29,1
	ctx.r29.s64 = 1;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// rlwinm r4,r6,0,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwimi r5,r29,3,31,28
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 3) & 0xFFFFFFFFFFFFFFF9) | (ctx.r5.u64 & 0x6);
	// srawi r3,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r3.s64 = ctx.r5.s32 >> 1;
	// or r10,r3,r4
	ctx.r10.u64 = ctx.r3.u64 | ctx.r4.u64;
	// b 0x82b70e4c
	goto loc_82B70E4C;
loc_82B70E34:
	// slw r10,r10,r9
	ctx.r10.u64 = ctx.r9.u8 & 0x20 ? 0 : (ctx.r10.u32 << (ctx.r9.u8 & 0x3F));
	// srawi r9,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 1;
	// rlwinm r8,r10,0,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF8;
	// clrlwi r7,r9,30
	ctx.r7.u64 = ctx.r9.u32 & 0x3;
	// mr r29,r17
	ctx.r29.u64 = ctx.r17.u64;
	// or r10,r7,r8
	ctx.r10.u64 = ctx.r7.u64 | ctx.r8.u64;
loc_82B70E4C:
	// rlwimi r11,r10,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
	// lwz r10,300(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 300);
	// rlwinm r9,r11,1,15,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x10000;
	// subf r8,r11,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r11.u64;
	// subf r10,r9,r11
	ctx.r10.u64 = ctx.r11.u64 - ctx.r9.u64;
	// subf r7,r19,r8
	ctx.r7.u64 = ctx.r8.u64 - ctx.r19.u64;
	// add r6,r10,r19
	ctx.r6.u64 = ctx.r10.u64 + ctx.r19.u64;
	// addis r5,r6,128
	ctx.r5.s64 = ctx.r6.s64 + 8388608;
	// addi r5,r5,56
	ctx.r5.s64 = ctx.r5.s64 + 56;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rlwinm r3,r4,0,0,16
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r3,r3,0,16,0
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r3,0
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 0, ctx.xer);
	// beq cr6,0x82b70f70
	if (ctx.cr6.eq) goto loc_82B70F70;
	// lwz r10,1368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// srawi r6,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r11.s32 >> 16;
	// lwz r8,116(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r4,r8,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r3,r23,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 5) & 0xFFFFFFE0;
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// rlwinm r10,r6,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x4;
	// bne cr6,0x82b70ec8
	if (!ctx.cr6.eq) goto loc_82B70EC8;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lhz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 52);
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// beq cr6,0x82b70ee4
	if (ctx.cr6.eq) goto loc_82B70EE4;
	// li r7,-35
	ctx.r7.s64 = -35;
	// addi r5,r10,3
	ctx.r5.s64 = ctx.r10.s64 + 3;
	// b 0x82b70eec
	goto loc_82B70EEC;
loc_82B70EC8:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lhz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 52);
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// beq cr6,0x82b70ee4
	if (ctx.cr6.eq) goto loc_82B70EE4;
	// li r7,-37
	ctx.r7.s64 = -37;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// b 0x82b70eec
	goto loc_82B70EEC;
loc_82B70EE4:
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// li r7,-36
	ctx.r7.s64 = -36;
loc_82B70EEC:
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// srawi r9,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 2;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// cmpwi cr6,r10,-17
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -17, ctx.xer);
	// bge cr6,0x82b70f0c
	if (!ctx.cr6.lt) goto loc_82B70F0C;
	// li r10,-17
	ctx.r10.s64 = -17;
	// b 0x82b70f20
	goto loc_82B70F20;
loc_82B70F0C:
	// lhz r8,50(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// rotlwi r8,r8,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 3);
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// ble cr6,0x82b70f24
	if (!ctx.cr6.gt) goto loc_82B70F24;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_82B70F20:
	// li r30,1
	ctx.r30.s64 = 1;
loc_82B70F24:
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x82b70f34
	if (!ctx.cr6.lt) goto loc_82B70F34;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// b 0x82b70f4c
	goto loc_82B70F4C;
loc_82B70F34:
	// cmpw cr6,r9,r5
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x82b70f44
	if (!ctx.cr6.gt) goto loc_82B70F44;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// b 0x82b70f4c
	goto loc_82B70F4C;
loc_82B70F44:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x82b70f6c
	if (ctx.cr6.eq) goto loc_82B70F6C;
loc_82B70F4C:
	// subf r8,r4,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r4.u64;
	// subf r9,r3,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r3.u64;
	// rlwinm r10,r8,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r9,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// clrlwi r9,r6,30
	ctx.r9.u64 = ctx.r6.u32 & 0x3;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r6,r8,r9
	ctx.r6.u64 = ctx.r8.u64 + ctx.r9.u64;
loc_82B70F6C:
	// rlwimi r11,r6,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
loc_82B70F70:
	// srawi r4,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r4.s64 = ctx.r11.s32 >> 16;
	// extsh r3,r11
	ctx.r3.s64 = ctx.r11.s16;
	// stw r4,616(r1)
	PPC_STORE_U32(ctx.r1.u32 + 616, ctx.r4.u32);
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// stw r3,608(r1)
	PPC_STORE_U32(ctx.r1.u32 + 608, ctx.r3.u32);
	// clrlwi r20,r4,30
	ctx.r20.u64 = ctx.r4.u32 & 0x3;
	// beq cr6,0x82b70fb8
	if (ctx.cr6.eq) goto loc_82B70FB8;
	// lwz r10,1368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r4
	ctx.r11.u64 = ctx.r11.u64 + ctx.r4.u64;
	// addi r8,r11,-4
	ctx.r8.s64 = ctx.r11.s64 + -4;
	// srawi r7,r8,3
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 3;
	// rlwinm r6,r7,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// or r5,r6,r20
	ctx.r5.u64 = ctx.r6.u64 | ctx.r20.u64;
	// subf r11,r9,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r9.u64;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// b 0x82b70fc4
	goto loc_82B70FC4;
loc_82B70FB8:
	// srawi r11,r4,3
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 3;
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// or r10,r10,r20
	ctx.r10.u64 = ctx.r10.u64 | ctx.r20.u64;
loc_82B70FC4:
	// clrlwi r21,r3,30
	ctx.r21.u64 = ctx.r3.u32 & 0x3;
	// lbz r9,31(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 31);
	// clrlwi r11,r10,30
	ctx.r11.u64 = ctx.r10.u32 & 0x3;
	// addi r8,r21,1
	ctx.r8.s64 = ctx.r21.s64 + 1;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// srawi r11,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// add r6,r11,r3
	ctx.r6.u64 = ctx.r11.u64 + ctx.r3.u64;
	// srawi r11,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 1;
	// srawi r9,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r7.s32 >> 2;
	// add r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 + ctx.r10.u64;
	// srawi r10,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 1;
	// beq cr6,0x82b71038
	if (ctx.cr6.eq) goto loc_82B71038;
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82b71018
	if (ctx.cr6.eq) goto loc_82B71018;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82b71014
	if (!ctx.cr6.gt) goto loc_82B71014;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x82b71018
	goto loc_82B71018;
loc_82B71014:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82B71018:
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82b71038
	if (ctx.cr6.eq) goto loc_82B71038;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x82b71034
	if (!ctx.cr6.gt) goto loc_82B71034;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// b 0x82b71038
	goto loc_82B71038;
loc_82B71034:
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
loc_82B71038:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// beq cr6,0x82b71050
	if (ctx.cr6.eq) goto loc_82B71050;
	// lwz r9,1368(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// rlwinm r9,r9,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addi r10,r10,-2
	ctx.r10.s64 = ctx.r10.s64 + -2;
loc_82B71050:
	// rlwinm r10,r10,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,316(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 316);
	// add r8,r10,r29
	ctx.r8.u64 = ctx.r10.u64 + ctx.r29.u64;
	// subf r7,r22,r9
	ctx.r7.u64 = ctx.r9.u64 - ctx.r22.u64;
	// rlwimi r11,r8,15,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 15) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
	// rlwinm r6,r11,1,15,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x10000;
	// subf r5,r11,r7
	ctx.r5.u64 = ctx.r7.u64 - ctx.r11.u64;
	// subf r10,r6,r22
	ctx.r10.u64 = ctx.r22.u64 - ctx.r6.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r9,r10,r16
	ctx.r9.u64 = ctx.r10.u64 + ctx.r16.u64;
	// or r8,r9,r5
	ctx.r8.u64 = ctx.r9.u64 | ctx.r5.u64;
	// rlwinm r7,r8,0,0,16
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r7,r7,0,16,0
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82b71120
	if (ctx.cr6.eq) goto loc_82B71120;
	// lwz r8,116(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// srawi r9,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 16;
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// lhz r7,52(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 52);
	// rlwinm r10,r8,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFF8;
	// lhz r5,50(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// srawi r8,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r11.s32 >> 2;
	// rotlwi r7,r7,2
	ctx.r7.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// add r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 + ctx.r10.u64;
	// srawi r6,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 2;
	// rlwinm r8,r23,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 3) & 0xFFFFFFF8;
	// rotlwi r5,r5,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r7,r7,1
	ctx.r7.s64 = ctx.r7.s64 + 1;
	// add r8,r6,r8
	ctx.r8.u64 = ctx.r6.u64 + ctx.r8.u64;
	// cmpwi cr6,r10,-8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -8, ctx.xer);
	// bge cr6,0x82b710dc
	if (!ctx.cr6.lt) goto loc_82B710DC;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r6,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r6.u64;
	// b 0x82b710f0
	goto loc_82B710F0;
loc_82B710DC:
	// cmpw cr6,r10,r5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x82b710f0
	if (!ctx.cr6.gt) goto loc_82B710F0;
	// subf r10,r10,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_82B710F0:
	// cmpwi cr6,r8,-9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, -9, ctx.xer);
	// bge cr6,0x82b71108
	if (!ctx.cr6.lt) goto loc_82B71108;
	// addi r10,r8,9
	ctx.r10.s64 = ctx.r8.s64 + 9;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// b 0x82b7111c
	goto loc_82B7111C;
loc_82B71108:
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// ble cr6,0x82b7111c
	if (!ctx.cr6.gt) goto loc_82B7111C;
	// subf r10,r8,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r8.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_82B7111C:
	// rlwimi r11,r9,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
loc_82B71120:
	// lhz r26,74(r31)
	ctx.r26.u64 = PPC_LOAD_U16(ctx.r31.u32 + 74);
	// srawi r23,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r23.s64 = ctx.r11.s32 >> 16;
	// extsh r25,r11
	ctx.r25.s64 = ctx.r11.s16;
	// lwz r10,12(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	// srawi r11,r4,2
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 2;
	// lhz r30,76(r31)
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// rlwinm r8,r26,31,1,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r4,8(r18)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// srawi r9,r3,2
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 2;
	// mullw r8,r8,r11
	ctx.r8.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r11.s32);
	// srawi r3,r23,2
	ctx.xer.ca = (ctx.r23.s32 < 0) & ((ctx.r23.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r23.s32 >> 2;
	// cmpwi cr6,r29,1
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 1, ctx.xer);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// srawi r11,r25,2
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r25.s32 >> 2;
	// bne cr6,0x82b7116c
	if (!ctx.cr6.eq) goto loc_82B7116C;
	// lwz r7,552(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 552);
	// lwz r6,556(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 556);
	// lwz r5,536(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 536);
	// b 0x82b71178
	goto loc_82B71178;
loc_82B7116C:
	// lwz r7,528(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 528);
	// lwz r6,532(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 532);
	// lwz r5,512(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 512);
loc_82B71178:
	// add r8,r7,r10
	ctx.r8.u64 = ctx.r7.u64 + ctx.r10.u64;
	// add r7,r6,r10
	ctx.r7.u64 = ctx.r6.u64 + ctx.r10.u64;
	// add r8,r8,r11
	ctx.r8.u64 = ctx.r8.u64 + ctx.r11.u64;
	// mullw r10,r3,r30
	ctx.r10.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
	// lwz r30,428(r31)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// add r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r9,r9,r5
	ctx.r9.u64 = ctx.r9.u64 + ctx.r5.u64;
	// add r28,r11,r10
	ctx.r28.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r29,r8,r10
	ctx.r29.u64 = ctx.r8.u64 + ctx.r10.u64;
	// add r24,r9,r4
	ctx.r24.u64 = ctx.r9.u64 + ctx.r4.u64;
	// li r11,128
	ctx.r11.s64 = 128;
	// dcbt r11,r24
	// addi r10,r26,128
	ctx.r10.s64 = ctx.r26.s64 + 128;
	// dcbt r10,r24
	// addi r9,r26,64
	ctx.r9.s64 = ctx.r26.s64 + 64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r8,r24
	// rlwinm r11,r26,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r26,r11
	ctx.r11.u64 = ctx.r26.u64 + ctx.r11.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r24
	// addi r6,r26,32
	ctx.r6.s64 = ctx.r26.s64 + 32;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r5,r24
	// rlwinm r11,r26,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r26,r11
	ctx.r11.u64 = ctx.r26.u64 + ctx.r11.u64;
	// addi r4,r11,128
	ctx.r4.s64 = ctx.r11.s64 + 128;
	// dcbt r4,r24
	// rlwinm r11,r26,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 1) & 0xFFFFFFFE;
	// add r3,r26,r11
	ctx.r3.u64 = ctx.r26.u64 + ctx.r11.u64;
	// rlwinm r11,r3,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r24
	// rlwinm r10,r26,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r11,r26,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r26.u64;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// dcbt r9,r24
	// lbz r8,48(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 48);
	// rlwinm r11,r21,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r21.u32 | (ctx.r21.u64 << 32), 2) & 0xFFFFFFFC;
	// li r10,1
	ctx.r10.s64 = 1;
	// cmplwi cr6,r8,1
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 1, ctx.xer);
	// li r6,16
	ctx.r6.s64 = 16;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// add r11,r11,r20
	ctx.r11.u64 = ctx.r11.u64 + ctx.r20.u64;
	// bne cr6,0x82b7128c
	if (!ctx.cr6.eq) goto loc_82B7128C;
	// addi r11,r11,241
	ctx.r11.s64 = ctx.r11.s64 + 241;
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// mr r9,r20
	ctx.r9.u64 = ctx.r20.u64;
	// rlwinm r3,r11,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r8,r21
	ctx.r8.u64 = ctx.r21.u64;
	// mr r7,r31
	ctx.r7.u64 = ctx.r31.u64;
	// lwzx r11,r3,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r31.u32);
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B71258;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82b7134c
	if (ctx.cr6.eq) goto loc_82B7134C;
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// lbz r9,35(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 35);
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// li r6,16
	ctx.r6.s64 = 16;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// bl 0x82a3a0a0
	ctx.lr = 0x82B71288;
	sub_82A3A0A0(ctx, base);
	// b 0x82b7134c
	goto loc_82B7134C;
loc_82B7128C:
	// addi r11,r11,257
	ctx.r11.s64 = ctx.r11.s64 + 257;
	// lbz r9,35(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 35);
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// rlwinm r22,r11,2,0,29
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwzx r11,r22,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + ctx.r31.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B712B4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r9,35(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 35);
	// lwzx r11,r22,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + ctx.r31.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r30,8
	ctx.r5.s64 = ctx.r30.s64 + 8;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r3,r24,8
	ctx.r3.s64 = ctx.r24.s64 + 8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B712E4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// rlwinm r11,r26,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 3) & 0xFFFFFFF8;
	// lbz r9,35(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 35);
	// li r10,1
	ctx.r10.s64 = 1;
	// add r24,r11,r24
	ctx.r24.u64 = ctx.r11.u64 + ctx.r24.u64;
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r30,128
	ctx.r5.s64 = ctx.r30.s64 + 128;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// mr r3,r24
	ctx.r3.u64 = ctx.r24.u64;
	// lwzx r11,r22,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + ctx.r31.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B7131C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lbz r9,35(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 35);
	// lwzx r11,r22,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + ctx.r31.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// mr r8,r20
	ctx.r8.u64 = ctx.r20.u64;
	// mr r7,r21
	ctx.r7.u64 = ctx.r21.u64;
	// li r6,16
	ctx.r6.s64 = 16;
	// addi r5,r30,136
	ctx.r5.s64 = ctx.r30.s64 + 136;
	// mr r4,r26
	ctx.r4.u64 = ctx.r26.u64;
	// addi r3,r24,8
	ctx.r3.s64 = ctx.r24.s64 + 8;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B7134C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82B7134C:
	// lhz r4,76(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// li r11,128
	ctx.r11.s64 = 128;
	// dcbt r11,r29
	// addi r10,r4,128
	ctx.r10.s64 = ctx.r4.s64 + 128;
	// dcbt r10,r29
	// addi r9,r4,64
	ctx.r9.s64 = ctx.r4.s64 + 64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r8,r29
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r29
	// addi r6,r4,32
	ctx.r6.s64 = ctx.r4.s64 + 32;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r5,r29
	// rotlwi r11,r4,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r3,r11,128
	ctx.r3.s64 = ctx.r11.s64 + 128;
	// dcbt r3,r29
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r10,r11,128
	ctx.r10.s64 = ctx.r11.s64 + 128;
	// dcbt r10,r29
	// rotlwi r9,r4,3
	ctx.r9.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// subf r11,r4,r9
	ctx.r11.u64 = ctx.r9.u64 - ctx.r4.u64;
	// addi r8,r11,128
	ctx.r8.s64 = ctx.r11.s64 + 128;
	// dcbt r8,r29
	// clrlwi r26,r23,30
	ctx.r26.u64 = ctx.r23.u32 & 0x3;
	// lbz r9,35(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 35);
	// rlwinm r11,r25,2,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xC;
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// clrlwi r24,r25,30
	ctx.r24.u64 = ctx.r25.u32 & 0x3;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// li r10,1
	ctx.r10.s64 = 1;
	// addi r7,r11,257
	ctx.r7.s64 = ctx.r11.s64 + 257;
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// rlwinm r3,r7,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r30,256
	ctx.r5.s64 = ctx.r30.s64 + 256;
	// lwzx r11,r3,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r31.u32);
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B71400;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r4,76(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// li r10,128
	ctx.r10.s64 = 128;
	// dcbt r10,r28
	// addi r9,r4,128
	ctx.r9.s64 = ctx.r4.s64 + 128;
	// dcbt r9,r28
	// addi r8,r4,64
	ctx.r8.s64 = ctx.r4.s64 + 64;
	// rlwinm r7,r8,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r7,r28
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// dcbt r6,r28
	// addi r5,r4,32
	ctx.r5.s64 = ctx.r4.s64 + 32;
	// rlwinm r3,r5,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r3,r28
	// rotlwi r11,r4,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r28
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r10,r4,r11
	ctx.r10.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r11,r10,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// dcbt r9,r28
	// rotlwi r8,r4,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// subf r11,r4,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r4.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r28
	// rlwinm r11,r25,2,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xC;
	// lbz r9,35(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 35);
	// stw r17,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r17.u32);
	// li r10,1
	ctx.r10.s64 = 1;
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// addi r6,r11,257
	ctx.r6.s64 = ctx.r11.s64 + 257;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r5,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r31.u32);
	// mr r8,r26
	ctx.r8.u64 = ctx.r26.u64;
	// mr r7,r24
	ctx.r7.u64 = ctx.r24.u64;
	// li r6,8
	ctx.r6.s64 = 8;
	// addi r5,r30,320
	ctx.r5.s64 = ctx.r30.s64 + 320;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B714AC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// li r24,16
	ctx.r24.s64 = 16;
	// li r23,32
	ctx.r23.s64 = 32;
	// lhz r7,74(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 74);
	// li r22,48
	ctx.r22.s64 = 48;
	// lwz r11,560(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 560);
	// lwz r10,8(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 8);
	// li r21,64
	ctx.r21.s64 = 64;
	// li r20,80
	ctx.r20.s64 = 80;
	// lvx128 v13,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v0,r0,r30
	ea = (ctx.r30.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r19,96
	ctx.r19.s64 = 96;
	// lvx128 v12,r30,r24
	ea = (ctx.r30.u32 + ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r11,r10
	ctx.r10.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lvx128 v10,r27,r24
	ea = (ctx.r27.u32 + ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r5,r7,1
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r7.u32, 1);
	// lvx128 v9,r30,r23
	ea = (ctx.r30.u32 + ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v11,v13,v0
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)ctx.v0.u8)));
	// lvx128 v7,r27,r23
	ea = (ctx.r27.u32 + ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r6,r7,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// lvx128 v6,r30,r22
	ea = (ctx.r30.u32 + ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v8,v10,v12
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)ctx.v12.u8)));
	// lvx128 v4,r27,r22
	ea = (ctx.r27.u32 + ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 + ctx.r7.u64;
	// lvx128 v3,r30,r21
	ea = (ctx.r30.u32 + ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v5,v7,v9
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v9.u8)));
	// lvx128 v1,r27,r21
	ea = (ctx.r27.u32 + ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v2,v4,v6
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v4.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// lvx128 v31,r30,r20
	ea = (ctx.r30.u32 + ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r3,580(r31)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r31.u32 + 580);
	// lvx128 v29,r27,r20
	ea = (ctx.r27.u32 + ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r29,r6,r7
	ctx.r29.u64 = ctx.r6.u64 + ctx.r7.u64;
	// lvx128 v28,r30,r19
	ea = (ctx.r30.u32 + ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v30,v1,v3
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v3.u8)));
	// lvx128 v26,r27,r19
	ea = (ctx.r27.u32 + ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r27,128
	ctx.r9.s64 = ctx.r27.s64 + 128;
	// add r28,r6,r5
	ctx.r28.u64 = ctx.r6.u64 + ctx.r5.u64;
	// vavgub v27,v29,v31
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v29.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)));
	// vavgub v24,v26,v28
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)ctx.v28.u8)));
	// addi r8,r30,128
	ctx.r8.s64 = ctx.r30.s64 + 128;
	// lwz r26,12(r18)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	// li r18,112
	ctx.r18.s64 = 112;
	// lwz r25,576(r31)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r31.u32 + 576);
	// addi r17,r1,768
	ctx.r17.s64 = ctx.r1.s64 + 768;
	// lhz r11,76(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// addi r16,r1,736
	ctx.r16.s64 = ctx.r1.s64 + 736;
	// add r3,r3,r26
	ctx.r3.u64 = ctx.r3.u64 + ctx.r26.u64;
	// lvx128 v25,r30,r18
	ea = (ctx.r30.u32 + ctx.r18.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r30,r25,r26
	ctx.r30.u64 = ctx.r25.u64 + ctx.r26.u64;
	// lvx128 v23,r27,r18
	ea = (ctx.r27.u32 + ctx.r18.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r27,r4,r6
	ctx.r27.u64 = ctx.r4.u64 + ctx.r6.u64;
	// stvx128 v11,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v22,v23,v25
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)ctx.v25.u8)));
	// stvx128 v8,r10,r7
	ea = (ctx.r10.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rotlwi r26,r7,3
	ctx.r26.u64 = __builtin_rotateleft32(ctx.r7.u32, 3);
	// stvx128 v5,r5,r10
	ea = (ctx.r5.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v2,r4,r10
	ea = (ctx.r4.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v2.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v30,r6,r10
	ea = (ctx.r6.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v27,r29,r10
	ea = (ctx.r29.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v27.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v24,r28,r10
	ea = (ctx.r28.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r27,r10
	ea = (ctx.r27.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v18,r8,r23
	ea = (ctx.r8.u32 + ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v19,r8,r24
	ea = (ctx.r8.u32 + ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v20,r9,r23
	ea = (ctx.r9.u32 + ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v17,r9,r24
	ea = (ctx.r9.u32 + ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v11,v20,v18
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v20.u8), simde_mm_load_si128((simde__m128i*)ctx.v18.u8)));
	// vavgub v12,v17,v19
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v17.u8), simde_mm_load_si128((simde__m128i*)ctx.v19.u8)));
	// lvx128 v21,r9,r21
	ea = (ctx.r9.u32 + ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v16,r8,r20
	ea = (ctx.r8.u32 + ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v15,r8,r22
	ea = (ctx.r8.u32 + ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v14,r9,r22
	ea = (ctx.r9.u32 + ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r8,r21
	ea = (ctx.r8.u32 + ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v10,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v11,r0,r17
	ea = (ctx.r17.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v12,r0,r16
	ea = (ctx.r16.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v9,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r26,r10
	ctx.r10.u64 = ctx.r26.u64 + ctx.r10.u64;
	// vavgub v8,v9,v10
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)ctx.v10.u8)));
	// lvx128 v7,r9,r20
	ea = (ctx.r9.u32 + ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v0,v14,v15
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v14.u8), simde_mm_load_si128((simde__m128i*)ctx.v15.u8)));
	// lvx128 v6,r8,r19
	ea = (ctx.r8.u32 + ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v5,r9,r19
	ea = (ctx.r9.u32 + ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v13,v21,v13
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v13.u8)));
	// lvx128 v4,r8,r18
	ea = (ctx.r8.u32 + ctx.r18.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v10,v7,v16
	simde_mm_store_si128((simde__m128i*)ctx.v10.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v7.u8), simde_mm_load_si128((simde__m128i*)ctx.v16.u8)));
	// lvx128 v3,r9,r18
	ea = (ctx.r9.u32 + ctx.r18.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v9,v5,v6
	simde_mm_store_si128((simde__m128i*)ctx.v9.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v5.u8), simde_mm_load_si128((simde__m128i*)ctx.v6.u8)));
	// stvx128 v8,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v8,v3,v4
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v3.u8), simde_mm_load_si128((simde__m128i*)ctx.v4.u8)));
	// stvx128 v12,r10,r7
	ea = (ctx.r10.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r9,r9,128
	ctx.r9.s64 = ctx.r9.s64 + 128;
	// stvx128 v11,r5,r10
	ea = (ctx.r5.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r8,r8,128
	ctx.r8.s64 = ctx.r8.s64 + 128;
	// stvx128 v0,r4,r10
	ea = (ctx.r4.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r26,r1,832
	ctx.r26.s64 = ctx.r1.s64 + 832;
	// stvx128 v13,r6,r10
	ea = (ctx.r6.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r7,r1,800
	ctx.r7.s64 = ctx.r1.s64 + 800;
	// stvx128 v10,r29,r10
	ea = (ctx.r29.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r6,r1,832
	ctx.r6.s64 = ctx.r1.s64 + 832;
	// stvx128 v9,r28,r10
	ea = (ctx.r28.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r5,r1,736
	ctx.r5.s64 = ctx.r1.s64 + 736;
	// stvx128 v8,r27,r10
	ea = (ctx.r27.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r10,r1,800
	ctx.r10.s64 = ctx.r1.s64 + 800;
	// addi r4,r1,768
	ctx.r4.s64 = ctx.r1.s64 + 768;
	// stvx128 v0,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r27,r1,848
	ctx.r27.s64 = ctx.r1.s64 + 848;
	// stvx128 v13,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r1,752
	ctx.r29.s64 = ctx.r1.s64 + 752;
	// addi r26,r1,752
	ctx.r26.s64 = ctx.r1.s64 + 752;
	// addi r28,r1,784
	ctx.r28.s64 = ctx.r1.s64 + 784;
	// addi r7,r1,816
	ctx.r7.s64 = ctx.r1.s64 + 816;
	// addi r25,r1,816
	ctx.r25.s64 = ctx.r1.s64 + 816;
	// stvx128 v10,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v10.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r29,r1,784
	ctx.r29.s64 = ctx.r1.s64 + 784;
	// stvx128 v9,r0,r28
	ea = (ctx.r28.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v9.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v8,r0,r7
	ea = (ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v8.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v21,r9,r21
	ea = (ctx.r9.u32 + ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v27,r8,r21
	ea = (ctx.r8.u32 + ctx.r21.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v14,v21,v27
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v21.u8), simde_mm_load_si128((simde__m128i*)ctx.v27.u8)));
	// lvx128 v28,r8,r24
	ea = (ctx.r8.u32 + ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v2,r8,r22
	ea = (ctx.r8.u32 + ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v26,r0,r9
	ea = (ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v23,r9,r22
	ea = (ctx.r9.u32 + ctx.r22.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v25,r8,r20
	ea = (ctx.r8.u32 + ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v1,r9,r24
	ea = (ctx.r9.u32 + ctx.r24.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v30,r9,r23
	ea = (ctx.r9.u32 + ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v31,r0,r8
	ea = (ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v29,r8,r23
	ea = (ctx.r8.u32 + ctx.r23.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v18,v30,v29
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v30.u8), simde_mm_load_si128((simde__m128i*)ctx.v29.u8)));
	// vavgub v22,v23,v2
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v23.u8), simde_mm_load_si128((simde__m128i*)ctx.v2.u8)));
	// stvx128 v18,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v18.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v16,v1,v28
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v1.u8), simde_mm_load_si128((simde__m128i*)ctx.v28.u8)));
	// stvx128 v14,r0,r10
	ea = (ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v14.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v0,v26,v31
	simde_mm_store_si128((simde__m128i*)ctx.v0.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v26.u8), simde_mm_load_si128((simde__m128i*)ctx.v31.u8)));
	// lvx128 v24,r9,r20
	ea = (ctx.r9.u32 + ctx.r20.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavgub v13,v24,v25
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v24.u8), simde_mm_load_si128((simde__m128i*)ctx.v25.u8)));
	// lvx128 v20,r8,r19
	ea = (ctx.r8.u32 + ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v22,r0,r6
	ea = (ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v22.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r4,768(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 768);
	// stvx128 v16,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v16.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r10,r30,r11
	ctx.r10.u64 = ctx.r30.u64 + ctx.r11.u64;
	// stvx128 v0,r0,r27
	ea = (ctx.r27.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v0.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v19,r9,r19
	ea = (ctx.r9.u32 + ctx.r19.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v17,r8,r18
	ea = (ctx.r8.u32 + ctx.r18.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v15,r9,r18
	ea = (ctx.r9.u32 + ctx.r18.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stvx128 v13,r0,r26
	ea = (ctx.r26.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v13.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r27,772(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 772);
	// lwz r6,800(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 800);
	// lwz r26,776(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 776);
	// lwz r24,780(r1)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 780);
	// lwz r5,844(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 844);
	// lwz r9,736(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 736);
	// lwz r8,740(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 740);
	// lwz r7,744(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 744);
	// lwz r28,748(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 748);
	// lwz r23,848(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 848);
	// lwz r22,852(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 852);
	// vavgub v12,v19,v20
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v19.u8), simde_mm_load_si128((simde__m128i*)ctx.v20.u8)));
	// lwz r21,860(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 860);
	// vavgub v11,v15,v17
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_avg_epu8(simde_mm_load_si128((simde__m128i*)ctx.v15.u8), simde_mm_load_si128((simde__m128i*)ctx.v17.u8)));
	// stw r23,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r23.u32);
	// lwz r20,832(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 832);
	// stvx128 v12,r0,r29
	ea = (ctx.r29.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v12.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lwz r29,856(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 856);
	// stw r22,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r22.u32);
	// stvx128 v11,r0,r25
	ea = (ctx.r25.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)PPC_RAW_ADDR(ea), simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)ctx.v11.u8), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// stw r21,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r21.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r25,804(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 804);
	// lwz r23,752(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 752);
	// stwx r29,r30,r11
	PPC_STORE_U32(ctx.r30.u32 + ctx.r11.u32, ctx.r29.u32);
	// lwz r30,836(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 836);
	// stw r9,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r9.u32);
	// stw r8,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r8.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r29,840(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 840);
	// lwz r9,812(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 812);
	// lwz r8,808(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 808);
	// lwz r22,756(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 756);
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// stw r28,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r28.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r7,760(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 760);
	// lwz r28,764(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 764);
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// stw r27,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r27.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r21,784(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 784);
	// lwz r19,788(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 788);
	// lwz r4,792(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 792);
	// lwz r27,796(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 796);
	// stw r26,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r26.u32);
	// stw r24,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r24.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// lwz r18,816(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 816);
	// lwz r17,820(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 820);
	// lwz r26,824(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 824);
	// lwz r24,828(r1)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r1.u32 + 828);
	// stw r20,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r20.u32);
	// stw r30,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r30.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r29,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r29.u32);
	// stw r5,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r5.u32);
	// add r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 + ctx.r11.u64;
	// stw r6,0(r3)
	PPC_STORE_U32(ctx.r3.u32 + 0, ctx.r6.u32);
	// stw r25,4(r3)
	PPC_STORE_U32(ctx.r3.u32 + 4, ctx.r25.u32);
	// stwx r8,r3,r11
	PPC_STORE_U32(ctx.r3.u32 + ctx.r11.u32, ctx.r8.u32);
	// stw r9,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r9.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r23,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r23.u32);
	// stw r22,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r22.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r7,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r7.u32);
	// stw r28,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r28.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r21,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r21.u32);
	// stw r19,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r19.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r4,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r4.u32);
	// stw r27,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r27.u32);
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r18,0(r10)
	PPC_STORE_U32(ctx.r10.u32 + 0, ctx.r18.u32);
	// stw r17,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r17.u32);
	// stw r26,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r26.u32);
	// stw r24,4(r11)
	PPC_STORE_U32(ctx.r11.u32 + 4, ctx.r24.u32);
	// b 0x82b72fdc
	goto loc_82B72FDC;
loc_82B71834:
	// lwz r10,444(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 444);
	// li r11,0
	ctx.r11.s64 = 0;
	// lhz r9,50(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// stw r11,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r11.u32);
	// stw r11,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r11.u32);
	// lwz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// stw r9,728(r1)
	PPC_STORE_U32(ctx.r1.u32 + 728, ctx.r9.u32);
	// rlwinm r11,r8,27,29,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 27) & 0x7;
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// cmpwi cr6,r11,4
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 4, ctx.xer);
	// bne cr6,0x82b71878
	if (!ctx.cr6.eq) goto loc_82B71878;
	// lwz r14,1836(r31)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// li r11,3
	ctx.r11.s64 = 3;
	// lwz r10,1840(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
	// lwz r9,1844(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// lwz r8,1848(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// b 0x82b7188c
	goto loc_82B7188C;
loc_82B71878:
	// lwz r14,1844(r31)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1844);
	// li r11,4
	ctx.r11.s64 = 4;
	// lwz r10,1848(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1848);
	// lwz r9,1836(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1836);
	// lwz r8,1840(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1840);
loc_82B7188C:
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// li r17,0
	ctx.r17.s64 = 0;
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// addi r15,r31,560
	ctx.r15.s64 = ctx.r31.s64 + 560;
	// stw r9,160(r1)
	PPC_STORE_U32(ctx.r1.u32 + 160, ctx.r9.u32);
	// mr r16,r17
	ctx.r16.u64 = ctx.r17.u64;
	// stw r10,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r10.u32);
	// rlwinm r9,r11,17,0,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// lwz r10,116(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// mr r18,r17
	ctx.r18.u64 = ctx.r17.u64;
	// stw r8,164(r1)
	PPC_STORE_U32(ctx.r1.u32 + 164, ctx.r8.u32);
	// addi r6,r31,36
	ctx.r6.s64 = ctx.r31.s64 + 36;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// stw r14,448(r1)
	PPC_STORE_U32(ctx.r1.u32 + 448, ctx.r14.u32);
	// stw r15,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r15.u32);
	// rlwinm r7,r8,6,0,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 6) & 0xFFFFFFC0;
	// stw r16,480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 480, ctx.r16.u32);
	// stw r18,516(r1)
	PPC_STORE_U32(ctx.r1.u32 + 516, ctx.r18.u32);
	// stw r17,632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 632, ctx.r17.u32);
	// stw r7,604(r1)
	PPC_STORE_U32(ctx.r1.u32 + 604, ctx.r7.u32);
	// stw r6,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r6.u32);
	// stw r17,624(r1)
	PPC_STORE_U32(ctx.r1.u32 + 624, ctx.r17.u32);
loc_82B718E4:
	// lwz r10,168(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// srawi r8,r16,1
	ctx.xer.ca = (ctx.r16.s32 < 0) & ((ctx.r16.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r16.s32 >> 1;
	// lwz r9,1060(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1060);
	// clrlwi r11,r16,31
	ctx.r11.u64 = ctx.r16.u32 & 0x1;
	// lwz r6,348(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 348);
	// lwz r5,128(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r4,116(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lhz r10,0(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// rlwinm r7,r5,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,0(r9)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// add r26,r8,r7
	ctx.r26.u64 = ctx.r8.u64 + ctx.r7.u64;
	// lhz r28,50(r31)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// add r23,r10,r9
	ctx.r23.u64 = ctx.r10.u64 + ctx.r9.u64;
	// clrlwi r3,r26,31
	ctx.r3.u64 = ctx.r26.u32 & 0x1;
	// rlwinm r27,r23,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 2) & 0xFFFFFFFC;
	// stw r23,612(r1)
	PPC_STORE_U32(ctx.r1.u32 + 612, ctx.r23.u32);
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r21,r28,1
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x1) != 0);
	ctx.r21.s64 = ctx.r28.s32 >> 1;
	// add r22,r11,r10
	ctx.r22.u64 = ctx.r11.u64 + ctx.r10.u64;
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// lwzx r20,r6,r27
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r27.u32);
	// stw r20,704(r1)
	PPC_STORE_U32(ctx.r1.u32 + 704, ctx.r20.u32);
	// bne cr6,0x82b7196c
	if (!ctx.cr6.eq) goto loc_82B7196C;
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x82b71960
	if (ctx.cr6.eq) goto loc_82B71960;
	// srawi r11,r26,1
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r26.s32 >> 1;
	// lwz r10,1304(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1304);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82b7196c
	if (ctx.cr6.eq) goto loc_82B7196C;
loc_82B71960:
	// li r29,1
	ctx.r29.s64 = 1;
	// li r30,0
	ctx.r30.s64 = 0;
	// b 0x82b71974
	goto loc_82B71974;
loc_82B7196C:
	// li r30,0
	ctx.r30.s64 = 0;
	// mr r29,r30
	ctx.r29.u64 = ctx.r30.u64;
loc_82B71974:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r9,100(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// srawi r19,r20,16
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0xFFFF) != 0);
	ctx.r19.s64 = ctx.r20.s32 >> 16;
	// rlwinm r8,r11,17,0,14
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// stw r30,376(r1)
	PPC_STORE_U32(ctx.r1.u32 + 376, ctx.r30.u32);
	// stw r30,372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 372, ctx.r30.u32);
	// mr r25,r30
	ctx.r25.u64 = ctx.r30.u64;
	// subf r7,r8,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r8.u64;
	// stw r30,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, ctx.r30.u32);
	// stw r30,404(r1)
	PPC_STORE_U32(ctx.r1.u32 + 404, ctx.r30.u32);
	// mr r24,r30
	ctx.r24.u64 = ctx.r30.u64;
	// stw r30,400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 400, ctx.r30.u32);
	// cmpwi cr6,r9,4
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 4, ctx.xer);
	// stw r19,708(r1)
	PPC_STORE_U32(ctx.r1.u32 + 708, ctx.r19.u32);
	// stw r7,408(r1)
	PPC_STORE_U32(ctx.r1.u32 + 408, ctx.r7.u32);
	// bne cr6,0x82b719cc
	if (!ctx.cr6.eq) goto loc_82B719CC;
	// lis r11,-32078
	ctx.r11.s64 = -2102263808;
	// lis r10,-32078
	ctx.r10.s64 = -2102263808;
	// addi r9,r11,12136
	ctx.r9.s64 = ctx.r11.s64 + 12136;
	// addi r8,r10,12416
	ctx.r8.s64 = ctx.r10.s64 + 12416;
	// b 0x82b719fc
	goto loc_82B719FC;
loc_82B719CC:
	// lwz r11,1372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1372);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82b719ec
	if (!ctx.cr6.eq) goto loc_82B719EC;
	// lis r11,-32078
	ctx.r11.s64 = -2102263808;
	// lis r10,-32078
	ctx.r10.s64 = -2102263808;
	// addi r9,r11,11448
	ctx.r9.s64 = ctx.r11.s64 + 11448;
	// addi r8,r10,11856
	ctx.r8.s64 = ctx.r10.s64 + 11856;
	// b 0x82b719fc
	goto loc_82B719FC;
loc_82B719EC:
	// lis r11,-32078
	ctx.r11.s64 = -2102263808;
	// lis r10,-32078
	ctx.r10.s64 = -2102263808;
	// addi r9,r11,11576
	ctx.r9.s64 = ctx.r11.s64 + 11576;
	// addi r8,r10,11512
	ctx.r8.s64 = ctx.r10.s64 + 11512;
loc_82B719FC:
	// stw r9,1744(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1744, ctx.r9.u32);
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// stw r8,1748(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1748, ctx.r8.u32);
	// beq cr6,0x82b71a84
	if (ctx.cr6.eq) goto loc_82B71A84;
	// addi r11,r23,-1
	ctx.r11.s64 = ctx.r23.s64 + -1;
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r14,r9
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r14.u32 + ctx.r9.u32);
	// lhzx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// sth r8,126(r1)
	PPC_STORE_U16(ctx.r1.u32 + 126, ctx.r8.u16);
	// sth r7,124(r1)
	PPC_STORE_U16(ctx.r1.u32 + 124, ctx.r7.u16);
	// lwz r4,124(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// clrlwi r6,r4,16
	ctx.r6.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r6,16384
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 16384, ctx.xer);
	// beq cr6,0x82b71a84
	if (ctx.cr6.eq) goto loc_82B71A84;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b71a64
	if (ctx.cr6.eq) goto loc_82B71A64;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 400, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B71A58;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, ctx.r3.u32);
	// li r24,1
	ctx.r24.s64 = 1;
	// b 0x82b71a80
	goto loc_82B71A80;
loc_82B71A64:
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,368(r1)
	PPC_STORE_U32(ctx.r1.u32 + 368, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B71A78;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,400(r1)
	PPC_STORE_U32(ctx.r1.u32 + 400, ctx.r3.u32);
	// li r25,1
	ctx.r25.s64 = 1;
loc_82B71A80:
	// li r30,1
	ctx.r30.s64 = 1;
loc_82B71A84:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x82b71bf4
	if (!ctx.cr6.eq) goto loc_82B71BF4;
	// subf r29,r28,r23
	ctx.r29.u64 = ctx.r23.u64 - ctx.r28.u64;
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// rlwinm r10,r29,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r14,r10
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r14.u32 + ctx.r10.u32);
	// lhzx r8,r11,r10
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r10.u32);
	// sth r9,126(r1)
	PPC_STORE_U16(ctx.r1.u32 + 126, ctx.r9.u16);
	// sth r8,124(r1)
	PPC_STORE_U16(ctx.r1.u32 + 124, ctx.r8.u16);
	// lwz r4,124(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// clrlwi r7,r4,16
	ctx.r7.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r7,16384
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 16384, ctx.xer);
	// beq cr6,0x82b71b28
	if (ctx.cr6.eq) goto loc_82B71B28;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rlwinm r11,r30,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// beq cr6,0x82b71af4
	if (ctx.cr6.eq) goto loc_82B71AF4;
	// addi r9,r1,400
	ctx.r9.s64 = ctx.r1.s64 + 400;
	// lwz r10,1744(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r11,r9
	PPC_STORE_U32(ctx.r11.u32 + ctx.r9.u32, ctx.r4.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r11,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r11.u32);
	// bctrl 
	ctx.lr = 0x82B71AE4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,184(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// addi r8,r1,368
	ctx.r8.s64 = ctx.r1.s64 + 368;
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// b 0x82b71b1c
	goto loc_82B71B1C;
loc_82B71AF4:
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// lwz r10,1748(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r11,r9
	PPC_STORE_U32(ctx.r11.u32 + ctx.r9.u32, ctx.r4.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// stw r11,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r11.u32);
	// bctrl 
	ctx.lr = 0x82B71B10;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,184(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// addi r8,r1,400
	ctx.r8.s64 = ctx.r1.s64 + 400;
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
loc_82B71B1C:
	// lwz r14,448(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 448);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// stwx r3,r11,r8
	PPC_STORE_U32(ctx.r11.u32 + ctx.r8.u32, ctx.r3.u32);
loc_82B71B28:
	// cmpwi cr6,r21,1
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 1, ctx.xer);
	// ble cr6,0x82b71bf4
	if (!ctx.cr6.gt) goto loc_82B71BF4;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x82b71b70
	if (ctx.cr6.eq) goto loc_82B71B70;
	// xor r11,r26,r22
	ctx.r11.u64 = ctx.r26.u64 ^ ctx.r22.u64;
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82b71b58
	if (ctx.cr6.eq) goto loc_82B71B58;
	// addi r11,r28,-1
	ctx.r11.s64 = ctx.r28.s64 + -1;
	// cmpw cr6,r22,r11
	ctx.cr6.compare<int32_t>(ctx.r22.s32, ctx.r11.s32, ctx.xer);
	// li r11,0
	ctx.r11.s64 = 0;
	// blt cr6,0x82b71b5c
	if (ctx.cr6.lt) goto loc_82B71B5C;
loc_82B71B58:
	// li r11,1
	ctx.r11.s64 = 1;
loc_82B71B5C:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// subf r10,r11,r23
	ctx.r10.u64 = ctx.r23.u64 - ctx.r11.u64;
	// subf r11,r28,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r28.u64;
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
	// b 0x82b71b74
	goto loc_82B71B74;
loc_82B71B70:
	// addi r11,r29,1
	ctx.r11.s64 = ctx.r29.s64 + 1;
loc_82B71B74:
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r14,r9
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r14.u32 + ctx.r9.u32);
	// lhzx r7,r10,r9
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r10.u32 + ctx.r9.u32);
	// sth r8,126(r1)
	PPC_STORE_U16(ctx.r1.u32 + 126, ctx.r8.u16);
	// sth r7,124(r1)
	PPC_STORE_U16(ctx.r1.u32 + 124, ctx.r7.u16);
	// lwz r4,124(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// clrlwi r6,r4,16
	ctx.r6.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r6,16384
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 16384, ctx.xer);
	// beq cr6,0x82b71bf4
	if (ctx.cr6.eq) goto loc_82B71BF4;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r30,r30,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b71bd0
	if (ctx.cr6.eq) goto loc_82B71BD0;
	// addi r10,r1,400
	ctx.r10.s64 = ctx.r1.s64 + 400;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r30,r10
	PPC_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B71BC4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,368
	ctx.r9.s64 = ctx.r1.s64 + 368;
	// addi r24,r24,1
	ctx.r24.s64 = ctx.r24.s64 + 1;
	// b 0x82b71bf0
	goto loc_82B71BF0;
loc_82B71BD0:
	// addi r10,r1,368
	ctx.r10.s64 = ctx.r1.s64 + 368;
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r30,r10
	PPC_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B71BE8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,400
	ctx.r9.s64 = ctx.r1.s64 + 400;
	// addi r25,r25,1
	ctx.r25.s64 = ctx.r25.s64 + 1;
loc_82B71BF0:
	// stwx r3,r30,r9
	PPC_STORE_U32(ctx.r30.u32 + ctx.r9.u32, ctx.r3.u32);
loc_82B71BF4:
	// add r11,r24,r25
	ctx.r11.u64 = ctx.r24.u64 + ctx.r25.u64;
	// li r3,0
	ctx.r3.s64 = 0;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x82b71d80
	if (!ctx.cr6.gt) goto loc_82B71D80;
	// lhz r11,378(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 378);
	// lhz r10,374(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 374);
	// lhz r9,370(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 370);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// extsh r29,r10
	ctx.r29.s64 = ctx.r10.s16;
	// lhz r8,376(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 376);
	// extsh r28,r9
	ctx.r28.s64 = ctx.r9.s16;
	// lhz r7,372(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 372);
	// lhz r6,368(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 368);
	// extsh r26,r8
	ctx.r26.s64 = ctx.r8.s16;
	// lhz r5,410(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 410);
	// extsh r23,r7
	ctx.r23.s64 = ctx.r7.s16;
	// extsh r22,r6
	ctx.r22.s64 = ctx.r6.s16;
	// lhz r4,406(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 406);
	// subf r10,r28,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r28.u64;
	// lhz r11,402(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 402);
	// subf r9,r30,r29
	ctx.r9.u64 = ctx.r29.u64 - ctx.r30.u64;
	// lhz r6,404(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 404);
	// extsh r18,r5
	ctx.r18.s64 = ctx.r5.s16;
	// lhz r8,408(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 408);
	// subf r7,r28,r30
	ctx.r7.u64 = ctx.r30.u64 - ctx.r28.u64;
	// lhz r21,400(r1)
	ctx.r21.u64 = PPC_LOAD_U16(ctx.r1.u32 + 400);
	// xor r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// extsh r17,r4
	ctx.r17.s64 = ctx.r4.s16;
	// subf r20,r22,r23
	ctx.r20.u64 = ctx.r23.u64 - ctx.r22.u64;
	// subf r19,r26,r23
	ctx.r19.u64 = ctx.r23.u64 - ctx.r26.u64;
	// extsh r16,r11
	ctx.r16.s64 = ctx.r11.s16;
	// subf r4,r22,r26
	ctx.r4.u64 = ctx.r26.u64 - ctx.r22.u64;
	// xor r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// extsh r14,r6
	ctx.r14.s64 = ctx.r6.s16;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// xor r9,r19,r20
	ctx.r9.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r5,r4,r20
	ctx.r5.u64 = ctx.r4.u64 ^ ctx.r20.u64;
	// extsh r15,r8
	ctx.r15.s64 = ctx.r8.s16;
	// extsh r21,r21
	ctx.r21.s64 = ctx.r21.s16;
	// subf r7,r16,r17
	ctx.r7.u64 = ctx.r17.u64 - ctx.r16.u64;
	// subf r6,r18,r17
	ctx.r6.u64 = ctx.r17.u64 - ctx.r18.u64;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// subf r4,r16,r18
	ctx.r4.u64 = ctx.r18.u64 - ctx.r16.u64;
	// srawi r8,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 31;
	// xor r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// subf r20,r21,r14
	ctx.r20.u64 = ctx.r14.u64 - ctx.r21.u64;
	// subf r19,r15,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r15.u64;
	// subf r5,r21,r15
	ctx.r5.u64 = ctx.r15.u64 - ctx.r21.u64;
	// xor r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// srawi r7,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 31;
	// xor r19,r19,r20
	ctx.r19.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// xor r20,r5,r20
	ctx.r20.u64 = ctx.r5.u64 ^ ctx.r20.u64;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r6,184(r1)
	PPC_STORE_U32(ctx.r1.u32 + 184, ctx.r6.u32);
	// srawi r6,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r4.s32 >> 31;
	// stw r5,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r5.u32);
	// srawi r5,r19,31
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r19.s32 >> 31;
	// srawi r4,r20,31
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r20.s32 >> 31;
	// and r10,r10,r28
	ctx.r10.u64 = ctx.r10.u64 & ctx.r28.u64;
	// and r8,r8,r22
	ctx.r8.u64 = ctx.r8.u64 & ctx.r22.u64;
	// and r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 & ctx.r29.u64;
	// or r22,r5,r4
	ctx.r22.u64 = ctx.r5.u64 | ctx.r4.u64;
	// and r9,r9,r23
	ctx.r9.u64 = ctx.r9.u64 & ctx.r23.u64;
	// and r4,r4,r21
	ctx.r4.u64 = ctx.r4.u64 & ctx.r21.u64;
	// andc r29,r15,r22
	ctx.r29.u64 = ctx.r15.u64 & ~ctx.r22.u64;
	// lwz r20,184(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 184);
	// lwz r28,124(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// andc r30,r30,r20
	ctx.r30.u64 = ctx.r30.u64 & ~ctx.r20.u64;
	// andc r28,r26,r28
	ctx.r28.u64 = ctx.r26.u64 & ~ctx.r28.u64;
	// or r26,r7,r6
	ctx.r26.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 | ctx.r10.u64;
	// or r8,r28,r8
	ctx.r8.u64 = ctx.r28.u64 | ctx.r8.u64;
	// and r6,r6,r16
	ctx.r6.u64 = ctx.r6.u64 & ctx.r16.u64;
	// andc r30,r18,r26
	ctx.r30.u64 = ctx.r18.u64 & ~ctx.r26.u64;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r10,r8,r9
	ctx.r10.u64 = ctx.r8.u64 | ctx.r9.u64;
	// or r9,r30,r6
	ctx.r9.u64 = ctx.r30.u64 | ctx.r6.u64;
	// and r8,r7,r17
	ctx.r8.u64 = ctx.r7.u64 & ctx.r17.u64;
	// and r6,r5,r14
	ctx.r6.u64 = ctx.r5.u64 & ctx.r14.u64;
	// or r7,r29,r4
	ctx.r7.u64 = ctx.r29.u64 | ctx.r4.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// or r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// lwz r19,708(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 708);
	// lwz r18,516(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 516);
	// lwz r17,632(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 632);
	// lwz r20,704(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 704);
	// lwz r23,612(r1)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r1.u32 + 612);
	// lwz r15,112(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// lwz r16,480(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 480);
	// lwz r14,448(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 448);
	// sth r5,462(r1)
	PPC_STORE_U16(ctx.r1.u32 + 462, ctx.r5.u16);
	// sth r4,460(r1)
	PPC_STORE_U16(ctx.r1.u32 + 460, ctx.r4.u16);
	// sth r11,454(r1)
	PPC_STORE_U16(ctx.r1.u32 + 454, ctx.r11.u16);
	// sth r10,452(r1)
	PPC_STORE_U16(ctx.r1.u32 + 452, ctx.r10.u16);
	// b 0x82b71db0
	goto loc_82B71DB0;
loc_82B71D80:
	// bne cr6,0x82b71d98
	if (!ctx.cr6.eq) goto loc_82B71D98;
	// lwz r11,368(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 368);
	// lwz r10,400(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 400);
	// stw r11,460(r1)
	PPC_STORE_U32(ctx.r1.u32 + 460, ctx.r11.u32);
	// stw r10,452(r1)
	PPC_STORE_U32(ctx.r1.u32 + 452, ctx.r10.u32);
	// b 0x82b71db0
	goto loc_82B71DB0;
loc_82B71D98:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// stw r3,460(r1)
	PPC_STORE_U32(ctx.r1.u32 + 460, ctx.r3.u32);
	// rlwinm r9,r11,17,0,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// subf r8,r9,r10
	ctx.r8.u64 = ctx.r10.u64 - ctx.r9.u64;
	// stw r8,452(r1)
	PPC_STORE_U32(ctx.r1.u32 + 452, ctx.r8.u32);
loc_82B71DB0:
	// lwz r11,1396(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1396);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b71dc8
	if (ctx.cr6.eq) goto loc_82B71DC8;
	// cmpw cr6,r25,r24
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r24.s32, ctx.xer);
	// ble cr6,0x82b71dd4
	if (!ctx.cr6.gt) goto loc_82B71DD4;
	// b 0x82b71dd8
	goto loc_82B71DD8;
loc_82B71DC8:
	// lwz r11,1400(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b71dd8
	if (ctx.cr6.eq) goto loc_82B71DD8;
loc_82B71DD4:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82B71DD8:
	// clrlwi r11,r19,31
	ctx.r11.u64 = ctx.r19.u32 & 0x1;
	// xor r10,r3,r11
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r11.u64;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r10,452(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 452);
	// bne cr6,0x82b71df0
	if (!ctx.cr6.eq) goto loc_82B71DF0;
	// lwz r10,460(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 460);
loc_82B71DF0:
	// rlwinm r11,r11,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// lhz r9,62(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 62);
	// lhz r8,66(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 66);
	// rlwinm r7,r23,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lwz r5,96(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// extsh r11,r9
	ctx.r11.s64 = ctx.r9.s16;
	// stw r6,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r6.u32);
	// extsh r4,r8
	ctx.r4.s64 = ctx.r8.s16;
	// mr r3,r9
	ctx.r3.u64 = ctx.r9.u64;
	// lhz r9,124(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 124);
	// extsh r9,r9
	ctx.r9.s64 = ctx.r9.s16;
	// lhz r10,126(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 126);
	// extsh r10,r10
	ctx.r10.s64 = ctx.r10.s16;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// add r8,r11,r20
	ctx.r8.u64 = ctx.r11.u64 + ctx.r20.u64;
	// and r6,r8,r4
	ctx.r6.u64 = ctx.r8.u64 & ctx.r4.u64;
	// subf r4,r3,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r3.u64;
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// sthx r3,r14,r7
	PPC_STORE_U16(ctx.r14.u32 + ctx.r7.u32, ctx.r3.u16);
	// lwz r11,348(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 348);
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// sth r3,2(r11)
	PPC_STORE_U16(ctx.r11.u32 + 2, ctx.r3.u16);
	// lhz r8,64(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 64);
	// extsh r10,r8
	ctx.r10.s64 = ctx.r8.s16;
	// lhz r6,68(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 68);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r11,348(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 348);
	// add r3,r10,r19
	ctx.r3.u64 = ctx.r10.u64 + ctx.r19.u64;
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
	// and r9,r3,r4
	ctx.r9.u64 = ctx.r3.u64 & ctx.r4.u64;
	// add r8,r11,r27
	ctx.r8.u64 = ctx.r11.u64 + ctx.r27.u64;
	// subf r6,r10,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r10.u64;
	// extsh r4,r6
	ctx.r4.s64 = ctx.r6.s16;
	// lhz r3,2(r8)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r8.u32 + 2);
	// extsh r11,r3
	ctx.r11.s64 = ctx.r3.s16;
	// sthx r4,r5,r7
	PPC_STORE_U16(ctx.r5.u32 + ctx.r7.u32, ctx.r4.u16);
	// lwz r10,348(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 348);
	// sthx r4,r10,r27
	PPC_STORE_U16(ctx.r10.u32 + ctx.r27.u32, ctx.r4.u16);
	// lwz r9,348(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 348);
	// lhzx r8,r9,r27
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r27.u32);
	// extsh r10,r8
	ctx.r10.s64 = ctx.r8.s16;
	// clrlwi r7,r10,31
	ctx.r7.u64 = ctx.r10.u32 & 0x1;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x82b71f48
	if (ctx.cr6.eq) goto loc_82B71F48;
	// lwz r9,468(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 468);
	// li r8,1
	ctx.r8.s64 = 1;
	// lwz r7,720(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 720);
	// addi r6,r1,688
	ctx.r6.s64 = ctx.r1.s64 + 688;
	// subf r5,r9,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r9.u64;
	// lwz r4,1368(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// subf r3,r7,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r7.u64;
	// lwz r7,176(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// mr r10,r5
	ctx.r10.u64 = ctx.r5.u64;
	// lwz r30,100(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// rlwinm r5,r5,0,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFC;
	// rlwimi r10,r8,3,31,28
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFFFFFFFFFF9) | (ctx.r10.u64 & 0x6);
	// rlwinm r9,r4,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
	// or r10,r10,r5
	ctx.r10.u64 = ctx.r10.u64 | ctx.r5.u64;
	// rlwimi r29,r8,3,31,28
	ctx.r29.u64 = (__builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 3) & 0xFFFFFFFFFFFFFFF9) | (ctx.r29.u64 & 0x6);
	// add r9,r9,r10
	ctx.r9.u64 = ctx.r9.u64 + ctx.r10.u64;
	// srawi r8,r29,1
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r29.s32 >> 1;
	// addi r5,r9,-4
	ctx.r5.s64 = ctx.r9.s64 + -4;
	// rlwinm r4,r4,2,0,29
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r9,r5,3
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 3;
	// addi r5,r1,640
	ctx.r5.s64 = ctx.r1.s64 + 640;
	// rlwimi r10,r9,2,0,29
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC) | (ctx.r10.u64 & 0xFFFFFFFF00000003);
	// addi r9,r7,1
	ctx.r9.s64 = ctx.r7.s64 + 1;
	// subf r10,r4,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r4.u64;
	// rlwinm r3,r3,0,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFFFFFC;
	// stw r9,176(r1)
	PPC_STORE_U32(ctx.r1.u32 + 176, ctx.r9.u32);
	// addi r7,r10,2
	ctx.r7.s64 = ctx.r10.s64 + 2;
	// stwx r11,r17,r5
	PPC_STORE_U32(ctx.r17.u32 + ctx.r5.u32, ctx.r11.u32);
	// or r10,r8,r3
	ctx.r10.u64 = ctx.r8.u64 | ctx.r3.u64;
	// stwx r7,r17,r6
	PPC_STORE_U32(ctx.r17.u32 + ctx.r6.u32, ctx.r7.u32);
	// addi r17,r17,4
	ctx.r17.s64 = ctx.r17.s64 + 4;
	// cmpwi cr6,r30,4
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 4, ctx.xer);
	// stw r17,632(r1)
	PPC_STORE_U32(ctx.r1.u32 + 632, ctx.r17.u32);
	// bne cr6,0x82b71f40
	if (!ctx.cr6.eq) goto loc_82B71F40;
	// addi r29,r31,488
	ctx.r29.s64 = ctx.r31.s64 + 488;
	// b 0x82b71f9c
	goto loc_82B71F9C;
loc_82B71F40:
	// addi r29,r31,536
	ctx.r29.s64 = ctx.r31.s64 + 536;
	// b 0x82b71f9c
	goto loc_82B71F9C;
loc_82B71F48:
	// srawi r8,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r10.s32 >> 1;
	// lwz r9,624(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 624);
	// rlwinm r7,r10,0,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFF8;
	// lwz r6,172(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// clrlwi r5,r8,30
	ctx.r5.u64 = ctx.r8.u32 & 0x3;
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r3,r1,656
	ctx.r3.s64 = ctx.r1.s64 + 656;
	// or r10,r5,r7
	ctx.r10.u64 = ctx.r5.u64 | ctx.r7.u64;
	// addi r8,r1,672
	ctx.r8.s64 = ctx.r1.s64 + 672;
	// srawi r7,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 1;
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// rlwimi r7,r10,0,30,31
	ctx.r7.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0x3) | (ctx.r7.u64 & 0xFFFFFFFFFFFFFFFC);
	// stwx r11,r9,r3
	PPC_STORE_U32(ctx.r9.u32 + ctx.r3.u32, ctx.r11.u32);
	// addi r5,r9,4
	ctx.r5.s64 = ctx.r9.s64 + 4;
	// stw r6,172(r1)
	PPC_STORE_U32(ctx.r1.u32 + 172, ctx.r6.u32);
	// stwx r7,r9,r8
	PPC_STORE_U32(ctx.r9.u32 + ctx.r8.u32, ctx.r7.u32);
	// cmpwi cr6,r4,4
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 4, ctx.xer);
	// stw r5,624(r1)
	PPC_STORE_U32(ctx.r1.u32 + 624, ctx.r5.u32);
	// addi r29,r31,464
	ctx.r29.s64 = ctx.r31.s64 + 464;
	// beq cr6,0x82b71f9c
	if (ctx.cr6.eq) goto loc_82B71F9C;
	// addi r29,r31,512
	ctx.r29.s64 = ctx.r31.s64 + 512;
loc_82B71F9C:
	// rlwimi r11,r10,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
	// lwz r10,604(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 604);
	// lwz r9,300(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 300);
	// rlwinm r7,r11,1,15,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x10000;
	// subf r8,r10,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r10.u64;
	// subf r10,r7,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r7.u64;
	// subf r6,r11,r8
	ctx.r6.u64 = ctx.r8.u64 - ctx.r11.u64;
	// add r5,r10,r11
	ctx.r5.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addis r4,r5,128
	ctx.r4.s64 = ctx.r5.s64 + 8388608;
	// addi r4,r4,56
	ctx.r4.s64 = ctx.r4.s64 + 56;
	// or r3,r4,r6
	ctx.r3.u64 = ctx.r4.u64 | ctx.r6.u64;
	// rlwinm r10,r3,0,0,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r10,r10,0,16,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82b720c8
	if (ctx.cr6.eq) goto loc_82B720C8;
	// lwz r10,1368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// srawi r6,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r11.s32 >> 16;
	// lwz r8,116(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// lwz r7,128(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// rlwinm r4,r8,4,0,27
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 4) & 0xFFFFFFF0;
	// rlwinm r3,r7,5,0,26
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 5) & 0xFFFFFFE0;
	// li r30,0
	ctx.r30.s64 = 0;
	// rlwinm r10,r6,0,29,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x4;
	// bne cr6,0x82b72020
	if (!ctx.cr6.eq) goto loc_82B72020;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lhz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 52);
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// beq cr6,0x82b7203c
	if (ctx.cr6.eq) goto loc_82B7203C;
	// li r7,-35
	ctx.r7.s64 = -35;
	// addi r5,r10,3
	ctx.r5.s64 = ctx.r10.s64 + 3;
	// b 0x82b72044
	goto loc_82B72044;
loc_82B72020:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lhz r10,52(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 52);
	// rotlwi r10,r10,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 4);
	// beq cr6,0x82b7203c
	if (ctx.cr6.eq) goto loc_82B7203C;
	// li r7,-37
	ctx.r7.s64 = -37;
	// addi r5,r10,1
	ctx.r5.s64 = ctx.r10.s64 + 1;
	// b 0x82b72044
	goto loc_82B72044;
loc_82B7203C:
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// li r7,-36
	ctx.r7.s64 = -36;
loc_82B72044:
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// srawi r9,r6,2
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 2;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// add r9,r9,r3
	ctx.r9.u64 = ctx.r9.u64 + ctx.r3.u64;
	// cmpwi cr6,r10,-17
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -17, ctx.xer);
	// bge cr6,0x82b72064
	if (!ctx.cr6.lt) goto loc_82B72064;
	// li r10,-17
	ctx.r10.s64 = -17;
	// b 0x82b72078
	goto loc_82B72078;
loc_82B72064:
	// lhz r8,50(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// rotlwi r8,r8,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r8.u32, 3);
	// cmpw cr6,r10,r8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r8.s32, ctx.xer);
	// ble cr6,0x82b7207c
	if (!ctx.cr6.gt) goto loc_82B7207C;
	// mr r10,r8
	ctx.r10.u64 = ctx.r8.u64;
loc_82B72078:
	// li r30,1
	ctx.r30.s64 = 1;
loc_82B7207C:
	// cmpw cr6,r9,r7
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r7.s32, ctx.xer);
	// bge cr6,0x82b7208c
	if (!ctx.cr6.lt) goto loc_82B7208C;
	// mr r9,r7
	ctx.r9.u64 = ctx.r7.u64;
	// b 0x82b720a4
	goto loc_82B720A4;
loc_82B7208C:
	// cmpw cr6,r9,r5
	ctx.cr6.compare<int32_t>(ctx.r9.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x82b7209c
	if (!ctx.cr6.gt) goto loc_82B7209C;
	// mr r9,r5
	ctx.r9.u64 = ctx.r5.u64;
	// b 0x82b720a4
	goto loc_82B720A4;
loc_82B7209C:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x82b720c4
	if (ctx.cr6.eq) goto loc_82B720C4;
loc_82B720A4:
	// subf r10,r4,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r4.u64;
	// subf r9,r3,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r3.u64;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r9,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r11,r11,30
	ctx.r11.u64 = ctx.r11.u32 & 0x3;
	// clrlwi r9,r6,30
	ctx.r9.u64 = ctx.r6.u32 & 0x3;
	// add r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 + ctx.r11.u64;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_82B720C4:
	// rlwimi r11,r6,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
loc_82B720C8:
	// lhz r30,90(r31)
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r31.u32 + 90);
	// srawi r10,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 16;
	// lwzx r8,r29,r18
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r18.u32);
	// extsh r4,r11
	ctx.r4.s64 = ctx.r11.s16;
	// srawi r9,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r9.s64 = ctx.r10.s32 >> 2;
	// lwz r6,1060(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1060);
	// rlwinm r5,r30,31,1,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r7,0(r15)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r15.u32 + 0);
	// li r3,128
	ctx.r3.s64 = 128;
	// mullw r9,r5,r9
	ctx.r9.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r9.s32);
	// lwz r11,8(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 8);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// srawi r8,r4,2
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r4.s32 >> 2;
	// add r28,r11,r7
	ctx.r28.u64 = ctx.r11.u64 + ctx.r7.u64;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// add r29,r9,r11
	ctx.r29.u64 = ctx.r9.u64 + ctx.r11.u64;
	// dcbt r3,r29
	// addi r11,r30,128
	ctx.r11.s64 = ctx.r30.s64 + 128;
	// dcbt r11,r29
	// addi r9,r30,64
	ctx.r9.s64 = ctx.r30.s64 + 64;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r8,r29
	// rotlwi r11,r30,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r30.u32, 1);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r29
	// addi r6,r30,32
	ctx.r6.s64 = ctx.r30.s64 + 32;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r5,r29
	// rotlwi r11,r30,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r30.u32, 2);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// addi r3,r11,128
	ctx.r3.s64 = ctx.r11.s64 + 128;
	// dcbt r3,r29
	// rotlwi r11,r30,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r30.u32, 1);
	// add r11,r30,r11
	ctx.r11.u64 = ctx.r30.u64 + ctx.r11.u64;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r9,r11,128
	ctx.r9.s64 = ctx.r11.s64 + 128;
	// dcbt r9,r29
	// rotlwi r8,r30,3
	ctx.r8.u64 = __builtin_rotateleft32(ctx.r30.u32, 3);
	// subf r11,r30,r8
	ctx.r11.u64 = ctx.r8.u64 - ctx.r30.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r29
	// lbz r6,48(r31)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r31.u32 + 48);
	// clrlwi r27,r4,30
	ctx.r27.u64 = ctx.r4.u32 & 0x3;
	// clrlwi r26,r10,30
	ctx.r26.u64 = ctx.r10.u32 & 0x3;
	// cmplwi cr6,r6,1
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 1, ctx.xer);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bne cr6,0x82b721e0
	if (!ctx.cr6.eq) goto loc_82B721E0;
	// addi r11,r27,52
	ctx.r11.s64 = ctx.r27.s64 + 52;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r26
	ctx.r10.u64 = ctx.r11.u64 + ctx.r26.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82B721B4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82b721fc
	if (ctx.cr6.eq) goto loc_82B721FC;
	// li r9,0
	ctx.r9.s64 = 0;
	// lbz r8,35(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 35);
	// mr r7,r26
	ctx.r7.u64 = ctx.r26.u64;
	// mr r6,r27
	ctx.r6.u64 = ctx.r27.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bl 0x82a3a308
	ctx.lr = 0x82B721DC;
	sub_82A3A308(ctx, base);
	// b 0x82b721fc
	goto loc_82B721FC;
loc_82B721E0:
	// addi r11,r27,56
	ctx.r11.s64 = ctx.r27.s64 + 56;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r26
	ctx.r10.u64 = ctx.r11.u64 + ctx.r26.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82B721FC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82B721FC:
	// lwz r11,168(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 168);
	// addi r18,r18,4
	ctx.r18.s64 = ctx.r18.s64 + 4;
	// addi r16,r16,1
	ctx.r16.s64 = ctx.r16.s64 + 1;
	// addi r10,r11,2
	ctx.r10.s64 = ctx.r11.s64 + 2;
	// stw r18,516(r1)
	PPC_STORE_U32(ctx.r1.u32 + 516, ctx.r18.u32);
	// addi r15,r15,4
	ctx.r15.s64 = ctx.r15.s64 + 4;
	// stw r16,480(r1)
	PPC_STORE_U32(ctx.r1.u32 + 480, ctx.r16.u32);
	// stw r10,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r10.u32);
	// cmpwi cr6,r18,16
	ctx.cr6.compare<int32_t>(ctx.r18.s32, 16, ctx.xer);
	// stw r15,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r15.u32);
	// blt cr6,0x82b718e4
	if (ctx.cr6.lt) goto loc_82B718E4;
	// lwz r17,1060(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1060);
	// li r10,0
	ctx.r10.s64 = 0;
	// lwz r19,128(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lhz r26,50(r31)
	ctx.r26.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// lwz r18,116(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// rlwinm r11,r19,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 1) & 0xFFFFFFFE;
	// srawi r24,r26,1
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x1) != 0);
	ctx.r24.s64 = ctx.r26.s32 >> 1;
	// lwz r23,0(r17)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	// rlwinm r25,r18,1,0,30
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 1) & 0xFFFFFFFE;
	// bne cr6,0x82b72280
	if (!ctx.cr6.eq) goto loc_82B72280;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b72274
	if (ctx.cr6.eq) goto loc_82B72274;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// lwz r10,1304(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1304);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82b72280
	if (ctx.cr6.eq) goto loc_82B72280;
loc_82B72274:
	// li r29,1
	ctx.r29.s64 = 1;
	// li r16,0
	ctx.r16.s64 = 0;
	// b 0x82b72288
	goto loc_82B72288;
loc_82B72280:
	// li r16,0
	ctx.r16.s64 = 0;
	// mr r29,r16
	ctx.r29.u64 = ctx.r16.u64;
loc_82B72288:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// lis r20,1
	ctx.r20.s64 = 65536;
	// lwz r10,120(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// mr r28,r16
	ctx.r28.u64 = ctx.r16.u64;
	// rlwinm r9,r11,17,0,14
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// stw r16,440(r1)
	PPC_STORE_U32(ctx.r1.u32 + 440, ctx.r16.u32);
	// stw r16,436(r1)
	PPC_STORE_U32(ctx.r1.u32 + 436, ctx.r16.u32);
	// mr r27,r16
	ctx.r27.u64 = ctx.r16.u64;
	// subf r8,r9,r20
	ctx.r8.u64 = ctx.r20.u64 - ctx.r9.u64;
	// stw r16,432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 432, ctx.r16.u32);
	// stw r16,420(r1)
	PPC_STORE_U32(ctx.r1.u32 + 420, ctx.r16.u32);
	// mr r30,r16
	ctx.r30.u64 = ctx.r16.u64;
	// stw r16,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, ctx.r16.u32);
	// cmpwi cr6,r10,4
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 4, ctx.xer);
	// stw r8,424(r1)
	PPC_STORE_U32(ctx.r1.u32 + 424, ctx.r8.u32);
	// bne cr6,0x82b722dc
	if (!ctx.cr6.eq) goto loc_82B722DC;
	// lis r11,-32078
	ctx.r11.s64 = -2102263808;
	// lis r10,-32078
	ctx.r10.s64 = -2102263808;
	// addi r9,r11,12136
	ctx.r9.s64 = ctx.r11.s64 + 12136;
	// addi r8,r10,12416
	ctx.r8.s64 = ctx.r10.s64 + 12416;
	// b 0x82b7230c
	goto loc_82B7230C;
loc_82B722DC:
	// lwz r11,1372(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1372);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82b722fc
	if (!ctx.cr6.eq) goto loc_82B722FC;
	// lis r11,-32078
	ctx.r11.s64 = -2102263808;
	// lis r10,-32078
	ctx.r10.s64 = -2102263808;
	// addi r9,r11,11448
	ctx.r9.s64 = ctx.r11.s64 + 11448;
	// addi r8,r10,11856
	ctx.r8.s64 = ctx.r10.s64 + 11856;
	// b 0x82b7230c
	goto loc_82B7230C;
loc_82B722FC:
	// lis r11,-32078
	ctx.r11.s64 = -2102263808;
	// lis r10,-32078
	ctx.r10.s64 = -2102263808;
	// addi r9,r11,11576
	ctx.r9.s64 = ctx.r11.s64 + 11576;
	// addi r8,r10,11512
	ctx.r8.s64 = ctx.r10.s64 + 11512;
loc_82B7230C:
	// lwz r22,160(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// lwz r21,164(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// stw r9,1744(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1744, ctx.r9.u32);
	// stw r8,1748(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1748, ctx.r8.u32);
	// beq cr6,0x82b72398
	if (ctx.cr6.eq) goto loc_82B72398;
	// addi r11,r23,-1
	ctx.r11.s64 = ctx.r23.s64 + -1;
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r22
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r22.u32);
	// lhzx r9,r11,r21
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r21.u32);
	// sth r10,150(r1)
	PPC_STORE_U16(ctx.r1.u32 + 150, ctx.r10.u16);
	// sth r9,148(r1)
	PPC_STORE_U16(ctx.r1.u32 + 148, ctx.r9.u16);
	// lwz r4,148(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b72398
	if (ctx.cr6.eq) goto loc_82B72398;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b72378
	if (ctx.cr6.eq) goto loc_82B72378;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B7236C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 432, ctx.r3.u32);
	// li r27,1
	ctx.r27.s64 = 1;
	// b 0x82b72394
	goto loc_82B72394;
loc_82B72378:
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stw r4,432(r1)
	PPC_STORE_U32(ctx.r1.u32 + 432, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B7238C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// stw r3,416(r1)
	PPC_STORE_U32(ctx.r1.u32 + 416, ctx.r3.u32);
	// li r28,1
	ctx.r28.s64 = 1;
loc_82B72394:
	// li r30,1
	ctx.r30.s64 = 1;
loc_82B72398:
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// bne cr6,0x82b724bc
	if (!ctx.cr6.eq) goto loc_82B724BC;
	// subf r29,r26,r23
	ctx.r29.u64 = ctx.r23.u64 - ctx.r26.u64;
	// rlwinm r11,r29,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r29.u32 | (ctx.r29.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r21
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r21.u32);
	// lhzx r9,r11,r22
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r22.u32);
	// sth r10,148(r1)
	PPC_STORE_U16(ctx.r1.u32 + 148, ctx.r10.u16);
	// sth r9,150(r1)
	PPC_STORE_U16(ctx.r1.u32 + 150, ctx.r9.u16);
	// lwz r4,148(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b72424
	if (ctx.cr6.eq) goto loc_82B72424;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r15,r30,2,0,29
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b723fc
	if (ctx.cr6.eq) goto loc_82B723FC;
	// addi r10,r1,416
	ctx.r10.s64 = ctx.r1.s64 + 416;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r15,r10
	PPC_STORE_U32(ctx.r15.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B723F0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,432
	ctx.r9.s64 = ctx.r1.s64 + 432;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// b 0x82b7241c
	goto loc_82B7241C;
loc_82B723FC:
	// addi r10,r1,432
	ctx.r10.s64 = ctx.r1.s64 + 432;
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r15,r10
	PPC_STORE_U32(ctx.r15.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B72414;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,416
	ctx.r9.s64 = ctx.r1.s64 + 416;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_82B7241C:
	// stwx r3,r15,r9
	PPC_STORE_U32(ctx.r15.u32 + ctx.r9.u32, ctx.r3.u32);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
loc_82B72424:
	// cmpwi cr6,r24,1
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 1, ctx.xer);
	// ble cr6,0x82b724bc
	if (!ctx.cr6.gt) goto loc_82B724BC;
	// addi r11,r26,-2
	ctx.r11.s64 = ctx.r26.s64 + -2;
	// cmpw cr6,r25,r11
	ctx.cr6.compare<int32_t>(ctx.r25.s32, ctx.r11.s32, ctx.xer);
	// addi r11,r29,2
	ctx.r11.s64 = ctx.r29.s64 + 2;
	// bne cr6,0x82b72440
	if (!ctx.cr6.eq) goto loc_82B72440;
	// addi r11,r29,-2
	ctx.r11.s64 = ctx.r29.s64 + -2;
loc_82B72440:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r11,r22
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r22.u32);
	// lhzx r9,r11,r21
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r21.u32);
	// sth r10,150(r1)
	PPC_STORE_U16(ctx.r1.u32 + 150, ctx.r10.u16);
	// sth r9,148(r1)
	PPC_STORE_U16(ctx.r1.u32 + 148, ctx.r9.u16);
	// lwz r4,148(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// clrlwi r8,r4,16
	ctx.r8.u64 = ctx.r4.u32 & 0xFFFF;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// beq cr6,0x82b724bc
	if (ctx.cr6.eq) goto loc_82B724BC;
	// rlwinm r11,r4,0,15,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x10000;
	// rlwinm r30,r30,2,0,29
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b72498
	if (ctx.cr6.eq) goto loc_82B72498;
	// addi r10,r1,416
	ctx.r10.s64 = ctx.r1.s64 + 416;
	// lwz r11,1744(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1744);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r30,r10
	PPC_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B7248C;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,432
	ctx.r9.s64 = ctx.r1.s64 + 432;
	// addi r27,r27,1
	ctx.r27.s64 = ctx.r27.s64 + 1;
	// b 0x82b724b8
	goto loc_82B724B8;
loc_82B72498:
	// addi r10,r1,432
	ctx.r10.s64 = ctx.r1.s64 + 432;
	// lwz r11,1748(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// stwx r4,r30,r10
	PPC_STORE_U32(ctx.r30.u32 + ctx.r10.u32, ctx.r4.u32);
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B724B0;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// addi r9,r1,416
	ctx.r9.s64 = ctx.r1.s64 + 416;
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
loc_82B724B8:
	// stwx r3,r30,r9
	PPC_STORE_U32(ctx.r30.u32 + ctx.r9.u32, ctx.r3.u32);
loc_82B724BC:
	// add r11,r27,r28
	ctx.r11.u64 = ctx.r27.u64 + ctx.r28.u64;
	// mr r3,r16
	ctx.r3.u64 = ctx.r16.u64;
	// cmpwi cr6,r11,1
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 1, ctx.xer);
	// ble cr6,0x82b72640
	if (!ctx.cr6.gt) goto loc_82B72640;
	// lhz r11,442(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 442);
	// lhz r10,438(r1)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r1.u32 + 438);
	// lhz r9,434(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 434);
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// extsh r29,r10
	ctx.r29.s64 = ctx.r10.s16;
	// lhz r8,440(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 440);
	// extsh r26,r9
	ctx.r26.s64 = ctx.r9.s16;
	// lhz r7,436(r1)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r1.u32 + 436);
	// lhz r6,432(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 432);
	// extsh r25,r8
	ctx.r25.s64 = ctx.r8.s16;
	// lhz r5,426(r1)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r1.u32 + 426);
	// extsh r24,r7
	ctx.r24.s64 = ctx.r7.s16;
	// extsh r22,r6
	ctx.r22.s64 = ctx.r6.s16;
	// lhz r4,422(r1)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r1.u32 + 422);
	// subf r10,r26,r29
	ctx.r10.u64 = ctx.r29.u64 - ctx.r26.u64;
	// lhz r11,418(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 418);
	// subf r9,r30,r29
	ctx.r9.u64 = ctx.r29.u64 - ctx.r30.u64;
	// lhz r6,420(r1)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r1.u32 + 420);
	// extsh r18,r5
	ctx.r18.s64 = ctx.r5.s16;
	// lhz r8,424(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 424);
	// subf r7,r26,r30
	ctx.r7.u64 = ctx.r30.u64 - ctx.r26.u64;
	// lhz r21,416(r1)
	ctx.r21.u64 = PPC_LOAD_U16(ctx.r1.u32 + 416);
	// xor r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r10.u64;
	// extsh r17,r4
	ctx.r17.s64 = ctx.r4.s16;
	// subf r20,r22,r24
	ctx.r20.u64 = ctx.r24.u64 - ctx.r22.u64;
	// subf r19,r25,r24
	ctx.r19.u64 = ctx.r24.u64 - ctx.r25.u64;
	// extsh r16,r11
	ctx.r16.s64 = ctx.r11.s16;
	// subf r4,r22,r25
	ctx.r4.u64 = ctx.r25.u64 - ctx.r22.u64;
	// xor r10,r7,r10
	ctx.r10.u64 = ctx.r7.u64 ^ ctx.r10.u64;
	// extsh r14,r6
	ctx.r14.s64 = ctx.r6.s16;
	// srawi r11,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 31;
	// xor r9,r19,r20
	ctx.r9.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// xor r5,r4,r20
	ctx.r5.u64 = ctx.r4.u64 ^ ctx.r20.u64;
	// extsh r15,r8
	ctx.r15.s64 = ctx.r8.s16;
	// extsh r21,r21
	ctx.r21.s64 = ctx.r21.s16;
	// subf r7,r16,r17
	ctx.r7.u64 = ctx.r17.u64 - ctx.r16.u64;
	// subf r6,r18,r17
	ctx.r6.u64 = ctx.r17.u64 - ctx.r18.u64;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r9.s32 >> 31;
	// subf r4,r16,r18
	ctx.r4.u64 = ctx.r18.u64 - ctx.r16.u64;
	// srawi r8,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 31;
	// xor r6,r6,r7
	ctx.r6.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// subf r20,r21,r14
	ctx.r20.u64 = ctx.r14.u64 - ctx.r21.u64;
	// subf r19,r15,r14
	ctx.r19.u64 = ctx.r14.u64 - ctx.r15.u64;
	// subf r5,r21,r15
	ctx.r5.u64 = ctx.r15.u64 - ctx.r21.u64;
	// xor r4,r4,r7
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r7.u64;
	// srawi r7,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r6.s32 >> 31;
	// xor r19,r19,r20
	ctx.r19.u64 = ctx.r19.u64 ^ ctx.r20.u64;
	// or r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 | ctx.r10.u64;
	// xor r20,r5,r20
	ctx.r20.u64 = ctx.r5.u64 ^ ctx.r20.u64;
	// or r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 | ctx.r8.u64;
	// stw r6,604(r1)
	PPC_STORE_U32(ctx.r1.u32 + 604, ctx.r6.u32);
	// srawi r6,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r4.s32 >> 31;
	// stw r5,612(r1)
	PPC_STORE_U32(ctx.r1.u32 + 612, ctx.r5.u32);
	// srawi r5,r19,31
	ctx.xer.ca = (ctx.r19.s32 < 0) & ((ctx.r19.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r19.s32 >> 31;
	// srawi r4,r20,31
	ctx.xer.ca = (ctx.r20.s32 < 0) & ((ctx.r20.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r20.s32 >> 31;
	// and r10,r10,r26
	ctx.r10.u64 = ctx.r10.u64 & ctx.r26.u64;
	// and r9,r9,r24
	ctx.r9.u64 = ctx.r9.u64 & ctx.r24.u64;
	// and r11,r11,r29
	ctx.r11.u64 = ctx.r11.u64 & ctx.r29.u64;
	// or r24,r5,r4
	ctx.r24.u64 = ctx.r5.u64 | ctx.r4.u64;
	// and r8,r8,r22
	ctx.r8.u64 = ctx.r8.u64 & ctx.r22.u64;
	// and r4,r4,r21
	ctx.r4.u64 = ctx.r4.u64 & ctx.r21.u64;
	// andc r29,r15,r24
	ctx.r29.u64 = ctx.r15.u64 & ~ctx.r24.u64;
	// lwz r20,604(r1)
	ctx.r20.u64 = PPC_LOAD_U32(ctx.r1.u32 + 604);
	// lwz r26,612(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 612);
	// andc r30,r30,r20
	ctx.r30.u64 = ctx.r30.u64 & ~ctx.r20.u64;
	// andc r26,r25,r26
	ctx.r26.u64 = ctx.r25.u64 & ~ctx.r26.u64;
	// or r25,r7,r6
	ctx.r25.u64 = ctx.r7.u64 | ctx.r6.u64;
	// or r10,r30,r10
	ctx.r10.u64 = ctx.r30.u64 | ctx.r10.u64;
	// or r9,r26,r9
	ctx.r9.u64 = ctx.r26.u64 | ctx.r9.u64;
	// and r6,r6,r16
	ctx.r6.u64 = ctx.r6.u64 & ctx.r16.u64;
	// andc r30,r18,r25
	ctx.r30.u64 = ctx.r18.u64 & ~ctx.r25.u64;
	// or r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r10,r9,r8
	ctx.r10.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r9,r30,r6
	ctx.r9.u64 = ctx.r30.u64 | ctx.r6.u64;
	// and r8,r7,r17
	ctx.r8.u64 = ctx.r7.u64 & ctx.r17.u64;
	// and r6,r5,r14
	ctx.r6.u64 = ctx.r5.u64 & ctx.r14.u64;
	// or r7,r29,r4
	ctx.r7.u64 = ctx.r29.u64 | ctx.r4.u64;
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// mr r4,r10
	ctx.r4.u64 = ctx.r10.u64;
	// or r11,r9,r8
	ctx.r11.u64 = ctx.r9.u64 | ctx.r8.u64;
	// or r10,r7,r6
	ctx.r10.u64 = ctx.r7.u64 | ctx.r6.u64;
	// lwz r21,164(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 164);
	// lwz r22,160(r1)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r1.u32 + 160);
	// li r16,0
	ctx.r16.s64 = 0;
	// lwz r18,116(r1)
	ctx.r18.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r19,128(r1)
	ctx.r19.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r17,1060(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1060);
	// sth r5,502(r1)
	PPC_STORE_U16(ctx.r1.u32 + 502, ctx.r5.u16);
	// sth r4,500(r1)
	PPC_STORE_U16(ctx.r1.u32 + 500, ctx.r4.u16);
	// sth r11,494(r1)
	PPC_STORE_U16(ctx.r1.u32 + 494, ctx.r11.u16);
	// sth r10,492(r1)
	PPC_STORE_U16(ctx.r1.u32 + 492, ctx.r10.u16);
	// b 0x82b7266c
	goto loc_82B7266C;
loc_82B72640:
	// bne cr6,0x82b72658
	if (!ctx.cr6.eq) goto loc_82B72658;
	// lwz r11,432(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 432);
	// lwz r10,416(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 416);
	// stw r11,500(r1)
	PPC_STORE_U32(ctx.r1.u32 + 500, ctx.r11.u32);
	// stw r10,492(r1)
	PPC_STORE_U32(ctx.r1.u32 + 492, ctx.r10.u32);
	// b 0x82b7266c
	goto loc_82B7266C;
loc_82B72658:
	// lwz r11,1368(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// stw r16,500(r1)
	PPC_STORE_U32(ctx.r1.u32 + 500, ctx.r16.u32);
	// rlwinm r10,r11,17,0,14
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 17) & 0xFFFE0000;
	// subf r9,r10,r20
	ctx.r9.u64 = ctx.r20.u64 - ctx.r10.u64;
	// stw r9,492(r1)
	PPC_STORE_U32(ctx.r1.u32 + 492, ctx.r9.u32);
loc_82B7266C:
	// lwz r11,1396(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1396);
	// lwz r29,180(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 180);
	// lwz r30,620(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 620);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b72690
	if (ctx.cr6.eq) goto loc_82B72690;
	// cmpw cr6,r28,r27
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r27.s32, ctx.xer);
	// ble cr6,0x82b7269c
	if (!ctx.cr6.gt) goto loc_82B7269C;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82b726a0
	if (!ctx.cr6.eq) goto loc_82B726A0;
loc_82B72690:
	// lwz r11,1400(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1400);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b726a0
	if (ctx.cr6.eq) goto loc_82B726A0;
loc_82B7269C:
	// li r3,1
	ctx.r3.s64 = 1;
loc_82B726A0:
	// lwz r11,492(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 492);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82b726b0
	if (!ctx.cr6.eq) goto loc_82B726B0;
	// lwz r11,500(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 500);
loc_82B726B0:
	// stw r11,168(r1)
	PPC_STORE_U32(ctx.r1.u32 + 168, ctx.r11.u32);
	// rlwinm r10,r23,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u32 | (ctx.r23.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r9,728(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 728);
	// stw r11,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r11.u32);
	// add r7,r22,r10
	ctx.r7.u64 = ctx.r22.u64 + ctx.r10.u64;
	// add r6,r23,r9
	ctx.r6.u64 = ctx.r23.u64 + ctx.r9.u64;
	// lwz r28,176(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 176);
	// add r4,r21,r10
	ctx.r4.u64 = ctx.r21.u64 + ctx.r10.u64;
	// lwz r3,172(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 172);
	// rlwinm r11,r6,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// cmpw cr6,r28,r3
	ctx.cr6.compare<int32_t>(ctx.r28.s32, ctx.r3.s32, ctx.xer);
	// add r6,r22,r11
	ctx.r6.u64 = ctx.r22.u64 + ctx.r11.u64;
	// add r5,r21,r11
	ctx.r5.u64 = ctx.r21.u64 + ctx.r11.u64;
	// lhz r9,170(r1)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r1.u32 + 170);
	// lhz r8,168(r1)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r1.u32 + 168);
	// sthx r9,r22,r11
	PPC_STORE_U16(ctx.r22.u32 + ctx.r11.u32, ctx.r9.u16);
	// sth r9,2(r6)
	PPC_STORE_U16(ctx.r6.u32 + 2, ctx.r9.u16);
	// sth r9,2(r7)
	PPC_STORE_U16(ctx.r7.u32 + 2, ctx.r9.u16);
	// sthx r9,r22,r10
	PPC_STORE_U16(ctx.r22.u32 + ctx.r10.u32, ctx.r9.u16);
	// sth r8,2(r5)
	PPC_STORE_U16(ctx.r5.u32 + 2, ctx.r8.u16);
	// sthx r8,r21,r11
	PPC_STORE_U16(ctx.r21.u32 + ctx.r11.u32, ctx.r8.u16);
	// sth r8,2(r4)
	PPC_STORE_U16(ctx.r4.u32 + 2, ctx.r8.u16);
	// sthx r8,r21,r10
	PPC_STORE_U16(ctx.r21.u32 + ctx.r10.u32, ctx.r8.u16);
	// ble cr6,0x82b729a8
	if (!ctx.cr6.gt) goto loc_82B729A8;
	// addi r11,r28,-1
	ctx.r11.s64 = ctx.r28.s64 + -1;
	// li r26,1
	ctx.r26.s64 = 1;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x82b72c94
	if (ctx.cr6.gt) goto loc_82B72C94;
	// lis r12,-32073
	ctx.r12.s64 = -2101936128;
	// addi r12,r12,10040
	ctx.r12.s64 = ctx.r12.s64 + 10040;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82B72748;
	case 1:
		goto loc_82B72754;
	case 2:
		goto loc_82B72780;
	case 3:
		goto loc_82B72804;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82B72748:
	// lwz r29,640(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 640);
	// lwz r30,688(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 688);
	// b 0x82b72c94
	goto loc_82B72C94;
loc_82B72754:
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// lwz r9,640(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 640);
	// lwz r11,692(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 692);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,688(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 688);
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addze r29,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r29.s64 = temp.s64;
	// srawi r6,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 1;
	// addze r30,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r30.s64 = temp.s64;
	// b 0x82b72c94
	goto loc_82B72C94;
loc_82B72780:
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// lwz r11,640(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 640);
	// lwz r9,648(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 648);
	// lwz r6,696(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 696);
	// subf r5,r11,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r8,688(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 688);
	// subf r4,r9,r10
	ctx.r4.u64 = ctx.r10.u64 - ctx.r9.u64;
	// lwz r7,692(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 692);
	// subf r3,r11,r9
	ctx.r3.u64 = ctx.r9.u64 - ctx.r11.u64;
	// xor r4,r4,r5
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r5.u64;
	// subf r30,r8,r7
	ctx.r30.u64 = ctx.r7.u64 - ctx.r8.u64;
	// subf r29,r6,r7
	ctx.r29.u64 = ctx.r7.u64 - ctx.r6.u64;
	// subf r28,r8,r6
	ctx.r28.u64 = ctx.r6.u64 - ctx.r8.u64;
	// xor r3,r3,r5
	ctx.r3.u64 = ctx.r3.u64 ^ ctx.r5.u64;
	// xor r29,r29,r30
	ctx.r29.u64 = ctx.r29.u64 ^ ctx.r30.u64;
	// srawi r5,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r4.s32 >> 31;
	// xor r30,r28,r30
	ctx.r30.u64 = ctx.r28.u64 ^ ctx.r30.u64;
	// srawi r4,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r3.s32 >> 31;
	// srawi r3,r29,31
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r29.s32 >> 31;
	// srawi r30,r30,31
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FFFFFFF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 31;
	// or r29,r4,r5
	ctx.r29.u64 = ctx.r4.u64 | ctx.r5.u64;
	// or r28,r3,r30
	ctx.r28.u64 = ctx.r3.u64 | ctx.r30.u64;
	// and r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 & ctx.r5.u64;
	// andc r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r29.u64;
	// andc r10,r6,r28
	ctx.r10.u64 = ctx.r6.u64 & ~ctx.r28.u64;
	// and r7,r7,r3
	ctx.r7.u64 = ctx.r7.u64 & ctx.r3.u64;
	// or r6,r9,r5
	ctx.r6.u64 = ctx.r9.u64 | ctx.r5.u64;
	// and r5,r4,r11
	ctx.r5.u64 = ctx.r4.u64 & ctx.r11.u64;
	// or r4,r10,r7
	ctx.r4.u64 = ctx.r10.u64 | ctx.r7.u64;
	// and r3,r8,r30
	ctx.r3.u64 = ctx.r8.u64 & ctx.r30.u64;
	// or r29,r6,r5
	ctx.r29.u64 = ctx.r6.u64 | ctx.r5.u64;
	// or r30,r4,r3
	ctx.r30.u64 = ctx.r4.u64 | ctx.r3.u64;
	// b 0x82b72c94
	goto loc_82B72C94;
loc_82B72804:
	// lwz r11,640(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 640);
	// lwz r10,644(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 644);
	// lwz r9,648(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 648);
	// subf r6,r11,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r3,652(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 652);
	// subf r4,r10,r9
	ctx.r4.u64 = ctx.r9.u64 - ctx.r10.u64;
	// lwz r7,692(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 692);
	// subf r30,r9,r11
	ctx.r30.u64 = ctx.r11.u64 - ctx.r9.u64;
	// lwz r8,688(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 688);
	// subf r29,r10,r11
	ctx.r29.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r5,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 31;
	// lwz r6,696(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 696);
	// subf r28,r9,r10
	ctx.r28.u64 = ctx.r10.u64 - ctx.r9.u64;
	// srawi r4,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 31;
	// srawi r30,r30,31
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FFFFFFF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 31;
	// srawi r29,r29,31
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x7FFFFFFF) != 0);
	ctx.r29.s64 = ctx.r29.s32 >> 31;
	// subf r27,r11,r9
	ctx.r27.u64 = ctx.r9.u64 - ctx.r11.u64;
	// srawi r28,r28,31
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x7FFFFFFF) != 0);
	ctx.r28.s64 = ctx.r28.s32 >> 31;
	// not r25,r5
	ctx.r25.u64 = ~ctx.r5.u64;
	// srawi r27,r27,31
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x7FFFFFFF) != 0);
	ctx.r27.s64 = ctx.r27.s32 >> 31;
	// not r28,r28
	ctx.r28.u64 = ~ctx.r28.u64;
	// not r29,r29
	ctx.r29.u64 = ~ctx.r29.u64;
	// and r24,r11,r25
	ctx.r24.u64 = ctx.r11.u64 & ctx.r25.u64;
	// and r23,r9,r28
	ctx.r23.u64 = ctx.r9.u64 & ctx.r28.u64;
	// and r25,r10,r25
	ctx.r25.u64 = ctx.r10.u64 & ctx.r25.u64;
	// not r27,r27
	ctx.r27.u64 = ~ctx.r27.u64;
	// not r30,r30
	ctx.r30.u64 = ~ctx.r30.u64;
	// and r22,r11,r29
	ctx.r22.u64 = ctx.r11.u64 & ctx.r29.u64;
	// and r24,r24,r27
	ctx.r24.u64 = ctx.r24.u64 & ctx.r27.u64;
	// not r21,r4
	ctx.r21.u64 = ~ctx.r4.u64;
	// and r29,r10,r29
	ctx.r29.u64 = ctx.r10.u64 & ctx.r29.u64;
	// and r28,r25,r28
	ctx.r28.u64 = ctx.r25.u64 & ctx.r28.u64;
	// and r23,r23,r30
	ctx.r23.u64 = ctx.r23.u64 & ctx.r30.u64;
	// and r27,r9,r27
	ctx.r27.u64 = ctx.r9.u64 & ctx.r27.u64;
	// and r25,r22,r30
	ctx.r25.u64 = ctx.r22.u64 & ctx.r30.u64;
	// or r24,r24,r23
	ctx.r24.u64 = ctx.r24.u64 | ctx.r23.u64;
	// and r29,r29,r21
	ctx.r29.u64 = ctx.r29.u64 & ctx.r21.u64;
	// or r28,r28,r25
	ctx.r28.u64 = ctx.r28.u64 | ctx.r25.u64;
	// and r27,r27,r21
	ctx.r27.u64 = ctx.r27.u64 & ctx.r21.u64;
	// or r29,r24,r29
	ctx.r29.u64 = ctx.r24.u64 | ctx.r29.u64;
	// or r28,r28,r27
	ctx.r28.u64 = ctx.r28.u64 | ctx.r27.u64;
	// subf r27,r29,r3
	ctx.r27.u64 = ctx.r3.u64 - ctx.r29.u64;
	// subf r25,r3,r28
	ctx.r25.u64 = ctx.r28.u64 - ctx.r3.u64;
	// xor r24,r5,r30
	ctx.r24.u64 = ctx.r5.u64 ^ ctx.r30.u64;
	// xor r23,r5,r21
	ctx.r23.u64 = ctx.r5.u64 ^ ctx.r21.u64;
	// subf r22,r28,r29
	ctx.r22.u64 = ctx.r29.u64 - ctx.r28.u64;
	// srawi r5,r27,31
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r27.s32 >> 31;
	// srawi r27,r25,31
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x7FFFFFFF) != 0);
	ctx.r27.s64 = ctx.r25.s32 >> 31;
	// srawi r25,r22,31
	ctx.xer.ca = (ctx.r22.s32 < 0) & ((ctx.r22.u32 & 0x7FFFFFFF) != 0);
	ctx.r25.s64 = ctx.r22.s32 >> 31;
	// eqv r27,r27,r5
	ctx.r27.u64 = ~(ctx.r27.u64 ^ ctx.r5.u64);
	// eqv r5,r25,r5
	ctx.r5.u64 = ~(ctx.r25.u64 ^ ctx.r5.u64);
	// xor r4,r4,r30
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r30.u64;
	// or r30,r27,r5
	ctx.r30.u64 = ctx.r27.u64 | ctx.r5.u64;
	// and r9,r4,r9
	ctx.r9.u64 = ctx.r4.u64 & ctx.r9.u64;
	// and r5,r29,r5
	ctx.r5.u64 = ctx.r29.u64 & ctx.r5.u64;
	// andc r4,r28,r30
	ctx.r4.u64 = ctx.r28.u64 & ~ctx.r30.u64;
	// and r11,r24,r11
	ctx.r11.u64 = ctx.r24.u64 & ctx.r11.u64;
	// or r5,r4,r5
	ctx.r5.u64 = ctx.r4.u64 | ctx.r5.u64;
	// or r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 | ctx.r11.u64;
	// and r4,r3,r27
	ctx.r4.u64 = ctx.r3.u64 & ctx.r27.u64;
	// and r10,r23,r10
	ctx.r10.u64 = ctx.r23.u64 & ctx.r10.u64;
	// or r11,r5,r4
	ctx.r11.u64 = ctx.r5.u64 | ctx.r4.u64;
	// or r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 | ctx.r10.u64;
	// subf r3,r8,r7
	ctx.r3.u64 = ctx.r7.u64 - ctx.r8.u64;
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf r10,r7,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r7.u64;
	// srawi r9,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 1;
	// subf r5,r6,r8
	ctx.r5.u64 = ctx.r8.u64 - ctx.r6.u64;
	// addze r29,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r29.s64 = temp.s64;
	// srawi r11,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r3.s32 >> 31;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 31;
	// not r3,r10
	ctx.r3.u64 = ~ctx.r10.u64;
	// not r30,r9
	ctx.r30.u64 = ~ctx.r9.u64;
	// xor r9,r11,r3
	ctx.r9.u64 = ctx.r11.u64 ^ ctx.r3.u64;
	// xor r5,r10,r30
	ctx.r5.u64 = ctx.r10.u64 ^ ctx.r30.u64;
	// and r28,r9,r7
	ctx.r28.u64 = ctx.r9.u64 & ctx.r7.u64;
	// and r27,r5,r6
	ctx.r27.u64 = ctx.r5.u64 & ctx.r6.u64;
	// xor r25,r11,r30
	ctx.r25.u64 = ctx.r11.u64 ^ ctx.r30.u64;
	// subf r4,r7,r8
	ctx.r4.u64 = ctx.r8.u64 - ctx.r7.u64;
	// subf r5,r6,r7
	ctx.r5.u64 = ctx.r7.u64 - ctx.r6.u64;
	// subf r24,r8,r6
	ctx.r24.u64 = ctx.r6.u64 - ctx.r8.u64;
	// lwz r10,700(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 700);
	// srawi r9,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 31;
	// srawi r5,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 31;
	// srawi r4,r24,31
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r24.s32 >> 31;
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// not r9,r9
	ctx.r9.u64 = ~ctx.r9.u64;
	// not r4,r4
	ctx.r4.u64 = ~ctx.r4.u64;
	// and r24,r8,r11
	ctx.r24.u64 = ctx.r8.u64 & ctx.r11.u64;
	// and r23,r7,r9
	ctx.r23.u64 = ctx.r7.u64 & ctx.r9.u64;
	// and r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 & ctx.r11.u64;
	// not r5,r5
	ctx.r5.u64 = ~ctx.r5.u64;
	// and r7,r6,r4
	ctx.r7.u64 = ctx.r6.u64 & ctx.r4.u64;
	// and r4,r24,r4
	ctx.r4.u64 = ctx.r24.u64 & ctx.r4.u64;
	// and r6,r6,r5
	ctx.r6.u64 = ctx.r6.u64 & ctx.r5.u64;
	// and r24,r23,r3
	ctx.r24.u64 = ctx.r23.u64 & ctx.r3.u64;
	// and r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 & ctx.r5.u64;
	// and r3,r7,r3
	ctx.r3.u64 = ctx.r7.u64 & ctx.r3.u64;
	// and r11,r8,r9
	ctx.r11.u64 = ctx.r8.u64 & ctx.r9.u64;
	// and r7,r6,r30
	ctx.r7.u64 = ctx.r6.u64 & ctx.r30.u64;
	// or r6,r5,r3
	ctx.r6.u64 = ctx.r5.u64 | ctx.r3.u64;
	// or r9,r4,r24
	ctx.r9.u64 = ctx.r4.u64 | ctx.r24.u64;
	// and r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 & ctx.r30.u64;
	// b 0x82b72c3c
	goto loc_82B72C3C;
loc_82B729A8:
	// addi r11,r3,-1
	ctx.r11.s64 = ctx.r3.s64 + -1;
	// mr r26,r16
	ctx.r26.u64 = ctx.r16.u64;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bgt cr6,0x82b72c94
	if (ctx.cr6.gt) goto loc_82B72C94;
	// lis r12,-32073
	ctx.r12.s64 = -2101936128;
	// addi r12,r12,10704
	ctx.r12.s64 = ctx.r12.s64 + 10704;
	// rlwinm r0,r11,2,0,29
	ctx.r0.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r0,r12,r0
	ctx.r0.u64 = PPC_LOAD_U32(ctx.r12.u32 + ctx.r0.u32);
	// mtctr r0
	ctx.ctr.u64 = ctx.r0.u64;
	// bctr 
	switch (ctx.r11.u32) {
	case 0:
		goto loc_82B729E0;
	case 1:
		goto loc_82B729EC;
	case 2:
		goto loc_82B72A18;
	case 3:
		goto loc_82B72A9C;
	default:
		__builtin_trap(); // Switch case out of range
	}
loc_82B729E0:
	// lwz r29,656(r1)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r1.u32 + 656);
	// lwz r30,672(r1)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r1.u32 + 672);
	// b 0x82b72c94
	goto loc_82B72C94;
loc_82B729EC:
	// lwz r10,660(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 660);
	// lwz r9,656(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 656);
	// lwz r11,676(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 676);
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lwz r10,672(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 672);
	// srawi r8,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 1;
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addze r29,r8
	temp.s64 = ctx.r8.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r8.u32;
	ctx.r29.s64 = temp.s64;
	// srawi r6,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r6.s64 = ctx.r7.s32 >> 1;
	// addze r30,r6
	temp.s64 = ctx.r6.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r6.u32;
	ctx.r30.s64 = temp.s64;
	// b 0x82b72c94
	goto loc_82B72C94;
loc_82B72A18:
	// lwz r10,660(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 660);
	// lwz r11,656(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 656);
	// lwz r9,664(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 664);
	// lwz r6,680(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 680);
	// subf r5,r11,r10
	ctx.r5.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r8,672(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 672);
	// subf r4,r9,r10
	ctx.r4.u64 = ctx.r10.u64 - ctx.r9.u64;
	// lwz r7,676(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 676);
	// subf r3,r11,r9
	ctx.r3.u64 = ctx.r9.u64 - ctx.r11.u64;
	// xor r4,r4,r5
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r5.u64;
	// subf r30,r8,r7
	ctx.r30.u64 = ctx.r7.u64 - ctx.r8.u64;
	// subf r29,r6,r7
	ctx.r29.u64 = ctx.r7.u64 - ctx.r6.u64;
	// subf r28,r8,r6
	ctx.r28.u64 = ctx.r6.u64 - ctx.r8.u64;
	// xor r3,r3,r5
	ctx.r3.u64 = ctx.r3.u64 ^ ctx.r5.u64;
	// xor r29,r29,r30
	ctx.r29.u64 = ctx.r29.u64 ^ ctx.r30.u64;
	// srawi r5,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r4.s32 >> 31;
	// xor r30,r28,r30
	ctx.r30.u64 = ctx.r28.u64 ^ ctx.r30.u64;
	// srawi r4,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r3.s32 >> 31;
	// srawi r3,r29,31
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x7FFFFFFF) != 0);
	ctx.r3.s64 = ctx.r29.s32 >> 31;
	// srawi r30,r30,31
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FFFFFFF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 31;
	// or r29,r5,r4
	ctx.r29.u64 = ctx.r5.u64 | ctx.r4.u64;
	// or r28,r3,r30
	ctx.r28.u64 = ctx.r3.u64 | ctx.r30.u64;
	// and r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 & ctx.r5.u64;
	// andc r9,r9,r29
	ctx.r9.u64 = ctx.r9.u64 & ~ctx.r29.u64;
	// andc r10,r6,r28
	ctx.r10.u64 = ctx.r6.u64 & ~ctx.r28.u64;
	// and r7,r7,r3
	ctx.r7.u64 = ctx.r7.u64 & ctx.r3.u64;
	// or r6,r9,r5
	ctx.r6.u64 = ctx.r9.u64 | ctx.r5.u64;
	// and r5,r11,r4
	ctx.r5.u64 = ctx.r11.u64 & ctx.r4.u64;
	// or r4,r10,r7
	ctx.r4.u64 = ctx.r10.u64 | ctx.r7.u64;
	// and r3,r8,r30
	ctx.r3.u64 = ctx.r8.u64 & ctx.r30.u64;
	// or r29,r6,r5
	ctx.r29.u64 = ctx.r6.u64 | ctx.r5.u64;
	// or r30,r4,r3
	ctx.r30.u64 = ctx.r4.u64 | ctx.r3.u64;
	// b 0x82b72c94
	goto loc_82B72C94;
loc_82B72A9C:
	// lwz r11,656(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 656);
	// lwz r10,660(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 660);
	// lwz r9,664(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 664);
	// subf r6,r11,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r3,668(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 668);
	// subf r4,r10,r9
	ctx.r4.u64 = ctx.r9.u64 - ctx.r10.u64;
	// lwz r7,676(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 676);
	// subf r30,r9,r11
	ctx.r30.u64 = ctx.r11.u64 - ctx.r9.u64;
	// lwz r8,672(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 672);
	// subf r29,r10,r11
	ctx.r29.u64 = ctx.r11.u64 - ctx.r10.u64;
	// srawi r5,r6,31
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 31;
	// lwz r6,680(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 680);
	// subf r28,r9,r10
	ctx.r28.u64 = ctx.r10.u64 - ctx.r9.u64;
	// srawi r4,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r4.s32 >> 31;
	// subf r27,r11,r9
	ctx.r27.u64 = ctx.r9.u64 - ctx.r11.u64;
	// srawi r30,r30,31
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x7FFFFFFF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 31;
	// srawi r29,r29,31
	ctx.xer.ca = (ctx.r29.s32 < 0) & ((ctx.r29.u32 & 0x7FFFFFFF) != 0);
	ctx.r29.s64 = ctx.r29.s32 >> 31;
	// srawi r28,r28,31
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x7FFFFFFF) != 0);
	ctx.r28.s64 = ctx.r28.s32 >> 31;
	// srawi r27,r27,31
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x7FFFFFFF) != 0);
	ctx.r27.s64 = ctx.r27.s32 >> 31;
	// not r25,r5
	ctx.r25.u64 = ~ctx.r5.u64;
	// not r29,r29
	ctx.r29.u64 = ~ctx.r29.u64;
	// not r27,r27
	ctx.r27.u64 = ~ctx.r27.u64;
	// and r23,r11,r25
	ctx.r23.u64 = ctx.r11.u64 & ctx.r25.u64;
	// and r22,r10,r29
	ctx.r22.u64 = ctx.r10.u64 & ctx.r29.u64;
	// not r24,r4
	ctx.r24.u64 = ~ctx.r4.u64;
	// not r28,r28
	ctx.r28.u64 = ~ctx.r28.u64;
	// and r25,r10,r25
	ctx.r25.u64 = ctx.r10.u64 & ctx.r25.u64;
	// and r21,r9,r27
	ctx.r21.u64 = ctx.r9.u64 & ctx.r27.u64;
	// and r27,r23,r27
	ctx.r27.u64 = ctx.r23.u64 & ctx.r27.u64;
	// and r20,r9,r28
	ctx.r20.u64 = ctx.r9.u64 & ctx.r28.u64;
	// and r23,r22,r24
	ctx.r23.u64 = ctx.r22.u64 & ctx.r24.u64;
	// and r28,r25,r28
	ctx.r28.u64 = ctx.r25.u64 & ctx.r28.u64;
	// not r30,r30
	ctx.r30.u64 = ~ctx.r30.u64;
	// and r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 & ctx.r29.u64;
	// and r25,r21,r24
	ctx.r25.u64 = ctx.r21.u64 & ctx.r24.u64;
	// or r27,r27,r23
	ctx.r27.u64 = ctx.r27.u64 | ctx.r23.u64;
	// and r23,r20,r30
	ctx.r23.u64 = ctx.r20.u64 & ctx.r30.u64;
	// or r28,r28,r25
	ctx.r28.u64 = ctx.r28.u64 | ctx.r25.u64;
	// and r29,r29,r30
	ctx.r29.u64 = ctx.r29.u64 & ctx.r30.u64;
	// or r27,r27,r23
	ctx.r27.u64 = ctx.r27.u64 | ctx.r23.u64;
	// or r29,r28,r29
	ctx.r29.u64 = ctx.r28.u64 | ctx.r29.u64;
	// subf r28,r27,r3
	ctx.r28.u64 = ctx.r3.u64 - ctx.r27.u64;
	// subf r25,r3,r29
	ctx.r25.u64 = ctx.r29.u64 - ctx.r3.u64;
	// xor r23,r5,r30
	ctx.r23.u64 = ctx.r5.u64 ^ ctx.r30.u64;
	// xor r24,r5,r24
	ctx.r24.u64 = ctx.r5.u64 ^ ctx.r24.u64;
	// subf r22,r29,r27
	ctx.r22.u64 = ctx.r27.u64 - ctx.r29.u64;
	// srawi r5,r28,31
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r28.s32 >> 31;
	// srawi r28,r25,31
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x7FFFFFFF) != 0);
	ctx.r28.s64 = ctx.r25.s32 >> 31;
	// srawi r25,r22,31
	ctx.xer.ca = (ctx.r22.s32 < 0) & ((ctx.r22.u32 & 0x7FFFFFFF) != 0);
	ctx.r25.s64 = ctx.r22.s32 >> 31;
	// eqv r28,r28,r5
	ctx.r28.u64 = ~(ctx.r28.u64 ^ ctx.r5.u64);
	// eqv r5,r25,r5
	ctx.r5.u64 = ~(ctx.r25.u64 ^ ctx.r5.u64);
	// xor r4,r4,r30
	ctx.r4.u64 = ctx.r4.u64 ^ ctx.r30.u64;
	// or r30,r28,r5
	ctx.r30.u64 = ctx.r28.u64 | ctx.r5.u64;
	// and r9,r4,r9
	ctx.r9.u64 = ctx.r4.u64 & ctx.r9.u64;
	// and r10,r24,r10
	ctx.r10.u64 = ctx.r24.u64 & ctx.r10.u64;
	// andc r4,r29,r30
	ctx.r4.u64 = ctx.r29.u64 & ~ctx.r30.u64;
	// and r3,r3,r28
	ctx.r3.u64 = ctx.r3.u64 & ctx.r28.u64;
	// or r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 | ctx.r9.u64;
	// and r11,r23,r11
	ctx.r11.u64 = ctx.r23.u64 & ctx.r11.u64;
	// or r9,r4,r3
	ctx.r9.u64 = ctx.r4.u64 | ctx.r3.u64;
	// and r5,r27,r5
	ctx.r5.u64 = ctx.r27.u64 & ctx.r5.u64;
	// or r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 | ctx.r11.u64;
	// or r11,r9,r5
	ctx.r11.u64 = ctx.r9.u64 | ctx.r5.u64;
	// subf r4,r8,r7
	ctx.r4.u64 = ctx.r7.u64 - ctx.r8.u64;
	// add r3,r11,r10
	ctx.r3.u64 = ctx.r11.u64 + ctx.r10.u64;
	// subf r10,r7,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r7.u64;
	// srawi r9,r3,1
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 1;
	// subf r5,r6,r8
	ctx.r5.u64 = ctx.r8.u64 - ctx.r6.u64;
	// addze r29,r9
	temp.s64 = ctx.r9.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r9.u32;
	ctx.r29.s64 = temp.s64;
	// srawi r11,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r4.s32 >> 31;
	// srawi r10,r10,31
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x7FFFFFFF) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 31;
	// srawi r9,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r5.s32 >> 31;
	// not r3,r10
	ctx.r3.u64 = ~ctx.r10.u64;
	// not r30,r9
	ctx.r30.u64 = ~ctx.r9.u64;
	// xor r9,r11,r3
	ctx.r9.u64 = ctx.r11.u64 ^ ctx.r3.u64;
	// xor r5,r10,r30
	ctx.r5.u64 = ctx.r10.u64 ^ ctx.r30.u64;
	// and r28,r9,r7
	ctx.r28.u64 = ctx.r9.u64 & ctx.r7.u64;
	// and r27,r5,r6
	ctx.r27.u64 = ctx.r5.u64 & ctx.r6.u64;
	// xor r25,r11,r30
	ctx.r25.u64 = ctx.r11.u64 ^ ctx.r30.u64;
	// subf r4,r7,r8
	ctx.r4.u64 = ctx.r8.u64 - ctx.r7.u64;
	// subf r5,r6,r7
	ctx.r5.u64 = ctx.r7.u64 - ctx.r6.u64;
	// subf r24,r8,r6
	ctx.r24.u64 = ctx.r6.u64 - ctx.r8.u64;
	// lwz r10,684(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 684);
	// srawi r9,r4,31
	ctx.xer.ca = (ctx.r4.s32 < 0) & ((ctx.r4.u32 & 0x7FFFFFFF) != 0);
	ctx.r9.s64 = ctx.r4.s32 >> 31;
	// srawi r5,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 31;
	// srawi r4,r24,31
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r24.s32 >> 31;
	// not r5,r5
	ctx.r5.u64 = ~ctx.r5.u64;
	// not r9,r9
	ctx.r9.u64 = ~ctx.r9.u64;
	// not r4,r4
	ctx.r4.u64 = ~ctx.r4.u64;
	// and r23,r6,r5
	ctx.r23.u64 = ctx.r6.u64 & ctx.r5.u64;
	// and r24,r7,r9
	ctx.r24.u64 = ctx.r7.u64 & ctx.r9.u64;
	// not r11,r11
	ctx.r11.u64 = ~ctx.r11.u64;
	// and r6,r6,r4
	ctx.r6.u64 = ctx.r6.u64 & ctx.r4.u64;
	// and r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 & ctx.r9.u64;
	// and r24,r24,r3
	ctx.r24.u64 = ctx.r24.u64 & ctx.r3.u64;
	// and r22,r8,r11
	ctx.r22.u64 = ctx.r8.u64 & ctx.r11.u64;
	// and r6,r6,r3
	ctx.r6.u64 = ctx.r6.u64 & ctx.r3.u64;
	// and r3,r9,r30
	ctx.r3.u64 = ctx.r9.u64 & ctx.r30.u64;
	// and r11,r7,r11
	ctx.r11.u64 = ctx.r7.u64 & ctx.r11.u64;
	// and r23,r23,r30
	ctx.r23.u64 = ctx.r23.u64 & ctx.r30.u64;
	// and r7,r22,r4
	ctx.r7.u64 = ctx.r22.u64 & ctx.r4.u64;
	// or r9,r24,r23
	ctx.r9.u64 = ctx.r24.u64 | ctx.r23.u64;
	// or r6,r6,r3
	ctx.r6.u64 = ctx.r6.u64 | ctx.r3.u64;
	// and r5,r11,r5
	ctx.r5.u64 = ctx.r11.u64 & ctx.r5.u64;
loc_82B72C3C:
	// or r4,r9,r7
	ctx.r4.u64 = ctx.r9.u64 | ctx.r7.u64;
	// or r3,r6,r5
	ctx.r3.u64 = ctx.r6.u64 | ctx.r5.u64;
	// subf r11,r4,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r4.u64;
	// subf r9,r10,r3
	ctx.r9.u64 = ctx.r3.u64 - ctx.r10.u64;
	// subf r7,r3,r4
	ctx.r7.u64 = ctx.r4.u64 - ctx.r3.u64;
	// srawi r11,r11,31
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x7FFFFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 31;
	// srawi r6,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 31;
	// srawi r5,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r7.s32 >> 31;
	// eqv r9,r6,r11
	ctx.r9.u64 = ~(ctx.r6.u64 ^ ctx.r11.u64);
	// eqv r7,r5,r11
	ctx.r7.u64 = ~(ctx.r5.u64 ^ ctx.r11.u64);
	// and r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 & ctx.r9.u64;
	// or r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 | ctx.r7.u64;
	// and r9,r25,r8
	ctx.r9.u64 = ctx.r25.u64 & ctx.r8.u64;
	// andc r10,r3,r5
	ctx.r10.u64 = ctx.r3.u64 & ~ctx.r5.u64;
	// and r8,r4,r7
	ctx.r8.u64 = ctx.r4.u64 & ctx.r7.u64;
	// or r11,r28,r27
	ctx.r11.u64 = ctx.r28.u64 | ctx.r27.u64;
	// or r7,r10,r6
	ctx.r7.u64 = ctx.r10.u64 | ctx.r6.u64;
	// or r10,r11,r9
	ctx.r10.u64 = ctx.r11.u64 | ctx.r9.u64;
	// or r11,r7,r8
	ctx.r11.u64 = ctx.r7.u64 | ctx.r8.u64;
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// srawi r5,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r5.s64 = ctx.r6.s32 >> 1;
	// addze r30,r5
	temp.s64 = ctx.r5.s64 + ctx.xer.ca;
	ctx.xer.ca = temp.u32 < ctx.r5.u32;
	ctx.r30.s64 = temp.s64;
loc_82B72C94:
	// clrlwi r10,r29,30
	ctx.r10.u64 = ctx.r29.u32 & 0x3;
	// lbz r9,31(r31)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r31.u32 + 31);
	// clrlwi r11,r30,30
	ctx.r11.u64 = ctx.r30.u32 & 0x3;
	// addi r8,r10,1
	ctx.r8.s64 = ctx.r10.s64 + 1;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// srawi r11,r8,2
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r8.s32 >> 2;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// add r6,r11,r29
	ctx.r6.u64 = ctx.r11.u64 + ctx.r29.u64;
	// srawi r9,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r6.s32 >> 1;
	// srawi r11,r7,2
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r7.s32 >> 2;
	// stw r9,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r9.u32);
	// add r5,r11,r30
	ctx.r5.u64 = ctx.r11.u64 + ctx.r30.u64;
	// srawi r11,r5,1
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r5.s32 >> 1;
	// beq cr6,0x82b72d10
	if (ctx.cr6.eq) goto loc_82B72D10;
	// clrlwi r10,r9,31
	ctx.r10.u64 = ctx.r9.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82b72cf0
	if (ctx.cr6.eq) goto loc_82B72CF0;
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// ble cr6,0x82b72ce8
	if (!ctx.cr6.gt) goto loc_82B72CE8;
	// addi r9,r9,-1
	ctx.r9.s64 = ctx.r9.s64 + -1;
	// b 0x82b72cec
	goto loc_82B72CEC;
loc_82B72CE8:
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
loc_82B72CEC:
	// stw r9,180(r1)
	PPC_STORE_U32(ctx.r1.u32 + 180, ctx.r9.u32);
loc_82B72CF0:
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82b72d10
	if (ctx.cr6.eq) goto loc_82B72D10;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82b72d0c
	if (!ctx.cr6.gt) goto loc_82B72D0C;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// b 0x82b72d10
	goto loc_82B72D10;
loc_82B72D0C:
	// addi r11,r11,1
	ctx.r11.s64 = ctx.r11.s64 + 1;
loc_82B72D10:
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// beq cr6,0x82b72d28
	if (ctx.cr6.eq) goto loc_82B72D28;
	// lwz r10,1368(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1368);
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,-2
	ctx.r11.s64 = ctx.r11.s64 + -2;
loc_82B72D28:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r10,4(r17)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r17.u32 + 4);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// lwz r8,352(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 352);
	// add r11,r11,r26
	ctx.r11.u64 = ctx.r11.u64 + ctx.r26.u64;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r11,16,0,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// srawi r11,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 1;
	// or r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 | ctx.r7.u64;
	// rlwinm r3,r11,16,0,15
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// stw r11,620(r1)
	PPC_STORE_U32(ctx.r1.u32 + 620, ctx.r11.u32);
	// stwx r4,r6,r8
	PPC_STORE_U32(ctx.r6.u32 + ctx.r8.u32, ctx.r4.u32);
	// rlwinm r10,r19,16,0,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 16) & 0xFFFF0000;
	// or r11,r3,r7
	ctx.r11.u64 = ctx.r3.u64 | ctx.r7.u64;
	// or r9,r10,r18
	ctx.r9.u64 = ctx.r10.u64 | ctx.r18.u64;
	// rlwinm r8,r11,1,15,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x10000;
	// rlwinm r10,r9,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r9,r8,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r8.u64;
	// add r7,r9,r10
	ctx.r7.u64 = ctx.r9.u64 + ctx.r10.u64;
	// addis r6,r7,24
	ctx.r6.s64 = ctx.r7.s64 + 1572864;
	// addi r6,r6,20
	ctx.r6.s64 = ctx.r6.s64 + 20;
	// lwz r5,316(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 316);
	// subf r4,r11,r5
	ctx.r4.u64 = ctx.r5.u64 - ctx.r11.u64;
	// subf r3,r10,r4
	ctx.r3.u64 = ctx.r4.u64 - ctx.r10.u64;
	// or r10,r6,r3
	ctx.r10.u64 = ctx.r6.u64 | ctx.r3.u64;
	// rlwinm r9,r10,0,0,16
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r9,r9,0,16,0
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// beq cr6,0x82b72e2c
	if (ctx.cr6.eq) goto loc_82B72E2C;
	// srawi r9,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 16;
	// lhz r7,52(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 52);
	// extsh r11,r11
	ctx.r11.s64 = ctx.r11.s16;
	// lhz r5,50(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// rlwinm r8,r18,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r18.u32 | (ctx.r18.u64 << 32), 3) & 0xFFFFFFF8;
	// srawi r10,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 2;
	// rotlwi r6,r7,2
	ctx.r6.u64 = __builtin_rotateleft32(ctx.r7.u32, 2);
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// srawi r8,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r9.s32 >> 2;
	// rlwinm r7,r19,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r19.u32 | (ctx.r19.u64 << 32), 3) & 0xFFFFFFF8;
	// rotlwi r5,r5,2
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r5.u32, 2);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// cmpwi cr6,r10,-8
	ctx.cr6.compare<int32_t>(ctx.r10.s32, -8, ctx.xer);
	// bge cr6,0x82b72de8
	if (!ctx.cr6.lt) goto loc_82B72DE8;
	// addi r10,r10,8
	ctx.r10.s64 = ctx.r10.s64 + 8;
	// rlwinm r7,r10,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r11,r7,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r7.u64;
	// b 0x82b72dfc
	goto loc_82B72DFC;
loc_82B72DE8:
	// cmpw cr6,r10,r5
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r5.s32, ctx.xer);
	// ble cr6,0x82b72dfc
	if (!ctx.cr6.gt) goto loc_82B72DFC;
	// subf r10,r10,r5
	ctx.r10.u64 = ctx.r5.u64 - ctx.r10.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
loc_82B72DFC:
	// cmpwi cr6,r8,-9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, -9, ctx.xer);
	// bge cr6,0x82b72e14
	if (!ctx.cr6.lt) goto loc_82B72E14;
	// addi r10,r8,9
	ctx.r10.s64 = ctx.r8.s64 + 9;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r9,r8,r9
	ctx.r9.u64 = ctx.r9.u64 - ctx.r8.u64;
	// b 0x82b72e28
	goto loc_82B72E28;
loc_82B72E14:
	// cmpw cr6,r8,r6
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r6.s32, ctx.xer);
	// ble cr6,0x82b72e28
	if (!ctx.cr6.gt) goto loc_82B72E28;
	// subf r10,r8,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r8.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
loc_82B72E28:
	// rlwimi r11,r9,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
loc_82B72E2C:
	// srawi r9,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r9.s64 = ctx.r11.s32 >> 16;
	// lhz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 92);
	// extsh r10,r11
	ctx.r10.s64 = ctx.r11.s16;
	// lwz r8,12(r17)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r17.u32 + 12);
	// srawi r5,r9,2
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3) != 0);
	ctx.r5.s64 = ctx.r9.s32 >> 2;
	// lwz r6,100(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// srawi r7,r10,2
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x3) != 0);
	ctx.r7.s64 = ctx.r10.s32 >> 2;
	// mullw r11,r5,r4
	ctx.r11.s64 = int64_t(ctx.r5.s32) * int64_t(ctx.r4.s32);
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// cmpwi cr6,r6,4
	ctx.cr6.compare<int32_t>(ctx.r6.s32, 4, ctx.xer);
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// bne cr6,0x82b72e7c
	if (!ctx.cr6.eq) goto loc_82B72E7C;
	// cmpwi cr6,r26,1
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 1, ctx.xer);
	// bne cr6,0x82b72e70
	if (!ctx.cr6.eq) goto loc_82B72E70;
	// lwz r6,504(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 504);
	// lwz r7,508(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 508);
	// b 0x82b72e98
	goto loc_82B72E98;
loc_82B72E70:
	// lwz r6,480(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 480);
	// lwz r7,484(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 484);
	// b 0x82b72e98
	goto loc_82B72E98;
loc_82B72E7C:
	// cmpwi cr6,r26,1
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 1, ctx.xer);
	// bne cr6,0x82b72e90
	if (!ctx.cr6.eq) goto loc_82B72E90;
	// lwz r6,552(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 552);
	// lwz r7,556(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 556);
	// b 0x82b72e98
	goto loc_82B72E98;
loc_82B72E90:
	// lwz r6,528(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 528);
	// lwz r7,532(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 532);
loc_82B72E98:
	// add r30,r7,r11
	ctx.r30.u64 = ctx.r7.u64 + ctx.r11.u64;
	// add r3,r6,r11
	ctx.r3.u64 = ctx.r6.u64 + ctx.r11.u64;
	// lwz r11,580(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 580);
	// li r7,128
	ctx.r7.s64 = 128;
	// add r28,r11,r8
	ctx.r28.u64 = ctx.r11.u64 + ctx.r8.u64;
	// dcbt r7,r3
	// addi r6,r4,128
	ctx.r6.s64 = ctx.r4.s64 + 128;
	// dcbt r6,r3
	// addi r5,r4,64
	ctx.r5.s64 = ctx.r4.s64 + 64;
	// rlwinm r11,r5,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r11,r3
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// dcbt r7,r3
	// addi r6,r4,32
	ctx.r6.s64 = ctx.r4.s64 + 32;
	// rlwinm r5,r6,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r5,r3
	// rlwinm r11,r4,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r3
	// rlwinm r11,r4,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// add r7,r4,r11
	ctx.r7.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// dcbt r6,r3
	// rlwinm r5,r4,3,0,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// subf r11,r4,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r4.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r3
	// clrlwi r10,r10,30
	ctx.r10.u64 = ctx.r10.u32 & 0x3;
	// lwz r11,576(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 576);
	// clrlwi r9,r9,30
	ctx.r9.u64 = ctx.r9.u32 & 0x3;
	// addi r10,r10,56
	ctx.r10.s64 = ctx.r10.s64 + 56;
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// li r7,0
	ctx.r7.s64 = 0;
	// add r9,r10,r9
	ctx.r9.u64 = ctx.r10.u64 + ctx.r9.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// rlwinm r29,r9,2,0,29
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r29,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r31.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82B72F48;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lhz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 92);
	// li r7,128
	ctx.r7.s64 = 128;
	// dcbt r7,r30
	// addi r6,r4,128
	ctx.r6.s64 = ctx.r4.s64 + 128;
	// dcbt r6,r30
	// addi r5,r4,64
	ctx.r5.s64 = ctx.r4.s64 + 64;
	// rlwinm r3,r5,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// dcbt r3,r30
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r11,r11,128
	ctx.r11.s64 = ctx.r11.s64 + 128;
	// dcbt r11,r30
	// addi r10,r4,32
	ctx.r10.s64 = ctx.r4.s64 + 32;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// dcbt r9,r30
	// rotlwi r11,r4,2
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 2);
	// add r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 + ctx.r11.u64;
	// addi r8,r11,128
	ctx.r8.s64 = ctx.r11.s64 + 128;
	// dcbt r8,r30
	// rotlwi r11,r4,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r4.u32, 1);
	// add r7,r4,r11
	ctx.r7.u64 = ctx.r4.u64 + ctx.r11.u64;
	// rlwinm r11,r7,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r6,r11,128
	ctx.r6.s64 = ctx.r11.s64 + 128;
	// dcbt r6,r30
	// rotlwi r5,r4,3
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r4.u32, 3);
	// subf r11,r4,r5
	ctx.r11.u64 = ctx.r5.u64 - ctx.r4.u64;
	// addi r3,r11,128
	ctx.r3.s64 = ctx.r11.s64 + 128;
	// dcbt r3,r30
	// lwzx r11,r29,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r29.u32 + ctx.r31.u32);
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r28
	ctx.r5.u64 = ctx.r28.u64;
	// mr r3,r30
	ctx.r3.u64 = ctx.r30.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B72FD4;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r15,104(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// lwz r14,108(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
loc_82B72FDC:
	// lwz r8,1060(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1060);
	// lwz r11,116(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r10,444(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 444);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// lwz r9,636(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 636);
	// addi r6,r10,24
	ctx.r6.s64 = ctx.r10.s64 + 24;
	// lhz r10,18(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 18);
	// cmplw cr6,r7,r9
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, ctx.r9.u32, ctx.xer);
	// lwz r11,0(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// lwz r9,4(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// addi r4,r11,2
	ctx.r4.s64 = ctx.r11.s64 + 2;
	// lwz r10,8(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r11,12(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// addi r3,r9,1
	ctx.r3.s64 = ctx.r9.s64 + 1;
	// stw r7,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r7.u32);
	// addi r7,r10,16
	ctx.r7.s64 = ctx.r10.s64 + 16;
	// stw r6,444(r1)
	PPC_STORE_U32(ctx.r1.u32 + 444, ctx.r6.u32);
	// addi r6,r11,8
	ctx.r6.s64 = ctx.r11.s64 + 8;
	// stw r4,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r4.u32);
	// stw r3,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r3.u32);
	// sth r5,18(r8)
	PPC_STORE_U16(ctx.r8.u32 + 18, ctx.r5.u16);
	// stw r7,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r7.u32);
	// stw r6,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r6.u32);
	// blt cr6,0x82b6d87c
	if (ctx.cr6.lt) goto loc_82B6D87C;
loc_82B73040:
	// lwz r9,1060(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 1060);
	// lwz r11,128(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r7,592(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 592);
	// addi r8,r11,1
	ctx.r8.s64 = ctx.r11.s64 + 1;
	// lwz r5,712(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 712);
	// lwz r6,596(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 596);
	// lhz r11,16(r9)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 16);
	// add r4,r5,r7
	ctx.r4.u64 = ctx.r5.u64 + ctx.r7.u64;
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r5,r11,2
	ctx.r5.s64 = ctx.r11.s64 + 2;
	// lwz r11,724(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 724);
	// lwz r7,716(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 716);
	// sth r5,16(r9)
	PPC_STORE_U16(ctx.r9.u32 + 16, ctx.r5.u16);
	// add r3,r11,r6
	ctx.r3.u64 = ctx.r11.u64 + ctx.r6.u64;
	// stw r8,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r8.u32);
	// cmplw cr6,r8,r7
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, ctx.r7.u32, ctx.xer);
	// stw r4,592(r1)
	PPC_STORE_U32(ctx.r1.u32 + 592, ctx.r4.u32);
	// stw r3,596(r1)
	PPC_STORE_U32(ctx.r1.u32 + 596, ctx.r3.u32);
	// lhz r11,50(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r11,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r11.u32);
	// blt cr6,0x82b6d850
	if (ctx.cr6.lt) goto loc_82B6D850;
loc_82B73098:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,1024
	ctx.r1.s64 = ctx.r1.s64 + 1024;
	// b 0x82ae1640
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82B73200"))) PPC_WEAK_FUNC(sub_82B73200);
PPC_FUNC_IMPL(__imp__sub_82B73200) {
	PPC_FUNC_PROLOGUE();
	// std r31,-8(r1)
	PPC_STORE_U64(ctx.r1.u32 + -8, ctx.r31.u64);
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// li r5,0
	ctx.r5.s64 = 0;
	// lhz r10,52(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 52);
	// lhz r9,50(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 50);
	// rlwinm r4,r10,31,1,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r11,1316(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 1316);
	// rlwinm r7,r9,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r4,0
	ctx.cr6.compare<uint32_t>(ctx.r4.u32, 0, ctx.xer);
	// beq cr6,0x82b732b4
	if (ctx.cr6.eq) goto loc_82B732B4;
	// lis r10,-32070
	ctx.r10.s64 = -2101739520;
	// addi r6,r10,-14520
	ctx.r6.s64 = ctx.r10.s64 + -14520;
loc_82B73230:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82b732a8
	if (ctx.cr6.eq) goto loc_82B732A8;
	// cntlzw r9,r5
	ctx.r9.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// rlwinm r8,r9,28,30,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 28) & 0x2;
loc_82B73244:
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// li r12,3855
	ctx.r12.s64 = 3855;
	// rlwinm r9,r9,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// rldicr r12,r12,32,31
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 32) & 0xFFFFFFFF00000000;
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
	// oris r12,r12,3855
	ctx.r12.u64 = ctx.r12.u64 | 252641280;
	// rlwinm r9,r3,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// ori r12,r12,3855
	ctx.r12.u64 = ctx.r12.u64 | 3855;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// ldx r3,r9,r6
	ctx.r3.u64 = PPC_LOAD_U64(ctx.r9.u32 + ctx.r6.u32);
	// and r9,r3,r12
	ctx.r9.u64 = ctx.r3.u64 & ctx.r12.u64;
	// rldicl r3,r9,56,8
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r9,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// rldicl r31,r3,56,8
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r3.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r3,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r3.u8);
	// rldicl r9,r31,56,8
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r31.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r31,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r31.u8);
	// rldicl r3,r9,56,8
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r9.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r9,3(r11)
	PPC_STORE_U8(ctx.r11.u32 + 3, ctx.r9.u8);
	// rldicl r31,r3,56,8
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r3.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r3,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r3.u8);
	// stb r31,5(r11)
	PPC_STORE_U8(ctx.r11.u32 + 5, ctx.r31.u8);
	// addi r11,r11,6
	ctx.r11.s64 = ctx.r11.s64 + 6;
	// blt cr6,0x82b73244
	if (ctx.cr6.lt) goto loc_82B73244;
loc_82B732A8:
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// cmplw cr6,r5,r4
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r4.u32, ctx.xer);
	// blt cr6,0x82b73230
	if (ctx.cr6.lt) goto loc_82B73230;
loc_82B732B4:
	// ld r31,-8(r1)
	ctx.r31.u64 = PPC_LOAD_U64(ctx.r1.u32 + -8);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82B732C0"))) PPC_WEAK_FUNC(sub_82B732C0);
PPC_FUNC_IMPL(__imp__sub_82B732C0) {
	PPC_FUNC_PROLOGUE();
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82ae162c
	ctx.lr = 0x82B732C8;
	__savegprlr_29(ctx, base);
	// lhz r11,52(r4)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r4.u32 + 52);
	// li r5,0
	ctx.r5.s64 = 0;
	// lhz r10,50(r4)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r4.u32 + 50);
	// rlwinm r31,r11,31,1,31
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r11,1316(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 1316);
	// rlwinm r7,r10,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82b73398
	if (ctx.cr6.eq) goto loc_82B73398;
	// lis r10,-32070
	ctx.r10.s64 = -2101739520;
	// li r4,0
	ctx.r4.s64 = 0;
	// addi r6,r10,-14520
	ctx.r6.s64 = ctx.r10.s64 + -14520;
loc_82B732F4:
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82b73310
	if (ctx.cr6.eq) goto loc_82B73310;
	// lwz r10,22192(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 22192);
	// lwzx r9,r10,r4
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r4.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// li r9,0
	ctx.r9.s64 = 0;
	// beq cr6,0x82b73314
	if (ctx.cr6.eq) goto loc_82B73314;
loc_82B73310:
	// li r9,1
	ctx.r9.s64 = 1;
loc_82B73314:
	// li r10,0
	ctx.r10.s64 = 0;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82b73388
	if (ctx.cr6.eq) goto loc_82B73388;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
loc_82B73324:
	// cntlzw r9,r10
	ctx.r9.u64 = ctx.r10.u32 == 0 ? 32 : __builtin_clz(ctx.r10.u32);
	// li r12,3855
	ctx.r12.s64 = 3855;
	// rlwinm r9,r9,27,31,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 27) & 0x1;
	// rldicr r12,r12,32,31
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 32) & 0xFFFFFFFF00000000;
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// oris r12,r12,3855
	ctx.r12.u64 = ctx.r12.u64 | 252641280;
	// rlwinm r9,r9,3,0,28
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 3) & 0xFFFFFFF8;
	// ori r12,r12,3855
	ctx.r12.u64 = ctx.r12.u64 | 3855;
	// addi r10,r10,1
	ctx.r10.s64 = ctx.r10.s64 + 1;
	// cmplw cr6,r10,r7
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r7.u32, ctx.xer);
	// ldx r9,r9,r6
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r9.u32 + ctx.r6.u32);
	// and r9,r9,r12
	ctx.r9.u64 = ctx.r9.u64 & ctx.r12.u64;
	// rldicl r30,r9,56,8
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r9.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r9,0(r11)
	PPC_STORE_U8(ctx.r11.u32 + 0, ctx.r9.u8);
	// rldicl r29,r30,56,8
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r30.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r30,1(r11)
	PPC_STORE_U8(ctx.r11.u32 + 1, ctx.r30.u8);
	// rldicl r9,r29,56,8
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r29.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r29,2(r11)
	PPC_STORE_U8(ctx.r11.u32 + 2, ctx.r29.u8);
	// rldicl r30,r9,56,8
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r9.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r9,3(r11)
	PPC_STORE_U8(ctx.r11.u32 + 3, ctx.r9.u8);
	// rldicl r29,r30,56,8
	ctx.r29.u64 = __builtin_rotateleft64(ctx.r30.u64, 56) & 0xFFFFFFFFFFFFFF;
	// stb r30,4(r11)
	PPC_STORE_U8(ctx.r11.u32 + 4, ctx.r30.u8);
	// stb r29,5(r11)
	PPC_STORE_U8(ctx.r11.u32 + 5, ctx.r29.u8);
	// addi r11,r11,6
	ctx.r11.s64 = ctx.r11.s64 + 6;
	// blt cr6,0x82b73324
	if (ctx.cr6.lt) goto loc_82B73324;
loc_82B73388:
	// addi r5,r5,1
	ctx.r5.s64 = ctx.r5.s64 + 1;
	// addi r4,r4,4
	ctx.r4.s64 = ctx.r4.s64 + 4;
	// cmplw cr6,r5,r31
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, ctx.r31.u32, ctx.xer);
	// blt cr6,0x82b732f4
	if (ctx.cr6.lt) goto loc_82B732F4;
loc_82B73398:
	// b 0x82ae167c
	__restgprlr_29(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82B733A0"))) PPC_WEAK_FUNC(sub_82B733A0);
PPC_FUNC_IMPL(__imp__sub_82B733A0) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82ae15f0
	ctx.lr = 0x82B733A8;
	__savegprlr_14(ctx, base);
	// stwu r1,-2624(r1)
	ea = -2624 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r4
	ctx.r31.u64 = ctx.r4.u64;
	// lwz r10,22488(r3)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r3.u32 + 22488);
	// mr r30,r5
	ctx.r30.u64 = ctx.r5.u64;
	// lwz r7,3076(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 3076);
	// li r11,0
	ctx.r11.s64 = 0;
	// stw r3,2644(r1)
	PPC_STORE_U32(ctx.r1.u32 + 2644, ctx.r3.u32);
	// li r8,1
	ctx.r8.s64 = 1;
	// stw r11,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r11.u32);
	// lwz r9,1312(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1312);
	// stw r10,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r10.u32);
	// lwz r6,22500(r3)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r3.u32 + 22500);
	// stw r6,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r6.u32);
	// lwz r5,616(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 616);
	// stw r5,36(r30)
	PPC_STORE_U32(ctx.r30.u32 + 36, ctx.r5.u32);
	// lwz r4,428(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 428);
	// stw r4,40(r30)
	PPC_STORE_U32(ctx.r30.u32 + 40, ctx.r4.u32);
	// lwz r10,1164(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1164);
	// stw r10,44(r30)
	PPC_STORE_U32(ctx.r30.u32 + 44, ctx.r10.u32);
	// stw r11,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r11.u32);
	// stw r11,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r11.u32);
	// sth r11,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r11.u16);
	// sth r11,18(r30)
	PPC_STORE_U16(ctx.r30.u32 + 18, ctx.r11.u16);
	// lhz r4,50(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// lhz r6,74(r31)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r31.u32 + 74);
	// lhz r5,76(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 76);
	// stw r8,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r8.u32);
	// lhz r8,52(r31)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r31.u32 + 52);
	// rlwinm r10,r8,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r4,r4,31,1,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r9,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r9.u32);
	// stw r7,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r7.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// stw r11,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r11.u32);
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// stw r11,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r11.u32);
	// stw r10,144(r1)
	PPC_STORE_U32(ctx.r1.u32 + 144, ctx.r10.u32);
	// stw r6,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r6.u32);
	// stw r4,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r4.u32);
	// stw r5,148(r1)
	PPC_STORE_U32(ctx.r1.u32 + 148, ctx.r5.u32);
	// ble cr6,0x82b740f0
	if (!ctx.cr6.gt) goto loc_82B740F0;
	// b 0x82b73458
	goto loc_82B73458;
loc_82B73450:
	// lwz r3,2644(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 2644);
	// li r11,0
	ctx.r11.s64 = 0;
loc_82B73458:
	// lwz r10,96(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r9,120(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// sth r11,18(r30)
	PPC_STORE_U16(ctx.r30.u32 + 18, ctx.r11.u16);
	// stw r10,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r10.u32);
	// stw r9,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r9.u32);
	// lwz r8,22164(r3)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r3.u32 + 22164);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82b73498
	if (ctx.cr6.eq) goto loc_82B73498;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// lwz r9,1304(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1304);
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r7,r9,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x82b73498
	if (ctx.cr6.eq) goto loc_82B73498;
	// li r10,1
	ctx.r10.s64 = 1;
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
loc_82B73498:
	// lwz r10,132(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// stw r11,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r11.u32);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x82b7408c
	if (!ctx.cr6.gt) goto loc_82B7408C;
loc_82B734A8:
	// lwz r9,124(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// li r28,2
	ctx.r28.s64 = 2;
	// lwz r10,112(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// addi r8,r9,8
	ctx.r8.s64 = ctx.r9.s64 + 8;
	// lwz r26,128(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// clrlwi r11,r10,29
	ctx.r11.u64 = ctx.r10.u32 & 0x7;
	// clrlwi r10,r10,28
	ctx.r10.u64 = ctx.r10.u32 & 0xF;
	// stw r8,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r8.u32);
	// ld r21,0(r9)
	ctx.r21.u64 = PPC_LOAD_U64(ctx.r9.u32 + 0);
	// addi r7,r11,588
	ctx.r7.s64 = ctx.r11.s64 + 588;
	// addi r6,r10,596
	ctx.r6.s64 = ctx.r10.s64 + 596;
	// rldicl r5,r21,3,61
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r21.u64, 3) & 0x7;
	// rldicl r4,r21,10,54
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r21.u64, 10) & 0x3FF;
	// rlwinm r3,r7,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwimi r5,r4,0,30,31
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x3) | (ctx.r5.u64 & 0xFFFFFFFFFFFFFFFC);
	// rlwinm r11,r6,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// clrlwi r14,r5,29
	ctx.r14.u64 = ctx.r5.u32 & 0x7;
	// rlwinm r5,r26,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r26.u32 | (ctx.r26.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r3,r31
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + ctx.r31.u32);
	// add r18,r14,r31
	ctx.r18.u64 = ctx.r14.u64 + ctx.r31.u64;
	// addi r9,r31,472
	ctx.r9.s64 = ctx.r31.s64 + 472;
	// stb r14,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r14.u8);
	// lhzx r8,r11,r31
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + ctx.r31.u32);
	// extsh r7,r10
	ctx.r7.s64 = ctx.r10.s16;
	// add r29,r5,r26
	ctx.r29.u64 = ctx.r5.u64 + ctx.r26.u64;
	// extsh r6,r8
	ctx.r6.s64 = ctx.r8.s16;
	// rlwinm r10,r7,6,0,25
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 6) & 0xFFFFFFC0;
	// lbz r27,1879(r18)
	ctx.r27.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1879);
	// rlwinm r7,r6,6,0,25
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 6) & 0xFFFFFFC0;
loc_82B7351C:
	// clrlwi r11,r27,31
	ctx.r11.u64 = ctx.r27.u32 & 0x1;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82b7356c
	if (ctx.cr6.eq) goto loc_82B7356C;
	// lwz r6,-8(r9)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + -8);
	// lwz r11,8(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// lwz r8,12(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// lwz r4,0(r9)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// add r11,r6,r11
	ctx.r11.u64 = ctx.r6.u64 + ctx.r11.u64;
	// lwz r3,8(r9)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r9.u32 + 8);
	// add r6,r8,r4
	ctx.r6.u64 = ctx.r8.u64 + ctx.r4.u64;
	// add r8,r3,r8
	ctx.r8.u64 = ctx.r3.u64 + ctx.r8.u64;
	// dcbt r10,r11
	// add r4,r10,r26
	ctx.r4.u64 = ctx.r10.u64 + ctx.r26.u64;
	// dcbt r4,r11
	// add r3,r10,r5
	ctx.r3.u64 = ctx.r10.u64 + ctx.r5.u64;
	// dcbt r3,r11
	// add r4,r10,r29
	ctx.r4.u64 = ctx.r10.u64 + ctx.r29.u64;
	// dcbt r4,r11
	// dcbt r7,r6
	// dcbt r7,r8
loc_82B7356C:
	// addic. r28,r28,-1
	ctx.xer.ca = ctx.r28.u32 > 0;
	ctx.r28.s64 = ctx.r28.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// addi r9,r9,4
	ctx.r9.s64 = ctx.r9.s64 + 4;
	// rlwinm r27,r27,31,1,31
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r27.u32 | (ctx.r27.u64 << 32), 31) & 0x7FFFFFFF;
	// bne 0x82b7351c
	if (!ctx.cr0.eq) goto loc_82B7351C;
	// lwz r10,108(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// addi r11,r31,1912
	ctx.r11.s64 = ctx.r31.s64 + 1912;
	// lwz r9,1912(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1912);
	// rlwinm r22,r10,2,0,29
	ctx.r22.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r22,r9
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r22.u32 + ctx.r9.u32);
	// cmpwi cr6,r11,16384
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16384, ctx.xer);
	// beq cr6,0x82b7401c
	if (ctx.cr6.eq) goto loc_82B7401C;
	// lwz r10,1916(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1916);
	// rldicl r9,r21,17,47
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r21.u64, 17) & 0x1FFFF;
	// lbz r8,30(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 30);
	// mr r25,r11
	ctx.r25.u64 = ctx.r11.u64;
	// clrlwi r20,r9,31
	ctx.r20.u64 = ctx.r9.u32 & 0x1;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// lwzx r24,r22,r10
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r22.u32 + ctx.r10.u32);
	// beq cr6,0x82b735c8
	if (ctx.cr6.eq) goto loc_82B735C8;
	// rlwinm r25,r25,1,0,30
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r24,r24,1,0,30
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r25,r25,0,16,14
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 0) & 0xFFFFFFFFFFFEFFFF;
	// rlwinm r24,r24,0,16,14
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 0) & 0xFFFFFFFFFFFEFFFF;
loc_82B735C8:
	// lwz r11,116(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r9,2316(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2316);
	// lwz r10,1788(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1788);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// lhz r8,2(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// lhz r7,0(r11)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r9,r8
	ctx.r9.s64 = ctx.r8.s16;
	// extsh r8,r7
	ctx.r8.s64 = ctx.r7.s16;
	// mullw r11,r9,r10
	ctx.r11.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// rlwinm r9,r9,8,0,23
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 8) & 0xFFFFFF00;
	// mullw r10,r8,r10
	ctx.r10.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r10.s32);
	// rlwinm r8,r8,8,0,23
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 8) & 0xFFFFFF00;
	// subf r9,r9,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r9.u64;
	// beq cr6,0x82b73648
	if (ctx.cr6.eq) goto loc_82B73648;
	// addi r7,r11,255
	ctx.r7.s64 = ctx.r11.s64 + 255;
	// subf r11,r8,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r8.u64;
	// addi r6,r10,255
	ctx.r6.s64 = ctx.r10.s64 + 255;
	// addi r5,r9,255
	ctx.r5.s64 = ctx.r9.s64 + 255;
	// srawi r4,r7,9
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1FF) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 9;
	// addi r3,r11,255
	ctx.r3.s64 = ctx.r11.s64 + 255;
	// srawi r11,r6,9
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1FF) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 9;
	// srawi r10,r5,9
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x1FF) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 9;
	// srawi r9,r3,9
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x1FF) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 9;
	// rlwinm r8,r4,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r7,r11,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r10,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// sth r8,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r8.u16);
	// rlwinm r5,r9,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// sth r7,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, ctx.r7.u16);
	// sth r6,90(r1)
	PPC_STORE_U16(ctx.r1.u32 + 90, ctx.r6.u16);
	// sth r5,88(r1)
	PPC_STORE_U16(ctx.r1.u32 + 88, ctx.r5.u16);
	// b 0x82b7367c
	goto loc_82B7367C;
loc_82B73648:
	// addi r7,r11,128
	ctx.r7.s64 = ctx.r11.s64 + 128;
	// subf r11,r8,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r8.u64;
	// addi r6,r10,128
	ctx.r6.s64 = ctx.r10.s64 + 128;
	// addi r5,r9,128
	ctx.r5.s64 = ctx.r9.s64 + 128;
	// srawi r4,r7,8
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0xFF) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 8;
	// addi r3,r11,128
	ctx.r3.s64 = ctx.r11.s64 + 128;
	// srawi r11,r6,8
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0xFF) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 8;
	// sth r4,86(r1)
	PPC_STORE_U16(ctx.r1.u32 + 86, ctx.r4.u16);
	// srawi r10,r5,8
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFF) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 8;
	// srawi r9,r3,8
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFF) != 0);
	ctx.r9.s64 = ctx.r3.s32 >> 8;
	// sth r11,84(r1)
	PPC_STORE_U16(ctx.r1.u32 + 84, ctx.r11.u16);
	// sth r10,90(r1)
	PPC_STORE_U16(ctx.r1.u32 + 90, ctx.r10.u16);
	// sth r9,88(r1)
	PPC_STORE_U16(ctx.r1.u32 + 88, ctx.r9.u16);
loc_82B7367C:
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r28,16(r30)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r27,1892(r31)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1892);
	// rlwinm r10,r5,1,15,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x10000;
	// lwz r26,1904(r31)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1904);
	// rlwinm r11,r28,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 5) & 0xFFFFFFE0;
	// subf r10,r10,r27
	ctx.r10.u64 = ctx.r27.u64 - ctx.r10.u64;
	// subf r9,r11,r26
	ctx.r9.u64 = ctx.r26.u64 - ctx.r11.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// subf r8,r5,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r5.u64;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// mr r29,r5
	ctx.r29.u64 = ctx.r5.u64;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | ctx.r11.u64;
	// rlwinm r6,r7,0,0,16
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r6,r6,0,16,0
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82b736d4
	if (ctx.cr6.eq) goto loc_82B736D4;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82a0dc08
	ctx.lr = 0x82B736D0;
	sub_82A0DC08(ctx, base);
	// mr r29,r3
	ctx.r29.u64 = ctx.r3.u64;
loc_82B736D4:
	// lwz r5,88(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r11,r28,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 5) & 0xFFFFFFE0;
	// stw r29,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r29.u32);
	// rlwinm r10,r5,1,15,15
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0x10000;
	// subf r9,r11,r26
	ctx.r9.u64 = ctx.r26.u64 - ctx.r11.u64;
	// subf r10,r10,r27
	ctx.r10.u64 = ctx.r27.u64 - ctx.r10.u64;
	// subf r8,r5,r9
	ctx.r8.u64 = ctx.r9.u64 - ctx.r5.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// mr r3,r5
	ctx.r3.u64 = ctx.r5.u64;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// or r7,r8,r11
	ctx.r7.u64 = ctx.r8.u64 | ctx.r11.u64;
	// rlwinm r6,r7,0,0,16
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r6,r6,0,16,0
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r6,0
	ctx.cr6.compare<uint32_t>(ctx.r6.u32, 0, ctx.xer);
	// beq cr6,0x82b73720
	if (ctx.cr6.eq) goto loc_82B73720;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r4,2
	ctx.r4.s64 = 2;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82a0dc08
	ctx.lr = 0x82B73720;
	sub_82A0DC08(ctx, base);
loc_82B73720:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// cmplwi cr6,r14,1
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 1, ctx.xer);
	// stw r3,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r3.u32);
	// addi r28,r31,1912
	ctx.r28.s64 = ctx.r31.s64 + 1912;
	// stw r25,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r25.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r24,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r24.u32);
	// lwz r9,1912(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1912);
	// stwx r29,r22,r9
	PPC_STORE_U32(ctx.r22.u32 + ctx.r9.u32, ctx.r29.u32);
	// lwz r8,1916(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1916);
	// stwx r3,r22,r8
	PPC_STORE_U32(ctx.r22.u32 + ctx.r8.u32, ctx.r3.u32);
	// beq cr6,0x82b73abc
	if (ctx.cr6.eq) goto loc_82B73ABC;
	// subfic r23,r14,5
	ctx.xer.ca = ctx.r14.u32 <= 5;
	ctx.r23.u64 = static_cast<uint64_t>(5) - ctx.r14.u64;
	// cmplwi cr6,r14,2
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 2, ctx.xer);
	// beq cr6,0x82b73768
	if (ctx.cr6.eq) goto loc_82B73768;
	// stw r25,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r25.u32);
	// stw r24,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r24.u32);
	// b 0x82b73770
	goto loc_82B73770;
loc_82B73768:
	// stw r25,140(r1)
	PPC_STORE_U32(ctx.r1.u32 + 140, ctx.r25.u32);
	// stw r24,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r24.u32);
loc_82B73770:
	// lwz r25,104(r1)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// addi r29,r1,136
	ctx.r29.s64 = ctx.r1.s64 + 136;
	// subfic r27,r31,-1912
	ctx.xer.ca = ctx.r31.u32 <= 4294965384;
	ctx.r27.u64 = static_cast<uint64_t>(-1912) - ctx.r31.u64;
	// li r26,2
	ctx.r26.s64 = 2;
loc_82B73780:
	// clrlwi r11,r23,31
	ctx.r11.u64 = ctx.r23.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b73aa8
	if (ctx.cr6.eq) goto loc_82B73AA8;
	// lwz r11,0(r28)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// stw r11,1908(r31)
	PPC_STORE_U32(ctx.r31.u32 + 1908, ctx.r11.u32);
	// beq cr6,0x82b73854
	if (ctx.cr6.eq) goto loc_82B73854;
	// lhz r10,18(r30)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r30.u32 + 18);
	// li r3,0
	ctx.r3.s64 = 0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82b73a38
	if (ctx.cr6.eq) goto loc_82B73A38;
	// lwz r10,4(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// rlwinm r10,r10,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r11,r10,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r11.u32);
	// cmpwi cr6,r11,16384
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 16384, ctx.xer);
	// beq cr6,0x82b73a38
	if (ctx.cr6.eq) goto loc_82B73A38;
	// lwz r10,2320(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2320);
	// rlwinm r9,r11,1,15,15
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x10000;
	// lwz r8,16(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// mr r3,r11
	ctx.r3.u64 = ctx.r11.u64;
	// addi r4,r10,1
	ctx.r4.s64 = ctx.r10.s64 + 1;
	// addi r7,r4,471
	ctx.r7.s64 = ctx.r4.s64 + 471;
	// addi r6,r4,474
	ctx.r6.s64 = ctx.r4.s64 + 474;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r6,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r10,r4,31
	ctx.r10.u64 = ctx.r4.u32 & 0x1;
	// subfic r10,r10,5
	ctx.xer.ca = ctx.r10.u32 <= 5;
	ctx.r10.u64 = static_cast<uint64_t>(5) - ctx.r10.u64;
	// lwzx r6,r5,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r31.u32);
	// lwzx r5,r7,r31
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r31.u32);
	// slw r10,r8,r10
	ctx.r10.u64 = ctx.r10.u8 & 0x20 ? 0 : (ctx.r8.u32 << (ctx.r10.u8 & 0x3F));
	// subf r9,r9,r6
	ctx.r9.u64 = ctx.r6.u64 - ctx.r9.u64;
	// subf r8,r10,r5
	ctx.r8.u64 = ctx.r5.u64 - ctx.r10.u64;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// subf r7,r11,r8
	ctx.r7.u64 = ctx.r8.u64 - ctx.r11.u64;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// or r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 | ctx.r10.u64;
	// rlwinm r5,r6,0,0,16
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r5,r5,0,16,0
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r5,0
	ctx.cr6.compare<uint32_t>(ctx.r5.u32, 0, ctx.xer);
	// beq cr6,0x82b73a38
	if (ctx.cr6.eq) goto loc_82B73A38;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x82b7384c
	if (!ctx.cr6.eq) goto loc_82B7384C;
	// lwz r10,1168(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1168);
	// cmpwi cr6,r10,7
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 7, ctx.xer);
	// bne cr6,0x82b7384c
	if (!ctx.cr6.eq) goto loc_82B7384C;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r4,r11
	ctx.r4.u64 = ctx.r11.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82b35e00
	ctx.lr = 0x82B73848;
	sub_82B35E00(ctx, base);
	// b 0x82b73a38
	goto loc_82B73A38;
loc_82B7384C:
	// mr r5,r11
	ctx.r5.u64 = ctx.r11.u64;
	// b 0x82b73a2c
	goto loc_82B73A2C;
loc_82B73854:
	// lwz r8,4(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lhz r7,50(r31)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// rlwinm r9,r8,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r6,18(r30)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r30.u32 + 18);
	// rlwinm r10,r7,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 31) & 0x7FFFFFFF;
	// add r4,r9,r11
	ctx.r4.u64 = ctx.r9.u64 + ctx.r11.u64;
	// subf r7,r10,r8
	ctx.r7.u64 = ctx.r8.u64 - ctx.r10.u64;
	// rlwinm r5,r6,31,1,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r9,r7,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// neg r3,r5
	ctx.r3.s64 = static_cast<int64_t>(-ctx.r5.u64);
	// lwz r6,-4(r4)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r4.u32 + -4);
	// addi r8,r10,-1
	ctx.r8.s64 = ctx.r10.s64 + -1;
	// srawi r4,r3,31
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x7FFFFFFF) != 0);
	ctx.r4.s64 = ctx.r3.s32 >> 31;
	// cmpw cr6,r5,r8
	ctx.cr6.compare<int32_t>(ctx.r5.s32, ctx.r8.s32, ctx.xer);
	// lwzx r9,r9,r11
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r11.u32);
	// and r10,r6,r4
	ctx.r10.u64 = ctx.r6.u64 & ctx.r4.u64;
	// li r8,1
	ctx.r8.s64 = 1;
	// blt cr6,0x82b738a0
	if (ctx.cr6.lt) goto loc_82B738A0;
	// li r8,0
	ctx.r8.s64 = 0;
loc_82B738A0:
	// rlwinm r8,r8,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 1) & 0xFFFFFFFE;
	// rlwinm r6,r9,31,1,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// xor r5,r6,r9
	ctx.r5.u64 = ctx.r6.u64 ^ ctx.r9.u64;
	// addi r8,r8,-1
	ctx.r8.s64 = ctx.r8.s64 + -1;
	// rlwinm r4,r10,31,1,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// rlwinm r3,r8,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r5,0,17,17
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0x4000;
	// xor r7,r4,r10
	ctx.r7.u64 = ctx.r4.u64 ^ ctx.r10.u64;
	// rlwinm r6,r7,0,17,17
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0x4000;
	// lwzx r11,r3,r11
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r11.u32);
	// rlwinm r5,r11,31,1,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// xor r4,r5,r11
	ctx.r4.u64 = ctx.r5.u64 ^ ctx.r11.u64;
	// rlwinm r7,r4,0,17,17
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 0) & 0x4000;
	// add r8,r7,r8
	ctx.r8.u64 = ctx.r7.u64 + ctx.r8.u64;
	// add. r8,r8,r6
	ctx.r8.u64 = ctx.r8.u64 + ctx.r6.u64;
	ctx.cr0.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// ble 0x82b738f8
	if (!ctx.cr0.gt) goto loc_82B738F8;
	// cmpwi cr6,r8,16384
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 16384, ctx.xer);
	// bne cr6,0x82b73a20
	if (!ctx.cr6.eq) goto loc_82B73A20;
	// cmplwi cr6,r9,16384
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 16384, ctx.xer);
	// bne cr6,0x82b73a00
	if (!ctx.cr6.eq) goto loc_82B73A00;
	// li r9,0
	ctx.r9.s64 = 0;
loc_82B738F8:
	// subf r8,r10,r11
	ctx.r8.u64 = ctx.r11.u64 - ctx.r10.u64;
	// lwz r4,2320(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2320);
	// subf r7,r9,r11
	ctx.r7.u64 = ctx.r11.u64 - ctx.r9.u64;
	// lwz r24,16(r30)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// subf r6,r9,r10
	ctx.r6.u64 = ctx.r10.u64 - ctx.r9.u64;
	// rlwinm r3,r11,16,0,15
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r19,r10,16,0,15
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r17,r9,16,0,15
	ctx.r17.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// xor r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 ^ ctx.r7.u64;
	// xor r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 ^ ctx.r7.u64;
	// subf r5,r17,r3
	ctx.r5.u64 = ctx.r3.u64 - ctx.r17.u64;
	// subf r16,r19,r3
	ctx.r16.u64 = ctx.r3.u64 - ctx.r19.u64;
	// subf r6,r17,r19
	ctx.r6.u64 = ctx.r19.u64 - ctx.r17.u64;
	// srawi r8,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r8.s64 = ctx.r8.s32 >> 31;
	// srawi r7,r7,31
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r7.s32 >> 31;
	// xor r16,r16,r5
	ctx.r16.u64 = ctx.r16.u64 ^ ctx.r5.u64;
	// xor r5,r6,r5
	ctx.r5.u64 = ctx.r6.u64 ^ ctx.r5.u64;
	// and r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 & ctx.r11.u64;
	// nor r8,r8,r7
	ctx.r8.u64 = ~(ctx.r8.u64 | ctx.r7.u64);
	// srawi r6,r16,31
	ctx.xer.ca = (ctx.r16.s32 < 0) & ((ctx.r16.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r16.s32 >> 31;
	// and r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 & ctx.r9.u64;
	// srawi r5,r5,31
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x7FFFFFFF) != 0);
	ctx.r5.s64 = ctx.r5.s32 >> 31;
	// and r10,r8,r10
	ctx.r10.u64 = ctx.r8.u64 & ctx.r10.u64;
	// or r9,r11,r7
	ctx.r9.u64 = ctx.r11.u64 | ctx.r7.u64;
	// nor r8,r6,r5
	ctx.r8.u64 = ~(ctx.r6.u64 | ctx.r5.u64);
	// and r7,r5,r17
	ctx.r7.u64 = ctx.r5.u64 & ctx.r17.u64;
	// and r6,r6,r3
	ctx.r6.u64 = ctx.r6.u64 & ctx.r3.u64;
	// or r5,r9,r10
	ctx.r5.u64 = ctx.r9.u64 | ctx.r10.u64;
	// or r3,r7,r6
	ctx.r3.u64 = ctx.r7.u64 | ctx.r6.u64;
	// and r11,r8,r19
	ctx.r11.u64 = ctx.r8.u64 & ctx.r19.u64;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// or r9,r3,r11
	ctx.r9.u64 = ctx.r3.u64 | ctx.r11.u64;
	// srawi r10,r5,16
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0xFFFF) != 0);
	ctx.r10.s64 = ctx.r5.s32 >> 16;
	// addi r8,r4,471
	ctx.r8.s64 = ctx.r4.s64 + 471;
	// addi r7,r4,474
	ctx.r7.s64 = ctx.r4.s64 + 474;
	// rlwinm r6,r10,16,0,15
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r5,r9,16,16,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r10,r7,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// or r3,r5,r6
	ctx.r3.u64 = ctx.r5.u64 | ctx.r6.u64;
	// clrlwi r9,r4,31
	ctx.r9.u64 = ctx.r4.u32 & 0x1;
	// rlwinm r8,r3,1,15,15
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x10000;
	// lwzx r7,r11,r31
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// subfic r11,r9,5
	ctx.xer.ca = ctx.r9.u32 <= 5;
	ctx.r11.u64 = static_cast<uint64_t>(5) - ctx.r9.u64;
	// lwzx r6,r10,r31
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r31.u32);
	// subf r10,r8,r7
	ctx.r10.u64 = ctx.r7.u64 - ctx.r8.u64;
	// slw r11,r24,r11
	ctx.r11.u64 = ctx.r11.u8 & 0x20 ? 0 : (ctx.r24.u32 << (ctx.r11.u8 & 0x3F));
	// subf r5,r3,r6
	ctx.r5.u64 = ctx.r6.u64 - ctx.r3.u64;
	// add r10,r10,r3
	ctx.r10.u64 = ctx.r10.u64 + ctx.r3.u64;
	// subf r9,r11,r5
	ctx.r9.u64 = ctx.r5.u64 - ctx.r11.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// or r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 | ctx.r11.u64;
	// rlwinm r7,r8,0,0,16
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r7,r7,0,16,0
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82b73a38
	if (ctx.cr6.eq) goto loc_82B73A38;
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x82b73a28
	if (!ctx.cr6.eq) goto loc_82B73A28;
	// lwz r11,1168(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1168);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x82b73a28
	if (!ctx.cr6.eq) goto loc_82B73A28;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82b35e00
	ctx.lr = 0x82B739FC;
	sub_82B35E00(ctx, base);
	// b 0x82b73a38
	goto loc_82B73A38;
loc_82B73A00:
	// cmplwi cr6,r11,16384
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 16384, ctx.xer);
	// bne cr6,0x82b73a10
	if (!ctx.cr6.eq) goto loc_82B73A10;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82b738f8
	goto loc_82B738F8;
loc_82B73A10:
	// cmplwi cr6,r10,16384
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 16384, ctx.xer);
	// bne cr6,0x82b738f8
	if (!ctx.cr6.eq) goto loc_82B738F8;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82b738f8
	goto loc_82B738F8;
loc_82B73A20:
	// li r3,0
	ctx.r3.s64 = 0;
	// b 0x82b73a38
	goto loc_82B73A38;
loc_82B73A28:
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
loc_82B73A2C:
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82a0dc08
	ctx.lr = 0x82B73A38;
	sub_82A0DC08(ctx, base);
loc_82B73A38:
	// clrlwi r11,r20,24
	ctx.r11.u64 = ctx.r20.u32 & 0xFF;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82b73a90
	if (!ctx.cr6.eq) goto loc_82B73A90;
	// lhz r11,2(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 2);
	// extsh r9,r3
	ctx.r9.s64 = ctx.r3.s16;
	// lhz r7,0(r29)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r29.u32 + 0);
	// srawi r6,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r6.s64 = ctx.r3.s32 >> 16;
	// extsh r8,r11
	ctx.r8.s64 = ctx.r11.s16;
	// lhz r11,62(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 62);
	// extsh r7,r7
	ctx.r7.s64 = ctx.r7.s16;
	// lhz r10,64(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 64);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lhz r5,66(r31)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r31.u32 + 66);
	// add r8,r6,r7
	ctx.r8.u64 = ctx.r6.u64 + ctx.r7.u64;
	// lhz r4,68(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 68);
	// add r3,r9,r11
	ctx.r3.u64 = ctx.r9.u64 + ctx.r11.u64;
	// add r9,r8,r10
	ctx.r9.u64 = ctx.r8.u64 + ctx.r10.u64;
	// and r8,r3,r5
	ctx.r8.u64 = ctx.r3.u64 & ctx.r5.u64;
	// and r7,r9,r4
	ctx.r7.u64 = ctx.r9.u64 & ctx.r4.u64;
	// subf r3,r11,r8
	ctx.r3.u64 = ctx.r8.u64 - ctx.r11.u64;
	// subf r6,r10,r7
	ctx.r6.u64 = ctx.r7.u64 - ctx.r10.u64;
	// rlwimi r3,r6,16,0,15
	ctx.r3.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000) | (ctx.r3.u64 & 0xFFFFFFFF0000FFFF);
loc_82B73A90:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r29,r29,4
	ctx.r29.s64 = ctx.r29.s64 + 4;
	// add r11,r11,r27
	ctx.r11.u64 = ctx.r11.u64 + ctx.r27.u64;
	// stwx r3,r11,r28
	PPC_STORE_U32(ctx.r11.u32 + ctx.r28.u32, ctx.r3.u32);
	// lwz r10,0(r28)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r28.u32 + 0);
	// stwx r3,r22,r10
	PPC_STORE_U32(ctx.r22.u32 + ctx.r10.u32, ctx.r3.u32);
loc_82B73AA8:
	// srawi r23,r23,1
	ctx.xer.ca = (ctx.r23.s32 < 0) & ((ctx.r23.u32 & 0x1) != 0);
	ctx.r23.s64 = ctx.r23.s32 >> 1;
	// addic. r26,r26,-1
	ctx.xer.ca = ctx.r26.u32 > 0;
	ctx.r26.s64 = ctx.r26.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// addi r28,r28,4
	ctx.r28.s64 = ctx.r28.s64 + 4;
	// bne 0x82b73780
	if (!ctx.cr0.eq) goto loc_82B73780;
	// b 0x82b73acc
	goto loc_82B73ACC;
loc_82B73ABC:
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r29,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r29.u32);
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// stw r3,4(r10)
	PPC_STORE_U32(ctx.r10.u32 + 4, ctx.r3.u32);
loc_82B73ACC:
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// lwz r9,388(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 388);
	// addi r11,r31,1852
	ctx.r11.s64 = ctx.r31.s64 + 1852;
	// stw r10,2308(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2308, ctx.r10.u32);
	// rldicl r8,r21,8,56
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r21.u64, 8) & 0xFF;
	// stw r11,700(r31)
	PPC_STORE_U32(ctx.r31.u32 + 700, ctx.r11.u32);
	// addi r7,r1,1312
	ctx.r7.s64 = ctx.r1.s64 + 1312;
	// clrlwi r11,r8,26
	ctx.r11.u64 = ctx.r8.u32 & 0x3F;
	// rldicl r6,r21,16,48
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r21.u64, 16) & 0xFFFF;
	// stw r7,2312(r31)
	PPC_STORE_U32(ctx.r31.u32 + 2312, ctx.r7.u32);
	// rlwinm r10,r11,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// mr r16,r21
	ctx.r16.u64 = ctx.r21.u64;
	// add r5,r11,r10
	ctx.r5.u64 = ctx.r11.u64 + ctx.r10.u64;
	// clrlwi r15,r6,26
	ctx.r15.u64 = ctx.r6.u32 & 0x3F;
	// rlwinm r11,r5,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r21,r31,1876
	ctx.r21.s64 = ctx.r31.s64 + 1876;
	// add r17,r11,r9
	ctx.r17.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r24,r31,464
	ctx.r24.s64 = ctx.r31.s64 + 464;
	// subfic r20,r31,-464
	ctx.xer.ca = ctx.r31.u32 <= 4294966832;
	ctx.r20.u64 = static_cast<uint64_t>(-464) - ctx.r31.u64;
	// li r19,2
	ctx.r19.s64 = 2;
	// lbz r18,1879(r18)
	ctx.r18.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1879);
loc_82B73B20:
	// clrlwi r11,r18,31
	ctx.r11.u64 = ctx.r18.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b73ddc
	if (ctx.cr6.eq) goto loc_82B73DDC;
	// lwz r10,4(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// add r22,r20,r24
	ctx.r22.u64 = ctx.r20.u64 + ctx.r24.u64;
	// lwz r9,16(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r8,1884(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1884);
	// lwz r7,1896(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1896);
	// rlwinm r11,r9,5,0,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 5) & 0xFFFFFFE0;
	// lwzx r3,r10,r22
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r22.u32);
	// subf r6,r11,r7
	ctx.r6.u64 = ctx.r7.u64 - ctx.r11.u64;
	// rlwinm r5,r3,1,15,15
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0x10000;
	// subf r4,r3,r6
	ctx.r4.u64 = ctx.r6.u64 - ctx.r3.u64;
	// subf r10,r5,r8
	ctx.r10.u64 = ctx.r8.u64 - ctx.r5.u64;
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r11,r11,r3
	ctx.r11.u64 = ctx.r11.u64 + ctx.r3.u64;
	// or r11,r4,r11
	ctx.r11.u64 = ctx.r4.u64 | ctx.r11.u64;
	// rlwinm r10,r11,0,0,16
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r10,r10,0,16,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82b73ba8
	if (ctx.cr6.eq) goto loc_82B73BA8;
	// lwz r11,1168(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1168);
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x82b73b94
	if (!ctx.cr6.eq) goto loc_82B73B94;
	// mr r4,r3
	ctx.r4.u64 = ctx.r3.u64;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82b35e00
	ctx.lr = 0x82B73B90;
	sub_82B35E00(ctx, base);
	// b 0x82b73ba8
	goto loc_82B73BA8;
loc_82B73B94:
	// mr r5,r3
	ctx.r5.u64 = ctx.r3.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// li r4,0
	ctx.r4.s64 = 0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82a0dc08
	ctx.lr = 0x82B73BA8;
	sub_82A0DC08(ctx, base);
loc_82B73BA8:
	// srawi r26,r3,16
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0xFFFF) != 0);
	ctx.r26.s64 = ctx.r3.s32 >> 16;
	// lhz r4,90(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 90);
	// extsh r25,r3
	ctx.r25.s64 = ctx.r3.s16;
	// lwz r9,0(r24)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r24.u32 + 0);
	// srawi r10,r26,2
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r26.s32 >> 2;
	// lwz r8,8(r30)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// srawi r11,r25,2
	ctx.xer.ca = (ctx.r25.s32 < 0) & ((ctx.r25.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r25.s32 >> 2;
	// lbz r7,48(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 48);
	// mullw r10,r10,r4
	ctx.r10.s64 = int64_t(ctx.r10.s32) * int64_t(ctx.r4.s32);
	// lwz r23,1844(r24)
	ctx.r23.u64 = PPC_LOAD_U32(ctx.r24.u32 + 1844);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// cmpwi cr6,r7,1
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 1, ctx.xer);
	// add r11,r11,r9
	ctx.r11.u64 = ctx.r11.u64 + ctx.r9.u64;
	// clrlwi r27,r26,30
	ctx.r27.u64 = ctx.r26.u32 & 0x3;
	// add r28,r11,r8
	ctx.r28.u64 = ctx.r11.u64 + ctx.r8.u64;
	// clrlwi r29,r25,30
	ctx.r29.u64 = ctx.r25.u32 & 0x3;
	// li r7,1
	ctx.r7.s64 = 1;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bne cr6,0x82b73c44
	if (!ctx.cr6.eq) goto loc_82B73C44;
	// addi r11,r29,44
	ctx.r11.s64 = ctx.r29.s64 + 44;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r27
	ctx.r10.u64 = ctx.r11.u64 + ctx.r27.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82B73C18;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// beq cr6,0x82b73c60
	if (ctx.cr6.eq) goto loc_82B73C60;
	// li r9,1
	ctx.r9.s64 = 1;
	// lbz r8,35(r31)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r31.u32 + 35);
	// mr r7,r27
	ctx.r7.u64 = ctx.r27.u64;
	// lhz r4,90(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 90);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82b525c8
	ctx.lr = 0x82B73C40;
	sub_82B525C8(ctx, base);
	// b 0x82b73c60
	goto loc_82B73C60;
loc_82B73C44:
	// addi r11,r29,48
	ctx.r11.s64 = ctx.r29.s64 + 48;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r10,r11,r27
	ctx.r10.u64 = ctx.r11.u64 + ctx.r27.u64;
	// rlwinm r9,r10,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r31
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// mtctr r8
	ctx.ctr.u64 = ctx.r8.u64;
	// bctrl 
	ctx.lr = 0x82B73C60;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82B73C60:
	// lwz r8,1172(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 1172);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82b73c84
	if (ctx.cr6.eq) goto loc_82B73C84;
	// lwz r11,4(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// add r11,r11,r22
	ctx.r11.u64 = ctx.r11.u64 + ctx.r22.u64;
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r25,r10
	ctx.r25.s64 = ctx.r10.s16;
	// extsh r26,r9
	ctx.r26.s64 = ctx.r9.s16;
loc_82B73C84:
	// clrlwi r11,r25,30
	ctx.r11.u64 = ctx.r25.u32 & 0x3;
	// lbz r10,31(r31)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r31.u32 + 31);
	// clrlwi r9,r26,30
	ctx.r9.u64 = ctx.r26.u32 & 0x3;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lbzx r11,r11,r21
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + ctx.r21.u32);
	// lbzx r10,r9,r21
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r21.u32);
	// add r7,r11,r25
	ctx.r7.u64 = ctx.r11.u64 + ctx.r25.u64;
	// add r6,r10,r26
	ctx.r6.u64 = ctx.r10.u64 + ctx.r26.u64;
	// srawi r10,r7,1
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r7.s32 >> 1;
	// srawi r11,r6,1
	ctx.xer.ca = (ctx.r6.s32 < 0) & ((ctx.r6.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r6.s32 >> 1;
	// beq cr6,0x82b73ce0
	if (ctx.cr6.eq) goto loc_82B73CE0;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// clrlwi r9,r10,31
	ctx.r9.u64 = ctx.r10.u32 & 0x1;
	// ble cr6,0x82b73cc4
	if (!ctx.cr6.gt) goto loc_82B73CC4;
	// subf r10,r9,r10
	ctx.r10.u64 = ctx.r10.u64 - ctx.r9.u64;
	// b 0x82b73cc8
	goto loc_82B73CC8;
loc_82B73CC4:
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
loc_82B73CC8:
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// clrlwi r9,r11,31
	ctx.r9.u64 = ctx.r11.u32 & 0x1;
	// ble cr6,0x82b73cdc
	if (!ctx.cr6.gt) goto loc_82B73CDC;
	// subf r11,r9,r11
	ctx.r11.u64 = ctx.r11.u64 - ctx.r9.u64;
	// b 0x82b73ce0
	goto loc_82B73CE0;
loc_82B73CDC:
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
loc_82B73CE0:
	// sth r10,94(r1)
	PPC_STORE_U16(ctx.r1.u32 + 94, ctx.r10.u16);
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// sth r11,92(r1)
	PPC_STORE_U16(ctx.r1.u32 + 92, ctx.r11.u16);
	// beq cr6,0x82b73d50
	if (ctx.cr6.eq) goto loc_82B73D50;
	// lwz r11,16(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 16);
	// lwz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// lwz r9,2324(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2324);
	// rlwinm r10,r11,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r8,2328(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2328);
	// rlwinm r7,r4,1,15,15
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0x10000;
	// add r6,r10,r9
	ctx.r6.u64 = ctx.r10.u64 + ctx.r9.u64;
	// rlwinm r5,r11,4,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0xFFFFFFF0;
	// subf r10,r7,r6
	ctx.r10.u64 = ctx.r6.u64 - ctx.r7.u64;
	// subf r3,r5,r8
	ctx.r3.u64 = ctx.r8.u64 - ctx.r5.u64;
	// add r10,r10,r4
	ctx.r10.u64 = ctx.r10.u64 + ctx.r4.u64;
	// subf r9,r4,r3
	ctx.r9.u64 = ctx.r3.u64 - ctx.r4.u64;
	// mr r11,r4
	ctx.r11.u64 = ctx.r4.u64;
	// or r8,r9,r10
	ctx.r8.u64 = ctx.r9.u64 | ctx.r10.u64;
	// rlwinm r7,r8,0,0,16
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFF8000;
	// rlwinm r7,r7,0,16,0
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFFF8000FFFF;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82b73d48
	if (ctx.cr6.eq) goto loc_82B73D48;
	// mr r5,r30
	ctx.r5.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82b35ee0
	ctx.lr = 0x82B73D44;
	sub_82B35EE0(ctx, base);
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
loc_82B73D48:
	// stw r11,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r11.u32);
	// b 0x82b73d54
	goto loc_82B73D54;
loc_82B73D50:
	// lwz r11,92(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
loc_82B73D54:
	// mr r10,r11
	ctx.r10.u64 = ctx.r11.u64;
	// lhz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 92);
	// srawi r11,r11,16
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0xFFFF) != 0);
	ctx.r11.s64 = ctx.r11.s32 >> 16;
	// lwz r9,12(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// extsh r5,r10
	ctx.r5.s64 = ctx.r10.s16;
	// lwz r10,8(r24)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r24.u32 + 8);
	// clrlwi r6,r11,30
	ctx.r6.u64 = ctx.r11.u32 & 0x3;
	// clrlwi r8,r5,30
	ctx.r8.u64 = ctx.r5.u32 & 0x3;
	// srawi r3,r11,2
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x3) != 0);
	ctx.r3.s64 = ctx.r11.s32 >> 2;
	// addi r8,r8,48
	ctx.r8.s64 = ctx.r8.s64 + 48;
	// mullw r11,r3,r4
	ctx.r11.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r4.s32);
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// srawi r8,r5,2
	ctx.xer.ca = (ctx.r5.s32 < 0) & ((ctx.r5.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r5.s32 >> 2;
	// add r7,r7,r6
	ctx.r7.u64 = ctx.r7.u64 + ctx.r6.u64;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r27,r7,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r28,r11,r9
	ctx.r28.u64 = ctx.r11.u64 + ctx.r9.u64;
	// addi r29,r23,768
	ctx.r29.s64 = ctx.r23.s64 + 768;
	// li r7,0
	ctx.r7.s64 = 0;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// lwzx r11,r27,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r31.u32);
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// add r3,r10,r28
	ctx.r3.u64 = ctx.r10.u64 + ctx.r28.u64;
	// mtctr r11
	ctx.ctr.u64 = ctx.r11.u64;
	// bctrl 
	ctx.lr = 0x82B73DB8;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
	// lwz r11,16(r24)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r24.u32 + 16);
	// lhz r4,92(r31)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r31.u32 + 92);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwzx r10,r27,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r31.u32);
	// add r3,r11,r28
	ctx.r3.u64 = ctx.r11.u64 + ctx.r28.u64;
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// addi r5,r29,16
	ctx.r5.s64 = ctx.r29.s64 + 16;
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82B73DDC;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82B73DDC:
	// srawi r18,r18,1
	ctx.xer.ca = (ctx.r18.s32 < 0) & ((ctx.r18.u32 & 0x1) != 0);
	ctx.r18.s64 = ctx.r18.s32 >> 1;
	// addic. r19,r19,-1
	ctx.xer.ca = ctx.r19.u32 > 0;
	ctx.r19.s64 = ctx.r19.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// addi r24,r24,4
	ctx.r24.s64 = ctx.r24.s64 + 4;
	// bne 0x82b73b20
	if (!ctx.cr0.eq) goto loc_82B73B20;
	// lbz r25,80(r1)
	ctx.r25.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// li r28,0
	ctx.r28.s64 = 0;
loc_82B73DF4:
	// srawi r27,r28,2
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x3) != 0);
	ctx.r27.s64 = ctx.r28.s32 >> 2;
	// addi r11,r28,140
	ctx.r11.s64 = ctx.r28.s64 + 140;
	// addi r10,r27,2
	ctx.r10.s64 = ctx.r27.s64 + 2;
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// clrlwi r7,r15,31
	ctx.r7.u64 = ctx.r15.u32 & 0x1;
	// rldicl r6,r16,20,44
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r16.u64, 20) & 0xFFFFF;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// lwzx r9,r9,r31
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r31.u32);
	// clrlwi r11,r6,29
	ctx.r11.u64 = ctx.r6.u32 & 0x7;
	// lwzx r10,r8,r30
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r30.u32);
	// add r26,r10,r9
	ctx.r26.u64 = ctx.r10.u64 + ctx.r9.u64;
	// beq cr6,0x82b73fac
	if (ctx.cr6.eq) goto loc_82B73FAC;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82b73efc
	if (!ctx.cr6.eq) goto loc_82B73EFC;
	// lwz r11,24(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 24);
	// addi r5,r31,168
	ctx.r5.s64 = ctx.r31.s64 + 168;
	// lwz r4,444(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 444);
	// li r9,0
	ctx.r9.s64 = 0;
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// lwz r6,0(r17)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r17.u32 + 0);
	// lwz r3,4(r17)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r17.u32 + 4);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r29,40(r30)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r30.u32 + 40);
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// lwz r11,20(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 20);
	// stw r7,24(r30)
	PPC_STORE_U32(ctx.r30.u32 + 24, ctx.r7.u32);
	// dcbzl r0,r29
	ea = (ctx.r29.u32) & ~127;
	memset((void*)PPC_RAW_ADDR(ea), 0, 128);
	// cmplwi cr6,r10,128
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 128, ctx.xer);
	// blt cr6,0x82b73e84
	if (ctx.cr6.lt) goto loc_82B73E84;
	// mr r7,r30
	ctx.r7.u64 = ctx.r30.u64;
	// mr r6,r17
	ctx.r6.u64 = ctx.r17.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829e8d28
	ctx.lr = 0x82B73E7C;
	sub_829E8D28(ctx, base);
	// mr r8,r3
	ctx.r8.u64 = ctx.r3.u64;
	// b 0x82b73edc
	goto loc_82B73EDC;
loc_82B73E84:
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// ble cr6,0x82b73ed8
	if (!ctx.cr6.gt) goto loc_82B73ED8;
loc_82B73E8C:
	// lhz r24,0(r11)
	ctx.r24.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// clrlwi r7,r24,26
	ctx.r7.u64 = ctx.r24.u32 & 0x3F;
	// rlwinm r23,r24,24,8,31
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 24) & 0xFFFFFF;
	// add r9,r7,r9
	ctx.r9.u64 = ctx.r7.u64 + ctx.r9.u64;
	// mullw r7,r23,r6
	ctx.r7.s64 = int64_t(ctx.r23.s32) * int64_t(ctx.r6.s32);
	// lbzx r23,r9,r4
	ctx.r23.u64 = PPC_LOAD_U8(ctx.r9.u32 + ctx.r4.u32);
	// lbzx r22,r23,r5
	ctx.r22.u64 = PPC_LOAD_U8(ctx.r23.u32 + ctx.r5.u32);
	// rlwinm r24,r24,25,31,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 25) & 0x1;
	// add r7,r7,r3
	ctx.r7.u64 = ctx.r7.u64 + ctx.r3.u64;
	// neg r24,r24
	ctx.r24.s64 = static_cast<int64_t>(-ctx.r24.u64);
	// rotlwi r23,r23,1
	ctx.r23.u64 = __builtin_rotateleft32(ctx.r23.u32, 1);
	// xor r7,r7,r24
	ctx.r7.u64 = ctx.r7.u64 ^ ctx.r24.u64;
	// or r8,r22,r8
	ctx.r8.u64 = ctx.r22.u64 | ctx.r8.u64;
	// subf r7,r24,r7
	ctx.r7.u64 = ctx.r7.u64 - ctx.r24.u64;
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// sthx r7,r23,r29
	PPC_STORE_U16(ctx.r23.u32 + ctx.r29.u32, ctx.r7.u16);
	// bne 0x82b73e8c
	if (!ctx.cr0.eq) goto loc_82B73E8C;
loc_82B73ED8:
	// stw r11,20(r30)
	PPC_STORE_U32(ctx.r30.u32 + 20, ctx.r11.u32);
loc_82B73EDC:
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// mr r4,r29
	ctx.r4.u64 = ctx.r29.u64;
	// mr r3,r29
	ctx.r3.u64 = ctx.r29.u64;
	// bne cr6,0x82b73ef4
	if (!ctx.cr6.eq) goto loc_82B73EF4;
	// bl 0x829f7cc8
	ctx.lr = 0x82B73EF0;
	sub_829F7CC8(ctx, base);
	// b 0x82b73f40
	goto loc_82B73F40;
loc_82B73EF4:
	// bl 0x82b38438
	ctx.lr = 0x82B73EF8;
	sub_82B38438(ctx, base);
	// b 0x82b73f40
	goto loc_82B73F40;
loc_82B73EFC:
	// rldicl r10,r16,24,40
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r16.u64, 24) & 0xFFFFFF;
	// lwz r7,36(r30)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r30.u32 + 36);
	// rlwinm r11,r11,0,29,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x6;
	// clrlwi r5,r10,28
	ctx.r5.u64 = ctx.r10.u32 & 0xF;
	// mr r29,r7
	ctx.r29.u64 = ctx.r7.u64;
	// add r9,r5,r31
	ctx.r9.u64 = ctx.r5.u64 + ctx.r31.u64;
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r4,r17
	ctx.r4.u64 = ctx.r17.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lbz r10,320(r9)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r9.u32 + 320);
	// add r11,r11,r10
	ctx.r11.u64 = ctx.r11.u64 + ctx.r10.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// addi r8,r11,159
	ctx.r8.s64 = ctx.r11.s64 + 159;
	// rlwinm r11,r8,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r10,r11,r31
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r31.u32);
	// mtctr r10
	ctx.ctr.u64 = ctx.r10.u64;
	// bctrl 
	ctx.lr = 0x82B73F40;
	PPC_CALL_INDIRECT_FUNC(ctx.ctr.u32);
loc_82B73F40:
	// clrlwi r14,r25,24
	ctx.r14.u64 = ctx.r25.u32 & 0xFF;
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// cmplwi cr6,r14,2
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 2, ctx.xer);
	// bgt cr6,0x82b73f78
	if (ctx.cr6.gt) goto loc_82B73F78;
	// addi r11,r27,45
	ctx.r11.s64 = ctx.r27.s64 + 45;
	// lwz r10,700(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 700);
	// mr r6,r29
	ctx.r6.u64 = ctx.r29.u64;
	// lwz r5,2312(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2312);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r4,2308(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2308);
	// lbzx r8,r28,r10
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r28.u32 + ctx.r10.u32);
	// lhzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r31.u32);
	// bl 0x82b74318
	ctx.lr = 0x82B73F74;
	sub_82B74318(ctx, base);
	// b 0x82b74008
	goto loc_82B74008;
loc_82B73F78:
	// lwz r11,700(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 700);
	// subfic r10,r14,581
	ctx.xer.ca = ctx.r14.u32 <= 581;
	ctx.r10.u64 = static_cast<uint64_t>(581) - ctx.r14.u64;
	// addi r9,r27,45
	ctx.r9.s64 = ctx.r27.s64 + 45;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// lbzx r6,r28,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r28.u32 + ctx.r11.u32);
	// lwzx r11,r8,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	// rotlwi r10,r6,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// lhzx r6,r7,r31
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r31.u32);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x82b3e730
	ctx.lr = 0x82B73FA8;
	sub_82B3E730(ctx, base);
	// b 0x82b74008
	goto loc_82B74008;
loc_82B73FAC:
	// cmplwi cr6,r14,2
	ctx.cr6.compare<uint32_t>(ctx.r14.u32, 2, ctx.xer);
	// mr r3,r26
	ctx.r3.u64 = ctx.r26.u64;
	// bgt cr6,0x82b73fdc
	if (ctx.cr6.gt) goto loc_82B73FDC;
	// addi r11,r27,45
	ctx.r11.s64 = ctx.r27.s64 + 45;
	// lwz r10,700(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 700);
	// lwz r5,2312(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2312);
	// rlwinm r9,r11,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r4,2308(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 2308);
	// lbzx r6,r28,r10
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r28.u32 + ctx.r10.u32);
	// lhzx r7,r9,r31
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r31.u32);
	// bl 0x82b74208
	ctx.lr = 0x82B73FD8;
	sub_82B74208(ctx, base);
	// b 0x82b74008
	goto loc_82B74008;
loc_82B73FDC:
	// lwz r11,700(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 700);
	// subfic r10,r14,581
	ctx.xer.ca = ctx.r14.u32 <= 581;
	ctx.r10.u64 = static_cast<uint64_t>(581) - ctx.r14.u64;
	// addi r9,r27,45
	ctx.r9.s64 = ctx.r27.s64 + 45;
	// rlwinm r8,r10,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r9,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lbzx r6,r28,r11
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r28.u32 + ctx.r11.u32);
	// lwzx r11,r8,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r31.u32);
	// rotlwi r10,r6,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r6.u32, 2);
	// lhzx r5,r7,r31
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r31.u32);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// bl 0x82b3e670
	ctx.lr = 0x82B74008;
	sub_82B3E670(ctx, base);
loc_82B74008:
	// addi r28,r28,1
	ctx.r28.s64 = ctx.r28.s64 + 1;
	// rlwinm r15,r15,31,25,31
	ctx.r15.u64 = __builtin_rotateleft64(ctx.r15.u32 | (ctx.r15.u64 << 32), 31) & 0x7F;
	// rldicr r16,r16,8,55
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r16.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// cmpwi cr6,r28,6
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 6, ctx.xer);
	// blt cr6,0x82b73df4
	if (ctx.cr6.lt) goto loc_82B73DF4;
loc_82B7401C:
	// lhz r10,18(r30)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r30.u32 + 18);
	// lwz r11,0(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// lwz r6,112(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// addi r7,r10,2
	ctx.r7.s64 = ctx.r10.s64 + 2;
	// lwz r4,116(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// addi r5,r11,2
	ctx.r5.s64 = ctx.r11.s64 + 2;
	// addi r8,r6,1
	ctx.r8.s64 = ctx.r6.s64 + 1;
	// lwz r9,4(r30)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r30.u32 + 4);
	// lwz r10,8(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 8);
	// addi r3,r4,4
	ctx.r3.s64 = ctx.r4.s64 + 4;
	// lwz r11,12(r30)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r30.u32 + 12);
	// mr r4,r7
	ctx.r4.u64 = ctx.r7.u64;
	// lwz r6,108(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwz r7,132(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// stw r8,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r8.u32);
	// addi r6,r6,1
	ctx.r6.s64 = ctx.r6.s64 + 1;
	// stw r3,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r3.u32);
	// stw r5,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r5.u32);
	// cmpw cr6,r8,r7
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r7.s32, ctx.xer);
	// stw r9,4(r30)
	PPC_STORE_U32(ctx.r30.u32 + 4, ctx.r9.u32);
	// sth r4,18(r30)
	PPC_STORE_U16(ctx.r30.u32 + 18, ctx.r4.u16);
	// stw r10,8(r30)
	PPC_STORE_U32(ctx.r30.u32 + 8, ctx.r10.u32);
	// stw r6,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r6.u32);
	// stw r11,12(r30)
	PPC_STORE_U32(ctx.r30.u32 + 12, ctx.r11.u32);
	// blt cr6,0x82b734a8
	if (ctx.cr6.lt) goto loc_82B734A8;
loc_82B7408C:
	// lhz r8,16(r30)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r30.u32 + 16);
	// li r7,0
	ctx.r7.s64 = 0;
	// lwz r6,148(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 148);
	// lwz r4,128(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// addi r8,r8,2
	ctx.r8.s64 = ctx.r8.s64 + 2;
	// lwz r3,120(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// rlwinm r11,r6,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r6,100(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// rlwinm r9,r4,4,0,27
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r5,96(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// add r4,r11,r3
	ctx.r4.u64 = ctx.r11.u64 + ctx.r3.u64;
	// lwz r10,0(r30)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r30.u32 + 0);
	// sth r8,16(r30)
	PPC_STORE_U16(ctx.r30.u32 + 16, ctx.r8.u16);
	// addi r8,r6,1
	ctx.r8.s64 = ctx.r6.s64 + 1;
	// lhz r11,50(r31)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r31.u32 + 50);
	// add r3,r9,r5
	ctx.r3.u64 = ctx.r9.u64 + ctx.r5.u64;
	// lwz r9,144(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 144);
	// add r6,r11,r10
	ctx.r6.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r8,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r8.u32);
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// stw r7,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r7.u32);
	// stw r3,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r3.u32);
	// stw r4,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r4.u32);
	// stw r6,0(r30)
	PPC_STORE_U32(ctx.r30.u32 + 0, ctx.r6.u32);
	// blt cr6,0x82b73450
	if (ctx.cr6.lt) goto loc_82B73450;
loc_82B740F0:
	// li r3,0
	ctx.r3.s64 = 0;
	// addi r1,r1,2624
	ctx.r1.s64 = ctx.r1.s64 + 2624;
	// b 0x82ae1640
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82B74100"))) PPC_WEAK_FUNC(sub_82B74100);
PPC_FUNC_IMPL(__imp__sub_82B74100) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82ae1628
	ctx.lr = 0x82B74108;
	__savegprlr_28(ctx, base);
	// stwu r1,-1664(r1)
	ea = -1664 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r31,r3
	ctx.r31.u64 = ctx.r3.u64;
	// lis r11,-31762
	ctx.r11.s64 = -2081554432;
	// addi r28,r31,22640
	ctx.r28.s64 = ctx.r31.s64 + 22640;
	// mr r4,r28
	ctx.r4.u64 = ctx.r28.u64;
	// lwz r3,32104(r11)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32104);
	// bl 0x82b5bac0
	ctx.lr = 0x82B74124;
	sub_82B5BAC0(ctx, base);
	// addi r29,r31,17360
	ctx.r29.s64 = ctx.r31.s64 + 17360;
	// addi r30,r31,15952
	ctx.r30.s64 = ctx.r31.s64 + 15952;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82b74a00
	ctx.lr = 0x82B7413C;
	sub_82B74A00(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82b74200
	if (!ctx.cr6.eq) goto loc_82B74200;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82b74600
	ctx.lr = 0x82B74154;
	sub_82B74600(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82b74200
	if (!ctx.cr6.eq) goto loc_82B74200;
	// mr r5,r29
	ctx.r5.u64 = ctx.r29.u64;
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x82b733a0
	ctx.lr = 0x82B7416C;
	sub_82B733A0(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// bne cr6,0x82b74200
	if (!ctx.cr6.eq) goto loc_82B74200;
	// lwz r11,3916(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 3916);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b741d8
	if (ctx.cr6.eq) goto loc_82B741D8;
	// lwz r11,15504(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 15504);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// cmpwi cr6,r11,7
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 7, ctx.xer);
	// bne cr6,0x82b7419c
	if (!ctx.cr6.eq) goto loc_82B7419C;
	// bl 0x82b732c0
	ctx.lr = 0x82B74198;
	sub_82B732C0(ctx, base);
	// b 0x82b741a0
	goto loc_82B741A0;
loc_82B7419C:
	// bl 0x82b73200
	ctx.lr = 0x82B741A0;
	sub_82B73200(ctx, base);
loc_82B741A0:
	// lhz r10,16004(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16004);
	// li r8,0
	ctx.r8.s64 = 0;
	// lwz r11,224(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 224);
	// mr r4,r30
	ctx.r4.u64 = ctx.r30.u64;
	// rlwinm r9,r10,31,1,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r7,3752(r31)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r31.u32 + 3752);
	// lwz r6,3748(r31)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r31.u32 + 3748);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// lwz r10,3744(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 3744);
	// add r7,r7,r11
	ctx.r7.u64 = ctx.r7.u64 + ctx.r11.u64;
	// lwz r5,220(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 220);
	// add r6,r6,r11
	ctx.r6.u64 = ctx.r6.u64 + ctx.r11.u64;
	// add r5,r10,r5
	ctx.r5.u64 = ctx.r10.u64 + ctx.r5.u64;
	// bl 0x829e9b48
	ctx.lr = 0x82B741D8;
	sub_829E9B48(ctx, base);
loc_82B741D8:
	// addi r4,r1,80
	ctx.r4.s64 = ctx.r1.s64 + 80;
	// mr r3,r28
	ctx.r3.u64 = ctx.r28.u64;
	// bl 0x82b5be08
	ctx.lr = 0x82B741E4;
	sub_82B5BE08(ctx, base);
	// li r11,1
	ctx.r11.s64 = 1;
	// li r10,0
	ctx.r10.s64 = 0;
	// stw r11,15592(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15592, ctx.r11.u32);
	// li r3,0
	ctx.r3.s64 = 0;
	// stw r10,15596(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15596, ctx.r10.u32);
	// stw r11,15568(r31)
	PPC_STORE_U32(ctx.r31.u32 + 15568, ctx.r11.u32);
	// stw r11,456(r31)
	PPC_STORE_U32(ctx.r31.u32 + 456, ctx.r11.u32);
loc_82B74200:
	// addi r1,r1,1664
	ctx.r1.s64 = ctx.r1.s64 + 1664;
	// b 0x82ae1678
	__restgprlr_28(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82B74208"))) PPC_WEAK_FUNC(sub_82B74208);
PPC_FUNC_IMPL(__imp__sub_82B74208) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// rlwinm r6,r6,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// li r8,144
	ctx.r8.s64 = 144;
	// add r4,r4,r6
	ctx.r4.u64 = ctx.r4.u64 + ctx.r6.u64;
	// add r2,r5,r6
	ctx.r2.u64 = ctx.r5.u64 + ctx.r6.u64;
	// li r6,48
	ctx.r6.s64 = 48;
	// mr r5,r7
	ctx.r5.u64 = ctx.r7.u64;
	// li r7,96
	ctx.r7.s64 = 96;
	// lvx128 v1,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,192
	ctx.r9.s64 = 192;
	// lvx128 v11,r0,r2
	ea = (ctx.r2.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,240
	ctx.r10.s64 = 240;
	// lvx128 v2,r4,r6
	ea = (ctx.r4.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v1,v1,v11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v1.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// lvx128 v12,r2,r6
	ea = (ctx.r2.u32 + ctx.r6.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r11,288
	ctx.r11.s64 = 288;
	// li r12,336
	ctx.r12.s64 = 336;
	// lvx128 v3,r4,r7
	ea = (ctx.r4.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r2,r7
	ea = (ctx.r2.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v2,v2,v12
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// lvx128 v4,r4,r8
	ea = (ctx.r4.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v3,v3,v13
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v3.u16), simde_mm_load_si128((simde__m128i*)ctx.v13.u16)));
	// lvx128 v14,r2,r8
	ea = (ctx.r2.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkshus v24,v1,v1
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v1.s16)));
	// lvx128 v5,r4,r9
	ea = (ctx.r4.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v4,v4,v14
	simde_mm_store_si128((simde__m128i*)ctx.v4.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v14.u16)));
	// lvx128 v15,r2,r9
	ea = (ctx.r2.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkshus v25,v2,v2
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v2.s16)));
	// lvx128 v6,r4,r10
	ea = (ctx.r4.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v5,v5,v15
	simde_mm_store_si128((simde__m128i*)ctx.v5.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v15.u16)));
	// lvx128 v7,r4,r11
	ea = (ctx.r4.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkshus v26,v3,v3
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v3.s16)));
	// lvx128 v8,r4,r12
	ea = (ctx.r4.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// lvx128 v16,r2,r10
	ea = (ctx.r2.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r6,r5,1,0,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lvx128 v17,r2,r11
	ea = (ctx.r2.u32 + ctx.r11.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v6,v6,v16
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v16.u16)));
	// vpkshus v27,v4,v4
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v4.s16)));
	// lvx128 v18,r2,r12
	ea = (ctx.r2.u32 + ctx.r12.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v7,v7,v17
	simde_mm_store_si128((simde__m128i*)ctx.v7.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v17.u16)));
	// stvewx v24,r0,r3
	ea = (ctx.r3.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v24.u32[3 - ((ea & 0xF) >> 2)]);
	// add r7,r5,r6
	ctx.r7.u64 = ctx.r5.u64 + ctx.r6.u64;
	// vpkshus v28,v5,v5
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v5.s16)));
	// stvewx v24,r0,r4
	ea = (ctx.r4.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v24.u32[3 - ((ea & 0xF) >> 2)]);
	// rlwinm r8,r5,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 2) & 0xFFFFFFFC;
	// vavguh v8,v8,v18
	simde_mm_store_si128((simde__m128i*)ctx.v8.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v18.u16)));
	// stvewx v25,r3,r5
	ea = (ctx.r3.u32 + ctx.r5.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v25.u32[3 - ((ea & 0xF) >> 2)]);
	// vpkshus v29,v6,v6
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v6.s16)));
	// stvewx v25,r4,r5
	ea = (ctx.r4.u32 + ctx.r5.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v25.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v26,r3,r6
	ea = (ctx.r3.u32 + ctx.r6.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v26.u32[3 - ((ea & 0xF) >> 2)]);
	// add r9,r5,r8
	ctx.r9.u64 = ctx.r5.u64 + ctx.r8.u64;
	// vpkshus v30,v7,v7
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v7.s16)));
	// stvewx v26,r4,r6
	ea = (ctx.r4.u32 + ctx.r6.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v26.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v27,r3,r7
	ea = (ctx.r3.u32 + ctx.r7.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v27.u32[3 - ((ea & 0xF) >> 2)]);
	// add r10,r6,r8
	ctx.r10.u64 = ctx.r6.u64 + ctx.r8.u64;
	// vpkshus v31,v8,v8
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v8.s16)));
	// stvewx v27,r4,r7
	ea = (ctx.r4.u32 + ctx.r7.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v27.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v28,r3,r8
	ea = (ctx.r3.u32 + ctx.r8.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v28.u32[3 - ((ea & 0xF) >> 2)]);
	// add r11,r7,r8
	ctx.r11.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stvewx v28,r4,r8
	ea = (ctx.r4.u32 + ctx.r8.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v28.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v29,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v29.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v29,r4,r9
	ea = (ctx.r4.u32 + ctx.r9.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v29.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v30,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v30.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v30,r4,r10
	ea = (ctx.r4.u32 + ctx.r10.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v30.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v31,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v31.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v31,r4,r11
	ea = (ctx.r4.u32 + ctx.r11.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v31.u32[3 - ((ea & 0xF) >> 2)]);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82B74318"))) PPC_WEAK_FUNC(sub_82B74318);
PPC_FUNC_IMPL(__imp__sub_82B74318) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// li r9,144
	ctx.r9.s64 = 144;
	// add r2,r5,r8
	ctx.r2.u64 = ctx.r5.u64 + ctx.r8.u64;
	// mr r5,r6
	ctx.r5.u64 = ctx.r6.u64;
	// add r4,r4,r8
	ctx.r4.u64 = ctx.r4.u64 + ctx.r8.u64;
	// mr r6,r7
	ctx.r6.u64 = ctx.r7.u64;
	// li r7,48
	ctx.r7.s64 = 48;
	// li r8,96
	ctx.r8.s64 = 96;
	// lvx128 v14,r2,r9
	ea = (ctx.r2.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v14.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r10,192
	ctx.r10.s64 = 192;
	// lvx128 v11,r0,r2
	ea = (ctx.r2.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v11.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v4,r4,r9
	ea = (ctx.r4.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v4.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// rlwinm r12,r6,1,0,30
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// lvx128 v1,r0,r4
	ea = (ctx.r4.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v1.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v4,v4,v14
	simde_mm_store_si128((simde__m128i*)ctx.v4.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v4.u16), simde_mm_load_si128((simde__m128i*)ctx.v14.u16)));
	// lvx128 v2,r4,r7
	ea = (ctx.r4.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v2.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v1,v1,v11
	simde_mm_store_si128((simde__m128i*)ctx.v1.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v1.u16), simde_mm_load_si128((simde__m128i*)ctx.v11.u16)));
	// lvx128 v3,r4,r8
	ea = (ctx.r4.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v3.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v5,r4,r10
	ea = (ctx.r4.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v5.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r4,r4,r10
	ctx.r4.u64 = ctx.r4.u64 + ctx.r10.u64;
	// lvx128 v12,r2,r7
	ea = (ctx.r2.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v12.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v13,r2,r8
	ea = (ctx.r2.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v13.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v2,v2,v12
	simde_mm_store_si128((simde__m128i*)ctx.v2.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v2.u16), simde_mm_load_si128((simde__m128i*)ctx.v12.u16)));
	// lvx128 v15,r2,r10
	ea = (ctx.r2.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v15.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r2,r2,r10
	ctx.r2.u64 = ctx.r2.u64 + ctx.r10.u64;
	// li r10,64
	ctx.r10.s64 = 64;
	// vavguh v3,v3,v13
	simde_mm_store_si128((simde__m128i*)ctx.v3.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v3.u16), simde_mm_load_si128((simde__m128i*)ctx.v13.u16)));
	// lvx128 v6,r4,r7
	ea = (ctx.r4.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v6.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v5,v5,v15
	simde_mm_store_si128((simde__m128i*)ctx.v5.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v5.u16), simde_mm_load_si128((simde__m128i*)ctx.v15.u16)));
	// lvx128 v7,r4,r8
	ea = (ctx.r4.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v7.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v8,r4,r9
	ea = (ctx.r4.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v8.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// addi r4,r3,4
	ctx.r4.s64 = ctx.r3.s64 + 4;
	// lvx128 v16,r2,r7
	ea = (ctx.r2.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r7,16
	ctx.r7.s64 = 16;
	// lvx128 v17,r2,r8
	ea = (ctx.r2.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r8,32
	ctx.r8.s64 = 32;
	// lvx128 v18,r2,r9
	ea = (ctx.r2.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vavguh v6,v6,v16
	simde_mm_store_si128((simde__m128i*)ctx.v6.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v6.u16), simde_mm_load_si128((simde__m128i*)ctx.v16.u16)));
	// lvx128 v16,r0,r5
	ea = (ctx.r5.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v16.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// li r9,48
	ctx.r9.s64 = 48;
	// vavguh v7,v7,v17
	simde_mm_store_si128((simde__m128i*)ctx.v7.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v7.u16), simde_mm_load_si128((simde__m128i*)ctx.v17.u16)));
	// lvx128 v20,r5,r10
	ea = (ctx.r5.u32 + ctx.r10.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v20.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v17,r5,r7
	ea = (ctx.r5.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v17.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v24,v1,v16
	simde_mm_store_si128((simde__m128i*)ctx.v24.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v1.s16), simde_mm_load_si128((simde__m128i*)ctx.v16.s16)));
	// vavguh v8,v8,v18
	simde_mm_store_si128((simde__m128i*)ctx.v8.u16, simde_mm_avg_epu16(simde_mm_load_si128((simde__m128i*)ctx.v8.u16), simde_mm_load_si128((simde__m128i*)ctx.v18.u16)));
	// lvx128 v18,r5,r8
	ea = (ctx.r5.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v18.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v25,v2,v17
	simde_mm_store_si128((simde__m128i*)ctx.v25.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v2.s16), simde_mm_load_si128((simde__m128i*)ctx.v17.s16)));
	// lvx128 v19,r5,r9
	ea = (ctx.r5.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v19.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vaddshs v26,v3,v18
	simde_mm_store_si128((simde__m128i*)ctx.v26.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v3.s16), simde_mm_load_si128((simde__m128i*)ctx.v18.s16)));
	// vpkshus v24,v24,v24
	simde_mm_store_si128((simde__m128i*)ctx.v24.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v24.s16), simde_mm_load_si128((simde__m128i*)ctx.v24.s16)));
	// add r5,r5,r10
	ctx.r5.u64 = ctx.r5.u64 + ctx.r10.u64;
	// vaddshs v27,v4,v19
	simde_mm_store_si128((simde__m128i*)ctx.v27.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v4.s16), simde_mm_load_si128((simde__m128i*)ctx.v19.s16)));
	// vpkshus v25,v25,v25
	simde_mm_store_si128((simde__m128i*)ctx.v25.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v25.s16), simde_mm_load_si128((simde__m128i*)ctx.v25.s16)));
	// vaddshs v28,v5,v20
	simde_mm_store_si128((simde__m128i*)ctx.v28.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v5.s16), simde_mm_load_si128((simde__m128i*)ctx.v20.s16)));
	// vpkshus v26,v26,v26
	simde_mm_store_si128((simde__m128i*)ctx.v26.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v26.s16), simde_mm_load_si128((simde__m128i*)ctx.v26.s16)));
	// vpkshus v27,v27,v27
	simde_mm_store_si128((simde__m128i*)ctx.v27.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v27.s16), simde_mm_load_si128((simde__m128i*)ctx.v27.s16)));
	// lvx128 v21,r5,r7
	ea = (ctx.r5.u32 + ctx.r7.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v21.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// lvx128 v22,r5,r8
	ea = (ctx.r5.u32 + ctx.r8.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v22.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// add r7,r6,r12
	ctx.r7.u64 = ctx.r6.u64 + ctx.r12.u64;
	// lvx128 v23,r5,r9
	ea = (ctx.r5.u32 + ctx.r9.u32) & ~0xF;
	simde_mm_store_si128((simde__m128i*)ctx.v23.u8, simde_mm_shuffle_epi8(simde_mm_load_si128((simde__m128i*)PPC_RAW_ADDR(ea)), simde_mm_load_si128((simde__m128i*)VectorMaskL)));
	// vpkshus v28,v28,v28
	simde_mm_store_si128((simde__m128i*)ctx.v28.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v28.s16), simde_mm_load_si128((simde__m128i*)ctx.v28.s16)));
	// stvewx v24,r0,r3
	ea = (ctx.r3.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v24.u32[3 - ((ea & 0xF) >> 2)]);
	// rlwinm r8,r6,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// stvewx v24,r0,r4
	ea = (ctx.r4.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v24.u32[3 - ((ea & 0xF) >> 2)]);
	// vaddshs v29,v6,v21
	simde_mm_store_si128((simde__m128i*)ctx.v29.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v6.s16), simde_mm_load_si128((simde__m128i*)ctx.v21.s16)));
	// stvewx v25,r3,r6
	ea = (ctx.r3.u32 + ctx.r6.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v25.u32[3 - ((ea & 0xF) >> 2)]);
	// vaddshs v30,v7,v22
	simde_mm_store_si128((simde__m128i*)ctx.v30.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v7.s16), simde_mm_load_si128((simde__m128i*)ctx.v22.s16)));
	// stvewx v25,r4,r6
	ea = (ctx.r4.u32 + ctx.r6.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v25.u32[3 - ((ea & 0xF) >> 2)]);
	// vaddshs v31,v8,v23
	simde_mm_store_si128((simde__m128i*)ctx.v31.s16, simde_mm_adds_epi16(simde_mm_load_si128((simde__m128i*)ctx.v8.s16), simde_mm_load_si128((simde__m128i*)ctx.v23.s16)));
	// stvewx v26,r3,r12
	ea = (ctx.r3.u32 + ctx.r12.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v26.u32[3 - ((ea & 0xF) >> 2)]);
	// add r9,r6,r8
	ctx.r9.u64 = ctx.r6.u64 + ctx.r8.u64;
	// stvewx v26,r4,r12
	ea = (ctx.r4.u32 + ctx.r12.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v26.u32[3 - ((ea & 0xF) >> 2)]);
	// vpkshus v29,v29,v29
	simde_mm_store_si128((simde__m128i*)ctx.v29.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v29.s16), simde_mm_load_si128((simde__m128i*)ctx.v29.s16)));
	// stvewx v27,r3,r7
	ea = (ctx.r3.u32 + ctx.r7.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v27.u32[3 - ((ea & 0xF) >> 2)]);
	// vpkshus v30,v30,v30
	simde_mm_store_si128((simde__m128i*)ctx.v30.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v30.s16), simde_mm_load_si128((simde__m128i*)ctx.v30.s16)));
	// stvewx v27,r4,r7
	ea = (ctx.r4.u32 + ctx.r7.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v27.u32[3 - ((ea & 0xF) >> 2)]);
	// add r10,r12,r8
	ctx.r10.u64 = ctx.r12.u64 + ctx.r8.u64;
	// stvewx v28,r3,r8
	ea = (ctx.r3.u32 + ctx.r8.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v28.u32[3 - ((ea & 0xF) >> 2)]);
	// vpkshus v31,v31,v31
	simde_mm_store_si128((simde__m128i*)ctx.v31.u8, simde_mm_packus_epi16(simde_mm_load_si128((simde__m128i*)ctx.v31.s16), simde_mm_load_si128((simde__m128i*)ctx.v31.s16)));
	// add r11,r7,r8
	ctx.r11.u64 = ctx.r7.u64 + ctx.r8.u64;
	// stvewx v28,r4,r8
	ea = (ctx.r4.u32 + ctx.r8.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v28.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v29,r3,r9
	ea = (ctx.r3.u32 + ctx.r9.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v29.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v29,r4,r9
	ea = (ctx.r4.u32 + ctx.r9.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v29.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v30,r3,r10
	ea = (ctx.r3.u32 + ctx.r10.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v30.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v30,r4,r10
	ea = (ctx.r4.u32 + ctx.r10.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v30.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v31,r3,r11
	ea = (ctx.r3.u32 + ctx.r11.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v31.u32[3 - ((ea & 0xF) >> 2)]);
	// stvewx v31,r4,r11
	ea = (ctx.r4.u32 + ctx.r11.u32) & ~0x3;
	PPC_STORE_U32(ea, ctx.v31.u32[3 - ((ea & 0xF) >> 2)]);
	// blr 
	return;
}

__attribute__((alias("__imp__sub_82B74600"))) PPC_WEAK_FUNC(sub_82B74600);
PPC_FUNC_IMPL(__imp__sub_82B74600) {
	PPC_FUNC_PROLOGUE();
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82ae15f0
	ctx.lr = 0x82B74608;
	__savegprlr_14(ctx, base);
	// stwu r1,-1728(r1)
	ea = -1728 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// lis r10,1
	ctx.r10.s64 = 65536;
	// mr r11,r3
	ctx.r11.u64 = ctx.r3.u64;
	// ori r8,r10,39772
	ctx.r8.u64 = ctx.r10.u64 | 39772;
	// mr r29,r4
	ctx.r29.u64 = ctx.r4.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// addi r9,r1,223
	ctx.r9.s64 = ctx.r1.s64 + 223;
	// addi r7,r1,796
	ctx.r7.s64 = ctx.r1.s64 + 796;
	// lwzx r10,r11,r8
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r8.u32);
	// rlwinm r6,r9,0,0,24
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 0) & 0xFFFFFF80;
	// rlwinm r5,r7,0,0,27
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 0) & 0xFFFFFFF0;
	// lwz r25,1312(r29)
	ctx.r25.u64 = PPC_LOAD_U32(ctx.r29.u32 + 1312);
	// stw r6,40(r31)
	PPC_STORE_U32(ctx.r31.u32 + 40, ctx.r6.u32);
	// addi r4,r10,-1
	ctx.r4.s64 = ctx.r10.s64 + -1;
	// stw r5,44(r31)
	PPC_STORE_U32(ctx.r31.u32 + 44, ctx.r5.u32);
	// li r15,0
	ctx.r15.s64 = 0;
	// lwz r10,22492(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 22492);
	// mr r19,r25
	ctx.r19.u64 = ctx.r25.u64;
	// stw r10,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r10.u32);
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// lwz r11,22504(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 22504);
	// addi r14,r11,4
	ctx.r14.s64 = ctx.r11.s64 + 4;
	// stw r11,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r11.u32);
	// mr r21,r15
	ctx.r21.u64 = ctx.r15.u64;
	// lwz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// mr r20,r15
	ctx.r20.u64 = ctx.r15.u64;
	// stw r15,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r15.u32);
	// mr r18,r15
	ctx.r18.u64 = ctx.r15.u64;
	// stw r15,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r15.u32);
	// mr r17,r15
	ctx.r17.u64 = ctx.r15.u64;
	// sth r15,16(r31)
	PPC_STORE_U16(ctx.r31.u32 + 16, ctx.r15.u16);
	// clrlwi r7,r9,16
	ctx.r7.u64 = ctx.r9.u32 & 0xFFFF;
	// lhz r6,50(r29)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r29.u32 + 50);
	// rlwinm r8,r9,16,22,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0x3FF;
	// lhz r5,74(r29)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r29.u32 + 74);
	// mr r23,r15
	ctx.r23.u64 = ctx.r15.u64;
	// lhz r11,76(r29)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r29.u32 + 76);
	// lhz r10,52(r29)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r29.u32 + 52);
	// rlwinm r16,r10,31,1,31
	ctx.r16.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r4,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r4.u32);
	// rlwinm r24,r6,31,1,31
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r5,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r5.u32);
	// cmplwi cr6,r16,0
	ctx.cr6.compare<uint32_t>(ctx.r16.u32, 0, ctx.xer);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// beq cr6,0x82b74840
	if (ctx.cr6.eq) goto loc_82B74840;
	// lis r27,-31762
	ctx.r27.s64 = -2081554432;
	// lis r26,-31762
	ctx.r26.s64 = -2081554432;
loc_82B746C4:
	// stw r18,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r18.u32);
	// cmplw cr6,r23,r8
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r8.u32, ctx.xer);
	// stw r17,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r17.u32);
	// sth r15,18(r31)
	PPC_STORE_U16(ctx.r31.u32 + 18, ctx.r15.u16);
	// bne cr6,0x82b747ec
	if (!ctx.cr6.eq) goto loc_82B747EC;
	// mr r22,r15
	ctx.r22.u64 = ctx.r15.u64;
	// cmplwi cr6,r24,0
	ctx.cr6.compare<uint32_t>(ctx.r24.u32, 0, ctx.xer);
	// beq cr6,0x82b747ec
	if (ctx.cr6.eq) goto loc_82B747EC;
loc_82B746E4:
	// cmplw cr6,r22,r7
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, ctx.r7.u32, ctx.xer);
	// bne cr6,0x82b74798
	if (!ctx.cr6.eq) goto loc_82B74798;
	// ld r11,0(r25)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r25.u32 + 0);
	// mr r30,r15
	ctx.r30.u64 = ctx.r15.u64;
	// rldicl r10,r11,8,56
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFF;
	// clrlwi r28,r10,26
	ctx.r28.u64 = ctx.r10.u32 & 0x3F;
loc_82B746FC:
	// srawi r11,r30,2
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r30.s32 >> 2;
	// lwz r10,28(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// addi r9,r30,140
	ctx.r9.s64 = ctx.r30.s64 + 140;
	// lwz r8,40(r31)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// addi r7,r11,2
	ctx.r7.s64 = ctx.r11.s64 + 2;
	// rlwinm r6,r9,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r3,r10,-128
	ctx.r3.s64 = ctx.r10.s64 + -128;
	// li r4,-128
	ctx.r4.s64 = -128;
	// lwzx r10,r6,r29
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r29.u32);
	// lwzx r11,r5,r31
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r31.u32);
	// stw r3,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r3.u32);
	// add r7,r10,r11
	ctx.r7.u64 = ctx.r10.u64 + ctx.r11.u64;
	// dcbt r4,r3
	// dcbzl r0,r8
	ea = (ctx.r8.u32) & ~127;
	memset((void*)PPC_RAW_ADDR(ea), 0, 128);
	// srawi r10,r30,2
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x3) != 0);
	ctx.r10.s64 = ctx.r30.s32 >> 2;
	// lwz r8,392(r29)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r29.u32 + 392);
	// rlwinm r11,r28,6,18,25
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 6) & 0x3FC0;
	// addi r10,r10,45
	ctx.r10.s64 = ctx.r10.s64 + 45;
	// lwz r9,32064(r26)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r26.u32 + 32064);
	// add r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 + ctx.r8.u64;
	// lwz r6,32060(r27)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r27.u32 + 32060);
	// rlwinm r8,r10,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r4,40(r31)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r31.u32 + 40);
	// lhzx r8,r8,r29
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r29.u32);
	// bl 0x82a353a8
	ctx.lr = 0x82B74764;
	sub_82A353A8(ctx, base);
	// addi r30,r30,1
	ctx.r30.s64 = ctx.r30.s64 + 1;
	// cmpwi cr6,r30,6
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 6, ctx.xer);
	// blt cr6,0x82b746fc
	if (ctx.cr6.lt) goto loc_82B746FC;
	// lwz r11,0(r14)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r14.u32 + 0);
	// addi r14,r14,4
	ctx.r14.s64 = ctx.r14.s64 + 4;
	// lwz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 80);
	// rlwinm r8,r11,16,22,31
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 16) & 0x3FF;
	// addi r9,r10,-1
	ctx.r9.s64 = ctx.r10.s64 + -1;
	// clrlwi r7,r11,16
	ctx.r7.u64 = ctx.r11.u32 & 0xFFFF;
	// stw r9,80(r1)
	PPC_STORE_U32(ctx.r1.u32 + 80, ctx.r9.u32);
	// cmplw cr6,r23,r8
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r8.u32, ctx.xer);
	// beq cr6,0x82b746e4
	if (ctx.cr6.eq) goto loc_82B746E4;
	// b 0x82b747ec
	goto loc_82B747EC;
loc_82B74798:
	// cmplw cr6,r23,r8
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r8.u32, ctx.xer);
	// bne cr6,0x82b747ec
	if (!ctx.cr6.eq) goto loc_82B747EC;
	// lhz r10,18(r31)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r31.u32 + 18);
	// addi r22,r22,1
	ctx.r22.s64 = ctx.r22.s64 + 1;
	// lwz r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 0);
	// addi r25,r25,8
	ctx.r25.s64 = ctx.r25.s64 + 8;
	// lwz r9,4(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 4);
	// addi r6,r10,2
	ctx.r6.s64 = ctx.r10.s64 + 2;
	// addi r5,r11,2
	ctx.r5.s64 = ctx.r11.s64 + 2;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r4,r9,1
	ctx.r4.s64 = ctx.r9.s64 + 1;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// stw r5,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r5.u32);
	// addi r9,r11,8
	ctx.r9.s64 = ctx.r11.s64 + 8;
	// stw r4,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r4.u32);
	// sth r6,18(r31)
	PPC_STORE_U16(ctx.r31.u32 + 18, ctx.r6.u16);
	// cmplw cr6,r22,r24
	ctx.cr6.compare<uint32_t>(ctx.r22.u32, ctx.r24.u32, ctx.xer);
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// stw r9,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r9.u32);
	// blt cr6,0x82b746e4
	if (ctx.cr6.lt) goto loc_82B746E4;
loc_82B747EC:
	// rlwinm r10,r24,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r9,16(r31)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r31.u32 + 16);
	// rlwinm r11,r24,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r6,88(r1)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lwz r5,84(r1)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// add r21,r10,r21
	ctx.r21.u64 = ctx.r10.u64 + ctx.r21.u64;
	// add r19,r11,r19
	ctx.r19.u64 = ctx.r11.u64 + ctx.r19.u64;
	// addi r4,r9,2
	ctx.r4.s64 = ctx.r9.s64 + 2;
	// stw r21,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r21.u32);
	// add r20,r24,r20
	ctx.r20.u64 = ctx.r24.u64 + ctx.r20.u64;
	// rlwinm r10,r6,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 4) & 0xFFFFFFF0;
	// sth r4,16(r31)
	PPC_STORE_U16(ctx.r31.u32 + 16, ctx.r4.u16);
	// rlwinm r11,r5,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r20,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r20.u32);
	// addi r23,r23,1
	ctx.r23.s64 = ctx.r23.s64 + 1;
	// mr r25,r19
	ctx.r25.u64 = ctx.r19.u64;
	// add r18,r10,r18
	ctx.r18.u64 = ctx.r10.u64 + ctx.r18.u64;
	// add r17,r11,r17
	ctx.r17.u64 = ctx.r11.u64 + ctx.r17.u64;
	// cmplw cr6,r23,r16
	ctx.cr6.compare<uint32_t>(ctx.r23.u32, ctx.r16.u32, ctx.xer);
	// blt cr6,0x82b746c4
	if (ctx.cr6.lt) goto loc_82B746C4;
	// li r3,0
	ctx.r3.s64 = 0;
loc_82B74840:
	// addi r1,r1,1728
	ctx.r1.s64 = ctx.r1.s64 + 1728;
	// b 0x82ae1640
	__restgprlr_14(ctx, base);
	return;
}

__attribute__((alias("__imp__sub_82B74A00"))) PPC_WEAK_FUNC(sub_82B74A00);
PPC_FUNC_IMPL(__imp__sub_82B74A00) {
	PPC_FUNC_PROLOGUE();
	PPCRegister temp{};
	uint32_t ea{};
	// mflr r12
	ctx.r12.u64 = ctx.lr;
	// bl 0x82ae15f0
	ctx.lr = 0x82B74A08;
	__savegprlr_14(ctx, base);
	// stwu r1,-336(r1)
	ea = -336 + ctx.r1.u32;
	PPC_STORE_U32(ea, ctx.r1.u32);
	ctx.r1.u32 = ea;
	// mr r15,r3
	ctx.r15.u64 = ctx.r3.u64;
	// mr r31,r5
	ctx.r31.u64 = ctx.r5.u64;
	// mr r18,r4
	ctx.r18.u64 = ctx.r4.u64;
	// stw r15,356(r1)
	PPC_STORE_U32(ctx.r1.u32 + 356, ctx.r15.u32);
	// stw r31,372(r1)
	PPC_STORE_U32(ctx.r1.u32 + 372, ctx.r31.u32);
	// li r17,1
	ctx.r17.s64 = 1;
	// li r25,0
	ctx.r25.s64 = 0;
	// lwz r11,2952(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 2952);
	// lwz r10,2112(r15)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r15.u32 + 2112);
	// addi r8,r11,732
	ctx.r8.s64 = ctx.r11.s64 + 732;
	// lwz r9,3984(r15)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r15.u32 + 3984);
	// addi r7,r11,735
	ctx.r7.s64 = ctx.r11.s64 + 735;
	// rlwinm r6,r8,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r10,3,0,28
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// rlwinm r5,r7,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r3,r11,r15
	ctx.r3.u64 = ctx.r11.u64 + ctx.r15.u64;
	// addi r4,r10,266
	ctx.r4.s64 = ctx.r10.s64 + 266;
	// lwzx r11,r6,r15
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + ctx.r15.u32);
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// rlwinm r10,r4,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 3) & 0xFFFFFFF8;
	// stw r11,2904(r15)
	PPC_STORE_U32(ctx.r15.u32 + 2904, ctx.r11.u32);
	// lwzx r8,r5,r15
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r15.u32);
	// stw r8,2916(r15)
	PPC_STORE_U32(ctx.r15.u32 + 2916, ctx.r8.u32);
	// lwz r7,2124(r3)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r3.u32 + 2124);
	// stw r7,2116(r15)
	PPC_STORE_U32(ctx.r15.u32 + 2116, ctx.r7.u32);
	// lwzx r6,r10,r15
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + ctx.r15.u32);
	// stw r6,2120(r15)
	PPC_STORE_U32(ctx.r15.u32 + 2120, ctx.r6.u32);
	// bne cr6,0x82b74a84
	if (!ctx.cr6.eq) goto loc_82B74A84;
	// stw r25,456(r15)
	PPC_STORE_U32(ctx.r15.u32 + 456, ctx.r25.u32);
	// b 0x82b74a88
	goto loc_82B74A88;
loc_82B74A84:
	// stw r17,456(r15)
	PPC_STORE_U32(ctx.r15.u32 + 456, ctx.r17.u32);
loc_82B74A88:
	// lwz r11,14808(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 14808);
	// lwz r10,3416(r15)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r15.u32 + 3416);
	// mullw r8,r11,r10
	ctx.r8.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r10.s32);
	// rlwinm r7,r8,0,0,24
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 0) & 0xFFFFFF80;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x82b74aac
	if (ctx.cr6.eq) goto loc_82B74AAC;
	// li r11,3
	ctx.r11.s64 = 3;
	// li r10,4
	ctx.r10.s64 = 4;
	// b 0x82b74ab4
	goto loc_82B74AB4;
loc_82B74AAC:
	// li r11,4
	ctx.r11.s64 = 4;
	// li r10,3
	ctx.r10.s64 = 3;
loc_82B74AB4:
	// stw r10,14816(r15)
	PPC_STORE_U32(ctx.r15.u32 + 14816, ctx.r10.u32);
	// cmpwi cr6,r9,2
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 2, ctx.xer);
	// stw r11,14812(r15)
	PPC_STORE_U32(ctx.r15.u32 + 14812, ctx.r11.u32);
	// beq cr6,0x82b74ad0
	if (ctx.cr6.eq) goto loc_82B74AD0;
	// cmpwi cr6,r9,3
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 3, ctx.xer);
	// mr r11,r25
	ctx.r11.u64 = ctx.r25.u64;
	// bne cr6,0x82b74ad4
	if (!ctx.cr6.eq) goto loc_82B74AD4;
loc_82B74AD0:
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
loc_82B74AD4:
	// lwz r10,1996(r15)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r15.u32 + 1996);
	// li r5,1
	ctx.r5.s64 = 1;
	// stw r11,76(r10)
	PPC_STORE_U32(ctx.r10.u32 + 76, ctx.r11.u32);
	// lwz r4,248(r15)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r15.u32 + 248);
	// lwz r3,1996(r15)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r15.u32 + 1996);
	// bl 0x82a27298
	ctx.lr = 0x82B74AEC;
	sub_82A27298(ctx, base);
	// lwz r11,248(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 248);
	// cmpwi cr6,r11,5
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 5, ctx.xer);
	// bge cr6,0x82b74b08
	if (!ctx.cr6.lt) goto loc_82B74B08;
	// addi r11,r15,2488
	ctx.r11.s64 = ctx.r15.s64 + 2488;
	// addi r10,r15,2504
	ctx.r10.s64 = ctx.r15.s64 + 2504;
	// addi r9,r15,2544
	ctx.r9.s64 = ctx.r15.s64 + 2544;
	// b 0x82b74b2c
	goto loc_82B74B2C;
loc_82B74B08:
	// cmpwi cr6,r11,13
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 13, ctx.xer);
	// bge cr6,0x82b74b20
	if (!ctx.cr6.lt) goto loc_82B74B20;
	// addi r11,r15,2476
	ctx.r11.s64 = ctx.r15.s64 + 2476;
	// addi r10,r15,2516
	ctx.r10.s64 = ctx.r15.s64 + 2516;
	// addi r9,r15,2556
	ctx.r9.s64 = ctx.r15.s64 + 2556;
	// b 0x82b74b2c
	goto loc_82B74B2C;
loc_82B74B20:
	// addi r11,r15,2464
	ctx.r11.s64 = ctx.r15.s64 + 2464;
	// addi r10,r15,2528
	ctx.r10.s64 = ctx.r15.s64 + 2528;
	// addi r9,r15,2568
	ctx.r9.s64 = ctx.r15.s64 + 2568;
loc_82B74B2C:
	// stw r11,2500(r15)
	PPC_STORE_U32(ctx.r15.u32 + 2500, ctx.r11.u32);
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// stw r10,2540(r15)
	PPC_STORE_U32(ctx.r15.u32 + 2540, ctx.r10.u32);
	// stw r9,2580(r15)
	PPC_STORE_U32(ctx.r15.u32 + 2580, ctx.r9.u32);
	// lwz r11,268(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 268);
	// stw r11,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r11.u32);
	// bl 0x829e8f00
	ctx.lr = 0x82B74B48;
	sub_829E8F00(ctx, base);
	// mr r4,r18
	ctx.r4.u64 = ctx.r18.u64;
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// bl 0x82a0e3e0
	ctx.lr = 0x82B74B54;
	sub_82A0E3E0(ctx, base);
	// lwz r10,22488(r15)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r15.u32 + 22488);
	// lhz r9,50(r18)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r18.u32 + 50);
	// mr r28,r25
	ctx.r28.u64 = ctx.r25.u64;
	// lhz r8,52(r18)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r18.u32 + 52);
	// mr r27,r25
	ctx.r27.u64 = ctx.r25.u64;
	// mr r14,r25
	ctx.r14.u64 = ctx.r25.u64;
	// stw r25,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r25.u32);
	// rlwinm r26,r8,31,1,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// stw r28,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r28.u32);
	// stw r10,20(r31)
	PPC_STORE_U32(ctx.r31.u32 + 20, ctx.r10.u32);
	// rlwinm r7,r9,31,1,31
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 31) & 0x7FFFFFFF;
	// lwz r6,22500(r15)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r15.u32 + 22500);
	// cmpwi cr6,r26,0
	ctx.cr6.compare<int32_t>(ctx.r26.s32, 0, ctx.xer);
	// stw r6,24(r31)
	PPC_STORE_U32(ctx.r31.u32 + 24, ctx.r6.u32);
	// lwz r5,22492(r15)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r15.u32 + 22492);
	// stw r5,28(r31)
	PPC_STORE_U32(ctx.r31.u32 + 28, ctx.r5.u32);
	// lwz r4,22504(r15)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r15.u32 + 22504);
	// stw r27,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r27.u32);
	// stw r14,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r14.u32);
	// stw r7,112(r1)
	PPC_STORE_U32(ctx.r1.u32 + 112, ctx.r7.u32);
	// stw r26,136(r1)
	PPC_STORE_U32(ctx.r1.u32 + 136, ctx.r26.u32);
	// stw r4,32(r31)
	PPC_STORE_U32(ctx.r31.u32 + 32, ctx.r4.u32);
	// stw r25,0(r31)
	PPC_STORE_U32(ctx.r31.u32 + 0, ctx.r25.u32);
	// stw r25,4(r31)
	PPC_STORE_U32(ctx.r31.u32 + 4, ctx.r25.u32);
	// sth r25,16(r31)
	PPC_STORE_U16(ctx.r31.u32 + 16, ctx.r25.u16);
	// sth r25,18(r31)
	PPC_STORE_U16(ctx.r31.u32 + 18, ctx.r25.u16);
	// ble cr6,0x82b775fc
	if (!ctx.cr6.gt) goto loc_82B775FC;
	// lis r11,-32250
	ctx.r11.s64 = -2113536000;
	// lis r10,-32250
	ctx.r10.s64 = -2113536000;
	// addi r16,r11,14656
	ctx.r16.s64 = ctx.r11.s64 + 14656;
	// addi r11,r10,14216
	ctx.r11.s64 = ctx.r10.s64 + 14216;
	// stw r16,116(r1)
	PPC_STORE_U32(ctx.r1.u32 + 116, ctx.r16.u32);
	// stw r11,88(r1)
	PPC_STORE_U32(ctx.r1.u32 + 88, ctx.r11.u32);
loc_82B74BD8:
	// stw r28,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r28.u32);
	// sth r25,18(r31)
	PPC_STORE_U16(ctx.r31.u32 + 18, ctx.r25.u16);
	// stw r27,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r27.u32);
	// lwz r11,22164(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 22164);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b74df4
	if (ctx.cr6.eq) goto loc_82B74DF4;
	// lwz r11,1304(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 1304);
	// rlwinm r10,r14,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r9,r11,r10
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r10.u32);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// beq cr6,0x82b74df4
	if (ctx.cr6.eq) goto loc_82B74DF4;
	// lwz r11,84(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// ld r10,104(r18)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r18.u32 + 104);
	// std r10,0(r11)
	PPC_STORE_U64(ctx.r11.u32 + 0, ctx.r10.u64);
	// lwz r9,112(r18)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r18.u32 + 112);
	// lwz r8,84(r15)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// stw r9,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r9.u32);
	// lwz r7,84(r15)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r6,116(r18)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r18.u32 + 116);
	// stw r6,12(r7)
	PPC_STORE_U32(ctx.r7.u32 + 12, ctx.r6.u32);
	// lwz r5,84(r15)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r4,120(r18)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r18.u32 + 120);
	// stw r4,16(r5)
	PPC_STORE_U32(ctx.r5.u32 + 16, ctx.r4.u32);
	// lwz r3,84(r15)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r11,124(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 124);
	// stw r11,20(r3)
	PPC_STORE_U32(ctx.r3.u32 + 20, ctx.r11.u32);
	// lwz r10,84(r15)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r9,128(r18)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r18.u32 + 128);
	// stw r9,24(r10)
	PPC_STORE_U32(ctx.r10.u32 + 24, ctx.r9.u32);
	// lwz r8,84(r15)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r7,132(r18)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r18.u32 + 132);
	// stw r7,28(r8)
	PPC_STORE_U32(ctx.r8.u32 + 28, ctx.r7.u32);
	// lwz r6,84(r15)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r5,136(r18)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r18.u32 + 136);
	// stw r5,32(r6)
	PPC_STORE_U32(ctx.r6.u32 + 32, ctx.r5.u32);
	// lwz r4,84(r15)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r3,140(r18)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r18.u32 + 140);
	// stw r3,36(r4)
	PPC_STORE_U32(ctx.r4.u32 + 36, ctx.r3.u32);
	// lwz r11,84(r15)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r10,144(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 144);
	// stw r10,40(r11)
	PPC_STORE_U32(ctx.r11.u32 + 40, ctx.r10.u32);
	// lwz r9,84(r15)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r8,148(r18)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r18.u32 + 148);
	// stw r8,44(r9)
	PPC_STORE_U32(ctx.r9.u32 + 44, ctx.r8.u32);
	// lwz r7,84(r15)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r6,152(r18)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r18.u32 + 152);
	// stw r6,48(r7)
	PPC_STORE_U32(ctx.r7.u32 + 48, ctx.r6.u32);
	// lwz r31,84(r15)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r5,28(r31)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r31.u32 + 28);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// beq cr6,0x82b74d3c
	if (ctx.cr6.eq) goto loc_82B74D3C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// mr r29,r25
	ctx.r29.u64 = ctx.r25.u64;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x82b74d14
	if (!ctx.cr6.lt) goto loc_82B74D14;
loc_82B74CBC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82b74d14
	if (ctx.cr6.eq) goto loc_82B74D14;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x82b74d04
	if (!ctx.cr0.lt) goto loc_82B74D04;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B74D04;
	sub_829DD138(ctx, base);
loc_82B74D04:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82b74cbc
	if (ctx.cr6.gt) goto loc_82B74CBC;
loc_82B74D14:
	// ld r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r10,r30,32
	ctx.r10.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// sld r8,r11,r10
	ctx.r8.u64 = ctx.r10.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r10.u8 & 0x7F));
	// subf. r7,r30,r9
	ctx.r7.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// std r8,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// stw r7,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge 0x82b74d3c
	if (!ctx.cr0.lt) goto loc_82B74D3C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B74D3C;
	sub_829DD138(ctx, base);
loc_82B74D3C:
	// lwz r11,8(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// clrlwi r4,r11,29
	ctx.r4.u64 = ctx.r11.u32 & 0x7;
	// bl 0x829dd208
	ctx.lr = 0x82B74D4C;
	sub_829DD208(ctx, base);
	// mr r4,r14
	ctx.r4.u64 = ctx.r14.u64;
	// mr r3,r15
	ctx.r3.u64 = ctx.r15.u64;
	// bl 0x82a15e08
	ctx.lr = 0x82B74D58;
	sub_82A15E08(ctx, base);
	// lwz r10,84(r15)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// ld r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r10.u32 + 0);
	// std r9,104(r18)
	PPC_STORE_U64(ctx.r18.u32 + 104, ctx.r9.u64);
	// lwz r8,84(r15)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r7,8(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// stw r7,112(r18)
	PPC_STORE_U32(ctx.r18.u32 + 112, ctx.r7.u32);
	// lwz r6,84(r15)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r5,12(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 12);
	// stw r5,116(r18)
	PPC_STORE_U32(ctx.r18.u32 + 116, ctx.r5.u32);
	// lwz r4,84(r15)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r11,16(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 16);
	// stw r11,120(r18)
	PPC_STORE_U32(ctx.r18.u32 + 120, ctx.r11.u32);
	// lwz r10,84(r15)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// stw r9,124(r18)
	PPC_STORE_U32(ctx.r18.u32 + 124, ctx.r9.u32);
	// lwz r8,84(r15)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r7,24(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 24);
	// stw r7,128(r18)
	PPC_STORE_U32(ctx.r18.u32 + 128, ctx.r7.u32);
	// lwz r6,84(r15)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r5,28(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 28);
	// stw r5,132(r18)
	PPC_STORE_U32(ctx.r18.u32 + 132, ctx.r5.u32);
	// lwz r4,84(r15)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r11,32(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 32);
	// stw r11,136(r18)
	PPC_STORE_U32(ctx.r18.u32 + 136, ctx.r11.u32);
	// lwz r10,84(r15)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r9,36(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 36);
	// stw r9,140(r18)
	PPC_STORE_U32(ctx.r18.u32 + 140, ctx.r9.u32);
	// lwz r8,84(r15)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r7,40(r8)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r8.u32 + 40);
	// stw r7,144(r18)
	PPC_STORE_U32(ctx.r18.u32 + 144, ctx.r7.u32);
	// lwz r6,84(r15)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r5,44(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 44);
	// stw r5,148(r18)
	PPC_STORE_U32(ctx.r18.u32 + 148, ctx.r5.u32);
	// lwz r4,84(r15)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r11,48(r4)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r4.u32 + 48);
	// stw r11,152(r18)
	PPC_STORE_U32(ctx.r18.u32 + 152, ctx.r11.u32);
	// stb r17,1251(r18)
	PPC_STORE_U8(ctx.r18.u32 + 1251, ctx.r17.u8);
	// bne cr6,0x82b776bc
	if (!ctx.cr6.eq) goto loc_82B776BC;
loc_82B74DF4:
	// lwz r11,112(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// stw r25,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r25.u32);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// ble cr6,0x82b77594
	if (!ctx.cr6.gt) goto loc_82B77594;
loc_82B74E04:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r26,84(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// li r10,128
	ctx.r10.s64 = 128;
	// ori r25,r11,32768
	ctx.r25.u64 = ctx.r11.u64 | 32768;
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r9,12(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 12);
	// dcbt r10,r9
	// lis r12,-4289
	ctx.r12.s64 = -281083904;
	// lwz r8,0(r26)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// li r19,0
	ctx.r19.s64 = 0;
	// ori r12,r12,63743
	ctx.r12.u64 = ctx.r12.u64 | 63743;
	// li r22,0
	ctx.r22.s64 = 0;
	// and r7,r8,r12
	ctx.r7.u64 = ctx.r8.u64 & ctx.r12.u64;
	// li r30,0
	ctx.r30.s64 = 0;
	// stw r7,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r7.u32);
	// li r20,0
	ctx.r20.s64 = 0;
	// li r21,0
	ctx.r21.s64 = 0;
	// lbz r6,24(r18)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r18.u32 + 24);
	// stb r6,4(r26)
	PPC_STORE_U8(ctx.r26.u32 + 4, ctx.r6.u8);
	// lwz r5,1824(r18)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r18.u32 + 1824);
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x82b74e90
	if (!ctx.cr6.eq) goto loc_82B74E90;
	// lwz r3,0(r18)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x82b74e84
	if (!ctx.cr0.lt) goto loc_82B74E84;
	// bl 0x829dd138
	ctx.lr = 0x82B74E84;
	sub_829DD138(ctx, base);
loc_82B74E84:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// rlwimi r11,r31,5,24,26
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 5) & 0xE0) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF1F);
	// stw r11,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
loc_82B74E90:
	// lbz r11,26(r18)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r18.u32 + 26);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82b74ed0
	if (!ctx.cr6.eq) goto loc_82B74ED0;
	// lwz r3,0(r18)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x82b74ec4
	if (!ctx.cr0.lt) goto loc_82B74EC4;
	// bl 0x829dd138
	ctx.lr = 0x82B74EC4;
	sub_829DD138(ctx, base);
loc_82B74EC4:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// rlwimi r11,r31,31,0,0
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r31.u32 | (ctx.r31.u64 << 32), 31) & 0x80000000) | (ctx.r11.u64 & 0xFFFFFFFF7FFFFFFF);
	// stw r11,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
loc_82B74ED0:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// rlwinm r10,r11,0,24,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xE0;
	// cmplwi cr6,r10,32
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 32, ctx.xer);
	// bne cr6,0x82b74ee8
	if (!ctx.cr6.eq) goto loc_82B74EE8;
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// b 0x82b7538c
	goto loc_82B7538C;
loc_82B74EE8:
	// rlwinm r11,r11,0,0,0
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// bne cr6,0x82b752d4
	if (!ctx.cr6.eq) goto loc_82B752D4;
	// lwz r31,0(r18)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r10,336(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 336);
	// ld r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r29,0(r10)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rldicl r9,r11,10,54
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 10) & 0x3FF;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r8,r29
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r29.u32);
	// extsh r30,r7
	ctx.r30.s64 = ctx.r7.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82b74fdc
	if (ctx.cr6.lt) goto loc_82B74FDC;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r9,r30,28
	ctx.r9.u64 = ctx.r30.u32 & 0xF;
	// sld r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r9.u8 & 0x7F));
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// std r8,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge cr6,0x82b74fd4
	if (!ctx.cr6.lt) goto loc_82B74FD4;
loc_82B74F3C:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82b74f68
	if (ctx.cr6.lt) goto loc_82B74F68;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd078
	ctx.lr = 0x82B74F58;
	sub_829DD078(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x82b74f3c
	if (ctx.cr6.eq) goto loc_82B74F3C;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x82b75018
	goto loc_82B75018;
loc_82B74F68:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r10,r10,8,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r8,2(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r7,3(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r5,5(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r9,r10,8,55
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// ld r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r8
	ctx.r3.s64 = ctx.r8.s32;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// add r9,r11,r6
	ctx.r9.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// sld r11,r11,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r3.u8 & 0x7F));
	// add r8,r11,r4
	ctx.r8.u64 = ctx.r11.u64 + ctx.r4.u64;
	// std r8,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
loc_82B74FD4:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x82b75018
	goto loc_82B75018;
loc_82B74FDC:
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd208
	ctx.lr = 0x82B74FE8;
	sub_829DD208(ctx, base);
loc_82B74FE8:
	// ld r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x829dd208
	ctx.lr = 0x82B75000;
	sub_829DD208(ctx, base);
	// add r10,r30,r25
	ctx.r10.u64 = ctx.r30.u64 + ctx.r25.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82b74fe8
	if (ctx.cr6.lt) goto loc_82B74FE8;
loc_82B75018:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// mr r10,r17
	ctx.r10.u64 = ctx.r17.u64;
	// cmpwi cr6,r11,37
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 37, ctx.xer);
	// bge cr6,0x82b7502c
	if (!ctx.cr6.lt) goto loc_82B7502C;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82B7502C:
	// extsw r23,r10
	ctx.r23.s64 = ctx.r10.s32;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82b7503c
	if (ctx.cr6.eq) goto loc_82B7503C;
	// addi r11,r11,-37
	ctx.r11.s64 = ctx.r11.s64 + -37;
loc_82B7503C:
	// li r24,0
	ctx.r24.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b752b0
	if (ctx.cr6.eq) goto loc_82B752B0;
	// cmpwi cr6,r11,35
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 35, ctx.xer);
	// bge cr6,0x82b75198
	if (!ctx.cr6.lt) goto loc_82B75198;
	// lwz r10,12(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// srawi r7,r8,24
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFFFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 24;
	// srawi r6,r8,4
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 4;
	// srawi r5,r8,8
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 8;
	// clrlwi r11,r8,28
	ctx.r11.u64 = ctx.r8.u32 & 0xF;
	// clrlwi r28,r6,28
	ctx.r28.u64 = ctx.r6.u32 & 0xF;
	// srawi r4,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 16;
	// add. r30,r28,r11
	ctx.r30.u64 = ctx.r28.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// clrlwi r27,r7,24
	ctx.r27.u64 = ctx.r7.u32 & 0xFF;
	// clrlwi r26,r5,24
	ctx.r26.u64 = ctx.r5.u32 & 0xFF;
	// clrlwi r25,r4,24
	ctx.r25.u64 = ctx.r4.u32 & 0xFF;
	// ble 0x82b75148
	if (!ctx.cr0.gt) goto loc_82B75148;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// bgt cr6,0x82b75148
	if (ctx.cr6.gt) goto loc_82B75148;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82b75148
	if (ctx.cr6.eq) goto loc_82B75148;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82b75104
	if (!ctx.cr6.gt) goto loc_82B75104;
loc_82B750AC:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82b75104
	if (ctx.cr6.eq) goto loc_82B75104;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x82b750f4
	if (!ctx.cr0.lt) goto loc_82B750F4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B750F4;
	sub_829DD138(ctx, base);
loc_82B750F4:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82b750ac
	if (ctx.cr6.gt) goto loc_82B750AC;
loc_82B75104:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x82b75140
	if (!ctx.cr0.lt) goto loc_82B75140;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B75140;
	sub_829DD138(ctx, base);
loc_82B75140:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// b 0x82b7514c
	goto loc_82B7514C;
loc_82B75148:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82B7514C:
	// sraw r11,r10,r28
	temp.u32 = ctx.r28.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r11.s64 = ctx.r10.s32 >> temp.u32;
	// and r9,r10,r27
	ctx.r9.u64 = ctx.r10.u64 & ctx.r27.u64;
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// clrlwi r8,r11,31
	ctx.r8.u64 = ctx.r11.u32 & 0x1;
	// srawi r11,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 1;
	// clrlwi r7,r9,31
	ctx.r7.u64 = ctx.r9.u32 & 0x1;
	// add r6,r11,r25
	ctx.r6.u64 = ctx.r11.u64 + ctx.r25.u64;
	// neg r4,r7
	ctx.r4.s64 = static_cast<int64_t>(-ctx.r7.u64);
	// neg r5,r8
	ctx.r5.s64 = static_cast<int64_t>(-ctx.r8.u64);
	// add r3,r10,r26
	ctx.r3.u64 = ctx.r10.u64 + ctx.r26.u64;
	// lwz r26,84(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// xor r11,r6,r4
	ctx.r11.u64 = ctx.r6.u64 ^ ctx.r4.u64;
	// xor r10,r3,r5
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r5.u64;
	// subf r9,r4,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r4.u64;
	// subf r11,r5,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r5.u64;
	// lis r8,0
	ctx.r8.s64 = 0;
	// rlwimi r11,r9,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
	// ori r25,r8,32768
	ctx.r25.u64 = ctx.r8.u64 | 32768;
	// b 0x82b752b0
	goto loc_82B752B0;
loc_82B75198:
	// cmpwi cr6,r11,36
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 36, ctx.xer);
	// bne cr6,0x82b751ac
	if (!ctx.cr6.eq) goto loc_82B751AC;
	// mr r24,r17
	ctx.r24.u64 = ctx.r17.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82b752b0
	goto loc_82B752B0;
loc_82B751AC:
	// lbz r11,30(r18)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r18.u32 + 30);
	// li r29,0
	ctx.r29.s64 = 0;
	// lhz r10,70(r18)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r18.u32 + 70);
	// lhz r9,72(r18)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r18.u32 + 72);
	// subf r27,r11,r10
	ctx.r27.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// subf r28,r11,r9
	ctx.r28.u64 = ctx.r9.u64 - ctx.r11.u64;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// add r30,r28,r27
	ctx.r30.u64 = ctx.r28.u64 + ctx.r27.u64;
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// ble cr6,0x82b751e0
	if (!ctx.cr6.gt) goto loc_82B751E0;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82b75290
	goto loc_82B75290;
loc_82B751E0:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82b751f0
	if (!ctx.cr6.eq) goto loc_82B751F0;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82b75290
	goto loc_82B75290;
loc_82B751F0:
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82b75250
	if (!ctx.cr6.gt) goto loc_82B75250;
loc_82B751F8:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82b75250
	if (ctx.cr6.eq) goto loc_82B75250;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x82b75240
	if (!ctx.cr0.lt) goto loc_82B75240;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B75240;
	sub_829DD138(ctx, base);
loc_82B75240:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82b751f8
	if (ctx.cr6.gt) goto loc_82B751F8;
loc_82B75250:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x82b7528c
	if (!ctx.cr0.lt) goto loc_82B7528C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B7528C;
	sub_829DD138(ctx, base);
loc_82B7528C:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_82B75290:
	// slw r11,r17,r27
	ctx.r11.u64 = ctx.r27.u8 & 0x20 ? 0 : (ctx.r17.u32 << (ctx.r27.u8 & 0x3F));
	// slw r9,r17,r28
	ctx.r9.u64 = ctx.r28.u8 & 0x20 ? 0 : (ctx.r17.u32 << (ctx.r28.u8 & 0x3F));
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// sraw r8,r10,r28
	temp.u32 = ctx.r28.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r8.s64 = ctx.r10.s32 >> temp.u32;
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// and r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 & ctx.r8.u64;
	// and r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 & ctx.r10.u64;
	// rlwimi r11,r6,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
loc_82B752B0:
	// rldicr r10,r23,8,55
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// clrldi r9,r11,32
	ctx.r9.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// or r8,r10,r24
	ctx.r8.u64 = ctx.r10.u64 | ctx.r24.u64;
	// rldimi r9,r8,32,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r9.u64 & 0xFFFFFFFF);
	// rldicl r7,r9,24,40
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 24) & 0xFFFFFF;
	// rldicl r6,r9,32,32
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF;
	// clrlwi r30,r7,31
	ctx.r30.u64 = ctx.r7.u32 & 0x1;
	// clrlwi r22,r6,31
	ctx.r22.u64 = ctx.r6.u32 & 0x1;
	// rotlwi r20,r9,0
	ctx.r20.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
loc_82B752D4:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// rlwinm r10,r11,0,24,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xE0;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// bne cr6,0x82b7538c
	if (!ctx.cr6.eq) goto loc_82B7538C;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x82b752f8
	if (ctx.cr6.eq) goto loc_82B752F8;
	// li r10,3
	ctx.r10.s64 = 3;
	// rlwimi r11,r10,5,24,26
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xE0) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF1F);
	// b 0x82b75388
	goto loc_82B75388;
loc_82B752F8:
	// lwz r3,0(r18)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x82b75320
	if (!ctx.cr0.lt) goto loc_82B75320;
	// bl 0x829dd138
	ctx.lr = 0x82B75320;
	sub_829DD138(ctx, base);
loc_82B75320:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82b7533c
	if (!ctx.cr6.eq) goto loc_82B7533C;
	// lwz r11,1828(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 1828);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// rlwimi r10,r11,5,24,26
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xE0) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFF1F);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x82b7538c
	goto loc_82B7538C;
loc_82B7533C:
	// lwz r3,0(r18)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x82b75364
	if (!ctx.cr0.lt) goto loc_82B75364;
	// bl 0x829dd138
	ctx.lr = 0x82B75364;
	sub_829DD138(ctx, base);
loc_82B75364:
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// bne cr6,0x82b75380
	if (!ctx.cr6.eq) goto loc_82B75380;
	// lwz r11,1832(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 1832);
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// rlwimi r10,r11,5,24,26
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 5) & 0xE0) | (ctx.r10.u64 & 0xFFFFFFFFFFFFFF1F);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x82b7538c
	goto loc_82B7538C;
loc_82B75380:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// rlwimi r11,r17,6,24,26
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 6) & 0xE0) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFF1F);
loc_82B75388:
	// stw r11,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
loc_82B7538C:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// rlwinm r10,r11,0,0,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80000000;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82b753a8
	if (ctx.cr6.eq) goto loc_82B753A8;
	// li r11,0
	ctx.r11.s64 = 0;
	// stb r11,5(r26)
	PPC_STORE_U8(ctx.r26.u32 + 5, ctx.r11.u8);
	// b 0x82b761ac
	goto loc_82B761AC;
loc_82B753A8:
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// bne cr6,0x82b756f0
	if (!ctx.cr6.eq) goto loc_82B756F0;
	// oris r11,r11,16384
	ctx.r11.u64 = ctx.r11.u64 | 1073741824;
	// stw r11,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
	// lbz r10,27(r18)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r18.u32 + 27);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82b756ac
	if (ctx.cr6.eq) goto loc_82B756AC;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x82b761a8
	if (ctx.cr6.eq) goto loc_82B761A8;
	// lbz r10,1245(r18)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1245);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82b75418
	if (ctx.cr6.eq) goto loc_82B75418;
	// rlwinm r11,r11,20,28,31
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 20) & 0xF;
	// and r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 & ctx.r11.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82b753fc
	if (ctx.cr6.eq) goto loc_82B753FC;
	// lbz r11,1246(r18)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1246);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// addi r10,r11,255
	ctx.r10.s64 = ctx.r11.s64 + 255;
	// stb r10,4(r26)
	PPC_STORE_U8(ctx.r26.u32 + 4, ctx.r10.u8);
	// b 0x82b75680
	goto loc_82B75680;
loc_82B753FC:
	// lbz r10,1244(r18)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1244);
	// lbz r11,1249(r18)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1249);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r9,r11,255
	ctx.r9.s64 = ctx.r11.s64 + 255;
	// stb r9,4(r26)
	PPC_STORE_U8(ctx.r26.u32 + 4, ctx.r9.u8);
	// b 0x82b75680
	goto loc_82B75680;
loc_82B75418:
	// lwz r31,0(r18)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// li r29,0
	ctx.r29.s64 = 0;
	// lbz r11,1250(r18)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1250);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// beq cr6,0x82b7550c
	if (ctx.cr6.eq) goto loc_82B7550C;
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x82b75498
	if (!ctx.cr6.lt) goto loc_82B75498;
loc_82B75440:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82b75498
	if (ctx.cr6.eq) goto loc_82B75498;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x82b75488
	if (!ctx.cr0.lt) goto loc_82B75488;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B75488;
	sub_829DD138(ctx, base);
loc_82B75488:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82b75440
	if (ctx.cr6.gt) goto loc_82B75440;
loc_82B75498:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x82b754d4
	if (!ctx.cr0.lt) goto loc_82B754D4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B754D4;
	sub_829DD138(ctx, base);
loc_82B754D4:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82b754f0
	if (ctx.cr6.eq) goto loc_82B754F0;
	// lbz r11,1246(r18)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1246);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stb r11,4(r26)
	PPC_STORE_U8(ctx.r26.u32 + 4, ctx.r11.u8);
	// b 0x82b75680
	goto loc_82B75680;
loc_82B754F0:
	// lbz r10,1244(r18)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1244);
	// lbz r11,1249(r18)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1249);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stb r11,4(r26)
	PPC_STORE_U8(ctx.r26.u32 + 4, ctx.r11.u8);
	// b 0x82b75680
	goto loc_82B75680;
loc_82B7550C:
	// li r30,3
	ctx.r30.s64 = 3;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x82b75570
	if (!ctx.cr6.lt) goto loc_82B75570;
loc_82B75518:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82b75570
	if (ctx.cr6.eq) goto loc_82B75570;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x82b75560
	if (!ctx.cr0.lt) goto loc_82B75560;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B75560;
	sub_829DD138(ctx, base);
loc_82B75560:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82b75518
	if (ctx.cr6.gt) goto loc_82B75518;
loc_82B75570:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x82b755ac
	if (!ctx.cr0.lt) goto loc_82B755AC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B755AC;
	sub_829DD138(ctx, base);
loc_82B755AC:
	// cmpwi cr6,r30,7
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 7, ctx.xer);
	// bne cr6,0x82b7566c
	if (!ctx.cr6.eq) goto loc_82B7566C;
	// lwz r31,0(r18)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// li r30,5
	ctx.r30.s64 = 5;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x82b75628
	if (!ctx.cr6.lt) goto loc_82B75628;
loc_82B755D0:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82b75628
	if (ctx.cr6.eq) goto loc_82B75628;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x82b75618
	if (!ctx.cr0.lt) goto loc_82B75618;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B75618;
	sub_829DD138(ctx, base);
loc_82B75618:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82b755d0
	if (ctx.cr6.gt) goto loc_82B755D0;
loc_82B75628:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x82b75664
	if (!ctx.cr0.lt) goto loc_82B75664;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B75664;
	sub_829DD138(ctx, base);
loc_82B75664:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// b 0x82b75674
	goto loc_82B75674;
loc_82B7566C:
	// lbz r11,1244(r18)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1244);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
loc_82B75674:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
	// stb r11,4(r26)
	PPC_STORE_U8(ctx.r26.u32 + 4, ctx.r11.u8);
loc_82B75680:
	// lbz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r26.u32 + 4);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82b75694
	if (ctx.cr6.lt) goto loc_82B75694;
	// cmplwi cr6,r11,62
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 62, ctx.xer);
	// ble cr6,0x82b756ac
	if (!ctx.cr6.gt) goto loc_82B756AC;
loc_82B75694:
	// li r11,4
	ctx.r11.s64 = 4;
	// li r12,1
	ctx.r12.s64 = 1;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// rldicr r12,r12,63,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// b 0x82b761c8
	goto loc_82B761C8;
loc_82B756AC:
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x82b761a8
	if (ctx.cr6.eq) goto loc_82B761A8;
	// lwz r3,0(r18)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x82b756dc
	if (!ctx.cr0.lt) goto loc_82B756DC;
	// bl 0x829dd138
	ctx.lr = 0x82B756DC;
	sub_829DD138(ctx, base);
loc_82B756DC:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// clrlwi r10,r31,24
	ctx.r10.u64 = ctx.r31.u32 & 0xFF;
	// rlwimi r11,r10,3,27,28
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0x18) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFE7);
	// stw r11,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
	// b 0x82b761a8
	goto loc_82B761A8;
loc_82B756F0:
	// rlwinm r11,r11,0,24,26
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xE0;
	// cmplwi cr6,r11,64
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 64, ctx.xer);
	// bne cr6,0x82b75b00
	if (!ctx.cr6.eq) goto loc_82B75B00;
	// lwz r31,0(r18)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r10,336(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 336);
	// ld r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r29,0(r10)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rldicl r9,r11,10,54
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 10) & 0x3FF;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r8,r29
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r29.u32);
	// extsh r30,r7
	ctx.r30.s64 = ctx.r7.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82b757e4
	if (ctx.cr6.lt) goto loc_82B757E4;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r9,r30,28
	ctx.r9.u64 = ctx.r30.u32 & 0xF;
	// sld r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r9.u8 & 0x7F));
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// std r8,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge cr6,0x82b757dc
	if (!ctx.cr6.lt) goto loc_82B757DC;
loc_82B75744:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82b75770
	if (ctx.cr6.lt) goto loc_82B75770;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd078
	ctx.lr = 0x82B75760;
	sub_829DD078(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x82b75744
	if (ctx.cr6.eq) goto loc_82B75744;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x82b75820
	goto loc_82B75820;
loc_82B75770:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r10,r10,8,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r8,2(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r7,3(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r5,5(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r9,r10,8,55
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// ld r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r8
	ctx.r3.s64 = ctx.r8.s32;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// add r9,r11,r6
	ctx.r9.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// sld r11,r11,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r3.u8 & 0x7F));
	// add r8,r11,r4
	ctx.r8.u64 = ctx.r11.u64 + ctx.r4.u64;
	// std r8,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
loc_82B757DC:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x82b75820
	goto loc_82B75820;
loc_82B757E4:
	// li r4,10
	ctx.r4.s64 = 10;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd208
	ctx.lr = 0x82B757F0;
	sub_829DD208(ctx, base);
loc_82B757F0:
	// ld r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x829dd208
	ctx.lr = 0x82B75808;
	sub_829DD208(ctx, base);
	// add r10,r30,r25
	ctx.r10.u64 = ctx.r30.u64 + ctx.r25.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82b757f0
	if (ctx.cr6.lt) goto loc_82B757F0;
loc_82B75820:
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// mr r10,r17
	ctx.r10.u64 = ctx.r17.u64;
	// cmpwi cr6,r11,37
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 37, ctx.xer);
	// bge cr6,0x82b75834
	if (!ctx.cr6.lt) goto loc_82B75834;
	// li r10,0
	ctx.r10.s64 = 0;
loc_82B75834:
	// extsw r23,r10
	ctx.r23.s64 = ctx.r10.s32;
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82b75844
	if (ctx.cr6.eq) goto loc_82B75844;
	// addi r11,r11,-37
	ctx.r11.s64 = ctx.r11.s64 + -37;
loc_82B75844:
	// li r24,0
	ctx.r24.s64 = 0;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b75ab8
	if (ctx.cr6.eq) goto loc_82B75AB8;
	// cmpwi cr6,r11,35
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 35, ctx.xer);
	// bge cr6,0x82b759a0
	if (!ctx.cr6.lt) goto loc_82B759A0;
	// lwz r10,12(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 12);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwzx r8,r9,r10
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r10.u32);
	// srawi r7,r8,24
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFFFF) != 0);
	ctx.r7.s64 = ctx.r8.s32 >> 24;
	// srawi r6,r8,4
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 4;
	// srawi r5,r8,8
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 8;
	// clrlwi r11,r8,28
	ctx.r11.u64 = ctx.r8.u32 & 0xF;
	// clrlwi r28,r6,28
	ctx.r28.u64 = ctx.r6.u32 & 0xF;
	// srawi r4,r8,16
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0xFFFF) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 16;
	// add. r30,r28,r11
	ctx.r30.u64 = ctx.r28.u64 + ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// clrlwi r27,r7,24
	ctx.r27.u64 = ctx.r7.u32 & 0xFF;
	// clrlwi r26,r5,24
	ctx.r26.u64 = ctx.r5.u32 & 0xFF;
	// clrlwi r25,r4,24
	ctx.r25.u64 = ctx.r4.u32 & 0xFF;
	// ble 0x82b75950
	if (!ctx.cr0.gt) goto loc_82B75950;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r29,0
	ctx.r29.s64 = 0;
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// bgt cr6,0x82b75950
	if (ctx.cr6.gt) goto loc_82B75950;
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82b75950
	if (ctx.cr6.eq) goto loc_82B75950;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82b7590c
	if (!ctx.cr6.gt) goto loc_82B7590C;
loc_82B758B4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82b7590c
	if (ctx.cr6.eq) goto loc_82B7590C;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x82b758fc
	if (!ctx.cr0.lt) goto loc_82B758FC;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B758FC;
	sub_829DD138(ctx, base);
loc_82B758FC:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82b758b4
	if (ctx.cr6.gt) goto loc_82B758B4;
loc_82B7590C:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x82b75948
	if (!ctx.cr0.lt) goto loc_82B75948;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B75948;
	sub_829DD138(ctx, base);
loc_82B75948:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
	// b 0x82b75954
	goto loc_82B75954;
loc_82B75950:
	// li r10,0
	ctx.r10.s64 = 0;
loc_82B75954:
	// sraw r11,r10,r28
	temp.u32 = ctx.r28.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r11.s64 = ctx.r10.s32 >> temp.u32;
	// and r9,r10,r27
	ctx.r9.u64 = ctx.r10.u64 & ctx.r27.u64;
	// srawi r10,r11,1
	ctx.xer.ca = (ctx.r11.s32 < 0) & ((ctx.r11.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r11.s32 >> 1;
	// clrlwi r8,r11,31
	ctx.r8.u64 = ctx.r11.u32 & 0x1;
	// srawi r11,r9,1
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r9.s32 >> 1;
	// clrlwi r7,r9,31
	ctx.r7.u64 = ctx.r9.u32 & 0x1;
	// add r6,r11,r25
	ctx.r6.u64 = ctx.r11.u64 + ctx.r25.u64;
	// neg r4,r7
	ctx.r4.s64 = static_cast<int64_t>(-ctx.r7.u64);
	// neg r5,r8
	ctx.r5.s64 = static_cast<int64_t>(-ctx.r8.u64);
	// add r3,r10,r26
	ctx.r3.u64 = ctx.r10.u64 + ctx.r26.u64;
	// lwz r26,84(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// xor r11,r6,r4
	ctx.r11.u64 = ctx.r6.u64 ^ ctx.r4.u64;
	// xor r10,r3,r5
	ctx.r10.u64 = ctx.r3.u64 ^ ctx.r5.u64;
	// subf r9,r4,r11
	ctx.r9.u64 = ctx.r11.u64 - ctx.r4.u64;
	// subf r11,r5,r10
	ctx.r11.u64 = ctx.r10.u64 - ctx.r5.u64;
	// lis r8,0
	ctx.r8.s64 = 0;
	// rlwimi r11,r9,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
	// ori r25,r8,32768
	ctx.r25.u64 = ctx.r8.u64 | 32768;
	// b 0x82b75ab8
	goto loc_82B75AB8;
loc_82B759A0:
	// cmpwi cr6,r11,36
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 36, ctx.xer);
	// bne cr6,0x82b759b4
	if (!ctx.cr6.eq) goto loc_82B759B4;
	// mr r24,r17
	ctx.r24.u64 = ctx.r17.u64;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82b75ab8
	goto loc_82B75AB8;
loc_82B759B4:
	// lbz r11,30(r18)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r18.u32 + 30);
	// li r29,0
	ctx.r29.s64 = 0;
	// lhz r10,70(r18)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r18.u32 + 70);
	// lhz r9,72(r18)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r18.u32 + 72);
	// subf r27,r11,r10
	ctx.r27.u64 = ctx.r10.u64 - ctx.r11.u64;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// subf r28,r11,r9
	ctx.r28.u64 = ctx.r9.u64 - ctx.r11.u64;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// add r30,r28,r27
	ctx.r30.u64 = ctx.r28.u64 + ctx.r27.u64;
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// ble cr6,0x82b759e8
	if (!ctx.cr6.gt) goto loc_82B759E8;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82b75a98
	goto loc_82B75A98;
loc_82B759E8:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82b759f8
	if (!ctx.cr6.eq) goto loc_82B759F8;
	// li r10,0
	ctx.r10.s64 = 0;
	// b 0x82b75a98
	goto loc_82B75A98;
loc_82B759F8:
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82b75a58
	if (!ctx.cr6.gt) goto loc_82B75A58;
loc_82B75A00:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82b75a58
	if (ctx.cr6.eq) goto loc_82B75A58;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x82b75a48
	if (!ctx.cr0.lt) goto loc_82B75A48;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B75A48;
	sub_829DD138(ctx, base);
loc_82B75A48:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82b75a00
	if (ctx.cr6.gt) goto loc_82B75A00;
loc_82B75A58:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x82b75a94
	if (!ctx.cr0.lt) goto loc_82B75A94;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B75A94;
	sub_829DD138(ctx, base);
loc_82B75A94:
	// mr r10,r30
	ctx.r10.u64 = ctx.r30.u64;
loc_82B75A98:
	// slw r11,r17,r27
	ctx.r11.u64 = ctx.r27.u8 & 0x20 ? 0 : (ctx.r17.u32 << (ctx.r27.u8 & 0x3F));
	// slw r9,r17,r28
	ctx.r9.u64 = ctx.r28.u8 & 0x20 ? 0 : (ctx.r17.u32 << (ctx.r28.u8 & 0x3F));
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// sraw r8,r10,r28
	temp.u32 = ctx.r28.u32 & 0x3F;
	if (temp.u32 > 0x1F) temp.u32 = 0x1F;
	ctx.xer.ca = (ctx.r10.s32 < 0) & (((ctx.r10.s32 >> temp.u32) << temp.u32) != ctx.r10.s32);
	ctx.r8.s64 = ctx.r10.s32 >> temp.u32;
	// addi r7,r9,-1
	ctx.r7.s64 = ctx.r9.s64 + -1;
	// and r11,r8,r11
	ctx.r11.u64 = ctx.r8.u64 & ctx.r11.u64;
	// and r6,r7,r10
	ctx.r6.u64 = ctx.r7.u64 & ctx.r10.u64;
	// rlwimi r11,r6,16,0,15
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 16) & 0xFFFF0000) | (ctx.r11.u64 & 0xFFFFFFFF0000FFFF);
loc_82B75AB8:
	// rldicr r10,r23,8,55
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r23.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// clrldi r9,r11,32
	ctx.r9.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// or r8,r10,r24
	ctx.r8.u64 = ctx.r10.u64 | ctx.r24.u64;
	// rldimi r9,r8,32,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r8.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r9.u64 & 0xFFFFFFFF);
	// rldicl r7,r9,32,32
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF;
	// rldicl r6,r9,24,40
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r9.u64, 24) & 0xFFFFFF;
	// clrlwi r5,r7,31
	ctx.r5.u64 = ctx.r7.u32 & 0x1;
	// clrlwi r11,r6,31
	ctx.r11.u64 = ctx.r6.u32 & 0x1;
	// or r4,r5,r22
	ctx.r4.u64 = ctx.r5.u64 | ctx.r22.u64;
	// rotlwi r21,r9,0
	ctx.r21.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// cmpwi cr6,r4,0
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 0, ctx.xer);
	// bne cr6,0x82b75f88
	if (!ctx.cr6.eq) goto loc_82B75F88;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// bne cr6,0x82b75b00
	if (!ctx.cr6.eq) goto loc_82B75B00;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// oris r10,r11,16384
	ctx.r10.u64 = ctx.r11.u64 | 1073741824;
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// b 0x82b761a8
	goto loc_82B761A8;
loc_82B75B00:
	// lbz r11,29(r18)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r18.u32 + 29);
	// lbz r28,28(r18)
	ctx.r28.u64 = PPC_LOAD_U8(ctx.r18.u32 + 28);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82b75b20
	if (ctx.cr6.eq) goto loc_82B75B20;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// bne cr6,0x82b75b20
	if (!ctx.cr6.eq) goto loc_82B75B20;
	// mr r27,r17
	ctx.r27.u64 = ctx.r17.u64;
	// b 0x82b75b64
	goto loc_82B75B64;
loc_82B75B20:
	// li r27,0
	ctx.r27.s64 = 0;
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x82b75b64
	if (ctx.cr6.eq) goto loc_82B75B64;
	// lwz r3,0(r18)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x82b75b54
	if (!ctx.cr0.lt) goto loc_82B75B54;
	// bl 0x829dd138
	ctx.lr = 0x82B75B54;
	sub_829DD138(ctx, base);
loc_82B75B54:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// clrlwi r10,r31,24
	ctx.r10.u64 = ctx.r31.u32 & 0xFF;
	// rlwimi r11,r10,3,27,28
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0x18) | (ctx.r11.u64 & 0xFFFFFFFFFFFFFFE7);
	// stw r11,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r11.u32);
loc_82B75B64:
	// lwz r31,0(r18)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r10,356(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 356);
	// ld r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r29,0(r10)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rldicl r9,r11,8,56
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFF;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r8,r29
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r29.u32);
	// extsh r30,r7
	ctx.r30.s64 = ctx.r7.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82b75c4c
	if (ctx.cr6.lt) goto loc_82B75C4C;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r9,r30,28
	ctx.r9.u64 = ctx.r30.u32 & 0xF;
	// sld r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r9.u8 & 0x7F));
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// std r8,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge cr6,0x82b75c44
	if (!ctx.cr6.lt) goto loc_82B75C44;
loc_82B75BAC:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82b75bd8
	if (ctx.cr6.lt) goto loc_82B75BD8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd078
	ctx.lr = 0x82B75BC8;
	sub_829DD078(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x82b75bac
	if (ctx.cr6.eq) goto loc_82B75BAC;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x82b75c88
	goto loc_82B75C88;
loc_82B75BD8:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r10,r10,8,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r8,2(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r7,3(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r5,5(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r9,r10,8,55
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// ld r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r8
	ctx.r3.s64 = ctx.r8.s32;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// add r9,r11,r6
	ctx.r9.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// sld r11,r11,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r3.u8 & 0x7F));
	// add r8,r11,r4
	ctx.r8.u64 = ctx.r11.u64 + ctx.r4.u64;
	// std r8,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
loc_82B75C44:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x82b75c88
	goto loc_82B75C88;
loc_82B75C4C:
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd208
	ctx.lr = 0x82B75C58;
	sub_829DD208(ctx, base);
loc_82B75C58:
	// ld r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x829dd208
	ctx.lr = 0x82B75C70;
	sub_829DD208(ctx, base);
	// add r10,r30,r25
	ctx.r10.u64 = ctx.r30.u64 + ctx.r25.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82b75c58
	if (ctx.cr6.lt) goto loc_82B75C58;
loc_82B75C88:
	// lwz r31,0(r18)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// mr r19,r30
	ctx.r19.u64 = ctx.r30.u64;
	// lwz r11,20(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 20);
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b75cb4
	if (ctx.cr6.eq) goto loc_82B75CB4;
	// li r11,4
	ctx.r11.s64 = 4;
	// li r12,1
	ctx.r12.s64 = 1;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// rldicr r12,r12,63,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// b 0x82b761c8
	goto loc_82B761C8;
loc_82B75CB4:
	// lbz r11,27(r18)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r18.u32 + 27);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82b75fa0
	if (ctx.cr6.eq) goto loc_82B75FA0;
	// lbz r11,1245(r18)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1245);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82b75d10
	if (ctx.cr6.eq) goto loc_82B75D10;
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// rlwinm r9,r10,20,28,31
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 20) & 0xF;
	// and r8,r9,r11
	ctx.r8.u64 = ctx.r9.u64 & ctx.r11.u64;
	// cmplwi cr6,r8,0
	ctx.cr6.compare<uint32_t>(ctx.r8.u32, 0, ctx.xer);
	// beq cr6,0x82b75cf4
	if (ctx.cr6.eq) goto loc_82B75CF4;
	// lbz r11,1246(r18)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1246);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// addi r10,r11,255
	ctx.r10.s64 = ctx.r11.s64 + 255;
	// stb r10,4(r26)
	PPC_STORE_U8(ctx.r26.u32 + 4, ctx.r10.u8);
	// b 0x82b75f74
	goto loc_82B75F74;
loc_82B75CF4:
	// lbz r10,1244(r18)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1244);
	// lbz r11,1249(r18)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1249);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r9,r11,255
	ctx.r9.s64 = ctx.r11.s64 + 255;
	// stb r9,4(r26)
	PPC_STORE_U8(ctx.r26.u32 + 4, ctx.r9.u8);
	// b 0x82b75f74
	goto loc_82B75F74;
loc_82B75D10:
	// lbz r11,1250(r18)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1250);
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// beq cr6,0x82b75e00
	if (ctx.cr6.eq) goto loc_82B75E00;
	// mr r30,r17
	ctx.r30.u64 = ctx.r17.u64;
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// bge cr6,0x82b75d8c
	if (!ctx.cr6.lt) goto loc_82B75D8C;
loc_82B75D34:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82b75d8c
	if (ctx.cr6.eq) goto loc_82B75D8C;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x82b75d7c
	if (!ctx.cr0.lt) goto loc_82B75D7C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B75D7C;
	sub_829DD138(ctx, base);
loc_82B75D7C:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82b75d34
	if (ctx.cr6.gt) goto loc_82B75D34;
loc_82B75D8C:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x82b75dc8
	if (!ctx.cr0.lt) goto loc_82B75DC8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B75DC8;
	sub_829DD138(ctx, base);
loc_82B75DC8:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// beq cr6,0x82b75de4
	if (ctx.cr6.eq) goto loc_82B75DE4;
	// lbz r11,1246(r18)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1246);
	// rotlwi r11,r11,1
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r11.u32, 1);
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stb r11,4(r26)
	PPC_STORE_U8(ctx.r26.u32 + 4, ctx.r11.u8);
	// b 0x82b75f74
	goto loc_82B75F74;
loc_82B75DE4:
	// lbz r10,1244(r18)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1244);
	// lbz r11,1249(r18)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1249);
	// rotlwi r10,r10,1
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r10.u32, 1);
	// add r11,r10,r11
	ctx.r11.u64 = ctx.r10.u64 + ctx.r11.u64;
	// addi r11,r11,-1
	ctx.r11.s64 = ctx.r11.s64 + -1;
	// stb r11,4(r26)
	PPC_STORE_U8(ctx.r26.u32 + 4, ctx.r11.u8);
	// b 0x82b75f74
	goto loc_82B75F74;
loc_82B75E00:
	// li r30,3
	ctx.r30.s64 = 3;
	// cmplwi cr6,r11,3
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 3, ctx.xer);
	// bge cr6,0x82b75e64
	if (!ctx.cr6.lt) goto loc_82B75E64;
loc_82B75E0C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82b75e64
	if (ctx.cr6.eq) goto loc_82B75E64;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x82b75e54
	if (!ctx.cr0.lt) goto loc_82B75E54;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B75E54;
	sub_829DD138(ctx, base);
loc_82B75E54:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82b75e0c
	if (ctx.cr6.gt) goto loc_82B75E0C;
loc_82B75E64:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x82b75ea0
	if (!ctx.cr0.lt) goto loc_82B75EA0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B75EA0;
	sub_829DD138(ctx, base);
loc_82B75EA0:
	// cmpwi cr6,r30,7
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 7, ctx.xer);
	// bne cr6,0x82b75f60
	if (!ctx.cr6.eq) goto loc_82B75F60;
	// lwz r31,0(r18)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// li r30,5
	ctx.r30.s64 = 5;
	// li r29,0
	ctx.r29.s64 = 0;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,5
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 5, ctx.xer);
	// bge cr6,0x82b75f1c
	if (!ctx.cr6.lt) goto loc_82B75F1C;
loc_82B75EC4:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82b75f1c
	if (ctx.cr6.eq) goto loc_82B75F1C;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r29,r11,r29
	ctx.r29.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r10,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x82b75f0c
	if (!ctx.cr0.lt) goto loc_82B75F0C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B75F0C;
	sub_829DD138(ctx, base);
loc_82B75F0C:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82b75ec4
	if (ctx.cr6.gt) goto loc_82B75EC4;
loc_82B75F1C:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r29
	ctx.r30.u64 = ctx.r11.u64 + ctx.r29.u64;
	// std r4,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x82b75f58
	if (!ctx.cr0.lt) goto loc_82B75F58;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B75F58;
	sub_829DD138(ctx, base);
loc_82B75F58:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// b 0x82b75f68
	goto loc_82B75F68;
loc_82B75F60:
	// lbz r11,1244(r18)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r18.u32 + 1244);
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
loc_82B75F68:
	// rlwinm r11,r11,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0xFFFFFFFE;
	// addi r11,r11,255
	ctx.r11.s64 = ctx.r11.s64 + 255;
	// stb r11,4(r26)
	PPC_STORE_U8(ctx.r26.u32 + 4, ctx.r11.u8);
loc_82B75F74:
	// lbz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r26.u32 + 4);
	// cmplwi cr6,r11,1
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 1, ctx.xer);
	// blt cr6,0x82b75f88
	if (ctx.cr6.lt) goto loc_82B75F88;
	// cmplwi cr6,r11,62
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 62, ctx.xer);
	// ble cr6,0x82b75fa0
	if (!ctx.cr6.gt) goto loc_82B75FA0;
loc_82B75F88:
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
	// li r12,1
	ctx.r12.s64 = 1;
	// clrldi r11,r11,32
	ctx.r11.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// rldicr r12,r12,63,63
	ctx.r12.u64 = __builtin_rotateleft64(ctx.r12.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// or r11,r11,r12
	ctx.r11.u64 = ctx.r11.u64 | ctx.r12.u64;
	// b 0x82b761c8
	goto loc_82B761C8;
loc_82B75FA0:
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// cmpwi cr6,r28,0
	ctx.cr6.compare<int32_t>(ctx.r28.s32, 0, ctx.xer);
	// rlwinm r10,r11,0,2,0
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0xFFFFFFFFBFFFFFFF;
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// beq cr6,0x82b76020
	if (ctx.cr6.eq) goto loc_82B76020;
	// lwz r3,0(r18)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r30,r10,1,63
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x82b75fdc
	if (!ctx.cr0.lt) goto loc_82B75FDC;
	// bl 0x829dd138
	ctx.lr = 0x82B75FDC;
	sub_829DD138(ctx, base);
loc_82B75FDC:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// beq cr6,0x82b76014
	if (ctx.cr6.eq) goto loc_82B76014;
	// lwz r3,0(r18)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x82b76010
	if (!ctx.cr0.lt) goto loc_82B76010;
	// bl 0x829dd138
	ctx.lr = 0x82B76010;
	sub_829DD138(ctx, base);
loc_82B76010:
	// add r11,r31,r30
	ctx.r11.u64 = ctx.r31.u64 + ctx.r30.u64;
loc_82B76014:
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// rlwimi r10,r11,22,8,9
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 22) & 0xC00000) | (ctx.r10.u64 & 0xFFFFFFFFFF3FFFFF);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
loc_82B76020:
	// cmpwi cr6,r27,0
	ctx.cr6.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// beq cr6,0x82b761a8
	if (ctx.cr6.eq) goto loc_82B761A8;
	// lwz r31,0(r18)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r10,360(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 360);
	// ld r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r29,0(r10)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rldicl r9,r11,8,56
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFF;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r8,r29
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r29.u32);
	// extsh r30,r7
	ctx.r30.s64 = ctx.r7.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82b76110
	if (ctx.cr6.lt) goto loc_82B76110;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r9,r30,28
	ctx.r9.u64 = ctx.r30.u32 & 0xF;
	// sld r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r9.u8 & 0x7F));
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// std r8,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge cr6,0x82b76108
	if (!ctx.cr6.lt) goto loc_82B76108;
loc_82B76070:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82b7609c
	if (ctx.cr6.lt) goto loc_82B7609C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd078
	ctx.lr = 0x82B7608C;
	sub_829DD078(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x82b76070
	if (ctx.cr6.eq) goto loc_82B76070;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x82b7614c
	goto loc_82B7614C;
loc_82B7609C:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r10,r10,8,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r8,2(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r7,3(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r5,5(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r9,r10,8,55
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// ld r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r8
	ctx.r3.s64 = ctx.r8.s32;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// add r9,r11,r6
	ctx.r9.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// sld r11,r11,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r3.u8 & 0x7F));
	// add r8,r11,r4
	ctx.r8.u64 = ctx.r11.u64 + ctx.r4.u64;
	// std r8,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
loc_82B76108:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x82b7614c
	goto loc_82B7614C;
loc_82B76110:
	// li r4,8
	ctx.r4.s64 = 8;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd208
	ctx.lr = 0x82B7611C;
	sub_829DD208(ctx, base);
loc_82B7611C:
	// ld r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x829dd208
	ctx.lr = 0x82B76134;
	sub_829DD208(ctx, base);
	// add r10,r30,r25
	ctx.r10.u64 = ctx.r30.u64 + ctx.r25.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82b7611c
	if (ctx.cr6.lt) goto loc_82B7611C;
loc_82B7614C:
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// beq cr6,0x82b76164
	if (ctx.cr6.eq) goto loc_82B76164;
	// li r11,4
	ctx.r11.s64 = 4;
	// b 0x82b761c8
	goto loc_82B761C8;
loc_82B76164:
	// cmpwi cr6,r30,8
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 8, ctx.xer);
	// mr r11,r17
	ctx.r11.u64 = ctx.r17.u64;
	// blt cr6,0x82b76174
	if (ctx.cr6.lt) goto loc_82B76174;
	// li r11,0
	ctx.r11.s64 = 0;
loc_82B76174:
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// rlwinm r9,r30,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r8,r16,-64
	ctx.r8.s64 = ctx.r16.s64 + -64;
	// rlwimi r10,r11,28,3,3
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 28) & 0x10000000) | (ctx.r10.u64 & 0xFFFFFFFFEFFFFFFF);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// lwzx r7,r9,r8
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r8.u32);
	// rlwimi r10,r7,24,5,7
	ctx.r10.u64 = (__builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 24) & 0x7000000) | (ctx.r10.u64 & 0xFFFFFFFFF8FFFFFF);
	// stw r10,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r10.u32);
	// rotlwi r5,r10,0
	ctx.r5.u64 = __builtin_rotateleft32(ctx.r10.u32, 0);
	// lwzx r6,r9,r16
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r9.u32 + ctx.r16.u32);
	// rlwimi r5,r6,20,10,11
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 20) & 0x300000) | (ctx.r5.u64 & 0xFFFFFFFFFFCFFFFF);
	// rlwinm r4,r5,0,5,3
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 0) & 0xFFFFFFFFF7FFFFFF;
	// stw r4,0(r26)
	PPC_STORE_U32(ctx.r26.u32 + 0, ctx.r4.u32);
loc_82B761A8:
	// stb r19,5(r26)
	PPC_STORE_U8(ctx.r26.u32 + 5, ctx.r19.u8);
loc_82B761AC:
	// cmpwi cr6,r22,0
	ctx.cr6.compare<int32_t>(ctx.r22.s32, 0, ctx.xer);
	// beq cr6,0x82b761c0
	if (ctx.cr6.eq) goto loc_82B761C0;
	// li r11,16384
	ctx.r11.s64 = 16384;
	// rldimi r11,r11,32,0
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r11.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r11.u64 & 0xFFFFFFFF);
	// b 0x82b761c8
	goto loc_82B761C8;
loc_82B761C0:
	// clrldi r11,r20,32
	ctx.r11.u64 = ctx.r20.u64 & 0xFFFFFFFF;
	// rldimi r11,r21,32,0
	ctx.r11.u64 = (__builtin_rotateleft64(ctx.r21.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r11.u64 & 0xFFFFFFFF);
loc_82B761C8:
	// lwz r10,0(r26)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// rlwinm r9,r10,0,24,26
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 0) & 0xE0;
	// cmplwi cr6,r9,96
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 96, ctx.xer);
	// beq cr6,0x82b761e4
	if (ctx.cr6.eq) goto loc_82B761E4;
	// lwz r10,3720(r15)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r15.u32 + 3720);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82b775f0
	if (ctx.cr6.eq) goto loc_82B775F0;
loc_82B761E4:
	// li r10,1
	ctx.r10.s64 = 1;
	// rldicr r9,r11,0,1
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 0) & 0xC000000000000000;
	// rldicr r8,r10,63,63
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 63) & 0xFFFFFFFFFFFFFFFF;
	// cmpld cr6,r9,r8
	ctx.cr6.compare<uint64_t>(ctx.r9.u64, ctx.r8.u64, ctx.xer);
	// beq cr6,0x82b775f0
	if (ctx.cr6.eq) goto loc_82B775F0;
	// lwz r10,100(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// li r9,16384
	ctx.r9.s64 = 16384;
	// lwz r8,1912(r18)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r18.u32 + 1912);
	// sradi r7,r11,32
	ctx.xer.ca = (ctx.r11.s64 < 0) & ((ctx.r11.u64 & 0xFFFFFFFF) != 0);
	ctx.r7.s64 = ctx.r11.s64 >> 32;
	// rlwinm r6,r10,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 2) & 0xFFFFFFFC;
	// rldimi r9,r9,32,0
	ctx.r9.u64 = (__builtin_rotateleft64(ctx.r9.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r9.u64 & 0xFFFFFFFF);
	// cmpld cr6,r11,r9
	ctx.cr6.compare<uint64_t>(ctx.r11.u64, ctx.r9.u64, ctx.xer);
	// stwx r11,r8,r6
	PPC_STORE_U32(ctx.r8.u32 + ctx.r6.u32, ctx.r11.u32);
	// lwz r3,1916(r18)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r18.u32 + 1916);
	// stwx r7,r3,r6
	PPC_STORE_U32(ctx.r3.u32 + ctx.r6.u32, ctx.r7.u32);
	// bne cr6,0x82b77048
	if (!ctx.cr6.eq) goto loc_82B77048;
	// lbz r11,4(r26)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r26.u32 + 4);
	// clrlwi r8,r14,31
	ctx.r8.u64 = ctx.r14.u32 & 0x1;
	// lwz r7,372(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// rotlwi r10,r11,2
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r11.u32, 2);
	// lbz r6,5(r26)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r26.u32 + 5);
	// neg r5,r8
	ctx.r5.s64 = static_cast<int64_t>(-ctx.r8.u64);
	// lwz r9,388(r18)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r18.u32 + 388);
	// add r4,r11,r10
	ctx.r4.u64 = ctx.r11.u64 + ctx.r10.u64;
	// lhz r3,50(r18)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r18.u32 + 50);
	// lbz r31,28(r18)
	ctx.r31.u64 = PPC_LOAD_U8(ctx.r18.u32 + 28);
	// lwz r10,4(r7)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r7.u32 + 4);
	// rlwinm r8,r4,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r11,1312(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 1312);
	// and r15,r5,r3
	ctx.r15.u64 = ctx.r5.u64 & ctx.r3.u64;
	// rlwinm r10,r10,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 3) & 0xFFFFFFF8;
	// stb r6,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r6.u8);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// add r16,r10,r11
	ctx.r16.u64 = ctx.r10.u64 + ctx.r11.u64;
	// stw r9,128(r1)
	PPC_STORE_U32(ctx.r1.u32 + 128, ctx.r9.u32);
	// cmplwi cr6,r31,0
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 0, ctx.xer);
	// beq cr6,0x82b7629c
	if (ctx.cr6.eq) goto loc_82B7629C;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// lwz r10,396(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 396);
	// lwz r9,400(r18)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r18.u32 + 400);
	// rlwinm r11,r11,12,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xC;
	// add r10,r10,r11
	ctx.r10.u64 = ctx.r10.u64 + ctx.r11.u64;
	// add r9,r9,r11
	ctx.r9.u64 = ctx.r9.u64 + ctx.r11.u64;
	// stw r10,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r10.u32);
	// stw r9,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r9.u32);
	// b 0x82b762ac
	goto loc_82B762AC;
loc_82B7629C:
	// addi r11,r18,404
	ctx.r11.s64 = ctx.r18.s64 + 404;
	// addi r10,r18,416
	ctx.r10.s64 = ctx.r18.s64 + 416;
	// stw r11,108(r1)
	PPC_STORE_U32(ctx.r1.u32 + 108, ctx.r11.u32);
	// stw r10,104(r1)
	PPC_STORE_U32(ctx.r1.u32 + 104, ctx.r10.u32);
loc_82B762AC:
	// lwz r10,372(r1)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// li r17,0
	ctx.r17.s64 = 0;
	// lwz r9,96(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// lwz r8,92(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// rlwinm r11,r9,16,0,15
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 16) & 0xFFFF0000;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,32(r10)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// or r5,r11,r8
	ctx.r5.u64 = ctx.r11.u64 | ctx.r8.u64;
	// stw r5,0(r6)
	PPC_STORE_U32(ctx.r6.u32 + 0, ctx.r5.u32);
	// lwz r11,32(r10)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r10.u32 + 32);
	// addi r4,r11,4
	ctx.r4.s64 = ctx.r11.s64 + 4;
	// stw r4,32(r10)
	PPC_STORE_U32(ctx.r10.u32 + 32, ctx.r4.u32);
	// lwz r3,1304(r18)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r18.u32 + 1304);
	// lhz r11,50(r18)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r18.u32 + 50);
	// mullw r10,r11,r9
	ctx.r10.s64 = int64_t(ctx.r11.s32) * int64_t(ctx.r9.s32);
	// srawi r10,r10,1
	ctx.xer.ca = (ctx.r10.s32 < 0) & ((ctx.r10.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r10.s32 >> 1;
	// add r14,r10,r8
	ctx.r14.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwzx r11,r3,r7
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r3.u32 + ctx.r7.u32);
	// addi r8,r11,-1
	ctx.r8.s64 = ctx.r11.s64 + -1;
	// and r7,r8,r9
	ctx.r7.u64 = ctx.r8.u64 & ctx.r9.u64;
	// stw r7,132(r1)
	PPC_STORE_U32(ctx.r1.u32 + 132, ctx.r7.u32);
loc_82B76300:
	// lbz r10,80(r1)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// srawi. r11,r17,2
	ctx.xer.ca = (ctx.r17.s32 < 0) & ((ctx.r17.u32 & 0x3) != 0);
	ctx.r11.s64 = ctx.r17.s32 >> 2;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// lwz r11,96(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// li r27,119
	ctx.r27.s64 = 119;
	// clrlwi r19,r10,31
	ctx.r19.u64 = ctx.r10.u32 & 0x1;
	// bne 0x82b7636c
	if (!ctx.cr0.eq) goto loc_82B7636C;
	// addi r10,r17,18
	ctx.r10.s64 = ctx.r17.s64 + 18;
	// lwz r7,92(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// rlwinm r6,r11,1,30,30
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x2;
	// lwz r8,432(r18)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r18.u32 + 432);
	// srawi r9,r17,1
	ctx.xer.ca = (ctx.r17.s32 < 0) & ((ctx.r17.u32 & 0x1) != 0);
	ctx.r9.s64 = ctx.r17.s32 >> 1;
	// lwz r22,348(r18)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r18.u32 + 348);
	// rlwinm r5,r10,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lwz r11,1224(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 1224);
	// or r10,r6,r9
	ctx.r10.u64 = ctx.r6.u64 | ctx.r9.u64;
	// lwz r21,104(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 104);
	// add r4,r15,r7
	ctx.r4.u64 = ctx.r15.u64 + ctx.r7.u64;
	// addi r3,r10,184
	ctx.r3.s64 = ctx.r10.s64 + 184;
	// rlwinm r10,r4,1,0,30
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r9,r5,r18
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r5.u32 + ctx.r18.u32);
	// rlwinm r7,r3,1,0,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lhzx r6,r7,r18
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r7.u32 + ctx.r18.u32);
	// add r29,r10,r8
	ctx.r29.u64 = ctx.r10.u64 + ctx.r8.u64;
	// extsh r20,r6
	ctx.r20.s64 = ctx.r6.s16;
	// b 0x82b763ac
	goto loc_82B763AC;
loc_82B7636C:
	// clrlwi r10,r11,31
	ctx.r10.u64 = ctx.r11.u32 & 0x1;
	// lwz r8,92(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r9,r17,105
	ctx.r9.s64 = ctx.r17.s64 + 105;
	// lwz r22,352(r18)
	ctx.r22.u64 = PPC_LOAD_U32(ctx.r18.u32 + 352);
	// addi r6,r10,182
	ctx.r6.s64 = ctx.r10.s64 + 182;
	// lwz r11,1228(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 1228);
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r21,108(r1)
	ctx.r21.u64 = PPC_LOAD_U32(ctx.r1.u32 + 108);
	// srawi r10,r15,1
	ctx.xer.ca = (ctx.r15.s32 < 0) & ((ctx.r15.u32 & 0x1) != 0);
	ctx.r10.s64 = ctx.r15.s32 >> 1;
	// rlwinm r5,r6,1,0,30
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 1) & 0xFFFFFFFE;
	// add r10,r10,r8
	ctx.r10.u64 = ctx.r10.u64 + ctx.r8.u64;
	// lwzx r9,r7,r18
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r18.u32);
	// rlwinm r10,r10,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 5) & 0xFFFFFFE0;
	// lhzx r4,r5,r18
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r5.u32 + ctx.r18.u32);
	// add r29,r9,r10
	ctx.r29.u64 = ctx.r9.u64 + ctx.r10.u64;
	// extsh r20,r4
	ctx.r20.s64 = ctx.r4.s16;
loc_82B763AC:
	// lwz r9,372(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// lwz r8,128(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 128);
	// lwz r10,28(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 28);
	// lwz r24,16(r8)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// addi r23,r10,-128
	ctx.r23.s64 = ctx.r10.s64 + -128;
	// stw r23,28(r9)
	PPC_STORE_U32(ctx.r9.u32 + 28, ctx.r23.u32);
	// dcbzl r0,r23
	ea = (ctx.r23.u32) & ~127;
	memset((void*)PPC_RAW_ADDR(ea), 0, 128);
	// li r26,0
	ctx.r26.s64 = 0;
	// lbz r4,8(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 8);
	// lwz r31,0(r18)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// subfic r7,r4,64
	ctx.xer.ca = ctx.r4.u32 <= 64;
	ctx.r7.u64 = static_cast<uint64_t>(64) - ctx.r4.u64;
	// lwz r28,0(r11)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// clrldi r6,r7,32
	ctx.r6.u64 = ctx.r7.u64 & 0xFFFFFFFF;
	// ld r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// srd r5,r11,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r11.u64 >> (ctx.r6.u8 & 0x7F));
	// rlwinm r3,r5,1,0,30
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r10,r3,r28
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r3.u32 + ctx.r28.u32);
	// extsh r30,r10
	ctx.r30.s64 = ctx.r10.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82b764bc
	if (ctx.cr6.lt) goto loc_82B764BC;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r9,r30,28
	ctx.r9.u64 = ctx.r30.u32 & 0xF;
	// sld r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r9.u8 & 0x7F));
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// std r8,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge cr6,0x82b764b4
	if (!ctx.cr6.lt) goto loc_82B764B4;
loc_82B7641C:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82b76448
	if (ctx.cr6.lt) goto loc_82B76448;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd078
	ctx.lr = 0x82B76438;
	sub_829DD078(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x82b7641c
	if (ctx.cr6.eq) goto loc_82B7641C;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x82b764fc
	goto loc_82B764FC;
loc_82B76448:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r10,r10,8,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r8,2(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,4(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// add r10,r9,r10
	ctx.r10.u64 = ctx.r9.u64 + ctx.r10.u64;
	// lbz r7,3(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// lbz r5,5(r11)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r9,r10,8,55
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// add r9,r9,r8
	ctx.r9.u64 = ctx.r9.u64 + ctx.r8.u64;
	// ld r4,0(r31)
	ctx.r4.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// neg r8,r10
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r8
	ctx.r3.s64 = ctx.r8.s32;
	// add r11,r11,r7
	ctx.r11.u64 = ctx.r11.u64 + ctx.r7.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// add r9,r11,r6
	ctx.r9.u64 = ctx.r11.u64 + ctx.r6.u64;
	// rldicr r11,r9,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r5
	ctx.r11.u64 = ctx.r11.u64 + ctx.r5.u64;
	// sld r11,r11,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r3.u8 & 0x7F));
	// add r8,r11,r4
	ctx.r8.u64 = ctx.r11.u64 + ctx.r4.u64;
	// std r8,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
loc_82B764B4:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x82b764fc
	goto loc_82B764FC;
loc_82B764BC:
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd208
	ctx.lr = 0x82B764C4;
	sub_829DD208(ctx, base);
	// lis r11,0
	ctx.r11.s64 = 0;
	// ori r25,r11,32768
	ctx.r25.u64 = ctx.r11.u64 | 32768;
loc_82B764CC:
	// ld r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x829dd208
	ctx.lr = 0x82B764E4;
	sub_829DD208(ctx, base);
	// add r10,r30,r25
	ctx.r10.u64 = ctx.r30.u64 + ctx.r25.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r28
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r28.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82b764cc
	if (ctx.cr6.lt) goto loc_82B764CC;
loc_82B764FC:
	// clrlwi r30,r30,16
	ctx.r30.u64 = ctx.r30.u32 & 0xFFFF;
	// mr r25,r30
	ctx.r25.u64 = ctx.r30.u64;
	// cmpw cr6,r30,r27
	ctx.cr6.compare<int32_t>(ctx.r30.s32, ctx.r27.s32, ctx.xer);
	// beq cr6,0x82b76628
	if (ctx.cr6.eq) goto loc_82B76628;
	// cmplwi cr6,r25,0
	ctx.cr6.compare<uint32_t>(ctx.r25.u32, 0, ctx.xer);
	// beq cr6,0x82b76750
	if (ctx.cr6.eq) goto loc_82B76750;
	// cmpwi cr6,r24,4
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 4, ctx.xer);
	// bne cr6,0x82b7655c
	if (!ctx.cr6.eq) goto loc_82B7655C;
	// ld r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r30,r10,1,63
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bge 0x82b76544
	if (!ctx.cr0.lt) goto loc_82B76544;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B76544;
	sub_829DD138(ctx, base);
loc_82B76544:
	// rlwinm r11,r25,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 1) & 0xFFFFFFFE;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addis r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 65536;
	// addi r10,r10,-1
	ctx.r10.s64 = ctx.r10.s64 + -1;
	// clrlwi r30,r10,16
	ctx.r30.u64 = ctx.r10.u32 & 0xFFFF;
	// b 0x82b76714
	goto loc_82B76714;
loc_82B7655C:
	// cmpwi cr6,r24,2
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 2, ctx.xer);
	// bne cr6,0x82b76714
	if (!ctx.cr6.eq) goto loc_82B76714;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// li r30,2
	ctx.r30.s64 = 2;
	// li r28,0
	ctx.r28.s64 = 0;
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplwi cr6,r11,2
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 2, ctx.xer);
	// bge cr6,0x82b765d4
	if (!ctx.cr6.lt) goto loc_82B765D4;
loc_82B7657C:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82b765d4
	if (ctx.cr6.eq) goto loc_82B765D4;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r28,r11,r28
	ctx.r28.u64 = ctx.r11.u64 + ctx.r28.u64;
	// std r10,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x82b765c4
	if (!ctx.cr0.lt) goto loc_82B765C4;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B765C4;
	sub_829DD138(ctx, base);
loc_82B765C4:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82b7657c
	if (ctx.cr6.gt) goto loc_82B7657C;
loc_82B765D4:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r28
	ctx.r30.u64 = ctx.r11.u64 + ctx.r28.u64;
	// std r4,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x82b76610
	if (!ctx.cr0.lt) goto loc_82B76610;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B76610;
	sub_829DD138(ctx, base);
loc_82B76610:
	// rlwinm r11,r25,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 2) & 0xFFFFFFFC;
	// add r11,r11,r30
	ctx.r11.u64 = ctx.r11.u64 + ctx.r30.u64;
	// addis r10,r11,1
	ctx.r10.s64 = ctx.r11.s64 + 65536;
	// addi r10,r10,-3
	ctx.r10.s64 = ctx.r10.s64 + -3;
	// clrlwi r30,r10,16
	ctx.r30.u64 = ctx.r10.u32 & 0xFFFF;
	// b 0x82b76714
	goto loc_82B76714;
loc_82B76628:
	// cmpwi cr6,r24,4
	ctx.cr6.compare<int32_t>(ctx.r24.s32, 4, ctx.xer);
	// bgt cr6,0x82b7663c
	if (ctx.cr6.gt) goto loc_82B7663C;
	// srawi r11,r24,1
	ctx.xer.ca = (ctx.r24.s32 < 0) & ((ctx.r24.u32 & 0x1) != 0);
	ctx.r11.s64 = ctx.r24.s32 >> 1;
	// subfic r11,r11,3
	ctx.xer.ca = ctx.r11.u32 <= 3;
	ctx.r11.u64 = static_cast<uint64_t>(3) - ctx.r11.u64;
	// b 0x82b76640
	goto loc_82B76640;
loc_82B7663C:
	// li r11,0
	ctx.r11.s64 = 0;
loc_82B76640:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r30,r11,8
	ctx.r30.s64 = ctx.r11.s64 + 8;
	// li r28,0
	ctx.r28.s64 = 0;
	// cmplwi cr6,r30,32
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 32, ctx.xer);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// ble cr6,0x82b76660
	if (!ctx.cr6.gt) goto loc_82B76660;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82b76710
	goto loc_82B76710;
loc_82B76660:
	// cmplwi cr6,r30,0
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, 0, ctx.xer);
	// bne cr6,0x82b76670
	if (!ctx.cr6.eq) goto loc_82B76670;
	// li r11,0
	ctx.r11.s64 = 0;
	// b 0x82b76710
	goto loc_82B76710;
loc_82B76670:
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// ble cr6,0x82b766d0
	if (!ctx.cr6.gt) goto loc_82B766D0;
loc_82B76678:
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82b766d0
	if (ctx.cr6.eq) goto loc_82B766D0;
	// subfic r9,r11,64
	ctx.xer.ca = ctx.r11.u32 <= 64;
	ctx.r9.u64 = static_cast<uint64_t>(64) - ctx.r11.u64;
	// ld r8,0(r31)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// clrldi r6,r9,32
	ctx.r6.u64 = ctx.r9.u64 & 0xFFFFFFFF;
	// subf r30,r11,r30
	ctx.r30.u64 = ctx.r30.u64 - ctx.r11.u64;
	// srd r5,r8,r6
	ctx.r5.u64 = ctx.r6.u8 & 0x40 ? 0 : (ctx.r8.u64 >> (ctx.r6.u8 & 0x7F));
	// rotlwi r4,r5,0
	ctx.r4.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// subf. r3,r11,r10
	ctx.r3.u64 = ctx.r10.u64 - ctx.r11.u64;
	ctx.cr0.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// slw r11,r4,r30
	ctx.r11.u64 = ctx.r30.u8 & 0x20 ? 0 : (ctx.r4.u32 << (ctx.r30.u8 & 0x3F));
	// sld r10,r8,r7
	ctx.r10.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r8.u64 << (ctx.r7.u8 & 0x7F));
	// stw r3,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r3.u32);
	// add r28,r11,r28
	ctx.r28.u64 = ctx.r11.u64 + ctx.r28.u64;
	// std r10,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r10.u64);
	// bge 0x82b766c0
	if (!ctx.cr0.lt) goto loc_82B766C0;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B766C0;
	sub_829DD138(ctx, base);
loc_82B766C0:
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// addi r11,r10,16
	ctx.r11.s64 = ctx.r10.s64 + 16;
	// cmplw cr6,r30,r11
	ctx.cr6.compare<uint32_t>(ctx.r30.u32, ctx.r11.u32, ctx.xer);
	// bgt cr6,0x82b76678
	if (ctx.cr6.gt) goto loc_82B76678;
loc_82B766D0:
	// subfic r11,r30,64
	ctx.xer.ca = ctx.r30.u32 <= 64;
	ctx.r11.u64 = static_cast<uint64_t>(64) - ctx.r30.u64;
	// ld r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrldi r8,r30,32
	ctx.r8.u64 = ctx.r30.u64 & 0xFFFFFFFF;
	// clrldi r7,r11,32
	ctx.r7.u64 = ctx.r11.u64 & 0xFFFFFFFF;
	// subf. r6,r30,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r30.u64;
	ctx.cr0.compare<int32_t>(ctx.r6.s32, 0, ctx.xer);
	// srd r5,r10,r7
	ctx.r5.u64 = ctx.r7.u8 & 0x40 ? 0 : (ctx.r10.u64 >> (ctx.r7.u8 & 0x7F));
	// rotlwi r11,r5,0
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r5.u32, 0);
	// stw r6,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r6.u32);
	// sld r4,r10,r8
	ctx.r4.u64 = ctx.r8.u8 & 0x40 ? 0 : (ctx.r10.u64 << (ctx.r8.u8 & 0x7F));
	// add r30,r11,r28
	ctx.r30.u64 = ctx.r11.u64 + ctx.r28.u64;
	// std r4,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r4.u64);
	// bge 0x82b7670c
	if (!ctx.cr0.lt) goto loc_82B7670C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B7670C;
	sub_829DD138(ctx, base);
loc_82B7670C:
	// mr r11,r30
	ctx.r11.u64 = ctx.r30.u64;
loc_82B76710:
	// clrlwi r30,r11,16
	ctx.r30.u64 = ctx.r11.u32 & 0xFFFF;
loc_82B76714:
	// ld r10,0(r31)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r9,8(r31)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// std r8,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// rldicl r28,r10,1,63
	ctx.r28.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// stw r11,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r11.u32);
	// bge 0x82b7673c
	if (!ctx.cr0.lt) goto loc_82B7673C;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd138
	ctx.lr = 0x82B7673C;
	sub_829DD138(ctx, base);
loc_82B7673C:
	// rlwinm r11,r28,1,0,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r28.u32 | (ctx.r28.u64 << 32), 1) & 0xFFFFFFFE;
	// extsh r10,r30
	ctx.r10.s64 = ctx.r30.s16;
	// subfic r9,r11,1
	ctx.xer.ca = ctx.r11.u32 <= 1;
	ctx.r9.u64 = static_cast<uint64_t>(1) - ctx.r11.u64;
	// mullw r8,r9,r10
	ctx.r8.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r10.s32);
	// extsh r26,r8
	ctx.r26.s64 = ctx.r8.s16;
loc_82B76750:
	// sth r26,0(r23)
	PPC_STORE_U16(ctx.r23.u32 + 0, ctx.r26.u16);
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82b775f0
	if (!ctx.cr6.eq) goto loc_82B775F0;
	// cmpwi cr6,r19,0
	ctx.cr6.compare<int32_t>(ctx.r19.s32, 0, ctx.xer);
	// beq cr6,0x82b76788
	if (ctx.cr6.eq) goto loc_82B76788;
	// mr r5,r23
	ctx.r5.u64 = ctx.r23.u64;
	// lwz r4,0(r21)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r21.u32 + 0);
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// lwz r6,444(r18)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r18.u32 + 444);
	// bl 0x82b35888
	ctx.lr = 0x82B76780;
	sub_82B35888(ctx, base);
	// cmpwi cr6,r3,0
	ctx.cr6.compare<int32_t>(ctx.r3.s32, 0, ctx.xer);
	// blt cr6,0x82b775f0
	if (ctx.cr6.lt) goto loc_82B775F0;
loc_82B76788:
	// lwz r11,84(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// rlwinm r10,r14,2,0,29
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r14.u32 | (ctx.r14.u64 << 32), 2) & 0xFFFFFFFC;
	// lhz r8,50(r18)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r18.u32 + 50);
	// rlwinm r7,r17,0,30,30
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r17.u32 | (ctx.r17.u64 << 32), 0) & 0x2;
	// add r9,r10,r22
	ctx.r9.u64 = ctx.r10.u64 + ctx.r22.u64;
	// rlwinm r30,r8,31,1,31
	ctx.r30.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 31) & 0x7FFFFFFF;
	// srawi r8,r17,2
	ctx.xer.ca = (ctx.r17.s32 < 0) & ((ctx.r17.u32 & 0x3) != 0);
	ctx.r8.s64 = ctx.r17.s32 >> 2;
	// lwz r6,0(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 0);
	// li r25,1
	ctx.r25.s64 = 1;
	// lbz r11,4(r11)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// li r28,0
	ctx.r28.s64 = 0;
	// rlwinm r5,r6,0,27,28
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 0) & 0x18;
	// li r27,0
	ctx.r27.s64 = 0;
	// cntlzw r4,r5
	ctx.r4.u64 = ctx.r5.u32 == 0 ? 32 : __builtin_clz(ctx.r5.u32);
	// li r10,0
	ctx.r10.s64 = 0;
	// rlwinm r26,r4,27,31,31
	ctx.r26.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 27) & 0x1;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// bne cr6,0x82b767f0
	if (!ctx.cr6.eq) goto loc_82B767F0;
	// lwz r7,132(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 132);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x82b76800
	if (ctx.cr6.eq) goto loc_82B76800;
	// rlwinm r7,r30,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r7,r9
	ctx.r6.u64 = ctx.r9.u64 - ctx.r7.u64;
	// lwz r5,0(r6)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r6.u32 + 0);
	// cmpwi cr6,r5,16384
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 16384, ctx.xer);
	// bne cr6,0x82b76800
	if (!ctx.cr6.eq) goto loc_82B76800;
loc_82B767F0:
	// rlwinm r10,r20,5,0,26
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 5) & 0xFFFFFFE0;
	// li r25,8
	ctx.r25.s64 = 8;
	// subf r28,r10,r29
	ctx.r28.u64 = ctx.r29.u64 - ctx.r10.u64;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
loc_82B76800:
	// cntlzw r7,r8
	ctx.r7.u64 = ctx.r8.u32 == 0 ? 32 : __builtin_clz(ctx.r8.u32);
	// rlwinm r6,r7,27,31,31
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 27) & 0x1;
	// and r5,r6,r17
	ctx.r5.u64 = ctx.r6.u64 & ctx.r17.u64;
	// cmpwi cr6,r5,0
	ctx.cr6.compare<int32_t>(ctx.r5.s32, 0, ctx.xer);
	// bne cr6,0x82b7682c
	if (!ctx.cr6.eq) goto loc_82B7682C;
	// lwz r7,92(r1)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x82b76a88
	if (ctx.cr6.eq) goto loc_82B76A88;
	// lwz r7,-4(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + -4);
	// cmpwi cr6,r7,16384
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 16384, ctx.xer);
	// bne cr6,0x82b76a88
	if (!ctx.cr6.eq) goto loc_82B76A88;
loc_82B7682C:
	// addic. r27,r29,-32
	ctx.xer.ca = ctx.r29.u32 > 31;
	ctx.r27.s64 = ctx.r29.s64 + -32;
	ctx.cr0.compare<int32_t>(ctx.r27.s32, 0, ctx.xer);
	// li r25,1
	ctx.r25.s64 = 1;
	// mr r10,r27
	ctx.r10.u64 = ctx.r27.u64;
	// beq 0x82b76db8
	if (ctx.cr0.eq) goto loc_82B76DB8;
	// cmplwi cr6,r28,0
	ctx.cr6.compare<uint32_t>(ctx.r28.u32, 0, ctx.xer);
	// beq cr6,0x82b76a88
	if (ctx.cr6.eq) goto loc_82B76A88;
	// clrlwi r7,r17,30
	ctx.r7.u64 = ctx.r17.u32 & 0x3;
	// li r6,0
	ctx.r6.s64 = 0;
	// cmpwi cr6,r7,0
	ctx.cr6.compare<int32_t>(ctx.r7.s32, 0, ctx.xer);
	// beq cr6,0x82b7685c
	if (ctx.cr6.eq) goto loc_82B7685C;
	// cmpwi cr6,r8,0
	ctx.cr6.compare<int32_t>(ctx.r8.s32, 0, ctx.xer);
	// beq cr6,0x82b76874
	if (ctx.cr6.eq) goto loc_82B76874;
loc_82B7685C:
	// addi r8,r30,1
	ctx.r8.s64 = ctx.r30.s64 + 1;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r5,r7,r9
	ctx.r5.u64 = ctx.r9.u64 - ctx.r7.u64;
	// lwz r4,0(r5)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r5.u32 + 0);
	// cmpwi cr6,r4,16384
	ctx.cr6.compare<int32_t>(ctx.r4.s32, 16384, ctx.xer);
	// bne cr6,0x82b7687c
	if (!ctx.cr6.eq) goto loc_82B7687C;
loc_82B76874:
	// lhz r9,-16(r28)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r28.u32 + -16);
	// extsh r6,r9
	ctx.r6.s64 = ctx.r9.s16;
loc_82B7687C:
	// lhz r9,16(r28)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r28.u32 + 16);
	// lhz r8,0(r27)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r27.u32 + 0);
	// lbz r7,27(r18)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r18.u32 + 27);
	// extsh r5,r9
	ctx.r5.s64 = ctx.r9.s16;
	// extsh r4,r8
	ctx.r4.s64 = ctx.r8.s16;
	// cmplwi cr6,r7,0
	ctx.cr6.compare<uint32_t>(ctx.r7.u32, 0, ctx.xer);
	// beq cr6,0x82b76a4c
	if (ctx.cr6.eq) goto loc_82B76A4C;
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// beq cr6,0x82b76994
	if (ctx.cr6.eq) goto loc_82B76994;
	// cmpwi cr6,r17,4
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 4, ctx.xer);
	// beq cr6,0x82b76994
	if (ctx.cr6.eq) goto loc_82B76994;
	// cmpwi cr6,r17,5
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 5, ctx.xer);
	// beq cr6,0x82b76994
	if (ctx.cr6.eq) goto loc_82B76994;
	// cmpwi cr6,r17,1
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 1, ctx.xer);
	// lis r31,2
	ctx.r31.s64 = 131072;
	// bne cr6,0x82b76928
	if (!ctx.cr6.eq) goto loc_82B76928;
	// rlwinm r7,r30,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// lwz r9,388(r18)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r18.u32 + 388);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// subf r7,r7,r16
	ctx.r7.u64 = ctx.r16.u64 - ctx.r7.u64;
	// add r8,r11,r8
	ctx.r8.u64 = ctx.r11.u64 + ctx.r8.u64;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r7,0(r7)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r7.u32 + 0);
	// add r24,r8,r9
	ctx.r24.u64 = ctx.r8.u64 + ctx.r9.u64;
	// clrlwi r8,r7,26
	ctx.r8.u64 = ctx.r7.u32 & 0x3F;
	// rlwinm r7,r8,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r24,16(r24)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r24.u32 + 16);
	// add r8,r8,r7
	ctx.r8.u64 = ctx.r8.u64 + ctx.r7.u64;
	// rlwinm r7,r24,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// lwzx r8,r7,r3
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r7.u32 + ctx.r3.u32);
	// lwz r7,16(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// mullw r9,r8,r7
	ctx.r9.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// mullw r7,r7,r5
	ctx.r7.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r5.s32);
	// mullw r6,r9,r6
	ctx.r6.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r6.s32);
	// mullw r5,r8,r7
	ctx.r5.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r7.s32);
	// add r9,r6,r31
	ctx.r9.u64 = ctx.r6.u64 + ctx.r31.u64;
	// add r8,r5,r31
	ctx.r8.u64 = ctx.r5.u64 + ctx.r31.u64;
	// srawi r6,r9,18
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3FFFF) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 18;
	// srawi r5,r8,18
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3FFFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 18;
	// b 0x82b76a54
	goto loc_82B76A54;
loc_82B76928:
	// cmpwi cr6,r17,2
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 2, ctx.xer);
	// bne cr6,0x82b76a50
	if (!ctx.cr6.eq) goto loc_82B76A50;
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r7,-8(r16)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r16.u32 + -8);
	// lwz r9,388(r18)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r18.u32 + 388);
	// add r3,r11,r8
	ctx.r3.u64 = ctx.r11.u64 + ctx.r8.u64;
	// clrlwi r8,r7,26
	ctx.r8.u64 = ctx.r7.u32 & 0x3F;
	// rlwinm r7,r3,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r8,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// add r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 + ctx.r3.u64;
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,16(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// add r9,r8,r9
	ctx.r9.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r8,r7,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,16(r9)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r9.u32 + 16);
	// lwzx r9,r8,r3
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + ctx.r3.u32);
	// mullw r8,r7,r4
	ctx.r8.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r4.s32);
	// mullw r7,r9,r7
	ctx.r7.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r7.s32);
	// mullw r6,r7,r6
	ctx.r6.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r6.s32);
	// mullw r4,r9,r8
	ctx.r4.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r8.s32);
	// add r9,r6,r31
	ctx.r9.u64 = ctx.r6.u64 + ctx.r31.u64;
	// add r8,r4,r31
	ctx.r8.u64 = ctx.r4.u64 + ctx.r31.u64;
	// srawi r6,r9,18
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3FFFF) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 18;
	// srawi r4,r8,18
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3FFFF) != 0);
	ctx.r4.s64 = ctx.r8.s32 >> 18;
	// b 0x82b76a54
	goto loc_82B76A54;
loc_82B76994:
	// rlwinm r7,r30,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// lbz r3,-8(r16)
	ctx.r3.u64 = PPC_LOAD_U8(ctx.r16.u32 + -8);
	// rlwinm r8,r11,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r9,388(r18)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r18.u32 + 388);
	// subf r31,r7,r16
	ctx.r31.u64 = ctx.r16.u64 - ctx.r7.u64;
	// add r7,r11,r8
	ctx.r7.u64 = ctx.r11.u64 + ctx.r8.u64;
	// clrlwi r8,r3,26
	ctx.r8.u64 = ctx.r3.u32 & 0x3F;
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r3,r8,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r24,-8(r31)
	ctx.r24.u64 = PPC_LOAD_U8(ctx.r31.u32 + -8);
	// add r23,r7,r9
	ctx.r23.u64 = ctx.r7.u64 + ctx.r9.u64;
	// add r22,r8,r3
	ctx.r22.u64 = ctx.r8.u64 + ctx.r3.u64;
	// lbz r7,0(r31)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r31.u32 + 0);
	// clrlwi r8,r24,26
	ctx.r8.u64 = ctx.r24.u32 & 0x3F;
	// clrlwi r7,r7,26
	ctx.r7.u64 = ctx.r7.u32 & 0x3F;
	// rlwinm r3,r8,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r31,r7,2,0,29
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r24,16(r23)
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16);
	// add r8,r8,r3
	ctx.r8.u64 = ctx.r8.u64 + ctx.r3.u64;
	// rlwinm r3,r22,2,0,29
	ctx.r3.u64 = __builtin_rotateleft64(ctx.r22.u32 | (ctx.r22.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r7,r31
	ctx.r7.u64 = ctx.r7.u64 + ctx.r31.u64;
	// rlwinm r8,r8,2,0,29
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r8.u32 | (ctx.r8.u64 << 32), 2) & 0xFFFFFFFC;
	// add r23,r3,r9
	ctx.r23.u64 = ctx.r3.u64 + ctx.r9.u64;
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// rlwinm r7,r7,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r7.u32 | (ctx.r7.u64 << 32), 2) & 0xFFFFFFFC;
	// add r8,r8,r9
	ctx.r8.u64 = ctx.r8.u64 + ctx.r9.u64;
	// rlwinm r24,r24,2,0,29
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r24.u32 | (ctx.r24.u64 << 32), 2) & 0xFFFFFFFC;
	// add r7,r7,r9
	ctx.r7.u64 = ctx.r7.u64 + ctx.r9.u64;
	// lwz r9,16(r23)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r23.u32 + 16);
	// lis r31,2
	ctx.r31.s64 = 131072;
	// lwz r8,16(r8)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r8.u32 + 16);
	// mullw r4,r9,r4
	ctx.r4.s64 = int64_t(ctx.r9.s32) * int64_t(ctx.r4.s32);
	// lwzx r24,r24,r3
	ctx.r24.u64 = PPC_LOAD_U32(ctx.r24.u32 + ctx.r3.u32);
	// lwz r9,16(r7)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// mullw r8,r24,r8
	ctx.r8.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r8.s32);
	// mullw r7,r24,r9
	ctx.r7.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r9.s32);
	// mullw r6,r8,r6
	ctx.r6.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r6.s32);
	// mullw r5,r7,r5
	ctx.r5.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r5.s32);
	// mullw r4,r24,r4
	ctx.r4.s64 = int64_t(ctx.r24.s32) * int64_t(ctx.r4.s32);
	// add r9,r6,r31
	ctx.r9.u64 = ctx.r6.u64 + ctx.r31.u64;
	// add r8,r5,r31
	ctx.r8.u64 = ctx.r5.u64 + ctx.r31.u64;
	// add r7,r4,r31
	ctx.r7.u64 = ctx.r4.u64 + ctx.r31.u64;
	// srawi r6,r9,18
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x3FFFF) != 0);
	ctx.r6.s64 = ctx.r9.s32 >> 18;
	// srawi r5,r8,18
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x3FFFF) != 0);
	ctx.r5.s64 = ctx.r8.s32 >> 18;
	// srawi r4,r7,18
	ctx.xer.ca = (ctx.r7.s32 < 0) & ((ctx.r7.u32 & 0x3FFFF) != 0);
	ctx.r4.s64 = ctx.r7.s32 >> 18;
	// b 0x82b76a54
	goto loc_82B76A54;
loc_82B76A4C:
	// lis r31,2
	ctx.r31.s64 = 131072;
loc_82B76A50:
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
loc_82B76A54:
	// subf r9,r5,r6
	ctx.r9.u64 = ctx.r6.u64 - ctx.r5.u64;
	// subf r8,r4,r6
	ctx.r8.u64 = ctx.r6.u64 - ctx.r4.u64;
	// srawi r7,r9,31
	ctx.xer.ca = (ctx.r9.s32 < 0) & ((ctx.r9.u32 & 0x7FFFFFFF) != 0);
	ctx.r7.s64 = ctx.r9.s32 >> 31;
	// srawi r6,r8,31
	ctx.xer.ca = (ctx.r8.s32 < 0) & ((ctx.r8.u32 & 0x7FFFFFFF) != 0);
	ctx.r6.s64 = ctx.r8.s32 >> 31;
	// xor r5,r9,r7
	ctx.r5.u64 = ctx.r9.u64 ^ ctx.r7.u64;
	// xor r4,r8,r6
	ctx.r4.u64 = ctx.r8.u64 ^ ctx.r6.u64;
	// subf r9,r7,r5
	ctx.r9.u64 = ctx.r5.u64 - ctx.r7.u64;
	// subf r8,r6,r4
	ctx.r8.u64 = ctx.r4.u64 - ctx.r6.u64;
	// cmpw cr6,r8,r9
	ctx.cr6.compare<int32_t>(ctx.r8.s32, ctx.r9.s32, ctx.xer);
	// bge cr6,0x82b76a90
	if (!ctx.cr6.lt) goto loc_82B76A90;
	// mr r10,r28
	ctx.r10.u64 = ctx.r28.u64;
	// li r25,8
	ctx.r25.s64 = 8;
	// b 0x82b76a90
	goto loc_82B76A90;
loc_82B76A88:
	// lwz r3,88(r1)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r1.u32 + 88);
	// lis r31,2
	ctx.r31.s64 = 131072;
loc_82B76A90:
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82b76db8
	if (ctx.cr6.eq) goto loc_82B76DB8;
	// lbz r9,27(r18)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r18.u32 + 27);
	// neg r8,r26
	ctx.r8.s64 = static_cast<int64_t>(-ctx.r26.u64);
	// cmplwi cr6,r9,0
	ctx.cr6.compare<uint32_t>(ctx.r9.u32, 0, ctx.xer);
	// or r25,r8,r25
	ctx.r25.u64 = ctx.r8.u64 | ctx.r25.u64;
	// beq cr6,0x82b76dac
	if (ctx.cr6.eq) goto loc_82B76DAC;
	// cmplw cr6,r10,r27
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r27.u32, ctx.xer);
	// bne cr6,0x82b76c2c
	if (!ctx.cr6.eq) goto loc_82B76C2C;
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// beq cr6,0x82b76afc
	if (ctx.cr6.eq) goto loc_82B76AFC;
	// cmpwi cr6,r17,2
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 2, ctx.xer);
	// beq cr6,0x82b76afc
	if (ctx.cr6.eq) goto loc_82B76AFC;
	// cmpwi cr6,r17,4
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 4, ctx.xer);
	// beq cr6,0x82b76afc
	if (ctx.cr6.eq) goto loc_82B76AFC;
	// cmpwi cr6,r17,5
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 5, ctx.xer);
	// beq cr6,0x82b76afc
	if (ctx.cr6.eq) goto loc_82B76AFC;
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// li r9,16
	ctx.r9.s64 = 16;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82B76AE0:
	// lhz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// sth r9,0(r11)
	PPC_STORE_U16(ctx.r11.u32 + 0, ctx.r9.u16);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// bdnz 0x82b76ae0
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82B76AE0;
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// b 0x82b76db8
	goto loc_82B76DB8;
loc_82B76AFC:
	// rlwinm r7,r11,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lbz r9,-8(r16)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r16.u32 + -8);
	// lwz r8,388(r18)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r18.u32 + 388);
	// rlwinm r5,r11,2,0,29
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// add r4,r11,r7
	ctx.r4.u64 = ctx.r11.u64 + ctx.r7.u64;
	// lhz r11,0(r10)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// clrlwi r9,r9,26
	ctx.r9.u64 = ctx.r9.u32 & 0x3F;
	// rlwinm r6,r4,2,0,29
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r7,r9,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// add r6,r6,r8
	ctx.r6.u64 = ctx.r6.u64 + ctx.r8.u64;
	// add r4,r9,r7
	ctx.r4.u64 = ctx.r9.u64 + ctx.r7.u64;
	// extsh r30,r11
	ctx.r30.s64 = ctx.r11.s16;
	// rlwinm r7,r4,2,0,29
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r4,r1,144
	ctx.r4.s64 = ctx.r1.s64 + 144;
	// lwz r11,16(r6)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// add r7,r7,r8
	ctx.r7.u64 = ctx.r7.u64 + ctx.r8.u64;
	// subf r6,r10,r4
	ctx.r6.u64 = ctx.r4.u64 - ctx.r10.u64;
	// lwzx r8,r5,r3
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r5.u32 + ctx.r3.u32);
	// rlwinm r27,r11,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// addi r28,r1,146
	ctx.r28.s64 = ctx.r1.s64 + 146;
	// addi r26,r1,148
	ctx.r26.s64 = ctx.r1.s64 + 148;
	// lwz r7,16(r7)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r7.u32 + 16);
	// addi r11,r10,6
	ctx.r11.s64 = ctx.r10.s64 + 6;
	// subf r5,r10,r28
	ctx.r5.u64 = ctx.r28.u64 - ctx.r10.u64;
	// lwzx r4,r27,r3
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r3.u32);
	// mullw r3,r7,r30
	ctx.r3.s64 = int64_t(ctx.r7.s32) * int64_t(ctx.r30.s32);
	// mullw r7,r4,r3
	ctx.r7.s64 = int64_t(ctx.r4.s32) * int64_t(ctx.r3.s32);
	// add r3,r7,r31
	ctx.r3.u64 = ctx.r7.u64 + ctx.r31.u64;
	// subf r4,r10,r26
	ctx.r4.u64 = ctx.r26.u64 - ctx.r10.u64;
	// srawi r3,r3,18
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3FFFF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 18;
	// addi r7,r1,148
	ctx.r7.s64 = ctx.r1.s64 + 148;
	// li r10,3
	ctx.r10.s64 = 3;
	// sth r3,144(r1)
	PPC_STORE_U16(ctx.r1.u32 + 144, ctx.r3.u16);
loc_82B76B80:
	// lhz r3,-4(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + -4);
	// lhz r30,-2(r11)
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r11.u32 + -2);
	// lhz r28,0(r11)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r3,r3
	ctx.r3.s64 = ctx.r3.s16;
	// lhz r27,2(r11)
	ctx.r27.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// extsh r30,r30
	ctx.r30.s64 = ctx.r30.s16;
	// lhz r26,4(r11)
	ctx.r26.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// extsh r28,r28
	ctx.r28.s64 = ctx.r28.s16;
	// extsh r27,r27
	ctx.r27.s64 = ctx.r27.s16;
	// mullw r3,r3,r8
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// extsh r26,r26
	ctx.r26.s64 = ctx.r26.s16;
	// mullw r30,r30,r8
	ctx.r30.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r8.s32);
	// mullw r28,r28,r8
	ctx.r28.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r8.s32);
	// mullw r27,r27,r8
	ctx.r27.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r8.s32);
	// mullw r3,r3,r9
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32);
	// mullw r26,r26,r9
	ctx.r26.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r9.s32);
	// mullw r30,r30,r9
	ctx.r30.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r9.s32);
	// mullw r28,r28,r9
	ctx.r28.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// mullw r27,r27,r9
	ctx.r27.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r9.s32);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + ctx.r31.u64;
	// mullw r26,r8,r26
	ctx.r26.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r26.s32);
	// add r30,r30,r31
	ctx.r30.u64 = ctx.r30.u64 + ctx.r31.u64;
	// add r28,r28,r31
	ctx.r28.u64 = ctx.r28.u64 + ctx.r31.u64;
	// srawi r3,r3,18
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3FFFF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 18;
	// add r27,r27,r31
	ctx.r27.u64 = ctx.r27.u64 + ctx.r31.u64;
	// srawi r30,r30,18
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x3FFFF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 18;
	// sth r3,-2(r7)
	PPC_STORE_U16(ctx.r7.u32 + -2, ctx.r3.u16);
	// add r26,r26,r31
	ctx.r26.u64 = ctx.r26.u64 + ctx.r31.u64;
	// srawi r28,r28,18
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x3FFFF) != 0);
	ctx.r28.s64 = ctx.r28.s32 >> 18;
	// sth r30,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, ctx.r30.u16);
	// srawi r27,r27,18
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x3FFFF) != 0);
	ctx.r27.s64 = ctx.r27.s32 >> 18;
	// srawi r26,r26,18
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x3FFFF) != 0);
	ctx.r26.s64 = ctx.r26.s32 >> 18;
	// sthx r28,r11,r6
	PPC_STORE_U16(ctx.r11.u32 + ctx.r6.u32, ctx.r28.u16);
	// sthx r27,r11,r5
	PPC_STORE_U16(ctx.r11.u32 + ctx.r5.u32, ctx.r27.u16);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// sthx r26,r11,r4
	PPC_STORE_U16(ctx.r11.u32 + ctx.r4.u32, ctx.r26.u16);
	// addi r7,r7,10
	ctx.r7.s64 = ctx.r7.s64 + 10;
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// bne 0x82b76b80
	if (!ctx.cr0.eq) goto loc_82B76B80;
	// lhz r11,144(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 144);
	// addi r10,r1,144
	ctx.r10.s64 = ctx.r1.s64 + 144;
	// sth r11,160(r1)
	PPC_STORE_U16(ctx.r1.u32 + 160, ctx.r11.u16);
	// b 0x82b76db8
	goto loc_82B76DB8;
loc_82B76C2C:
	// cmpwi cr6,r17,0
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 0, ctx.xer);
	// beq cr6,0x82b76c74
	if (ctx.cr6.eq) goto loc_82B76C74;
	// cmpwi cr6,r17,1
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 1, ctx.xer);
	// beq cr6,0x82b76c74
	if (ctx.cr6.eq) goto loc_82B76C74;
	// cmpwi cr6,r17,4
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 4, ctx.xer);
	// beq cr6,0x82b76c74
	if (ctx.cr6.eq) goto loc_82B76C74;
	// cmpwi cr6,r17,5
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 5, ctx.xer);
	// beq cr6,0x82b76c74
	if (ctx.cr6.eq) goto loc_82B76C74;
	// addi r11,r1,144
	ctx.r11.s64 = ctx.r1.s64 + 144;
	// li r9,16
	ctx.r9.s64 = 16;
	// mtctr r9
	ctx.ctr.u64 = ctx.r9.u64;
loc_82B76C58:
	// lhz r9,0(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// addi r10,r10,2
	ctx.r10.s64 = ctx.r10.s64 + 2;
	// sth r9,0(r11)
	PPC_STORE_U16(ctx.r11.u32 + 0, ctx.r9.u16);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// bdnz 0x82b76c58
	--ctx.ctr.u64;
	if (ctx.ctr.u32 != 0) goto loc_82B76C58;
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// b 0x82b76db8
	goto loc_82B76DB8;
loc_82B76C74:
	// rlwinm r8,r30,3,0,28
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r30.u32 | (ctx.r30.u64 << 32), 3) & 0xFFFFFFF8;
	// lhz r6,0(r10)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// rlwinm r9,r11,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r7,388(r18)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r18.u32 + 388);
	// subf r5,r8,r16
	ctx.r5.u64 = ctx.r16.u64 - ctx.r8.u64;
	// add r4,r11,r9
	ctx.r4.u64 = ctx.r11.u64 + ctx.r9.u64;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r9,r4,2,0,29
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r4.u32 | (ctx.r4.u64 << 32), 2) & 0xFFFFFFFC;
	// extsh r30,r6
	ctx.r30.s64 = ctx.r6.s16;
	// lbz r8,0(r5)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r5.u32 + 0);
	// add r6,r9,r7
	ctx.r6.u64 = ctx.r9.u64 + ctx.r7.u64;
	// addi r5,r1,144
	ctx.r5.s64 = ctx.r1.s64 + 144;
	// clrlwi r9,r8,26
	ctx.r9.u64 = ctx.r8.u32 & 0x3F;
	// lwzx r8,r11,r3
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + ctx.r3.u32);
	// addi r4,r1,146
	ctx.r4.s64 = ctx.r1.s64 + 146;
	// rlwinm r11,r9,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 2) & 0xFFFFFFFC;
	// lwz r6,16(r6)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r6.u32 + 16);
	// addi r28,r1,148
	ctx.r28.s64 = ctx.r1.s64 + 148;
	// add r11,r9,r11
	ctx.r11.u64 = ctx.r9.u64 + ctx.r11.u64;
	// rlwinm r27,r6,2,0,29
	ctx.r27.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 2) & 0xFFFFFFFC;
	// rlwinm r11,r11,2,0,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 2) & 0xFFFFFFFC;
	// subf r6,r10,r5
	ctx.r6.u64 = ctx.r5.u64 - ctx.r10.u64;
	// add r26,r11,r7
	ctx.r26.u64 = ctx.r11.u64 + ctx.r7.u64;
	// subf r5,r10,r4
	ctx.r5.u64 = ctx.r4.u64 - ctx.r10.u64;
	// subf r4,r10,r28
	ctx.r4.u64 = ctx.r28.u64 - ctx.r10.u64;
	// lwzx r3,r27,r3
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r27.u32 + ctx.r3.u32);
	// addi r11,r10,6
	ctx.r11.s64 = ctx.r10.s64 + 6;
	// addi r7,r1,148
	ctx.r7.s64 = ctx.r1.s64 + 148;
	// lwz r28,16(r26)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r26.u32 + 16);
	// li r10,3
	ctx.r10.s64 = 3;
	// mullw r30,r28,r30
	ctx.r30.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r30.s32);
	// mullw r3,r3,r30
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r30.s32);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + ctx.r31.u64;
	// srawi r3,r3,18
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3FFFF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 18;
	// sth r3,144(r1)
	PPC_STORE_U16(ctx.r1.u32 + 144, ctx.r3.u16);
loc_82B76D00:
	// lhz r3,-4(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + -4);
	// lhz r30,-2(r11)
	ctx.r30.u64 = PPC_LOAD_U16(ctx.r11.u32 + -2);
	// lhz r28,0(r11)
	ctx.r28.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// extsh r3,r3
	ctx.r3.s64 = ctx.r3.s16;
	// lhz r27,2(r11)
	ctx.r27.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// extsh r30,r30
	ctx.r30.s64 = ctx.r30.s16;
	// lhz r26,4(r11)
	ctx.r26.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// extsh r28,r28
	ctx.r28.s64 = ctx.r28.s16;
	// extsh r27,r27
	ctx.r27.s64 = ctx.r27.s16;
	// mullw r3,r3,r8
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r8.s32);
	// extsh r26,r26
	ctx.r26.s64 = ctx.r26.s16;
	// mullw r30,r30,r8
	ctx.r30.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r8.s32);
	// mullw r28,r28,r8
	ctx.r28.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r8.s32);
	// mullw r27,r27,r8
	ctx.r27.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r8.s32);
	// mullw r3,r3,r9
	ctx.r3.s64 = int64_t(ctx.r3.s32) * int64_t(ctx.r9.s32);
	// mullw r26,r26,r9
	ctx.r26.s64 = int64_t(ctx.r26.s32) * int64_t(ctx.r9.s32);
	// mullw r30,r30,r9
	ctx.r30.s64 = int64_t(ctx.r30.s32) * int64_t(ctx.r9.s32);
	// mullw r28,r28,r9
	ctx.r28.s64 = int64_t(ctx.r28.s32) * int64_t(ctx.r9.s32);
	// mullw r27,r27,r9
	ctx.r27.s64 = int64_t(ctx.r27.s32) * int64_t(ctx.r9.s32);
	// add r3,r3,r31
	ctx.r3.u64 = ctx.r3.u64 + ctx.r31.u64;
	// mullw r26,r8,r26
	ctx.r26.s64 = int64_t(ctx.r8.s32) * int64_t(ctx.r26.s32);
	// add r30,r30,r31
	ctx.r30.u64 = ctx.r30.u64 + ctx.r31.u64;
	// add r28,r28,r31
	ctx.r28.u64 = ctx.r28.u64 + ctx.r31.u64;
	// srawi r3,r3,18
	ctx.xer.ca = (ctx.r3.s32 < 0) & ((ctx.r3.u32 & 0x3FFFF) != 0);
	ctx.r3.s64 = ctx.r3.s32 >> 18;
	// add r27,r27,r31
	ctx.r27.u64 = ctx.r27.u64 + ctx.r31.u64;
	// srawi r30,r30,18
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0x3FFFF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 18;
	// sth r3,-2(r7)
	PPC_STORE_U16(ctx.r7.u32 + -2, ctx.r3.u16);
	// add r26,r26,r31
	ctx.r26.u64 = ctx.r26.u64 + ctx.r31.u64;
	// srawi r28,r28,18
	ctx.xer.ca = (ctx.r28.s32 < 0) & ((ctx.r28.u32 & 0x3FFFF) != 0);
	ctx.r28.s64 = ctx.r28.s32 >> 18;
	// sth r30,0(r7)
	PPC_STORE_U16(ctx.r7.u32 + 0, ctx.r30.u16);
	// srawi r27,r27,18
	ctx.xer.ca = (ctx.r27.s32 < 0) & ((ctx.r27.u32 & 0x3FFFF) != 0);
	ctx.r27.s64 = ctx.r27.s32 >> 18;
	// srawi r26,r26,18
	ctx.xer.ca = (ctx.r26.s32 < 0) & ((ctx.r26.u32 & 0x3FFFF) != 0);
	ctx.r26.s64 = ctx.r26.s32 >> 18;
	// sthx r28,r11,r6
	PPC_STORE_U16(ctx.r11.u32 + ctx.r6.u32, ctx.r28.u16);
	// sthx r27,r11,r5
	PPC_STORE_U16(ctx.r11.u32 + ctx.r5.u32, ctx.r27.u16);
	// addic. r10,r10,-1
	ctx.xer.ca = ctx.r10.u32 > 0;
	ctx.r10.s64 = ctx.r10.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// sthx r26,r11,r4
	PPC_STORE_U16(ctx.r11.u32 + ctx.r4.u32, ctx.r26.u16);
	// addi r7,r7,10
	ctx.r7.s64 = ctx.r7.s64 + 10;
	// addi r11,r11,10
	ctx.r11.s64 = ctx.r11.s64 + 10;
	// bne 0x82b76d00
	if (!ctx.cr0.eq) goto loc_82B76D00;
	// lhz r11,144(r1)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r1.u32 + 144);
	// addi r10,r1,160
	ctx.r10.s64 = ctx.r1.s64 + 160;
	// sth r11,160(r1)
	PPC_STORE_U16(ctx.r1.u32 + 160, ctx.r11.u16);
	// b 0x82b76db8
	goto loc_82B76DB8;
loc_82B76DAC:
	// cmplw cr6,r10,r28
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, ctx.r28.u32, ctx.xer);
	// bne cr6,0x82b76db8
	if (!ctx.cr6.eq) goto loc_82B76DB8;
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
loc_82B76DB8:
	// lwz r11,372(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// lwz r11,28(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 28);
	// beq cr6,0x82b76f9c
	if (ctx.cr6.eq) goto loc_82B76F9C;
	// lhz r9,0(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// cmpwi cr6,r25,1
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 1, ctx.xer);
	// lhz r8,0(r10)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r10.u32 + 0);
	// add r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// sth r6,0(r11)
	PPC_STORE_U16(ctx.r11.u32 + 0, ctx.r6.u16);
	// sth r6,0(r29)
	PPC_STORE_U16(ctx.r29.u32 + 0, ctx.r6.u16);
	// sth r6,16(r29)
	PPC_STORE_U16(ctx.r29.u32 + 16, ctx.r6.u16);
	// bne cr6,0x82b76ed0
	if (!ctx.cr6.eq) goto loc_82B76ED0;
	// lhz r9,2(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// lhz r8,2(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// add r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// sth r6,2(r11)
	PPC_STORE_U16(ctx.r11.u32 + 2, ctx.r6.u16);
	// sth r6,2(r29)
	PPC_STORE_U16(ctx.r29.u32 + 2, ctx.r6.u16);
	// lhz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// lhz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 4);
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r3
	ctx.r9.s64 = ctx.r3.s16;
	// sth r9,4(r11)
	PPC_STORE_U16(ctx.r11.u32 + 4, ctx.r9.u16);
	// sth r9,4(r29)
	PPC_STORE_U16(ctx.r29.u32 + 4, ctx.r9.u16);
	// lhz r8,6(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 6);
	// lhz r9,6(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// add r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// sth r5,6(r11)
	PPC_STORE_U16(ctx.r11.u32 + 6, ctx.r5.u16);
	// sth r5,6(r29)
	PPC_STORE_U16(ctx.r29.u32 + 6, ctx.r5.u16);
	// lhz r3,8(r10)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// lhz r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 8);
	// add r9,r3,r8
	ctx.r9.u64 = ctx.r3.u64 + ctx.r8.u64;
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// sth r8,8(r11)
	PPC_STORE_U16(ctx.r11.u32 + 8, ctx.r8.u16);
	// sth r8,8(r29)
	PPC_STORE_U16(ctx.r29.u32 + 8, ctx.r8.u16);
	// lhz r9,10(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 10);
	// lhz r8,10(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 10);
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// sth r4,10(r11)
	PPC_STORE_U16(ctx.r11.u32 + 10, ctx.r4.u16);
	// sth r4,10(r29)
	PPC_STORE_U16(ctx.r29.u32 + 10, ctx.r4.u16);
	// lhz r3,12(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 12);
	// lhz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 12);
	// add r8,r9,r3
	ctx.r8.u64 = ctx.r9.u64 + ctx.r3.u64;
	// extsh r7,r8
	ctx.r7.s64 = ctx.r8.s16;
	// sth r7,12(r11)
	PPC_STORE_U16(ctx.r11.u32 + 12, ctx.r7.u16);
	// sth r7,12(r29)
	PPC_STORE_U16(ctx.r29.u32 + 12, ctx.r7.u16);
	// lhz r9,14(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 14);
	// lhz r10,14(r10)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r10.u32 + 14);
	// add r4,r10,r9
	ctx.r4.u64 = ctx.r10.u64 + ctx.r9.u64;
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// sth r3,14(r11)
	PPC_STORE_U16(ctx.r11.u32 + 14, ctx.r3.u16);
	// sth r3,14(r29)
	PPC_STORE_U16(ctx.r29.u32 + 14, ctx.r3.u16);
	// lhz r10,16(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 16);
	// sth r10,18(r29)
	PPC_STORE_U16(ctx.r29.u32 + 18, ctx.r10.u16);
	// lhz r9,32(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 32);
	// sth r9,20(r29)
	PPC_STORE_U16(ctx.r29.u32 + 20, ctx.r9.u16);
	// lhz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 48);
	// sth r8,22(r29)
	PPC_STORE_U16(ctx.r29.u32 + 22, ctx.r8.u16);
	// lhz r7,64(r11)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + 64);
	// sth r7,24(r29)
	PPC_STORE_U16(ctx.r29.u32 + 24, ctx.r7.u16);
	// lhz r6,80(r11)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r11.u32 + 80);
	// sth r6,26(r29)
	PPC_STORE_U16(ctx.r29.u32 + 26, ctx.r6.u16);
	// lhz r5,96(r11)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r11.u32 + 96);
	// sth r5,28(r29)
	PPC_STORE_U16(ctx.r29.u32 + 28, ctx.r5.u16);
	// lhz r4,112(r11)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r11.u32 + 112);
	// sth r4,30(r29)
	PPC_STORE_U16(ctx.r29.u32 + 30, ctx.r4.u16);
	// b 0x82b76ff8
	goto loc_82B76FF8;
loc_82B76ED0:
	// cmpwi cr6,r25,8
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 8, ctx.xer);
	// bne cr6,0x82b76fa8
	if (!ctx.cr6.eq) goto loc_82B76FA8;
	// lhz r9,2(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// sth r9,2(r29)
	PPC_STORE_U16(ctx.r29.u32 + 2, ctx.r9.u16);
	// lwz r8,4(r11)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r8,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r8.u32);
	// ld r7,8(r11)
	ctx.r7.u64 = PPC_LOAD_U64(ctx.r11.u32 + 8);
	// std r7,8(r29)
	PPC_STORE_U64(ctx.r29.u32 + 8, ctx.r7.u64);
	// lhz r9,2(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 2);
	// lhz r8,16(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 16);
	// add r4,r9,r8
	ctx.r4.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r3,r4
	ctx.r3.s64 = ctx.r4.s16;
	// sth r3,16(r11)
	PPC_STORE_U16(ctx.r11.u32 + 16, ctx.r3.u16);
	// sth r3,18(r29)
	PPC_STORE_U16(ctx.r29.u32 + 18, ctx.r3.u16);
	// lhz r9,4(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 4);
	// lhz r8,32(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 32);
	// add r7,r9,r8
	ctx.r7.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r6,r7
	ctx.r6.s64 = ctx.r7.s16;
	// sth r6,32(r11)
	PPC_STORE_U16(ctx.r11.u32 + 32, ctx.r6.u16);
	// sth r6,20(r29)
	PPC_STORE_U16(ctx.r29.u32 + 20, ctx.r6.u16);
	// lhz r9,6(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 6);
	// lhz r8,48(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 48);
	// add r3,r9,r8
	ctx.r3.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r9,r3
	ctx.r9.s64 = ctx.r3.s16;
	// sth r9,48(r11)
	PPC_STORE_U16(ctx.r11.u32 + 48, ctx.r9.u16);
	// sth r9,22(r29)
	PPC_STORE_U16(ctx.r29.u32 + 22, ctx.r9.u16);
	// lhz r9,8(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 8);
	// lhz r8,64(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 64);
	// add r6,r9,r8
	ctx.r6.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r5,r6
	ctx.r5.s64 = ctx.r6.s16;
	// sth r5,64(r11)
	PPC_STORE_U16(ctx.r11.u32 + 64, ctx.r5.u16);
	// sth r5,24(r29)
	PPC_STORE_U16(ctx.r29.u32 + 24, ctx.r5.u16);
	// lhz r4,10(r10)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r10.u32 + 10);
	// lhz r8,80(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 80);
	// add r9,r4,r8
	ctx.r9.u64 = ctx.r4.u64 + ctx.r8.u64;
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// sth r8,80(r11)
	PPC_STORE_U16(ctx.r11.u32 + 80, ctx.r8.u16);
	// sth r8,26(r29)
	PPC_STORE_U16(ctx.r29.u32 + 26, ctx.r8.u16);
	// lhz r8,96(r11)
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r11.u32 + 96);
	// lhz r9,12(r10)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r10.u32 + 12);
	// add r5,r9,r8
	ctx.r5.u64 = ctx.r9.u64 + ctx.r8.u64;
	// extsh r4,r5
	ctx.r4.s64 = ctx.r5.s16;
	// sth r4,96(r11)
	PPC_STORE_U16(ctx.r11.u32 + 96, ctx.r4.u16);
	// sth r4,28(r29)
	PPC_STORE_U16(ctx.r29.u32 + 28, ctx.r4.u16);
	// lhz r9,112(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 112);
	// lhz r3,14(r10)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r10.u32 + 14);
	// add r9,r3,r9
	ctx.r9.u64 = ctx.r3.u64 + ctx.r9.u64;
	// extsh r8,r9
	ctx.r8.s64 = ctx.r9.s16;
	// sth r8,112(r11)
	PPC_STORE_U16(ctx.r11.u32 + 112, ctx.r8.u16);
	// sth r8,30(r29)
	PPC_STORE_U16(ctx.r29.u32 + 30, ctx.r8.u16);
	// b 0x82b76ff8
	goto loc_82B76FF8;
loc_82B76F9C:
	// lhz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 0);
	// sth r10,0(r29)
	PPC_STORE_U16(ctx.r29.u32 + 0, ctx.r10.u16);
	// sth r10,16(r29)
	PPC_STORE_U16(ctx.r29.u32 + 16, ctx.r10.u16);
loc_82B76FA8:
	// lhz r10,2(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 2);
	// sth r10,2(r29)
	PPC_STORE_U16(ctx.r29.u32 + 2, ctx.r10.u16);
	// lwz r9,4(r11)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r11.u32 + 4);
	// stw r9,4(r29)
	PPC_STORE_U32(ctx.r29.u32 + 4, ctx.r9.u32);
	// ld r8,8(r11)
	ctx.r8.u64 = PPC_LOAD_U64(ctx.r11.u32 + 8);
	// std r8,8(r29)
	PPC_STORE_U64(ctx.r29.u32 + 8, ctx.r8.u64);
	// lhz r7,16(r11)
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r11.u32 + 16);
	// sth r7,18(r29)
	PPC_STORE_U16(ctx.r29.u32 + 18, ctx.r7.u16);
	// lhz r6,32(r11)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r11.u32 + 32);
	// sth r6,20(r29)
	PPC_STORE_U16(ctx.r29.u32 + 20, ctx.r6.u16);
	// lhz r5,48(r11)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r11.u32 + 48);
	// sth r5,22(r29)
	PPC_STORE_U16(ctx.r29.u32 + 22, ctx.r5.u16);
	// lhz r4,64(r11)
	ctx.r4.u64 = PPC_LOAD_U16(ctx.r11.u32 + 64);
	// sth r4,24(r29)
	PPC_STORE_U16(ctx.r29.u32 + 24, ctx.r4.u16);
	// lhz r3,80(r11)
	ctx.r3.u64 = PPC_LOAD_U16(ctx.r11.u32 + 80);
	// sth r3,26(r29)
	PPC_STORE_U16(ctx.r29.u32 + 26, ctx.r3.u16);
	// lhz r10,96(r11)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r11.u32 + 96);
	// sth r10,28(r29)
	PPC_STORE_U16(ctx.r29.u32 + 28, ctx.r10.u16);
	// lhz r9,112(r11)
	ctx.r9.u64 = PPC_LOAD_U16(ctx.r11.u32 + 112);
	// sth r9,30(r29)
	PPC_STORE_U16(ctx.r29.u32 + 30, ctx.r9.u16);
loc_82B76FF8:
	// lbz r11,80(r1)
	ctx.r11.u64 = PPC_LOAD_U8(ctx.r1.u32 + 80);
	// addi r17,r17,1
	ctx.r17.s64 = ctx.r17.s64 + 1;
	// rlwinm r10,r11,31,1,31
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 31) & 0x7FFFFFFF;
	// cmpwi cr6,r17,6
	ctx.cr6.compare<int32_t>(ctx.r17.s32, 6, ctx.xer);
	// stb r10,80(r1)
	PPC_STORE_U8(ctx.r1.u32 + 80, ctx.r10.u8);
	// blt cr6,0x82b76300
	if (ctx.cr6.lt) goto loc_82B76300;
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// lwz r8,372(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// lwz r11,0(r9)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// lbz r5,5(r9)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r9.u32 + 5);
	// clrlwi r7,r11,1
	ctx.r7.u64 = ctx.r11.u32 & 0x7FFFFFFF;
	// lbz r6,4(r9)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r9.u32 + 4);
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// rldimi r5,r6,8,48
	ctx.r5.u64 = (__builtin_rotateleft64(ctx.r6.u64, 8) & 0xFF00) | (ctx.r5.u64 & 0xFFFFFFFFFFFF00FF);
	// rldicr r4,r5,48,15
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u64, 48) & 0xFFFF000000000000;
	// lwz r3,4(r8)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// lwz r11,1312(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 1312);
	// rlwinm r10,r3,3,0,28
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 3) & 0xFFFFFFF8;
	// stdx r4,r10,r11
	PPC_STORE_U64(ctx.r10.u32 + ctx.r11.u32, ctx.r4.u64);
	// b 0x82b77510
	goto loc_82B77510;
loc_82B77048:
	// lbz r10,29(r18)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r18.u32 + 29);
	// li r24,0
	ctx.r24.s64 = 0;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// lbz r25,34(r18)
	ctx.r25.u64 = PPC_LOAD_U8(ctx.r18.u32 + 34);
	// mr r28,r10
	ctx.r28.u64 = ctx.r10.u64;
	// lbz r20,5(r26)
	ctx.r20.u64 = PPC_LOAD_U8(ctx.r26.u32 + 5);
	// rlwinm r23,r11,12,30,31
	ctx.r23.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0x3;
	// rlwinm r19,r11,4,31,31
	ctx.r19.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 4) & 0x1;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82b77074
	if (ctx.cr6.eq) goto loc_82B77074;
	// rlwinm r25,r11,8,29,31
	ctx.r25.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 8) & 0x7;
loc_82B77074:
	// lbz r10,28(r18)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r18.u32 + 28);
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82b77090
	if (ctx.cr6.eq) goto loc_82B77090;
	// lwz r10,396(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 396);
	// rlwinm r11,r11,12,28,29
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 12) & 0xC;
	// add r22,r11,r10
	ctx.r22.u64 = ctx.r11.u64 + ctx.r10.u64;
	// b 0x82b77094
	goto loc_82B77094;
loc_82B77090:
	// addi r22,r18,404
	ctx.r22.s64 = ctx.r18.s64 + 404;
loc_82B77094:
	// lis r11,0
	ctx.r11.s64 = 0;
	// lwz r17,372(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// li r21,0
	ctx.r21.s64 = 0;
	// ori r27,r11,32768
	ctx.r27.u64 = ctx.r11.u64 | 32768;
loc_82B770A4:
	// clrlwi r11,r20,31
	ctx.r11.u64 = ctx.r20.u32 & 0x1;
	// cmpwi cr6,r11,0
	ctx.cr6.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// beq cr6,0x82b774a0
	if (ctx.cr6.eq) goto loc_82B774A0;
	// addi r11,r28,-1
	ctx.r11.s64 = ctx.r28.s64 + -1;
	// and r10,r11,r19
	ctx.r10.u64 = ctx.r11.u64 & ctx.r19.u64;
	// cmplwi cr6,r10,0
	ctx.cr6.compare<uint32_t>(ctx.r10.u32, 0, ctx.xer);
	// beq cr6,0x82b77204
	if (ctx.cr6.eq) goto loc_82B77204;
	// lwz r31,0(r18)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r10,608(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 608);
	// ld r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r29,0(r10)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rldicl r9,r11,6,58
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 6) & 0x3F;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r8,r29
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r29.u32);
	// extsh r30,r7
	ctx.r30.s64 = ctx.r7.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82b771a8
	if (ctx.cr6.lt) goto loc_82B771A8;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r9,r30,28
	ctx.r9.u64 = ctx.r30.u32 & 0xF;
	// sld r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r9.u8 & 0x7F));
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// std r8,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge cr6,0x82b771a0
	if (!ctx.cr6.lt) goto loc_82B771A0;
loc_82B77108:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82b77134
	if (ctx.cr6.lt) goto loc_82B77134;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd078
	ctx.lr = 0x82B77124;
	sub_829DD078(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x82b77108
	if (ctx.cr6.eq) goto loc_82B77108;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x82b771e4
	goto loc_82B771E4;
loc_82B77134:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r10,r10,8,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r4,2(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,3(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r8,5(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r5,r10,8,55
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// neg r4,r10
	ctx.r4.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r5,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rldicr r11,r7,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// sld r11,r11,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r3.u8 & 0x7F));
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// std r6,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r6.u64);
loc_82B771A0:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x82b771e4
	goto loc_82B771E4;
loc_82B771A8:
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd208
	ctx.lr = 0x82B771B4;
	sub_829DD208(ctx, base);
loc_82B771B4:
	// ld r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x829dd208
	ctx.lr = 0x82B771CC;
	sub_829DD208(ctx, base);
	// add r10,r30,r27
	ctx.r10.u64 = ctx.r30.u64 + ctx.r27.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82b771b4
	if (ctx.cr6.lt) goto loc_82B771B4;
loc_82B771E4:
	// lwz r11,0(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r10,20(r11)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r11.u32 + 20);
	// cmpwi cr6,r10,0
	ctx.cr6.compare<int32_t>(ctx.r10.s32, 0, ctx.xer);
	// bne cr6,0x82b775f0
	if (!ctx.cr6.eq) goto loc_82B775F0;
	// add r11,r30,r18
	ctx.r11.u64 = ctx.r30.u64 + ctx.r18.u64;
	// add r10,r30,r18
	ctx.r10.u64 = ctx.r30.u64 + ctx.r18.u64;
	// lbz r25,684(r11)
	ctx.r25.u64 = PPC_LOAD_U8(ctx.r11.u32 + 684);
	// lbz r23,692(r10)
	ctx.r23.u64 = PPC_LOAD_U8(ctx.r10.u32 + 692);
loc_82B77204:
	// cmpwi cr6,r25,0
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 0, ctx.xer);
	// bne cr6,0x82b7724c
	if (!ctx.cr6.eq) goto loc_82B7724C;
	// lwz r31,20(r17)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r17.u32 + 20);
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// lwz r4,0(r22)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// mr r6,r31
	ctx.r6.u64 = ctx.r31.u64;
	// lbz r5,160(r18)
	ctx.r5.u64 = PPC_LOAD_U8(ctx.r18.u32 + 160);
	// bl 0x82b354c8
	ctx.lr = 0x82B77224;
	sub_82B354C8(ctx, base);
	// rlwinm r11,r3,1,24,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFE;
	// lwz r10,24(r17)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r17.u32 + 24);
	// ori r24,r24,1
	ctx.r24.u64 = ctx.r24.u64 | 1;
	// add r8,r11,r31
	ctx.r8.u64 = ctx.r11.u64 + ctx.r31.u64;
	// stw r8,20(r17)
	PPC_STORE_U32(ctx.r17.u32 + 20, ctx.r8.u32);
	// stb r3,0(r10)
	PPC_STORE_U8(ctx.r10.u32 + 0, ctx.r3.u8);
	// lwz r11,24(r17)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r17.u32 + 24);
	// addi r7,r11,1
	ctx.r7.s64 = ctx.r11.s64 + 1;
	// stw r7,24(r17)
	PPC_STORE_U32(ctx.r17.u32 + 24, ctx.r7.u32);
	// b 0x82b7749c
	goto loc_82B7749C;
loc_82B7724C:
	// cmpwi cr6,r25,2
	ctx.cr6.compare<int32_t>(ctx.r25.s32, 2, ctx.xer);
	// bgt cr6,0x82b772d0
	if (ctx.cr6.gt) goto loc_82B772D0;
	// or r11,r19,r28
	ctx.r11.u64 = ctx.r19.u64 | ctx.r28.u64;
	// cmplwi cr6,r11,0
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, 0, ctx.xer);
	// beq cr6,0x82b77268
	if (ctx.cr6.eq) goto loc_82B77268;
	// mr r11,r23
	ctx.r11.u64 = ctx.r23.u64;
	// b 0x82b77408
	goto loc_82B77408;
loc_82B77268:
	// lwz r3,0(r18)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x82b77290
	if (!ctx.cr0.lt) goto loc_82B77290;
	// bl 0x829dd138
	ctx.lr = 0x82B77290;
	sub_829DD138(ctx, base);
loc_82B77290:
	// cmplwi cr6,r31,1
	ctx.cr6.compare<uint32_t>(ctx.r31.u32, 1, ctx.xer);
	// bne cr6,0x82b772c8
	if (!ctx.cr6.eq) goto loc_82B772C8;
	// lwz r3,0(r18)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// ld r10,0(r3)
	ctx.r10.u64 = PPC_LOAD_U64(ctx.r3.u32 + 0);
	// lwz r9,8(r3)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r3.u32 + 8);
	// rldicr r8,r10,1,62
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0xFFFFFFFFFFFFFFFE;
	// addic. r11,r9,-1
	ctx.xer.ca = ctx.r9.u32 > 0;
	ctx.r11.s64 = ctx.r9.s64 + -1;
	ctx.cr0.compare<int32_t>(ctx.r11.s32, 0, ctx.xer);
	// rldicl r31,r10,1,63
	ctx.r31.u64 = __builtin_rotateleft64(ctx.r10.u64, 1) & 0x1;
	// std r8,0(r3)
	PPC_STORE_U64(ctx.r3.u32 + 0, ctx.r8.u64);
	// stw r11,8(r3)
	PPC_STORE_U32(ctx.r3.u32 + 8, ctx.r11.u32);
	// bge 0x82b772c0
	if (!ctx.cr0.lt) goto loc_82B772C0;
	// bl 0x829dd138
	ctx.lr = 0x82B772C0;
	sub_829DD138(ctx, base);
loc_82B772C0:
	// addi r11,r31,1
	ctx.r11.s64 = ctx.r31.s64 + 1;
	// b 0x82b77408
	goto loc_82B77408;
loc_82B772C8:
	// li r11,3
	ctx.r11.s64 = 3;
	// b 0x82b77408
	goto loc_82B77408;
loc_82B772D0:
	// lwz r31,0(r18)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// lwz r10,612(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 612);
	// ld r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// lwz r29,0(r10)
	ctx.r29.u64 = PPC_LOAD_U32(ctx.r10.u32 + 0);
	// rldicl r9,r11,6,58
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r11.u64, 6) & 0x3F;
	// rlwinm r8,r9,1,0,30
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r9.u32 | (ctx.r9.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r7,r8,r29
	ctx.r7.u64 = PPC_LOAD_U16(ctx.r8.u32 + ctx.r29.u32);
	// extsh r30,r7
	ctx.r30.s64 = ctx.r7.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82b773b8
	if (ctx.cr6.lt) goto loc_82B773B8;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// clrlwi r9,r30,28
	ctx.r9.u64 = ctx.r30.u32 & 0xF;
	// sld r8,r11,r9
	ctx.r8.u64 = ctx.r9.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r9.u8 & 0x7F));
	// subf r7,r9,r10
	ctx.r7.u64 = ctx.r10.u64 - ctx.r9.u64;
	// std r8,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r8.u64);
	// cmpw cr6,r10,r9
	ctx.cr6.compare<int32_t>(ctx.r10.s32, ctx.r9.s32, ctx.xer);
	// stw r7,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r7.u32);
	// bge cr6,0x82b773b0
	if (!ctx.cr6.lt) goto loc_82B773B0;
loc_82B77318:
	// lwz r10,16(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 16);
	// lwz r11,12(r31)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r31.u32 + 12);
	// addi r10,r10,-4
	ctx.r10.s64 = ctx.r10.s64 + -4;
	// cmplw cr6,r11,r10
	ctx.cr6.compare<uint32_t>(ctx.r11.u32, ctx.r10.u32, ctx.xer);
	// blt cr6,0x82b77344
	if (ctx.cr6.lt) goto loc_82B77344;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd078
	ctx.lr = 0x82B77334;
	sub_829DD078(ctx, base);
	// cmplwi cr6,r3,1
	ctx.cr6.compare<uint32_t>(ctx.r3.u32, 1, ctx.xer);
	// beq cr6,0x82b77318
	if (ctx.cr6.eq) goto loc_82B77318;
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x82b773f4
	goto loc_82B773F4;
loc_82B77344:
	// lbz r10,0(r11)
	ctx.r10.u64 = PPC_LOAD_U8(ctx.r11.u32 + 0);
	// addi r3,r11,6
	ctx.r3.s64 = ctx.r11.s64 + 6;
	// lbz r9,1(r11)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r11.u32 + 1);
	// rldicr r10,r10,8,63
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFFFF;
	// lbz r4,2(r11)
	ctx.r4.u64 = PPC_LOAD_U8(ctx.r11.u32 + 2);
	// lbz r6,3(r11)
	ctx.r6.u64 = PPC_LOAD_U8(ctx.r11.u32 + 3);
	// add r10,r10,r9
	ctx.r10.u64 = ctx.r10.u64 + ctx.r9.u64;
	// lbz r7,4(r11)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r11.u32 + 4);
	// lbz r8,5(r11)
	ctx.r8.u64 = PPC_LOAD_U8(ctx.r11.u32 + 5);
	// rldicr r5,r10,8,55
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r10.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// lwz r10,8(r31)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r31.u32 + 8);
	// stw r3,12(r31)
	PPC_STORE_U32(ctx.r31.u32 + 12, ctx.r3.u32);
	// add r5,r5,r4
	ctx.r5.u64 = ctx.r5.u64 + ctx.r4.u64;
	// ld r9,0(r31)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// neg r4,r10
	ctx.r4.s64 = static_cast<int64_t>(-ctx.r10.u64);
	// rldicr r11,r5,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r5.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// extsw r3,r4
	ctx.r3.s64 = ctx.r4.s32;
	// add r11,r11,r6
	ctx.r11.u64 = ctx.r11.u64 + ctx.r6.u64;
	// addi r10,r10,48
	ctx.r10.s64 = ctx.r10.s64 + 48;
	// rldicr r11,r11,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// stw r10,8(r31)
	PPC_STORE_U32(ctx.r31.u32 + 8, ctx.r10.u32);
	// add r7,r11,r7
	ctx.r7.u64 = ctx.r11.u64 + ctx.r7.u64;
	// rldicr r11,r7,8,55
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r7.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// add r11,r11,r8
	ctx.r11.u64 = ctx.r11.u64 + ctx.r8.u64;
	// sld r11,r11,r3
	ctx.r11.u64 = ctx.r3.u8 & 0x40 ? 0 : (ctx.r11.u64 << (ctx.r3.u8 & 0x7F));
	// add r6,r11,r9
	ctx.r6.u64 = ctx.r11.u64 + ctx.r9.u64;
	// std r6,0(r31)
	PPC_STORE_U64(ctx.r31.u32 + 0, ctx.r6.u64);
loc_82B773B0:
	// srawi r30,r30,4
	ctx.xer.ca = (ctx.r30.s32 < 0) & ((ctx.r30.u32 & 0xF) != 0);
	ctx.r30.s64 = ctx.r30.s32 >> 4;
	// b 0x82b773f4
	goto loc_82B773F4;
loc_82B773B8:
	// li r4,6
	ctx.r4.s64 = 6;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// bl 0x829dd208
	ctx.lr = 0x82B773C4;
	sub_829DD208(ctx, base);
loc_82B773C4:
	// ld r11,0(r31)
	ctx.r11.u64 = PPC_LOAD_U64(ctx.r31.u32 + 0);
	// li r4,1
	ctx.r4.s64 = 1;
	// mr r3,r31
	ctx.r3.u64 = ctx.r31.u64;
	// rldicl r11,r11,1,63
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r11.u64, 1) & 0x1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// bl 0x829dd208
	ctx.lr = 0x82B773DC;
	sub_829DD208(ctx, base);
	// add r10,r30,r27
	ctx.r10.u64 = ctx.r30.u64 + ctx.r27.u64;
	// rlwinm r9,r10,1,0,30
	ctx.r9.u64 = __builtin_rotateleft64(ctx.r10.u32 | (ctx.r10.u64 << 32), 1) & 0xFFFFFFFE;
	// lhzx r8,r9,r29
	ctx.r8.u64 = PPC_LOAD_U16(ctx.r9.u32 + ctx.r29.u32);
	// extsh r30,r8
	ctx.r30.s64 = ctx.r8.s16;
	// cmpwi cr6,r30,0
	ctx.cr6.compare<int32_t>(ctx.r30.s32, 0, ctx.xer);
	// blt cr6,0x82b773c4
	if (ctx.cr6.lt) goto loc_82B773C4;
loc_82B773F4:
	// lwz r10,0(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 0);
	// addi r11,r30,1
	ctx.r11.s64 = ctx.r30.s64 + 1;
	// lwz r9,20(r10)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r10.u32 + 20);
	// cmpwi cr6,r9,0
	ctx.cr6.compare<int32_t>(ctx.r9.s32, 0, ctx.xer);
	// bne cr6,0x82b775f0
	if (!ctx.cr6.eq) goto loc_82B775F0;
loc_82B77408:
	// rlwinm r10,r25,4,0,27
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r25.u32 | (ctx.r25.u64 << 32), 4) & 0xFFFFFFF0;
	// lwz r17,372(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// add r9,r11,r18
	ctx.r9.u64 = ctx.r11.u64 + ctx.r18.u64;
	// lwz r27,0(r22)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r22.u32 + 0);
	// extsw r8,r10
	ctx.r8.s64 = ctx.r10.s32;
	// extsw r7,r11
	ctx.r7.s64 = ctx.r11.s32;
	// add r6,r25,r18
	ctx.r6.u64 = ctx.r25.u64 + ctx.r18.u64;
	// or r5,r8,r7
	ctx.r5.u64 = ctx.r8.u64 | ctx.r7.u64;
	// lwz r28,24(r17)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r17.u32 + 24);
	// lbz r29,320(r9)
	ctx.r29.u64 = PPC_LOAD_U8(ctx.r9.u32 + 320);
	// li r31,0
	ctx.r31.s64 = 0;
	// lwz r30,20(r17)
	ctx.r30.u64 = PPC_LOAD_U32(ctx.r17.u32 + 20);
	// or r24,r5,r24
	ctx.r24.u64 = ctx.r5.u64 | ctx.r24.u64;
	// cmpwi cr6,r29,0
	ctx.cr6.compare<int32_t>(ctx.r29.s32, 0, ctx.xer);
	// lbz r26,160(r6)
	ctx.r26.u64 = PPC_LOAD_U8(ctx.r6.u32 + 160);
	// ble cr6,0x82b77474
	if (!ctx.cr6.gt) goto loc_82B77474;
loc_82B77448:
	// mr r6,r30
	ctx.r6.u64 = ctx.r30.u64;
	// mr r5,r26
	ctx.r5.u64 = ctx.r26.u64;
	// mr r4,r27
	ctx.r4.u64 = ctx.r27.u64;
	// mr r3,r18
	ctx.r3.u64 = ctx.r18.u64;
	// bl 0x82b354c8
	ctx.lr = 0x82B7745C;
	sub_82B354C8(ctx, base);
	// stbx r3,r31,r28
	PPC_STORE_U8(ctx.r31.u32 + ctx.r28.u32, ctx.r3.u8);
	// rlwinm r11,r3,1,24,30
	ctx.r11.u64 = __builtin_rotateleft64(ctx.r3.u32 | (ctx.r3.u64 << 32), 1) & 0xFE;
	// addi r31,r31,1
	ctx.r31.s64 = ctx.r31.s64 + 1;
	// add r30,r11,r30
	ctx.r30.u64 = ctx.r11.u64 + ctx.r30.u64;
	// cmpw cr6,r31,r29
	ctx.cr6.compare<int32_t>(ctx.r31.s32, ctx.r29.s32, ctx.xer);
	// blt cr6,0x82b77448
	if (ctx.cr6.lt) goto loc_82B77448;
loc_82B77474:
	// cmpwi cr6,r30,-1
	ctx.cr6.compare<int32_t>(ctx.r30.s32, -1, ctx.xer);
	// beq cr6,0x82b775f0
	if (ctx.cr6.eq) goto loc_82B775F0;
	// lwz r11,24(r17)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r17.u32 + 24);
	// lis r10,0
	ctx.r10.s64 = 0;
	// stw r30,20(r17)
	PPC_STORE_U32(ctx.r17.u32 + 20, ctx.r30.u32);
	// add r9,r11,r29
	ctx.r9.u64 = ctx.r11.u64 + ctx.r29.u64;
	// lwz r26,84(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// ori r27,r10,32768
	ctx.r27.u64 = ctx.r10.u64 | 32768;
	// stw r9,24(r17)
	PPC_STORE_U32(ctx.r17.u32 + 24, ctx.r9.u32);
	// lwz r17,372(r1)
	ctx.r17.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
loc_82B7749C:
	// li r28,0
	ctx.r28.s64 = 0;
loc_82B774A0:
	// addi r21,r21,1
	ctx.r21.s64 = ctx.r21.s64 + 1;
	// rlwinm r20,r20,31,25,31
	ctx.r20.u64 = __builtin_rotateleft64(ctx.r20.u32 | (ctx.r20.u64 << 32), 31) & 0x7F;
	// rldicr r24,r24,8,55
	ctx.r24.u64 = __builtin_rotateleft64(ctx.r24.u64, 8) & 0xFFFFFFFFFFFFFF00;
	// cmpwi cr6,r21,6
	ctx.cr6.compare<int32_t>(ctx.r21.s32, 6, ctx.xer);
	// blt cr6,0x82b770a4
	if (ctx.cr6.lt) goto loc_82B770A4;
	// lwz r11,0(r26)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r26.u32 + 0);
	// rldicl r10,r24,56,8
	ctx.r10.u64 = __builtin_rotateleft64(ctx.r24.u64, 56) & 0xFFFFFFFFFFFFFF;
	// lbz r9,4(r26)
	ctx.r9.u64 = PPC_LOAD_U8(ctx.r26.u32 + 4);
	// rlwinm r8,r11,0,24,24
	ctx.r8.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 0) & 0x80;
	// lbz r7,5(r26)
	ctx.r7.u64 = PPC_LOAD_U8(ctx.r26.u32 + 5);
	// rlwinm r6,r11,1,23,25
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 1) & 0x1C0;
	// lwz r5,4(r17)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r17.u32 + 4);
	// or r4,r8,r9
	ctx.r4.u64 = ctx.r8.u64 | ctx.r9.u64;
	// lwz r3,1312(r18)
	ctx.r3.u64 = PPC_LOAD_U32(ctx.r18.u32 + 1312);
	// or r7,r6,r7
	ctx.r7.u64 = ctx.r6.u64 | ctx.r7.u64;
	// lwz r9,84(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 84);
	// mr r6,r4
	ctx.r6.u64 = ctx.r4.u64;
	// lwz r8,372(r1)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// clrlwi r4,r7,24
	ctx.r4.u64 = ctx.r7.u32 & 0xFF;
	// rlwinm r7,r6,8,16,23
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r6.u32 | (ctx.r6.u64 << 32), 8) & 0xFF00;
	// rldicr r6,r11,0,32
	ctx.r6.u64 = __builtin_rotateleft64(ctx.r11.u64, 0) & 0xFFFFFFFF80000000;
	// or r4,r7,r4
	ctx.r4.u64 = ctx.r7.u64 | ctx.r4.u64;
	// rlwinm r7,r5,3,0,28
	ctx.r7.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 3) & 0xFFFFFFF8;
	// rldimi r6,r4,32,0
	ctx.r6.u64 = (__builtin_rotateleft64(ctx.r4.u64, 32) & 0xFFFFFFFF00000000) | (ctx.r6.u64 & 0xFFFFFFFF);
	// rlwinm r5,r11,27,29,31
	ctx.r5.u64 = __builtin_rotateleft64(ctx.r11.u32 | (ctx.r11.u64 << 32), 27) & 0x7;
	// rldicr r4,r6,16,47
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r6.u64, 16) & 0xFFFFFFFFFFFF0000;
	// or r11,r4,r10
	ctx.r11.u64 = ctx.r4.u64 | ctx.r10.u64;
	// stdx r11,r7,r3
	PPC_STORE_U64(ctx.r7.u32 + ctx.r3.u32, ctx.r11.u64);
loc_82B77510:
	// addi r6,r9,24
	ctx.r6.s64 = ctx.r9.s64 + 24;
	// lhz r10,18(r8)
	ctx.r10.u64 = PPC_LOAD_U16(ctx.r8.u32 + 18);
	// lwz r11,0(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 0);
	// li r17,1
	ctx.r17.s64 = 1;
	// stw r6,84(r1)
	PPC_STORE_U32(ctx.r1.u32 + 84, ctx.r6.u32);
	// addi r5,r10,2
	ctx.r5.s64 = ctx.r10.s64 + 2;
	// lwz r4,92(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 92);
	// addi r3,r11,2
	ctx.r3.s64 = ctx.r11.s64 + 2;
	// lwz r9,4(r8)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r8.u32 + 4);
	// addi r7,r4,1
	ctx.r7.s64 = ctx.r4.s64 + 1;
	// lwz r10,8(r8)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r8.u32 + 8);
	// lwz r11,12(r8)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r8.u32 + 12);
	// addi r9,r9,1
	ctx.r9.s64 = ctx.r9.s64 + 1;
	// lwz r4,100(r1)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r1.u32 + 100);
	// addi r10,r10,16
	ctx.r10.s64 = ctx.r10.s64 + 16;
	// lwz r31,112(r1)
	ctx.r31.u64 = PPC_LOAD_U32(ctx.r1.u32 + 112);
	// addi r11,r11,8
	ctx.r11.s64 = ctx.r11.s64 + 8;
	// addi r4,r4,1
	ctx.r4.s64 = ctx.r4.s64 + 1;
	// lwz r16,116(r1)
	ctx.r16.u64 = PPC_LOAD_U32(ctx.r1.u32 + 116);
	// lwz r14,96(r1)
	ctx.r14.u64 = PPC_LOAD_U32(ctx.r1.u32 + 96);
	// cmpw cr6,r7,r31
	ctx.cr6.compare<int32_t>(ctx.r7.s32, ctx.r31.s32, ctx.xer);
	// stw r7,92(r1)
	PPC_STORE_U32(ctx.r1.u32 + 92, ctx.r7.u32);
	// stw r3,0(r8)
	PPC_STORE_U32(ctx.r8.u32 + 0, ctx.r3.u32);
	// stw r9,4(r8)
	PPC_STORE_U32(ctx.r8.u32 + 4, ctx.r9.u32);
	// sth r5,18(r8)
	PPC_STORE_U16(ctx.r8.u32 + 18, ctx.r5.u16);
	// stw r10,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r10.u32);
	// stw r4,100(r1)
	PPC_STORE_U32(ctx.r1.u32 + 100, ctx.r4.u32);
	// stw r11,12(r8)
	PPC_STORE_U32(ctx.r8.u32 + 12, ctx.r11.u32);
	// lwz r15,356(r1)
	ctx.r15.u64 = PPC_LOAD_U32(ctx.r1.u32 + 356);
	// blt cr6,0x82b74e04
	if (ctx.cr6.lt) goto loc_82B74E04;
	// lwz r27,120(r1)
	ctx.r27.u64 = PPC_LOAD_U32(ctx.r1.u32 + 120);
	// lwz r28,124(r1)
	ctx.r28.u64 = PPC_LOAD_U32(ctx.r1.u32 + 124);
	// lwz r26,136(r1)
	ctx.r26.u64 = PPC_LOAD_U32(ctx.r1.u32 + 136);
loc_82B77594:
	// lwz r9,372(r1)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// addi r14,r14,1
	ctx.r14.s64 = ctx.r14.s64 + 1;
	// stw r14,96(r1)
	PPC_STORE_U32(ctx.r1.u32 + 96, ctx.r14.u32);
	// cmpw cr6,r14,r26
	ctx.cr6.compare<int32_t>(ctx.r14.s32, ctx.r26.s32, ctx.xer);
	// lhz r11,16(r9)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r9.u32 + 16);
	// lwz r10,0(r9)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r9.u32 + 0);
	// addi r11,r11,2
	ctx.r11.s64 = ctx.r11.s64 + 2;
	// sth r11,16(r9)
	PPC_STORE_U16(ctx.r9.u32 + 16, ctx.r11.u16);
	// lhz r11,50(r18)
	ctx.r11.u64 = PPC_LOAD_U16(ctx.r18.u32 + 50);
	// add r7,r11,r10
	ctx.r7.u64 = ctx.r11.u64 + ctx.r10.u64;
	// stw r7,0(r9)
	PPC_STORE_U32(ctx.r9.u32 + 0, ctx.r7.u32);
	// lhz r6,76(r18)
	ctx.r6.u64 = PPC_LOAD_U16(ctx.r18.u32 + 76);
	// lhz r5,74(r18)
	ctx.r5.u64 = PPC_LOAD_U16(ctx.r18.u32 + 74);
	// rotlwi r11,r6,3
	ctx.r11.u64 = __builtin_rotateleft32(ctx.r6.u32, 3);
	// rotlwi r10,r5,4
	ctx.r10.u64 = __builtin_rotateleft32(ctx.r5.u32, 4);
	// add r27,r11,r27
	ctx.r27.u64 = ctx.r11.u64 + ctx.r27.u64;
	// add r28,r10,r28
	ctx.r28.u64 = ctx.r10.u64 + ctx.r28.u64;
	// stw r27,120(r1)
	PPC_STORE_U32(ctx.r1.u32 + 120, ctx.r27.u32);
	// stw r28,124(r1)
	PPC_STORE_U32(ctx.r1.u32 + 124, ctx.r28.u32);
	// bge cr6,0x82b775fc
	if (!ctx.cr6.lt) goto loc_82B775FC;
	// rotlwi r31,r9,0
	ctx.r31.u64 = __builtin_rotateleft32(ctx.r9.u32, 0);
	// li r25,0
	ctx.r25.s64 = 0;
	// b 0x82b74bd8
	goto loc_82B74BD8;
loc_82B775F0:
	// li r3,4
	ctx.r3.s64 = 4;
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x82ae1640
	__restgprlr_14(ctx, base);
	return;
loc_82B775FC:
	// lwz r11,372(r1)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r1.u32 + 372);
	// lis r10,1
	ctx.r10.s64 = 65536;
	// lwz r9,22504(r15)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r15.u32 + 22504);
	// li r8,-1
	ctx.r8.s64 = -1;
	// ori r7,r10,39772
	ctx.r7.u64 = ctx.r10.u64 | 39772;
	// li r3,0
	ctx.r3.s64 = 0;
	// lwz r6,32(r11)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// subf r5,r9,r6
	ctx.r5.u64 = ctx.r6.u64 - ctx.r9.u64;
	// rlwinm r4,r5,30,2,31
	ctx.r4.u64 = __builtin_rotateleft64(ctx.r5.u32 | (ctx.r5.u64 << 32), 30) & 0x3FFFFFFF;
	// stwx r4,r15,r7
	PPC_STORE_U32(ctx.r15.u32 + ctx.r7.u32, ctx.r4.u32);
	// lwz r11,32(r11)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r11.u32 + 32);
	// stw r8,0(r11)
	PPC_STORE_U32(ctx.r11.u32 + 0, ctx.r8.u32);
	// lwz r10,84(r15)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// ld r9,104(r18)
	ctx.r9.u64 = PPC_LOAD_U64(ctx.r18.u32 + 104);
	// std r9,0(r10)
	PPC_STORE_U64(ctx.r10.u32 + 0, ctx.r9.u64);
	// lwz r8,84(r15)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r7,112(r18)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r18.u32 + 112);
	// stw r7,8(r8)
	PPC_STORE_U32(ctx.r8.u32 + 8, ctx.r7.u32);
	// lwz r5,84(r15)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r6,116(r18)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r18.u32 + 116);
	// stw r6,12(r5)
	PPC_STORE_U32(ctx.r5.u32 + 12, ctx.r6.u32);
	// lwz r11,120(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 120);
	// lwz r4,84(r15)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// stw r11,16(r4)
	PPC_STORE_U32(ctx.r4.u32 + 16, ctx.r11.u32);
	// lwz r10,124(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 124);
	// lwz r9,84(r15)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// stw r10,20(r9)
	PPC_STORE_U32(ctx.r9.u32 + 20, ctx.r10.u32);
	// lwz r8,84(r15)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r7,128(r18)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r18.u32 + 128);
	// stw r7,24(r8)
	PPC_STORE_U32(ctx.r8.u32 + 24, ctx.r7.u32);
	// lwz r5,84(r15)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r6,132(r18)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r18.u32 + 132);
	// stw r6,28(r5)
	PPC_STORE_U32(ctx.r5.u32 + 28, ctx.r6.u32);
	// lwz r4,84(r15)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r11,136(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 136);
	// stw r11,32(r4)
	PPC_STORE_U32(ctx.r4.u32 + 32, ctx.r11.u32);
	// lwz r9,84(r15)
	ctx.r9.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r10,140(r18)
	ctx.r10.u64 = PPC_LOAD_U32(ctx.r18.u32 + 140);
	// stw r10,36(r9)
	PPC_STORE_U32(ctx.r9.u32 + 36, ctx.r10.u32);
	// lwz r7,144(r18)
	ctx.r7.u64 = PPC_LOAD_U32(ctx.r18.u32 + 144);
	// lwz r8,84(r15)
	ctx.r8.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// stw r7,40(r8)
	PPC_STORE_U32(ctx.r8.u32 + 40, ctx.r7.u32);
	// lwz r6,84(r15)
	ctx.r6.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r5,148(r18)
	ctx.r5.u64 = PPC_LOAD_U32(ctx.r18.u32 + 148);
	// stw r5,44(r6)
	PPC_STORE_U32(ctx.r6.u32 + 44, ctx.r5.u32);
	// lwz r4,84(r15)
	ctx.r4.u64 = PPC_LOAD_U32(ctx.r15.u32 + 84);
	// lwz r11,152(r18)
	ctx.r11.u64 = PPC_LOAD_U32(ctx.r18.u32 + 152);
	// stw r11,48(r4)
	PPC_STORE_U32(ctx.r4.u32 + 48, ctx.r11.u32);
loc_82B776BC:
	// addi r1,r1,336
	ctx.r1.s64 = ctx.r1.s64 + 336;
	// b 0x82ae1640
	__restgprlr_14(ctx, base);
	return;
}

