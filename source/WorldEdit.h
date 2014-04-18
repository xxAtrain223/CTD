#include "GameState.h"

#ifndef WORLDEDIT
#define WORLDEDIT
class WorldEdit : public GameState
{
public:
	WorldEdit();
	~WorldEdit();

	void Initialize();
	void LoadContent();
	void Update();
	void Draw();
	void UnloadContent();
	void EventHandler(sf::Event);
};
#endif //WORLDEDIT