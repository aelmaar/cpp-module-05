/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:47:17 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/12 18:56:22 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(Bureaucrat const &old_obj): name(old_obj.name), range(old_obj.range) {}

Bureaucrat::Bureaucrat(std::string const &name, int range): name(name), range(range) {
    if (range < 1)
        throw Bureaucrat::GradeTooHighException();
    if (range > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
    if (this != &other)
        this->range = other.range;
    return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string const &Bureaucrat::getName() const { return (name); }

const char *Bureaucrat::GradeTooHighException::what() const throw() { return "Grade is too high"; }

const char *Bureaucrat::GradeTooLowException::what() const throw() { return "Grade is too low"; }

int Bureaucrat::getRange() const { return (range); }

void    Bureaucrat::IncrementGrade()
{
    if ((this->range - 1) < 1)
        throw Bureaucrat::GradeTooHighException();
    this->range--;
}


void    Bureaucrat::DecrementGrade()
{
    if ((this->range + 1) > 150)
        throw Bureaucrat::GradeTooLowException();
    this->range++;
}

std::ostream &operator<< (std::ostream &cout, Bureaucrat const &obj) {
    cout << obj.getName();
    cout << ", bureaucrat grade " << obj.getRange();
    return (cout);
}

void    Bureaucrat::signForm(AForm const &form) {
    if (form.getIsSigned())
    {
        std::cout << "The bureaucrat " << this->getName() << " signed " << form.getName() << std::endl;
        return;
    }
    std::cout << "The bureaucrat " << this->getName() << " couldn't sign " << form.getName();
    std::cout << " because the bureaucrat's grade is lower then the form's grade" << std::endl;
}
