#include "stage/stageManager.h"
#include "state.h"
#include "menu/menu.h"

/**************************************************************************************************************************************************************************************************
* Use this to compile:
* g++ -std=c++11 -stdlib=libc++ -I /usr/local/include/allegro5 -l allegro -l allegro_main -l allegro_image -l allegro_font -l allegro_ttf -l allegro_color game.cpp player.cpp stage/stageEventManager.cpp stage/stageDisplay.cpp stage/inputManager.cpp timer.cpp tile.cpp stage/stageBuilder.cpp stage/modelManager.cpp enemy.cpp text.cpp coin.cpp stage/gameManager.cpp stage/stageManager.cpp menu/menuEventManager.cpp menu/menuDisplay.cpp menu/menu.cpp menu/menuAnimation.cpp -o game.out
**************************************************************************************************************************************************************************************************/

// TODO: Add Makefile
//		 Add stages
//		 Add new mechanics and enemies
//		 Add global finish
//		 Add Animations to main menu
//		 Make world transitions and/or a stage select
//		 Add saving/loading
//		 Make things prettier

const float FPS = 60;
const int SCREEN_W = 320;
const int SCREEN_H = 320;

int main(int argc, char **argv){

	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	int stage = 1;
	State state = State::MENU;
	StageManager* stage_man = new StageManager();
	Menu* mainMenu = new Menu();
	while(1){
		if (state == State::START){
			stage_man->launchStage(stage, state, SCREEN_W, SCREEN_H);
		}
		else if (state == State::MENU){
			mainMenu->launchMenu(state, SCREEN_W, SCREEN_H);
		}

		if (state == State::QUIT){
			return 0;
		}
		else if (state == State::NEXT){
			state = State::START;
		}

		if (stage > 2){
			return 0;
		}
	}

}