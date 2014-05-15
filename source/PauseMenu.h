#include "GameState.h"

#ifndef PAUSEMENU
#define PAUSEMENU
class PauseMenu : public GameState
{
public:
	PauseMenu();
	~PauseMenu();

	//Standard Game Functions
	void Initialize();
	void LoadContent();
	void Update();
	void Draw();
	void UnloadContent();
	void EventHandler(sf::Event);

	void SwitchState(int);

protected:
	//Variables for the Pause Menu
	vector<string> Options;
	vector<sf::FloatRect> BoundingBoxes;
	sf::Font Font;
	sf::Text Text;
	int Selected;
};
#endif //PAUSEMENU