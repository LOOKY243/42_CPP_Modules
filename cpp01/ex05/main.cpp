#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl pedro;

    for (int i = 1; i < argc; i++)
        pedro.complain(argv[i]);
}