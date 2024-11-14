/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:06:27 by codespace         #+#    #+#             */
/*   Updated: 2024/11/14 16:32:37 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const std::string RESET = "\033[0m";
const std::string GREEN = "\033[32m";

int main()
{
    std::cout << std::endl << GREEN << "-----Testing Bureaucrat created with grade too low-----" << RESET << std::endl;
    try
    {
        Bureaucrat jon("jon", LOWEST + 1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << GREEN << "-----Testing Bureaucrat created with grade too high-----" << RESET << std::endl;
    try
    {
        Bureaucrat jon("jon", HIGHEST - 1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << GREEN << "-----Testing Bureaucrat when decrementing grade-----" << RESET << std::endl;
    try
    {
        Bureaucrat jon("jon", LOWEST);
        std::cout << jon << std::endl;
        jon.decrementGrade(1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl << GREEN << "-----Testing Bureaucrat when incrementing grade-----" << RESET << std::endl;
    try
    {
        Bureaucrat jon("jon", HIGHEST);
        std::cout << jon << std::endl;
        jon.incrementGrade(1);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}