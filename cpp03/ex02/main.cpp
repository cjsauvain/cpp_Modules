/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   *//*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:12:21 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/23 10:27:37 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void	attackMultipleTimes(FragTrap & toto, int nbAttacks)
{
	int	i = 0;

	while (i < nbAttacks)
	{
		toto.attack("Arthur");
		i++;
	}
}

int	main(void)
{
	FragTrap	toto("Jordan");

	attackMultipleTimes(toto, 97);
	toto.beRepaired(3);
	toto.takeDamage(98);
	toto.beRepaired(3);
	toto.takeDamage(8);
	toto.attack("Arthur");
	toto.highFivesGuys();
}
