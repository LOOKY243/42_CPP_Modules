#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstddef>
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
        void SortVector(int left, int right);
        void MergeVector(int left, int mid, int right);
        void InsertionVector(int left, int right);
        void SortDeque(int left, int right);
        void MergeDeque(int left, int mid, int right);
        void InsertionDeque(int left, int right);
};

#endif