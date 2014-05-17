#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <vector>
#include <ctime>

#include "GameState.h"
#include "MainMenu.h"

using namespace std;

#ifndef _GAMECONTEXT_
#define _GAMECONTEXT_

//Enumeration to reference the GameStates
enum Paul
{
	NU = -1,
	ER = 0,
	MM,
	MG,
	PM,
	WE
};

//Macros for the Mouse Buttons
#define LeftMouseButton 0x001
#define RightMouseButton 0x010
#define MiddleMouseButton 0x100

//Macros for key/button press/release/held
#define keyboardPress(key) GC->currentKeyboard[key] && !GC->previousKeyboard[key]
#define keyboardRelease(key) !GC->currentKeyboard[key] && GC->previousKeyboard[key]
#define keyboardHeld(key) GC->currentKeyboard[key]
#define mousePress(button) (GC->currentMouseButtonState & button) && !(GC->previousMouseButtonState & button)
#define mouseRelease(button) !(GC->currentMouseButtonState & button) && (GC->previousMouseButtonState & button)
#define mouseHeld(button) GC->currentMouseButtonState & button

class GameContext
{
public:
	//Game window
	sf::RenderWindow window;
	bool IsFocused = true;

	//Variables for 'input snapshots'
	bool previousKeyboard[sf::Keyboard::KeyCount];
	bool currentKeyboard[sf::Keyboard::KeyCount];
	sf::Vector2i previousMousePosition;
	sf::Vector2i currentMousePosition;
	int previousMouseButtonState;
	int currentMouseButtonState;

	//Current Gamestate and reference to next Gamestate
	GameState *GS;
	Paul GSNext;
	
	//Constructors and Deconstructors
	GameContext();
	GameContext(sf::VideoMode, string);
	~GameContext();

	//Used to change and add Gamestates
	void SetState();
	void SetState(Paul);
	void AddGameState(GameState*);

	//Updates the mouse and keyboard
	void UpdateKeyboard();
	void UpdateMouse();

	//Sets ands draws debug text to the screen
	void SetDebugText(string);
	void DrawDebugText();

	static string GetEventName(sf::Event);

protected:
	vector<GameState*> GSVec;
	clock_t DebugTextUpdateTime;
	sf::Font DebugFont;
	sf::Text DebugText;
};

#endif  //_GAMECONTEXT_