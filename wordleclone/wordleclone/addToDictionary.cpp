#include "addToDictionary.h"

addToDictionary::addToDictionary(std::string NameOfFileWithDictionary)
{
    std::fstream str;
    std::string line;
    this->nameWithFileWithDictionary = NameOfFileWithDictionary;

    str.open(NameOfFileWithDictionary, std::ios::in);
    
    while (std::getline(str, line))
    {
        dictionary[line]++;
    }
    str.close();
}

addToDictionary::~addToDictionary()
{

}

void addToDictionary::run(UI* userInterface)
{
    std::string userword;
    char buf;

    userInterface->printOutSingleString(1, "Enter the word to add to the dictionary: ");
    
    do
    {
    userInterface->getUserResponseNoEnter(buf, 'a', 'z');
    userInterface->clearScreen();
    userword.push_back(buf);
    userInterface->printOutSingleString(1, "Enter the word to add to the dictionary: ");
    std::cout << userword;

    } while (userword.size() != 5);

    dictionary[userword]++;

    if (dictionary[userword] == 1)
    {
    userInterface->printOutSingleString(1, "Saving to file");
    std::fstream str;
    str.open(this->nameWithFileWithDictionary, std::ios::app);

    str << std::endl;
    str << userword;


    str.close();
    }
    else
    {
    userInterface->printOutSingleString(1, "Word exists");
    }

    Sleep(3000);

}

int addToDictionary::getNextScene()
{
    return 0;
}



