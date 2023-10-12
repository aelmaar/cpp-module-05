/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:26:21 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/12 19:36:24 by ael-maar         ###   ########.fr       */
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
    std::fstream ascii_tree;

    if (!this->getIsSigned() && executor.getRange() > this->getGradeExec())
        throw ShrubberyCreationForm::GradeTooLowException();
    ascii_tree.open(this->getName()+"_shrubbery", std::fstream::out | std::fstream::trunc | std::fstream::in);
    if (!ascii_tree.is_open())
        throw ShrubberyCreationForm::FilePermissionDenied(this->getName() + "_shrubbery");
    ascii_tree << "        _-_\n";
    ascii_tree << "       /   \\\n";
    ascii_tree << "      /     \\\n";
    ascii_tree << "     /       \\\n";
    ascii_tree << "    /         \\\n";
    ascii_tree << "   /           \\\n";
    ascii_tree << "   |   o   o   |\n";
    ascii_tree << "   |     |     |\n";
    ascii_tree << "   |    \\_/    |\n";
    ascii_tree << "   |   --|--   |\n";
    ascii_tree << "    \\         /\n";
    ascii_tree << "     \\       /\n";
    ascii_tree << "      \\     /\n";
    ascii_tree << "       \\   /\n";
    ascii_tree << "        \\_/\n";
    ascii_tree.close();
}

ShrubberyCreationForm::FilePermissionDenied::FilePermissionDenied(std::string const &file): file(file) {}

const char *ShrubberyCreationForm::FilePermissionDenied::what() const throw() {
    std::string message = this->file + ": " + strerror(errno);

    return (message.c_str());
}
