#include "WorldEdit.h"
#include "GameContext.h"

extern GameContext *GC;

WorldEdit::WorldEdit()
{
}

WorldEdit::~WorldEdit()
{
}

void WorldEdit::Initialize()
{
}

void WorldEdit::LoadContent()
{
}

void WorldEdit::Update()
{
	if (GC->currentKeyboard[sf::Keyboard::Escape] && !GC->previousKeyboard[sf::Keyboard::Escape])
		GC->GSNext = Paul::MM;
}

void WorldEdit::Draw()
{
	GC->window.clear(sf::Color::Cyan);
	sf::Font font;
	font.loadFromFile("CalibriL.ttf");
	sf::Text text("WorldEdit", font);
	GC->window.draw(text);
	GC->window.display();
}

void WorldEdit::UnloadContent()
{
}

void WorldEdit::EventHandler(sf::Event e)
{
	switch (e.type)
	{
	case sf::Event::Closed:
		GC->window.close();
		break;
	default:
		printf("WorldEdit: Event Handler not implemented\n");
		break;
	}
}