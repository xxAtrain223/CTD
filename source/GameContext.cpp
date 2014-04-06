#include "GameContext.h"

GameContext::GameContext()
{
	GS = NULL;
	for (int i = 0; i < sf::Keyboard::KeyCount; i++)
	{
		previousKeyboard[i] = false;
		currentKeyboard[i] = false;
	}
}

GameContext::GameContext(sf::VideoMode vm, string windowName)
{
	GS = NULL;
	for (int i = 0; i < sf::Keyboard::KeyCount; i++)
	{
		previousKeyboard[i] = false;
		currentKeyboard[i] = false;
	}

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