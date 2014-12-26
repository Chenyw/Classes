#include "GameScene.h"
USING_NS_CC;

GameScene::GameScene()
:m_player(NULL)
{
}

GameScene::~GameScene()
{
}

CCScene *GameScene::createScene()
{
	CCScene *p = CCScene::create();
	GameScene *layer = GameScene::create();
	p->addChild(layer);
	return p;

}

bool GameScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	setTouchEnabled(true);
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Character/zhaoyu.plist", "Character/zhaoyu.png");  
  	CCSprite *playerSp = CCSprite::createWithSpriteFrameName("idle0.png");
	if (playerSp)
	{
		playerSp->setPosition(ccp(playerSp->getContentSize().width/2, origin.y + visibleSize.height/2));
		this->addChild(playerSp, 1, 99);
	}

	CCArray *arrayFrames = CCArray::create();
	char str[256] = {0};
	for (int i = 0; i <= 11; i++)
	{
		sprintf(str, "idle%d.png", i);
		CCSpriteFrame *pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
		arrayFrames->addObject(pFrame);
	}

	CCAnimation *pAnimation = CCAnimation::createWithSpriteFrames(arrayFrames);
	pAnimation->setDelayPerUnit(1.0f/12.0f);
	CCAnimate *pAnimate = CCAnimate::create(pAnimation);
	playerSp->runAction(CCRepeatForever::create(pAnimate));
	arrayFrames->release();
	return true;
}

void GameScene::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -128, false);
}

bool GameScene::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	CCPoint touchPoint = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
	m_player = (CCSprite *)this->getChildByTag(99);
	m_player->stopAllActions();
	//m_player->setPosition(touchPoint);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Character/zhaoyu.plist", "Character/zhaoyu.png");
	CCArray *array = CCArray::createWithCapacity(0);
	char str[256] = {0};
	for (int i = 0; i <= 6; i++)
	{
		 sprintf(str, "walk%d.png", i);
		 CCSpriteFrame *pFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
		 array->addObject(pFrame);
	}
	CCAnimation *pAnimation = CCAnimation::createWithSpriteFrames(array);
	pAnimation->setDelayPerUnit(1.0f/8.0f);
	pAnimation->setRestoreOriginalFrame(true);
	CCAnimate *animate = CCAnimate::create(pAnimation);
	m_player->runAction(CCRepeatForever::create(animate));
	CCMoveTo *to = CCMoveTo::create(5.0f, touchPoint);
	CCSpawn *spawn = CCSpawn::create(animate, to, NULL);

	m_player->runAction(spawn);
	array->release();

	return true;
}

void GameScene::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{

}

void GameScene::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	m_player->stopAllActions();
	CCArray *array = CCArray::createWithCapacity(0);
	char str[256] = {0};
	for (int i = 0; i <= 14; i++)
	{
		sprintf(str, "attack%d.png", i);
		CCSpriteFrame *frames = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
		array->addObject(frames);
	}
	CCAnimation *animation = CCAnimation::createWithSpriteFrames(array);
	animation->setDelayPerUnit(1.0f / 14.0f);
	animation->setRestoreOriginalFrame(true);
	m_player->runAction(CCRepeatForever::create(CCAnimate::create(animation)));

	
}