#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC

#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <iostream>

#include "GameContext.h"
#include "GameState.h"
#include "MainMenu.h"
#include "MainGame.h"

using namespace std;

GameContext *GC;

void DisplaySplashScreen(string fileName)
{
	sf::Texture texture;
	texture.loadFromFile(fileName);
	sf::RenderWindow splashWindow(sf::VideoMode(texture.getSize().x, texture.getSize().y), "Custom Tower Defense", sf::Style::None, sf::ContextSettings(0, 0, 0, 2, 0));
	sf::Sprite sprite;
	sprite.setTexture(texture);
	splashWindow.clear(sf::Color::Transparent);
	splashWindow.draw(sprite);
	splashWindow.display();
	sf::sleep(sf::seconds(3));
	splashWindow.close();
}

int main()
{
	string str;

	DisplaySplashScreen("img_gameon_brand1.jpg");
	
	GC = new GameContext(sf::VideoMode(960, 720), "Custom Tower Defence");
	GC->window.setFramerateLimit(60);
	GC->AddGameState(new GameState);
	GC->AddGameState(new MainMenu);
	GC->AddGameState(new MainGame);

	GC->SetState(Paul::MM);
	GC->GS->Initialize();
	GC->GS->LoadContent();

	while (GC->window.isOpen())
	{
		sf::Event event;
		while (GC->window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				GC->window.close();
				break;
			case sf::Event::KeyPressed:
			case sf::Event::KeyReleased:
				GC->UpdateKeyboard(event);
				break;
			case sf::Event::MouseButtonPressed:
			case sf::Event::MouseButtonReleased:
			case sf::Event::MouseMoved:
				GC->UpdateMouse(event);
				break;
			default:
				GC->GS->EventHandler(event);
				break;
			}
		}

		GC->GS->Update();
		GC->GS->Draw();

		GC->SetState();
	}

	GC->GS->UnloadContent();

	printf("Exiting...\n");
	getline(cin, str);

	return 0;
}