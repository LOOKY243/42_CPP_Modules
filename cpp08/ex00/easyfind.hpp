#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

template<typename T>
int easyfind(T arr, int toFind)
{
    typename T::iterator it = std::find(arr.begin(), arr.end(), toFind);
    if (it != arr.end())
        return toFind;
    throw std::runtime_error("No repeated element found");
}

#endif