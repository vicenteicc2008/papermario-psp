.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AA8_DC4E78
/* DC4E78 80240AA8 27BDFF98 */  addiu     $sp, $sp, -0x68
/* DC4E7C 80240AAC AFB30054 */  sw        $s3, 0x54($sp)
/* DC4E80 80240AB0 0080982D */  daddu     $s3, $a0, $zero
/* DC4E84 80240AB4 AFBF0060 */  sw        $ra, 0x60($sp)
/* DC4E88 80240AB8 AFB5005C */  sw        $s5, 0x5c($sp)
/* DC4E8C 80240ABC AFB40058 */  sw        $s4, 0x58($sp)
/* DC4E90 80240AC0 AFB20050 */  sw        $s2, 0x50($sp)
/* DC4E94 80240AC4 AFB1004C */  sw        $s1, 0x4c($sp)
/* DC4E98 80240AC8 AFB00048 */  sw        $s0, 0x48($sp)
/* DC4E9C 80240ACC 8E710148 */  lw        $s1, 0x148($s3)
/* DC4EA0 80240AD0 86240008 */  lh        $a0, 8($s1)
/* DC4EA4 80240AD4 0C00EABB */  jal       get_npc_unsafe
/* DC4EA8 80240AD8 00A0802D */   daddu    $s0, $a1, $zero
/* DC4EAC 80240ADC 8E63000C */  lw        $v1, 0xc($s3)
/* DC4EB0 80240AE0 0260202D */  daddu     $a0, $s3, $zero
/* DC4EB4 80240AE4 8C650000 */  lw        $a1, ($v1)
/* DC4EB8 80240AE8 0C0B1EAF */  jal       get_variable
/* DC4EBC 80240AEC 0040902D */   daddu    $s2, $v0, $zero
/* DC4EC0 80240AF0 AFA00018 */  sw        $zero, 0x18($sp)
/* DC4EC4 80240AF4 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DC4EC8 80240AF8 8C630030 */  lw        $v1, 0x30($v1)
/* DC4ECC 80240AFC AFA3001C */  sw        $v1, 0x1c($sp)
/* DC4ED0 80240B00 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DC4ED4 80240B04 8C63001C */  lw        $v1, 0x1c($v1)
/* DC4ED8 80240B08 AFA30020 */  sw        $v1, 0x20($sp)
/* DC4EDC 80240B0C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DC4EE0 80240B10 8C630024 */  lw        $v1, 0x24($v1)
/* DC4EE4 80240B14 AFA30024 */  sw        $v1, 0x24($sp)
/* DC4EE8 80240B18 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DC4EEC 80240B1C 8C630028 */  lw        $v1, 0x28($v1)
/* DC4EF0 80240B20 27B50018 */  addiu     $s5, $sp, 0x18
/* DC4EF4 80240B24 AFA30028 */  sw        $v1, 0x28($sp)
/* DC4EF8 80240B28 8E2300D0 */  lw        $v1, 0xd0($s1)
/* DC4EFC 80240B2C 3C014282 */  lui       $at, 0x4282
/* DC4F00 80240B30 44810000 */  mtc1      $at, $f0
/* DC4F04 80240B34 8C63002C */  lw        $v1, 0x2c($v1)
/* DC4F08 80240B38 0040A02D */  daddu     $s4, $v0, $zero
/* DC4F0C 80240B3C E7A00030 */  swc1      $f0, 0x30($sp)
/* DC4F10 80240B40 A7A00034 */  sh        $zero, 0x34($sp)
/* DC4F14 80240B44 16000005 */  bnez      $s0, .L80240B5C
/* DC4F18 80240B48 AFA3002C */   sw       $v1, 0x2c($sp)
/* DC4F1C 80240B4C 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DC4F20 80240B50 30420004 */  andi      $v0, $v0, 4
/* DC4F24 80240B54 10400044 */  beqz      $v0, .L80240C68
/* DC4F28 80240B58 00000000 */   nop
.L80240B5C:
/* DC4F2C 80240B5C 2404F7FF */  addiu     $a0, $zero, -0x801
/* DC4F30 80240B60 AE600070 */  sw        $zero, 0x70($s3)
/* DC4F34 80240B64 A640008E */  sh        $zero, 0x8e($s2)
/* DC4F38 80240B68 8E2200CC */  lw        $v0, 0xcc($s1)
/* DC4F3C 80240B6C 8E430000 */  lw        $v1, ($s2)
/* DC4F40 80240B70 8C420000 */  lw        $v0, ($v0)
/* DC4F44 80240B74 00641824 */  and       $v1, $v1, $a0
/* DC4F48 80240B78 AE430000 */  sw        $v1, ($s2)
/* DC4F4C 80240B7C AE420028 */  sw        $v0, 0x28($s2)
/* DC4F50 80240B80 8E2200D0 */  lw        $v0, 0xd0($s1)
/* DC4F54 80240B84 8C420034 */  lw        $v0, 0x34($v0)
/* DC4F58 80240B88 54400005 */  bnel      $v0, $zero, .L80240BA0
/* DC4F5C 80240B8C 2402FDFF */   addiu    $v0, $zero, -0x201
/* DC4F60 80240B90 34620200 */  ori       $v0, $v1, 0x200
/* DC4F64 80240B94 2403FFF7 */  addiu     $v1, $zero, -9
/* DC4F68 80240B98 080902EA */  j         .L80240BA8
/* DC4F6C 80240B9C 00431024 */   and      $v0, $v0, $v1
.L80240BA0:
/* DC4F70 80240BA0 00621024 */  and       $v0, $v1, $v0
/* DC4F74 80240BA4 34420008 */  ori       $v0, $v0, 8
.L80240BA8:
/* DC4F78 80240BA8 AE420000 */  sw        $v0, ($s2)
/* DC4F7C 80240BAC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DC4F80 80240BB0 30420004 */  andi      $v0, $v0, 4
/* DC4F84 80240BB4 10400004 */  beqz      $v0, .L80240BC8
/* DC4F88 80240BB8 24020063 */   addiu    $v0, $zero, 0x63
/* DC4F8C 80240BBC AE620070 */  sw        $v0, 0x70($s3)
/* DC4F90 80240BC0 080902F8 */  j         .L80240BE0
/* DC4F94 80240BC4 AE600074 */   sw       $zero, 0x74($s3)
.L80240BC8:
/* DC4F98 80240BC8 8E220000 */  lw        $v0, ($s1)
/* DC4F9C 80240BCC 3C034000 */  lui       $v1, 0x4000
/* DC4FA0 80240BD0 00431024 */  and       $v0, $v0, $v1
/* DC4FA4 80240BD4 10400002 */  beqz      $v0, .L80240BE0
/* DC4FA8 80240BD8 2402000C */   addiu    $v0, $zero, 0xc
/* DC4FAC 80240BDC AE620070 */  sw        $v0, 0x70($s3)
.L80240BE0:
/* DC4FB0 80240BE0 3C06BFFF */  lui       $a2, 0xbfff
/* DC4FB4 80240BE4 34C6FFFF */  ori       $a2, $a2, 0xffff
/* DC4FB8 80240BE8 27A50038 */  addiu     $a1, $sp, 0x38
/* DC4FBC 80240BEC 2404FFFB */  addiu     $a0, $zero, -5
/* DC4FC0 80240BF0 8E2200B0 */  lw        $v0, 0xb0($s1)
/* DC4FC4 80240BF4 8E230000 */  lw        $v1, ($s1)
/* DC4FC8 80240BF8 3C0142C8 */  lui       $at, 0x42c8
/* DC4FCC 80240BFC 44810000 */  mtc1      $at, $f0
/* DC4FD0 80240C00 00441024 */  and       $v0, $v0, $a0
/* DC4FD4 80240C04 00661824 */  and       $v1, $v1, $a2
/* DC4FD8 80240C08 AE2200B0 */  sw        $v0, 0xb0($s1)
/* DC4FDC 80240C0C AE230000 */  sw        $v1, ($s1)
/* DC4FE0 80240C10 864200A8 */  lh        $v0, 0xa8($s2)
/* DC4FE4 80240C14 27A70040 */  addiu     $a3, $sp, 0x40
/* DC4FE8 80240C18 E7A00044 */  swc1      $f0, 0x44($sp)
/* DC4FEC 80240C1C C6460038 */  lwc1      $f6, 0x38($s2)
/* DC4FF0 80240C20 C640003C */  lwc1      $f0, 0x3c($s2)
/* DC4FF4 80240C24 C6420040 */  lwc1      $f2, 0x40($s2)
/* DC4FF8 80240C28 44822000 */  mtc1      $v0, $f4
/* DC4FFC 80240C2C 00000000 */  nop
/* DC5000 80240C30 46802120 */  cvt.s.w   $f4, $f4
/* DC5004 80240C34 27A20044 */  addiu     $v0, $sp, 0x44
/* DC5008 80240C38 46040000 */  add.s     $f0, $f0, $f4
/* DC500C 80240C3C E7A60038 */  swc1      $f6, 0x38($sp)
/* DC5010 80240C40 E7A20040 */  swc1      $f2, 0x40($sp)
/* DC5014 80240C44 E7A0003C */  swc1      $f0, 0x3c($sp)
/* DC5018 80240C48 AFA20010 */  sw        $v0, 0x10($sp)
/* DC501C 80240C4C 8E440080 */  lw        $a0, 0x80($s2)
/* DC5020 80240C50 0C0372DF */  jal       func_800DCB7C
/* DC5024 80240C54 27A6003C */   addiu    $a2, $sp, 0x3c
/* DC5028 80240C58 10400003 */  beqz      $v0, .L80240C68
/* DC502C 80240C5C 00000000 */   nop
/* DC5030 80240C60 C7A0003C */  lwc1      $f0, 0x3c($sp)
/* DC5034 80240C64 E640003C */  swc1      $f0, 0x3c($s2)
.L80240C68:
/* DC5038 80240C68 8E630070 */  lw        $v1, 0x70($s3)
/* DC503C 80240C6C 2C620064 */  sltiu     $v0, $v1, 0x64
/* DC5040 80240C70 10400050 */  beqz      $v0, .L80240DB4
/* DC5044 80240C74 00031080 */   sll      $v0, $v1, 2
/* DC5048 80240C78 3C018025 */  lui       $at, %hi(D_80248770)
/* DC504C 80240C7C 00220821 */  addu      $at, $at, $v0
/* DC5050 80240C80 8C228770 */  lw        $v0, %lo(D_80248770)($at)
/* DC5054 80240C84 00400008 */  jr        $v0
/* DC5058 80240C88 00000000 */   nop
/* DC505C 80240C8C 0260202D */  daddu     $a0, $s3, $zero
/* DC5060 80240C90 0280282D */  daddu     $a1, $s4, $zero
/* DC5064 80240C94 0C012568 */  jal       func_800495A0
/* DC5068 80240C98 02A0302D */   daddu    $a2, $s5, $zero
/* DC506C 80240C9C 0260202D */  daddu     $a0, $s3, $zero
/* DC5070 80240CA0 0280282D */  daddu     $a1, $s4, $zero
/* DC5074 80240CA4 0C0125AE */  jal       func_800496B8
/* DC5078 80240CA8 02A0302D */   daddu    $a2, $s5, $zero
/* DC507C 80240CAC 0809036D */  j         .L80240DB4
/* DC5080 80240CB0 00000000 */   nop
/* DC5084 80240CB4 0260202D */  daddu     $a0, $s3, $zero
/* DC5088 80240CB8 0280282D */  daddu     $a1, $s4, $zero
/* DC508C 80240CBC 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* DC5090 80240CC0 02A0302D */   daddu    $a2, $s5, $zero
/* DC5094 80240CC4 0260202D */  daddu     $a0, $s3, $zero
/* DC5098 80240CC8 0280282D */  daddu     $a1, $s4, $zero
/* DC509C 80240CCC 0C012701 */  jal       func_80049C04
/* DC50A0 80240CD0 02A0302D */   daddu    $a2, $s5, $zero
/* DC50A4 80240CD4 0809036D */  j         .L80240DB4
/* DC50A8 80240CD8 00000000 */   nop
/* DC50AC 80240CDC 0260202D */  daddu     $a0, $s3, $zero
/* DC50B0 80240CE0 0280282D */  daddu     $a1, $s4, $zero
/* DC50B4 80240CE4 0C01278F */  jal       func_80049E3C
/* DC50B8 80240CE8 02A0302D */   daddu    $a2, $s5, $zero
/* DC50BC 80240CEC 0260202D */  daddu     $a0, $s3, $zero
/* DC50C0 80240CF0 0280282D */  daddu     $a1, $s4, $zero
/* DC50C4 80240CF4 0C0127B3 */  jal       func_80049ECC
/* DC50C8 80240CF8 02A0302D */   daddu    $a2, $s5, $zero
/* DC50CC 80240CFC 0809036D */  j         .L80240DB4
/* DC50D0 80240D00 00000000 */   nop
/* DC50D4 80240D04 0260202D */  daddu     $a0, $s3, $zero
/* DC50D8 80240D08 0280282D */  daddu     $a1, $s4, $zero
/* DC50DC 80240D0C 0C0127DF */  jal       func_80049F7C
/* DC50E0 80240D10 02A0302D */   daddu    $a2, $s5, $zero
/* DC50E4 80240D14 0260202D */  daddu     $a0, $s3, $zero
/* DC50E8 80240D18 0280282D */  daddu     $a1, $s4, $zero
/* DC50EC 80240D1C 0C012849 */  jal       func_8004A124
/* DC50F0 80240D20 02A0302D */   daddu    $a2, $s5, $zero
/* DC50F4 80240D24 8E630070 */  lw        $v1, 0x70($s3)
/* DC50F8 80240D28 2402000E */  addiu     $v0, $zero, 0xe
/* DC50FC 80240D2C 14620021 */  bne       $v1, $v0, .L80240DB4
/* DC5100 80240D30 00000000 */   nop
/* DC5104 80240D34 0260202D */  daddu     $a0, $s3, $zero
/* DC5108 80240D38 0280282D */  daddu     $a1, $s4, $zero
/* DC510C 80240D3C 0C09021C */  jal       func_80240870_DC4C40
/* DC5110 80240D40 02A0302D */   daddu    $a2, $s5, $zero
/* DC5114 80240D44 8E630070 */  lw        $v1, 0x70($s3)
/* DC5118 80240D48 2402000F */  addiu     $v0, $zero, 0xf
/* DC511C 80240D4C 14620019 */  bne       $v1, $v0, .L80240DB4
/* DC5120 80240D50 00000000 */   nop
/* DC5124 80240D54 0260202D */  daddu     $a0, $s3, $zero
/* DC5128 80240D58 0280282D */  daddu     $a1, $s4, $zero
/* DC512C 80240D5C 0C090238 */  jal       func_802408E0_DC4CB0
/* DC5130 80240D60 02A0302D */   daddu    $a2, $s5, $zero
/* DC5134 80240D64 8E630070 */  lw        $v1, 0x70($s3)
/* DC5138 80240D68 24020010 */  addiu     $v0, $zero, 0x10
/* DC513C 80240D6C 14620011 */  bne       $v1, $v0, .L80240DB4
/* DC5140 80240D70 00000000 */   nop
/* DC5144 80240D74 0260202D */  daddu     $a0, $s3, $zero
/* DC5148 80240D78 0280282D */  daddu     $a1, $s4, $zero
/* DC514C 80240D7C 0C09026C */  jal       func_802409B0_DC4D80
/* DC5150 80240D80 02A0302D */   daddu    $a2, $s5, $zero
/* DC5154 80240D84 8E630070 */  lw        $v1, 0x70($s3)
/* DC5158 80240D88 24020011 */  addiu     $v0, $zero, 0x11
/* DC515C 80240D8C 14620009 */  bne       $v1, $v0, .L80240DB4
/* DC5160 80240D90 00000000 */   nop
/* DC5164 80240D94 0260202D */  daddu     $a0, $s3, $zero
/* DC5168 80240D98 0280282D */  daddu     $a1, $s4, $zero
/* DC516C 80240D9C 0C090292 */  jal       func_80240A48_DC4E18
/* DC5170 80240DA0 02A0302D */   daddu    $a2, $s5, $zero
/* DC5174 80240DA4 0809036D */  j         .L80240DB4
/* DC5178 80240DA8 00000000 */   nop
/* DC517C 80240DAC 0C0129CF */  jal       func_8004A73C
/* DC5180 80240DB0 0260202D */   daddu    $a0, $s3, $zero
.L80240DB4:
/* DC5184 80240DB4 8FBF0060 */  lw        $ra, 0x60($sp)
/* DC5188 80240DB8 8FB5005C */  lw        $s5, 0x5c($sp)
/* DC518C 80240DBC 8FB40058 */  lw        $s4, 0x58($sp)
/* DC5190 80240DC0 8FB30054 */  lw        $s3, 0x54($sp)
/* DC5194 80240DC4 8FB20050 */  lw        $s2, 0x50($sp)
/* DC5198 80240DC8 8FB1004C */  lw        $s1, 0x4c($sp)
/* DC519C 80240DCC 8FB00048 */  lw        $s0, 0x48($sp)
/* DC51A0 80240DD0 0000102D */  daddu     $v0, $zero, $zero
/* DC51A4 80240DD4 03E00008 */  jr        $ra
/* DC51A8 80240DD8 27BD0068 */   addiu    $sp, $sp, 0x68
/* DC51AC 80240DDC 00000000 */  nop
