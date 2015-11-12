#include "player.h"

#include <string>

void Player::timerUpdate(double elapsed){
	this->_position->shiftX((this->_speed * this->_outDirection->x()) * elapsed);
	this->_position->shiftY((this->_speed * this->_outDirection->y()) * elapsed);
}

Player::~Player(){
	delete this->_inDirection;
	delete this->_outDirection;
}

void Player::reset(){
	Position *init = new Position(this->_initialX, this->_initialY);
	this->position(init);
}