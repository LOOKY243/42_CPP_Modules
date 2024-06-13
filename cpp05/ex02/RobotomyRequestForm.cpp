#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45)
{
    _target = "Default";
    _status = false;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
    _target = target;
    _status = false;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other)
{
    _target = other._target;
    _status = other._status;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this == &other)
        return *this;
    AForm::operator=(other);
    _target = other._target;
    _status = other._status;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor)
{
    if (executor.getGrade() <= getGradeExec())
    {
        std::cout << "* DRILLING NOISES *" << std::endl;
        _status = !_status;
        if (_status)
            std::cout << _target << " has been robotomized successfully" << std::endl;
        else
            std::cout << "Robotomy has failed" << std::endl;
    }
    else
        std::cout << "Grade isn't high enough to execute the form" << std::endl;
}