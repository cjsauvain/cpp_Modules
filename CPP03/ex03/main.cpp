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

#include "DiamondTrap.hpp"

void	attackMultipleTimes(DiamondTrap & toto, int nbAttacks)
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
	DiamondTrap	toto("Jordan");

	std::cout << std::endl;
	//attackMultipleTimes(toto, 48);
	toto.beRepaired(3);
	toto.takeDamage(98);
	toto.beRepaired(3);
	toto.takeDamage(8);
	toto.attack("Arthur");
	toto.highFivesGuys();
	toto.guardGate();
	toto.whoAmI();
	std::cout << std::endl;
}
