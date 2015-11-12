#ifndef POSITION_H
#define POSITION_H

class Position{
	public:
		Position(float x, float y){
			this->_x = x;
			this->_y = y;
		}

		void shiftX(float dx){
			this->_x += dx;
		}
		void shiftY(float dy){
			this->_y += dy;
		}
		void x(float newX){
			this->_x = newX;
		}
		void y(float newY){
			this->_y = newY;
		}
		float x(){ return this->_x;}
		float y(){ return this->_y;}
	private:
		float _x;
		float _y;
};

#endif