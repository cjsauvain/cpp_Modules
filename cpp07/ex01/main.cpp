/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:04:51 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/18 16:34:11 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

template <typename T, typename U>
void	printArray(T array, U size)
{
	std::cout << "Array : (";
	for (U i = 0; i < size; i++)
	{
		std::cout << array[i];
		if (i != size - 1)
			std::cout << ", ";
	}
	std::cout << ")\n";
}

void	initialize(int & arrayElement)
{
	arrayElement = std::rand() % 50;
}

void	squared(int & a)
{
	a = a * a;
}

template <typename T>
void	printModuloTwo(T & array)
{
	std::cout << array << " % 2 = " << array % 2 << std::endl;
}

int	main(void)
{
	int	*i = new int[5];

	std::srand(time(NULL));
	iter(i, 5, &initialize);
	printArray(i, 5);
	iter(i, 5, &printModuloTwo<int>);
	std::cout << std::endl;
	iter(i, 5, &squared);
	printArray(i, 5);
	iter(i, 5, &printModuloTwo<int>);
}
