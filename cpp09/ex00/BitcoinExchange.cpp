#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    ParseData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
    _filename = filename;
    ParseData();
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _filename = other._filename;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::ParseData()
{
    std::ifstream inputFile("data.csv");

    if (!inputFile)
    {
        std::cout << "Unable to open database" << std::endl;
        return ;
    }
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::stringstream ss(line);
        std::string date;
        float value;
        if (std::getline(ss, date, ',') && (ss >> value))
        {
            _data[date] = value;
        }
    }
    ParseFile();
}

bool BitcoinExchange::isLeapYear(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    else
        return false;
}

bool BitcoinExchange::validDay(int days, int month)
{
    if ((month == 1 || month == 3 || month == 5
        || month == 7 || month == 8 || month == 10
        || month == 12) && days > 31)
        return false;
    if ((month == 4 || month == 6
        || month == 9 || month == 11) && days > 31)
        return false;
    else
        return true;
}

bool BitcoinExchange::checkDateFormat(std::string date)
{
    int i = 0;
    int year = 0;
    
    while (std::isdigit(date[i]))
    {
        year = year * 10 + (date[i] - '0');
        i++;
    }
    if (i != 4 || year == 0)
        return false;
    if (date[i] == '-')
        i++;
    int month = 0;
    while (std::isdigit(date[i]))
    {
        month = month * 10 + (date[i] - '0');
        i++;
    }
    if (i != 7 || month > 12 || month == 0)
        return false;
    if (date[i] == '-')
        i++;
    int days = 0;
    while (std::isdigit(date[i]))
    {
        days = days * 10 + (date[i] - '0');
        i++;
    }
    if (isLeapYear(year) && month == 2 && days > 29)
        return false;
    if (!isLeapYear(year) && month == 2 && days > 28)
        return false;
    if (i != 10 || !validDay(days, month) || days == 0)
        return false;
    return true;
}

bool BitcoinExchange::IsDigit(std::string num)
{
    for (int i = 0; i < (int)num.size(); i++)
    {
        if (!std::isdigit(num[i]))
            return false;
    }
    return true;
}

double BitcoinExchange::atod(std::string str)
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
            decimals *= 10;
        else if (str[i] == '.')
            fraction = 1;
    }
    res = (res / decimals) * negative;
    return res;
}

void BitcoinExchange::ParseFile()
{
    std::ifstream inputFile(_filename.c_str());

    if (!inputFile)
    {
        std::cout << "Unable to open database" << std::endl;
        return ;
    }
    std::string line;
    std::getline(inputFile, line);
    if (line != "date | value")
    {
        std::cout << "Error: header should be 'date | value'" << std::endl;
        return ;
    }
    while (std::getline(inputFile, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string value;
        double val;

        if (std::getline(ss, date, '|'))
        {
            std::getline(ss, value);
            val = atod(value);
            if (!checkDateFormat(date))
                std::cout << "Error: bad input => " << date << std::endl;
            else if (val > 2147483647.0)
                std::cout << "Error: too large a number." << std::endl;
            else if (value[1] == '-')
                std::cout << "Error: not a positive number." << std::endl;
            else if (date < _data.begin()->first)
                std::cout << "Error: no date found for " << date << std::endl;
            else if (IsDigit(value))
                std::cout << "Error: not a number" << std::endl;
            else
                ConvertValues(date, val);
        }
    }
}

std::string BitcoinExchange::DecreaseDate(std::string date)
{
    std::tm _tm = {};

    if (strptime(date.c_str(), "%Y-%m-%d", &_tm) == NULL)
        return "";

    _tm.tm_mday -= 1;
    std::mktime(&_tm);
    char _buffer[11];
    strftime(_buffer, sizeof(_buffer), "%Y-%m-%d", &_tm);
    return std::string(_buffer);
}

std::string BitcoinExchange::FindDate(std::string date)
{
    std::string curDate = date.substr(0, date.size() - 1);
    if (date > _data.rbegin()->first)
        return _data.rbegin()->first;
    while(_data.find(curDate) == _data.end())
        curDate = DecreaseDate(curDate);
    return curDate;
}

void BitcoinExchange::ConvertValues(std::string date, float value)
{
    float convRes;
    std::string closestDate;
    if (_data.find(date) == _data.end())
        closestDate = FindDate(date);
    else
        closestDate = date;

    convRes = _data[closestDate] * value;
    std::cout << date << " => " << value << " = " << convRes << std::endl;
}