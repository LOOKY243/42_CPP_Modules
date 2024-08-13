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
            vec.push_back(tmp);
        }
        else if (argv[i][0] == '-')
        {
            std::cerr << "Error: Numbers can't be negative" << std::endl;
            return 0;
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
            deq.push_back(tmp);
        }
        else if (argv[i][0] == '-')
        {
            std::cerr << "Error: Numbers can't be negative" << std::endl;
            return 0;
        }
        else
        {
            std::cerr << "Error: Non digit argument" << std::endl;
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
    SortVector(0, vec.size() - 1);
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
    SortDeque(0, deq.size() - 1);
    stop = std::clock();
    elapsedTime = (stop - start) * 1e6 / CLOCKS_PER_SEC;

    std::cout << "Time to process a range of " << deq.size() 
        << " elements with std::deque " << elapsedTime << " us" << std::endl;
}

void PmergeMe::SortVector(int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        SortVector(left, mid);
        SortVector(mid + 1, right);

        if (right - left + 1 > 2)
            MergeVector(left, mid, right);
        else
            InsertionVector(left, right);
    }
}

void PmergeMe::MergeVector(int left, int mid, int right)
{
    std::vector<int> _tmp(right - left + 1);
    int i = left;
    int j = mid + 1;
    unsigned int k = 0;

    while (i <= mid && j <= right)
    {
        if (vec[i] <= vec[j])
            _tmp[k++] = vec[i++];
        else
            _tmp[k++] = vec[j++];
    }

    while (i <= mid)
        _tmp[k++] = vec[i++];

    while (j <= right)
        _tmp[k++] = vec[j++];

    for (k = 0; k < _tmp.size(); k++)
        vec[left + k] = _tmp[k];
}

void PmergeMe::InsertionVector(int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int key = vec[i];
        int j = i - 1;

        while (j >= left && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            --j;
        }

        vec[j + 1] = key;
    }
}

void PmergeMe::SortDeque(int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        SortDeque(left, mid);
        SortDeque(mid + 1, right);

        if (right - left + 1 > 2)
            MergeDeque(left, mid, right);
        else
            InsertionDeque(left, right);
    }
}

void PmergeMe::MergeDeque(int left, int mid, int right)
{
    std::vector<int> _tmp(right - left + 1);
    int i = left;
    int j = mid + 1;
    unsigned int k = 0;

    while (i <= mid && j <= right)
    {
        if (deq[i] <= deq[j])
            _tmp[k++] = deq[i++];
        else
            _tmp[k++] = deq[j++];
    }

    while (i <= mid)
        _tmp[k++] = deq[i++];

    while (j <= right)
        _tmp[k++] = deq[j++];

    for (k = 0; k < _tmp.size(); k++)
        deq[left + k] = _tmp[k];
}

void PmergeMe::InsertionDeque(int left, int right)
{
    for (int i = left + 1; i <= right; ++i)
    {
        int key = deq[i];
        int j = i - 1;

        while (j >= left && deq[j] > key)
        {
            deq[j + 1] = deq[j];
            --j;
        }

        deq[j + 1] = key;
    }
}