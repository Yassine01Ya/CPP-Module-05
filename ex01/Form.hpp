#pragma once
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class Form
{
public:
    class GradeTooHighException : public std::exception
    {
    public :
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
    bool isSigned;
    const unsigned int gradeToSign;
    const unsigned int gradeToExec;

public:
  Form(const std::string name, const unsigned int toSign,
       const unsigned int toExec);
  Form(const Form& f);
  Form& operator=(const Form& f);
  std::string getName() const;
  bool getIsSigned() const;
  unsigned int getGradeToSign() const;
  unsigned int getGradeToExec() const;
  void beSigned(const Bureaucrat& b);
};

std::ostream &operator<<(std::ostream &out, const Form &rhs);