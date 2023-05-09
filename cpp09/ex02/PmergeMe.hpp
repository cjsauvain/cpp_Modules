/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:04:12 by jsauvain          #+#    #+#             */
/*   Updated: 2023/05/09 17:17:35 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>

std::vector<int>	mergeSort(std::vector<int> sequence, std::vector<int> firstHalf,	\
						std::vector<int> secondHalf);
std::vector<int>	insertionSort(std::vector<int> half);
std::vector<int>	mergeInsertSort(std::vector<int> sequence);

#endif
