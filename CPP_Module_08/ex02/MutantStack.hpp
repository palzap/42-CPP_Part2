/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutatedStack.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:38:34 by pealexan          #+#    #+#             */
/*   Updated: 2023/11/23 10:39:09 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
    private:

    public:
        MutantStack();
        MutantStack(const MutantStack& original);
        MutantStack& operator=(const MutantStack& original);
        ~MutantStack();

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin(void);
        iterator end(void);
};

#include "MutantStack.tpp"

#endif