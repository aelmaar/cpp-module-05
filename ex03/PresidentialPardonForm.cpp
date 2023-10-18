/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:26:11 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/18 13:43:11 by ael-maar         ###   ########.fr       */
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
        throw PresidentialPardonForm::GradeTooLowException();
    if (!this->getIsSigned())
        throw PresidentialPardonForm::NotSignedException();
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
