#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), Target(target)
{
    if (target.empty())
        throw AForm::EmptyTargetException();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy)
    : AForm(cpy), Target(cpy.Target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& cpy)
{
    if (this != &cpy)
    {
        (AForm&)* this = cpy;
        Target = cpy.Target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    AForm::execute(executor);
    std::cout << "Making some drilling noises.\n";
    srand(time(0));
    int randomNumber = rand() % 2;
    if (randomNumber)
        std::cout << Target << "has been robotomized successfully\n ";
    else
        std::cout << "The robotomy for " << Target << " Failed.\n";
}
