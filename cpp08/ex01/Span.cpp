#include "Span.hpp"

Span::Span()
{
    len = 0;
}

Span::Span(unsigned int N)
{
    len = N;
}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        len = other.len;
        vec = std::vector<int>(len);
        for (unsigned int i = 0; i < other.vec.size(); i++)
        {
            vec[i] = other.vec[i];
        }
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int num)
{
    if (vec.size() >= len)
        throw vecFull();
    vec.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    for (std::vector<int>::iterator it = begin; it != end; it++)
        addNumber(*it);
}

int Span::longestSpan()
{
    if (vec.size() < 2)
        throw notEnoughNums();
    
    return *std::max_element(vec.begin(), vec.end()) - *std::min_element(vec.begin(), vec.end());
}

int Span::shortestSpan()
{
    if (vec.size() < 2)
        throw notEnoughNums();
    std::vector<int> sortedVec = vec;
    std::sort(sortedVec.begin(), sortedVec.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sortedVec.size(); i++)
    {
        int span = sortedVec[i] - sortedVec[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

