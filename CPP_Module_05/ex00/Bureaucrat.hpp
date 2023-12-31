/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:54:09 by pealexan          #+#    #+#             */
/*   Updated: 2023/10/26 11:23:18 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator=(const Bureaucrat &src);
	~Bureaucrat();
	
	std::string getName() const;
	int getGrade() const;
	
	void incrementGrade();
	void decrementGrade();

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
	int _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src);

#endif