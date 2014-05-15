#include "GameState.h"

#ifndef MAINGAME
#define MAINGAME
class MainGame : public GameState
{
public:
	MainGame();
	~MainGame();

	//Standard Game Functions
	void Initialize();
	void LoadContent();
	void Update();
	void Draw();
	void UnloadContent();
	void EventHandler(sf::Event);

protected:
	//Variables for the Main Game
	sf::Texture UIOverlayTexture;
	sf::Sprite UIOverlaySprite;
};
#endif //MAINGAME