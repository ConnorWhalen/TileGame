#include "menuAnimation.h"

namespace bmpFiles{
	const char* playerBmp = "bitmaps/greenIcon.png";
	const char* enemyBmp = "bitmaps/gimpCross.png";
	const char* tileBmp = "bitmaps/tile.png";
	const char* tile2Bmp = "bitmaps/tile2.png";
	const char* greenBmp = "bitmaps/green.png";
	const char* coinBmp = "bitmaps/coin.png";
}

MenuAnimation::MenuAnimation(MenuDisplay* display)
	: _display(display), _current(NULL), _complete(false)
{
	for (int i = 0; i < 20; i++){
		this->_columns.push_back(0);
	}
	this->createTile();
}

void MenuAnimation::createTile(){
	bool columnFull = true;
	while (columnFull){
		this->_currentCol = rand() % 20;
		if (this->_columns[this->_currentCol] != 20){
			columnFull = false;
		}
	}
	int xPos = this->_currentCol * 16;
	this->_current = new Model(xPos, -16, 16.0, 16.0, bmpFiles::tileBmp);
	this->_display->addAnimationModel(this->_current);
}

void MenuAnimation::updateAnimation(){
	if (this->_complete){
		return;
	}

	this->_current->position()->shiftY(150.0/60.0);

	if (this->_current->position()->y() >= 304 - (this->_columns[this->_currentCol] * 16)){
		this->_current->position()->y(304 - (this->_columns[this->_currentCol] * 16));
		this->_columns[this->_currentCol]++;
		this->_complete = true;
		for (int i = 0; i < this->_columns.size(); i++){
			if (this->_columns[i] < 20){
				this->_complete = false;
				this->createTile();
				break;
			}
		}
	}
}