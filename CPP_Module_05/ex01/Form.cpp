/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:27:57 by pealexan          #+#    #+#             */
/*   Updated: 2023/10/26 12:52:14 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeSign(150), _gradeExec(150) {
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	if (gradeSign < 1 || gradeExec < 1)
		throw GradeTooHighException();
	if (gradeSign > 150 || gradeExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &src) : _name(src._name), _signed(src._signed), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec) {
}

Form &Form::operator=(const Form &src) {
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

Form::~Form() {
}

std::string Form::getName() const {
	return (this->_name);
}

int Form::getGradeSign() const {
	return (this->_gradeSign);
}

int Form::getGradeExec() const {
	return (this->_gradeExec);
}

bool Form::getSigned() const {
	return (this->_signed);
}

void Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->getGradeSign())
		throw GradeTooLowException();
	this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high.");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low.");
}

std::ostream &operator<<(std::ostream &out, const Form &src) {
	out << src.getName() << " is " << (src.getSigned() ? "signed" : "not signed") << " and requires a grade of " << src.getGradeSign() << " to sign and a grade of " << src.getGradeExec() << " to execute." << std::endl;
	return (out);
}