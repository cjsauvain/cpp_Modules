/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:24:03 by jsauvain          #+#    #+#             */
/*   Updated: 2023/06/02 17:52:04 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>

int	main(void)
{
	srand(time(NULL));
	try
	{
		Bureaucrat	george("George", 1);
		try {
			george.incrementGrade();
		}
		catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			george.decrementGrade();
			george.decrementGrade();
		}
		catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			AForm*	form = new ShrubberyCreationForm("myGarden");
			for (int i = 0; i < 3; i++)
			{
				if (i == 1)
				{
					delete form;
					form = new RobotomyRequestForm("cyborg");
				}
				else if (i == 2)
				{
					delete form;
					form = new PresidentialPardonForm("john");
				}
				try {
					george.signForm(*form);
				}
				catch (std::exception & e) {
					std::cerr << e.what() << std::endl;
				}
				try {
					george.executeForm(*form);
				}
				catch (std::exception & e) {
					std::cerr << e.what() << std::endl;
				}
				std::cout << std::endl;
			}
			delete form;
		}
		catch (std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}			
