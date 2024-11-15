/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:40:21 by codespace         #+#    #+#             */
/*   Updated: 2024/11/15 21:33:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

const std::string RESET = "\033[0m";
const std::string GREEN = "\033[32m";

int main()
{
    std::cout << std::endl << GREEN << "-----Constructors-----" << RESET << std::endl;
    ShrubberyCreationForm shrubbery("home");
	RobotomyRequestForm robotomy("Robot");
	PresidentialPardonForm pardon("Ford");
	Bureaucrat jon("Jon", LOWEST);
	Bureaucrat jim("Jim", HIGHEST);
  
    std::cout << std::endl << GREEN << "-----Testing Bureaucrats and AForms interacting-----" << RESET << std::endl;
    std::cout << jon << std::endl;
    std::cout << jim << std::endl;
    std::cout << shrubbery << std::endl;
    std::cout << robotomy << std::endl;
    std::cout << pardon << std::endl;
    std::cout << std::endl << GREEN << "-----Valid signing, invalid execution-----" << RESET << std::endl;
    try
    {
        jim.signForm(robotomy);
        robotomy.execute(jon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << robotomy << std::endl;
    std::cout << std::endl << GREEN << "-----Invalid signing, invalid execution-----" << RESET << std::endl;
    try
    {
        jon.signForm(pardon);
        pardon.execute(jon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << pardon << std::endl;
    std::cout << std::endl << GREEN << "-----Valid signing, valid execution-----" << RESET << std::endl;
    try
    {
        jim.signForm(shrubbery);
        jim.signForm(robotomy);
        jim.signForm(pardon);
        shrubbery.execute(jim);
        robotomy.execute(jim);
        jim.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl << GREEN << "-----Destructors-----" << RESET << std::endl;
    return 0;
}