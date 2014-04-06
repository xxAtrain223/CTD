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

using namespace std;

GameContext *GC;

int main()
{
	string str;
	GC = new GameContext(sf::VideoMode(960, 720), "Custom Tower Defence");
	GC->window.setFramerateLimit(60);
	GC->AddGameState(new GameState);
	GC->AddGameState(new MainMenu);

	GC->SetState(Paul::ER);
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