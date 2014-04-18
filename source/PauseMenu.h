#include "GameState.h"

#ifndef PAUSEMENU
#define PAUSEMENU
class PauseMenu : public GameState
{
public:
	PauseMenu();
	~PauseMenu();

	void Initialize();
	void LoadContent();
	void Update();
	void Draw();
	void UnloadContent();
	void EventHandler(sf::Event);
};
#endif //PAUSEMENU