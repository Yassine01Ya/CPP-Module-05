#pragma once
#include "AForm.hpp"
#include <string>

#define ASCII_TREE                                                                       \
    "       ^\n"                                                                         \
    "      ^^^\n"                                                                        \
    "     ^^^^^\n"                                                                       \
    "    ^^^^^^^\n"                                                                      \
    "   ^^^^^^^^^\n"                                                                     \
    "  ^^^^^^^^^^^\n"                                                                    \
    " ^^^^^^^^^^^^^\n"                                                                   \
    "^^^^^^^^^^^^^^^\n"                                                                  \
    "      ###\n"                                                                        \
    "      ###\n";

class ShrubberyCreationForm : public AForm
{
private:
    std::string Target;

public:
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& cpy);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& cpy);
    ~ShrubberyCreationForm();
    void execute(Bureaucrat const& executor) const;
};
