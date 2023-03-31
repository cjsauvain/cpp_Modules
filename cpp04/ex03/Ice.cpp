/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:39:22 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/28 16:14:49 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(std::string const & type) : AMateria(type)
{
}

Ice::Ice(Ice const & source) : AMateria(source._type)
{
}

Ice::~Ice(void)
{
}

Ice &	Ice::operator=(Ice const & source)
{
	if (this != &source)
		_type = source._type;
	return (*this);
}

AMateria*	Ice::clone(void) const
{
	Ice*	ice = new Ice("ice");

	return (ice);
}

void	Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *";
	std::cout << std::endl;
}
