#ifndef MENUANIMATION_H
#define MENUANIMATION_H

#include "menuDisplay.h"
#include "../model.h"
#include <vector>

class MenuAnimation {
	public:
		MenuAnimation(MenuDisplay* display);
		void createTile();
		void updateAnimation();
	private:
		MenuDisplay* _display;
		Model* _current;
		int _currentCol;
		bool _complete;
		std::vector<int> _columns;
};

#endif