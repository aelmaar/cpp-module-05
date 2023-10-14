/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:26:14 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/12 16:57:54 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const &old_obj);
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
        ~PresidentialPardonForm();
        void execute(Bureaucrat const & executor) const;
};

#endif
