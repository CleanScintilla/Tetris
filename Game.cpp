#include "Game.h"

Game::Game() :BaseApp(18,29)
{
	map.fillTileMatrix();
	map.createTetra();
	map.draw(this);
}

Game::~Game()
{
}

void Game::UpdateF(float deltaTime)
{
	sleepTime += deltaTime;
	if (sleepTime < currentSpeed) {
		return;
	}
	sleepTime -= currentSpeed;
	map.moveDown();
	map.draw(this);
	map.deleteline(&updateSpeed);
	map.End();
	currentSpeed = FALLING_NORMAL_SPD - updateSpeed;
}

void Game::KeyPressed(int btnCode)
{
	switch (btnCode)
	{
	case KEYBOARD_RIGHT:
		map.moveRight();
		break;
	case KEYBOARD_LEFT:
		map.moveLeft();
		break;
	case KEYBOARD_SPACE:
		map.rotate();
		break;
	case KEYBOARD_DOWN:
		currentSpeed = FALLING_FAST_SPD;
		break;
	}
}