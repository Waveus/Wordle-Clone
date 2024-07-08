#pragma once
#include "virtualFileLoader.h"
#include "myList.h"
#include <random>

class fileLoaderDictionary : public virtualFileLoader
{
private:
	myList<std::string> vectorStringBufToReturn;
public:
	fileLoaderDictionary(std::string dictionary) : virtualFileLoader(dictionary) {};
	myList<std::string>& getData();
	bool doesWordExist(std::string&);
};

