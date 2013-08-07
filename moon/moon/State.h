
/*
 *------------------------------------------------------------------------
 *
 *  Name:   State
 *
 *  Desc:   State
 *
 *  Author: Yi Yang 08/02/2013
 *  
 *------------------------------------------------------------------------
 */
#ifndef __AboutFuture__State__
#define __AboutFuture__State__



template <class entity_type>
class State
{
public:
    
  virtual ~State(){};

  //this will execute when the state is entered
  virtual void stateEnter(entity_type*)=0;

  //this is the states normal update function
  virtual void stateExecute(entity_type*)=0;

  //this will execute when the state is exited. (My word, isn't
  //life full of surprises... ;o))
  virtual void stateExit(entity_type*)=0;
};

#endif