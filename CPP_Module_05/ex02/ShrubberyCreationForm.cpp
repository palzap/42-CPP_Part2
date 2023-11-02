/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:15:13 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/02 11:22:37 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target) {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::executeForm() const {
	std::ofstream outfile;
	
	outfile.open((this->_target + "_shrubbery").c_str());
	if (outfile.is_open()) {
		outfile << "	            ,@@@@@@@,					    \n";
		outfile << "       ,,,.   ,@@@@@@/@@,  .oo8888o.			\n";
		outfile << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o			\n";
		outfile << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'		\n";
		outfile << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'		\n";
		outfile << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'			\n";
		outfile << "   `&%\\ ` /%&'    |.|        \\ '|8'			\n";
		outfile << "	    |o|        | |         | |				\n";
		outfile << "		 |.|        | |         | |				\n";
		outfile << "	  \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_	\n";
		outfile.close();
	}
}