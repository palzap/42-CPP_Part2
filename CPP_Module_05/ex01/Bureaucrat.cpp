/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:59:03 by pealexan          #+#    #+#             */
/*   Updated: 2023/10/26 12:59:57 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	this->_grade = grade;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	if (this != &src)
		this->_grade = src._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {
}

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade() {
	this->_grade--;
	if (this->_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	this->_grade++;
	if (this->_grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::signForm(Form& form) {
	if (form.getSigned())
		std::cout << this->getName() << " signed " << form.getName() << "." << std::endl;
	else {
		if (this->_grade <= form.getGradeSign())
			form.beSigned(*this);
		else {
			throw Form::GradeTooLowException();
		}
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src) {
	out << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return (out);
}
