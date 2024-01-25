/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:15:20 by pealexan          #+#    #+#             */
/*   Updated: 2024/01/25 15:17:16 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ReversePolishNotation.hpp"

int main(int argc, char** argv)
{
	if (argc != 2) {
        std::cerr << "Error: wrong number of arguments." << std::endl;
        return (1);
    }

	try
	{
		ReversePolishNotation calculate(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}