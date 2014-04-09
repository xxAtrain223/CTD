#include "GameState.h"

#ifndef MAINGAME
#define MAINGAME
class MainGame : public GameState
{
public:
	MainGame();
	~MainGame();

	void Initialize();
	void LoadContent();
	void Update();
	void Draw();
	void UnloadContent();
	void EventHandler(sf::Event);
};
#endif //MAINGAME