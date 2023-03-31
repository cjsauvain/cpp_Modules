/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 09:51:11 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/28 13:50:23 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) : _type("empty")
{
}

AMateria::AMateria(std::string const & type) : _type(type)
{
}

AMateria::AMateria(AMateria const & source)
{
	*this = source;
}

AMateria::~AMateria(void)
{
}

AMateria &	AMateria::operator=(AMateria const & source)
{
	if (this != &source)
		_type = source._type;
	return (*this);
}

std::string const &	AMateria::getType(void) const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}
