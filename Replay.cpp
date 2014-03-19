/*
 * Cory Savit
 * Brick Break for Android
 * Cocos2dx Project in C++
 */
#include "Options.h"
#include "Home.h"
#include "HelloWorldScene.h"
#include "Replay.h"

#include "SimpleAudioEngine.h"

using namespace cocos2d;


CCScene* Replay::scene()
{
    CCScene *scene = CCScene::create();

    Replay *layer = Replay::create();

    scene->addChild(layer);

    return scene;
}

bool Replay::init()
{
    if (!CCLayer::init())
    {
        return false;
    }

    // Get the window size
    CCSize _winSize = CCDirector::sharedDirector()->getWinSize();

    // Set the options screen title
    CCLabelTTF *title = CCLabelTTF::create("Game Over", "Ariel", 60);
	title->setPosition(ccp(_winSize.width / 2, _winSize.height/4*3));
	this->addChild(title);

	// Menu Buttons
	CCMenuItemFont::setFontName("Ariel");
	CCMenuItemFont *replayButton = CCMenuItemFont::create("Play Again?", this, menu_selector(Replay::replayButtonAction));
	CCMenuItemFont *homeButton = CCMenuItemFont::create("Home", this, menu_selector(Replay::homeButtonAction));

	//Menu
	CCMenu *menu = CCMenu::create(replayButton, homeButton, NULL);
	menu->alignItemsVerticallyWithPadding(40);
	menu->setPosition(ccp(_winSize.width / 2, _winSize.height / 2));

	// Add menu to layer
	this->addChild(menu);

    return true;
}

void Replay::replayButtonAction(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}

void Replay::homeButtonAction(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(Home::scene());
}
