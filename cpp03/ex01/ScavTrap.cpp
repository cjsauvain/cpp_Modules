/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:42:52 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/24 14:21:40 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & source) : ClapTrap()
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	_name = source._name;
	_hitPoints = source._hitPoints;
	_energyPoints = source._energyPoints;
	_attackDamage = source._attackDamage;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap default destructor called" << std::endl;
}

ScavTrap	ScavTrap::operator=(ScavTrap const & source)
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

void	ScavTrap::attack(const std::string& target)
{
	if (_hitPoints > 0)
	{
		if (_energyPoints > 0)
		{
			_energyPoints--;
			std::cout << "ScavTrap " << _name << " attacks " << target \
			<< ", causing " << _attackDamage << " points of damage !";
			std::cout << std::endl;
		}
		else if (_energyPoints <= 0)
		{
			std::cout << "ScavTrap " << _name << " does not have enough energy to attack";
			std::cout << std::endl;
		}
	}
	else
	{
		std::cout << "ScavTrap " << _name << " cannot attack because he is dead";
		std::cout << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	if (_hitPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " entered in Gate keeper mode";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "ScavTrap " << _name << " cannot entered in Gate keeper mode";
		std::cout << " because he is dead" << std::endl;
	}
}
