/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:06:43 by codespace         #+#    #+#             */
/*   Updated: 2024/11/14 16:07:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# define HIGHEST 1
# define LOWEST 150

class Bureaucrat
{
    private:
        std::string _name;
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

        class GradeTooHighException : public std::exception
        {
            public:
                virtual char const  *what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                virtual char const  *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &str, const Bureaucrat &bureaucrat);

#endif