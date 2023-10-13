/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:43:32 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/13 15:12:42 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    std::string const name;
    bool is_signed;
    int const grade_sign;
    int const grade_exec;
    public:
        Form();
        Form(Form const &old_obj);
        Form(std::string const &name, int const grade_sign, int const grade_exec);
        Form &operator=(Form const &other);
        ~Form();
        class GradeTooHighException;
        class GradeTooLowException;
        std::string const &getName() const;
        bool getIsSigned() const;
        int getGradeSign() const;
        int getGradeExec() const;
        void beSigned(Bureaucrat const &bureaucrat);
};

std::ostream &operator<< (std::ostream &out, Form const &obj);

class Form::GradeTooHighException: public std::exception {
    public:
        const char *what() const throw();
};

class Form::GradeTooLowException: public std::exception {
    public:
        const char *what() const throw();
};

#endif
