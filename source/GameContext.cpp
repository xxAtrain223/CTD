#include "GameContext.h"

GameContext::GameContext()
{
	GS = NULL;
	for (int i = 0; i < sf::Keyboard::KeyCount; i++)
	{
		previousKeyboard[i] = false;
		currentKeyboard[i] = false;
	}
	
	previousMousePosition = sf::Vector2i(0, 0);
	currentMousePosition = sf::Vector2i(0, 0);
	previousMouseButtonState = 0x0;
	currentMouseButtonState = 0x0;
}

GameContext::GameContext(sf::VideoMode vm, string windowName)
{
	GS = NULL;
	for (int i = 0; i < sf::Keyboard::KeyCount; i++)
	{
		previousKeyboard[i] = false;
		currentKeyboard[i] = false;
	}

	previousMousePosition = sf::Vector2i(0, 0);
	currentMousePosition = sf::Vector2i(0, 0);
	previousMouseButtonState = 0x0;
	currentMouseButtonState = 0x0;

	window.create(vm, windowName, sf::Style::Close | sf::Style::Titlebar);
}

GameContext::~GameContext()
{
	GS = NULL;
	for (int i = 0; i < (signed)GSVec.size(); i++)
		delete GSVec[i];
}


void GameContext::SetState()
{
	if (GSNext != Paul::NU)
	{
		GS = GSVec[GSNext];
		GSNext = Paul::NU;
	}
}

void GameContext::SetState(Paul p)
{
	if (GS != NULL && p != Paul::NU)
		GS->UnloadContent();

	if (p != Paul::NU)
		GS = GSVec[p];
	else if (GSNext != Paul::NU)
		GS = GSVec[GSNext];

	GS->Initialize();
	GS->LoadContent();

	GSNext = Paul::NU;
}

void GameContext::AddGameState(GameState* gs)
{
	GSVec.push_back(gs);
}

void GameContext::UpdateKeyboard()
{
	for (int i = 0; i < sf::Keyboard::KeyCount; i++)
	{
		previousKeyboard[i] = currentKeyboard[i];
		if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i))
			currentKeyboard[i] = true;
		else
			currentKeyboard[i] = false;
	}
}

void GameContext::UpdateMouse()
{
	previousMousePosition = currentMousePosition;
	currentMousePosition = sf::Mouse::getPosition();

	previousMouseButtonState = currentMouseButtonState;
	currentMouseButtonState = 0x000;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		currentMouseButtonState |= LeftMouseButton;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
		currentMouseButtonState |= MiddleMouseButton;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		currentMouseButtonState |= RightMouseButton;
}