/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:47:35 by jsauvain          #+#    #+#             */
/*   Updated: 2023/06/02 17:40:14 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequest", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequest", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & source) :
	AForm("RobotomyRequest", 72, 45), _target(source._target)
{
	*this = source;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & source)
{
	if (this != &source)
		_signed = source._signed;
	return (*this);
}

void	RobotomyRequestForm::executeFormAction(void) const
{
	std::cout << "* " << _target << "'s robotization started *" << std::endl;
	if (std::rand() % 2)
		std::cout << "Robotization successfull" << std::endl;
	else
		std::cout << "Robotization failed" << std::endl;
}
