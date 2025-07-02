#pragma once
#include <string>
#include <iostream>
#include <fstream>

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
    Bureaucrat(const Bureaucrat &cpy);
    Bureaucrat &operator=(const Bureaucrat &cpy);
    ~Bureaucrat();
    std::string getName() const;
    unsigned int getGrade() const;
    void incrementGrade();
    void decrement_grade();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);
