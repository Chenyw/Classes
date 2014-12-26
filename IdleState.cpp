#include "IdleState.h"
#include "AttackState.h"
#include "PlayerState.h"
#include "EnumMsgType.h"

void IdleState::execute( PlayerState* playerState, EnumMsgType enMsgType ) {
    switch(enMsgType) {
    case en_Msg_AttackState:
        playerState->walkState();
        playerState->getFSM()->changeState(new AttackState());
        break;
    }
}
