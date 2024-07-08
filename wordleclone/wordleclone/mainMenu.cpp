#include "mainMenu.h"

mainMenu::mainMenu(std::initializer_list<std::string> nameOfFilesToLoad)
{
	virtualFileLoader* buf = nullptr;
	this->doesFilesExist = 1;
	this->nextScene = 0;

	for (const auto& oneNameOfFileToLoad : nameOfFilesToLoad)
	{
		buf = new fileLoaderRawData(oneNameOfFileToLoad);
		this->objects.push_back(buf);
		doesFilesExist = buf->getDoesItExist() * doesFilesExist;
	}

}

mainMenu::~mainMenu()
{
	for (const auto& object : this->objects)
	{
		delete object;
	}
}

void mainMenu::run(UI* interFace)
{
	//cout full scene

	interFace->printOutStringVector(1 , ((fileLoaderRawData*)objects[0])->getData());
	interFace->printOutSingleString(1, "\n\n");
	interFace->printOutStringVector(1, ((fileLoaderRawData*)objects[1])->getData());
	
	//get user input to go to the next scene
	
	interFace->getUserResponseNoEnter(this->nextScene, '1', '4');
	if (this->nextScene == '3') this->nextScene = '0' - 1;
	if (this->nextScene == '4') this->nextScene = '3';

	interFace->clearScreen();
}

int mainMenu::getNextScene()
{
	return  int(this->nextScene - '0');
}
