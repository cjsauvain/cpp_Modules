/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:36:30 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/09 10:39:25 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
 
int main(int argc, char **argv)
{
	std::string		str;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int j = 1; j < argc; j++)
	{
		str = argv[j];
		for (size_t i = 0; i < str.length(); i++)
			std::cout << (char)std::toupper(str[i]);
	}
	std::cout << std::endl;
	return (0);
}
