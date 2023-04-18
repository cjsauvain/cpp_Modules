/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:22:57 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/18 20:53:54 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <ctime>

template <typename T>
void	printContainer(T container)
{
	typename T::iterator it = container.begin();
	typename T::iterator itEnd = container.end();

	std::cout << "Contains : (";
	itEnd--;
	for (; it != itEnd; it++)
		std::cout << *it << ", ";
	std::cout << *it << ")\n";
}

int	main(void)
{
	std::srand(time(0));
	std::cout << "---------- Tests with vectors ----------\n\n";
	{
		std::vector<int>			vec;
		std::vector<int>::iterator	it;
		int							nb;

		vec.push_back(std::rand() % 20);
		vec.push_back(std::rand() % 20);
		nb = std::rand() % 20;
		vec.push_back(nb);
		vec.push_back(std::rand() % 20);
		printContainer(vec);
		it = easyfind(vec, nb);
		if (it != vec.end())
			std::cout << "Occurence " << *it << " found\n";
		it = easyfind(vec, -1);
		if (it != vec.end())
			std::cout << "Occurence " << *it << " found\n";
		std::cout << std::endl;
	}
	std::cout << "---------- Tests with lists ----------\n\n";
	{
		std::list<int>				lst;
		std::list<int>::iterator	it;
		int							nb;

		lst.push_back(std::rand() % 20);
		lst.push_back(std::rand() % 20);
		nb = std::rand() % 20;
		lst.push_back(nb);
		lst.push_back(std::rand() % 20);
		printContainer(lst);
		it = easyfind(lst, nb);
		if (it != lst.end())
			std::cout << "Occurence " << *it << " found\n";
		it = easyfind(lst, -1);
		if (it != lst.end())
			std::cout << "Occurence " << *it << " found\n";
		std::cout << std::endl;
	}
	std::cout << "---------- Tests with deques ----------\n\n";
	{
		std::deque<int>				dq;
		std::deque<int>::iterator	it;
		int							nb;

		dq.push_back(std::rand() % 20);
		dq.push_back(std::rand() % 20);
		nb = std::rand() % 20;
		dq.push_back(nb);
		dq.push_back(std::rand() % 20);
		printContainer(dq);
		it = easyfind(dq, nb);
		if (it != dq.end())
			std::cout << "Occurence " << *it << " found\n";
		it = easyfind(dq, -1);
		if (it != dq.end())
			std::cout << "Occurence " << *it << " found\n";
		std::cout << std::endl;
	}
	std::cout << "---------------------------------------\n";
}
