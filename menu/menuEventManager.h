#ifndef MENUEVENTMANAGER_H
#define MENUEVENTMANAGER_H

#include <allegro.h>
#include "menuDisplay.h"
#include "menuAnimation.h"
#include "../state.h"
#include "../timer.h"

class MenuEventManager {
	public:
		MenuEventManager(MenuDisplay *display, MenuAnimation *animator, Timer *timer){
			this->_display = display;
			this->_animator = animator;
			this->_timer = timer;
			this->_eventQueue = al_create_event_queue();
			al_register_event_source(this->_eventQueue, al_get_display_event_source(this->_display->display()));
			al_install_keyboard();
			al_register_event_source(this->_eventQueue, al_get_keyboard_event_source());
			al_register_event_source(this->_eventQueue, al_get_timer_event_source(timer->timer()));
		}
		~MenuEventManager(){
			al_destroy_event_queue(this->_eventQueue);
		}
		void launchMenu(State& state, int& selected, int& choices);
		void checkUserInput(ALLEGRO_EVENT& ev, State& state, int& selected, int& choices);
		void launchOptionsMenu(State& state);

	private:
		ALLEGRO_EVENT_QUEUE *_eventQueue;
		MenuDisplay *_display;
		MenuAnimation *_animator;
		Timer *_timer;
};

#endif