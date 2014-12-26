#include "WelComeScene.h"
#include "GameScene.h"
USING_NS_CC;

WelComeScene::WelComeScene()
{
}

WelComeScene::~WelComeScene()
{
}

CCScene *WelComeScene::createScene()
{
	CCScene *p = CCScene::create();
	WelComeScene *layer = WelComeScene::create();
	p->addChild(layer);
	return p;
}

bool WelComeScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCMenuItemImage *startGameBtn = CCMenuItemImage::create("CloseNormal.png",
		"CloseSelected.png",
		this,
		menu_selector(WelComeScene::startGameCallBack));
	startGameBtn->setPosition(ccp(origin.x + visibleSize.width/2 - startGameBtn->getContentSize().width/2 ,
		origin.y + visibleSize.height / 2 + startGameBtn->getContentSize().height/2));
	CCMenu *pMenu = CCMenu::create(startGameBtn, NULL);
	pMenu->setPosition(CCPointZero);
	addChild(pMenu);

	return true;
}

void WelComeScene::startGameCallBack(CCObject *pSender)
{
	CCDirector::sharedDirector()->purgeCachedData();
	CCScene *p = GameScene::createScene();
	CCDirector::sharedDirector()->replaceScene(p);

}

