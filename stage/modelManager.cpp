#include "modelManager.h"

#include <math.h>

#define PI 3.14159265

ModelManager::ModelManager(Player *player, std::vector<Enemy*>& enemies, std::vector<Coin*>& coins, std::vector<Tile*>& tiles,
						   std::vector<Tile*>& safeZones, GameManager *gameManager)
	: _player(player), _enemies(enemies), _coins(coins), _tiles(tiles), _safeZones(safeZones), _gameManager(gameManager)
{
}

void ModelManager::updateModels(State& state){
	this->Obstruct(this->_player, this->_tiles);
	for (Enemy *e : this->_enemies){
		this->Obstruct(e, this->_tiles);
		this->Obstruct(e, this->_safeZones);
	}
	this->directEnemies();
	if (this->checkHit()){
		this->_gameManager->playerHit(state);
	}
	this->checkCoins(state);
}

void ModelManager::Obstruct(Model *mover, std::vector<Tile*>& walls){
	for (Tile *t : walls){
		if (mover->position()->y() > t->position()->y()-14 && mover->position()->y() < t->position()->y()+14){
			if (mover->position()->x() <= t->position()->x() + 16 && mover->position()->x() >= t->position()->x()){
				mover->position()->x(t->position()->x() + 16);
			}
			else if (mover->position()->x() >= t->position()->x() - 16 && mover->position()->x() <= t->position()->x()){
				mover->position()->x(t->position()->x() - 16);
			}
		}
		if (mover->position()->x() > t->position()->x()-14 && mover->position()->x() < t->position()->x()+14){
			if (mover->position()->y() <= t->position()->y() + 16 && mover->position()->y() >= t->position()->y()){
				mover->position()->y(t->position()->y() + 16);
			}
			else if (mover->position()->y() >= t->position()->y() - 16 && mover->position()->y() <= t->position()->y()){
				mover->position()->y(t->position()->y() - 16);
			}
		}
	}
}

void ModelManager::directEnemies(){
	for (Enemy *e : this->_enemies){
		float dx = this->_player->position()->x() - e->position()->x();
		float dy = this->_player->position()->y() - e->position()->y();
		double enemyAngle = atan2(dy, dx);
		e->inDirection((int)(enemyAngle*180/PI));
	}
}

bool ModelManager::checkHit(){
	for (Enemy *e : this->_enemies){
		if (this->_player->position()->x() > e->position()->x() - 16 &&
			this->_player->position()->y() > e->position()->y() - 16 &&
			this->_player->position()->x() < e->position()->x() + 16 &&
			this->_player->position()->y() < e->position()->y() + 16){

			return true;
		}
	}
	return false;
}

void ModelManager::checkCoins(State& state){
	for (Coin *c : this->_coins){
		if (this->_player->position()->x() > c->position()->x() - 10 &&
			this->_player->position()->y() > c->position()->y() - 10 &&
			this->_player->position()->x() < c->position()->x() + 10 &&
			this->_player->position()->y() < c->position()->y() + 10){

			this->_gameManager->coinCollect(c, state);
		}
	}
}

void ModelManager::resetStage(){
	this->_player->reset();
	for (Enemy *e : this->_enemies){
		e->reset();
	}
	for (Coin *c : this->_coins){
		c->reset();
	}
}