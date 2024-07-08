#include "fileLoaderDictionary.h"

myList<std::string>& fileLoaderDictionary::getData()
{
    std::string stringBuf;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> myDistribution(0, this->allFromTxt.size() - 1);
    
    do 
    {
        this->vectorStringBufToReturn.clear();
        for (int i = 0; i < 3; i++)
        {
            stringBuf = this->allFromTxt[myDistribution(rng)];
            vectorStringBufToReturn.push_back(stringBuf);
        }
    } while ((vectorStringBufToReturn[0]) == (vectorStringBufToReturn[1]) || (vectorStringBufToReturn[0]) == (vectorStringBufToReturn[2]) || (vectorStringBufToReturn[1]) == (vectorStringBufToReturn[2]));
    

    return vectorStringBufToReturn;
}

bool fileLoaderDictionary::doesWordExist(std::string& wordToCheckDoesItExist)
{
    bool existBuf = 0;

    std::for_each(this->allFromTxt.begin(), this->allFromTxt.end(), [&](auto wordInVector) {
        if (wordToCheckDoesItExist == wordInVector)
        {
            existBuf = 1;
        }
        });

    return existBuf;
}
