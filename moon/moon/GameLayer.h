//
//  GameLayer.h
//  AboutFuture
//
//  Created by 杨 奕 on 13-6-1.
//
//

#ifndef __AboutFuture__GameLayer__
#define __AboutFuture__GameLayer__

#include "cocos2d.h"
#include "Hero.h"
#include "HudLayer.h"
#include "DPad.h"
USING_NS_CC;
class GameLayer :public CCLayer ,public SimpleDPadDelegate{



public:
    CCSpriteBatchNode *actors;
    
    CCTMXTiledMap   *tileMap;
    CCTMXLayer      *testLayer1;
    
    Hero *hero;
    CC_SYNTHESIZE(HudLayer*, _hud, Hud);

    GameLayer();
    virtual ~GameLayer();
    CREATE_FUNC(GameLayer);

    virtual bool init();
    void initTileMap();
    void initHero();

    //touches
    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    
    //daili
	virtual void didChangeDirectionTo(SimpleDPad *simpleDPad, cocos2d::CCPoint direction);
	virtual void isHoldingDirection(SimpleDPad *simpleDPad, cocos2d::CCPoint direction);
	virtual void simpleDPadTouchEnded(SimpleDPad *simpleDPad);
    
    void update(float delta);
    void updatePositions();
    void setViewPointCenter(CCPoint position);

};
#endif /* defined(__AboutFuture__GameLayer__) */
