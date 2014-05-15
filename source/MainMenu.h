#include "GameState.h"

#ifndef MAINMENU
#define MAINMENU
class MainMenu : public GameState
{
public:
	MainMenu();
	~MainMenu();
	
	//Standard Game Functions
	void Initialize();
	void LoadContent();
	void Update();
	void Draw();
	void UnloadContent();
	void EventHandler(sf::Event);

	void SwitchState(int);

protected:
	//Variables for the Main Menu
	vector<string> Options;
	vector<sf::FloatRect> BoundingBoxes;
	sf::Font Font;
	sf::Text Text;
	int Selected;
};
#endif //MAINMENU