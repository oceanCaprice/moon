/*
 *------------------------------------------------------------------------
 *
 *  Name:   BaseGameRole
 *
 *  Desc:   base class of all role in game world
 *
 *  Author: Yi Yang 08/02/2013
 *
 *------------------------------------------------------------------------
 */

#ifndef __AboutFuture__BaseGameRole__
#define __AboutFuture__BaseGameRole__

#include "cocos2d.h"
USING_NS_CC;

//struct BoundingBox{
//    
//    CCRect actual;
//    CCRect original;
//    
//};

class BaseGameRole : public CCSprite {
public:

    
	//movement用于计算精灵如何沿着地图运动
	CC_SYNTHESIZE(CCPoint, _velocity, Velocity);
	CC_SYNTHESIZE(CCPoint, _desiredPosition, DesiredPosition);
    
	//measurements用于计算精灵框体
	CC_SYNTHESIZE(float, _centerToSides, CenterToSides);
	CC_SYNTHESIZE(float, _centerToBottom, CenterToBottom);
    
    
    
    


};


#endif /* defined(__AboutFuture__BaseGameRole__) */
