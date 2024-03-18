/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pealexan <pealexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:33:45 by pealexan          #+#    #+#             */
/*   Updated: 2024/03/18 15:37:38 by pealexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& original) : _vec(original._vec), _deq(original._deq) {}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe& original) {
    if (this != &original) {
        this->_vec = original._vec;
        this->_deq = original._deq;
    }
    return (*this);
}

PmergeMe::PmergeMe(std::vector<int> vec) : _vec(vec), _deq(vec.begin(), vec.end()) {
    Sort(this->_vec);
}

void PmergeMe::Sort(std::vector<int>& vec) {
    std::cout << "Before: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

    // MergeSort time in milliseconds for std::vector
    clock_t vecStart = clock();

    mergeSortVec(this->_vec, 0, this->_vec.size() - 1);

    clock_t vecEnd = clock();
    double elapsed_time_vec = static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000;
    
    // MergeSort time in milliseconds for std::deque
    clock_t deqStart = clock();

    mergeSortDeq(this->_deq, 0, this->_deq.size() - 1);

    clock_t deqEnd = clock();
    double elapsed_time_deq = static_cast<double>(deqEnd - deqStart) / CLOCKS_PER_SEC * 1000;

	// Print the sorted vector
    std::cout << "(Vec) After: ";
	for (std::vector<int>::iterator it = this->_vec.begin(); it != this->_vec.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Print the sorted deque
    std::cout << "(Deq) After: ";
	for (std::deque<int>::iterator it = this->_deq.begin(); it != this->_deq.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Print final results
    std::cout << "Processed " << this->_vec.size() << " elements with std::vector in: " << elapsed_time_vec << " milliseconds" << std::endl;
    std::cout << "Processed " << this->_deq.size() << " elements with std::deque in: " << elapsed_time_deq << " milliseconds" << std::endl;
}

void PmergeMe::mergeSortVec(std::vector<int>& vec, int min, int max) {
    if (min >= max) return;

    int middle = min + (max - min) / 2;

    mergeSortVec(vec, min, middle);
    mergeSortVec(vec, middle + 1, max);
    mergeVec(vec, min, middle, max);
}

void PmergeMe::mergeVec(std::vector<int>& vec, int min, int mid, int max) {
    std::vector<int> temp(max - min + 1);
    int i = min, j = mid + 1, k = 0;

    while (i <= mid && j <= max) {
        if (vec[i] <= vec[j]) {
            temp[k++] = vec[i++];
        } else {
            temp[k++] = vec[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = vec[i++];
    }

    while (j <= max) {
        temp[k++] = vec[j++];
    }

    for (i = min, k = 0; i <= max; ++i, ++k) {
        vec[i] = temp[k];
    }
}

void PmergeMe::mergeSortDeq(std::deque<int>& deq, int min, int max) {
    if (min >= max) return;

    int middle = min + (max - min) / 2;

    mergeSortDeq(deq, min, middle);
    mergeSortDeq(deq, middle + 1, max);
    mergeDeq(deq, min, middle, max);
}

void PmergeMe::mergeDeq(std::deque<int>& deq, int min, int mid, int max) {
    std::deque<int> left(deq.begin() + min, deq.begin() + mid + 1);
    std::deque<int> right(deq.begin() + mid + 1, deq.begin() + max + 1);
    
    int	k = min;
    
    while (!left.empty() && !right.empty()) {
        if (left.front() <= right.front()) {
            deq[k++] = left.front();
            left.pop_front();
        } else {
            deq[k++] = right.front();
            right.pop_front();
        }
    }
    
    while (!left.empty()) {
        deq[k++] = left.front();
        left.pop_front();
    }
    
    while (!right.empty()) {
        deq[k++] = right.front();
        right.pop_front();
    }
}
