/*
    �ļ�����    State.h
    �衡����    ״̬����
    �����ˣ�    ��ľͷ (CSDN���ͣ�http://blog.csdn.net/musicvs)

    �������ڣ�   2012.12.17
    �޸����ڣ�   2012.12.20
*/
#ifndef __I_STATE_H__
#define __I_STATE_H__

#include "EnumMsgType.h"

class PlayerState;

class I_State {
public:
    virtual void execute(PlayerState* playerState, EnumMsgType enMsgType) = 0;
};

#endif