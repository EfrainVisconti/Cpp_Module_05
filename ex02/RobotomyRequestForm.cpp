/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:21:00 by codespace         #+#    #+#             */
/*   Updated: 2024/11/15 19:50:50 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Untargeted") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm  &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this == &other)
        return *this;
    AForm::operator=(other);
	this->_target = other._target;
    return *this;
}

void    RobotomyRequestForm::doExecute() const
{
    std::cout << "*Some drilling noises...*" << std::endl;
	int success = rand() % 2;
	if (success)
        std::cout << this->_target << " has been robotomized." << std::endl;
	else
		std::cout << this->_target << " robotomization failed." << std::endl;
}