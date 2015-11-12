#include "menuEventManager.h"

void MenuEventManager::launchMenu(State& state, int& selected, int& choices){
	this->_display->drawMenuDisplay(selected);
	this->_timer->startTimer();
	while(1){
		ALLEGRO_EVENT ev;
		al_wait_for_event(this->_eventQueue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			state = State::QUIT;
		}

		if (ev.type == ALLEGRO_EVENT_TIMER){
			this->_animator->updateAnimation();
		}

		this->checkUserInput(ev, state, selected, choices);

		if (al_is_event_queue_empty(this->_eventQueue)){
			this->_display->drawMenuDisplay(selected);
		}

		if (state != State::MENU){
			break;
		}
	}
	this->_timer->stopTimer();
}

void MenuEventManager::checkUserInput(ALLEGRO_EVENT& ev, State& state, int& selected, int& choices){
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
		if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN){
			selected++;
			if (selected == choices){
				selected = 0;
			}
		}
		else if (ev.keyboard.keycode == ALLEGRO_KEY_UP){
			selected--;
			if (selected == -1){
				selected = choices - 1;
			}
		}
		else if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER){
			if (selected == 0){
				state = State::START;
			}
			else if (selected == 2){
				state = State::OPTIONS;
			}
		}
	}
}

void MenuEventManager::launchOptionsMenu(State& state){
	this->_display->drawOptionsDisplay();
	while(1){
		ALLEGRO_EVENT ev;
		al_wait_for_event(this->_eventQueue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			state = State::QUIT;
		}

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_ENTER){
			state = State::MENU;
		}

		if (al_is_event_queue_empty(this->_eventQueue)){
			this->_display->drawOptionsDisplay();
		}

		if (state != State::OPTIONS){
			break;
		}
	}
}
