#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);

        ~Bureaucrat();

        std::exception GradeTooHighException();
        std::exception GradeTooLowException();

        const std::string getName() const;
        int getGrade() const;

        void increment();
        void decrement();
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other);

#endif