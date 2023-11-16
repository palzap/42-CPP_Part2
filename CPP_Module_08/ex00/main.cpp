/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:40:46 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/16 12:03:15 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void) {
    std::cout << "VECTOR" << std::endl;
    std::cout << std::endl;

    std::vector<int> vec;
    
    vec.push_back(42);
    vec.push_back(12);
    vec.push_back(27);
    vec.push_back(123);

    std::cout << "Vector values: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

	try {
		std::cout << "Looking for 42..." << std::endl;
		easyfind(vec, 42);
		std::cout << "Looking for 27..." << std::endl;
		easyfind(vec, 27);
		std::cout << "Looking for 123..." << std::endl;
		easyfind(vec, 123);
		std::cout << "Looking for 41..." << std::endl;
		easyfind(vec, 41);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
    
    std::cout << std::endl;
    std::cout << std::endl;
    
    std::cout << "LIST" << std::endl;
    std::cout << std::endl;

    std::list<int> lst;
    
	lst.push_back(42);
    lst.push_back(96);
    lst.push_back(72);
    lst.push_back(482);

    std::cout << "List values: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

	try {
		std::cout << "Looking for 42..." << std::endl;
		easyfind(lst, 42);
		std::cout << "Looking for 96..." << std::endl;
		easyfind(lst, 96);
		std::cout << "Looking for 78..." << std::endl;
		easyfind(lst, 78);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}