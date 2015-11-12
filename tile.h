#ifndef TILE_H
#define TILE_H

#include "model.h"
#include "position.h"
#include "bitmap.h"

class Tile : public Model{
	public:
		Tile(float x, float y, float xSize, float ySize, const char *bitmapFile)
			: Model(x, y, xSize, ySize, bitmapFile)
		{
		}
		void timerUpdate(double elapsed) override;
};

#endif