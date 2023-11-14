/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:08:30 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/14 10:26:12 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	std::cout << "INT ARRAY" << std::endl;
	int iarray[] = {42, -42, 27, 345, -123456};
	::iter(iarray, 5, ::print);
	std::cout << std::endl;
	::iter(iarray, 5, ::increment);

	std::cout << std::endl;

	std::cout << "FLOAT ARRAY" << std::endl;
	float farray[] = {42.42, -42, 27.12, 34.5, -123.456, 0.98};
	::iter(farray, 6, ::print);
	std::cout << std::endl;
	::iter(farray, 6, ::increment);

	std::cout << std::endl;

	std::cout << "CHAR ARRAY" << std::endl;
	char carray[] = {'a', 'b', '4', '2'};
	::iter(carray, 4, ::print);
	std::cout << std::endl;
	::iter(carray, 4, ::increment);
}