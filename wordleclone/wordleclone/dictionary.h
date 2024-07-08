#pragma once
#include <map>
#include <iostream>

class dictionary
{
private:
	std::map<std::string, bool> dictionary;
public:
	bool doesTheEnteredWordItExist(std::string&);
};

