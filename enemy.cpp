#include "enemy.h"

Enemy::Enemy(float x, float y, float xSize, float ySize, const char *bitmapFile)
		: Model(x, y, xSize, ySize, bitmapFile)
{
	this->_initialX = x;
	this->_initialY = y;
	this->_inDirection = new Direction(0);
	this->_outDirection = new Direction(0);
	this->_speed = 70;
}

Enemy::~Enemy(){
	delete this->_inDirection;
	delete this->_outDirection;
}

void Enemy::timerUpdate(double elapsed){
	this->_position->shiftX((this->_speed * this->_outDirection->x()) * elapsed);
	this->_position->shiftY((this->_speed * this->_outDirection->y()) * elapsed);
}

void Enemy::reset(){
	Position *init = new Position(this->_initialX, this->_initialY);
	this->position(init);
}