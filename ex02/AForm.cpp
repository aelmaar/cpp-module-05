/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:43:35 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/14 13:57:19 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): name("Unknown"), is_signed(false), grade_sign(10), grade_exec(10) {}

AForm::AForm(std::string const &name, int const grade_sign, int const grade_exec): name(name), is_signed(false), grade_sign(grade_sign), grade_exec(grade_exec) {
    if (grade_sign < 1 || grade_exec < 1)
        throw AForm::GradeTooHighException();
    if (grade_sign > 150 || grade_exec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &old_obj): name(old_obj.name), is_signed(old_obj.is_signed), grade_sign(old_obj.grade_sign), grade_exec(old_obj.grade_exec) {}

AForm &AForm::operator=(AForm const &other) {
    if (this != &other)
        this->is_signed = other.is_signed;
    return (*this);
}

AForm::~AForm() {}

const char *AForm::GradeTooHighException::what() const throw() { return "Grade is too high"; }

const char *AForm::GradeTooLowException::what() const throw() { return "Grade is too low"; }

const char *AForm::NotSignedException::what() const throw() { return "Form is not signed"; }

std::string const &AForm::getName() const { return (name); }

bool AForm::getIsSigned() const { return (is_signed); }

int AForm::getGradeSign() const { return (grade_sign); }

int AForm::getGradeExec() const { return (grade_exec); }

void AForm::beSigned(Bureaucrat const &bureaucrat) {
    if (bureaucrat.getRange() > grade_sign)
        throw AForm::GradeTooLowException();
    else
        is_signed = true;
}

std::ostream &operator<< (std::ostream &cout, AForm const &obj) {
    cout << obj.getName();
    cout << " with grade sign: " << obj.getGradeSign() << ", grade execution: " << obj.getGradeExec();
    cout << " and " << (obj.getIsSigned() ? "is signed":"is not signed");
    return (cout);
}
