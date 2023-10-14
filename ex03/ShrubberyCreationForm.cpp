/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:26:21 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/13 17:51:46 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Unknown", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &old_obj): AForm(old_obj) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target): AForm(target, 145, 137) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    std::fstream ascii_tree;

    if (!this->getIsSigned() || executor.getRange() > this->getGradeExec())
        throw ShrubberyCreationForm::GradeTooLowException();
    ascii_tree.open(this->getName()+"_shrubbery", std::fstream::out | std::fstream::trunc | std::fstream::in);
    if (!ascii_tree.is_open())
        throw ShrubberyCreationForm::FilePermissionDenied();
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

// Implementation of the FilePermissionDenied exception class if the file doesn't have permissions (read, write)
const char *ShrubberyCreationForm::FilePermissionDenied::what() const throw() {
    return "File doesn't have permissions for read or write";
}