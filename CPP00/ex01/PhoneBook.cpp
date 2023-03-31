/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:09:06 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/13 17:15:16 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook(void)
{
	this->nb_contacts = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::EmptyInfos(int i)
{
	this->contacts[i].first_name = "";
	this->contacts[i].last_name = "";
	this->contacts[i].nickname = "";
	this->contacts[i].phone_number = "";
	this->contacts[i].darkest_secret = "";
}

void	PhoneBook::AddContact(int i)
{
	std::cout << std::endl;
	if (this->nb_contacts < 8)
		this->nb_contacts++;
	this->contacts[i].index = i + 1;
	EmptyInfos(i);
	while (std::cin && this->contacts[i].first_name.empty())
	{
		std::cout << "First name : ";
		getline(std::cin, this->contacts[i].first_name);
	}
	while (std::cin && this->contacts[i].last_name.empty())
	{
		std::cout << "Last name : ";
		getline(std::cin, this->contacts[i].last_name);
	}
	while (std::cin && this->contacts[i].nickname.empty())
	{
		std::cout << "Nickname : ";
		getline(std::cin, this->contacts[i].nickname);
	}
	while (std::cin && this->contacts[i].phone_number.empty())
	{
		std::cout << "Phone number : ";
		getline(std::cin, this->contacts[i].phone_number);
	}
	while (std::cin && this->contacts[i].darkest_secret.empty())
	{
		std::cout << "Darkest secret : ";
		getline(std::cin, this->contacts[i].darkest_secret);
	}
	std::cout << std::endl;
}

std::string	GetValidIndex(size_t nb_contacts)
{
	std::string	index;
	std::size_t	pos;

	std::cout << "Enter the index you are looking for : ";
	getline(std::cin, index);
	pos = index.find_first_not_of("12345678");
	while ((index.length() > 1 || index.empty()
		|| pos != std::string::npos
		|| (size_t)(index[0] - 48) > nb_contacts) && std::cin)
	{
		std::cout << "Invalid index, try again : ";
		getline(std::cin, index);
		pos = index.find_first_not_of("12345678");
	}
	return (index);
}

void	PhoneBook::DisplayInfos(void)
{
	std::string	index;

	DisplayContacts();
	index = GetValidIndex(this->nb_contacts);
	if (index.empty())
		return ;
	std::cout << std::endl << "First name : " \
		<< this->contacts[index[0] - 49].first_name;
	std::cout << std::endl << "Last name : " \
		<< this->contacts[index[0] - 49].last_name;
	std::cout << std::endl << "Nickname : " \
		<< this->contacts[index[0] - 49].nickname;
	std::cout << std::endl << "Phone number : " \
		<< this->contacts[index[0] - 49].phone_number;
	std::cout << std::endl << "Darkest secret : " \
		<< this->contacts[index[0] - 49].darkest_secret;
	std::cout << std::endl;
}

void	PhoneBook::SearchContact(void)
{
	std::cout << std::endl;
	if (this->nb_contacts)
		DisplayInfos();
	else
		std::cout << "No contacts registered yet" << std::endl;
	std::cout << std::endl;
}
