#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_trd_part_1_trd_02d

EvtScript N(80224CA0) = {
    EVT_SET(LW(10), LW(0))
    EVT_LABEL(0)
    EVT_CALL(RotateGroup, LW(10), 2, 0, 0, 1)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(RotateGroup, LW(10), 1, 0, 0, 1)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(RotateGroup, LW(10), -2, 0, 0, 1)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(RotateGroup, LW(10), 1, 0, 0, 1)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(RandInt, 30, LW(0))
    EVT_ADD(LW(0), 30)
    EVT_WAIT_FRAMES(LW(0))
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(80224DB8) = {
    EVT_SET(LW(10), LW(0))
    EVT_LOOP(0)
        EVT_CALL(TranslateModel, LW(10), 1, 0, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 1, 0, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), 1, EVT_FLOAT(-0.5), 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), 1, -1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), EVT_FLOAT(1.5), -1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), 2, -1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 2, -1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 2, -1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), EVT_FLOAT(2.5), EVT_FLOAT(-1.5), 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), 3, -2, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 3, -2, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), 3, EVT_FLOAT(-2.5), 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), 3, -3, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 3, -3, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), 3, -3, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), 3, EVT_FLOAT(-2.5), 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), 3, -2, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), EVT_FLOAT(2.5), -2, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), 2, -2, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), 2, EVT_FLOAT(-1.5), 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), 2, -1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), EVT_FLOAT(1.5), EVT_FLOAT(-0.5), 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), 1, 0, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), 1, EVT_FLOAT(0.5), 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), 1, 1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), EVT_FLOAT(0.5), 1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), 0, 1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), EVT_FLOAT(-0.5), 1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), -1, 1, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), -1, 1, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), -1, EVT_FLOAT(0.5), 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), -1, 0, 0)
        EVT_WAIT_FRAMES(2)
        EVT_CALL(TranslateModel, LW(10), -1, 0, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), EVT_FLOAT(-0.5), 0, 0)
        EVT_WAIT_FRAMES(1)
        EVT_CALL(TranslateModel, LW(10), 0, 0, 0)
        EVT_WAIT_FRAMES(2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(beforeBattle_80225364) = {
    EVT_CALL(SetSpriteShading, -1)
    EVT_CALL(SetCamBGColor, 1, 0, 0, 0)
    EVT_CALL(EnableModel, 19, 0)
    EVT_CALL(EnableModel, 17, 0)
    EVT_CALL(EnableModel, 15, 0)
    EVT_CALL(EnableModel, 13, 0)
    EVT_CALL(EnableModel, 9, 0)
    EVT_CALL(EnableModel, 10, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(afterBattle_80225418) = {
    EVT_RETURN
    EVT_END
};

s32 N(foregroundModelList_80225428)[] = {
    0x00000016, 0x00000000,
};

Stage NAMESPACE = {
    .texture = "trd_tex",
    .shape = "trd_bt02_shape",
    .hit = "trd_bt02_hit",
    .preBattle = &N(beforeBattle_80225364),
    .postBattle = &N(afterBattle_80225418),
    .foregroundModelList = N(foregroundModelList_80225428),
};
