/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:47:49 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/13 15:42:58 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void)
{
    std::cout << "-----Test1-----" << std::endl;
    try
    {
        Form form("Anouar", 100, 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----Test2-----" << std::endl;
    try
    {
        Bureaucrat bureaucrat("Anouar", 141);
        Form form("Urgence", 100, 150);
        form.beSigned(bureaucrat);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----Test3-----" << std::endl;
    try
    {
        Bureaucrat bureaucrat("Anouar", 50);
        Form form("Urgence", 100, 150);
        form.beSigned(bureaucrat);
        bureaucrat.signForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----Test4-----" << std::endl;
    try
    {
        Bureaucrat bureaucrat("Anouar", 50);
        Form form("Urgence", 100, 150);
        bureaucrat.signForm(form);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
