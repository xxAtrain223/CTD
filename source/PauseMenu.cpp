#include "PauseMenu.h"
#include "GameContext.h"

extern GameContext *GC;

PauseMenu::PauseMenu()
{
	Options.push_back("MainGame");
	Options.push_back("MainMenu");
	Options.push_back("Options");

	Selected = 0;
}

PauseMenu::~PauseMenu()
{
	while (!Options.empty())
		Options.pop_back();
}

void PauseMenu::Initialize()
{
	GC->SetDebugText("PauseMenu");
}

void PauseMenu::LoadContent()
{
	if (!Font.loadFromFile("CalibriL.ttf"))
		perror("CalibriL.ttf");
	Text.setFont(Font);
	Text.setCharacterSize(32);

	if (BoundingBoxes.empty())
	{
		sf::Vector2u winSize = GC->window.getSize();
		sf::FloatRect textBoundingBox;

		for (int i = 0; i < Options.size(); i++)
		{
			Text.setString(Options[i]);
			textBoundingBox = Text.getLocalBounds();
			textBoundingBox.top = winSize.y / 2 + textBoundingBox.height * 2 * i;
			textBoundingBox.left = winSize.x / 2 - textBoundingBox.width / 2;
			BoundingBoxes.push_back(textBoundingBox);
		}
	}
}

void PauseMenu::SwitchState(int Selected)
{
	switch (Selected)
	{
	case 0:
		GC->GSNext = Paul::MG;
		break;
	case 1:
		GC->GSNext = Paul::MM;
		break;
	case 2:
		GC->SetDebugText("In-Game Options not Implemented");
		break;
	default:
		break;
	}
}

void PauseMenu::Update()
{
	if (GC->currentMousePosition != GC->previousMousePosition)
	{
		for (int i = 0; i < BoundingBoxes.size(); i++)
			if (BoundingBoxes[i].contains(GC->currentMousePosition.x, GC->currentMousePosition.y))
				Selected = i;
	}

	if (keyboardPress(sf::Keyboard::Escape))
		GC->GSNext = Paul::MG;
	if (keyboardPress(sf::Keyboard::Up))
		Selected = (Selected + Options.size() - 1) % Options.size();
	if (keyboardPress(sf::Keyboard::Down))
		Selected = (Selected + 1) % Options.size();
	if (keyboardPress(sf::Keyboard::Return) ||
		mousePress(LeftMouseButton))
		SwitchState(Selected);
}

void PauseMenu::Draw()
{
	GC->window.clear(sf::Color::Green);
	
	for (int i = 0; i < Options.size(); i++)
	{
		Text.setString(Options[i]);
		Text.setPosition(BoundingBoxes[i].left, BoundingBoxes[i].top - BoundingBoxes[i].height / 2);
		if (i == Selected)
			Text.setColor(sf::Color::Yellow);
		else
			Text.setColor(sf::Color::White);
		GC->window.draw(Text);
	}
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