/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:26:23 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/13 17:51:16 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const &old_obj);
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
        ~ShrubberyCreationForm();
        void execute(Bureaucrat const & executor) const;
        class FilePermissionDenied;
};

class ShrubberyCreationForm::FilePermissionDenied: public std::exception {
    public:
        const char *what() const throw();
};

#endif