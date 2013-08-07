//
//  DPad.h
//  AboutFuture
//
//  Created by 杨 奕 on 13-6-3.
//
//

#ifndef __AboutFuture__DPad__
#define __AboutFuture__DPad__

#include "cocos2d.h"
using namespace cocos2d;

class SimpleDPad;

class SimpleDPadDelegate
{
public:
	virtual void didChangeDirectionTo(SimpleDPad *simpleDPad, CCPoint direction) = 0;
	virtual void isHoldingDirection(SimpleDPad *simpleDPad, CCPoint direction) = 0;
	virtual void simpleDPadTouchEnded(SimpleDPad *simpleDPad) = 0;
};

class SimpleDPad : public CCSprite, public CCTargetedTouchDelegate
{
public:
	SimpleDPad(void);
	~SimpleDPad(void);
    
	static SimpleDPad* dPadWithFile(CCString *fileName, float radius);
	bool initWithFile(CCString *filename, float radius);
    
	void onEnterTransitionDidFinish();
	void onExit();
	void update(float dt);
    
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    
	void updateDirectionForTouchLocation(CCPoint location);
    
	CC_SYNTHESIZE(SimpleDPadDelegate*, _delegate, Delegate);
	CC_SYNTHESIZE(bool, _isHeld, IsHeld);
    
protected:
	float _radius;
	CCPoint _direction;
};
#endif /* defined(__AboutFuture__DPad__) */
