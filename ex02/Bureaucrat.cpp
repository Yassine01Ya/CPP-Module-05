#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat::GradeTooHighException";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat::GradeTooLowException";
}
const char* Bureaucrat::EmptyNameException::what() const throw()
{
    return "Bureaucrat::EmptyNameException";
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

Bureaucrat::Bureaucrat(const Bureaucrat& b)
{
    *this = b;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b)
{
    if (&b != this)
        Grade = b.Grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

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

void executeForm(AForm const& form);

void Bureaucrat::decrement_grade()
{
    if (Grade == 150)
        throw GradeTooLowException();
    Grade++;
}

void Bureaucrat::signForm(AForm& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << Name << " signed " << f.getName() << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << Name << " couldn't sign " << f.getName() << " because " << e.what()
                  << "\n";
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& rhs)
{
    out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
    return out;
}

void Bureaucrat::executeForm(AForm const& form)
{
    try
    {
        form.execute(*this);
        std::cout << Name << " executed " << form.getName() << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << Name << " did not executed " << form.getName()
                  << " for this reason : " << e.what() << '\n';
    }

    try
    {
        form.execute(*this);
        std::cout << Name << "executed " << form.getName() << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << Name << "is not executed " << form.getName() << "for this reason -> "
                  << e.what() << "\n";
    }
}
