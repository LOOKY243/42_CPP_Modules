#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45)
{
    _target = "Default";
    _sign = false;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
    _target = target;
    _sign = false;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other)
{
    _target = other._target;
    _sign = other._sign;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this == &other)
        return *this;
    AForm::operator=(other);
    _target = other._target;
    _sign = other._sign;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::ExecForm() const
{
    std::cout << "* DRILLING NOISES *" << std::endl;
    srand(time(NULL));
	int random = rand() % 100;
    if (random < 50)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy has failed" << std::endl;
}