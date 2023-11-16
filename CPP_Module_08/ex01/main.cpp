/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:03:23 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/16 15:27:30 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		Span a(5);

		try
		{
			a.addNumber(std::numeric_limits<int>::max());
			a.addNumber(std::numeric_limits<int>::min());
			a.addNumber(-17);
			a.addNumber(-9);
			a.addNumber(-25);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		a.printNumbers();
		std::cout << std::endl;
		try
		{
			std::cout << "Shortest Span" << std::endl;
			std::cout << a.shortestSpan() << std::endl;
			std::cout << "Longest Span" << std::endl;
			std::cout << a.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		Span b(1);

		try
		{
			b.addNumber(-5);
			b.addNumber(-3);
			b.addNumber(-17);
			b.addNumber(-9);
			b.addNumber(-25);
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		b.printNumbers();
		std::cout << std::endl;
		try
		{
			std::cout << "Shortest Span" << std::endl;
			std::cout << b.shortestSpan() << std::endl;
			std::cout << "Longest Span" << std::endl;
			std::cout << b.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else if (argc == 2)
	{
		int number = std::atoi(argv[1]);

		if (number <= 0 || number > 15000)
		{
			std::cout << "0 or negative elements or max number of elements is 15000" << std::endl;
			return (0);
		}

		Span a(number);

		a.generateNumbers(number);
		a.printNumbers();
		try
		{
			std::cout << "Shortest Span" << std::endl;
			std::cout << a.shortestSpan() << std::endl;
			std::cout << "Longest Span" << std::endl;
			std::cout << a.longestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cout << "Wrong number of arguments" << std::endl;
}