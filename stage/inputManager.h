#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "../player.h"

class InputManager{
	public:
		InputManager(Player *player);
		void setPlayerSpeed(double speed);
		void setPlayerDirection(int angle);
		void playerUp();
		void playerDown();
		void playerLeft();
		void playerRight();
		void playerUpRelease();
		void playerDownRelease();
		void playerLeftRelease();
		void playerRightRelease();
	private:
		Player *_player;
		bool _up;
		bool _down;
		bool _left;
		bool _right;
};

#endif