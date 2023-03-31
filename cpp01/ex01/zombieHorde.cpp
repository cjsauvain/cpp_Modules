/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:04:51 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/31 14:52:18 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	if (N > 0)
	{
		Zombie	*zombies;
		int		i;

		zombies = new Zombie[N];
		i = 0;
		while (i < N)
		{
			zombies[i].SetName(name);
			i++;
		}
		return (zombies);
	}
	return (NULL);
}
