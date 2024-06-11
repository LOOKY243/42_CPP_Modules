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

int main(int argc, char **argv)
{
    std::string line;
    std::string filename;
    std::string s1;
    std::string s2;

    if (argc != 4)
    {
        std::cout << "Use: ./sed Filename, to_replace, replace_with" << std::endl;
        return 1;
    }
    filename = argv[1];
    s1 = argv[2];
    s2 = argv[3];
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
