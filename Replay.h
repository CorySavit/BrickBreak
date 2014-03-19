/*
 * Cory Savit
 * Brick Break for Android
 * Cocos2dx Project in C++
 */
#ifndef REPLAY_H_
#define REPLAY_H_


#include "cocos2d.h"

using namespace cocos2d;

class Replay : public cocos2d::CCLayer {
public:

    virtual bool init();
    static CCScene* scene();

    CREATE_FUNC(Replay);

    void replayButtonAction(CCObject* pSender);
    void homeButtonAction(CCObject* pSender);

};

#endif /* REPLAY_H_ */
