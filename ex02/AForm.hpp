/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:45:17 by codespace         #+#    #+#             */
/*   Updated: 2024/11/15 19:41:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# define HIGHEST 1
# define LOWEST 150

class Bureaucrat;

class AForm
{
    private:
        std::string const   _name;
        bool                _isSigned;
        int const           _signGrade;
        int const           _execGrade;

    public:
        AForm();
        AForm(std::string name, int signGrade, int execGrade);
        AForm(AForm const &other);
        virtual ~AForm();
        AForm    &operator=(const AForm &other);
        
        std::string     getName() const;
        bool            getIsSigned() const;
        int             getSignGrade() const;
        int             getExecGrade() const;
        void            setIsSigned();
        void            beSigned(Bureaucrat &bureaucrat);
        void            execute(Bureaucrat const &executor) const;
        virtual void    doExecute() const = 0;

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

        class IsNotSignedException : public std::exception
        {
            public:
                char const  *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &str, const AForm &form);

#endif