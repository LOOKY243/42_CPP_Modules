#include "Data.hpp"

Data::Data()
{
    _name = "Data";
    _num = 5;
}

Data::Data(std::string str)
{
    (void)str;
}

Data::Data(const Data &other)
{
    (void)other;
}

Data &Data::operator=(Data &other)
{
    return other;
}

Data::~Data()
{
}

void Data::showInfos()
{
    std::cout << _name << std::endl;
    std::cout << _num << std::endl; 
}