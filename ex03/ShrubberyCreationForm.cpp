#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), Target(target)
{
    if (target.empty())
        throw EmptyTargetException();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy)
    : AForm(cpy), Target(cpy.Target)
{
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& cpy)
{
    if (this != &cpy)
    {
        (AForm&)* this = cpy;
        Target         = cpy.Target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
    AForm::execute(executor);
    std::ofstream file_shrubbery((Target + "_shrubbery").c_str());
    file_shrubbery << ASCII_TREE;
    file_shrubbery.close();
}
void ShrubberyCreationForm::setTarget(std::string newTarget)
{
    if (newTarget.empty())
        throw AForm::EmptyTargetException();
    Target = newTarget;
}
