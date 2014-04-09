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
}

void MainGame::Draw()
{
	GC->window.clear(sf::Color::Blue);
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
		printf("Event Handler not implemented\n");
		break;
	}
}