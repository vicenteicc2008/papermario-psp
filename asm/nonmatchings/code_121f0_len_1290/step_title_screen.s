.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel step_title_screen
/* 124B4 800370B4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 124B8 800370B8 AFB00018 */  sw        $s0, 0x18($sp)
/* 124BC 800370BC 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 124C0 800370C0 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 124C4 800370C4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 124C8 800370C8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 124CC 800370CC 8E020000 */  lw        $v0, ($s0)
/* 124D0 800370D0 3C013F80 */  lui       $at, 0x3f80
/* 124D4 800370D4 44816000 */  mtc1      $at, $f12
/* 124D8 800370D8 0C00AFBB */  jal       set_curtain_scale
/* 124DC 800370DC 8C510010 */   lw       $s1, 0x10($v0)
/* 124E0 800370E0 44806000 */  mtc1      $zero, $f12
/* 124E4 800370E4 0C00AFC9 */  jal       set_curtain_fade
/* 124E8 800370E8 00000000 */   nop
/* 124EC 800370EC 3C04800A */  lui       $a0, %hi(D_800A0988)
/* 124F0 800370F0 24840988 */  addiu     $a0, $a0, %lo(D_800A0988)
/* 124F4 800370F4 84820000 */  lh        $v0, ($a0)
/* 124F8 800370F8 94830000 */  lhu       $v1, ($a0)
/* 124FC 800370FC 18400002 */  blez      $v0, .L80037108
/* 12500 80037100 2462FFFF */   addiu    $v0, $v1, -1
/* 12504 80037104 A4820000 */  sh        $v0, ($a0)
.L80037108:
/* 12508 80037108 8E020000 */  lw        $v0, ($s0)
/* 1250C 8003710C 804300AC */  lb        $v1, 0xac($v0)
/* 12510 80037110 2C620007 */  sltiu     $v0, $v1, 7
/* 12514 80037114 10400115 */  beqz      $v0, .L8003756C
/* 12518 80037118 00031080 */   sll      $v0, $v1, 2
/* 1251C 8003711C 3C01800A */  lui       $at, %hi(jtbl_800983A8_737A8)
/* 12520 80037120 00220821 */  addu      $at, $at, $v0
/* 12524 80037124 8C2283A8 */  lw        $v0, %lo(jtbl_800983A8_737A8)($at)
/* 12528 80037128 00400008 */  jr        $v0
/* 1252C 8003712C 00000000 */   nop
glabel L80037130_12530
/* 12530 80037130 3C04800A */  lui       $a0, %hi(D_8009A650)
/* 12534 80037134 2484A650 */  addiu     $a0, $a0, %lo(D_8009A650)
/* 12538 80037138 8C820000 */  lw        $v0, ($a0)
/* 1253C 8003713C 24030003 */  addiu     $v1, $zero, 3
/* 12540 80037140 3C01800A */  lui       $at, %hi(D_800A0970)
/* 12544 80037144 A4230970 */  sh        $v1, %lo(D_800A0970)($at)
/* 12548 80037148 34420008 */  ori       $v0, $v0, 8
/* 1254C 8003714C AC820000 */  sw        $v0, ($a0)
/* 12550 80037150 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* 12554 80037154 2484419C */  addiu     $a0, $a0, %lo(gGameStatusPtr)
/* 12558 80037158 8C830000 */  lw        $v1, ($a0)
/* 1255C 8003715C 24020014 */  addiu     $v0, $zero, 0x14
/* 12560 80037160 A06200B0 */  sb        $v0, 0xb0($v1)
/* 12564 80037164 8C830000 */  lw        $v1, ($a0)
/* 12568 80037168 906200B0 */  lbu       $v0, 0xb0($v1)
/* 1256C 8003716C A06200AF */  sb        $v0, 0xaf($v1)
/* 12570 80037170 8C830000 */  lw        $v1, ($a0)
/* 12574 80037174 906200AC */  lbu       $v0, 0xac($v1)
/* 12578 80037178 24420001 */  addiu     $v0, $v0, 1
/* 1257C 8003717C 0800DD5B */  j         .L8003756C
/* 12580 80037180 A06200AC */   sb       $v0, 0xac($v1)
glabel L80037184_12584
/* 12584 80037184 3C04800A */  lui       $a0, %hi(D_800A0970)
/* 12588 80037188 24840970 */  addiu     $a0, $a0, %lo(D_800A0970)
/* 1258C 8003718C 84820000 */  lh        $v0, ($a0)
/* 12590 80037190 94830000 */  lhu       $v1, ($a0)
/* 12594 80037194 10400003 */  beqz      $v0, .L800371A4
/* 12598 80037198 2462FFFF */   addiu    $v0, $v1, -1
/* 1259C 8003719C 0800DD5B */  j         .L8003756C
/* 125A0 800371A0 A4820000 */   sh       $v0, ($a0)
.L800371A4:
/* 125A4 800371A4 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 125A8 800371A8 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 125AC 800371AC 8E040000 */  lw        $a0, ($s0)
/* 125B0 800371B0 808200AF */  lb        $v0, 0xaf($a0)
/* 125B4 800371B4 908300AF */  lbu       $v1, 0xaf($a0)
/* 125B8 800371B8 10400002 */  beqz      $v0, .L800371C4
/* 125BC 800371BC 2462FFFF */   addiu    $v0, $v1, -1
/* 125C0 800371C0 A08200AF */  sb        $v0, 0xaf($a0)
.L800371C4:
/* 125C4 800371C4 24040006 */  addiu     $a0, $zero, 6
/* 125C8 800371C8 3C02800A */  lui       $v0, %hi(D_8009A650)
/* 125CC 800371CC 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* 125D0 800371D0 8C430000 */  lw        $v1, ($v0)
/* 125D4 800371D4 2405FFF7 */  addiu     $a1, $zero, -9
/* 125D8 800371D8 00651824 */  and       $v1, $v1, $a1
/* 125DC 800371DC 0C00CDFE */  jal       intro_logos_fade_in
/* 125E0 800371E0 AC430000 */   sw       $v1, ($v0)
/* 125E4 800371E4 10400074 */  beqz      $v0, .L800373B8
/* 125E8 800371E8 00000000 */   nop
/* 125EC 800371EC 8E030000 */  lw        $v1, ($s0)
/* 125F0 800371F0 806200AF */  lb        $v0, 0xaf($v1)
/* 125F4 800371F4 14400070 */  bnez      $v0, .L800373B8
/* 125F8 800371F8 24020002 */   addiu    $v0, $zero, 2
/* 125FC 800371FC 0800DCEE */  j         .L800373B8
/* 12600 80037200 A06200AC */   sb       $v0, 0xac($v1)
glabel L80037204_12604
/* 12604 80037204 3C028007 */  lui       $v0, %hi(D_80077A34)
/* 12608 80037208 8C427A34 */  lw        $v0, %lo(D_80077A34)($v0)
/* 1260C 8003720C 1040000B */  beqz      $v0, .L8003723C
/* 12610 80037210 24020078 */   addiu    $v0, $zero, 0x78
/* 12614 80037214 3C03800A */  lui       $v1, %hi(D_800A0988)
/* 12618 80037218 84630988 */  lh        $v1, %lo(D_800A0988)($v1)
/* 1261C 8003721C 14620007 */  bne       $v1, $v0, .L8003723C
/* 12620 80037220 24020008 */   addiu    $v0, $zero, 8
/* 12624 80037224 AFA20010 */  sw        $v0, 0x10($sp)
/* 12628 80037228 0000202D */  daddu     $a0, $zero, $zero
/* 1262C 8003722C 2405FFFF */  addiu     $a1, $zero, -1
/* 12630 80037230 0080302D */  daddu     $a2, $a0, $zero
/* 12634 80037234 0C052A46 */  jal       set_music_track
/* 12638 80037238 24070F3C */   addiu    $a3, $zero, 0xf3c
.L8003723C:
/* 1263C 8003723C 3C02800A */  lui       $v0, %hi(D_800A0988)
/* 12640 80037240 84420988 */  lh        $v0, %lo(D_800A0988)($v0)
/* 12644 80037244 14400012 */  bnez      $v0, .L80037290
/* 12648 80037248 32229000 */   andi     $v0, $s1, 0x9000
/* 1264C 8003724C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 12650 80037250 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 12654 80037254 24030004 */  addiu     $v1, $zero, 4
/* 12658 80037258 A04300AC */  sb        $v1, 0xac($v0)
/* 1265C 8003725C 3C028007 */  lui       $v0, %hi(D_80077A34)
/* 12660 80037260 8C427A34 */  lw        $v0, %lo(D_80077A34)($v0)
/* 12664 80037264 14400002 */  bnez      $v0, .L80037270
/* 12668 80037268 24020009 */   addiu    $v0, $zero, 9
/* 1266C 8003726C 2402000A */  addiu     $v0, $zero, 0xa
.L80037270:
/* 12670 80037270 3C018007 */  lui       $at, %hi(D_800779C0)
/* 12674 80037274 A42279C0 */  sh        $v0, %lo(D_800779C0)($at)
/* 12678 80037278 3C038007 */  lui       $v1, %hi(D_80077A34)
/* 1267C 8003727C 24637A34 */  addiu     $v1, $v1, %lo(D_80077A34)
/* 12680 80037280 8C620000 */  lw        $v0, ($v1)
/* 12684 80037284 38420001 */  xori      $v0, $v0, 1
/* 12688 80037288 0800DD64 */  j         .L80037590
/* 1268C 8003728C AC620000 */   sw       $v0, ($v1)
.L80037290:
/* 12690 80037290 104000B6 */  beqz      $v0, .L8003756C
/* 12694 80037294 24020004 */   addiu    $v0, $zero, 4
/* 12698 80037298 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 1269C 8003729C 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 126A0 800372A0 A06200AC */  sb        $v0, 0xac($v1)
/* 126A4 800372A4 24020005 */  addiu     $v0, $zero, 5
/* 126A8 800372A8 3C018007 */  lui       $at, %hi(D_800779C0)
/* 126AC 800372AC A42279C0 */  sh        $v0, %lo(D_800779C0)($at)
/* 126B0 800372B0 0C05272D */  jal       play_sound
/* 126B4 800372B4 240400D5 */   addiu    $a0, $zero, 0xd5
/* 126B8 800372B8 0000202D */  daddu     $a0, $zero, $zero
/* 126BC 800372BC 24050069 */  addiu     $a1, $zero, 0x69
/* 126C0 800372C0 0080302D */  daddu     $a2, $a0, $zero
/* 126C4 800372C4 240701F4 */  addiu     $a3, $zero, 0x1f4
/* 126C8 800372C8 24020008 */  addiu     $v0, $zero, 8
/* 126CC 800372CC 0C052A46 */  jal       set_music_track
/* 126D0 800372D0 AFA20010 */   sw       $v0, 0x10($sp)
/* 126D4 800372D4 0800DD64 */  j         .L80037590
/* 126D8 800372D8 00000000 */   nop
glabel L800372DC_126DC
/* 126DC 800372DC 240400D0 */  addiu     $a0, $zero, 0xd0
/* 126E0 800372E0 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 126E4 800372E4 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 126E8 800372E8 8E030000 */  lw        $v1, ($s0)
/* 126EC 800372EC 24020005 */  addiu     $v0, $zero, 5
/* 126F0 800372F0 0C00CDF8 */  jal       intro_logos_set_fade_color
/* 126F4 800372F4 A06200AC */   sb       $v0, 0xac($v1)
/* 126F8 800372F8 3C028007 */  lui       $v0, %hi(D_800779C0)
/* 126FC 800372FC 944279C0 */  lhu       $v0, %lo(D_800779C0)($v0)
/* 12700 80037300 2442FFF7 */  addiu     $v0, $v0, -9
/* 12704 80037304 2C420002 */  sltiu     $v0, $v0, 2
/* 12708 80037308 10400004 */  beqz      $v0, .L8003731C
/* 1270C 8003730C 24020014 */   addiu    $v0, $zero, 0x14
/* 12710 80037310 8E030000 */  lw        $v1, ($s0)
/* 12714 80037314 0800DCCA */  j         .L80037328
/* 12718 80037318 A06200B0 */   sb       $v0, 0xb0($v1)
.L8003731C:
/* 1271C 8003731C 8E030000 */  lw        $v1, ($s0)
/* 12720 80037320 2402000A */  addiu     $v0, $zero, 0xa
/* 12724 80037324 A06200B0 */  sb        $v0, 0xb0($v1)
.L80037328:
/* 12728 80037328 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 1272C 8003732C 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 12730 80037330 906200B0 */  lbu       $v0, 0xb0($v1)
/* 12734 80037334 0800DD5B */  j         .L8003756C
/* 12738 80037338 A06200AF */   sb       $v0, 0xaf($v1)
glabel L8003733C_1273C
/* 1273C 8003733C 3C038007 */  lui       $v1, %hi(D_800779C0)
/* 12740 80037340 946379C0 */  lhu       $v1, %lo(D_800779C0)($v1)
/* 12744 80037344 2462FFF7 */  addiu     $v0, $v1, -9
/* 12748 80037348 2C420002 */  sltiu     $v0, $v0, 2
/* 1274C 8003734C 1040001E */  beqz      $v0, .L800373C8
/* 12750 80037350 00031400 */   sll      $v0, $v1, 0x10
/* 12754 80037354 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 12758 80037358 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 1275C 8003735C 8E040000 */  lw        $a0, ($s0)
/* 12760 80037360 808200AF */  lb        $v0, 0xaf($a0)
/* 12764 80037364 908300AF */  lbu       $v1, 0xaf($a0)
/* 12768 80037368 10400002 */  beqz      $v0, .L80037374
/* 1276C 8003736C 2462FFFF */   addiu    $v0, $v1, -1
/* 12770 80037370 A08200AF */  sb        $v0, 0xaf($a0)
.L80037374:
/* 12774 80037374 0C00CE0C */  jal       intro_logos_fade_out
/* 12778 80037378 2404000A */   addiu    $a0, $zero, 0xa
/* 1277C 8003737C 1040000E */  beqz      $v0, .L800373B8
/* 12780 80037380 00000000 */   nop
/* 12784 80037384 8E030000 */  lw        $v1, ($s0)
/* 12788 80037388 806200AF */  lb        $v0, 0xaf($v1)
/* 1278C 8003738C 1440000A */  bnez      $v0, .L800373B8
/* 12790 80037390 24020003 */   addiu    $v0, $zero, 3
/* 12794 80037394 A06200AF */  sb        $v0, 0xaf($v1)
/* 12798 80037398 3C03800A */  lui       $v1, %hi(D_8009A650)
/* 1279C 8003739C 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* 127A0 800373A0 8C620000 */  lw        $v0, ($v1)
/* 127A4 800373A4 34420008 */  ori       $v0, $v0, 8
/* 127A8 800373A8 AC620000 */  sw        $v0, ($v1)
/* 127AC 800373AC 8E030000 */  lw        $v1, ($s0)
/* 127B0 800373B0 24020006 */  addiu     $v0, $zero, 6
/* 127B4 800373B4 A06200AC */  sb        $v0, 0xac($v1)
.L800373B8:
/* 127B8 800373B8 0C00CE1D */  jal       intro_logos_update_fade
/* 127BC 800373BC 00000000 */   nop
/* 127C0 800373C0 0800DD5B */  j         .L8003756C
/* 127C4 800373C4 00000000 */   nop
.L800373C8:
/* 127C8 800373C8 00021403 */  sra       $v0, $v0, 0x10
/* 127CC 800373CC 24030005 */  addiu     $v1, $zero, 5
/* 127D0 800373D0 14430012 */  bne       $v0, $v1, .L8003741C
/* 127D4 800373D4 24020003 */   addiu    $v0, $zero, 3
/* 127D8 800373D8 3C058007 */  lui       $a1, %hi(gGameStatusPtr)
/* 127DC 800373DC 24A5419C */  addiu     $a1, $a1, %lo(gGameStatusPtr)
/* 127E0 800373E0 8CA40000 */  lw        $a0, ($a1)
/* 127E4 800373E4 808200AF */  lb        $v0, 0xaf($a0)
/* 127E8 800373E8 908300AF */  lbu       $v1, 0xaf($a0)
/* 127EC 800373EC 1440001F */  bnez      $v0, .L8003746C
/* 127F0 800373F0 2462FFFF */   addiu    $v0, $v1, -1
/* 127F4 800373F4 24020003 */  addiu     $v0, $zero, 3
/* 127F8 800373F8 3C03800A */  lui       $v1, %hi(D_8009A650)
/* 127FC 800373FC 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* 12800 80037400 A08200AF */  sb        $v0, 0xaf($a0)
/* 12804 80037404 8C620000 */  lw        $v0, ($v1)
/* 12808 80037408 34420008 */  ori       $v0, $v0, 8
/* 1280C 8003740C AC620000 */  sw        $v0, ($v1)
/* 12810 80037410 8CA30000 */  lw        $v1, ($a1)
/* 12814 80037414 0800DD12 */  j         .L80037448
/* 12818 80037418 24020006 */   addiu    $v0, $zero, 6
.L8003741C:
/* 1281C 8003741C 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* 12820 80037420 2484419C */  addiu     $a0, $a0, %lo(gGameStatusPtr)
/* 12824 80037424 8C830000 */  lw        $v1, ($a0)
/* 12828 80037428 A06200AF */  sb        $v0, 0xaf($v1)
/* 1282C 8003742C 3C03800A */  lui       $v1, %hi(D_8009A650)
/* 12830 80037430 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* 12834 80037434 8C620000 */  lw        $v0, ($v1)
/* 12838 80037438 34420008 */  ori       $v0, $v0, 8
/* 1283C 8003743C AC620000 */  sw        $v0, ($v1)
/* 12840 80037440 8C830000 */  lw        $v1, ($a0)
/* 12844 80037444 24020006 */  addiu     $v0, $zero, 6
.L80037448:
/* 12848 80037448 0800DD5B */  j         .L8003756C
/* 1284C 8003744C A06200AC */   sb       $v0, 0xac($v1)
glabel L80037450_12850
/* 12850 80037450 3C108007 */  lui       $s0, %hi(gGameStatusPtr)
/* 12854 80037454 2610419C */  addiu     $s0, $s0, %lo(gGameStatusPtr)
/* 12858 80037458 8E040000 */  lw        $a0, ($s0)
/* 1285C 8003745C 808200AF */  lb        $v0, 0xaf($a0)
/* 12860 80037460 908300AF */  lbu       $v1, 0xaf($a0)
/* 12864 80037464 10400003 */  beqz      $v0, .L80037474
/* 12868 80037468 2462FFFF */   addiu    $v0, $v1, -1
.L8003746C:
/* 1286C 8003746C 0800DD5B */  j         .L8003756C
/* 12870 80037470 A08200AF */   sb       $v0, 0xaf($a0)
.L80037474:
/* 12874 80037474 0C00AB00 */  jal       general_heap_create
/* 12878 80037478 00000000 */   nop
/* 1287C 8003747C 0C047624 */  jal       func_8011D890
/* 12880 80037480 00000000 */   nop
/* 12884 80037484 0C00B7BD */  jal       create_cameras_a
/* 12888 80037488 00000000 */   nop
/* 1288C 8003748C 0C0482EC */  jal       clear_entity_models
/* 12890 80037490 00000000 */   nop
/* 12894 80037494 0C047889 */  jal       func_8011E224
/* 12898 80037498 00000000 */   nop
/* 1289C 8003749C 0C00E12F */  jal       clear_npcs
/* 128A0 800374A0 00000000 */   nop
/* 128A4 800374A4 0C050440 */  jal       func_80141100
/* 128A8 800374A8 00000000 */   nop
/* 128AC 800374AC 0C0B763E */  jal       func_802DD8F8
/* 128B0 800374B0 0000202D */   daddu    $a0, $zero, $zero
/* 128B4 800374B4 0C04432E */  jal       clear_entity_data
/* 128B8 800374B8 24040001 */   addiu    $a0, $zero, 1
/* 128BC 800374BC 0C051CFC */  jal       func_801473F0
/* 128C0 800374C0 00000000 */   nop
/* 128C4 800374C4 3C04800A */  lui       $a0, %hi(D_8009A650)
/* 128C8 800374C8 2484A650 */  addiu     $a0, $a0, %lo(D_8009A650)
/* 128CC 800374CC 2403FFF7 */  addiu     $v1, $zero, -9
/* 128D0 800374D0 8C820000 */  lw        $v0, ($a0)
/* 128D4 800374D4 8E050000 */  lw        $a1, ($s0)
/* 128D8 800374D8 00431024 */  and       $v0, $v0, $v1
/* 128DC 800374DC 2403FFFD */  addiu     $v1, $zero, -3
/* 128E0 800374E0 00431024 */  and       $v0, $v0, $v1
/* 128E4 800374E4 AC820000 */  sw        $v0, ($a0)
/* 128E8 800374E8 3C038007 */  lui       $v1, %hi(D_800779C0)
/* 128EC 800374EC 846379C0 */  lh        $v1, %lo(D_800779C0)($v1)
/* 128F0 800374F0 24020009 */  addiu     $v0, $zero, 9
/* 128F4 800374F4 1062000D */  beq       $v1, $v0, .L8003752C
/* 128F8 800374F8 A4A0008E */   sh       $zero, 0x8e($a1)
/* 128FC 800374FC 2862000A */  slti      $v0, $v1, 0xa
/* 12900 80037500 10400005 */  beqz      $v0, .L80037518
/* 12904 80037504 24020005 */   addiu    $v0, $zero, 5
/* 12908 80037508 10620011 */  beq       $v1, $v0, .L80037550
/* 1290C 8003750C 2404000E */   addiu    $a0, $zero, 0xe
/* 12910 80037510 0800DD64 */  j         .L80037590
/* 12914 80037514 00000000 */   nop
.L80037518:
/* 12918 80037518 2402000A */  addiu     $v0, $zero, 0xa
/* 1291C 8003751C 10620008 */  beq       $v1, $v0, .L80037540
/* 12920 80037520 00000000 */   nop
/* 12924 80037524 0800DD64 */  j         .L80037590
/* 12928 80037528 00000000 */   nop
.L8003752C:
/* 1292C 8003752C A0A000A8 */  sb        $zero, 0xa8($a1)
/* 12930 80037530 0C00CD3C */  jal       set_game_mode
/* 12934 80037534 24040010 */   addiu    $a0, $zero, 0x10
/* 12938 80037538 0800DD64 */  j         .L80037590
/* 1293C 8003753C 00000000 */   nop
.L80037540:
/* 12940 80037540 0C00CD3C */  jal       set_game_mode
/* 12944 80037544 24040011 */   addiu    $a0, $zero, 0x11
/* 12948 80037548 0800DD64 */  j         .L80037590
/* 1294C 8003754C 00000000 */   nop
.L80037550:
/* 12950 80037550 2402000B */  addiu     $v0, $zero, 0xb
/* 12954 80037554 A4A00086 */  sh        $zero, 0x86($a1)
/* 12958 80037558 A4A2008C */  sh        $v0, 0x8c($a1)
/* 1295C 8003755C 0C00CD3C */  jal       set_game_mode
/* 12960 80037560 A4A0008E */   sh       $zero, 0x8e($a1)
/* 12964 80037564 0800DD64 */  j         .L80037590
/* 12968 80037568 00000000 */   nop
.L8003756C:
glabel L8003756C_1296C
/* 1296C 8003756C 3C02800A */  lui       $v0, %hi(D_8009A650)
/* 12970 80037570 8C42A650 */  lw        $v0, %lo(D_8009A650)($v0)
/* 12974 80037574 30420008 */  andi      $v0, $v0, 8
/* 12978 80037578 14400005 */  bnez      $v0, .L80037590
/* 1297C 8003757C 00000000 */   nop
/* 12980 80037580 0C00E64C */  jal       update_npcs
/* 12984 80037584 00000000 */   nop
/* 12988 80037588 0C00B500 */  jal       update_cameras
/* 1298C 8003758C 00000000 */   nop
.L80037590:
/* 12990 80037590 8FBF0020 */  lw        $ra, 0x20($sp)
/* 12994 80037594 8FB1001C */  lw        $s1, 0x1c($sp)
/* 12998 80037598 8FB00018 */  lw        $s0, 0x18($sp)
/* 1299C 8003759C 03E00008 */  jr        $ra
/* 129A0 800375A0 27BD0028 */   addiu    $sp, $sp, 0x28
