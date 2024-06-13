#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat first;
    Form form;
    Form form2("jobless", 14, 30);
    Bureaucrat second("Mie", 1);
    Bureaucrat third("Caline", 25);
    Bureaucrat fourth(first);

    try
    {
        std::cout << first.getGrade() << std::endl;
        first.decrement();
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        form.beSigned(first);
        std::cout << first.getGrade() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "------------------" << std::endl;
    try
    {
        std::cout << second.getGrade() << std::endl;
        second.increment();
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "------------------" << std::endl;
    try
    {
        for (int i = 0; i < 11; i++)
        {
            third.increment();
            form2.beSigned(third);
            std::cout << third.getGrade() << std::endl;
        }
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "------------------" << std::endl;
    try
    {
        fourth.increment();
        std::cout << fourth.getGrade() << std::endl;
        fourth.decrement();
        std::cout << fourth.getGrade() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}