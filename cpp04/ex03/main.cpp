/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:56:46 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/29 14:59:55 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void	loop(ICharacter* me, IMateriaSource* src, ICharacter* bob)
{
	AMateria* tmp;

	(void)bob;
	for (int i = 0; i < 3; i++)
	{
		tmp = src->createMateria("ic");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("la");
		me->equip(tmp);
		/*me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);*/
		me->unequip(0);
		me->unequip(1);
		me->unequip(2);
		me->unequip(3);
	}
}

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	loop(me, src, bob);

	delete bob;
	delete me;
	delete src;

	return (0);
}
