#include "MainGame.h"
#include "GameContext.h"

extern GameContext *GC;

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
}

void MainGame::Initialize()
{
}

void MainGame::LoadContent()
{
}

void MainGame::Update()
{
	if (GC->currentKeyboard[sf::Keyboard::Escape] && !GC->previousKeyboard[sf::Keyboard::Escape])
		GC->GSNext = Paul::PM;
}

void MainGame::Draw()
{
	GC->window.clear(sf::Color::Blue);
	sf::Font font;
	font.loadFromFile("CalibriL.ttf");
	sf::Text text("MainGame", font);
	GC->window.draw(text);
	GC->window.display();
}

void MainGame::UnloadContent()
{
}

void MainGame::EventHandler(sf::Event e)
{
	switch (e.type)
	{
	case sf::Event::Closed:
		GC->window.close();
		break;
	default:
		printf("MainGame: Event Handler not implemented\n");
		break;
	}
}