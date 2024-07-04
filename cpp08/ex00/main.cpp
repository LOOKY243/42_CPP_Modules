#include "easyfind.hpp"

int main(void)
{
    std::vector<int> vec1;
    std::vector<int> vec2;

    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);
    vec1.push_back(40);
    vec1.push_back(50);

    vec2.push_back(18);
    vec2.push_back(18);
    vec2.push_back(143);
    vec2.push_back(18);
    vec2.push_back(138);
    vec2.push_back(176);
    vec2.push_back(112);
    vec2.push_back(198765);
    vec2.push_back(1564);

    try
    {
        std::cout << easyfind(vec1, 20) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "No repeated element found" << std::endl;
    }
    try
    {
        std::cout << easyfind(vec2, 112) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "No repeated element found" << std::endl;
    }
    try
    {
        std::cout << easyfind(vec2, 99) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "No repeated element found" << std::endl;
    }
}