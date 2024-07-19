#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *arr, size_t len, void(*func)(T))
{
    if (!arr)
        return ;
    if (!func)
        return ;
    for (size_t i = 0; i < len; i++)
    {
        func(arr[i]);
    }
}

template<typename T1, typename T2>
void iter(T1 *arr, size_t len, void(*func)(T2))
{
    if (!arr)
        return ;
    if (!func)
        return ;
    for (size_t i = 0; i < len; i++)
    {
        func(arr[i]);
    }
}

#endif