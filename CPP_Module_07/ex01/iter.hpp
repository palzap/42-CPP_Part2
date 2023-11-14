/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:08:32 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/14 10:17:50 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*f)(T &))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
void print(T &x)
{
	std::cout << x <<  " | ";
}

template <typename T>
void increment(T &x)
{
	x++;
	std::cout << x << " | ";
}

#endif