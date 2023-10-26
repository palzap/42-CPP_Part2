/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 13:03:15 by pealexan          #+#    #+#             */
/*   Updated: 2023/10/26 14:53:25 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    {
		Form form("Form0", 1, 1);
		Form form1("Form1", 150, 150);
		Form formCopy(form);
		Form formAssignOperator;
		Bureaucrat bureaucrat("Bureaucrat", 1);
		
		std::cout << "\t>>>COPY CONSTRUCTOR TESTS<<<\t" << std::endl;
		std::cout << form;
		std::cout << form1;
		std::cout << formCopy;
		std::cout << formAssignOperator;
		bureaucrat.signForm(form1);
		formAssignOperator = form1;
		std::cout << formAssignOperator;
		
		std::cout << "\t>>>COPIED CLASS ADDRESSES<<<\t" << std::endl;
		std::cout << &form << std::endl;
		std::cout << &form1 << std::endl;
		std::cout << &formCopy << std::endl;
		std::cout << &formAssignOperator << std::endl;
	}
	{
		std::cout << "\t>>>TESTS 2<<<\t" << std::endl;
		std::cout << "\t>>>CLASS CREATION<<<\t" << std::endl;
		Bureaucrat bureaucrat("Bureaucrat0", 1);
		Bureaucrat bureaucrat1("Bureaucrat1", 150);
		Form form("Form0", 150, 150);
		Form form1("Form1", 1, 1);

		std::cout << bureaucrat;
		std::cout << bureaucrat1;
		std::cout << form;
		std::cout << form1;
		
		std::cout << "\t>>>SIGNED TESTS<<<\t" << std::endl;
		bureaucrat.signForm(form);
		bureaucrat.signForm(form1);
		
		std::cout << form;
		std::cout << form1;

		std::cout << "\t>>>EXCEPTION TRY/CATCH TESTS<<<\t" << std::endl;

		try {
			Form form2("Form2", 100, 1000);
		} catch (std::exception& error) {
			std::cerr << error.what() << std::endl;
		}

		try {
			Form form3("Form3", 0, 100);
		} catch (std::exception& error) {
			std::cerr << error.what() << std::endl;
		}

		Form form2("Form2", 1, 1);
		Form form3 = form2;
		try {
			std::cout << form;
			bureaucrat1.signForm(form);
		} catch (std::exception& error) {
			std::cerr << error.what() << std::endl;
		}

		try {
			std::cout << form2;
			bureaucrat.signForm(form2);
			std::cout << form2;
			bureaucrat.decrementGrade();
			std::cout << form3;
			bureaucrat.signForm(form3);
		} catch (std::exception& error) {
			std::cerr << error.what() << std::endl;
		}
	}
}