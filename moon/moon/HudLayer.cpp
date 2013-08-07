//
//  HudLayer.cpp
//  AboutFuture
//
//  Created by 杨 奕 on 13-6-1.
//
//

#include "HudLayer.h"
HudLayer::HudLayer(){}
HudLayer::~HudLayer(){}

bool HudLayer::init()
{
    
    if (!CCLayer::init()) {
        return false;
    }
    
    
    _dPad = SimpleDPad::dPadWithFile(CCString::create("pd_dpad.png"), 64);
    _dPad->setPosition(ccp(64.0, 64.0));
    _dPad->setOpacity(100);
    this->addChild(_dPad);
    return true;
}