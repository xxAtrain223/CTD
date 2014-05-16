#include "GameContext.h"
#include <iostream>

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

	DebugFont.loadFromFile("cour.ttf");
	DebugText.setFont(DebugFont);
	DebugText.setCharacterSize(20);
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
	DebugFont.loadFromFile("cour.ttf");
	DebugText.setFont(DebugFont);
	DebugText.setCharacterSize(20);
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
		if (GS != NULL)
			GS->UnloadContent();

		GS = GSVec[GSNext];
		GSNext = Paul::NU;

		GS->Initialize();
		GS->LoadContent();

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
		if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i) && IsFocused)
			currentKeyboard[i] = true;
		else
			currentKeyboard[i] = false;
	}
}

void GameContext::UpdateMouse()
{
	previousMousePosition = currentMousePosition;
	if (IsFocused)
		currentMousePosition = sf::Mouse::getPosition(window);
	else
		currentMousePosition = sf::Vector2i(-1, -1);

	previousMouseButtonState = currentMouseButtonState;
	currentMouseButtonState = 0x000;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && IsFocused)
		currentMouseButtonState |= LeftMouseButton;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Middle) && IsFocused)
		currentMouseButtonState |= MiddleMouseButton;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && IsFocused)
		currentMouseButtonState |= RightMouseButton;
}

void GameContext::SetDebugText(string str)
{
 	DebugTextUpdateTime = clock();
	DebugText.setString(str);
	printf("%s\n", str.c_str());
}

void GameContext::DrawDebugText()
{
	int numLines = 1;
	string str = DebugText.getString();
	float alpha = ((float)(CLOCKS_PER_SEC * 5 - (clock() - DebugTextUpdateTime)) / (CLOCKS_PER_SEC * 5)) * 255;
	sf::Color color(255, 255, 255, alpha);
	for (int i = 0; i < str.length(); i++)
		if (str[i] == '\n')
			numLines++;

	DebugText.setPosition(0, window.getSize().y - (numLines)* DebugFont.getLineSpacing(DebugText.getCharacterSize()));
	if (alpha >= 0)
	{
		DebugText.setColor(color);
		window.draw(DebugText);
	}
}