/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:33:51 by codespace         #+#    #+#             */
/*   Updated: 2024/11/15 21:52:50 by codespace        ###   ########.fr       */
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

AForm   *Intern::makeForm(std::string const formName, std::string const formTarget)
{
    try
    {
        
        std::cout << "Intern creates " << formName << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

const char  *Intern::InvalidFormNameException::what() const throw()
{
    return "Invalid Form Name!";
}