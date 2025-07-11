#pragma once
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class AForm
{
public:
    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw();
    };
    
    class EmptyNameException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class EmptyTargetException : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class FormNotSignedException : public std::exception
    {
    public:
        const char* what() const throw();
    };
private:
    const std::string Name;
    bool isSigned;
    const unsigned int gradeToSign;
    const unsigned int gradeToExec;

public:
    AForm(const std::string name, const unsigned int toSign, const unsigned int toExec);
    AForm(const AForm &f);
    AForm &operator=(const AForm &f);
    virtual ~AForm();
    std::string getName() const;
    bool getIsSigned() const;
    unsigned int getGradeToSign() const;
    unsigned int getGradeToExec() const;
    void beSigned(const Bureaucrat& b);
    virtual void execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream &out, const AForm &rhs);