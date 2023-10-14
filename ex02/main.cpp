/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:47:49 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/14 14:05:34 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    std::cout << "-----Test1-----" << std::endl;
    try
    {
        Bureaucrat bureaucrat("Anouar", 138);
        AForm *shrubbery = new ShrubberyCreationForm("Home");

        shrubbery->beSigned(bureaucrat);
        bureaucrat.executeForm(*shrubbery);

        delete shrubbery;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----Test2-----" << std::endl;
    try
    {
        Bureaucrat bureaucrat("Anouar", 136);
        AForm *shrubbery = new ShrubberyCreationForm("Home");

        bureaucrat.executeForm(*shrubbery);

        delete shrubbery;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----Test3-----" << std::endl;
    try
    {
        Bureaucrat bureaucrat("Anouar", 4);
        AForm *shrubbery = new ShrubberyCreationForm("Home");
        AForm *robotomy = new RobotomyRequestForm("Robot");
        AForm *president = new PresidentialPardonForm("Omar");

        shrubbery->beSigned(bureaucrat);
        bureaucrat.executeForm(*shrubbery);
        robotomy->beSigned(bureaucrat);
        bureaucrat.executeForm(*robotomy);
        president->beSigned(bureaucrat);
        bureaucrat.executeForm(*president);

        delete shrubbery;
        delete robotomy;
        delete president;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
