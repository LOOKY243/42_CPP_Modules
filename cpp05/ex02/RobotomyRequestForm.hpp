#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    private:
        std::string _target;
        bool _status;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string _type);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm &other);

        ~RobotomyRequestForm();

        void execute(Bureaucrat const &executor);
};



#endif