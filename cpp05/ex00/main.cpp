#include "Bureaucrat.hpp"

// int main()
// {
//     Bureaucrat first;
//     Bureaucrat second("Mie", 1);
//     Bureaucrat third("Caline", 25);
//     Bureaucrat fourth(first);

//     try
//     {
//         // first.decrement();
//         // std::cout << first.getGrade() << std::endl;
//         // second.increment();
//         std::cout << second.getGrade() << std::endl;
//         std::cout << "------------------" << std::endl;
//         for (int i = 0; i < 11; i++)
//         {
//             third.increment();
//             std::cout << third.getGrade() << std::endl;
//         }
//         std::cout << "------------------" << std::endl;
//         fourth.increment();
//         std::cout << fourth.getGrade() << std::endl;
//         fourth.decrement();
//         std::cout << fourth.getGrade() << std::endl;
//     }
//     catch (std::exception & e) {
//         std::cerr << e.what() << std::endl;
//     }
// }

void TooLow()
{
    try {
        Bureaucrat low("Low", 151);
        std::cout << low << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
    }
}

void TooHigh()
{
    try {
        Bureaucrat high("High", 0);
        std::cout << high << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
    }
}

void GoLow()
{
    try {
        Bureaucrat low("Low", 150);
        std::cout << low << std::endl;
        low.decrement();
        std::cout << low << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
    }
}

void GoHigh()
{
    try {
        Bureaucrat high("High", 1);
        std::cout << high << std::endl;
        high.increment();
        std::cout << high << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "\x1b[1;31m" << e.what() << "\x1b[0m" << std::endl;
    }
}

int main()
{
    TooLow();
    TooHigh();
    GoLow();
    GoHigh();
}