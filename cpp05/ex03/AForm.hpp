#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
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

        std::exception GradeTooHighException();
        std::exception GradeTooLowException();
        void    beSigned(Bureaucrat &bureaucrat);
        virtual void    execute(Bureaucrat const &Bureaucrat) = 0;
        int    getGradeExec();
        int    getGradeSign();
};

#endif