#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "../coin.h"
#include "../player.h"
#include "../enemy.h"
#include "../state.h"
#include <vector>

class GameManager {
	public:
		GameManager(Player *player, std::vector<Enemy*>& enemies, std::vector<Coin*>& coins);
		void coinCollect(Coin *coin, State& state);
		void playerHit(State& state);
	private:
		Player* _player;
		std::vector<Enemy*>& _enemies;
		std::vector<Coin*>& _coins;
};

#endif