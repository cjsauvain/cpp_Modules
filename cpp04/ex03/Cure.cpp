/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:39:22 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/28 13:53:08 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(std::string const & type) : AMateria(type)
{
}

Cure::Cure(Cure const & source) : AMateria(source._type)
{
}

Cure::~Cure(void)
{
}

Cure &	Cure::operator=(Cure const & source)
{
	if (this != &source)
		_type = source._type;
	return (*this);
}

AMateria*	Cure::clone(void) const
{
	Cure*	cure = new Cure("cure");

	return (cure);
}

void	Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *";
	std::cout << std::endl;
}
