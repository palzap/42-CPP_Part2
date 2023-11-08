/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:25:26 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/08 11:34:16 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data = {"This is the string", 42};

	std::cout << "Data address: " << &data << std::endl;
	std::cout << "Data string content: " << data.string << std::endl;
	std::cout << "Data number content: " << data.number << std::endl;

	uintptr_t ptr = Serializer::serialize(&data);
	std::cout << "Serialized uint: " << ptr << std::endl;
	std::cout << "Serialized address: " << &ptr << std::endl;
	std::cout << "Deserialized address: " << Serializer::deserialize(ptr) << std::endl;
}