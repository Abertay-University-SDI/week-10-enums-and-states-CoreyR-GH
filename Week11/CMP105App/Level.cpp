#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");

	ballSpeed = 200;

	ball.setRadius(80);
	ball.setFillColor(sf::Color::Blue);
	ball.setPosition(200, 250);


	if (!textFont.loadFromFile("font/arial.ttf")) { std::cout << "error - font not loading"; }
	pauseText.setFont(textFont);
	pauseText.setPosition(sf::Vector2f(550, 310));
	pauseText.setString("Paused");
	pauseText.setCharacterSize(60);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isPressed(sf::Keyboard::Escape)) 
	{
		switch (gameState->getCurrentState())
		{
		case(State::LEVEL):
			gameState->setCurrentState(State::PAUSE);
			break;
		case(State::PAUSE):
			gameState->setCurrentState(State::LEVEL);
			break;
		}
	}
}

// Update game objects
void Level::update(float dt)
{
	switch (gameState->getCurrentState()) 
	{
	case(State::LEVEL):	
		ball.move(sf::Vector2f(ballSpeed * dt, 0));

		if (ball.getPosition().x + (ball.getRadius() * 2) > 1200 || ball.getPosition().x < 0) { ballSpeed = -ballSpeed; }
		break;
	case(State::PAUSE):
		break;
	}

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(ball);

	if (gameState->getCurrentState() == State::PAUSE) { window->draw(pauseText); }

	endDraw();
}

