#include "stageEventManager.h"

void StageEventManager::launchStartScreen(State& state){
	this->_display->drawStartDisplay();
	while(1){
		ALLEGRO_EVENT ev;
		al_wait_for_event(this->_eventQueue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			state = State::QUIT;
		}

		if (al_is_event_queue_empty(this->_eventQueue)){
			this->_display->drawStartDisplay();
		}

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
			if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER){
				this->_modelManager->resetStage();
				state = State::STAGE;
			}
		}

		this->checkPlayerInput(ev);

		if (state != State::START){
			break;
		}
	}
}

void StageEventManager::launchDeathScreen(State& state){
	this->_display->drawDeathDisplay();
	while(1){
		ALLEGRO_EVENT ev;
		al_wait_for_event(this->_eventQueue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			state = State::QUIT;
		}

		if (al_is_event_queue_empty(this->_eventQueue)){
			this->_display->drawDeathDisplay();
		}

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
			if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER){
				this->_modelManager->resetStage();
				state = State::STAGE;
			}
		}

		this->checkPlayerInput(ev);

		if (state != State::DEATH){
			break;
		}
	}
}

void StageEventManager::launchPauseScreen(State& state){
	this->_display->drawPauseDisplay();
	while(1){
		ALLEGRO_EVENT ev;
		al_wait_for_event(this->_eventQueue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			state = State::QUIT;
		}

		if (al_is_event_queue_empty(this->_eventQueue)){
			this->_display->drawPauseDisplay();
		}

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
			if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER){
				state = State::STAGE;
			}
		}

		this->checkPlayerInput(ev);

		if (state != State::PAUSE){
			break;
		}
	}
}

void StageEventManager::launchWinScreen(State& state){
	this->_display->drawWinDisplay();
	while(1){
		ALLEGRO_EVENT ev;
		al_wait_for_event(this->_eventQueue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			state = State::QUIT;
		}

		if (al_is_event_queue_empty(this->_eventQueue)){
			this->_display->drawWinDisplay();
		}

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
			if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER){
				this->_modelManager->resetStage();
				state = State::NEXT;
			}
		}

		this->checkPlayerInput(ev);

		if (state != State::WIN){
			break;
		}
	}
}

void StageEventManager::launchStage(State& state){
	this->_timer->startTimer();
	while(1){
		ALLEGRO_EVENT ev;
		al_wait_for_event(this->_eventQueue, &ev);

		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			state = State::QUIT;
		}

		if (ev.type == ALLEGRO_EVENT_TIMER){
			this->_modelManager->updateModels(state);
			this->_timer->updateModels();
		}

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_ENTER){
			state = State::PAUSE;
		}

		this->checkPlayerInput(ev);

		if (al_is_event_queue_empty(this->_eventQueue)){
			this->_display->drawStageDisplay();
		}

		if (state != State::STAGE){
			break;
		}
	}
	this->_timer->stopTimer();
}

void StageEventManager::checkPlayerInput(ALLEGRO_EVENT& ev){
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN){
			if (ev.keyboard.keycode == ALLEGRO_KEY_UP){
				// fprintf(stdout, "UP\n");
				this->_inputManager->playerUp();
			}
			else if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN){
				// fprintf(stdout, "DOWN\n");
				this->_inputManager->playerDown();
			}
			else if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT){
				// fprintf(stdout, "LEFT\n");
				this->_inputManager->playerLeft();
			}
			else if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT){
				// fprintf(stdout, "RIGHT\n");
				this->_inputManager->playerRight();
			}
		}
		if (ev.type == ALLEGRO_EVENT_KEY_UP){
			if (ev.keyboard.keycode == ALLEGRO_KEY_UP){
				// fprintf(stdout, "!UP\n");
				this->_inputManager->playerUpRelease();
			}
			else if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN){
				// fprintf(stdout, "!DOWN\n");
				this->_inputManager->playerDownRelease();
			}
			else if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT){
				// fprintf(stdout, "!LEFT\n");
				this->_inputManager->playerLeftRelease();
			}
			else if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT){
				// fprintf(stdout, "!RIGHT\n");
				this->_inputManager->playerRightRelease();
			}
		}
}