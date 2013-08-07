//
//  HeroOwnedState.cpp
//  AboutFuture
//
//  Created by kingnet on 13-8-2.
//
//

#include "HeroOwnedState.h"
#include "Hero.h"
#include "State.h"


/**
 * idle state
 */
StateIdle* StateIdle::getInstance()
{
    static StateIdle instance;
    return &instance;
}
void StateIdle::stateEnter(Hero* pHero)
{
    pHero->stopAllActions();
    pHero->runAction(pHero->getIdleAction());
}
void StateIdle::stateExecute(Hero* pHero)
{
}
void StateIdle::stateExit(Hero* pHero)
{
}


/**
 * attack state
 */
StateAttack* StateAttack::getInstance()
{
    static StateAttack instance;
    return &instance;
}
void StateAttack::stateEnter(Hero* pHero)
{
    pHero->stopAllActions();
    pHero->runAction(pHero->getAttackAction());
}
void StateAttack::stateExecute(Hero* pHero)
{
    /**
     * back previous state if state is done
     */
    if (pHero->getAttackAction()->isDone())
    {
        pHero->getFSM()->backToPreviousState();
    }
}
void StateAttack::stateExit(Hero* pHero)
{
   
}

/**
 * walk state
 */
StateWalk* StateWalk::getInstance()
{
    static StateWalk instance;
    return &instance;
}
void StateWalk::stateEnter(Hero* pHero)
{
    pHero->stopAllActions();
    pHero->runAction(pHero->getWalkAction());
}
void StateWalk::stateExecute(Hero* pHero)
{
    if (pHero->getDirection().x >= 0)
    {
        pHero->setScaleX(1.0);
    }
    else
    {
        pHero->setScaleX(-1.0);
    }
}
void StateWalk::stateExit(Hero* pHero)
{
}


/**
 * jump state
 */
StateJump* StateJump::getInstance()
{
    static StateJump instance;
    return &instance;
}
void StateJump::stateEnter(Hero* pHero)
{
    pHero->stopAllActions();
    pHero->runAction(pHero->getJumpAction());
}
void StateJump::stateExecute(Hero* pHero)
{
    /**
     * back previous state if state is done
     */
    if (pHero->getJumpAction()->isDone())
    {
        pHero->getFSM()->backToPreviousState();
    }
}
void StateJump::stateExit(Hero* pHero)
{

}