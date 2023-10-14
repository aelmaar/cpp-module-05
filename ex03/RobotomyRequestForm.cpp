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
    if (!this->getIsSigned() || executor.getRange() > this->getGradeExec())
    {
        std::cout << "Robotomy failed" << std::endl;
        throw RobotomyRequestForm::GradeTooLowException();
    }
    std::cout << this->getName() << " has been robotomized successfully 50%% of the time" << std::endl;
}
