#include "ScalarConverter.hpp"

int precision = 1;

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(std::string foo)
{
    (void)foo;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &other)
{
    return other;
}

ScalarConverter::~ScalarConverter()
{
}

double atod(std::string str)
{
    double res = 0;
    int i = -1;
    int fraction = 0;
    int decimals = 1;
    int negative = 1;

    if (str[0] == '-')
    {
        i++;
        negative = -1;
    }
    else if (str[0] == '+')
        i++;
    while (str[++i])
    {
        if (std::isdigit(str[i]))
            res = res * 10 + (str[i] - '0');
        if (fraction)
        {
            decimals *= 10;
            precision++;
        }
        else if (str[i] == '.')
            fraction = 1;
    }
    res = (res / decimals) * negative;
    return res;
}

int IsDigit(std::string str)
{
    int i = 0;
    if (str[i] == '-')
        i++;
    while (str[i] != 0)
    {
        if (!std::isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}

int IsFloat(std::string str)
{
    int i = 0;
    int dot = 0;

    if (str[i] == '-')
        i++;
    while (str[i] != 0)
    {
        if (str[i] == '.')
        {
            if (dot)
                return 0;
            dot++;
        }
        else if (!std::isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}

int FromInt(std::string literal)
{
    if (!IsDigit(literal))
        return 0;

    char character = atod(literal);
    double dbl = atod(literal);
    if (std::isprint(character))
        std::cout << "Char : " << character << std::endl;
    else
        std::cout << "Char : Non-printable" << std::endl;
    if (dbl >= -2147483648 && dbl <= 2147483647)
    {
        int integer = atoi(literal.c_str());
        std::cout << "Int: " << integer << std::endl;
    }
    else
        std::cout << "Int: Non-Printable" << std::endl;
    std::cout << std::fixed << std::setprecision(precision) << "Float : " << dbl << "f" << std::endl;
    std::cout << "Double : " << dbl << std::endl;

    return 1;
}

int FromChar(std::string literal)
{
    if (literal.length() > 1)
        return 0;
    int integer = static_cast<int>(literal[0]);
    float decimal = static_cast<float>(literal[0]);
    double dbl = static_cast<double>(literal[0]);

    std::cout << "Char : " << literal[0] << std::endl;
    std::cout << "Int : " << integer << std::endl;
    std::cout << "Float : " << decimal << ".0f" << std::endl;
    std::cout << "Double : " << dbl << ".0" << std::endl;

    return 1;
}

int FromFloat(std::string literal)
{
    if (!IsFloat(literal))
        return 0;
    double decimal = atod(literal);
    char c = decimal;
    std::cout << "Char: " << c << std::endl;
    if (decimal >= -2147483648 && decimal <= 2147483647)
    {
        int integer = atoi(literal.c_str());
        std::cout << "Int: " << integer << std::endl;
    }
    else
        std::cout << "Int: Non-Printable" << std::endl;
    std::cout << std::fixed << std::setprecision(precision / 2) << "Float: " << decimal << "f" << std::endl;
    std::cout << "Double: " << decimal << std::endl;
    return 1;
}

int BruteNums(std::string literal)
{
    if (literal == "nan")
    {
        std::cout << "Char: impossible" << std::endl;
        std::cout << "Int: impossible" << std::endl;
        std::cout << "Float: nanf" << std::endl;
        std::cout << "Double: nan" << std::endl;
        return 1;
    }
    return 0;
}

std::string removeF(std::string literal)
{
    int end = literal.size();
    
    while (end > 0 && literal[end - 1] == 'f')
        end--;
    return literal.substr(0, end);
}

void ScalarConverter::convert(std::string literal)
{
    if (literal.empty())
        return ;
    literal = removeF(literal);
    if (!BruteNums(literal))
        if (!FromInt(literal))
            if (!FromFloat(literal))
                if (!FromChar(literal))
                    std::cout << "Value cannot be converted" << std::endl;
}