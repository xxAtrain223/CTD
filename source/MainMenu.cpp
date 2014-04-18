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
	if (GC->currentKeyboard[sf::Keyboard::Escape] && !GC->previousKeyboard[sf::Keyboard::Escape])
		GC->window.close();
	if (GC->currentKeyboard[sf::Keyboard::Num1] && !GC->previousKeyboard[sf::Keyboard::Num1])
		GC->GSNext = Paul::MG;
	if (GC->currentKeyboard[sf::Keyboard::Num2] && !GC->previousKeyboard[sf::Keyboard::Num2])
		GC->GSNext = Paul::WE;
}

void MainMenu::Draw()
{
	GC->window.clear(sf::Color::Red);
	sf::Font font;
	font.loadFromFile("CalibriL.ttf");
	sf::Text text("MainMenu", font);
	GC->window.draw(text);
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
		printf("MainMenu: Event Handler not implemented\n");
		break;
	}
}