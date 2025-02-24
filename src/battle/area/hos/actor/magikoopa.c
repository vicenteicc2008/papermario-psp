#include "../area.h"
#include "sprite/npc/FlyingMagikoopa.h"
#include "sprite/npc/Magikoopa.h"

#define NAMESPACE A(magikoopa)

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_2               = 2,
    PRT_3               = 3,
};

enum N(ActorVars) {
    AVAR_Unk_0      = 0,
    AVAR_Unk_1      = 1,
    AVAR_Unk_2      = 2,
    AVAR_Unk_3      = 3,
    AVAR_Unk_4      = 4,
    AVAR_Unk_5      = 5,
    AVAR_Unk_6      = 6,
    AVAR_Unk_7      = 7,
    AVAR_Unk_8      = 8,
    AVAR_Unk_9      = 9,
    AVAR_Unk_A      = 10,
    AVAR_Unk_B      = 11,
};

enum N(ActorParams) {
    DMG_UNK         = 0,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(DefenseTable_flying)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,             100,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              50,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,            100,
    STATUS_KEY_STOP,              100,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

s32 N(StatusTable_flying)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,             100,
    STATUS_KEY_POISON,             50,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             50,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,            100,
    STATUS_KEY_STOP,              100,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

extern s32 N(IdleAnimations)[];

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -12 },
    },
};

extern s32 N(IdleAnimations_flying)[];
extern s32 N(IdleAnimations_broomstick)[];

ActorPartBlueprint N(ActorParts_flying)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable_flying),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -12 },
    },
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -10, 35 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_flying),
        .defenseTable = N(DefenseTable_flying),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_broomstick),
        .defenseTable = N(DefenseTable_flying),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

extern EvtScript N(init_8021E100);

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_MAGIKOOPA_BOSS,
    .level = ACTOR_LEVEL_MAGIKOOPA_BOSS,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(init_8021E100),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 0,
    .size = { 36, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

extern EvtScript N(init_8021E2C0);

ActorBlueprint N(flying) = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_FLYING_MAGIKOOPA_BOSS,
    .level = ACTOR_LEVEL_FLYING_MAGIKOOPA_BOSS,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(ActorParts_flying)),
    .partsData = N(ActorParts_flying),
    .initScript = &N(init_8021E2C0),
    .statusTable = N(StatusTable_flying),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 100,
    .coinReward = 0,
    .size = { 48, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

s32 N(IdleAnimations)[] = {
    STATUS_KEY_NORMAL,    ANIM_Magikoopa_Anim01,
    STATUS_KEY_STONE,     ANIM_Magikoopa_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Magikoopa_Anim08,
    STATUS_KEY_POISON,    ANIM_Magikoopa_Anim01,
    STATUS_KEY_STOP,      ANIM_Magikoopa_Anim00,
    STATUS_KEY_STATIC,    ANIM_Magikoopa_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_Magikoopa_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Magikoopa_Anim07,
    STATUS_KEY_FEAR,      ANIM_Magikoopa_Anim07,
    STATUS_END,
};

s32 N(IdleAnimations_flying)[] = {
    STATUS_KEY_NORMAL,    ANIM_FlyingMagikoopa_Anim01,
    STATUS_KEY_STONE,     ANIM_FlyingMagikoopa_Anim00,
    STATUS_KEY_SLEEP,     ANIM_FlyingMagikoopa_Anim08,
    STATUS_KEY_POISON,    ANIM_FlyingMagikoopa_Anim01,
    STATUS_KEY_STOP,      ANIM_FlyingMagikoopa_Anim00,
    STATUS_KEY_STATIC,    ANIM_FlyingMagikoopa_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_FlyingMagikoopa_Anim00,
    STATUS_KEY_DIZZY,     ANIM_FlyingMagikoopa_Anim07,
    STATUS_KEY_FEAR,      ANIM_FlyingMagikoopa_Anim07,
    STATUS_END,
};

s32 N(IdleAnimations_broomstick)[] = {
    STATUS_KEY_NORMAL,    ANIM_FlyingMagikoopa_Anim0A,
    STATUS_END,
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

#include "common/ShrinkActor.inc.c"

#include "common/GetSelectedMoveID.inc.c"

EvtScript N(8021D784) = {
    EVT_CALL(GetBattleFlags, LVar0)
    EVT_IF_NOT_FLAG(LVar0, BS_FLAGS1_PARTNER_ACTING)
        EVT_IF_FLAG(LVar0, BS_FLAGS1_200 | BS_FLAGS1_40)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_2, 1)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(N(GetSelectedMoveID), LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_OR_EQ(MOVE_HEADBONK1)
            EVT_CASE_OR_EQ(MOVE_HEADBONK2)
            EVT_CASE_OR_EQ(MOVE_HEADBONK3)
            EVT_CASE_OR_EQ(MOVE_MULTIBONK)
                EVT_CALL(GetBattleFlags, LVar0)
                EVT_IF_FLAG(LVar0, BS_FLAGS1_200 | BS_FLAGS1_40)
                    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_2, 1)
                EVT_END_IF
            EVT_END_CASE_GROUP
        EVT_END_SWITCH
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

#include "common/battle/SetAbsoluteStatusOffsets.inc.c"

#include "common/StartRumbleWithParams.inc.c"

extern EvtScript N(handleEvent_8021E6D8);

EvtScript N(8021D890) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_2, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim04)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetLastElement, LVar0)
    EVT_IF_FLAG(LVar0, DAMAGE_TYPE_POW)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim04)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_RETURN
    EVT_LABEL(0)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_3, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_MULTI_TARGET, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_2, ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_2, ACTOR_PART_FLAG_MULTI_TARGET, FALSE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_3, ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 1)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_3, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.8))
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    EVT_CALL(N(StartRumbleWithParams), 150, 10)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(0.7))
    EVT_END_THREAD
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar3)
    EVT_IF_EQ(LVar3, 15)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim04)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        EVT_ADD(LVar4, 10)
        EVT_ADD(LVar5, 5)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar3, LVar4, LVar5, EVT_FLOAT(1.0), 10, 0)
    EVT_END_IF
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_LOOP(20)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_WAIT(1)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim01)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_FLYING, FALSE)
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021E6D8)))
    EVT_CALL(SetActorType, ACTOR_SELF, 149)
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable)))
    EVT_CALL(N(SetAbsoluteStatusOffsets), -10, 20, 10, 32)
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TYPE_CHANGED, TRUE)
    EVT_CALL(ResetAllActorSounds, ACTOR_SELF)
    EVT_CALL(GetIndexFromPos, ACTOR_SELF, LVar0)
    EVT_MOD(LVar0, 4)
    EVT_CALL(SetGoalToIndex, ACTOR_SELF, LVar0)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAway) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_IF_NE(LVar0, 57)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 15)
        EVT_WAIT(15)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_01)
    EVT_END_IF
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_WAIT(10)
    EVT_CALL(SetActorYaw, ACTOR_SELF, 180)
    EVT_CALL(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(10.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 200)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
    EVT_CALL(YieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_EXEC_WAIT(EVS_ForceNextTarget)
    EVT_CALL(HideHealthBar, ACTOR_SELF)
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_0, LVar0)
    EVT_BITWISE_AND_CONST(LVar0, -2) // TODO
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_0, LVar0)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(takeTurn_80223B24);

EvtScript N(init_8021E100) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80223B24)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021E6D8)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(GetBattleVar, 2, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetBattleVar, 2, -1)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_2, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_3, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_4, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_5, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_6, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_7, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_8, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_9, -1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_A, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_B, -1)
    EVT_RETURN
    EVT_END
};

extern EvtScript N(handleEvent_8021EDF0);

EvtScript N(init_8021E2C0) = {
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_80223B24)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021EDF0)))
    EVT_CALL(GetBattleVar, 2, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetBattleVar, 2, -1)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_2, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_3, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_4, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_5, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_6, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_7, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_8, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_9, -1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_A, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_B, -1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021E46C) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_1, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_9, LVar0)
    EVT_CALL(ActorExists, LVar0, LVar1)
    EVT_IF_EQ(LVar1, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_A, 0)
    EVT_CALL(GetLastElement, LVarA)
    EVT_IF_FLAG(LVarA, DAMAGE_TYPE_MULTIPLE_POPUPS)
        EVT_LABEL(0)
        EVT_CALL(GetBattleFlags, LVarA)
        EVT_IF_FLAG(LVarA, BS_FLAGS1_100)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_9, LVar0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_9, -1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVarA)
    EVT_IF_FLAG(LVarA, ACTOR_FLAG_FLYING)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_2, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
    EVT_ELSE
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, FALSE)
    EVT_END_IF
    EVT_CALL(GetActorPos, LVar0, LVar1, LVar2, LVar3)
    EVT_CALL(RemoveActor, LVar0)
    EVT_THREAD
        EVT_ADD(LVar3, 2)
        EVT_LOOP(2)
            EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar1, LVar2, LVar3, 0, 0, 0, 0, 0)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021E6D8) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_MAIN, 255)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_0, LVar0)
            EVT_BITWISE_OR_CONST(LVar0, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_0, LVar0)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_UP_AND_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim05)
            EVT_SET_CONST(LVar2, ANIM_Magikoopa_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim05)
            EVT_SET_CONST(LVar2, ANIM_Magikoopa_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_0, LVar0)
            EVT_IF_FLAG(LVar0, 1)
                EVT_EXEC_WAIT(N(8021E46C))
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_EXEC_WAIT(N(8021E46C))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim04)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim02)
            EVT_EXEC_WAIT(N(runAway))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_MAIN, 0, 2, 0)
                EVT_ELSE
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_MAIN, -4, 5, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_STAR_BEAM)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_Magikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021EDF0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetPartAlpha, ACTOR_SELF, PRT_2, 255)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_0, LVar0)
            EVT_BITWISE_OR_CONST(LVar0, 1)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_0, LVar0)
            EVT_EXEC_WAIT(N(8021D784))
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_FALL_TRIGGER)
            EVT_EXEC_WAIT(N(8021D784))
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_EXEC_WAIT(N(8021D890))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_UP_AND_AWAY)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
        EVT_CASE_OR_EQ(EVENT_15)
            EVT_EXEC_WAIT(N(8021D784))
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim05)
            EVT_SET_CONST(LVar2, ANIM_FlyingMagikoopa_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_EXEC_WAIT(N(8021D890))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim05)
            EVT_SET_CONST(LVar2, ANIM_FlyingMagikoopa_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim06)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_0, LVar0)
            EVT_IF_FLAG(LVar0, 1)
                EVT_EXEC_WAIT(N(8021E46C))
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NE(LVar0, 0)
                EVT_EXEC_WAIT(N(8021E46C))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
            EVT_CALL(SetActorPos, ACTOR_SELF, 20, 0, 0)
            EVT_CALL(HPBarToCurrent, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim01)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(4.0))
            EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 1, EASING_LINEAR)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim01)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim04)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.5))
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim02)
            EVT_EXEC_WAIT(N(runAway))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_EXEC_WAIT(N(8021E46C))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_2, -3, 0, 0)
                EVT_ELSE
                    EVT_CALL(SetPartDispOffset, ACTOR_SELF, PRT_2, -15, 0, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim01)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_EQ(EVENT_STAR_BEAM)
            EVT_SET_CONST(LVar0, PRT_2)
            EVT_SET_CONST(LVar1, ANIM_FlyingMagikoopa_Anim04)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_EXEC_WAIT(N(8021E46C))
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(healOne) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_A, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_B, 0)
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_Unk_4, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 12)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 16)
            EVT_ADD(LVar1, 31)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtActor, LVarB, SOUND_206D)
        EVT_CALL(PlaySoundAtActor, LVarB, SOUND_HEART_BOUNCE)
        EVT_WAIT(30)
        EVT_CALL(PlaySoundAtActor, LVarB, SOUND_STAR_BOUNCE_A)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(FreezeBattleState, TRUE)
        EVT_CALL(HealActor, LVarB, 0, FALSE)
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(healAll) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_A, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_B, 1)
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_Unk_3, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 12)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 16)
            EVT_ADD(LVar1, 31)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 7, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_SET(LFlag0, FALSE)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetOriginalActorType, LVar0, LVar1)
    EVT_IF_EQ(LVar1, 71)
        EVT_CALL(GetActorVar, LVar0, AVAR_Unk_8, LVar1)
        EVT_IF_EQ(LVar1, 1)
            EVT_SET(LFlag0, TRUE)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_THREAD
            EVT_WAIT(5)
            EVT_CALL(PlaySoundAtActor, LVar0, SOUND_206D)
            EVT_CALL(PlaySoundAtActor, LVar0, SOUND_HEART_BOUNCE)
            EVT_WAIT(30)
            EVT_CALL(PlaySoundAtActor, LVar0, SOUND_STAR_BOUNCE_A)
        EVT_END_THREAD
        EVT_THREAD
            EVT_CALL(FreezeBattleState, TRUE)
            EVT_CALL(HealActor, LVar0, 0, TRUE)
            EVT_CALL(FreezeBattleState, FALSE)
        EVT_END_THREAD
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(WaitForBuffDone)
    EVT_WAIT(1)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 10)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(shapeSpell) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_B, 2)
    EVT_SET(LFlag0, FALSE)
    EVT_SET(LFlag1, FALSE)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_A, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_SET(LFlag0, TRUE)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_9, LVarA)
    EVT_END_IF
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_SET(LFlag1, TRUE)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_CALL(UseIdleAnimation, LVarA, FALSE)
    EVT_END_IF
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 10)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_IF_EQ(LFlag1, FALSE)
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(SetAnimation, LVarA, 1, ANIM_Magikoopa_Anim02)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 17)
            EVT_ADD(LVar1, 33)
            EVT_PLAY_EFFECT(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 30, 0)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim02)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
        EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 13)
        EVT_ELSE
            EVT_SUB(LVar0, 17)
            EVT_ADD(LVar1, 33)
        EVT_END_IF
        EVT_PLAY_EFFECT(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 30, 0)
    EVT_ELSE
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(SetAnimation, LVarA, 1, ANIM_FlyingMagikoopa_Anim02)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_PLAY_EFFECT(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 30, 0)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim02)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
        EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
        EVT_END_IF
        EVT_PLAY_EFFECT(EFFECT_GATHER_MAGIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.5), 30, 0)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar9, 0, 0, 1, 16)
    EVT_SWITCH(LVar9)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_CALL(PlaySoundAtActor, LVarA, SOUND_SPELL_CAST2)
            EVT_END_IF
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
            EVT_IF_EQ(LFlag1, FALSE)
                EVT_IF_EQ(LFlag0, TRUE)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_Magikoopa_Anim03)
                EVT_END_IF
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim03)
            EVT_ELSE
                EVT_IF_EQ(LFlag0, TRUE)
                    EVT_CALL(SetAnimation, LVarA, 1, ANIM_FlyingMagikoopa_Anim03)
                EVT_END_IF
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim03)
            EVT_END_IF
            EVT_WAIT(5)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
            EVT_SUB(LVar4, 50)
            EVT_SET(LVar5, 0)
            EVT_IF_EQ(LFlag1, FALSE)
                EVT_IF_EQ(LFlag0, TRUE)
                    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                    EVT_SUB(LVar0, 20)
                    EVT_ADD(LVar1, 20)
                    EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 30)
                EVT_END_IF
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                    EVT_SUB(LVar0, 8)
                    EVT_ADD(LVar1, 8)
                EVT_ELSE
                    EVT_SUB(LVar0, 20)
                    EVT_ADD(LVar1, 20)
                EVT_END_IF
                EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 30)
            EVT_ELSE
                EVT_IF_EQ(LFlag0, TRUE)
                    EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
                    EVT_SUB(LVar0, 20)
                    EVT_ADD(LVar1, 20)
                    EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 30)
                EVT_END_IF
                EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
                EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
                    EVT_SUB(LVar0, 8)
                    EVT_ADD(LVar1, 8)
                EVT_ELSE
                    EVT_SUB(LVar0, 20)
                    EVT_ADD(LVar1, 20)
                EVT_END_IF
                EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 30)
            EVT_END_IF
            EVT_WAIT(50)
            EVT_IF_EQ(LVar9, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_IF_EQ(LFlag0, TRUE)
                EVT_CALL(UseIdleAnimation, LVarA, TRUE)
            EVT_END_IF
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_CALL(PlaySoundAtActor, LVarA, SOUND_SPELL_CAST2)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST2)
    EVT_IF_EQ(LFlag1, FALSE)
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(SetAnimation, LVarA, 1, ANIM_Magikoopa_Anim03)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim03)
    EVT_ELSE
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(SetAnimation, LVarA, 1, ANIM_FlyingMagikoopa_Anim03)
        EVT_END_IF
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim03)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
    EVT_IF_EQ(LFlag1, FALSE)
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_ADD(LVar1, 20)
            EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 20)
        EVT_END_IF
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
        EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 8)
            EVT_ADD(LVar1, 8)
        EVT_ELSE
            EVT_SUB(LVar0, 20)
            EVT_ADD(LVar1, 20)
        EVT_END_IF
        EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 20)
    EVT_ELSE
        EVT_IF_EQ(LFlag0, TRUE)
            EVT_CALL(GetActorPos, LVarA, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_ADD(LVar1, 20)
            EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 20)
        EVT_END_IF
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar3)
        EVT_IF_FLAG(LVar3, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 8)
            EVT_ADD(LVar1, 8)
        EVT_ELSE
            EVT_SUB(LVar0, 20)
            EVT_ADD(LVar1, 20)
        EVT_END_IF
        EVT_CALL(N(ShrinkActor), LVar0, LVar1, LVar6, LVar4, LVar5, LVar6, 20)
    EVT_END_IF
    EVT_WAIT(18)
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_WAIT(2)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, (DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT), 0, 0, 0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_ELSE
        EVT_WAIT(2)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, (DAMAGE_TYPE_MAGIC | DAMAGE_TYPE_NO_CONTACT), 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_IF
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_IF_EQ(LFlag0, TRUE)
        EVT_CALL(UseIdleAnimation, LVarA, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80221144) = {
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetIndexFromHome, LVar0, LVar1)
    EVT_MOD(LVar1, 4)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_SET(LFlagB, TRUE)
        EVT_CASE_EQ(1)
            EVT_SET(LFlagC, TRUE)
        EVT_CASE_EQ(2)
            EVT_SET(LFlagD, TRUE)
        EVT_CASE_EQ(3)
            EVT_SET(LFlagE, TRUE)
    EVT_END_SWITCH
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_SET(LVar0, -1)
    EVT_CALL(GetIndexFromHome, ACTOR_SELF, LVar1)
    EVT_MOD(LVar1, 4)
    EVT_SWITCH(LVar1)
        EVT_CASE_EQ(0)
            EVT_IF_EQ(LFlagC, FALSE)
                EVT_SET(LVar0, 1)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_IF_EQ(LFlagB, FALSE)
                EVT_SET(LVar0, 0)
            EVT_END_IF
            EVT_IF_EQ(LFlagD, FALSE)
                EVT_SET(LVar0, 2)
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_IF_EQ(LFlagC, FALSE)
                EVT_SET(LVar0, 1)
            EVT_END_IF
            EVT_IF_EQ(LFlagE, FALSE)
                EVT_SET(LVar0, 3)
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_IF_EQ(LFlagD, FALSE)
                EVT_SET(LVar0, 2)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_IF_NE(LVar0, -1)
        EVT_CALL(GetActorFlags, ACTOR_SELF, LVar1)
        EVT_IF_FLAG(LVar1, ACTOR_FLAG_FLYING)
            EVT_ADD(LVar0, 4)
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8022142C) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(init_8022143C) = {
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8022142C)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_1, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(init_80221478) = {
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8022142C)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_1, 1)
    EVT_RETURN
    EVT_END
};

s32 N(DefenseTable_802214B4)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(DefenseTable_802214C0)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable_802214CC)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,                0,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

s32 N(StatusTable_80221578)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,                0,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts_80221624)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 2, 35 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable_802214B4),
        .eventFlags = ACTOR_EVENT_FLAG_ILLUSORY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -12 },
    },
};

ActorPartBlueprint N(ActorParts_80221648)[] = {
    {
        .flags = ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -10, 35 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_flying),
        .defenseTable = N(DefenseTable_802214C0),
        .eventFlags = ACTOR_EVENT_FLAG_ILLUSORY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
};

ActorBlueprint N(clone) = {
    .flags = ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_MAGICLONE,
    .level = ACTOR_LEVEL_MAGICLONE,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(ActorParts_80221624)),
    .partsData = N(ActorParts_80221624),
    .initScript = &N(init_8022143C),
    .statusTable = N(StatusTable_802214CC),
    .escapeChance = 40,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 0,
    .size = { 36, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 32 },
};

ActorBlueprint N(flying_clone) = {
    .flags = ACTOR_FLAG_FLYING | ACTOR_FLAG_NO_ATTACK,
    .type = ACTOR_TYPE_FLYING_MAGICLONE,
    .level = ACTOR_LEVEL_FLYING_MAGICLONE,
    .maxHP = 11,
    .partCount = ARRAY_COUNT(N(ActorParts_80221648)),
    .partsData = N(ActorParts_80221648),
    .initScript = &N(init_80221478),
    .statusTable = N(StatusTable_80221578),
    .escapeChance = 40,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 75,
    .coinReward = 2,
    .size = { 48, 40 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -25, 20 },
    .statusTextOffset = { 1, 34 },
};

Vec3i N(vector3D_802216BC) = { 0, -1000, 0 };

Formation N(specialFormation_802216C8) = {
    ACTOR_BY_POS(N(clone), N(vector3D_802216BC), 0),
};

Formation N(specialFormation_802216E4) = {
    ACTOR_BY_POS(N(flying_clone), N(vector3D_802216BC), 0),
};

EvtScript N(makeCopy) = {
    EVT_CALL(CountPlayerTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_8000, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(runAway))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_A, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_B, 3)
    EVT_SET(LFlag0, FALSE)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_SET(LFlag0, TRUE)
    EVT_END_IF
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_CALL(SummonEnemy, EVT_PTR(N(specialFormation_802216C8)), FALSE)
    EVT_ELSE
        EVT_CALL(SummonEnemy, EVT_PTR(N(specialFormation_802216E4)), FALSE)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_9, LVar0)
    EVT_SET(LVarA, LVar0)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(EnableIdleScript, LVarA, IDLE_SCRIPT_DISABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(UseIdleAnimation, LVarA, FALSE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 25)
    EVT_WAIT(25)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST3)
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim02)
        EVT_CALL(SetAnimation, LVarA, 1, ANIM_Magikoopa_Anim02)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 23)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim02)
        EVT_CALL(SetAnimation, LVarA, 1, ANIM_FlyingMagikoopa_Anim02)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 23)
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 1, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 30, 0)
    EVT_WAIT(10)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(EnableIdleScript, LVar9, IDLE_SCRIPT_ENABLE)
    EVT_WAIT(30)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, -3)
    EVT_CALL(SetActorPos, LVarA, LVar0, LVar1, LVar2)
    EVT_SET(LVar9, LVarA)
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST4)
    EVT_CALL(PlaySoundAtActor, LVar9, SOUND_SPELL_CAST4)
    EVT_CALL(SetPartFlagBits, LVar9, 1, ACTOR_PART_FLAG_MULTI_TARGET, FALSE)
    EVT_CALL(RandInt, 1000, LVar0)
    EVT_IF_LT(LVar0, 500)
        EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(2.0))
        EVT_EXEC_WAIT(N(80221144))
        EVT_CALL(SetGoalToIndex, ACTOR_SELF, LVar0)
        EVT_CALL(FlyToGoal, ACTOR_SELF, 0, 0, EASING_LINEAR)
    EVT_ELSE
        EVT_CALL(SetActorSpeed, LVar9, EVT_FLOAT(2.0))
        EVT_EXEC_WAIT(N(80221144))
        EVT_CALL(SetGoalToIndex, LVar9, LVar0)
        EVT_CALL(FlyToGoal, LVar9, 0, 0, EASING_LINEAR)
    EVT_END_IF
    EVT_CALL(SetPartFlagBits, LVar9, 1, ACTOR_PART_FLAG_MULTI_TARGET, TRUE)
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_CALL(SetEnemyHP, LVar9, LVar0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(GetActorPos, LVar9, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVar9, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, LVar9)
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_ATTACK_CHARGED, TRUE)
    EVT_ELSE
        EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_2, ACTOR_EVENT_FLAG_ATTACK_CHARGED, TRUE)
    EVT_END_IF
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim01)
        EVT_CALL(SetAnimation, LVar9, 1, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim01)
        EVT_CALL(SetAnimation, LVar9, 1, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_CALL(UseIdleAnimation, LVar9, TRUE)
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/UnkFunc52.inc.c"

EvtScript N(boostAttack) = {
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetIndexFromHome, LVar0, LVar1)
    EVT_CALL(GetBattleVar, 2, LVar2)
    EVT_IF_GT(LVar1, LVar2)
        EVT_CALL(N(UnkFunc52), LVar0, LVar3)
        EVT_IF_EQ(LVar3, 0)
            EVT_CALL(GetActorAttackBoost, LVar0, LVar4)
            EVT_IF_LT(LVar4, 0)
                EVT_SET(LVar8, LVar0)
                EVT_CALL(SetBattleVar, 2, LVar1)
                EVT_GOTO(100)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_SET(LFlag0, TRUE)
        EVT_CALL(SetBattleVar, 2, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(CountPlayerTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_8000, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(runAway))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(shapeSpell))
    EVT_RETURN
    EVT_LABEL(100)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_A, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_B, 4)
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_Unk_5, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 12)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 16)
            EVT_ADD(LVar1, 31)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, LVar8, SOUND_02DD)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(FreezeBattleState, TRUE)
        EVT_CALL(BoostAttack, LVar8, 0)
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(boostDefense) = {
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetIndexFromHome, LVar0, LVar1)
    EVT_CALL(GetBattleVar, 2, LVar2)
    EVT_IF_GT(LVar1, LVar2)
        EVT_CALL(N(UnkFunc52), LVar0, LVar3)
        EVT_IF_EQ(LVar3, 0)
            EVT_CALL(GetActorDefenseBoost, LVar0, LVar4)
            EVT_IF_LT(LVar4, 0)
                EVT_SET(LVar8, LVar0)
                EVT_CALL(SetBattleVar, 2, LVar1)
                EVT_GOTO(100)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_SET(LFlag0, TRUE)
        EVT_CALL(SetBattleVar, 2, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(CountPlayerTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_8000, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(runAway))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(shapeSpell))
    EVT_RETURN
    EVT_LABEL(100)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_A, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_B, 5)
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_Unk_6, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 12)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 16)
            EVT_ADD(LVar1, 31)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 5, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, LVar8, SOUND_02DD)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(FreezeBattleState, TRUE)
        EVT_CALL(BoostDefense, LVar8, 0)
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(electrify) = {
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetIndexFromHome, LVar0, LVar1)
    EVT_CALL(GetBattleVar, 2, LVar2)
    EVT_IF_GT(LVar1, LVar2)
        EVT_CALL(N(UnkFunc52), LVar0, LVar3)
        EVT_IF_EQ(LVar3, 0)
            EVT_CALL(GetStatusFlags, LVar0, LVar4)
            EVT_IF_NOT_FLAG(LVar4, STATUS_FLAG_TRANSPARENT | STATUS_FLAG_STATIC)
                EVT_SET(LVar8, LVar0)
                EVT_CALL(SetBattleVar, 2, LVar1)
                EVT_GOTO(100)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_SET(LFlag0, TRUE)
        EVT_CALL(SetBattleVar, 2, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(CountPlayerTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_8000, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(runAway))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(shapeSpell))
    EVT_RETURN
    EVT_LABEL(100)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_A, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_B, 6)
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_Unk_7, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_MAGIKOOPA_ELECTRIFY)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 12)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 16)
            EVT_ADD(LVar1, 31)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtActor, LVar8, SOUND_ELECTRIC_BUZZ)
            EVT_CALL(RandInt, 3, LVar0)
            EVT_ADD(LVar0, 3)
            EVT_WAIT(LVar0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(FreezeBattleState, TRUE)
        EVT_CALL(ElectrifyActor, LVar8, 0)
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(vanish) = {
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetIndexFromHome, LVar0, LVar1)
    EVT_CALL(GetBattleVar, 2, LVar2)
    EVT_IF_GT(LVar1, LVar2)
        EVT_CALL(N(UnkFunc52), LVar0, LVar3)
        EVT_IF_EQ(LVar3, 0)
            EVT_CALL(GetStatusFlags, LVar0, LVar4)
            EVT_IF_NOT_FLAG(LVar4, STATUS_FLAG_TRANSPARENT | STATUS_FLAG_STATIC)
                EVT_SET(LVar8, LVar0)
                EVT_CALL(SetBattleVar, 2, LVar1)
                EVT_GOTO(100)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_SET(LFlag0, TRUE)
        EVT_CALL(SetBattleVar, 2, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(CountPlayerTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_8000, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(runAway))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(shapeSpell))
    EVT_RETURN
    EVT_LABEL(100)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_A, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_B, 7)
    EVT_CALL(AddActorVar, ACTOR_SELF, AVAR_Unk_8, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_14)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_WAIT(15)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim02)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim02)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_SPELL_CAST1)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 6)
            EVT_ADD(LVar1, 12)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 6, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 16)
            EVT_ADD(LVar1, 31)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 6, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVarA)
        EVT_IF_FLAG(LVarA, STATUS_FLAG_SHRINK)
            EVT_SUB(LVar0, 12)
            EVT_ADD(LVar1, 14)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 6, LVar0, LVar1, LVar2, EVT_FLOAT(0.12), 30, 0)
        EVT_ELSE
            EVT_SUB(LVar0, 30)
            EVT_ADD(LVar1, 36)
            EVT_SUB(LVar2, 2)
            EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 6, LVar0, LVar1, LVar2, EVT_FLOAT(0.3), 30, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorFlags, ACTOR_SELF, LVar0)
    EVT_IF_NOT_FLAG(LVar0, ACTOR_FLAG_FLYING)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Magikoopa_Anim01)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_2, ANIM_FlyingMagikoopa_Anim01)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtActor, LVar8, SOUND_02DB)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(FreezeBattleState, TRUE)
        EVT_CALL(VanishActor, LVar8, 0)
        EVT_CALL(FreezeBattleState, FALSE)
    EVT_END_THREAD
    EVT_CALL(WaitForBuffDone)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_WAIT(10)
    EVT_CALL(YieldTurn)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80223B24) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(shapeSpell))
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_A, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_SET(LVarA, 0)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
    EVT_SET(LFlag0, FALSE)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetOriginalActorType, LVar0, LVar1)
    EVT_IF_EQ(LVar1, 71)
        EVT_CALL(GetActorVar, LVar0, AVAR_Unk_8, LVar1)
        EVT_IF_EQ(LVar1, 1)
            EVT_SET(LFlag0, TRUE)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorHP, LVar0, LVar2)
    EVT_CALL(GetEnemyMaxHP, LVar0, LVar3)
    EVT_MULF(LVar2, EVT_FLOAT(100.0))
    EVT_DIVF(LVar2, LVar3)
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_IF_LE(LVar2, 0)
            EVT_CALL(RandInt, 99, LVar4)
            EVT_ADD(LVar4, 1)
            EVT_IF_LT(LVar4, 0)
                EVT_ADD(LVarA, 1)
                EVT_SET(LVarB, LVar0)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_IF_GT(LVarA, 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_SET(LVarA, 0)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(1)
    EVT_SET(LFlag0, FALSE)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetOriginalActorType, LVar0, LVar1)
    EVT_IF_EQ(LVar1, 71)
        EVT_CALL(GetActorVar, LVar0, AVAR_Unk_8, LVar1)
        EVT_IF_EQ(LVar1, 1)
            EVT_SET(LFlag0, TRUE)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorHP, LVar0, LVar2)
    EVT_CALL(GetEnemyMaxHP, LVar0, LVar3)
    EVT_MULF(LVar2, EVT_FLOAT(100.0))
    EVT_DIVF(LVar2, LVar3)
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_IF_LE(LVar2, 0)
            EVT_CALL(RandInt, 99, LVar4)
            EVT_ADD(LVar4, 1)
            EVT_IF_LT(LVar4, 0)
                EVT_ADD(LVarA, 1)
                EVT_SET(LVarB, LVar0)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_IF_GT(LVarA, 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_SET(LVarA, 0)
    EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(2)
    EVT_SET(LFlag0, FALSE)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_CALL(GetOriginalActorType, LVar0, LVar1)
    EVT_IF_EQ(LVar1, 71)
        EVT_CALL(GetActorVar, LVar0, AVAR_Unk_8, LVar1)
        EVT_IF_EQ(LVar1, 1)
            EVT_SET(LFlag0, TRUE)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetActorHP, LVar0, LVar2)
    EVT_CALL(GetEnemyMaxHP, LVar0, LVar3)
    EVT_MULF(LVar2, EVT_FLOAT(100.0))
    EVT_DIVF(LVar2, LVar3)
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_IF_LE(LVar2, 0)
            EVT_CALL(RandInt, 99, LVar4)
            EVT_ADD(LVar4, 1)
            EVT_IF_LT(LVar4, 0)
                EVT_ADD(LVarA, 1)
                EVT_SET(LVarB, LVar0)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_IF_GT(LVarA, 0)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_GOTO(20)
    EVT_LABEL(10)
    EVT_CALL(CountPlayerTargets, ACTOR_SELF, TARGET_FLAG_2 | TARGET_FLAG_8000, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_EXEC_WAIT(N(runAway))
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVarA, 1)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_4, LVar0)
        EVT_IF_LT(LVar0, 0)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 0)
                EVT_EXEC_WAIT(N(healOne))
                EVT_RETURN
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_3, LVar0)
            EVT_IF_LT(LVar0, 0)
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, 0)
                    EVT_EXEC_WAIT(N(healAll))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_3, LVar0)
        EVT_IF_LT(LVar0, 0)
            EVT_CALL(RandInt, 1000, LVar0)
            EVT_IF_LT(LVar0, 0)
                EVT_EXEC_WAIT(N(healAll))
                EVT_RETURN
            EVT_END_IF
        EVT_ELSE
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_4, LVar0)
            EVT_IF_LT(LVar0, 0)
                EVT_SETF(LVar9, EVT_FLOAT(100.0))
                EVT_CALL(EnemyCreateTargetList, TARGET_FLAG_2 | TARGET_FLAG_8000)
                EVT_CALL(InitTargetIterator)
                EVT_LABEL(11)
                EVT_SET(LFlag0, FALSE)
                EVT_CALL(GetOwnerTarget, LVar0, LVar1)
                EVT_CALL(GetOriginalActorType, LVar0, LVar1)
                EVT_IF_EQ(LVar1, 71)
                    EVT_CALL(GetActorVar, LVar0, AVAR_Unk_8, LVar1)
                    EVT_IF_EQ(LVar1, 1)
                        EVT_SET(LFlag0, TRUE)
                    EVT_END_IF
                EVT_END_IF
                EVT_CALL(GetActorHP, LVar0, LVar2)
                EVT_CALL(GetEnemyMaxHP, LVar0, LVar3)
                EVT_MULF(LVar2, EVT_FLOAT(100.0))
                EVT_DIVF(LVar2, LVar3)
                EVT_IF_EQ(LFlag0, FALSE)
                    EVT_IF_LE(LVar2, LVar9)
                        EVT_SETF(LVar9, LVar2)
                        EVT_SET(LVarB, LVar0)
                    EVT_END_IF
                EVT_END_IF
                EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
                EVT_IF_NE(LVar0, -1)
                    EVT_GOTO(11)
                EVT_END_IF
                EVT_CALL(RandInt, 1000, LVar0)
                EVT_IF_LT(LVar0, 0)
                    EVT_EXEC_WAIT(N(healOne))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_LABEL(20)
    EVT_SET(LVarA, 100)
    EVT_SET(LVarB, 0)
    EVT_SET(LVarC, 0)
    EVT_SET(LVarD, 0)
    EVT_SET(LVarE, 0)
    EVT_SET(LVarF, 0)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_A, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_SET(LVarA, 100)
        EVT_SET(LVarB, 0)
        EVT_SET(LVarC, 0)
        EVT_SET(LVarD, 0)
        EVT_SET(LVarE, 0)
        EVT_SET(LVarF, 0)
        EVT_GOTO(123)
    EVT_ELSE
        EVT_EXEC_WAIT(N(80221144))
        EVT_IF_EQ(LVar0, -1)
            EVT_SET(LVarB, 0)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_SET(LVarB, 0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_B, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(4)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_5, LVar1)
            EVT_IF_LT(LVar1, 0)
                EVT_CALL(RandInt, 99, LVar0)
                EVT_ADD(LVar0, 1)
                EVT_IF_LE(LVar0, 0)
                    EVT_SET(LVarA, 0)
                    EVT_SET(LVarB, 0)
                    EVT_SET(LVarC, 100)
                    EVT_SET(LVarD, 0)
                    EVT_SET(LVarE, 0)
                    EVT_SET(LVarF, 0)
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_EQ(5)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_6, LVar1)
            EVT_IF_LT(LVar1, 0)
                EVT_CALL(RandInt, 99, LVar0)
                EVT_ADD(LVar0, 1)
                EVT_IF_LE(LVar0, 0)
                    EVT_SET(LVarA, 0)
                    EVT_SET(LVarB, 0)
                    EVT_SET(LVarC, 0)
                    EVT_SET(LVarD, 100)
                    EVT_SET(LVarE, 0)
                    EVT_SET(LVarF, 0)
                EVT_END_IF
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_5, LVar0)
    EVT_IF_GE(LVar0, 0)
        EVT_SET(LVarC, 0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_6, LVar0)
    EVT_IF_GE(LVar0, 0)
        EVT_SET(LVarD, 0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_7, LVar0)
    EVT_IF_GE(LVar0, 0)
        EVT_SET(LVarE, 0)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_8, LVar0)
    EVT_IF_GE(LVar0, 0)
        EVT_SET(LVarF, 0)
    EVT_END_IF
    EVT_LABEL(123)
    EVT_SET(LVar9, 0)
    EVT_ADD(LVar9, LVarA)
    EVT_ADD(LVar9, LVarB)
    EVT_ADD(LVar9, LVarC)
    EVT_ADD(LVar9, LVarD)
    EVT_ADD(LVar9, LVarE)
    EVT_ADD(LVar9, LVarF)
    EVT_SUB(LVar9, 1)
    EVT_CALL(RandInt, LVar9, LVar0)
    EVT_ADD(LVar0, 1)
    EVT_IF_LE(LVar0, LVarA)
        EVT_EXEC_WAIT(N(shapeSpell))
        EVT_RETURN
    EVT_END_IF
    EVT_ADD(LVarA, LVarB)
    EVT_IF_LE(LVar0, LVarA)
        EVT_EXEC_WAIT(N(makeCopy))
        EVT_RETURN
    EVT_END_IF
    EVT_ADD(LVarA, LVarC)
    EVT_IF_LE(LVar0, LVarA)
        EVT_EXEC_WAIT(N(boostAttack))
        EVT_RETURN
    EVT_END_IF
    EVT_ADD(LVarA, LVarD)
    EVT_IF_LE(LVar0, LVarA)
        EVT_EXEC_WAIT(N(boostDefense))
        EVT_RETURN
    EVT_END_IF
    EVT_ADD(LVarA, LVarE)
    EVT_IF_LE(LVar0, LVarA)
        EVT_EXEC_WAIT(N(electrify))
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC_WAIT(N(vanish))
    EVT_RETURN
    EVT_END
};
