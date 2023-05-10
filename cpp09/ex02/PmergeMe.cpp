/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:52:38 by jsauvain          #+#    #+#             */
/*   Updated: 2023/05/10 14:58:44 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//VECTOR ALGORITHM
std::vector<int>	mergeSortVec(std::vector<int> sequence, std::vector<int> firstHalf,	\
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
		sequence = mergeSortVec(sequence, firstHalf, secondHalf);
	return (sequence);
}

std::vector<int>	insertionSortVec(std::vector<int> half)
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

std::vector<int>	mergeInsertSortVec(std::vector<int> sequence)
{
	std::vector<int>::iterator	it = sequence.begin() + sequence.size() / 2;
	std::vector<int>			firstHalf(sequence.begin(), it);
	std::vector<int>			secondHalf(it, sequence.end());

	if (sequence.size() == 1)
		return (sequence);
	if (sequence.size() > 10)
	{
		firstHalf = mergeInsertSortVec(firstHalf);
		secondHalf = mergeInsertSortVec(secondHalf);
	}
	firstHalf = insertionSortVec(firstHalf);
	secondHalf = insertionSortVec(secondHalf);
	sequence.clear();
	sequence = mergeSortVec(sequence, firstHalf, secondHalf);
	return (sequence);
}

//DEQUE ALGORITHM
std::deque<int>	mergeSortDeque(std::deque<int> sequence, std::deque<int> firstHalf,	\
	std::deque<int> secondHalf)
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
		sequence = mergeSortDeque(sequence, firstHalf, secondHalf);
	return (sequence);
}

std::deque<int>	insertionSortDeque(std::deque<int> half)
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

std::deque<int>	mergeInsertSortDeque(std::deque<int> sequence)
{
	std::deque<int>::iterator	it = sequence.begin() + sequence.size() / 2;
	std::deque<int>				firstHalf(sequence.begin(), it);
	std::deque<int>				secondHalf(it, sequence.end());

	if (sequence.size() == 1)
		return (sequence);
	if (sequence.size() > 10)
	{
		firstHalf = mergeInsertSortDeque(firstHalf);
		secondHalf = mergeInsertSortDeque(secondHalf);
	}
	firstHalf = insertionSortDeque(firstHalf);
	secondHalf = insertionSortDeque(secondHalf);
	sequence.clear();
	sequence = mergeSortDeque(sequence, firstHalf, secondHalf);
	return (sequence);
}
