#ifndef MODEL_H
#define MODEL_H

#include "position.h"
#include "bitmap.h"

class Model{
	public:
		Model(float x, float y, float xSize, float ySize, const char *bitmapFile){
			this->_position = new Position(x, y);
			this->_size = new Position(xSize, ySize);
			this->_bitmap = new Bitmap(bitmapFile);
		}
		~Model(){
			delete this->_position;
			delete this->_size;
			delete this->_bitmap;
		}

		Position *position(){ return this->_position;}
		Position *size(){ return this->_size;}
		Bitmap *bitmap(){ return this->_bitmap;}

		void position(Position *newPosition){
			delete this->_position;
			this->_position = newPosition;
		}
		virtual void draw(){this->_bitmap->drawToScreen(this->_position);}
		virtual void timerUpdate(double elapsed){}
	protected:
		Position *_position;
		Position *_size;
		Bitmap *_bitmap;
};

#endif