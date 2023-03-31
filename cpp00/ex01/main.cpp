/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:24:08 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/13 11:47:13 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	instance;
	std::string	command;
	int			index;

	index = 0;
	while (std::cin)
	{
		std::cout << "Enter a command : ";
		getline(std::cin, command);
		if (!command.compare("ADD"))
		{
			instance.AddContact(index);
			index++;
			if (index == 8)
				index = 0;
		}
		else if (!command.compare("SEARCH"))
			instance.SearchContact();
		else if (!command.compare("EXIT"))
			return (1);
	}
	return (0);
}
