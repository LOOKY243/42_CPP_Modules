#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Bureaucrat"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name)
{
    std::cout << "Copy constructor called" << std::endl;
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

std::exception Bureaucrat::GradeTooHighException()
{
    throw std::invalid_argument("Grade too high");
}

std::exception Bureaucrat::GradeTooLowException()
{
    throw std::invalid_argument("Grade too low");
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

void    Bureaucrat::signForm(int opt, std::string form)
{
    if (opt == 1)
        std::cout << getName() << " signed " << form << std::endl;
    else if (opt == 2)
        std::cout << getName() << " is already signed" << std::endl;
    else
        std::cout << getName() << " couldn't sign " << form
            << " because its grade isn't high enough" << std::endl;
}