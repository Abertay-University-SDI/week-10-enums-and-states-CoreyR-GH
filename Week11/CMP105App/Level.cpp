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
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	ball.move(sf::Vector2f(ballSpeed * dt, 0));

	if (ball.getPosition().x + (ball.getRadius() * 2) > 1200 || ball.getPosition().x < 0) { ballSpeed = -ballSpeed; }
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(ball);

	endDraw();
}

