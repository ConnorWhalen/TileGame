#ifndef MENUDISPLAY_H
#define MENUDISPLAY_H

#include <vector>
#include <allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "../text.h"
#include "../model.h"

class MenuDisplay {
	public:
		MenuDisplay(int width, int height);
		~MenuDisplay();
		void addTitleText(Text *txt);
		void addSelectableText(Text *txt);
		void addSelectedText(Text *txt);
		void addOptionsText(Text *txt);
		void addAnimationModel(Model *mod);
		void drawMenuDisplay(int selected);
		void drawOptionsDisplay();
		ALLEGRO_DISPLAY *display(){ return this->_display;}

	private:
		ALLEGRO_DISPLAY *_display;
		std::vector<Text*> _titleText;
		std::vector<Text*> _selectableText;
		std::vector<Text*> _selectedText;
		std::vector<Text*> _optionsText;
		std::vector<Model*> _animationModels;
		const int _width;
		const int _height;
};

#endif