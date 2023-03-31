/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:10:17 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/31 14:53:04 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombie;
	
	zombie = zombieHorde(5, "Kevin");
	if (zombie)
	{
		zombie[0].announce();
		zombie[1].announce();
		zombie[2].announce();
		zombie[3].announce();
		zombie[4].announce();
		delete []zombie;
	}
}
