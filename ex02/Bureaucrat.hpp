/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:47:14 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/12 16:23:35 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"

class Bureaucrat
{
    std::string const name;
    int range;
    public:
        Bureaucrat();
        Bureaucrat(Bureaucrat const &old_obj);
        Bureaucrat(std::string const &name, int range);
        Bureaucrat &operator=(Bureaucrat const &other);
        ~Bureaucrat();
        class GradeTooHighException;
        class GradeTooLowException;
        const std::string &getName() const;
        int getRange() const;
        void    IncrementGrade();
        void    DecrementGrade();
        void    signForm(AForm const &form);
};

std::ostream &operator<< (std::ostream &out, Bureaucrat const &obj);

class Bureaucrat::GradeTooHighException: public std::exception{
    public:
        const char *what() const throw();
};

class Bureaucrat::GradeTooLowException: public std::exception{
    public:
        const char *what() const throw();
};

#endif
