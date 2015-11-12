#ifndef MENU_H
#define MENU_H

#include "../state.h"
#include "menuDisplay.h"
#include "menuAnimation.h"
#include "menuEventManager.h"
#include "../text.h"
#include "../timer.h"

#include <string>

class Menu {
	public:
		Menu();
		void launchMenu(State& state, int screenWidth, int screenHeight);
		void populateMenu(std::vector<Text*>& titleText, std::vector<Text*>& selectableText, std::vector<Text*>& selectedText,
						  std::vector<Text*>& optionsText, int& choices);
	private:
};

#endif