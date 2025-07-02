#include "Bureaucrat.hpp"

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "GradeTooHighException";
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "GradeTooLowException";
}
const char *Bureaucrat::EmptyNameException::what() const throw()
{
    return "EmptyNameException";
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : Name(name)
{
    if (name.empty())
        throw EmptyNameException();
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    Grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy)
{
    *this = cpy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy)
{
    if (&cpy != this)
        Grade = cpy.Grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
    return Name;
}

unsigned int Bureaucrat::getGrade() const
{
    return Grade;
}

void Bureaucrat::incrementGrade()
{
    if (Grade == 1)
        throw GradeTooHighException();
    Grade--;
}


void Bureaucrat::decrement_grade()
{
    if (Grade == 150)
        throw GradeTooLowException();
    Grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs)
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return out;
}
