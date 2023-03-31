/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:53:03 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/24 11:10:54 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
	_name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
	_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap assignment constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & source)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = source;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap default destructor called" << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & source)
{
	if (this != &source)
	{
		_name = source._name;
		_hitPoints = source._hitPoints;
		_energyPoints = source._energyPoints;
		_attackDamage = source._attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints > 0)
	{
		if (_energyPoints > 0)
		{
			_energyPoints--;
			std::cout << "ClapTrap " << _name << " attacks " << target \
			<< ", causing " << _attackDamage << " points of damage !";
			std::cout << std::endl;
		}
		else if (_energyPoints <= 0)
		{
			std::cout << "ClapTrap " << _name << " does not have enough energy to attack";
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << "ClapTrap " << _name << " cannot attack because he is dead";
		std::cout << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " damages";
		std::cout << std::endl;
		if (_hitPoints <= 0)
			std::cout << "ClapTrap " << _name << " died !" << std::endl;
	}
	else
	{
		std::cout << "You cannot attack ClapTrap" << _name \
			<< ", he is already dead" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints > 0)
	{
		if (_energyPoints > 0)
		{
			_hitPoints += amount;
			_energyPoints--;
			std::cout << "ClapTrap " << _name << " regain " << amount \
				<< " hit points" << std::endl;
		}
		else
		{
			std::cout << "ClapTrap " << _name << " does not have enough energy to heal";
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << "ClapTrap " << _name << " cannot heal, he is already dead !";
		std::cout << std::endl;
	}
}
