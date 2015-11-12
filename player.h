#ifndef PLAYER_H
#define PLAYER_H

#include "model.h"
#include "position.h"
#include "direction.h"
#include "bitmap.h"

class Player : public Model{
	public:
		Player(float x, float y, float xSize, float ySize, const char *bitmapFile)
			: Model(x, y, xSize, ySize, bitmapFile)
		{
			this->_initialX = x;
			this->_initialY = y;
			this->_inDirection = new Direction(0);
			this->_outDirection = new Direction(0);
			this->_speed = 0;
		}
		~Player();

		void timerUpdate(double elapsed) override;

		void reset();

		void inDirection(int newAngle){
			this->_inDirection->angle(newAngle);
			this->_outDirection->angle(newAngle);
		}
		void outDirection(int newAngle){
			this->_outDirection->angle(newAngle);
		}
		void speed(double newSpeed){
			this->_speed = newSpeed;
		}

		Direction *inDirection(){ return this->_inDirection;}
		Direction *outDirection(){ return this->_outDirection;}
		double speed(){ return this->_speed;}
	private:
		float _initialX;
		float _initialY;
		Direction *_inDirection;
		Direction *_outDirection;
		double _speed;
};

#endif