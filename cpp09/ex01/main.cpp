#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Use: ./RPN <RPN calculus>" << std::endl;
        return 1;
    }
    RPN rpn;
    rpn.RevPolish(argv[1]);
}