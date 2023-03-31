/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:17:51 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/24 11:26:14 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const & source) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = source;
}

Dog::~Dog(void)
{
	std::cout << "Dog default destructor called" << std::endl;
}

Dog &	Dog::operator=(Dog const & source)
{
	if (this != &source)
		_type = source._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Waf !!" << std::endl;
}
