#include "gameManager.h"

GameManager::GameManager(Player *player, std::vector<Enemy*>& enemies, std::vector<Coin*>& coins)
	: _player(player), _enemies(enemies), _coins(coins)
{
}

void GameManager::coinCollect(Coin *coin, State& state){
	coin->collect();
	for (Coin* c : this->_coins){
		if (!c->collected()){
			return;
		}
	}
	state = State::WIN;
}
		
void GameManager::playerHit(State& state){
	state = State::DEATH;
}