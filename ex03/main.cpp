/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:40:21 by codespace         #+#    #+#             */
/*   Updated: 2024/11/17 01:26:51 by codespace        ###   ########.fr       */
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
    Intern someRandomIntern;
    Bureaucrat jon("Jon", HIGHEST);
    AForm *f1;
    AForm *f2;
    AForm *f3;

    std::cout << std::endl << GREEN << "-----Testing Intern-----" << RESET << std::endl;
    try
    {
        f1 = someRandomIntern.makeForm("robotomy request", "Bender");
        f2 = someRandomIntern.makeForm("presidential pardon", "Bender");
        f3 = someRandomIntern.makeForm("shrubbery creation", "Bender");
        f1->beSigned(jon);
        f2->beSigned(jon);
        f3->beSigned(jon);
        f1->execute(jon);
        f2->execute(jon);
        f3->execute(jon);
        f1 = someRandomIntern.makeForm("invalid form", "Bender");
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
        delete f1;
        delete f2;
        delete f3;
    }
    return 0;
}