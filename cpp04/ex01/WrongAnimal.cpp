/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:10:09 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/24 11:31:06 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & source)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = source;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal default destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	_type = type;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & source)
{
	if (this != &source)
		_type = source._type;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Random animal sound" << std::endl;
}
