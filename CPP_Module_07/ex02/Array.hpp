/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:23:36 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/14 14:09:48 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>
class Array
{
private:
	T *_array;
	unsigned int _n;

public:
	Array();
	Array(unsigned int n);
	Array(const Array &original);
	Array &operator=(const Array &original);
	~Array();

	T &operator[](unsigned int i);

	size_t size() const;

	class IndexOutOfBoundsException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#include "Array.tpp"

#endif
