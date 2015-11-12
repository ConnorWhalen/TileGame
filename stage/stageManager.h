#ifndef STAGEMANAGER_H
#define STAGEMANAGER_H

#include "../player.h"
#include "../tile.h"
#include "StageEventManager.h"
#include "StageDisplay.h"
#include "inputManager.h"
#include "../timer.h"
#include "stageBuilder.h"
#include "modelManager.h"
#include "../enemy.h"
#include "../state.h"
#include "../coin.h"
#include "gameManager.h"
#include "../text.h"

#include <vector>

class StageManager {
	public:
		StageManager();
		void launchStage(int& stage, State& state, int screenWidth, int screenHeight);
	private:
};

#endif