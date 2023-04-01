/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:21:52 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/01 18:03:21 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	_form[0] = "shrubbery creation";
	_form[1] = "robotomy request";
	_form[2] = "presidential pardon";
}

Intern::Intern(Intern const & source)
{
	*this = source;
}

Intern::~Intern(void)
{
}

Intern &	Intern::operator=(Intern const & source)
{
	if (this != &source)
	{
		for (int i = 0; i < 3; i++)
			_form[i] = source._form[i];
	}
	return (*this);
}

AForm*	Intern::makeForm(std::string name, std::string target) const
{
	for (int i = 0; i < 3; i++)
	{
		if (_form[i] == name)
		{
			switch (i)
			{
				case 0:
					std::cout << "Intern creates ShrubberyCreationForm\n";
					return (new (ShrubberyCreationForm)(target));
				case 1:
					std::cout << "Intern creates RobotomyRequestForm\n";
					return (new (RobotomyRequestForm)(target));
				case 2:
					std::cout << "Intern creates PresidentialPardonForm\n";
					return (new (PresidentialPardonForm)(target));
			}
		}
	}
	std::cout << "This form doesn't exist\n";
	return (NULL);
}
