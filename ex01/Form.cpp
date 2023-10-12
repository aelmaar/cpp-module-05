/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:43:35 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/12 17:06:06 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("Unknown"), is_signed(false), grade_sign(10), grade_exec(10) {}

Form::Form(std::string const &name, int const grade_sign, int const grade_exec): name(name), is_signed(false), grade_sign(grade_sign), grade_exec(grade_exec) {
    if (grade_sign < 1 || grade_exec < 1)
        throw Form::GradeTooHighException();
    if (grade_sign > 150 || grade_exec > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &old_obj): name(old_obj.name), is_signed(old_obj.is_signed), grade_sign(old_obj.grade_sign), grade_exec(old_obj.grade_exec) {}

Form &Form::operator=(Form const &other) {
    if (this != &other)
        this->is_signed = other.is_signed;
    return (*this);
}

Form::~Form() {}

std::string const &Form::getName() const { return (name); }

bool const Form::getIsSigned() const { return (is_signed); }

int const Form::getGradeSign() const { return (grade_sign); }

int const Form::getGradeExec() const { return (grade_exec); }

void Form::beSigned(Bureaucrat const &bureaucrat) {
    if (bureaucrat.getRange() > grade_sign)
        throw Form::GradeTooLowException();
    else
        is_signed = true;
}

std::ostream &operator<< (std::ostream &cout, Form const &obj) {
    cout << obj.getName();
    cout << " with grade sign: " << obj.getGradeSign() << ", grade execution: " << obj.getGradeExec();
    cout << " and " << obj.getIsSigned() ? "is signed":"is not signed";
    return (cout);
}
