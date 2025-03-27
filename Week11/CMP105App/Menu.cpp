#include "menu.h"

Menu::Menu(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	if (!textFont.loadFromFile("font/arial.ttf")) { std::cout << "error - font not loading"; }
	menuText.setFont(textFont);
	menuText.setPosition(sf::Vector2f(450, 310));
	menuText.setString("\t\t\tGame\nPress Enter key to start");
	menuText.setCharacterSize(35);
}

Menu::~Menu()
{
}

void Menu::handleInput(float dt)
{
	if (input->isPressed(sf::Keyboard::Enter)) 
	{
		gameState->setCurrentState(State::LEVEL);
	}
}

void Menu::update(float dt)
{
	
}

void Menu::render()
{
	beginDraw();
	window->draw(menuText);
	endDraw();
}
