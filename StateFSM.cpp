#include "StateFSM.h"
#include "PlayerState.h"
#include "I_State.h"
#include "EnumMsgType.h"

#define NOTIFY CCNotificationCenter::sharedNotificationCenter()

StateFSM::~StateFSM() {
    NOTIFY->removeObserver(this, "AttackState");
    NOTIFY->removeObserver(this, "IdleState");
    NOTIFY->removeObserver(this, "WalkState");
}

StateFSM* StateFSM::createWithStateFSM( PlayerState* playerState ) {
    StateFSM* fsm = new StateFSM();

    if(fsm && fsm->initWithStateFSM(playerState)) {
        fsm->autorelease();
    }
    else {
        CC_SAFE_DELETE(fsm);
        fsm = NULL;
    }

    return fsm;
}

bool StateFSM::initWithStateFSM( PlayerState* playerState ) {
    this->mCurState = NULL;
    this->m_playerState = playerState;
    m_playerState->retain();

    /* ¶©ÔÄÏûÏ¢ */
    NOTIFY->addObserver(this,callfuncO_selector(StateFSM::onRecvAttackState) , "AttackState", NULL);
    NOTIFY->addObserver(this,callfuncO_selector(StateFSM::onRecvIdleState) , "IdleState", NULL);
    NOTIFY->addObserver(this,callfuncO_selector(StateFSM::onRecvWalkState) , "WalkState", NULL);
    return true;
}

void StateFSM::changeState( I_State* state ) {
    CC_SAFE_DELETE(mCurState);

    this->mCurState = state;
    
}
void StateFSM::onRecvAttackState( CCObject* obj ) {
    this->mCurState->execute(m_playerState, en_Msg_AttackState);
}

void StateFSM::onRecvIdleState( CCObject* obj ) {
    this->mCurState->execute(m_playerState, en_Msg_IdleState);
}

void StateFSM::onRecvWalkState( CCObject* obj ) {
    this->mCurState->execute(m_playerState, en_Msg_WalkState);
}