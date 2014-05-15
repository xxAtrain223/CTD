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
	GC->SetDebugText("WorldEdit");
	if (!UIOverlayTexture.loadFromFile("UIOverlay.png"))
		printf("Failed to load texture: %s\n", "UIOverlay.png");
	UIOverlaySprite.setTexture(UIOverlayTexture);
}

void WorldEdit::Update()
{
	if (keyboardPress(sf::Keyboard::Escape))
		GC->GSNext = Paul::MM;
}

void WorldEdit::Draw()
{
	GC->window.clear(sf::Color::Cyan);
	GC->window.draw(UIOverlaySprite);
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