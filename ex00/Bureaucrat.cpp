/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:06:53 by codespace         #+#    #+#             */
/*   Updated: 2024/11/13 16:51:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(1)
{
    std::cout << "Default Bureaucrat constructor called" << std::endl;
    //to do throw error
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Bureaucrat constructor called: " << this->_name << std::endl;
    //to do throw error
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = other;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called: " << this->_name << std::endl;
}

Bureaucrat  &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->_name = other.getName();
    this->_grade = other.getGrade();
    return *this;
}

std::string Bureaucrat::getName()
{
    return this->_name;
}

int Bureaucrat::getGrade()
{
    return this->_grade;
}