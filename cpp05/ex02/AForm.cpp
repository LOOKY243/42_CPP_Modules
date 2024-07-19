#include "AForm.hpp"

AForm::AForm(): _name("AForm"), _gradeSign(150), _gradeExec(150)
{
    _sign = false;
}

AForm::AForm(std::string name, const int gradeSign, const int gradeExec): _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec)
{
    _sign = false;
}

AForm::AForm(const AForm &other): _name(other._name), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec)
{
    _sign = other._sign;
}

AForm &AForm::operator=(const AForm &other)
{
    _sign = other._sign;
    const_cast<std::string &>(_name) = other._name;
    const_cast<int &>(_gradeSign) = other._gradeSign;
    const_cast<int &>(_gradeExec) = other._gradeExec;
    return *this;
}

AForm::~AForm()
{
}

std::exception AForm::GradeTooHighException()
{
    throw std::invalid_argument("Grade too high");
}

std::exception AForm::GradeTooLowException()
{
    throw std::invalid_argument("Grade too low");
}

void    AForm::beSigned(Bureaucrat &bureaucrat)
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

const std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSign() const
{
	return _sign;
}

int AForm::getGradeSign() const
{
	return _gradeSign;
}

int AForm::getGradeExec() const
{
	return _gradeExec;
}
std::ostream &operator<<(std::ostream &os, AForm const &other)
{
    if (other.getSign())
		os << ", signed";
	else
		os << ", not signed";
	os << ", can be signed by at least " << other.getGradeSign();
	os << ", can be executed by at least " << other.getGradeExec() << ".\x1b[0m";
    return os;
}