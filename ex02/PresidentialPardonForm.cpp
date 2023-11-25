/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:26:11 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/13 17:02:10 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Unknown", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &old_obj): AForm(old_obj) {}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): AForm(target, 25, 5) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (executor.getRange() > this->getGradeExec())
        throw ShrubberyCreationForm::GradeTooLowException();
    else if (!this->getIsSigned())
        throw ShrubberyCreationForm::NotSignedException();
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
