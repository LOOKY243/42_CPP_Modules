#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string _name;
        bool _sign;
        const int _gradeSign;
        const int _gradeExec;

    public:
        Form();
        Form(std::string name, const int gradeSign, const int gradeExec);
        Form(const Form &other);
        Form &operator=(const Form &other);

        ~Form();

        std::exception GradeTooHighException();
        std::exception GradeTooLowException();
        void    beSigned(Bureaucrat &bureaucrat);
        const std::string getName() const;
        bool getSign() const;
        int getGradeSign() const;
        int getGradeExec() const;
};

std::ostream &operator<<(std::ostream &os, Form const &other);

#endif