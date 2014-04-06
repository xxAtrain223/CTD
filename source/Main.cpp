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

#include "GameContext.h"
#include "GameState.h"
#include "MainMenu.h"

using namespace std;

GameContext *GC;

int main()
{
	GC = new GameContext(sf::VideoMode(960, 720), "Custom Tower Defence");
	GC->window.setFramerateLimit(60);
	GC->AddGameState(new GameState);
	GC->AddGameState(new MainMenu);

	GC->SetState(Paul::MM);
	GC->GS->Initialize();
	GC->GS->LoadContent();

	while (GC->window.isOpen())
	{
		sf::Event event;
		while (GC->window.pollEvent(event))
			GC->GS->EventHandler(event);

		GC->GS->Update();
		GC->GS->Draw();

		GC->SetState();
	}

	GC->GS->UnloadContent();
	
	return 0;
}