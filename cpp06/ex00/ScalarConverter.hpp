#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <iomanip>

class ScalarConverter
{
    private:
        ScalarConverter(std::string foo);
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(ScalarConverter &other);
        ScalarConverter();

    public:
        ~ScalarConverter();

        static void convert(std::string literal);
};

int IsDigit(std::string str);
int IsFloat(std::string str);
int BruteNums(std::string literal);
std::string removeF(std::string literal);
double atod(std::string str);
int FromChar(std::string literal);
int  FromInt(std::string literal);

#endif