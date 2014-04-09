#include "Splash.h"
#include "GameContext.h"

extern GameContext *GC;

Splash::Splash()
{
}

Splash::~Splash()
{
}

void Splash::Initialize()
{
}

void Splash::LoadContent()
{
}

void Splash::Update()
{
}

void Splash::Draw()
{
	/*
	GC->window.
	GC->window.clear(sf::Color::Transparent);
	GC->window.display();
	*/
}

void Splash::UnloadContent()
{
}

void Splash::EventHandler(sf::Event e)
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