/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:18:56 by codespace         #+#    #+#             */
/*   Updated: 2024/11/15 20:56:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Untargeted") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm  &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this == &other)
        return *this;
    AForm::operator=(other);
	this->_target = other._target;
    return *this;
}

void    ShrubberyCreationForm::doExecute() const
{
    std::ofstream outfile;
    std::string filename = this->_target + "_shrubbery";
	outfile.open(filename.c_str());
	if (!outfile.is_open())
		throw std::runtime_error("Error opening outfile");
    outfile << "               ,@@@@@@@," << std::endl;
    outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
    outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
    outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
    outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
    outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    outfile << "       |o|        | |         | |" << std::endl;
    outfile << "       |.|        | |         | |" << std::endl;
    outfile << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
    outfile.close();
    std::cout << this->getName() << " created " << filename << " with a nice tree" << std::endl;
}