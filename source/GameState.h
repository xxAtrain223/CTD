#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <cstdio>
#include <cstdlib>

using namespace std;

#ifndef GAMESTATE
#define GAMESTATE

class GameState
{
public:
	GameState();
	~GameState();

	//Standard Game Functions
	virtual void Initialize();
	virtual void LoadContent();
	virtual void Update();
	virtual void Draw();
	virtual void UnloadContent();
	virtual void EventHandler(sf::Event);
};

#endif // !GAMESTATE