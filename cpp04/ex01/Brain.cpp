/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:47:56 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/01 18:29:48 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <cstdlib>

Brain::Brain(void)
{
	std::string	ideas[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	int			j;

	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		j = std::rand() % 9;
		_ideas[i] = ideas[j];
	}
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const & source)
{
	std::cout << "Brain default constructor called" << std::endl;
	*this = source;
}

Brain::~Brain(void)
{
	std::cout << "Brain default destructor called" << std::endl;
}

Brain &	Brain::operator=(Brain const & source)
{
	if (this != &source)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = source._ideas[i];
	}
	return (*this);
}

void	Brain::setIdeas(Brain* idea, int idx)
{
	_ideas[idx] = idea->_ideas[idx];
}

void	Brain::displayIdeas(void) const
{
	for (int i = 0; i < 100; i++)
		std::cout << _ideas[i] << " ";
	std::cout << std::endl;
}
