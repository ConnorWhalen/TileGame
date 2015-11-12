#include "coin.h"

void Coin::draw(){
	if (!this->_collected){
		this->_bitmap->drawToScreen(this->_position);
	}
}

void Coin::reset(){
	this->_collected = false;
}

void Coin::collect(){
	this->_collected = true;
}