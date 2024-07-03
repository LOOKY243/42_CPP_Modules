#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
    private:
        T *arr;
        unsigned int len;
    public:
        Array()
        {
            arr = new T[0];
            len = 0;
        }

        Array(unsigned int n)
        {
            arr = new T[n];
            len = n;
            for (unsigned int i = 0; i < n; i++)
                arr[i] = T();
        }

        Array(Array &other)
        {
            arr = new T[other.len];
            len = other.len;
            for (unsigned int i = 0; i < len; i++)
                arr[i] = other.arr[i];
        }

        Array &operator=(Array &other)
        {
            if (this != &other)
            {
                if (arr)
                    delete [] arr;
                arr = new T[other.len];
                len = other.len;
                for (unsigned int i = 0; i < len; i++)
                    arr[i] = other.arr[i];
            }
            return *this;
        }

        ~Array()
        {
            delete [] arr;
        }

        unsigned int size()
        {
            return len;
        }

        T &operator[](unsigned int index)
        {
            if (index >= len)
                throw std::out_of_range("Index out of range");
            return arr[index];
        }
};


#endif