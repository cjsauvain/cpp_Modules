/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:33:28 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/23 16:04:59 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : _name("DdefaultName")
{
	_hitPoints = 100; //FragTrap::_hitPoints;
	_energyPoints = 50; //ScavTrap::_energyPoints;
	_attackDamage = 30; //FragTrap::_attackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
	_name = name;
	_hitPoints = 100; //FragTrap::_hitPoints;
	_energyPoints = 50; //ScavTrap::_energyPoints;
	_attackDamage = 30; //FragTrap::_attackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const & source) :
	ClapTrap(source._name + "_clap_name"), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	_name = source._name;
	_hitPoints = source._hitPoints;
	_energyPoints = source._energyPoints;
	_attackDamage = source._attackDamage;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap default destructor called" << std::endl;
}

DiamondTrap &	DiamondTrap::operator=(DiamondTrap const & source)
{
	if (this == &source)
	{
		ClapTrap::_name = source.ClapTrap::_name;
		_name = source._name;
		_hitPoints = source._hitPoints;
		_energyPoints = source._energyPoints;
		_attackDamage = source._attackDamage;
	}
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	if (_hitPoints > 0)
	{
		std::cout << "My ClapTrap name is : " << ClapTrap::_name << std::endl;
		std::cout << "My DiamondTrap name is : " << _name << std::endl;
	}
	else
	{
		std::cout << "DiamondTrap cannot present himself because he is dead";
		std::cout << std::endl;
	}
}
