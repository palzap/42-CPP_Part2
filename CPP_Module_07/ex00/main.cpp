/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:57:35 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/08 15:07:18 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main(void)
{

	int a = 2;
	int b = 3;

	std::cout << "ORIGINAL" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	::swap(a, b);
	std::cout << "SWAP" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "MIN" << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "MAX" << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::cout << std::endl;

	std::string c = "string1";
	std::string d = "string2";

	std::cout << "ORIGINAL" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	::swap(c, d);
	std::cout << "SWAP" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "MIN" << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "MAX" << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	return 0;
}