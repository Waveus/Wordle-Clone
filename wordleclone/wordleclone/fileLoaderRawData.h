#pragma once
#include "virtualFileLoader.h"
#include "myList.h"
#include <random>

class fileLoaderRawData : public virtualFileLoader
{
public:
    fileLoaderRawData(std::string nameOfFile) : virtualFileLoader(nameOfFile) {}
    ~fileLoaderRawData();

    myList<std::string>& getData();
    myList<int> getRandomNumberVector(int lowerBound, int greaterBound);
};

