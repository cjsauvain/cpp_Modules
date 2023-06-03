/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:29:12 by jsauvain          #+#    #+#             */
/*   Updated: 2023/06/02 17:58:20 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardon", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("PresidentialPardon", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & source) :
	AForm("PresidentialPardon", 25, 5), _target(source._target)
{
	*this = source;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & source)
{
	if (this != &source)
		_signed = source._signed;
	return (*this);
}

void	PresidentialPardonForm::executeFormAction(void) const
{
	std::cout << _target << "has been pardoned by Zaphod Beeblebrox" <<std::endl;
}
