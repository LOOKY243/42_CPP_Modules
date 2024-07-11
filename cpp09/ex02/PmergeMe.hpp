#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>
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
        void MergeVec(std::vector<int>& vec, std::vector<int>& temp, int lo, int mid, int hi);
        void MergeDeq(std::deque<int>& deq, std::deque<int>& temp, int lo, int mid, int hi);
};

#endif