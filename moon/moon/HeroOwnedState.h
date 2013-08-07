/*
 *------------------------------------------------------------------------
 *
 *  Name:   HeroOwnedState
 *
 *  Desc:   all state  implment of hero
 *
 *  Author: Yi Yang 08/02/2013
 *
 *------------------------------------------------------------------------
 */

#ifndef __AboutFuture__HeroOwnedState__
#define __AboutFuture__HeroOwnedState__

#include "State.h"

class Hero;

/**
 * @Class: StateIdle
 * @description: hero idle state
 */
class StateIdle : public State<Hero>
{
private:
    StateIdle(){};
    
    /**
     * copy ctor and assignment should be private
     */
    StateIdle(const StateIdle&);
    StateIdle& operator = (const StateIdle&);
    
    
    
public:
    static StateIdle* getInstance();
    
    virtual void stateEnter(Hero* hero);
    virtual void stateExecute(Hero* hero);
    virtual void stateExit(Hero* hero);
};


/**
 * @Class: StateAttack
 * @description: hero attack state
 */
class StateAttack : public State<Hero>
{
private:
    StateAttack(){};
    
    /**
     * copy ctor and assignment should be private
     */
    StateAttack(const StateAttack&);
    StateAttack& operator = (const StateAttack&);
    
    
    
public:
    static StateAttack* getInstance();
    
    virtual void stateEnter(Hero* hero);
    virtual void stateExecute(Hero* hero);
    virtual void stateExit(Hero* hero);
};

/**
 * @Class: StateWalk
 * @description: hero walk state
 */
class StateWalk : public State<Hero>
{
private:
    StateWalk(){};
    
    /**
     * copy ctor and assignment should be private
     */
    StateWalk(const StateWalk&);
    StateWalk& operator = (const StateWalk&);
    
    
    
public:
    static StateWalk* getInstance();
    

    virtual void stateEnter(Hero* hero);
    virtual void stateExecute(Hero* hero);
    virtual void stateExit(Hero* hero);
};

/**
 * @Class: StateJump
 * @description: hero Jump state
 */
class StateJump : public State<Hero>
{
private:
    StateJump(){};
    
    /**
     * copy ctor and assignment should be private
     */
    StateJump(const StateJump&);
    StateJump& operator = (const StateJump&);
    
    
    
public:
    static StateJump* getInstance();
    
    virtual void stateEnter(Hero* hero);
    virtual void stateExecute(Hero* hero);
    virtual void stateExit(Hero* hero);
};

#endif /* defined(__AboutFuture__HeroOwnedState__) */
