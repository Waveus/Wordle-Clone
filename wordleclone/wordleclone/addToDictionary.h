#pragma once
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>
#include "UI.h"
#include "scene.h"


class addToDictionary : public scene
{
private:
	std::string nameWithFileWithDictionary;
	std::map<std::string, int> dictionary;
public:
	addToDictionary(std::string NameOfFileWithDictionary);
	~addToDictionary();


	void run(UI* userInterface);

	int getNextScene();

	
};

