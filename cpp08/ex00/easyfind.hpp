/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:58:10 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/18 20:53:16 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <cstddef>

template <typename T>
typename T::iterator	easyfind(T & container, int toFind)
{
	typename T::iterator	itToFind;

	itToFind = find(container.begin(), container.end(), toFind);
	if (itToFind == container.end())
		std::cout << "Occurence " << toFind << " not found\n";
	return (itToFind);
}

#endif
