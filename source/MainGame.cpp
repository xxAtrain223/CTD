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
	GC->SetDebugText("MainGame");
	if (!UIOverlayTexture.loadFromFile("UIOverlay.png"))
		printf("Failed to load texture: %s\n", "UIOverlay.png");
	UIOverlaySprite.setTexture(UIOverlayTexture);
}

void MainGame::LoadContent()
{
}

void MainGame::Update()
{
	if (keyboardPress(sf::Keyboard::Escape))
		GC->GSNext = Paul::PM;
}

void MainGame::Draw()
{
	GC->window.clear(sf::Color::Blue);
	GC->window.draw(UIOverlaySprite);
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
		printf("MainGame: %-20s handler not implemented\n", GC->GetEventName(e).c_str());
		break;
	}
}