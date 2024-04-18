#include "main.hpp"

int is_in_string(std::string str, std::string s1, int pos)
{
    int i = 0;
    while (i < (int)s1.length())
    {
        if (str[pos + i] != s1[i])
            return 0;
        i++;
    }
    return 1;
}


std::string replace(std::string str, std::string s1, std::string s2)
{
    std::string s;

    for (int i = 0; str[i]; i++)
    {
        if (is_in_string(str, s1, i))
        {
            for (int k = 0; s2[k]; k++)
                s += s2[k];
            i += s1.length() - 1;
        }
        else
            s += str[i];
    }
    return s;
}

int main(void)
{
    std::string line;
    std::string filename;
    std::string s1;
    std::string s2;

    std::cout << "Filename: ";
    std::getline(std::cin, filename);
    if (filename.empty())
    {
        std::cout << "Filename can't be empty" << std::endl;
        return 1;
    }
    std::cout << "To replace: ";
    std::getline(std::cin, s1);
    if (s1.empty())
    {
        std::cout << "The string to replace can't be blank" << std::endl;
        return 1;
    }
    std::cout << "Replace with: ";
    std::getline(std::cin, s2);
    if (s2.empty())
    {
        std::cout << "Can't replace with an empty line" << std::endl;
        return 1;
    }

    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Unable to open input file." << std::endl;
        return 1;
    }
    std::ofstream outputFile((filename + ".replace").c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Unable to create output file." << std::endl;
        return 1;
    }
    while (std::getline(inputFile, line))
    {
        std::string replaced = replace(line, s1, s2);
        outputFile << replaced << std::endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
