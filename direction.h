#ifndef DIRECTION_H
#define DIRECTION_H

#include <cmath>

#define PI 3.14159265

class Direction{
	public:
		Direction(int angle){
			this->_angle = angle%360;
			this->_x = cos((angle * PI)/180);
			this->_y = sin((angle * PI)/180);
		}
		void angle(int newAngle){
			this->_angle = newAngle%360;
			this->_x = cos((newAngle * PI)/180);
			this->_y = sin((newAngle * PI)/180);
		}
		double x(){ return this->_x;}
		double y(){ return this->_y;}
		int angle(){ return this->_angle;}
	private:
		double _x;
		double _y;
		int _angle;
};
#endif