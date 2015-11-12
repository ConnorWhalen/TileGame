#include "menuDisplay.h"

MenuDisplay::MenuDisplay(int width, int height)
	: _width(width), _height(height)
{
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	this->_display = al_create_display(width, height);
	al_set_target_bitmap(al_get_backbuffer(this->_display));
	al_clear_to_color(al_map_rgb(0, 0, 0));
}

MenuDisplay::~MenuDisplay(){
	al_destroy_display(this->_display);
}

void MenuDisplay::addTitleText(Text *txt){
	this->_titleText.push_back(txt);
}

void MenuDisplay::addSelectableText(Text *txt){
	this->_selectableText.push_back(txt);
}

void MenuDisplay::addSelectedText(Text *txt){
	this->_selectedText.push_back(txt);
}

void MenuDisplay::addOptionsText(Text *txt){
	this->_optionsText.push_back(txt);
}

void MenuDisplay::addAnimationModel(Model *mod){
	this->_animationModels.push_back(mod);
}

void MenuDisplay::drawMenuDisplay(int selected){
	al_clear_to_color(al_map_rgb(0, 0, 0));
	for (int i = 0; i < this->_animationModels.size(); i++){
		this->_animationModels[i]->draw();
	}
	for (int i = 0; i < this->_titleText.size(); i++){
		this->_titleText[i]->drawToScreen();
	}
	for (int i = 0; i < this->_selectableText.size(); i++){
		if (i != selected){
			this->_selectableText[i]->drawToScreen();
		}
		else {
			this->_selectedText[i]->drawToScreen();
		}
	}
	al_flip_display();
}

void MenuDisplay::drawOptionsDisplay(){
	al_clear_to_color(al_map_rgb(0, 0, 0));
	for (int i = 0; i < this->_optionsText.size(); i++){
		this->_optionsText[i]->drawToScreen();
	}

	al_flip_display();
}