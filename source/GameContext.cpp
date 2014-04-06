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
		GS = GSVec[GSNext];
}

void GameContext::SetState(Paul p)
{
	if (GS != NULL)
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

void GameContext::UpdateKeyboard(sf::Event e)
{
	previousKeyboard[e.key.code] = currentKeyboard[e.key.code];
	
	if (e.type == sf::Event::KeyPressed)
		currentKeyboard[e.key.code] = true;
	else if (e.type == sf::Event::KeyReleased)
		currentKeyboard[e.key.code] = false;
}

void GameContext::UpdateMouse(sf::Event e)
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