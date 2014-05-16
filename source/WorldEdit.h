#include "GameState.h"

#ifndef WORLDEDIT
#define WORLDEDIT
class WorldEdit : public GameState
{
public:
	WorldEdit();
	~WorldEdit();

	//Standard Game Functions
	void Initialize();
	void LoadContent();
	void Update();
	void Draw();
	void UnloadContent();
	void EventHandler(sf::Event);

	void UpdateFlash();

	//Used to display the UI Overlay
	sf::Texture UIOverlayTexture;
	sf::Sprite UIOverlaySprite;
	vector< vector<sf::RectangleShape> > Squares;
	vector< vector<sf::Color> > SquareColor;
	float FlashAlphaColor;
	float FlashAlphaColorModVal;
};
#endif //WORLDEDIT