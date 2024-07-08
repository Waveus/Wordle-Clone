#pragma once
#include "virtualFileLoader.h"
#include "fileLoaderRawData.h"
#include "UI.h"
#include "myList.h"
class scene
{
protected:
	std::vector<virtualFileLoader*> objects;
	int doesFilesExist;
	char nextScene;
public:
	virtual ~scene() = 0;

	int doesFilesExistReturnValue();
	virtual void run(UI* userInterface) = 0;
	virtual int getNextScene() = 0;
};

