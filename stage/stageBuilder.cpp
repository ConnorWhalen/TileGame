#include <fstream>
#include <string>
#include <vector>
#include "stageBuilder.h"

const char* playerBmp = "bitmaps/greenIcon.png";
const char* enemyBmp = "bitmaps/gimpCross.png";
const char* tileBmp = "bitmaps/tile.png";
const char* tile2Bmp = "bitmaps/tile2.png";
const char* greenBmp = "bitmaps/green.png";
const char* coinBmp = "bitmaps/coin.png";
std::string fileRoot = "stages/stage";
int TILE_HEIGHT = 16;
int TILE_WIDTH = 16;

void buildStage(int stageNumber, Player* &player, std::vector<Enemy*>& enemies, std::vector<Coin*>& coins, std::vector<Tile*>& tiles,
				std::vector<Tile*>& safeZones, std::vector<Text*>& startText, std::vector<Text*>& deathText, std::vector<Text*>& pauseText,
				std::vector<Text*>& winText){
	std::string inString;
	std::ifstream inFile;
	inFile.open(fileRoot + std::to_string(stageNumber) + ".txt");
	int row = 0;
	int col;
	int index;
	int prev;
	while (getline(inFile, inString)){
		col = 0;
		if (inString[0] != '#'){
			while (col != inString.length()){
				if (inString[col] == '1'){
					Tile *newTile1 = new Tile(col*TILE_WIDTH, row*TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT, tileBmp);
					tiles.push_back(newTile1);
				}
				else if (inString[col] == '2'){
					Tile *newTile2 = new Tile(col*TILE_WIDTH, row*TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT, tile2Bmp);
					tiles.push_back(newTile2);
				}
				else if (inString[col] == 's'){
					Tile *safe = new Tile(col*TILE_WIDTH, row*TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT, greenBmp);
					safeZones.push_back(safe);
				}
				else if (inString[col] == 'p'){
					player = new Player(col*TILE_WIDTH, row*TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT, playerBmp);
				}
				else if (inString[col] == 'e'){
					Enemy *newEnemy = new Enemy(col*TILE_WIDTH, row*TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT, enemyBmp);
					enemies.push_back(newEnemy);
				}
				else if (inString[col] == 'c'){
					Coin *newCoin = new Coin(col*TILE_WIDTH, row*TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT, coinBmp);
					coins.push_back(newCoin);
				}
				col++;
			}
		}
		else{
			prev = 2;
			index = inString.find('"', prev+1);
			std::string *phraseStr = new std::string(inString.substr(prev+1, (index-prev-1)));

			prev = index + 1;
			index = inString.find(' ', prev+1);
			std::string *colorStr = new std::string(inString.substr(prev+1, (index-prev-1)));

			prev = index;
			index = inString.find(' ', prev+1);
			std::string *fontFileStr = new std::string("fonts/" + inString.substr(prev+1, (index-prev-1)));

			prev = index;
			index = inString.find(' ', prev+1);
			float xPos = stof(inString.substr(prev+1, (index-prev-1)));

			prev = index;
			index = inString.find(' ', prev+1);
			float yPos = stof(inString.substr(prev+1, (index-prev-1)));

			Position *pos = new Position(xPos, yPos);

			prev = index;
			index = inString.find(' ', prev+1);
			int fontSize = stoi(inString.substr(prev+1, (index-prev-1)));

			prev = index;
			index = inString.find(' ', prev+1);
			std::string state = inString.substr(prev+1, (index-prev-1));

			Text *text = new Text(phraseStr, colorStr, fontFileStr, pos, fontSize);
			if (state == "start"){
				startText.push_back(text);
			}
			else if (state == "death"){
				deathText.push_back(text);
			}
			else if (state == "pause"){
				pauseText.push_back(text);
			}
			else if (state == "win"){
				winText.push_back(text);
			}
		}
		row++;
	}
	inFile.close();
}