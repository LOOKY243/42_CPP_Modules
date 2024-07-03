#include "iter.hpp"

template<typename T>
void print(T a)
{
    std::cout << a << std::endl;
}

int main()
{
    std::string strArr[3] = {"wassup", "my", "g"};
    int intArr[5] = {1, 4, 2, 5, 3};
    char charArr[5] = {'h', 'e', 'l', 'l', 'o'};
    std::cout << "Before call to iter" << std::endl;
    iter(strArr, 3, print);
    iter(intArr, 5, print);
    iter(charArr, 5, print);
}