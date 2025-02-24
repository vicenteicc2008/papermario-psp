#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "animation_script.h"

#define NAMESPACE b_area_omo2_light_bulb

typedef struct IceShardBlueprint {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
} IceShardBlueprint; // size = 0x28

extern AnimScript toy_tank_as_close_hatch;

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(onHit);
extern EvtScript N(shake_tank);
extern EvtScript N(onDeath);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
};

enum N(ActorVars) {
    AVAR_Unk_5      = 5,
    AVAR_Unk_9      = 9,
};

enum N(ActorParams) {
    DMG_UNK         = 0,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_SHOCK,    0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
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

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 35 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -14 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_80 | ACTOR_FLAG_NO_HEALTH_BAR,
    .type = ACTOR_TYPE_LIGHT_BULB,
    .level = ACTOR_LEVEL_LIGHT_BULB,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 30, 30 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(SetActorPos, ACTOR_SELF, 116, 70, 0)
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_EXEC_WAIT(N(onHit))
        EVT_CASE_OR_EQ(EVENT_HIT)
        EVT_CASE_OR_EQ(EVENT_BURN_HIT)
            EVT_EXEC_WAIT(N(onHit))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(onHit))
        EVT_CASE_EQ(EVENT_ZERO_DAMAGE)
            EVT_CALL(GetActorVar, ACTOR_ENEMY1, AVAR_Unk_9, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(func_8026E914, LVar0, LVar1)
                EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
                EVT_WAIT(30)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_IMMUNE)
            EVT_CALL(GetActorVar, ACTOR_ENEMY1, AVAR_Unk_9, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
                EVT_WAIT(30)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
        EVT_CASE_OR_EQ(EVENT_DEATH)
        EVT_CASE_OR_EQ(EVENT_BURN_DEATH)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(onDeath))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(onHit) = {
    EVT_EXEC_WAIT(N(shake_tank))
    EVT_RETURN
    EVT_END
};

EvtScript N(shake_tank) = {
    EVT_CALL(GetActorVar, ACTOR_ENEMY1, AVAR_Unk_9, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(PlayModelAnimation, 0, EVT_PTR(toy_tank_as_close_hatch))
        EVT_WAIT(30)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

API_CALLABLE(func_80218250_52B8F0) {
    s32 i;
    IceShardBlueprint bpArray[] = {
        {
            .unk_00 = 1,
            .unk_04 = 117.0f,
            .unk_08 = 102.0f,
            .unk_0C = 0.0f,
            .unk_10 = 0.2f,
            .unk_14 = 20,
            .unk_18 = 0.3f,
            .unk_1C = 0.7f,
            .unk_20 = 0.0f,
            .unk_24 = -0.3f,
        },
        {
            .unk_00 = 0,
            .unk_04 = 117.0f,
            .unk_08 = 82.0f,
            .unk_0C = 11.0f,
            .unk_10 = 0.5f,
            .unk_14 = 20,
            .unk_18 = 0.3f,
            .unk_1C = 0.9f,
            .unk_20 = 0.1f,
            .unk_24 = -0.3f,
        },
        {
            .unk_00 = 0,
            .unk_04 = 117.0f,
            .unk_08 = 92.0f,
            .unk_0C = 14.0f,
            .unk_10 = 0.4f,
            .unk_14 = 20,
            .unk_18 = 0.3f,
            .unk_1C = 0.8f,
            .unk_20 = 0.3f,
            .unk_24 = -0.3f,
        },
        {
            .unk_00 = 1,
            .unk_04 = 125.0f,
            .unk_08 = 82.0f,
            .unk_0C = 0.0f,
            .unk_10 = 0.2f,
            .unk_14 = 20,
            .unk_18 = 0.5f,
            .unk_1C = 0.9f,
            .unk_20 = 0.0f,
            .unk_24 = -0.3f,
        },
        {
            .unk_00 = 0,
            .unk_04 = 108.0f,
            .unk_08 = 82.0f,
            .unk_0C = 0.0f,
            .unk_10 = 0.3f,
            .unk_14 = 20,
            .unk_18 = -0.2f,
            .unk_1C = 0.9f,
            .unk_20 = 0.0f,
            .unk_24 = -0.3f,
        },
        {
            .unk_00 = 0,
            .unk_04 = 105.0f,
            .unk_08 = 92.0f,
            .unk_0C = 0.0f,
            .unk_10 = 0.4f,
            .unk_14 = 20,
            .unk_18 = -0.1f,
            .unk_1C = 0.8f,
            .unk_20 = 0.0f,
            .unk_24 = -0.3f,
        },
        {
            .unk_00 = 1,
            .unk_04 = 127.0f,
            .unk_08 = 92.0f,
            .unk_0C = 0.0f,
            .unk_10 = 0.2f,
            .unk_14 = 20,
            .unk_18 = 0.7f,
            .unk_1C = 0.8f,
            .unk_20 = 0.0f,
            .unk_24 = -0.3f,
        },
        {
            .unk_00 = 0,
            .unk_04 = 117.0f,
            .unk_08 = 97.0f,
            .unk_0C = 7.0f,
            .unk_10 = 0.1f,
            .unk_14 = 20,
            .unk_18 = 0.7f,
            .unk_1C = 0.8f,
            .unk_20 = 0.2f,
            .unk_24 = -0.3f,
        },
        {
            .unk_00 = 0,
            .unk_04 = 117.0f,
            .unk_08 = 87.0f,
            .unk_0C = 7.0f,
            .unk_10 = 0.3f,
            .unk_14 = 20,
            .unk_18 = 0.7f,
            .unk_1C = 0.8f,
            .unk_20 = 0.2f,
            .unk_24 = -0.3f,
        },
        {
            .unk_00 = 0,
            .unk_04 = 111.0f,
            .unk_08 = 97.0f,
            .unk_0C = 3.0f,
            .unk_10 = 0.2f,
            .unk_14 = 20,
            .unk_18 = 0.0f,
            .unk_1C = 1.0f,
            .unk_20 = 0.1f,
            .unk_24 = -0.3f,
        },
        {
            .unk_00 = 0,
            .unk_04 = 111.0f,
            .unk_08 = 92.0f,
            .unk_0C = 7.0f,
            .unk_10 = 0.1f,
            .unk_14 = 20,
            .unk_18 = 0.0f,
            .unk_1C = 1.0f,
            .unk_20 = 0.2f,
            .unk_24 = -0.3f,
        },
        {
            .unk_00 = 0,
            .unk_04 = 111.0f,
            .unk_08 = 87.0f,
            .unk_0C = 3.0f,
            .unk_10 = 0.5f,
            .unk_14 = 20,
            .unk_18 = 0.0f,
            .unk_1C = 1.0f,
            .unk_20 = 0.1f,
            .unk_24 = -0.3f,
        },
        {
            .unk_00 = 1,
            .unk_04 = 123.0f,
            .unk_08 = 97.0f,
            .unk_0C = 3.0f,
            .unk_10 = 0.2f,
            .unk_14 = 20,
            .unk_18 = 0.1f,
            .unk_1C = 1.0f,
            .unk_20 = 0.1f,
            .unk_24 = -0.3f,
        },
        {
            .unk_00 = 0,
            .unk_04 = 123.0f,
            .unk_08 = 92.0f,
            .unk_0C = 7.0f,
            .unk_10 = 0.4f,
            .unk_14 = 20,
            .unk_18 = 0.1f,
            .unk_1C = 1.0f,
            .unk_20 = 0.2f,
            .unk_24 = -0.3f,
        },
        {
            .unk_00 = 0,
            .unk_04 = 123.0f,
            .unk_08 = 87.0f,
            .unk_0C = 3.0f,
            .unk_10 = 0.3f,
            .unk_14 = 20,
            .unk_18 = 0.1f,
            .unk_1C = 1.0f,
            .unk_20 = 0.1f,
            .unk_24 = -0.3f,
        },
    };

    for (i = 0; i < ARRAY_COUNT(bpArray); i++) {
        EffectInstance* effect = fx_ice_shard(bpArray[i].unk_00, bpArray[i].unk_04, bpArray[i].unk_08,
                                              bpArray[i].unk_0C, bpArray[i].unk_10, bpArray[i].unk_14);
        effect->data.iceShard->vel.x = bpArray[i].unk_18;
        effect->data.iceShard->vel.y = bpArray[i].unk_1C;
        effect->data.iceShard->vel.z = bpArray[i].unk_20;
        effect->data.iceShard->gravAccel = bpArray[i].unk_24;
    }

    return ApiStatus_DONE2;
}

EvtScript N(onDeath) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY2, SOUND_03AE)
    EVT_CALL(func_80218250_52B8F0)
    EVT_CALL(EnableModel, 39, FALSE)
    EVT_CALL(EnableModel, 41, FALSE)
    EVT_CALL(GetActorVar, ACTOR_ENEMY1, AVAR_Unk_5, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(RemoveEffect, LVar0)
        EVT_CALL(SetActorVar, ACTOR_ENEMY1, AVAR_Unk_5, 0)
    EVT_END_IF
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
