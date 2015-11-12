#ifndef TIMER_H
#define TIMER_H

#include <vector>
#include <allegro.h>
#include "Model.h"

class Timer{
	public:
		Timer(int FPS);
		~Timer();
		void addModel(Model *mod);
		void startTimer();
		void stopTimer();
		void updateModels();
		ALLEGRO_TIMER *timer(){ return this->_timer;}
	private:
		std::vector<Model*> _models;
		ALLEGRO_TIMER *_timer;
		int _fps;
};

#endif