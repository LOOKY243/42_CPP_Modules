#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <deque>

class PmergeMe
{
    private:
        std::vector<int> vec;
        std::deque<int> deq;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);

        ~PmergeMe();

        void Init(int argc, char **argv);
        int InitVec(int argc, char **argv);
        int InitDeq(int argc, char **argv);
        bool IsDigit(std::string num);
        void VecAlgorithm();
        void DeqAlgorithm();
        int VecBinarySearch(const std::vector<int>& vec, int value);
        int DeqBinarySearch(const std::deque<int>& vec, int value);
};

#endif