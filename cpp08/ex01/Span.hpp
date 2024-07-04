#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>

class Span
{
    class vecFull: public std::exception
    {
        virtual const char *what() const throw()
        {
            return "Vector is already filled";
        }
    };
    class notEnoughNums: public std::exception
    {
        virtual const char *what() const throw()
        {
            return "Vector must have at least 2 elements";
        }
    };
    private:
        std::vector<int> vec;
        unsigned int len;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);

        ~Span();

        void addNumber(int num);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
};


#endif