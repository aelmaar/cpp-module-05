/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:47:49 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/14 12:17:32 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void)
{
    {
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        delete rrf;
        rrf = someRandomIntern.makeForm("shrubbery", "Home");
        delete rrf;
        rrf = someRandomIntern.makeForm("presidential pardon", "President");
        delete rrf;
        rrf = someRandomIntern.makeForm("Nothing", "President");
        delete rrf;
    }
}
