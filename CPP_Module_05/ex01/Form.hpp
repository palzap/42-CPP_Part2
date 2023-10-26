/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:27:02 by pealexan          #+#    #+#             */
/*   Updated: 2023/10/26 13:07:30 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form();
	Form(std::string name, int gradeSign, int gradeExec);
	Form(const Form &src);
	Form &operator=(const Form &src);
	~Form();
	
	std::string getName() const;
	int getGradeSign() const;
	int getGradeExec() const;
	bool getSigned() const;
	
	void beSigned(Bureaucrat& bureaucrat);
	
	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
	
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

private:
	std::string const _name;
	bool _signed;
	int const _gradeSign;
	int const _gradeExec;
};

std::ostream &operator<<(std::ostream &out, const Form &src);

#endif