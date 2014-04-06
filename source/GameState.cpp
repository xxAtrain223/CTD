#include "GameState.h"
#include "GameContext.h"

extern GameContext *GC;

GameState::GameState()
{
}

GameState::~GameState()
{
}

void GameState::Initialize()
{
	printf("Initialize not implemented\n");
}

void GameState::LoadContent()
{
	printf("LoadContent not implemented\n");
}

void GameState::Update()
{
	printf("Update not implemented\n");
}

void GameState::Draw()
{
	printf("Draw not implemented\n");
	GC->window.clear(sf::Color::Magenta);
	GC->window.display();
}

void GameState::UnloadContent()
{
	printf("Unload Content not implemented\n");
}

void GameState::EventHandler(sf::Event e)
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