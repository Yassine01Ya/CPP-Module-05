#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form::GradeTooHighException";
}
const char* Form::GradeTooLowException::what() const throw()
{
    return "Form::GradeTooLowException";
}
const char* Form::EmptyNameException::what() const throw()
{
    return "Form::EmptyNameException";
}

Form::Form(const std::string name, const unsigned int toSign, const unsigned int toExec)
    : Name(name), isSigned(false), gradeToSign(toSign), gradeToExec(toExec)
{
    if (name.empty())
        throw Form::EmptyNameException();
    if (toSign < 1 || toExec < 1)
        throw Form::GradeTooHighException();
    if (toSign > 150 || toExec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& f)
    : Name(f.Name), isSigned(f.isSigned), gradeToSign(f.gradeToSign),
      gradeToExec(f.gradeToExec)
{
}

Form& Form::operator=(const Form& f)
{
    if (this != &f)
    {
        isSigned = f.isSigned;
    }
    return *this;
}

std::string Form::getName() const
{
    return Name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

unsigned int Form::getGradeToSign() const
{
    return gradeToSign;
}

unsigned int Form::getGradeToExec() const
{
    return gradeToExec;
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > gradeToSign)
        throw Form::GradeTooLowException();
    isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& rhs)
{
    out << "Form Name: " << rhs.getName();
    rhs.getIsSigned() ? out << ", is signed\n" : out << ", couldn't sign\n";
    out << "requires " << rhs.getGradeToSign() << " higher to sign\n"
        << "requires " << rhs.getGradeToExec() << " higher t exec\n";
    return out;
}
