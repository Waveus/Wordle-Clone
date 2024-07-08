#include "game.h"

game::game(std::initializer_list<scene*> allScenes)
{
	this->nextScene = 0;
	for (const auto& scene : allScenes)
	{
		this->sceneVector.push_back(scene);
	}
}


void game::run(UI* userInterface)
{
	do
	{
		this->sceneVector[this->nextScene]->run(userInterface);
		this->nextScene = this->sceneVector[this->nextScene]->getNextScene();
		userInterface->clearScreen();

	} while (this->nextScene != -1);
}
