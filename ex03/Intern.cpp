/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:42:34 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/14 12:03:06 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    forms[0] = "shrubbery";
    forms[1] = "robotomy request";
    forms[2] = "presidential pardon";
    createform[0] = &Intern::createShrubbery;
    createform[1] = &Intern::createRobotomyRequest;
    createform[2] = &Intern::createPresidentialPardon;
}

Intern::Intern(Intern const &old_obj) {
    this->forms[0] = old_obj.forms[0];
    this->forms[1] = old_obj.forms[1];
    this->forms[2] = old_obj.forms[2];
    this->createform[0] = old_obj.createform[0];
    this->createform[1] = old_obj.createform[1];
    this->createform[2] = old_obj.createform[2];
}

Intern &Intern::operator=(Intern const &other) {
    if (this != &other)
    {
        this->forms[0] = other.forms[0];
        this->forms[1] = other.forms[1];
        this->forms[2] = other.forms[2];
        this->createform[0] = other.createform[0];
        this->createform[1] = other.createform[1];
        this->createform[2] = other.createform[2];
    }
    return (*this);
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string const &form_name, std::string const &form_target) {
    for (int i = 0; i < FORMS; i++)
        if (this->forms[i] == form_name)
            return ((this->*createform[i])(form_target));
    std::cout << "Intern doesn't create " << form_name << " form" << std::endl;
    return (0);
}

AForm *Intern::createShrubbery(std::string const &form_target) {
    AForm *newShrubberyForm;

    newShrubberyForm = new ShrubberyCreationForm(form_target);
    std::cout << "Intern creates " << *newShrubberyForm << std::endl;
    return (newShrubberyForm);
}

AForm *Intern::createRobotomyRequest(std::string const &form_target) {
    AForm *newRobotomyRequest;

    newRobotomyRequest = new RobotomyRequestForm(form_target);
    std::cout << "Intern creates " << *newRobotomyRequest << std::endl;
    return (newRobotomyRequest);
}

AForm *Intern::createPresidentialPardon(std::string const &form_target) {
    AForm *newPresidentialPardon;

    newPresidentialPardon = new PresidentialPardonForm(form_target);
    std::cout << "Intern creates " << *newPresidentialPardon << std::endl;
    return (newPresidentialPardon);
}
