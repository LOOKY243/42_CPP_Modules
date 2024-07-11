#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <stack>

class RPN
{
    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);

        ~RPN();

        void RevPolish(std::string calc);
        std::string itoa(int num);
};

#endif