/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:52:38 by jsauvain          #+#    #+#             */
/*   Updated: 2023/05/09 18:12:51 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	mergeSort(std::vector<int> sequence, std::vector<int> firstHalf,	\
	std::vector<int> secondHalf)
{
	if (!firstHalf.empty() && !secondHalf.empty()
		&& firstHalf.front() <= secondHalf.front())
	{
		sequence.push_back(firstHalf.front());
		firstHalf.erase(firstHalf.begin());
	}
	else if (!firstHalf.empty() && !secondHalf.empty()
		&& firstHalf.front() >= secondHalf.front())
	{
		sequence.push_back(secondHalf.front());
		secondHalf.erase(secondHalf.begin());
	}
	else if (!firstHalf.empty() && secondHalf.empty())
	{
		sequence.push_back(firstHalf.front());
		firstHalf.erase(firstHalf.begin());
	}
	else if (firstHalf.empty() && !secondHalf.empty())
	{
		sequence.push_back(secondHalf.front());
		secondHalf.erase(secondHalf.begin());
	}
	if (!firstHalf.empty() || !secondHalf.empty())
		sequence = mergeSort(sequence, firstHalf, secondHalf);
	return (sequence);
}

std::vector<int>	insertionSort(std::vector<int> half)
{
	int		tmp;
	size_t	i = 0;

	while (i < half.size() - 1)
	{
		if (half[i] > half[i + 1])
		{
			tmp = half[i];
			half[i] = half[i + 1];
			half[i + 1] = tmp;
			if (i)
				i--;
		}
		else
			i++;
	}
	return (half);
}

std::vector<int>	mergeInsertSort(std::vector<int> sequence)
{
	std::vector<int>::iterator	it = sequence.begin() + sequence.size() / 2;
	std::vector<int>			firstHalf(sequence.begin(), it);
	std::vector<int>			secondHalf(it, sequence.end());

	if (sequence.size() > 10)
	{
		firstHalf = mergeInsertSort(firstHalf);
		secondHalf = mergeInsertSort(secondHalf);
	}
	firstHalf = insertionSort(firstHalf);
	secondHalf = insertionSort(secondHalf);
	sequence.clear();
	sequence = mergeSort(sequence, firstHalf, secondHalf);
	return (sequence);
}
