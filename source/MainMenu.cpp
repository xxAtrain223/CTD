#include "MainMenu.h"
#include "GameContext.h"

extern GameContext *GC;

MainMenu::MainMenu()
{
	Options.push_back("MainGame");
	Options.push_back("WorldEdit");
	Options.push_back("Options");
	Options.push_back("Exit");
	Selected = 0;
}

MainMenu::~MainMenu()
{
	while (!Options.empty())
		Options.pop_back();
}

void MainMenu::Initialize()
{
	GC->SetDebugText("MainMenu");
}

void MainMenu::LoadContent()
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

void MainMenu::SwitchState(int Selected)
{
	switch (Selected)
	{
	case 0:
		GC->GSNext = Paul::MG;
		break;
	case 1:
		GC->GSNext = Paul::WE;
		break;
	case 2:
		GC->SetDebugText("In-Game Options not Implemented");
		break;
	case 3:
		GC->window.close();
		break;
	default:
		break;
	}
}

void MainMenu::Update()
{
	if (GC->currentMousePosition != GC->previousMousePosition)
	{
		for (int i = 0; i < BoundingBoxes.size(); i++)
			if (BoundingBoxes[i].contains(GC->currentMousePosition.x, GC->currentMousePosition.y))
				Selected = i;
	}

	if (keyboardPress(sf::Keyboard::Escape))
		GC->window.close();
	if (keyboardPress(sf::Keyboard::Up))
		Selected = (Selected + Options.size() - 1) % Options.size();
	if (keyboardPress(sf::Keyboard::Down))
		Selected = (Selected + 1) % Options.size();
	if (keyboardPress(sf::Keyboard::Return) ||
		mousePress(LeftMouseButton))
		SwitchState(Selected);
}

void MainMenu::Draw()
{
	GC->window.clear(sf::Color::Red);
	
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
		printf("MainMenu: %-20s handler not implemented\n", GC->GetEventName(e).c_str());
		break;
	}
}