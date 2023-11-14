/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:24:11 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/14 14:16:41 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"
#include <iostream>

int main()
{
    std::cout << "INT ARRAY" << std::endl;
    Array<int> arr1(10);
    Array<int> arr2;

    arr2 = arr1;

    std::cout << arr1.size() << std::endl;
    std::cout << arr2.size() << std::endl;
    
    for (unsigned int i = 0; i < arr1.size(); i++)
        arr1[i] = i+1;

    std::cout << arr1[0] << std::endl;
	
	for (unsigned int i = 0; i < arr1.size(); i++)
        std::cout << arr1[i] << " ";
    std::cout << std::endl;

    for (unsigned int i = 0; i < arr2.size(); i++)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;

	std::cout << std::endl;
    std::cout << "CHAR ARRAY" << std::endl;
    Array<char> arr3(5);
   
    Array<char> arr4(arr3);

    std::cout << arr3.size() << std::endl;
    std::cout << arr4.size() << std::endl;
    
    for (unsigned int i = 0; i < arr3.size(); i++)
        arr3[i] = 'A' + i;
    std::cout << std::endl;

    for (unsigned int i = 0; i < arr3.size(); i++)
        std::cout << arr3[i] << " ";
    std::cout << std::endl;

    for (unsigned int i = 0; i < arr4.size(); i++)
        std::cout << arr4[i] << " ";
    std::cout << std::endl;

	std::cout << std::endl;
    std::cout << "EXCEPTIONS" << std::endl;

    try {
        arr1[20];
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        arr3[50];
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}