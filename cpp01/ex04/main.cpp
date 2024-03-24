#include "main.hpp"



int main(void)
{
    std::string line;
    std::string filename;
    std::string s1;
    std::string s2;

    std::cout << "Filename: ";
    std::getline(std::cin, filename);
    std::cout << "To replace: ";
    std::getline(std::cin, s1);
    std::cout << "Replace with: ";
    std::getline(std::cin, s2);

    std::ifstream inputFile(filename);
    std::ofstream outputFile(filename + ".replace");
    while (std::getline(inputFile, line))
    {
        // continue here
    }
}