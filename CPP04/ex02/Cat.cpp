/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:17:51 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/30 17:21:41 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const & source) : AAnimal()
{
	_brain = new Brain();
	std::cout << "Cat copy constructor called" << std::endl;
	*this = source;
}

Cat::~Cat(void)
{
	std::cout << "Cat default destructor called" << std::endl;
	delete _brain;
}

Cat &	Cat::operator=(Cat const & source)
{
	if (this != &source)
	{
		_type = source._type;
		for (int i = 0; i < 100; i++)
			_brain->setIdeas(source._brain, i);
	}
	return (*this);
}

void	Cat::printIdeas(void) const
{
	_brain->displayIdeas();
}

void	Cat::makeSound(void) const
{
	std::cout << "Meeewwww..." << std::endl;
}
