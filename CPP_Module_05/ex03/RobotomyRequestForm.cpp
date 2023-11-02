/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:36:14 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/02 11:18:59 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::executeForm() const {
    std::srand(std::time(0));
	int randomValue = std::rand();

    if (randomValue % 2 == 0) {
        std::cout << this->_target << " -> Successfully robotomized!" << std::endl;
    }
	else {
		std::cout << this->_target << " -> Robotomy failed!" << std::endl;
	}
}