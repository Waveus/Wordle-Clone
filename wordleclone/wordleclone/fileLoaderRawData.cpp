#include "fileLoaderRawData.h"

fileLoaderRawData::~fileLoaderRawData()
{

}

myList<std::string>& fileLoaderRawData::getData()
{
    return this->allFromTxt;
}




