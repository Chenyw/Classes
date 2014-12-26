#include "AttackState.h"
#include "WalkState.h"
#include "IdleState.h"
#include "PlayerState.h"
#include "EnumMsgType.h"

void AttackState::execute( PlayerState* playerState, EnumMsgType enMsgType ) {
    switch(enMsgType) {
    case en_Msg_IdleState:
        playerState->idleState();
        playerState->getFSM()->changeState(new IdleState());
        break;
    case en_Msg_WalkState:
        playerState->attackState();
        playerState->getFSM()->changeState(new WalkState());
        break;
    }
}
