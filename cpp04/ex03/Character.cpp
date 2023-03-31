/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:52:43 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/31 14:19:27 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : ICharacter(), _name("defaultName")
{
	int	i = 0;

	while (i < 50)
	{
		if (i < 4)
			_m[i] = NULL;
		_trash[i] = NULL;
		i++;
	}
}

Character::Character(std::string name) : ICharacter(), _name(name)
{
	int	i = 0;

	while (i < 50)
	{
		if (i < 4)
			_m[i] = NULL;
		_trash[i] = NULL;
		i++;
	}
}

Character::Character(Character const & source) : ICharacter()
{
	int	i = 0;

	while (i < 50)
	{
		if (i < 4)
			_m[i] = NULL;
		_trash[i] = NULL;
		i++;
	}
	*this = source;
}

Character::~Character(void)
{
	int	i = 0;

	while (i < 50)
	{
		if (i < 4)
			delete _m[i];
		delete _trash[i];
		i++;
	}
}

Character &	Character::operator=(Character const & source)
{
	if (this != &source)
	{
		int	i = 0;

		while (i < 50)
		{
			if (i < 4)
			{
				delete _m[i];
				if (source._m[i])
					_m[i] = source._m[i]->clone();
			}
			delete _trash[i];
			if (source._trash[i])
				_trash[i] = source._trash[i]->clone();
			i++;
		}
		_name = source._name;
	}
	return (*this);
}

std::string const &	Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	int	i = 0;

	while (i < 4)
	{
		if (_m[i] == NULL)
		{
			_m[i] = m;
			return ;
		}
		i++;
	}
}

void	Character::unequip(int idx)
{
	int	i = 0;

	if (idx >= 0 && idx <= 3)
	{
		while (i < 50)
		{
			if (_trash[i] == NULL)
			{
				_trash[i] = _m[idx];
				_m[idx] = NULL;
				return ;
			}
			i++;
		}
		std::cout << _name << " cannot unequip because the floor is full";
		std::cout << std::endl;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (_m[idx])
		_m[idx]->use(target);
}
