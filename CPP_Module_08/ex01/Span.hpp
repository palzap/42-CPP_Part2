/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:03:25 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/16 15:29:37 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <limits>

class Span
{
private:
	unsigned int _N;
	std::vector<int> _vector;

public:
	Span();
	Span(unsigned int N);
	Span(const Span &src);
	Span &operator=(const Span &src);
	~Span();

	void addNumber(int n);
	void generateNumbers(unsigned int N);
	void addMultipleNumbers(std::vector<int> &newNumbers);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	void printNumbers();

	class FullException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class NotEnoughElementsException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif