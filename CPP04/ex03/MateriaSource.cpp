/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:28:22 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/29 13:00:46 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : IMateriaSource()
{
	int	i = 0;

	while (i < 4)
	{
		_materiaLearned[i] = NULL;
		i++;
	}
}

MateriaSource::MateriaSource(MateriaSource const & source) : IMateriaSource()
{
	int	i = 0;

	while (i < 4)
	{
		_materiaLearned[i] = NULL;
		i++;
	}
	*this = source;
}

MateriaSource::~MateriaSource(void)
{
	int	i = 0;

	while (i < 4)
	{
		delete _materiaLearned[i];
		i++;
	}
}

MateriaSource &	MateriaSource::operator=(MateriaSource const & source)
{
	if (this != &source)
	{
		int	i = 0;

		while (i < 4)
		{
			delete _materiaLearned[i];
			if (source._materiaLearned[i])
				_materiaLearned[i] = source._materiaLearned[i]->clone();
			i++;
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* newMateria)
{
	int	i = 0;
	
	while (i < 4)
	{
		if (_materiaLearned[i] == NULL)
		{
			_materiaLearned[i] = newMateria;
			return ;
		}
		i++;
	}
	delete newMateria;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	int			i = 0;

	while (i < 4)
	{
		if (_materiaLearned[i] != NULL && _materiaLearned[i]->getType() == type)
			return (_materiaLearned[i]->clone());
		i++;
	}
	return (0);
}
