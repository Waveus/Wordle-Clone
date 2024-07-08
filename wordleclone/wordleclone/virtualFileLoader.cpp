#include "virtualFileLoader.h"

virtualFileLoader::virtualFileLoader(std::string _Name_of_File)
{
    std::fstream str;
    std::string line;

    try
    {
        str.open(_Name_of_File, std::ios::in);
        if (!str.is_open())
        {
            throw std::exception();
        }
        while (std::getline(str, line))
        {
            this->allFromTxt.push_back(line);
        }
        this->doesItExistValue = 1;
    }
    catch (const std::exception&)
    {
        std::cerr << "File cannot be opened" << std::endl;
        this->doesItExistValue = 0;
    }
}

virtualFileLoader::~virtualFileLoader()
{

}

int virtualFileLoader::getDoesItExist()
{
    return this->doesItExistValue;
}
