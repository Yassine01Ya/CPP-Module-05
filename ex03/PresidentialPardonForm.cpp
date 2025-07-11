#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), Target(target)
{
    if (target.empty())
        throw AForm::EmptyTargetException();
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy)
    : AForm(cpy), Target(cpy.Target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& cpy
)
{
    if (this != &cpy)
    {
        (AForm&)* this = cpy;
        Target         = cpy.Target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    AForm::execute(executor);
    std::cout << Target << " has been pardoned by Zaphod Beeblebrox.\n";
}

void PresidentialPardonForm::setTarget(std::string newTarget)
{
    if (newTarget.empty())
        throw AForm::EmptyTargetException();
    Target = newTarget;
}
