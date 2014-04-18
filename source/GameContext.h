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

#define LeftMouseButton 0x001
#define RightMouseButton 0x010
#define MiddleMouseButton 0x100

class GameContext
{
public:
	sf::RenderWindow window;

	bool previousKeyboard[sf::Keyboard::KeyCount];
	bool currentKeyboard[sf::Keyboard::KeyCount];
	sf::Vector2i previousMousePosition;
	sf::Vector2i currentMousePosition;
	int previousMouseButtonState;
	int currentMouseButtonState;

	GameState *GS;
	Paul GSNext;
	
	GameContext();
	GameContext(sf::VideoMode, string);
	~GameContext();

	void SetState();
	void SetState(Paul);
	void AddGameState(GameState*);

	void UpdateKeyboard();
	void UpdateMouse();

protected:
	vector<GameState*> GSVec;
};

#endif  //_GAMECONTEXT_