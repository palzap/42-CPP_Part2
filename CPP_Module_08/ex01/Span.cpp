/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:03:27 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/16 15:29:45 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0)
{
}

Span::Span(unsigned int N) : _N(N)
{
}

Span::Span(const Span &src) : _N(src._N), _vector(src._vector)
{
	this->_vector.clear();
}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		this->_N = src._N;
		this->_vector.clear();
		std::copy(src._vector.begin(), src._vector.end(), this->_vector.begin());
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (this->_vector.size() >= this->_N)
		throw FullException();
	this->_vector.push_back(n);
}

unsigned int Span::shortestSpan()
{
	if (this->_N < 2)
		throw Span::NotEnoughElementsException();
	std::sort(this->_vector.begin(), this->_vector.end());
	unsigned int min = std::numeric_limits<unsigned int>::max();
	for (size_t i = 1; i < this->_vector.size(); ++i)
	{
		unsigned int span = this->_vector[i] - this->_vector[i - 1];
		min = std::min(min, span);
	}
	return (min);
}

unsigned int Span::longestSpan()
{
	if (this->_N < 2)
		throw Span::NotEnoughElementsException();
	int min = *(std::min_element(this->_vector.begin(), this->_vector.end()));
	int max = *(std::max_element(this->_vector.begin(), this->_vector.end()));
	std::cout << "min: " << min << " max: " << max << std::endl;
	return (max - min);
}

void Span::generateNumbers(unsigned int N)
{
	std::srand(std::time(NULL));
	std::vector<int> newNumbers;
	for (unsigned int i = 0; i < N; i++)
		newNumbers.push_back(rand());
	this->addMultipleNumbers(newNumbers);
	return;
}

void Span::printNumbers()
{
	for (std::vector<int>::iterator it = this->_vector.begin(); it != this->_vector.end(); ++it)
		std::cout << *it << " | ";
	std::cout << std::endl;
}

void Span::addMultipleNumbers(std::vector<int> &newNumbers)
{
	if (this->_vector.size() + newNumbers.size() > this->_N)
		throw FullException();
	this->_vector.insert(this->_vector.end(), newNumbers.begin(), newNumbers.end());
}

const char *Span::FullException::what() const throw()
{
	return ("Can't add more numbers!");
}

const char *Span::NotEnoughElementsException::what() const throw()
{
	return ("Not enough elements!");
}
