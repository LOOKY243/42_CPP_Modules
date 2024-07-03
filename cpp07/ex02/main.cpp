#include "Array.hpp"

int main()
{
    Array<int> _a(5);
    Array<int> _b(5);
    int * a = new int();

    _a = _b;
    for (unsigned int i = 0; i < _a.size(); i++)
        std::cout << _a[i] << std::endl;
    delete a;
}