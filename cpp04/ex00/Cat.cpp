/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:17:51 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/24 11:25:55 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const & source) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = source;
}

Cat::~Cat(void)
{
	std::cout << "Cat default destructor called" << std::endl;
}

Cat &	Cat::operator=(Cat const & source)
{
	if (this != &source)
		_type = source._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meeewwww..." << std::endl;
}
