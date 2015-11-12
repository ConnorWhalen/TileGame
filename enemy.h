#ifndef ENEMY_H
#define ENEMY_H

#include "model.h"
#include "direction.h"
#include "position.h"

class Enemy : public Model{
	public:
		Enemy(float x, float y, float xSize, float ySize, const char *bitmapFile);
		~Enemy();

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