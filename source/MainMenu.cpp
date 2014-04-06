#include "MainMenu.h"
#include "GameContext.h"

extern GameContext *GC;

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::Initialize()
{
}

void MainMenu::LoadContent()
{
}

void MainMenu::Update()
{
}

void MainMenu::Draw()
{
	GC->window.clear(sf::Color::Red);
	GC->window.display();
}

void MainMenu::UnloadContent()
{
}

void MainMenu::EventHandler(sf::Event e)
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