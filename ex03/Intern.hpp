/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:42:32 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/14 11:56:31 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# define FORMS 3


class Intern
{
    typedef AForm* (Intern::*createForm)(std::string const &);
    const char *forms[3];
    createForm createform[3];
    public:
        Intern();
        Intern(Intern const &old_obj);
        Intern &operator=(Intern const &other);
        ~Intern();
        AForm *makeForm(std::string const &form_name, std::string const &form_target);
        AForm *createShrubbery(std::string const &form_target);
        AForm *createRobotomyRequest(std::string const &form_target);
        AForm *createPresidentialPardon(std::string const &form_target);
};


#endif
