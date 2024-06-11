#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl pedro;

    if (argc != 2)
    {
        std::cout << "1 argument needed." << std::endl;
        return (0);
    }
    pedro.complain(argv[1]);
    return (1);
}