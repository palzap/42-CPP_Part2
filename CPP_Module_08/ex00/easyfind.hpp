/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:03:41 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/16 11:59:32 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class NotFoundException : public std::exception {
    public:
        virtual const char *what() const throw() {
            return ("Exception: Not found.");
        }
};

template <typename T>
void easyfind(const T& container, int n) {
    if (std::find(container.begin(), container.end(), n) != container.end())
        std::cout << n << " found." << std::endl;
    else
        throw NotFoundException();
}

#endif