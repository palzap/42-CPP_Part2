/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:06:37 by diogmart          #+#    #+#             */
/*   Updated: 2023/11/02 12:40:22 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>


int main(void)
{
	std::cout << "\t======|ShrubberyCreationForm|======" << std::endl;
	std::cout << "\tRequired grades: sign 145, exec 137" << std::endl;

	Bureaucrat bur11("bur11", 1);
	Bureaucrat bur12("bur12", 140);
	Bureaucrat bur13("bur13", 150);

	ShrubberyCreationForm a("form");
	ShrubberyCreationForm a2("cenas");

	std::cout << "\n\t======|Form not signed|======" << std::endl;
	try {
		std::cout << a;
		a.execute(bur11);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\t======|Grade to low to sign|======" << std::endl;
	try {
		std::cout << bur13;
		std::cout << a;
		bur13.signForm(a);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\t======|Grade to low to execute|======" << std::endl;
	try {
		std::cout << bur12;
		std::cout << a;
		bur12.signForm(a);
		bur12.executeForm(a);
		a.execute(bur12);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\t======|Working|======" << std::endl;
	try {
		std::cout << bur11;
		a.execute(bur11);
		bur11.signForm(a2);
		bur11.executeForm(a2);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n\t======|RobotomyRequestForm|======" << std::endl;
	std::cout << "\tRequired grades: sign 72, exec 45" << std::endl;

	Bureaucrat bur21("bur21", 1);
	Bureaucrat bur22("bur22", 70);
	Bureaucrat bur23("bur23", 100);

	RobotomyRequestForm b("Target1");
	RobotomyRequestForm b2("Target2");

	std::cout << "\n\t======|Form not signed|======" << std::endl;
	try {
		std::cout << b;
		b.execute(bur21);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\t======|Grade to low to sign|======" << std::endl;
	try {
		std::cout << bur23;
		std::cout << b;
		bur23.signForm(b);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\t======|Grade to low to execute|======" << std::endl;
	try {
		std::cout << bur22;
		std::cout << b;
		bur22.signForm(b);
		bur22.executeForm(b);
		b.execute(bur22);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\t======|Working|======" << std::endl;
	try {
		std::cout << bur21;
		b.execute(bur21);
		bur21.signForm(b2);
		bur21.executeForm(b2);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\n\t======|PresidentialPardonForm|======" << std::endl;
	std::cout << "\tRequired grades: sign 25, exec 5" << std::endl;

	Bureaucrat bur31("bur31", 1);
	Bureaucrat bur32("bur32", 20);
	Bureaucrat bur33("bur33", 30);

	PresidentialPardonForm c("Target2");
	PresidentialPardonForm c2("Target3");

	std::cout << "\n\t======|Form not signed|======" << std::endl;
	try {
		std::cout << c;
		c.execute(bur31);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\t======|Grade to low to sign|======" << std::endl;
	try {
		std::cout << bur33;
		std::cout << c;
		bur33.signForm(c);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\t======|Grade to low to execute|======" << std::endl;
	try {
		std::cout << bur32;
		std::cout << c;
		bur32.signForm(c);
		bur32.executeForm(c);
		c.execute(bur32);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n\t======|Working|======" << std::endl;
	try {
		std::cout << bur31;
		c.execute(bur31);
		bur31.signForm(c2);
		bur31.executeForm(c2);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
