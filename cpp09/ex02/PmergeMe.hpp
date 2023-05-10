/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:04:12 by jsauvain          #+#    #+#             */
/*   Updated: 2023/05/10 15:13:07 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <sys/time.h>

//VECTOR
std::vector<int>	mergeSortVec(std::vector<int> sequence, std::vector<int> firstHalf,	\
						std::vector<int> secondHalf);
std::vector<int>	insertionSortVec(std::vector<int> half);
std::vector<int>	mergeInsertSortVec(std::vector<int> sequence);

//DEQUE
std::deque<int>	mergeSortDeque(std::deque<int> sequence, std::deque<int> firstHalf,	\
					std::deque<int> secondHalf);
std::deque<int>	insertionSortDeque(std::deque<int> half);
std::deque<int>	mergeInsertSortDeque(std::deque<int> sequence);

#endif
