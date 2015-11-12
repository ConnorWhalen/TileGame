#ifndef STAGEDISPLAY_H
#define STAGEDISPLAY_H

#include <vector>
#include <allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "../model.h"
#include "../text.h"

class StageDisplay{
	public:
		StageDisplay(int width, int height);
		~StageDisplay();
		void addModel(Model *mod);
		void addStartText(Text *txt);
		void addDeathText(Text *txt);
		void addPauseText(Text *txt);
		void addWinText(Text *txt);
		void addMenuText(Text *txt);
		void drawStartDisplay();
		void drawDeathDisplay();
		void drawPauseDisplay();
		void drawWinDisplay();
		void drawStageDisplay();
		ALLEGRO_DISPLAY *display(){ return this->_display;}
	private:
		ALLEGRO_DISPLAY *_display;
		std::vector<Model*> _models;
		std::vector<Text*> _startText;
		std::vector<Text*> _deathText;
		std::vector<Text*> _pauseText;
		std::vector<Text*> _winText;
		const int _width;
		const int _height;
};

#endif