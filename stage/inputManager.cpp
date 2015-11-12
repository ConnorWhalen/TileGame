#include "inputManager.h"

InputManager::InputManager(Player *player)
	: _up(false), _down(false), _left(false), _right(false)
{
	this->_player = player;
	al_install_keyboard();
}

void InputManager::setPlayerSpeed(double speed){
	this->_player->speed(speed);
}
void InputManager::setPlayerDirection(int angle){
	this->_player->inDirection(angle);
}

void InputManager::playerUp(){
	_up = true;
	if (!_down){
		this->_player->speed(100);
		if (_left == _right){
			this->_player->inDirection(-90);
		}
		else if (_left){
			this->_player->inDirection(-135);
		}
		else if (_right){
			this->_player->inDirection(-45);
		}
	}
	else if (!_left && !_right){
		this->_player->speed(0);
	}
}
void InputManager::playerDown(){
	_down = true;
	if (!_up){
		this->_player->speed(100);
		if (_left == _right){
			this->_player->inDirection(90);
		}
		else if (_left){
			this->_player->inDirection(135);
		}
		else if (_right){
			this->_player->inDirection(45);
		}
	}
	else if (!_left && !_right){
		this->_player->speed(0);
	}
}
void InputManager::playerLeft(){
	_left = true;
	if (!_right){
		this->_player->speed(100);
		if (_up == _down){
			this->_player->inDirection(180);
		}
		else if (_up){
			this->_player->inDirection(-135);
		}
		else if (_down){
			this->_player->inDirection(135);
		}
	}
	else if (!_up && !_down){
		this->_player->speed(0);
	}
}
void InputManager::playerRight(){
	_right = true;
	if (!_left){
		this->_player->speed(100);
		if (_up == _down){
			this->_player->inDirection(0);
		}
		else if (_up){
			this->_player->inDirection(-45);
		}
		else if (_down){
			this->_player->inDirection(45);
		}
	}
	else if (!_up && !_down){
		this->_player->speed(0);
	}
}

void InputManager::playerUpRelease(){
	_up = false;
	if (!_down){
		if (_left == _right){
			this->_player->speed(0);
		}
		else if (_left){
			this->_player->speed(100);
			this->_player->inDirection(180);
		}
		else if (_right){
			this->_player->speed(100);
			this->_player->inDirection(0);
		}
	}
	else{
		this->_player->speed(100);
		if (!_left && !_right){
			this->_player->inDirection(90);
		}
		else if (!_left && _right){
			this->_player->inDirection(45);
		}
		else if (_left && !_right){
			this->_player->inDirection(135);
		}
	}
}
void InputManager::playerDownRelease(){
	_down = false;
	if (!_up){
		if (_left == _right){
			this->_player->speed(0);
		}
		else if (_left){
			this->_player->speed(100);
			this->_player->inDirection(180);
		}
		else if (_right){
			this->_player->speed(100);
			this->_player->inDirection(0);
		}
	}
	else{
		this->_player->speed(100);
		if (!_left && !_right){
			this->_player->inDirection(-90);
		}
		else if (!_left && _right){
			this->_player->inDirection(-45);
		}
		else if (_left && !_right){
			this->_player->inDirection(-135);
		}
	}
}
void InputManager::playerLeftRelease(){
	_left = false;
	if (!_right){
		if (_up == _down){
			this->_player->speed(0);
		}
		else if (_up){
			this->_player->speed(100);
			this->_player->inDirection(-90);
		}
		else if (_down){
			this->_player->speed(100);
			this->_player->inDirection(90);
		}
	}
	else{
		this->_player->speed(100);
		if (!_up && !_down){
			this->_player->inDirection(0);
		}
		else if (!_up && _down){
			this->_player->inDirection(45);
		}
		else if (_up && !_down){
			this->_player->inDirection(-45);
		}
	}
}
void InputManager::playerRightRelease(){
	_right = false;
	if (!_left){
		if (_up == _down){
			this->_player->speed(0);
		}
		else if (_up){
			this->_player->speed(100);
			this->_player->inDirection(-90);
		}
		else if (_down){
			this->_player->speed(100);
			this->_player->inDirection(90);
		}
	}
	else{
		this->_player->speed(100);
		if (!_up && !_down){
			this->_player->inDirection(180);
		}
		else if (!_up && _down){
			this->_player->inDirection(135);
		}
		else if (_up && !_down){
			this->_player->inDirection(-135);
		}
	}
}