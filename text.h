#ifndef TEXT_H
#define TEXT_H

#include <allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_color.h>
#include "Position.h"

#include <string>

class Text{
	public:
		Text(std::string* text, std::string* color, std::string* textFile, Position* position, int size);
		~Text();
		void drawToScreen();
	// private:
		const char* _text;
		const char* _color;
		const char* _tempFileName;
		ALLEGRO_FONT *_font;
		Position *_position;
		int _size;
};

#endif
