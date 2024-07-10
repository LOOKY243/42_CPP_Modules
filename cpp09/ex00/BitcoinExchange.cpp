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
}

bool checkDateFormat(std::string date)
{
    int i = 0;
    int val = 0;
    
    while (std::isdigit(date[i]))
    {
        val = val * 10 + (date[i] - '0');
        i++;
    }
    if (i != 4 || val == 0)
        return false;
    i++;
    val = 0;
    while (std::isdigit(date[i]))
    {
        val = val * 10 + (date[i] - '0');
        i++;
    }
    if (i != 7 || val > 12 || val == 0)
        return false;
    i++;
    val = 0;
    while (std::isdigit(date[i]))
    {
        val = val * 10 + (date[i] - '0');
        i++;
    }
    if (i != 10 || val > 30 || val == 0)
        return false;
    return true;
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
    while (std::getline(inputFile, line))
    {
        std::stringstream ss(line);
        std::string date;
        float value;

        if (std::getline(ss, date, '|'))
        {
            ss >> value;
            if (!checkDateFormat(date))
                std::cout << "Error: bad input => " << date << std::endl;
            else if (value > 2147483647.0)
                std::cout << "Error: too large a number." << std::endl;
            else if (value < 0)
                std::cout << "Error: not a positive number." << std::endl;
            else if (date < _data.begin()->first)
                std::cout << "Error: no date found for " << date << std::endl;
            else
                ConvertValues(date, value);
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
    std::string curDate = date;
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