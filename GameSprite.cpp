/*
 * Cory Savit
 * Brick Break for Android
 * Cocos2dx Project in C++
 */
#include "GameSprite.h"

GameSprite::GameSprite(void) {
	_vector = ccp(0,0);

}

GameSprite::~GameSprite(void) {
	// TODO Auto-generated destructor stub
}

GameSprite* GameSprite::gameSpriteWithFile(const char * pszFileName) {
	GameSprite * sprite = new GameSprite();
	if (sprite && sprite->initWithFile(pszFileName)) {
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return NULL;
}

void GameSprite::setPosition(const CCPoint& pos) {
	CCSprite::setPosition(pos);
	if(! _nextPosition.equals(pos)) {
		_nextPosition = pos;
	}
}

float GameSprite::radius() {
	return boundingBox().size.width/2;
}

float GameSprite::width() {
	return boundingBox().size.width;
}

float GameSprite::height() {
	return boundingBox().size.height;
}


