/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:45:13 by codespace         #+#    #+#             */
/*   Updated: 2024/11/14 17:53:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _signGrade(LOWEST), _execGrade(LOWEST)
{
    std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(std::string const name, int const signGrade, int const execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
    std::cout << "Form constructor called: " << this->_name << std::endl;
    if (signGrade < HIGHEST || execGrade < HIGHEST)
        throw Form::GradeTooHighException();
    else if (signGrade > LOWEST || execGrade > LOWEST)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _execGrade(other._execGrade)
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form destructor called: " << this->_name << std::endl;
}

Form    &Form::operator=(const Form &other)
{
    std::cout << "Form copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->_isSigned = other._isSigned;
    return *this;
}

std::string Form::getName() const
{
    return this->_name;
}

bool    Form::getIsSigned() const
{
    return this->_isSigned;
}

int Form::getSignGrade() const
{
    return this->_signGrade;
}

int Form::getExecGrade() const
{
    return this->_execGrade;
}

void    Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (this->_isSigned == true)
    {
        std::cout << "Form " << this->_name << " is already signed" << std::endl;
        return ;
    }
    if (bureaucrat.getGrade() > this->_signGrade)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

const char  *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too High!";
}

const char  *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream	&operator<<(std::ostream &str, Form const &form)
{
	return (str << form.getName() << ", form, isSigned: " << form.getIsSigned() << ", signGrade: " << form.getSignGrade() << ", execGrade: " << form.getExecGrade());
}