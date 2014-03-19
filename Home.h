/*
 * Cory Savit
 * Brick Break for Android
 * Cocos2dx Project in C++
 */
#ifndef HOME_H_
#define HOME_H_
#include "cocos2d.h"



using namespace cocos2d;

class Home : cocos2d::CCLayer {
public:
	virtual bool init();
	static CCScene* scene();
	CREATE_FUNC(Home);

	void playButtonAction(CCObject* psender);
	void optionsButtonAction(CCObject* psender);

};

#endif // __HOME_H__
