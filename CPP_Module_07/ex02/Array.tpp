/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:24:14 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/14 14:09:39 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

template <class T>
Array<T>::Array() : _n(0)
{
	this->_array = new T[this->_n];
}

template <class T>
Array<T>::Array(unsigned int n) : _n(n)
{
	this->_array = new T[this->_n];
	for (unsigned int i = 0; i < this->_n; i++)
	{
		this->_array[i] = T();
	}
}

template <class T>
Array<T>::Array(const Array &src) : _n(src._n)
{
	this->_array = new T[this->_n];
    for (unsigned int i = 0; i < src._n; i++)
        this->_array[i] = src._array[i];
}

template <class T>
Array<T> &Array<T>::operator=(const Array &src)
{
	if (this != &src)
    {
        delete[] this->_array;
        this->_n = src._n;
        this->_array = new T[this->_n];
        for (unsigned int i = 0; i < src._n; i++)
            this->_array[i] = src._array[i];
    }
    return (*this);
}

template <class T>
Array<T>::~Array()
{
	if (this->_array)
		delete[] this->_array;
}

template <class T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= this->_n)
		throw Array<T>::IndexOutOfBoundsException();
	return (this->_array[i]);
}

template <class T>
size_t Array<T>::size() const
{
	return (this->_n);
}

template <class T>
const char *Array<T>::IndexOutOfBoundsException::what() const throw()
{
	return ("Index out of bounds");
}

#endif