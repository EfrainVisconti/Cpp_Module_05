/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:18:56 by codespace         #+#    #+#             */
/*   Updated: 2024/11/15 18:20:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(LOWEST), _execGrade(LOWEST)
{
    std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    std::cout << "AForm constructor called: " << this->_name << std::endl;
    if (signGrade < HIGHEST || execGrade < HIGHEST)
        throw AForm::GradeTooHighException();
    else if (signGrade > LOWEST || execGrade > LOWEST)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const Form &other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
    std::cout << "Form copy constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "Form destructor called: " << this->_name << std::endl;
}

AForm    &AForm::operator=(const AForm &other)
{
    std::cout << "AForm copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->_isSigned = other._isSigned;
    return *this;
}