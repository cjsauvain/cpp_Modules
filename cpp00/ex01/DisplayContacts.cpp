/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DisplayContacts.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:37:30 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/13 17:22:44 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

static void	print_header(void)
{
	std::cout << "*********************************************" << std::endl;
	std::cout << "*     INDEX|FIRST NAME| LAST NAME|  NICKNAME*" << std::endl;
	std::cout << "*********************************************" << std::endl;
}

std::string	PhoneBook::PrintContactInfos(size_t i)
{
	std::string	infos;

	std::cout << std::setw(11) << this->contacts[i].index << "|";
	infos = this->contacts[i].first_name;
	if (infos.length() >= 10)
	{
		infos.resize(9);
		infos.resize(10, '.');
	}
	std::cout << std::setw(10) << infos << "|";
	infos = this->contacts[i].last_name;
	if (infos.length() >= 10)
	{
		infos.resize(9);
		infos.resize(10, '.');
	}
	std::cout << std::setw(10) << infos << "|";
	infos = this->contacts[i].nickname;
	if (infos.length() >= 10)
	{
		infos.resize(9);
		infos.resize(10, '.');
	}
	std::cout << std::setw(10) << infos << "|";
	return (infos);
}

void	PhoneBook::DisplayContacts(void)
{
	size_t		i;
	std::string	infos;

	i = 0;
	print_header();
	while (i < this->nb_contacts)
	{
		PrintContactInfos(i);
		std::cout << std::endl;
		i++;
	}
	std::cout << std::endl << std::endl;
}
