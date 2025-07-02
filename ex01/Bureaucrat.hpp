#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Form;

class Bureaucrat
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

private:
    const std::string Name;
    unsigned int Grade;

public:
    Bureaucrat(std::string name, unsigned int grade);
    Bureaucrat(const Bureaucrat &b);
    Bureaucrat &operator=(const Bureaucrat &b);
    ~Bureaucrat();
    std::string getName() const;
    unsigned int getGrade() const;
    void incrementGrade();
    void decrement_grade();
    void signForm(Form &f);
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);
