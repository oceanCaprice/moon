//
//  GameLayer.cpp
//  AboutFuture
//
//  Created by 杨 奕 on 13-6-1.
//
//

#include "GameLayer.h"
GameLayer::GameLayer(void)
{
	tileMap = NULL;
	hero = NULL;
}

GameLayer::~GameLayer(void)
{
}
bool GameLayer::init()
{
    if (!CCLayer::init()) {
        return false;
    }

    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("hero.plist");
    
    actors = CCSpriteBatchNode::create("hero.pvr.ccz");
    actors->getTexture()->setAliasTexParameters();
    this->addChild(actors,-5);
    this->initTileMap();

    this->initHero();
    
    
    this->setTouchEnabled(true);
    
    this->scheduleUpdate();
    return true;
}

void GameLayer::updatePositions()
{
    float posX = MIN(tileMap->getMapSize().width * tileMap->getTileSize().width - hero->getCenterToSides(), MAX(hero->getCenterToSides(), hero->getDesiredPosition().x));
/*Y轴横板
   float posY = MIN(3 * tileMap->getTileSize().height + hero->getCenterToBottom(), MAX(hero->getCenterToBottom(), hero->getDesiredPosition().y));
*/
    hero->setPosition(ccp(posX, hero->getPositionY()));
}

void GameLayer::setViewPointCenter(CCPoint position)
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    
    
    //限制边界
    int x = MAX(position.x, winSize.width/2);
    int y = MAX(position.y, winSize.height/2);
    
    // x,
    x = MIN(x,(tileMap->getMapSize().width * tileMap->getTileSize().width) - winSize.width / 2);
    y = MIN(y, (tileMap->getMapSize().height * tileMap->getTileSize().height) - winSize.height / 2);

    
    CCPoint actualPosition = ccp(x, y);
    
    CCPoint centerOfView = ccp(winSize.width/2, winSize.height/2);
    CCPoint viewPoint = ccpSub(centerOfView, actualPosition);
    this->setPosition(viewPoint);

}



void GameLayer::update(float delta)
{
    this->updatePositions();
    this->setViewPointCenter(hero->getPosition());
}

void GameLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	hero->getFSM()->changeState(StateAttack::getInstance());
}

//行走状态 方向参数待添加
void GameLayer::didChangeDirectionTo(SimpleDPad *simpleDPad, CCPoint direction)
{
    CCPoint checkDirectionIsTop = ccp(0.0, 1.0);
    if (direction.equals(checkDirectionIsTop))
    {
        hero->getFSM()->changeState(StateJump::getInstance());
    }
    else
    {
        //设置方向,
        hero->setDirection(direction);
        hero->getFSM()->changeState(StateWalk::getInstance());
    }
}

void GameLayer::isHoldingDirection(SimpleDPad *simpleDPad, CCPoint direction)
{
    hero->setDirection(direction);

}

void GameLayer::simpleDPadTouchEnded(SimpleDPad *simpleDPad)
{
    if (hero->getFSM()->isInState(*StateWalk::getInstance()))
    {
        hero->getFSM()->changeState(StateIdle::getInstance());
    }

}

void GameLayer::initHero()
{
    hero = Hero::create();
    actors->addChild(hero);
    CCTMXObjectGroup *object = tileMap->objectGroupNamed("object1");
    CCAssert(object, "objects group not found");
    CCDictionary *spawnPoint = object->objectNamed("SpawnPoint");
    CCAssert(spawnPoint, "SpawnPoint object not found");
    int x = spawnPoint->valueForKey("x")->intValue();
    int y = spawnPoint->valueForKey("y")->intValue();

    hero->setPosition(ccp(x, y));
    hero->getFSM()->changeState(StateIdle::getInstance());
    
    
}

void GameLayer::initTileMap()
{
 
    tileMap = CCTMXTiledMap::create("GameScene.tmx");
    testLayer1 = tileMap->layerNamed("1");

    
    
    
    
    CCArray * pChildrenArray = tileMap->getChildren();
    CCSpriteBatchNode* child = NULL;
    CCObject* pObject = NULL;
    //遍历Tilemap的所有图层
    CCARRAY_FOREACH(pChildrenArray, pObject)
    {
        child = (CCSpriteBatchNode*)pObject;
        if(!child)
            break;
        //给图层的纹理关闭抗锯齿
        child->getTexture()->setAliasTexParameters();
    }
    this->addChild(tileMap,-6);
}