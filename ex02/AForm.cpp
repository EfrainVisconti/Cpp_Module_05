/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:45:13 by codespace         #+#    #+#             */
/*   Updated: 2024/11/15 18:57:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

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

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm destructor called: " << this->_name << std::endl;
}

AForm    &AForm::operator=(const AForm &other)
{
    std::cout << "AForm copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->_isSigned = other._isSigned;
    return *this;
}

std::string AForm::getName() const
{
    return this->_name;
}

bool    AForm::getIsSigned() const
{
    return this->_isSigned;
}

int AForm::getSignGrade() const
{
    return this->_signGrade;
}

int AForm::getExecGrade() const
{
    return this->_execGrade;
}

void    AForm::setIsSigned()
{
    this->_isSigned = !(this->_isSigned);
}

void    AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (this->_isSigned == true)
        throw AForm::IsAlreadySignedException();
    if (bureaucrat.getGrade() > this->_signGrade)
        throw AForm::GradeTooLowException();
    this->_isSigned = true;
}

void    AForm::execute(Bureaucrat const &executor) const
{
    if (this->_isSigned == false)
        throw AForm::IsNotSignedException();
    if (bureaucrat.getGrade() > this->_execGrade)
        throw AForm::GradeTooLowException();
    this->beExecute();
}

const char  *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too High!";
}

const char  *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char  *AForm::IsAlreadySignedException::what() const throw()
{
    return "It's already signed!";
}

const char  *AForm::IsNotSignedException::what() const throw()
{
    return "It is not signed!"
}

std::ostream	&operator<<(std::ostream &str, AForm const &form)
{
	return (str << form.getName() << ", form isSigned: " << form.getIsSigned() << ", signGrade: " << form.getSignGrade() << ", execGrade: " << form.getExecGrade());
}