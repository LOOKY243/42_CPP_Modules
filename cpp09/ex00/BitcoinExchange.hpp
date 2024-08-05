#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <ctime>
#include <sstream>
#include <iomanip>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _data;
        std::string _filename;

        BitcoinExchange();
    public:
        BitcoinExchange(std::string filename);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);

        ~BitcoinExchange();

        void ParseData();
        void ParseFile();
        std::string FindDate(std::string date);
        std::string DecreaseDate(std::string _date);
        void ConvertValues(std::string date, float value);
        bool checkDateFormat(std::string date);
        bool isLeapYear(int year);
        bool validDay(int days, int month);
        bool IsDigit(std::string num);
        double atod(std::string str);
};


#endif