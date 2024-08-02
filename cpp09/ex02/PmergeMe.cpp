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
                std::cerr << "Error: Numbers can't be negative" << std::endl;
                return 0;
            }
            vec.push_back(tmp);
        }
        else
        {
            std::cerr << "Error: Non digit argument" << std::endl;
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

    start = std::clock();
    if (!InitDeq(argc, argv))
        return ;
    DeqAlgorithm();
    stop = std::clock();
    elapsedTime = (stop - start) * 1e6 / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << deq.size() 
        << " elements with std::deque " << elapsedTime << " us" << std::endl;
}

int PmergeMe::VecBinarySearch(const std::vector<int>& vec, int value)
{
    int left = 0;
    int right = vec.size();

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (vec[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

void PmergeMe::VecAlgorithm()
{
    std::vector<std::pair<int, int> > pairVec;

    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        int first = *it;
        int second = -1;

        if (it + 1 != vec.end())
            second = *(++it);

        std::pair<int, int> pair;
        if (first)
            pair.first = (first > second) ? first : second;
        if (second != -1)
            pair.second = (pair.first == first) ? second : first;
        else
            pair.second = second;

        pairVec.push_back(pair);
    }

    vec.clear();
    for (int i = 0; i < (int)pairVec.size(); i++)
        vec.push_back(pairVec[i].first);
    std::sort(vec.begin(), vec.end());

    std::vector<std::vector<int> > Dvec;
    int size = 2;
    int oldSize = 0;
    int current = 0;
    int power = 1;
    std::vector<int> tmp;
    for (int i = 0; i < (int)pairVec.size(); i++)
    {
        if (current == size)
        {
            oldSize = size;
            current = 0;
            power++;
            size = pow(size, power) - oldSize;
            std::reverse(tmp.begin(), tmp.end());
            Dvec.push_back(tmp);
            tmp.clear();
        }
        tmp.push_back(pairVec[i].second);
        current++;
    }
    if (tmp.size() != 0)
        Dvec.push_back(tmp);
    for (int i = 0; i < (int)Dvec.size(); i++)
    {
        for (int j = 0; j < (int)Dvec[i].size(); j++)
        {
            if (Dvec[i][j] != -1)
                vec.insert(vec.begin() + VecBinarySearch(vec, Dvec[i][j]), Dvec[i][j]);
        }
    }
}

int PmergeMe::DeqBinarySearch(const std::deque<int>& deq, int value)
{
    int left = 0;
    int right = deq.size();

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (deq[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

void PmergeMe::DeqAlgorithm()
{
    std::deque<std::pair<int, int> > pairDeq;

    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
    {
        int first = *it;
        int second = -1;

        if (it + 1 != deq.end())
            second = *(++it);

        std::pair<int, int> pair;
        if (first)
            pair.first = (first > second) ? first : second;
        if (second != -1)
            pair.second = (pair.first == first) ? second : first;
        else
            pair.second = second;

        pairDeq.push_back(pair);
    }

    deq.clear();
    for (int i = 0; i < (int)pairDeq.size(); i++)
        deq.push_back(pairDeq[i].first);
    std::sort(deq.begin(), deq.end());

    std::deque<std::deque<int> > Ddeq;
    int size = 2;
    int oldSize = 0;
    int current = 0;
    int power = 1;
    std::deque<int> tmp;
    for (int i = 0; i < (int)pairDeq.size(); i++)
    {
        if (current == size)
        {
            oldSize = size;
            current = 0;
            power++;
            size = pow(size, power) - oldSize;
            std::reverse(tmp.begin(), tmp.end());
            Ddeq.push_back(tmp);
            tmp.clear();
        }
        tmp.push_back(pairDeq[i].second);
        current++;
    }
    if (tmp.size() != 0)
        Ddeq.push_back(tmp);
    for (int i = 0; i < (int)Ddeq.size(); i++)
    {
        for (int j = 0; j < (int)Ddeq[i].size(); j++)
        {
            if (Ddeq[i][j] != -1)
                deq.insert(deq.begin() + DeqBinarySearch(deq, Ddeq[i][j]), Ddeq[i][j]);
        }
    }
}