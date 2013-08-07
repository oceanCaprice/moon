//
//  DeBug.h
//  AboutFuture
//
//  Created by 杨 奕 on 13-6-5.
//
//

#ifndef __AboutFuture__DeBug__
#define __AboutFuture__DeBug__

#include <string>
#include "cocos2d.h"
USING_NS_CC;
using namespace std;
class DeBug
{
    string m_msg;
public:
    DeBug(){}
    DeBug(const string& msg):m_msg(msg){
        CCLog("%s BEGINS!",m_msg.c_str());}
    ~DeBug(){CCLog("%s ENDS!",m_msg.c_str());}
};
#define LOG_FUNCTION_LIFE DeBug(__FUNCTION__);

#endif /* defined(__AboutFuture__DeBug__) */
