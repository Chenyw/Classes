/*
    文件名：    State.h
    描　述：    状态基类
    创建人：    笨木头 (CSDN博客：http://blog.csdn.net/musicvs)

    创建日期：   2012.12.17
    修改日期：   2012.12.20
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