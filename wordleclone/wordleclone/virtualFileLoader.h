#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "myList.h"

class virtualFileLoader
{
protected:
	myList<std::string> allFromTxt;
	int doesItExistValue;
public:
	virtualFileLoader(std::string);
	virtual ~virtualFileLoader() = 0;
	
	int getDoesItExist();
	virtual myList<std::string>& getData() = 0;
};

