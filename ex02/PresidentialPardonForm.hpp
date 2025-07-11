#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string Target;

public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& cpy);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& cpy);
    ~PresidentialPardonForm();
    void execute(Bureaucrat const& executor) const;
};
