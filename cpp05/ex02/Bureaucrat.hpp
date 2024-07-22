#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    class GradeTooHighException: public std::exception
    {
        virtual const char *what() const throw()
        {
            return "Grade is too high";
        }
    };
    class GradeTooLowException: public std::exception
    {
        virtual const char *what() const throw()
        {
            return "Grade is too low";
        }
    };
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);

        ~Bureaucrat();

        const std::string getName() const;
        int getGrade() const;

        void increment();
        void decrement();
        void signForm(int opt, std::string form);
        void executeForm(const AForm &form) const;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other);

#endif