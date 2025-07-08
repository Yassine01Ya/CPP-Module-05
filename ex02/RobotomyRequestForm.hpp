#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string Target;

public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &cpy);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &cpy);
    ~RobotomyRequestForm();
    void execute(Bureaucrat const &executor) const;
};
