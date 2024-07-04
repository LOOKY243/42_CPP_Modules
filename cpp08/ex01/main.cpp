#include "Span.hpp"

// int main()
// {
//     Span sp = Span(5);
//     sp.addNumber(6);
//     sp.addNumber(3);
//     sp.addNumber(17);
//     sp.addNumber(9);
//     sp.addNumber(11);
//     std::cout << sp.shortestSpan() << std::endl;
//     std::cout << sp.longestSpan() << std::endl;
//     return 0;
// }

int main()
{
    Span sp = Span(6);

    try {
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::vector<int> vec;
    vec.push_back(6);
    vec.push_back(3);
    vec.push_back(17);
    vec.push_back(9);
    vec.push_back(11);
    sp.addNumber(14);
    sp.addNumber(vec.begin(), vec.end());

    try {
        sp.addNumber(2);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        sp.addNumber(vec.begin(), vec.end());
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    return 0;
}