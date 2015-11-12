#include "stageDisplay.h"

StageDisplay::StageDisplay(int width, int height)
	: _width(width), _height(height)
{
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	this->_display = al_create_display(width, height);
	al_set_target_bitmap(al_get_backbuffer(this->_display));
	al_clear_to_color(al_map_rgb(0, 0, 0));
}

StageDisplay::~StageDisplay(){
	al_destroy_display(this->_display);
}

void StageDisplay::addModel(Model *mod){
	this->_models.push_back(mod);
}

void StageDisplay::addStartText(Text *txt){
	this->_startText.push_back(txt);
}

void StageDisplay::addDeathText(Text *txt){
	this->_deathText.push_back(txt);
}

void StageDisplay::addPauseText(Text *txt){
	this->_pauseText.push_back(txt);
}

void StageDisplay::addWinText(Text *txt){
	this->_winText.push_back(txt);
}

void StageDisplay::drawStartDisplay(){
	al_clear_to_color(al_map_rgb(0, 0, 0));
	for (int i = 0; i < this->_models.size(); i++){
		this->_models[i]->draw();
	}
	for (int i = 0; i < this->_startText.size(); i++){
		this->_startText[i]->drawToScreen();
	}
	al_flip_display();
}

void StageDisplay::drawDeathDisplay(){
	al_clear_to_color(al_map_rgb(0, 0, 0));
	for (int i = 0; i < this->_models.size(); i++){
		this->_models[i]->draw();
	}
	for (int i = 0; i < this->_deathText.size(); i++){
		this->_deathText[i]->drawToScreen();
	}
	al_flip_display();
}

void StageDisplay::drawPauseDisplay(){
	al_clear_to_color(al_map_rgb(0, 0, 0));
	for (int i = 0; i < this->_models.size(); i++){
		this->_models[i]->draw();
	}
	for (int i = 0; i < this->_pauseText.size(); i++){
		this->_pauseText[i]->drawToScreen();
	}
	al_flip_display();
}

void StageDisplay::drawWinDisplay(){
	al_clear_to_color(al_map_rgb(0, 0, 0));
	for (int i = 0; i < this->_models.size(); i++){
		this->_models[i]->draw();
	}
	for (int i = 0; i < this->_winText.size(); i++){
		this->_winText[i]->drawToScreen();
	}
	al_flip_display();
}

void StageDisplay::drawStageDisplay(){
	al_clear_to_color(al_map_rgb(0, 0, 0));
	for (int i = 0; i < this->_models.size(); i++){
		this->_models[i]->draw();
	}
	al_flip_display();
}