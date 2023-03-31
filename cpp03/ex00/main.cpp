/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:12:21 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/24 14:19:10 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	attackMultipleTimes(ClapTrap & toto, int nbAttacks)
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
	ClapTrap	toto("toto");

	attackMultipleTimes(toto, 9);
	toto.takeDamage(5);
	toto.beRepaired(3);
	toto.takeDamage(8);
}
