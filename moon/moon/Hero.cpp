//
//  Hero.cpp
//  AboutFuture
//
//  Created by 杨 奕 on 13-6-1.
//
//

#include "Hero.h"
#include "DeBug.h"

bool Hero::init()
{
    
    if (!BaseGameRole::initWithSpriteFrameName("hero_idle_0.png")) {
        return false;
    }
    //属性初始化
    _centerToBottom = 39.0;
    _centerToSides = 29.0;

    
    //角色动画配置
    //idle
    CCArray *idleFrames = CCArray::createWithCapacity(2);
    for (int i=0; i<2; i++)
    {
        CCString *temp = CCString::createWithFormat("hero_idle_%d.png",i);
        CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(temp->getCString());

        idleFrames->addObject(frame);
    }
    CCAnimation *idleAnimation = CCAnimation::createWithSpriteFrames(idleFrames,1.0/4);
    this->setIdleAction(CCRepeatForever::create(CCAnimate::create(idleAnimation)));
  
    
    //attack
    CCArray *attackFrames = CCArray::createWithCapacity(6);
    for (int i=0; i<6; i++)
    {
        CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("攻击/hero_attack_%d.png",i)->getCString());
        attackFrames->addObject(frame);
    }
    CCAnimation *attackAnimation = CCAnimation::createWithSpriteFrames(attackFrames,1.0/12);
    this->setAttackAction(CCAnimate::create(attackAnimation));

    
    //walk
    CCArray *walkFrames = CCArray::createWithCapacity(8);
    for (int i=0; i<8; i++)
    {
        CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("跑动/hero_run_%d.png",i)->getCString());
        walkFrames->addObject(frame);
    }
    CCAnimation *walkAnimation = CCAnimation::createWithSpriteFrames(walkFrames,1.0/12);
    this->setWalkAction(CCRepeatForever::create(CCAnimate::create(walkAnimation)));

    //jump
    CCArray *jumpFrames = CCArray::createWithCapacity(8);
    for (int i=0; i<8; i++)
    {
        CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(CCString::createWithFormat("跳跃/hero_jump_%d.png",i)->getCString());
        jumpFrames->addObject(frame);
    }
    CCAnimation *jumpAnimation = CCAnimation::createWithSpriteFrames(jumpFrames,1.0/12);
    this->setJumpAction(CCAnimate::create(jumpAnimation));
    
    
    this->scheduleUpdate();
    return true;
    
}

void Hero::update(float delta)
{
    m_pStateMachine->update();
}