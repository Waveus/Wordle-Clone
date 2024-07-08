#include "UI.h"

UI::UI()
{
}

void UI::getUserResponse(std::string& userString)
{
	try
	{
		userString = "";
		std::cin >> userString;
		while (std::cin.get()!='\n');

	}
	catch (const std::exception&e)
	{
		std::cout << e.what();
	}
}

void UI::getUserResponseNoEnter(char& chosenValue, const char& minValue, const char& maxValue)
{
    do

        try
    {
        chosenValue = ' ';
        chosenValue = _getch();
        if (chosenValue >= minValue && chosenValue <= maxValue)
        {
            return;
        }
        throw std::invalid_argument("Niepoprawny argument");
    }
    catch (const std::exception& e)
    {
    }

    while (true);
}

void UI::printOutStringVector(int color, myList<std::string>&stringVectorToPrintOut)
{
    if (color == 1)
    {
        std::for_each(stringVectorToPrintOut.begin(), stringVectorToPrintOut.end(), [](const std::string& lineFromVector) {

            std::cout << "\x1B[32m" + lineFromVector + "\x1B[0m";
        std::cout << std::endl;

            });
    }
    else if (color == 2)
    {
        std::for_each(stringVectorToPrintOut.begin(), stringVectorToPrintOut.end(), [](const std::string& lineFromVector) {

            std::cout << "\x1B[31m" + lineFromVector + "\x1B[0m";
        std::cout << std::endl;

            });
    }
    else if (color == 3)
    {
        std::for_each(stringVectorToPrintOut.begin(), stringVectorToPrintOut.end(), [](const std::string& lineFromVector) {

            std::cout << "\x1B[33m" + lineFromVector + "\x1B[0m";
        std::cout << std::endl;

            });
    }
    else
    {
        std::for_each(stringVectorToPrintOut.begin(), stringVectorToPrintOut.end(), [](const std::string& lineFromVector) {
            std::cout << lineFromVector;
        std::cout << std::endl;
            });
    }
}

void UI::printOutGuessedWordColored(myList<int> colors, myList<myList<std::string>>& guessedWordToPrintOut)
{
    int color = 0;

    for (int i = 0; i < 4; i++)
    {
        color = 0;
        std::for_each(guessedWordToPrintOut.begin(), guessedWordToPrintOut.end(), [&](myList<std::string>& stringvector) {

        printOutSingleStringNoEndl(colors[color], stringvector[i]);
        color++;

            });
        std::cout << std::endl;
    }
}

void UI::printOutGuessedWord(myList<myList<std::string>>& guessedWordToPrintOut)
{

    for (int i = 0; i < 4; i++)
    {

        std::for_each(guessedWordToPrintOut.begin(), guessedWordToPrintOut.end(), [&](myList<std::string>& stringvector) {

            printOutSingleStringNoEndl(0, stringvector[i]);

            });
        std::cout << std::endl;
    }
}

void UI::printOutSingleString(int color, std::string& stringToPrintOut)
{
    if (color == 1)
    {
        std::cout << "\x1B[32m" + stringToPrintOut + "\x1B[0m";
        std::cout << std::endl;
    }
    else if (color == 2)
    {

        std::cout << "\x1B[31m" + stringToPrintOut + "\x1B[0m";
        std::cout << std::endl;

    }
    else if (color == 3)
    {

        std::cout << "\x1B[33m" + stringToPrintOut + "\x1B[0m";
        std::cout << std::endl;
    }
    else
    {
        std::cout << stringToPrintOut;
        std::cout << std::endl;

    }
}

void UI::printOutSingleStringNoEndl(int color, std::string& stringToPrintOut)
{
    if (color == 1)
    {
        std::cout << "\x1B[32m" + stringToPrintOut + "\x1B[0m";
    }
    else if (color == 2)
    {
        std::cout << "\x1B[31m" + stringToPrintOut + "\x1B[0m";

    }
    else if (color == 3)
    {
        std::cout << "\x1B[33m" + stringToPrintOut + "\x1B[0m";
    }
    else
    {
        std::cout << stringToPrintOut;
    }
}

void UI::printOutSingleString(int color, std::string stringToPrintOut)
{
    if (color == 1)
    {
            std::cout << "\x1B[32m" + stringToPrintOut + "\x1B[0m";
            std::cout << std::endl;
    }
    else if (color == 2)
    {

        std::cout << "\x1B[31m" + stringToPrintOut + "\x1B[0m";
        std::cout << std::endl;

    }
    else if (color == 3)
    {

            std::cout << "\x1B[33m" + stringToPrintOut + "\x1B[0m";
        std::cout << std::endl;
    }
    else
    {
            std::cout << stringToPrintOut;
        std::cout << std::endl;

    }
}

void UI::clearScreen()
{
    std::cout << u8"\033[2J\033[1;1H";
}
