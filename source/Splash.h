#include "GameState.h"

#ifndef SPLASH
#define SPLASH
class Splash : public GameState
{
public:
	Splash();
	~Splash();

	void Initialize();
	void LoadContent();
	void Update();
	void Draw();
	void UnloadContent();
	void EventHandler(sf::Event);
};
#endif //SPLASH