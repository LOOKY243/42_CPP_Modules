#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::IsDigit(std::string num)
{
    for (int i = 0; i < (int)num.size(); i++)
    {
        if (!std::isdigit(num[i]))
            return false;
    }
    return true;
}

int PmergeMe::InitVec(int argc, char **argv)
{
    int tmp;

    for (int i = 1; i < argc; i++)
    {
        if (IsDigit(argv[i]))
        {
            tmp = atoi(argv[i]);
            if (tmp < 0)
            {
                std::cerr << "Error: Numbers can't be neagtive" << std::endl;
                return 0;
            }
            vec.push_back(tmp);
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return 0;
        }
    }
    return 1;
}

int PmergeMe::InitDeq(int argc, char **argv)
{
    int tmp;

    for (int i = 1; i < argc; i++)
    {
        if (IsDigit(argv[i]))
        {
            tmp = atoi(argv[i]);
            if (tmp < 0)
            {
                std::cerr << "Error" << std::endl;
                return 0;
            }
            deq.push_back(tmp);
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return 0;
        }
    }
    return 1;
}

void PmergeMe::Init(int argc, char **argv)
{
    double elapsedTime;

    if (!InitVec(argc, argv))
        return ;
    std::cout << "Before: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    vec.clear();

    std::clock_t start = std::clock();
    InitVec(argc, argv);
    VecAlgorithm();
    std::clock_t stop = std::clock();
    elapsedTime = (stop - start) * 1e6 / CLOCKS_PER_SEC;
    
    std::cout << "After: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size() 
        << " elements with std::vector " << elapsedTime << " us" << std::endl;
    vec.clear();

    start = std::clock();
    if (!InitDeq(argc, argv))
        return ;
    DeqAlgorithm();
    stop = std::clock();
    elapsedTime = (stop - start) * 1e6 / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << deq.size() 
        << " elements with std::deque " << elapsedTime << " us" << std::endl;
    deq.clear();

}

void PmergeMe::VecAlgorithm()
{
    int left = 0, right = vec.size() - 1;
    std::vector<int> temp(vec.size());

    for (int length = 1; length <= right - left + 1; length *= 2)
    {
        for (int i = left; i <= right; i += 2 * length)
        {
            int lo = i;
            int hi = std::min(i + 2 * length - 1, right);
            int mid = lo + length - 1;
            MergeVec(vec, temp, lo, mid, hi);
        }
        std::copy(temp.begin(), temp.end(), vec.begin());
    }
}

void PmergeMe::MergeVec(std::vector<int>& vec, std::vector<int>& temp, int lo, int mid, int hi)
{ 
    int i = lo;
    int j = mid + 1;

    for (int k = lo; k <= hi; ++k)
    {
        if (i > mid)
            temp[k] = vec[j++];
        else if (j > hi)
            temp[k] = vec[i++];
        else if (vec[j] < vec[i])
            temp[k] = vec[j++];
        else
            temp[k] = vec[i++];
    }
}

void PmergeMe::DeqAlgorithm()
{
    int left = 0, right = deq.size() - 1;
    std::deque<int> temp;

    for (int length = 1; length <= right - left + 1; length *= 2)
    {
        for (int i = left; i <= right; i += 2 * length)
        {
            int lo = i;
            int hi = std::min(i + 2 * length - 1, right);
            int mid = lo + length - 1;
            MergeDeq(deq, temp, lo, mid, hi);
        }
        deq.swap(temp);
    }
}

void PmergeMe::MergeDeq(std::deque<int>& deq, std::deque<int>& temp, int lo, int mid, int hi)
{
    int i = lo, j = mid + 1;

    while (i <= mid && j <= hi)
    {
        if (deq[j] < deq[i])
            temp.push_back(deq[j++]);
        else
            temp.push_back(deq[i++]);
    }
    while (i <= mid)
        temp.push_back(deq[i++]);
    while (j <= hi)
        temp.push_back(deq[j++]);

}