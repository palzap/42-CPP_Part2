/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:30:19 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/02 15:15:28 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern () {
}

Intern::Intern (const Intern& src) {
    (void)src;
}

Intern::~Intern() {
}

Intern &Intern::operator=(const Intern& src) {
    (void)src;
    return (*this);
}

AForm *Intern::makeShrubberyCreation(const std::string& target) {
    std::cout << "Intern creates ShrubberyCreationForm." << std::endl;
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequest(const std::string& target) {
    std::cout << "Intern creates RobotomyRequestForm." << std::endl;
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardon(const std::string& target) {
    std::cout << "Intern creates PresidentialPardonForm." << std::endl;
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string& name, const std::string& target) {
    const std::string forms[3] = {
        "ShrubberyCreationForm",
        "RobotomyRequestForm",
        "PresidentialPardonForm"
    };

    AForm *(Intern::*constructors[3])(const std::string&) = {
        &Intern::makeShrubberyCreation,
        &Intern::makeRobotomyRequest,
        &Intern::makePresidentialPardon
    };

    for (int i = 0; i < 4; i++) {
        if (forms[i] == name)
            return ((this->*constructors[i])(target));
    }
    std::cout << "Intern couldn't find form!" << std::endl;
    return (NULL);
}