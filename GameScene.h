#pragma once
#include "cocos2d.h"


class GameScene : public cocos2d::CCLayer
{
public:
	GameScene();
	~GameScene();
public:
	static cocos2d::CCScene *createScene();
	virtual bool init();
	CREATE_FUNC(GameScene);
private:
	void registerWithTouchDispatcher();
	virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);

private:
	cocos2d::CCSprite *m_player;

};

