#include "GameState.h"

#ifndef MAINMENU
#define MAINMENU
class MainMenu : public GameState
{
public:
	MainMenu();
	~MainMenu();
	
	void Initialize();
	void LoadContent();
	void Update();
	void Draw();
	void UnloadContent();
	void EventHandler(sf::Event);
};
#endif //MAINMENU