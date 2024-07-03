#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
    private:
        Data(std::string str);
        Data(const Data &other);
        Data &operator=(Data &other);

        std::string _name;
        int _num;
    public:
        Data();
        ~Data();

        void showInfos();
};


#endif