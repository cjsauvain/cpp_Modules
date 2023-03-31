/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:17:51 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/24 11:32:13 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & source) : WrongAnimal()
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = source;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat default destructor called" << std::endl;
}

WrongCat &	WrongCat::operator=(WrongCat const & source)
{
	if (this != &source)
		_type = source._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Meeewwww..." << std::endl;
}
