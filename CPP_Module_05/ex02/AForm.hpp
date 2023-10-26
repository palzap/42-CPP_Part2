/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:27:02 by pealexan          #+#    #+#             */
/*   Updated: 2023/10/26 15:26:16 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
	AForm();
	AForm(std::string name, int gradeSign, int gradeExec);
	AForm(const AForm &src);
	AForm &operator=(const AForm &src);
	~AForm();
	
	std::string getName() const;
	int getGradeSign() const;
	int getGradeExec() const;
	bool getSigned() const;
	
	void beSigned(Bureaucrat& bureaucrat);

	void execute(Bureaucrat const &executor) const;

	virtual void executeForm() const = 0;
	
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

std::ostream &operator<<(std::ostream &out, const AForm &src);

#endif