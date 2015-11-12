#include "stageManager.h"

StageManager::StageManager(){}

void StageManager::launchStage(int& stage, State& state, int screenWidth, int screenHeight){
		StageDisplay *mainDisplay = new StageDisplay(screenWidth, screenHeight);
		std::vector<Coin*> coins;
		std::vector<Tile*> tiles;
		std::vector<Tile*> safeZones;
		std::vector<Text*> startText;
		std::vector<Text*> deathText;
		std::vector<Text*> pauseText;
		std::vector<Text*> winText;
		std::vector<Enemy*> enemies;
		Player *player1 = NULL;
		buildStage(stage, player1, enemies, coins, tiles, safeZones, startText, deathText, pauseText, winText);

		Timer *timer = new Timer(60);

		for (Coin* c : coins){
			mainDisplay->addModel(c);
			timer->addModel(c);
		}
		for (Tile* t : tiles){
			mainDisplay->addModel(t);
			timer->addModel(t);
		}
		for (Tile* t : safeZones){
			mainDisplay->addModel(t);
			timer->addModel(t);
		}
		for (Text* t : startText){
			mainDisplay->addStartText(t);
		}
		for (Text* t : deathText){
			mainDisplay->addDeathText(t);
		}
		for (Text* t : pauseText){
			mainDisplay->addPauseText(t);
		}
		for (Text* t : winText){
			mainDisplay->addWinText(t);
		}
		for (Enemy* e : enemies){
			mainDisplay->addModel(e);
			timer->addModel(e);
		}
		mainDisplay->addModel(player1);
		timer->addModel(player1);

		InputManager *in_man = new InputManager(player1);

		GameManager *game_man = new GameManager(player1, enemies, coins);

		ModelManager *model_man = new ModelManager(player1, enemies, coins, tiles, safeZones, game_man);

		StageEventManager *evt_man = new StageEventManager(timer, mainDisplay, in_man, model_man);

		while (state != State::QUIT && state != State::NEXT){
			if (state == State::START){
				evt_man->launchStartScreen(state);
			}
			else if (state == State::DEATH){
				evt_man->launchDeathScreen(state);		
			}
			else if (state == State::STAGE){
				evt_man->launchStage(state);		
			}
			else if (state == State::PAUSE){
				evt_man->launchPauseScreen(state);		
			}
			else if (state == State::WIN){
				evt_man->launchWinScreen(state);		
			}
		}

		if (state == State::NEXT){
			stage++;
		}

		delete mainDisplay;
		coins.clear();
		tiles.clear();
		safeZones.clear();
		startText.clear();
		deathText.clear();
		pauseText.clear();
		winText.clear();
		enemies.clear();
		delete player1;
		delete timer;
		delete in_man;
		delete game_man;
		delete model_man;
		delete evt_man;
}