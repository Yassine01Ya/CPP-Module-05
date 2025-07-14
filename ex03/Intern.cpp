#include "Intern.hpp"

const char* Intern::NoFormNameException::what() const throw()
{
    return "NoFormNameException";
}
Intern::Intern() : Shrubbery("home"), Presidential("home"), Robotomy("home")
{
    Forms[0] = &Shrubbery;
    Forms[1] = &Presidential;
    Forms[2] = &Robotomy;
}

Intern::Intern(const Intern& i)
    : Shrubbery(i.Shrubbery), Presidential(i.Presidential), Robotomy(i.Robotomy)
{
    Forms[0] = &Shrubbery;
    Forms[1] = &Presidential;
    Forms[2] = &Robotomy;
}

Intern& Intern::operator=(const Intern& i)
{
    if (this != &i)
    {
        Shrubbery    = i.Shrubbery;
        Presidential = i.Presidential;
        Robotomy     = i.Robotomy;
    }
    return *this;
}

Intern::~Intern() {}

AForm* Intern::MakeForm(std::string FormName, std::string TargetName)
{
    for (int i = 0; i < 3; i++)
    {
        if (Forms[i]->getName() == FormName)
        {
            Forms[i]->setTarget(TargetName);
            return Forms[i];
        }
    }
    throw Intern::NoFormNameException();
}
