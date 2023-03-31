/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:03:05 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/13 12:02:54 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:

		PhoneBook(void);
		~PhoneBook(void);

		void		AddContact(int i);
		void		SearchContact(void);
		void		ExitPhoneBook(void);
		void		DisplayContacts(void);
		std::string	PrintContactInfos(size_t i);
		void		DisplayInfos(void);
		void		EmptyInfos(int i);

	private:

		size_t	nb_contacts;
		Contact	contacts[8];
};

#endif
