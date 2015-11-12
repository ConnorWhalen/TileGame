#ifndef STAGEEVENTMANAGER_H
#define STAGEEVENTMANAGER_H

#include <allegro.h>
#include "../player.h"
#include "stageDisplay.h"
#include "inputManager.h"
#include "../timer.h"
#include "modelManager.h"
#include "../state.h"

class StageEventManager{
	public:
		StageEventManager(Timer *timer, StageDisplay *display, InputManager *inputManager, ModelManager *modelManager){
			this->_timer = timer;
			this->_display = display;
			this->_inputManager = inputManager;
			this->_modelManager = modelManager;
			this->_eventQueue = al_create_event_queue();
			al_register_event_source(this->_eventQueue, al_get_timer_event_source(timer->timer()));
			al_register_event_source(this->_eventQueue, al_get_display_event_source(this->_display->display()));
			al_register_event_source(this->_eventQueue, al_get_keyboard_event_source());
		}
		~StageEventManager(){
			al_destroy_event_queue(this->_eventQueue);
		}
		void launchStartScreen(State& state);
		void launchStage(State& state);
		void launchDeathScreen(State& state);
		void launchPauseScreen(State& state);
		void launchWinScreen(State& state);
		void checkPlayerInput(ALLEGRO_EVENT& ev);
	private:
		ALLEGRO_EVENT_QUEUE *_eventQueue;
		Timer *_timer;
		StageDisplay *_display;
		InputManager *_inputManager;
		ModelManager *_modelManager;
};

#endif