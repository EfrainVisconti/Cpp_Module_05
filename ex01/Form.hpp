/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:45:17 by codespace         #+#    #+#             */
/*   Updated: 2024/11/15 14:54:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# define HIGHEST 1
# define LOWEST 150

class Bureaucrat;

class Form
{
    private:
        std::string const   _name;
        bool                _isSigned;
        int const           _signGrade;
        int const           _execGrade;

    public:
        Form();
        Form(std::string name, int signGrade, int execGrade);
        Form(Form const &other);
        ~Form();
        Form    &operator=(const Form &other);
        
        std::string getName() const;
        bool         getIsSigned() const;
        int         getSignGrade() const;
        int         getExecGrade() const;
        void        beSigned(Bureaucrat &bureaucrat);

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

        class IsAlreadySignedException : public std::exception
        {
            public:
                char const  *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &str, const Form &form);

#endif