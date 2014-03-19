/*
 * Cory Savit
 * Brick Break for Android
 * Cocos2dx Project in C++
 */
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GameSprite.h"

using namespace cocos2d;


class HelloWorld : public cocos2d::CCLayerColor
{
	GameSprite * _paddle;
	GameSprite * _ball;
	CCLabelTTF * _scoreLabel;
	CCSize _winSize;
	bool sound;
	int _score;


	void playerScore(int player);

public:
	~HelloWorld();
    virtual bool init();  

    static CCScene* scene();
    CREATE_FUNC(HelloWorld);
    void menuCloseCallback(CCObject* pSender);
    


    virtual void ccTouchesBegan(CCSet* pTouches, CCEvent* event);
    virtual void ccTouchesMoved(CCSet* pTouches, CCEvent* event);
    virtual void ccTouchesEnded(CCSet* pTouches, CCEvent* event);
    void update (float dt);
    void createBlocks (int rows, int cols);

protected:
    CCArray* _blocks;
};

#endif // __HELLOWORLD_SCENE_H__
