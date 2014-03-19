/*
 * Cory Savit
 * Brick Break for Android
 * Cocos2dx Project in C++
 */
#include "Options.h"
#include "Home.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;


CCScene* Options::scene()
{
    CCScene *scene = CCScene::create();

    Options *layer = Options::create();

    scene->addChild(layer);

    return scene;
}

bool Options::init()
{
    if (!CCLayer::init())
    {
        return false;
    }

    // Get the window size
    CCSize _winSize = CCDirector::sharedDirector()->getWinSize();

    // Set the options screen title
    CCLabelTTF *title = CCLabelTTF::create("Options", "Ariel", 60);
	title->setPosition(ccp(_winSize.width / 2, _winSize.height/4*3));
	this->addChild(title);

	// Menu Buttons
	CCMenuItemFont::setFontName("Ariel");
	CCMenuItemFont *soundOn = CCMenuItemFont::create("Sound On", this, menu_selector(Options::soundOnButtonAction));
	CCMenuItemFont *soundOff = CCMenuItemFont::create("Sound Off", this, menu_selector(Options::soundOffButtonAction));
	CCMenuItemFont *homeButton = CCMenuItemFont::create("Home", this, menu_selector(Options::homeButtonAction));

	//Menu
	CCMenu *menu = CCMenu::create(soundOn, soundOff, homeButton, NULL);
	menu->alignItemsVerticallyWithPadding(20);
	menu->setPosition(ccp(_winSize.width / 2, _winSize.height / 2));

	// Add menu to layer
	this->addChild(menu);

    return true;
}

void Options::soundOnButtonAction(CCObject* pSender)
{
    CCUserDefault::sharedUserDefault()->setBoolForKey("sound", true);
}

void Options::soundOffButtonAction(CCObject* pSender)
{
	CCUserDefault::sharedUserDefault()->setBoolForKey("sound", false);
}

void Options::homeButtonAction(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(Home::scene());
}

