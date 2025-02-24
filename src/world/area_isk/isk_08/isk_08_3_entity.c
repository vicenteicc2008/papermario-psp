#include "isk_08.h"
#include "effects.h"

EvtScript N(EVS_SetupFlames) = {
    EVT_PLAY_EFFECT(EFFECT_FLAME, 1, -358, -323, 358, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, 1, -459, -323, 214, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, 1, -358, -453, 358, EVT_FLOAT(0.3), LVar0)
    EVT_PLAY_EFFECT(EFFECT_FLAME, 1, -459, -453, 214, EVT_FLOAT(0.3), LVar0)
    EVT_RETURN
    EVT_END
};

BombTrigger N(BombPos_Wall) = {
    .pos = { -569.0f, -520.0f, 207.0f },
    .radius = 0.0f
};

EvtScript N(EVS_OnBlast_Wall) = {
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 36, 12, 1, 10, 30)
    EVT_LOOP(10)
        EVT_CALL(EnableModel, MODEL_g293, TRUE)
        EVT_WAIT(1)
        EVT_CALL(EnableModel, MODEL_g293, FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_ISK_BombedWallFrom08, TRUE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HideDestroyedWall) = {
    EVT_CALL(EnableModel, MODEL_o2012, FALSE)
    EVT_CALL(EnableModel, MODEL_o2019, FALSE)
    EVT_CALL(EnableModel, MODEL_o2021, FALSE)
    EVT_CALL(EnableModel, MODEL_o2018, FALSE)
    EVT_CALL(EnableModel, MODEL_o2020, FALSE)
    EVT_CALL(EnableModel, MODEL_o2022, FALSE)
    EVT_CALL(EnableModel, MODEL_o2023, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2029, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2030, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2032, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupBombableWall) = {
    EVT_IF_EQ(GF_ISK_BombedWallFrom08, FALSE)
        EVT_IF_EQ(GF_ISK_BombedWallFrom10, FALSE)
            EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnBlast_Wall)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Wall)), 1, 0)
            EVT_EXEC_WAIT(N(EVS_HideDestroyedWall))
        EVT_ELSE
            EVT_CALL(EnableModel, MODEL_g293, FALSE)
            EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittw, COLLIDER_FLAGS_UPPER_MASK)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_g293, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittw, COLLIDER_FLAGS_UPPER_MASK)
        EVT_EXEC_WAIT(N(EVS_HideDestroyedWall))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
