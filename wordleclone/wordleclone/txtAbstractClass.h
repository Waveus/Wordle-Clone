#pragma once
#include <iostream>

class txtAbstractClass
{
private:
	std::string textOfObject;
public:
	virtual void doesTheFileExist() = 0;
};