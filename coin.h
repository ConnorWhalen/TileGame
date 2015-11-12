#ifndef COIN_H
#define COIN_H

#include "model.h"
#include "position.h"
#include "bitmap.h"

class Coin : public Model {
	public:
		Coin(float x, float y, float xSize, float ySize, const char *bitmapFile)
			: Model(x, y, xSize, ySize, bitmapFile), _collected(false)
		{
		}
		void draw() override;
		void reset();
		void collect();
		bool collected(){ return this->_collected;}
	private:
		bool _collected;
};

#endif