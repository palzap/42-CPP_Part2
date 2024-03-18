/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:33:51 by pealexan          #+#    #+#             */
/*   Updated: 2024/03/18 15:33:52 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
#include <cstdlib>

class PmergeMe {

	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
		void mergeVec(std::vector<int>& vec, int min, int middle, int max);
		void mergeDeq(std::deque<int>& deq, int min, int middle, int max);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& original);
		~PmergeMe();
		PmergeMe &operator=(const PmergeMe& original);

		PmergeMe(std::vector<int> vec);

		void Sort(std::vector<int>& vec);

		void mergeSortVec(std::vector<int>& vec, int min, int max);
		void mergeSortDeq(std::deque<int>& deq, int min, int max);
};