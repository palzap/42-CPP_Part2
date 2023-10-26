/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:04:52 by pealexan          #+#    #+#             */
/*   Updated: 2023/10/26 11:06:49 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    {
		Bureaucrat cenas("cenas1", 1);
		Bureaucrat cenas2(cenas);
		Bureaucrat cenas3("coiso", 150);
		
		std::cout << "\t>>>COPY CONSTRUCTOR TESTS<<<\t" << std::endl;
		std::cout << cenas;
		std::cout << cenas2;
		std::cout << cenas3;
		cenas3 = cenas;
		std::cout << cenas3;
		
		std::cout << "\t>>>COPIED CLASS ADDRESSES<<<\t" << std::endl;
		std::cout << &cenas << std::endl;
		std::cout << &cenas2 << std::endl;
		std::cout << &cenas3 << std::endl;
	}
	{
		std::cout << "\t>>>CLASS CREATION TESTS<<<\t" << std::endl;	
		Bureaucrat test;
		Bureaucrat test1("Test", 150);
		Bureaucrat test2(test1);
		Bureaucrat test3("Test3", 1);

		std::cout << test;
		std::cout << test1;
		std::cout << test2;
		std::cout << test3;
		test = test1;
		std::cout << test;
		
		std::cout << "\t>>>INCREMENT/DECREMENT TESTS<<<\t" << std::endl;
		test.incrementGrade();
		test1.incrementGrade();
		//test3.incrementGrade();
		test3.decrementGrade();
		
		std::cout << test;
		std::cout << test1;
		std::cout << test3;
		test3.decrementGrade();
		std::cout << test3;

		std::cout << "\t>>>EXCEPTION TRY/CATCH TESTS<<<\t" << std::endl;

		try {
			Bureaucrat test4("test4", 300);
		}
		catch (std::exception& error) {
			std::cerr << error.what() << std::endl;
		}

		try {
			Bureaucrat test5("test5", 0);
		}
		catch (std::exception& error) {
			std::cerr << error.what() << std::endl;
		}

		try {
			test1.decrementGrade();
			std::cout << test1;
			test1.decrementGrade();
		}
		catch (std::exception& error) {
			std::cerr << error.what() << std::endl;
		}

		try {
			test3.incrementGrade();
			std::cout << test3;
			test3.incrementGrade();
			std::cout << test3;
			test3.incrementGrade();
			std::cout << test3;
			test3.incrementGrade();
		}
		catch (std::exception& error) {
			std::cerr << error.what() << std::endl;
		}
	}
}