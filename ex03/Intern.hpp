/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:30:18 by codespace         #+#    #+#             */
/*   Updated: 2024/11/17 00:28:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
# define Intern_HPP

# include <iostream>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# define SIZE 3

class Intern
{
    public:
        Intern();
        Intern(const Intern &other); //Copy constructor
        ~Intern();
        Intern  &operator=(const Intern &other); //Copy assignment operator
        
        AForm   *createRobotomyRequestForm(std::string target);
        AForm   *createPresidentialPardonForm(std::string target);
        AForm   *createShrubberyCreationForm(std::string target);
        AForm   *makeForm(std::string const formName, std::string const formTarget);

        class InvalidFormNameException : public std::exception
        {
            public:
                char const  *what() const throw();
        };
};

#endif