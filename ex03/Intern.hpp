#pragma once
#include <string>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
public:
    class NoFormNameException : public std::exception
    {
    public:
        const char *what() const throw();
    };

private:
    ShrubberyCreationForm  Shrubbery;
    PresidentialPardonForm Presidential;
    RobotomyRequestForm    Robotomy;
    AForm*  Forms[3];

public:
    Intern();
    Intern(const Intern& i);
    Intern& operator=(const Intern& i);
    ~Intern();
    AForm* MakeForm(std::string FormName, std::string TargetName);
};
