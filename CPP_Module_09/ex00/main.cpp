/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:34:14 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/28 14:08:52 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    
    if (argc != 2) {
        std::cerr << "Error: wrong number of arguments." << std::endl;
        return (1);
    }
    
    try {
        BitcoinExchange btc(argv[1]);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
