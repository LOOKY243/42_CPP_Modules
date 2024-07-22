#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    class FormNotSignedException: public std::exception
    {
        virtual const char *what() const throw()
        {
            return "Form is not signed";
        }
    };
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
        bool _sign;
        const int _gradeSign;
        const int _gradeExec;

    public:
        AForm();
        AForm(std::string name, const int gradeSign, const int gradeExec);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);

        virtual ~AForm();

        void    beSigned(Bureaucrat &bureaucrat);
        const std::string getName() const;
        bool getSign() const;
        int getGradeSign() const;
        int getGradeExec() const;
        void execute(const Bureaucrat &executor) const;
        virtual void ExecForm() const = 0;
};

std::ostream &operator<<(std::ostream &os, AForm const &other);

#endif