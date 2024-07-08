#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <conio.h>
#include <iomanip>
#include "myList.h"

class UI
{
private:

public:
	UI();

	void getUserResponse(std::string& userString);
	void getUserResponseNoEnter(char& chosenValue, const char& minValue, const char& maxValue);
	void printOutStringVector(int color, myList<std::string>&);
	void printOutGuessedWordColored(myList<int> colors, myList<myList<std::string>>& guessedWordToPrintOut);
	void printOutGuessedWord(myList<myList<std::string>>& guessedWordToPrintOut);
	void printOutSingleString(int color, std::string&);
	void printOutSingleStringNoEndl(int color, std::string& stringToPrintOut);
	void printOutSingleString(int color, std::string);
	void clearScreen();
};

