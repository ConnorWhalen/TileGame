#ifndef MODELMANAGER_H
#define MODELMANAGER_H

#include "../player.h"
#include "../tile.h"
#include "../enemy.h"
#include "../state.h"
#include "../coin.h"
#include "gameManager.h"

#include <vector>

class ModelManager{
	public:
		ModelManager(Player *player, std::vector<Enemy*>& enemies, std::vector<Coin*>& coins, std::vector<Tile*>& tiles,
					 std::vector<Tile*>& safeZones, GameManager *gameManager);
		void updateModels(State& state);
		void Obstruct(Model *mover, std::vector<Tile*>& walls);
		void directEnemies();
		bool checkHit();
		void checkCoins(State& state);
		void resetStage();
	private:
		Player *_player;
		std::vector<Enemy*>& _enemies;
		std::vector<Coin*>& _coins;
		std::vector<Tile*>& _tiles;
		std::vector<Tile*>& _safeZones;
		GameManager *_gameManager;
};

#endif