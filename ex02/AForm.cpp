#include "AForm.hpp"
const char* AForm::GradeTooHighException::what() const throw()
{
    return "AForm::GradeTooHighException";
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return "AForm::GradeTooLowException";
}
const char* AForm::EmptyNameException::what() const throw()
{
    return "AForm::EmptyNameException";
}
const char* AForm::EmptyTargetException::what() const throw()
{
    return "AForm::EmptyTargetException";
}
const char* AForm::FormNotSignedException::what() const throw()
{
    return "AForm::FormNotSignedException";
}

AForm::AForm(const std::string name, const unsigned int toSign, const unsigned int toExec)
    : Name(name), isSigned(false), gradeToSign(toSign), gradeToExec(toExec)
{
    if (name.empty())
        throw AForm::EmptyNameException();
    if (toSign < 1 || toExec < 1)
        throw AForm::GradeTooHighException();
    if (toSign > 150 || toExec > 150)
        throw AForm ::GradeTooLowException();
}

AForm::AForm(const AForm& f)
    : Name(f.Name), isSigned(f.isSigned), gradeToSign(f.gradeToSign),
      gradeToExec(f.gradeToExec)
{
}

AForm& AForm::operator=(const AForm& f)
{
    if (this != &f)
        isSigned = f.isSigned;
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const
{
    return Name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

unsigned int AForm::getGradeToSign() const
{
    return gradeToSign;
}

unsigned int AForm::getGradeToExec() const
{
    return gradeToExec;
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    isSigned = true;
}
void AForm::execute(Bureaucrat const& executor) const
{
    if (executor.getGrade() > gradeToExec)
        throw AForm::GradeTooLowException();
    if (isSigned == false)
        throw AForm::FormNotSignedException();
}

std::ostream& operator<<(std::ostream& out, const AForm& rhs)
{
    out << "Form Name : " << rhs.getName();
    rhs.getIsSigned() ? out << " is signed\n" : out << " is not signed\n";
    out << "requires " << rhs.getGradeToSign() << " grade or higher to sign\n"
        << "requires " << rhs.getGradeToExec() << " grade or higher to execute\n";
    return out;
}
