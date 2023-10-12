/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:43:32 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/12 16:53:47 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class AForm
{
    std::string const name;
    bool is_signed;
    int const grade_sign;
    int const grade_exec;
    public:
        AForm();
        AForm(AForm const &old_obj);
        AForm(std::string const &name, int const grade_sign, int const grade_exec);
        AForm &operator=(AForm const &other);
        ~AForm();
        class GradeTooHighException;
        class GradeTooLowException;
        std::string const &getName() const;
        bool const getIsSigned() const;
        int const getGradeSign() const;
        int const getGradeExec() const;
        void beSigned(Bureaucrat const &bureaucrat);
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<< (std::ostream &out, AForm const &obj);

class AForm::GradeTooHighException: public std::exception{
    public:
        const char *what() const throw();
};

class AForm::GradeTooLowException: public std::exception{
    public:
        const char *what() const throw();
};

#endif
