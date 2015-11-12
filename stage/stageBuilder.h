#include "../tile.h"
#include "../text.h"
#include "../player.h"
#include "../enemy.h"
#include "../coin.h"

void buildStage(int stageNumber, Player* &player, std::vector<Enemy*>& enemies, std::vector<Coin*>& coins, std::vector<Tile*>& tiles,
				std::vector<Tile*>& safeZones, std::vector<Text*>& startText, std::vector<Text*>& deathText, std::vector<Text*>& pauseText,
				std::vector<Text*>& winText);