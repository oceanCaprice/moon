//
//  HudLayer.h
//  AboutFuture
//
//  Created by 杨 奕 on 13-6-1.
//
//

#ifndef __AboutFuture__HudLayer__
#define __AboutFuture__HudLayer__

#include "cocos2d.h"
#include "DPad.h"

USING_NS_CC;
class HudLayer :public CCLayer{
    
    
public:
    HudLayer();
    virtual ~HudLayer();
    CREATE_FUNC(HudLayer);
    virtual bool init();
    
    CC_SYNTHESIZE(SimpleDPad*, _dPad, DPad);
    
    
};


#endif /* defined(__AboutFuture__HudLayer__) */
