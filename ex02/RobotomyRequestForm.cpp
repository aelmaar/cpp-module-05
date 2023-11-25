/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-maar <ael-maar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:26:16 by ael-maar          #+#    #+#             */
/*   Updated: 2023/10/13 17:00:10 by ael-maar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Unknown", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &old_obj): AForm(old_obj) {}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm(target, 72, 45) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
    if (this != &other)
        AForm::operator=(other);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (executor.getRange() > this->getGradeExec())
        throw RobotomyRequestForm::GradeTooLowException();
    if (!this->getIsSigned())
        throw RobotomyRequestForm::NotSignedException();
    std::srand(std::time(NULL));
    int random = rand() % 2;
    std::cout << "random" << random << std::endl;
    if (random % 2)
        std::cout << this->getName() << " has been robotomized successfully 50%% of the time" << std::endl;
    else
        std::cout << "Robotomy failed" << std::endl;
}
