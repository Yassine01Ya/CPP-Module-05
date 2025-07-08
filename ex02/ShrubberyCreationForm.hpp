#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string Target;

public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &cpy);
    ~ShrubberyCreationForm();
    void execute(Bureaucrat const &executor) const;
};
