/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:10:09 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/30 17:20:49 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & source)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = source;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal default destructor called" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
	_type = type;
}

AAnimal &	AAnimal::operator=(AAnimal const & source)
{
	if (this != &source)
		_type = source._type;
	return (*this);
}

void	AAnimal::printIdeas(void) const
{
	std::cout << "Ideas are inside Dogs or Cats" << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}
