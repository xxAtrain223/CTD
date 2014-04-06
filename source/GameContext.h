#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <vector>

#include "GameState.h"
#include "MainMenu.h"

using namespace std;

#ifndef _GAMECONTEXT_
#define _GAMECONTEXT_

enum Paul
{
	NU = -1,
	ER = 0,
	MM,
	MG,
	PM,
	WE
};

class GameContext
{
public:
	sf::RenderWindow window;

	bool previousKeyboard[sf::Keyboard::KeyCount];
	bool currentKeyboard[sf::Keyboard::KeyCount];

	GameState *GS;
	Paul GSNext;
	
	GameContext();
	GameContext(sf::VideoMode, string);
	~GameContext();

	void SetState();
	void SetState(Paul);
	void AddGameState(GameState*);

protected:
	vector<GameState*> GSVec;
};

#endif  //_GAMECONTEXT_