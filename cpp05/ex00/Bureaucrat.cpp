#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name)
{
    if (other._grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (other._grade < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade = other._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (other._grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (other._grade < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::increment(void)
{
	if(_grade > 1)
		_grade--;
	else
		throw GradeTooHighException();
}

void Bureaucrat::decrement(void)
{

	if(_grade < 150)
		_grade++;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
    os << other.getName() << ", bureaucrat grade " << other.getGrade();
    return os;
}