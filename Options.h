/*
 * Cory Savit
 * Brick Break for Android
 * Cocos2dx Project in C++
 */
#ifndef __OPTIONS_H__
#define __OPTIONS_H__

#include "cocos2d.h"

using namespace cocos2d;

class Options : public cocos2d::CCLayer
{

public:
    virtual bool init();
    static CCScene* scene();

    CREATE_FUNC(Options);

    void soundOnButtonAction(CCObject* pSender);
    void soundOffButtonAction(CCObject* pSender);
    void homeButtonAction(CCObject* pSender);

};

#endif  //__OPTIONS_H__
