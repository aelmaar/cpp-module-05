/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:26:21 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/12 17:43:35 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &old_obj): AForm(old_obj) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm(target, 25, 5) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned() && executor.getRange() > this->getGradeExec())
        throw ShrubberyCreationForm::GradeTooLowException();
    std::cout << "        _-_\n";
    std::cout << "       /   \\\n";
    std::cout << "      /     \\\n";
    std::cout << "     /       \\\n";
    std::cout << "    /         \\\n";
    std::cout << "   /           \\\n";
    std::cout << "   |   o   o   |\n";
    std::cout << "   |     |     |\n";
    std::cout << "   |    \\_/    |\n";
    std::cout << "   |   --|--   |\n";
    std::cout << "    \\         /\n";
    std::cout << "     \\       /\n";
    std::cout << "      \\     /\n";
    std::cout << "       \\   /\n";
    std::cout << "        \\_/\n";
}
