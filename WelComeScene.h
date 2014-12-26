#pragma once
#include "cocos2d.h"

class WelComeScene : public cocos2d::CCLayer
{
public:
	WelComeScene();
	~WelComeScene();
	static cocos2d::CCScene *createScene();
	virtual bool init();
	CREATE_FUNC(WelComeScene);
public:
	void startGameCallBack(cocos2d::CCObject *pSender);


};