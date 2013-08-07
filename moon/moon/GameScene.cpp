//
//  GameScene.cpp
//  AboutFuture
//
//  Created by 杨 奕 on 13-6-1.
//
//

#include "GameScene.h"

GameScene::GameScene(void)
{
	_gameLayer = NULL;
	_hudLayer = NULL;
}

GameScene::~GameScene(void)
{
}

bool GameScene::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!CCScene::init());
        
		_gameLayer = GameLayer::create();
		this->addChild(_gameLayer, 0);
		_hudLayer = HudLayer::create();
		this->addChild(_hudLayer, 1);
		_hudLayer->getDPad()->setDelegate(_gameLayer);
		_gameLayer->setHud(_hudLayer);
        
		bRet = true;
	} while (0);
    
	return bRet;
    
}