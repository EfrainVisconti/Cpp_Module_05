/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:45:17 by codespace         #+#    #+#             */
/*   Updated: 2024/11/14 17:18:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# define HIGHEST 1
# define LOWEST 150

class Form
{
    private:
        std::string const   _name;
        bool                _isSigned;
        int const           _signGrade;
        int const           _execGrade;

    public:
        Form():
        Form(std::string const name, int const signGrade, int const execGrade);
        Form(Form const &other);
        ~Form();
        Form    &operator=(const Form &other);
        
        std::string getName() const;
        int         getIsSigned() const;
        int         getSignGrade() const;
        int         getExecGrade() const;
        void        beSigned(Bureaucrat const &bureaucrat);

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

std::ostream    &operator<<(std::ostream &str, const Form &form);

#endif