/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:17:51 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/30 17:22:10 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const & source) : AAnimal()
{
	_brain = new Brain();
	std::cout << "Dog copy constructor called" << std::endl;
	*this = source;
}

Dog::~Dog(void)
{
	std::cout << "Dog default destructor called" << std::endl;
	delete _brain;
}

Dog &	Dog::operator=(Dog const & source)
{
	if (this != &source)
	{
		_type = source._type;
		for (int i = 0; i < 100; i++)
			_brain->setIdeas(source._brain, i);
	}
	return (*this);
}

void	Dog::printIdeas(void) const
{
	_brain->displayIdeas();
}

void	Dog::makeSound(void) const
{
	std::cout << "Waf !!" << std::endl;
}
