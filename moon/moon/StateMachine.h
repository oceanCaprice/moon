/*
 *------------------------------------------------------------------------
 *
 *  Name:   StateMachine
 *
 *  Desc:    StateMachine
 *
 *  Author: Yi Yang 08/02/2013
 *
 *------------------------------------------------------------------------
 */

#ifndef __AboutFuture__StateMachine__
#define __AboutFuture__StateMachine__

#include "cocos2d.h"
#include "State.h"
template <class entity_type>
class StateMachine
{
private:
    //a pointer to the agent that owns this instance
    entity_type*          m_pOwner;
    
    State<entity_type>*   m_pCurrentState;
    
    //a record of the last state the agent was in
    State<entity_type>*   m_pPreviousState;
    
    //this is called every time the FSM is updated
    State<entity_type>*   m_pGlobalState;
    
public:
    StateMachine(entity_type* owner):
    m_pOwner(owner),
    m_pCurrentState(NULL),
    m_pPreviousState(NULL),
    m_pGlobalState(NULL)
    {}
    
    virtual ~StateMachine(){}
    
    //use these methods to initialize the FSM
    void setCurrentState(State<entity_type>* s) {m_pCurrentState = s;}
    void setGlobalState(State<entity_type>* s)  {m_pGlobalState = s;}
    void setPreviousState(State<entity_type>* s){m_pPreviousState = s;}
    /**
     * use these methods to get state
     */
    State<entity_type>*  getCurrentState()  const{return m_pCurrentState;}
    State<entity_type>*  getGlobalState()   const{return m_pGlobalState;}
    State<entity_type>*  getPreviousState() const{return m_pPreviousState;}
    
    void update()const
    {
        //if a global state exists, call its execute method, else do nothing
        if(m_pGlobalState)   m_pGlobalState->stateExecute(m_pOwner);
        
        //same for the current state
        if (m_pCurrentState) m_pCurrentState->stateExecute(m_pOwner);
    }
    
    void changeState(State<entity_type>* pNewState)
    {
        CCAssert(pNewState, "error: new state is null");
        
        //keep a record of the previous state
        m_pPreviousState = m_pCurrentState;
        
        //call the exit method of the existing state
        if (m_pCurrentState) {m_pCurrentState->stateExit(m_pOwner);}
        
        //change state to the new state
        m_pCurrentState = pNewState;
        
        //call the entry method of the new state
        m_pCurrentState->stateEnter(m_pOwner);
    }
    
    
    void backToPreviousState()
    {
        changeState(m_pPreviousState);
    }
    
    
    
    /**
     * returns true if the current state's type is equal to the type of the class passed as a parameter.
     * @param current state
     * @returns bool
     * @exception 
     */
    bool  isInState(const State<entity_type>& st)const
    {
        return typeid(*m_pCurrentState) == typeid(st);
    }


};








#endif /* defined(__AboutFuture__StateMachine__) */
