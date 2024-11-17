/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:33:51 by codespace         #+#    #+#             */
/*   Updated: 2024/11/17 00:40:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    std::cout << "Intern copy constructor called" << std::endl;
    *this = other;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

Intern  &Intern::operator=(const Intern &other)
{
    std::cout << "Intern copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

AForm   *Intern::createRobotomyRequestForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm   *Intern::createPresidentialPardonForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm   *Intern::createShrubberyCreationForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm   *Intern::makeForm(std::string const formName, std::string const formTarget)
{
    std::string validForms[SIZE] = {"robotomy request",
                                "presidential pardon",
                                "shrubbery creation"};
    AForm *(Intern::*functs[SIZE])(std::string) = {&Intern::createRobotomyRequestForm,
                                            &Intern::createPresidentialPardonForm,
                                            &Intern::createShrubberyCreationForm};

    for (int i = 0; i < SIZE; i++)
    {
        if (validForms[i] == formName)
        {
            std::cout << "Intern creates " << validForms[i] << std::endl;
            return (this->*functs[i])(formTarget);
        }
    }
    throw Intern::InvalidFormNameException(); 
}

const char  *Intern::InvalidFormNameException::what() const throw()
{
    return "Invalid Form Name!";
}