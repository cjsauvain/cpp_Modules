/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:32:42 by jsauvain          #+#    #+#             */
/*   Updated: 2023/05/10 15:22:15 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <exception>

template <typename T>
T	init(char **argv)
{
	T	sequence;
	int	nb;

	for (int i = 0; argv[i]; i++)
	{
		if (!(std::stringstream(argv[i]) >> nb))
			throw std::out_of_range("Error: overflow\n");
		sequence.push_back(nb);
	}
	return (sequence);
}

template <typename T>
void	display(T sequence, std::string str)
{
	typename T::iterator	it;

	std::cout << str;
	for (it = sequence.begin(); it != --(sequence.end()); it++)
		std::cout << *it << " ";
	std::cout << *it << std::endl;
}

int	parsing(int argc, char **argv)
{
	std::string	str;
	size_t		pos = 0;
	size_t		pos2 = 0;

	if (argc == 1)
	{
		std::cerr << "Error: missing arguments\n";
		return (1);
	}
	for (int i = 0; argv[i]; i++)
	{
		str = argv[i];
		pos = str.find_first_not_of("0123456789");
		if (pos != std::string::npos || str.empty())
		{
			pos2 = str.find_first_not_of("0123456789", pos + 1);
			if (pos2 == std::string::npos && str[pos] == '-')
				std::cerr << "Error: negative number\n";
			else
				std::cerr << "Error: invalid format\n";
			return (1);
		}
	}
	return (0);
}

int	vectorSorting(char **argv)
{
	std::vector<int>	vectorSequence;
	struct timeval		tv;
	int					time = 0;

	try
	{
		vectorSequence = init< std::vector<int> >(argv);
		gettimeofday(&tv, NULL);
		time = tv.tv_sec * 1000000 + tv.tv_usec;
		vectorSequence = mergeInsertSortVec(vectorSequence);
		gettimeofday(&tv, NULL);
		time = tv.tv_sec * 1000000 + tv.tv_usec - time;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what();
	}
	return (time);
}

int	dequeSorting(char **argv)
{
	std::deque<int>		dequeSequence;
	struct timeval		tv;
	int					time = 0;

	try
	{
		dequeSequence = init< std::deque<int> >(argv);
		display< std::deque<int> >(dequeSequence, "Before:   ");
		gettimeofday(&tv, NULL);
		time = tv.tv_sec * 1000000 + tv.tv_usec;
		dequeSequence = mergeInsertSortDeque(dequeSequence);
		gettimeofday(&tv, NULL);
		time = tv.tv_sec * 1000000 + tv.tv_usec - time;
		display< std::deque<int> >(dequeSequence, "After:   ");
	}
	catch (std::exception & e)
	{
		std::cerr << e.what();
	}
	return (time);
}

int	main(int argc, char **argv)
{
	int	timeVector = 0;
	int	timeDeque = 0;

	if (parsing(argc, argv + 1))
		return (1);
	else
	{
		timeVector = vectorSorting(argv + 1);
		timeDeque = dequeSorting(argv + 1);
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector :   " \
			<< timeVector << " μs\n";
		std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque :   " \
			<< timeDeque << " μs\n";
	}
	return (0);
}
