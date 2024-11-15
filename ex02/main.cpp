/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:40:21 by codespace         #+#    #+#             */
/*   Updated: 2024/11/15 17:17:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const std::string RESET = "\033[0m";
const std::string GREEN = "\033[32m";

int main()
{
    std::cout << std::endl << GREEN << "-----Testing Form created with grade too low-----" << RESET << std::endl;
    try
    {
        Form f1("f1", LOWEST + 1, LOWEST);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << GREEN << "-----Testing Form created with grade too high-----" << RESET << std::endl;
    try
    {
        Form f1("f1", HIGHEST, HIGHEST - 1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << GREEN << "-----Testing Bureaucrats and Forms interacting-----" << RESET << std::endl;
    Bureaucrat jon("jon", LOWEST);
    Form f1("f1", LOWEST, LOWEST);
    Form f2("f2", HIGHEST, HIGHEST);
    std::cout << jon << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << std::endl << GREEN << "-----Jon signing f1 (valid grades)-----" << RESET << std::endl;
    try
    {
        jon.signForm(f1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        f1.beSigned(jon);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << f1 << std::endl;
    std::cout << std::endl << GREEN << "-----Jon signing f2 (invalid grades)-----" << RESET << std::endl;
    try
    {
        jon.signForm(f2);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        f2.beSigned(jon);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << f2 << std::endl;
    std::cout << std::endl << GREEN << "-----Destructors-----" << RESET << std::endl;
    return 0;
}