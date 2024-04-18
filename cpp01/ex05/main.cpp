#include "Harl.hpp"

int main(void)
{
    Harl pedro;
    std::string lvl;

    std::cout << "[ DEBUG ] [ INFO ] [ WARNING ] [ ERROR ]" << std::endl;
    std::cout << "Select a level of complaining: ";
    std::getline(std::cin, lvl);
    pedro.complain(lvl);

}