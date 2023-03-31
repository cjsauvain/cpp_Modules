/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:24:03 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/31 11:55:21 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	George("George", 1);

		std::cout << George;
		George.incrementGrade();
		std::cout << George;
		George.decrementGrade();
		std::cout << George;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
