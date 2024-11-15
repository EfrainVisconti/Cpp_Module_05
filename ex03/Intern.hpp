/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:30:18 by codespace         #+#    #+#             */
/*   Updated: 2024/11/15 21:42:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
# define Intern_HPP

# include <iostream>
# include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &other); //Copy constructor
        ~Intern();
        Intern  &operator=(const Intern &other); //Copy assignment operator
        
        AForm   *makeForm(std::string const formName, std::string const formTarget);

        class InvalidFormNameException : public std::exception
        {
            public:
                char const  *what() const throw();
        };
};

#endif