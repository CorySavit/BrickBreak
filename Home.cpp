/*
 * Cory Savit
 * Brick Break for Android
 * Cocos2dx Project in C++
 */
#include "Options.h"
#include "HelloWorldScene.h"
#include "Home.h"
//#include "SimpleAudioEngine.h"

using namespace cocos2d;

USING_NS_CC;

CCScene* Home::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();

    // 'layer' is an autorelease object
    Home *layer = Home::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Home::init()
{
    if (!CCLayer::init())
    {
        return false;
    }


    CCSize _winSize = CCDirector::sharedDirector()->getWinSize();

    // Title
	CCLabelTTF *title = CCLabelTTF::create("Brick Breaker!!!", "Ariel", 60);
	title->setPosition(ccp(_winSize.width/2, _winSize.height/4*3));
	this->addChild(title);

	// Create the label for the author
	CCLabelTTF *creator = CCLabelTTF::create("Created by: Cory Savit", "Ariel", 40);
	creator->setPosition(ccp(_winSize.width/2, _winSize.height / 2));
	this->addChild(creator);

	CCMenuItemFont::setFontName("Ariel");
	CCMenuItemFont *playButton = CCMenuItemFont::create("Start Game!", this, menu_selector(Home::playButtonAction));
	CCMenuItemFont *optionsButton = CCMenuItemFont::create("Options", this, menu_selector(Home::optionsButtonAction));

	CCMenu *optionsMenu = CCMenu::create(playButton, optionsButton, NULL);
	optionsMenu->alignItemsVerticallyWithPadding(10);
	optionsMenu->setPosition(ccp(_winSize.width/2, _winSize.height/5));
	this->addChild(optionsMenu);

    return true;
}

void Home::playButtonAction(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}

void Home::optionsButtonAction(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(Options::scene());
}
