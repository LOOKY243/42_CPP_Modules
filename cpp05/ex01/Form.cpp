#include "Form.hpp"

Form::Form(): _name("Form"), _gradeSign(150), _gradeExec(150)
{
    _sign = false;
}

Form::Form(std::string name, const int gradeSign, const int gradeExec): _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    _sign = false;
}

Form::Form(const Form &other): _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
    _sign = other._sign;
}

Form &Form::operator=(const Form &other)
{
    _sign = other._sign;
    const_cast<std::string &>(_name) = other._name;
    const_cast<int &>(_gradeSign) = other._gradeSign;
    const_cast<int &>(_gradeExec) = other._gradeExec;
    return *this;
}

Form::~Form()
{
}

std::exception Form::GradeTooHighException()
{
    throw std::invalid_argument("Grade too high");
}

std::exception Form::GradeTooLowException()
{
    throw std::invalid_argument("Grade too low");
}

void    Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeSign && !_sign)
    {
        _sign = true;
        bureaucrat.signForm(1, _name);
    }
    else if (_sign)
        bureaucrat.signForm(2, _name);
    else
        bureaucrat.signForm(3, _name);
}
