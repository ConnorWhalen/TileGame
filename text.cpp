#include "text.h"

Text::Text(std::string* text, std::string* color, std::string* textFile, Position* position, int size)
	: _position(position), _size(size)
{
	this->_text = (*text).c_str();
	this->_color = (*color).c_str();
	this->_tempFileName = (*textFile).c_str();
	this->_font = al_load_ttf_font(this->_tempFileName, -size, 0);
}

Text::~Text(){
	delete this->_text;
	delete this->_color;
	delete this->_tempFileName;
	delete this->_position;
}

void Text::drawToScreen(){
	al_draw_text(this->_font, al_color_name(this->_color), this->_position->x(), this->_position->y(), 0, this->_text);
}