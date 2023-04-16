/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:55:48 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/16 15:20:43 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	print(T array)
{
	std::cout << array << std::endl;
}

template <typename T>
void	iter(T * array, int length, void (*f)(T))
{
	for (int i = 0; i < length && i < array.length(); i++)
		(*f)(array[i]);
}
