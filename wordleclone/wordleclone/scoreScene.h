#pragma once
#include "mainMenu.h"
#include "myList.h"
class scoreScene : public mainMenu
{
private:
	std::string nameOfFileWithScores;
	void reload();
public:

	scoreScene(std::initializer_list<std::string> nameOfFilesToLoad) : mainMenu(nameOfFilesToLoad) 
	{
		std::for_each(nameOfFilesToLoad.begin() + 1, nameOfFilesToLoad.begin() + 2, [&](std::string nameOfFirstFile) {
			nameOfFileWithScores = nameOfFirstFile;
			});
	};

	void run(UI* userInterface);
	int getNextScene();
};

