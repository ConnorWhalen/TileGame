#include "timer.h"

Timer::Timer(int FPS){
	this->_fps = FPS;
	this->_timer = al_create_timer(1.0 / FPS);
}

Timer::~Timer(){
	al_destroy_timer(this->_timer);
}

void Timer::addModel(Model *mod){
	this->_models.push_back(mod);
}

void Timer::startTimer(){
	al_start_timer(this->_timer);
}

void Timer::stopTimer(){
	al_stop_timer(this->_timer);
}

void Timer::updateModels(){
	for (int i = 0; i < this->_models.size(); i++){
		this->_models[i]->timerUpdate(1.0 / this->_fps);
	}
}