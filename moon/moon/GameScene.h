//
//  GameScene.h
//  AboutFuture
//
//  Created by 杨 奕 on 13-6-1.
//
//

#ifndef __AboutFuture__GameScene__
#define __AboutFuture__GameScene__

#include "cocos2d.h"
#include "GameLayer.h"
#include "HudLayer.h"

USING_NS_CC;
class GameScene :public CCScene{


public:
    GameScene(void);
	~GameScene(void);
	CC_SYNTHESIZE(GameLayer*, _gameLayer, GameLayer);
	CC_SYNTHESIZE(HudLayer*, _hudLayer, HudLayer);
    
    CREATE_FUNC(GameScene);
    virtual bool init();
    static CCScene* scene();
    
    
};



#endif /* defined(__AboutFuture__GameScene__) */

