/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:29:57 by pealexan          #+#    #+#             */
/*   Updated: 2024/03/18 15:57:34 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {

	if (argc < 3) {
		std::cerr << "Error: wrong number of arguments." << std::endl;
		return (1);
	}

	for(int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j] != '\0'; j++) {
			if (!isdigit(argv[i][j])) {
				std::cerr << "Error: all arguments must be positive integers." << std::endl;
				return (-1);
			}
		}
	}
	
	// Push values to a vector
	std::vector<int> numbers;
	for (int i = 1; i < argc; i++) {
		numbers.push_back(atoi(argv[i]));
	}
	PmergeMe PmergeMe(numbers);
}