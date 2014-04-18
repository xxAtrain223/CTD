#include "PauseMenu.h"
#include "GameContext.h"

extern GameContext *GC;

PauseMenu::PauseMenu()
{
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::Initialize()
{
}

void PauseMenu::LoadContent()
{
}

void PauseMenu::Update()
{
	if (GC->currentKeyboard[sf::Keyboard::Escape] && !GC->previousKeyboard[sf::Keyboard::Escape])
		GC->GSNext = Paul::MG;
	if (GC->currentKeyboard[sf::Keyboard::Num1] && !GC->previousKeyboard[sf::Keyboard::Num1])
		GC->GSNext = Paul::MM;
}

void PauseMenu::Draw()
{
	GC->window.clear(sf::Color::Green);
	sf::Font font;
	font.loadFromFile("CalibriL.ttf");
	sf::Text text("PauseMenu", font);
	GC->window.draw(text);
	GC->window.display();
}

void PauseMenu::UnloadContent()
{
}

void PauseMenu::EventHandler(sf::Event e)
{
	switch (e.type)
	{
	case sf::Event::Closed:
		GC->window.close();
		break;
	default:
		printf("PauseMenu: Event Handler not implemented\n");
		break;
	}
}