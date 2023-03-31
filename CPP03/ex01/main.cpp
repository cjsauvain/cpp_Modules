/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:12:21 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/24 14:26:07 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	attackMultipleTimes(ScavTrap & toto, int nbAttacks)
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
	ScavTrap	toto("toto");

	std::cout << std::endl;
	attackMultipleTimes(toto, 49);
	toto.beRepaired(3);
	toto.takeDamage(98);
	toto.beRepaired(3);
	toto.guardGate();
	std::cout << std::endl;
}
