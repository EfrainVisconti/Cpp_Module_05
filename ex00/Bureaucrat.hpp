/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:06:43 by codespace         #+#    #+#             */
/*   Updated: 2024/11/13 16:37:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    private:
        std::string const   _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(const Bureaucrat &other); //Copy constructor
        ~Bureaucrat();
        Bureaucrat  &operator=(const Bureaucrat &other); //Copy assignment operator
        
        std::string getName() const;
        int getGrade() const;
        
        void    incrementGrade(int value);
        void    decrementGrade(int value);
};

std::ostream    &operator<<(std::ostream &out, const Bureaucrat &other);

#endif