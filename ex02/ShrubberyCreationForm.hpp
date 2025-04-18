/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:19:08 by codespace         #+#    #+#             */
/*   Updated: 2024/11/15 20:24:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"
# define HIGHEST 1
# define LOWEST 150

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;    

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &other);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm   &operator=(const ShrubberyCreationForm &other);

        void    doExecute() const;
};

#endif