#include "WorldEdit.h"
#include "GameContext.h"

extern GameContext *GC;

WorldEdit::WorldEdit()
{
	FlashAlphaColor = 64;
	FlashAlphaColorModVal = 1;
}

WorldEdit::~WorldEdit()
{
}

void WorldEdit::Initialize()
{
	if (Squares.empty())
	{
		Squares.resize(16);
		SquareColor.resize(16);
		for (int i = 0; i < Squares.size(); i++)
		{
			Squares[i].resize(12);
			SquareColor[i].resize(12);
			for (int j = 0; j < Squares[i].size(); j++)
			{
				if ((i + j) % 2)
					SquareColor[i][j] = sf::Color::White;
				else
					SquareColor[i][j] = sf::Color::Black;
				Squares[i][j].setPosition(sf::Vector2f(50 * i + 3 * (i + 1), 50 * j + 3 * (j + 1)));
				Squares[i][j].setSize(sf::Vector2f(50, 50));
				Squares[i][j].setFillColor(SquareColor[i][j]);
				Squares[i][j].setOutlineColor(sf::Color::Black);
				Squares[i][j].setOutlineThickness(1.5);
			}
		}
	}
}

void WorldEdit::LoadContent()
{
	GC->SetDebugText("WorldEdit");
	if (!UIOverlayTexture.loadFromFile("UIOverlay.png"))
		printf("Failed to load texture: %s\n", "UIOverlay.png");
	UIOverlaySprite.setTexture(UIOverlayTexture);
}

void WorldEdit::UpdateFlash()
{
	if ((FlashAlphaColor + FlashAlphaColorModVal) < 64 || (FlashAlphaColor + FlashAlphaColorModVal) > 128)
		FlashAlphaColorModVal *= -1;
	FlashAlphaColor += FlashAlphaColorModVal;
}

void WorldEdit::Update()
{
	if (keyboardPress(sf::Keyboard::Escape))
		GC->GSNext = Paul::MM;

	UpdateFlash();

	sf::FloatRect BoundingBox;
	
	for (int i = 0; i < Squares.size(); i++)
	{
		for (int j = 0; j < Squares[i].size(); j++)
		{
			if (Squares[i][j].getGlobalBounds().contains(GC->currentMousePosition.x, GC->currentMousePosition.y))
				Squares[i][j].setFillColor(sf::Color(SquareColor[i][j].r, SquareColor[i][j].g, SquareColor[i][j].b, FlashAlphaColor));
			else
				Squares[i][j].setFillColor(SquareColor[i][j]);
		}
	}
}

void WorldEdit::Draw()
{
	GC->window.clear(sf::Color::Yellow);
	GC->window.draw(UIOverlaySprite);
	for (int i = 0; i < Squares.size(); i++)
		for (int j = 0; j < Squares[i].size(); j++)
			GC->window.draw(Squares[i][j]);
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