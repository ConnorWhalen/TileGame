#include "menu.h"

std::string* menuFont = new std::string("fonts/Instruction.otf");
std::string* title1Text = new std::string("WILD TILE");
std::string* title2Text = new std::string("ADVENTURE");
std::string* title3Text = new std::string("III");
std::string* option1Text = new std::string("New Game");
std::string* option2Text = new std::string("Do Nothing");
std::string* option3Text = new std::string("Controls/Settings");
std::string* controls1Text = new std::string("Use the arrow keys to move");
std::string* controls2Text = new std::string("Press enter to pause");
std::string* controls3Text = new std::string("(Also press enter to go back to the main menu)");
std::string* titleColor = new std::string("red");
std::string* selectableColor = new std::string("red");
std::string* selectedColor = new std::string("blue");
std::string* controlsColor1 = new std::string("maroon");
std::string* controlsColor2 = new std::string("aquamarine");

Menu::Menu(){}

void Menu::launchMenu(State& state, int screenWidth, int screenHeight){
	MenuDisplay *menuDisplay = new MenuDisplay(screenWidth, screenHeight);
	MenuAnimation *animator = new MenuAnimation(menuDisplay);
	Timer *timer = new Timer(60);
	std::vector<Text*> titleText;
	std::vector<Text*> selectableText;
	std::vector<Text*> selectedText;
	std::vector<Text*> optionsText;
	int choices = 0;
	populateMenu(titleText, selectableText, selectedText, optionsText, choices);
	int selectedChoice = 0;

	for (Text* t : titleText){
		menuDisplay->addTitleText(t);
	}
	for (Text* t : selectableText){
		menuDisplay->addSelectableText(t);
	}
	for (Text* t : selectedText){
		menuDisplay->addSelectedText(t);
	}
	for (Text* t : optionsText){
		menuDisplay->addOptionsText(t);
	}

	MenuEventManager *menuEventMan = new MenuEventManager(menuDisplay, animator, timer);

	while (state == State::MENU || state == State::OPTIONS){
		if (state == State::MENU){	
			menuEventMan->launchMenu(state, selectedChoice, choices);
		}
		else if (state == State::OPTIONS){
			menuEventMan->launchOptionsMenu(state);
		}
	}

	delete menuDisplay;
	delete animator;
	delete timer;
	titleText.clear();
	selectableText.clear();
	selectedText.clear();
	optionsText.clear();
	delete menuEventMan;
}

void Menu::populateMenu(std::vector<Text*>& titleText, std::vector<Text*>& selectableText, std::vector<Text*>& selectedText,
						std::vector<Text*>& optionsText, int& choices){
	Text *title1 = new Text(title1Text, titleColor, menuFont, new Position(64, 22), 48);
	titleText.push_back(title1);

	Text *title2 = new Text(title2Text, titleColor, menuFont, new Position(64, 70), 48);
	titleText.push_back(title2);

	Text *title3 = new Text(title3Text, titleColor, menuFont, new Position(122, 108), 60);
	titleText.push_back(title3);

	Text *option1a = new Text(option1Text, selectableColor, menuFont, new Position(122, 190), 24);
	Text *option1b = new Text(option1Text, selectedColor, menuFont, new Position(118, 189), 26);
	selectableText.push_back(option1a);
	selectedText.push_back(option1b);

	Text *option2a = new Text(option2Text, selectableColor, menuFont, new Position(110, 220), 24);
	Text *option2b = new Text(option2Text, selectedColor, menuFont, new Position(105, 219), 26);
	selectableText.push_back(option2a);
	selectedText.push_back(option2b);

	Text *option3a = new Text(option3Text, selectableColor, menuFont, new Position(72, 250), 24);
	Text *option3b = new Text(option3Text, selectedColor, menuFont, new Position(64, 249), 26);
	selectableText.push_back(option3a);
	selectedText.push_back(option3b);

	Text *controls1 = new Text(controls1Text, controlsColor1, menuFont, new Position(32, 32), 20);
	optionsText.push_back(controls1);

	Text *controls2 = new Text(controls2Text, controlsColor1, menuFont, new Position(32, 64), 20);
	optionsText.push_back(controls2);

	Text *controls3 = new Text(controls3Text, controlsColor2, menuFont, new Position(32, 100), 10);
	optionsText.push_back(controls3);

	choices = selectableText.size();
}