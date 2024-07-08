#pragma once
#include "scene.h"
#include "initializer_list"
#include "myList.h"


class mainMenu : public scene
{
protected:
	
public:
	mainMenu(std::initializer_list<std::string> nameOfFilesToLoad);
	~mainMenu();

	void run(UI* userInterface);
	int getNextScene();
};

