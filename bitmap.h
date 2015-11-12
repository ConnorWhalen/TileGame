#ifndef BITMAP_H
#define BITMAP_H

#include <allegro.h>
#include "position.h"
#include "direction.h"

class Bitmap{
	public:
		Bitmap(const char* filename){
			this->_filename = filename;
			this->_bmp = al_load_bitmap(filename);
		}

		~Bitmap(){
			al_destroy_bitmap(this->_bmp);
		}

		void drawToScreen(Position *position){
			al_draw_bitmap(this->_bmp, position->x(), position->y(), 0);
		}

		const char *filename(){ return this->_filename;}
	private:
		ALLEGRO_BITMAP *_bmp;
		const char *_filename;
};

#endif