/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:40:02 by codespace         #+#    #+#             */
/*   Updated: 2024/11/15 14:52:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"
# define HIGHEST 1
# define LOWEST 150

class Form;

class Bureaucrat
{
    private:
        std::string _name;
        int         _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string const name, int grade);
        Bureaucrat(const Bureaucrat &other); //Copy constructor
        ~Bureaucrat();
        Bureaucrat  &operator=(const Bureaucrat &other); //Copy assignment operator
        
        std::string getName() const;
        int         getGrade() const; 
        void        incrementGrade(int value);
        void        decrementGrade(int value);
        void        signForm(Form &form);

        class GradeTooHighException : public std::exception
        {
            public:
                char const  *what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                char const  *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &str, const Bureaucrat &bureaucrat);

#endif