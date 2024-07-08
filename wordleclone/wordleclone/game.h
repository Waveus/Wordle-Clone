#pragma once
#include <memory>
#include "scene.h"
#include "fileLoaderRawData.h"
#include "myList.h"
#include "UI.h"
#include <initializer_list>

class game
{
private:
	myList<scene*> sceneVector;
	int nextScene;
public:
	
	game(std::initializer_list<scene*>);
	void run(UI* userInterface);
};

