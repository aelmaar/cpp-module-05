/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:47:49 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/11 10:15:05 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    // Grade during initialization is high
    std::cout << "-----Test1-----" << std::endl;
    try
    {
        Bureaucrat b1("Anouar", -1);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // Grade during initialization is low
    std::cout << "-----Test2-----" << std::endl;
    try
    {
        Bureaucrat b2("Malak", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // Grade is out of range
    std::cout << "-----Test3-----" << std::endl;
    try
    {
        Bureaucrat b1("Anouar", 1);
        std::cout << b1 << std::endl;
        b1.IncrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "-----Test4-----" << std::endl;
    try
    {
        Bureaucrat b1("Anouar", 150);
        std::cout << b1 << std::endl;
        b1.DecrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
