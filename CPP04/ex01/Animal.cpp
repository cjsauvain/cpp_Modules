/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:10:09 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/24 15:51:34 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const & source)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = source;
}

Animal::~Animal(void)
{
	std::cout << "Animal default destructor called" << std::endl;
}

Animal::Animal(std::string type)
{
	_type = type;
}

Animal &	Animal::operator=(Animal const & source)
{
	if (this != &source)
		_type = source._type;
	return (*this);
}

void	Animal::printIdeas(void) const
{
	std::cout << "Ideas are inside Dogs or Cats" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Random animal sound" << std::endl;
}
