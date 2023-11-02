/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:06:37 by diogmart          #+#    #+#             */
/*   Updated: 2023/11/02 14:58:59 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main(void) {
    
    Intern intern0;
	Bureaucrat bureaucrat0("Bureaucrat0", 1);
    
    AForm* shrubberyCreationForm;
    
    shrubberyCreationForm = intern0.makeForm("ShrubberyCreationForm", "Target1");
    std::cout << *shrubberyCreationForm;
	bureaucrat0.signForm(*shrubberyCreationForm);
	bureaucrat0.executeForm(*shrubberyCreationForm);
	std::cout << std::endl;

    AForm* robotomyRequestForm;
    robotomyRequestForm = intern0.makeForm("RobotomyRequestForm", "Target2");
    std::cout << *robotomyRequestForm;
	bureaucrat0.signForm(*robotomyRequestForm);
	bureaucrat0.executeForm(*robotomyRequestForm);
	std::cout << std::endl;
    
    AForm* presidentialPardonForm;
    presidentialPardonForm = intern0.makeForm("PresidentialPardonForm", "Target3");
    std::cout << *presidentialPardonForm;
	bureaucrat0.signForm(*presidentialPardonForm);
	bureaucrat0.executeForm(*presidentialPardonForm);
	std::cout << std::endl;
	
	AForm* unknownForm;
	unknownForm = intern0.makeForm("UnknownForm", "Target4");
}
