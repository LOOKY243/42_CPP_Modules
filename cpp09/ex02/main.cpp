#include "PmergeMe.hpp"

int main(int argc , char **argv)
{
    if (argc <= 1)
    {
        std::cerr << "Usage: ./PmergeMe <integer arguments>" << std::endl;
        return 1;
    }
    PmergeMe foo;
    foo.Init(argc, argv);

}