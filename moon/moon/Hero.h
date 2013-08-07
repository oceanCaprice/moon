//
//  Hero.h
//  AboutFuture
//
//  Created by 杨 奕 on 13-6-1.
//
//

#ifndef __AboutFuture__Hero__
#define __AboutFuture__Hero__

#include "BaseGameRole.h"
#include "StateMachine.h"
#include "HeroOwnedState.h"


USING_NS_CC;




enum HeroState
{
    kHeroStateNone,
    kHeroStateIdle,
    kHeroStateAttack,
    kHeroStateWalk,
    kHeroStateJump
};

class Hero : public BaseGameRole
{
    
private:
    /**
     * an instance of the state machine class
     */
    StateMachine<Hero> *m_pStateMachine;
    
    virtual bool init();
    
public:
    CREATE_FUNC(Hero);
    Hero()
    {
        m_pStateMachine = new StateMachine<Hero>(this);
    }
    
    ~Hero(){delete m_pStateMachine;}
    
    virtual void update(float delta);//from parent
    
    
    CC_SYNTHESIZE(CCPoint, direction, Direction);
    CC_SYNTHESIZE(HeroState, heroState, HeroState);
    CC_SYNTHESIZE_RETAIN(CCAction*, idleAction, IdleAction);
	CC_SYNTHESIZE_RETAIN(CCAction*, attackAction, AttackAction);
	CC_SYNTHESIZE_RETAIN(CCAction*, walkAction, WalkAction);
    CC_SYNTHESIZE_RETAIN(CCAction*, jumpAction, JumpAction);
    
    
    StateMachine<Hero>* getFSM()const
    {
        CCAssert(m_pStateMachine, "FSM is null");
        return m_pStateMachine;
    }
    
    

};

#endif /* defined(__AboutFuture__Hero__) */
