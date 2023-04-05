/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:49:27 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/05 18:13:26 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::convert(std::string literal)
{
	int	pos;

	pos = literal.find_first_not_of("0123456789");
	if (pos == std::npos)
	{
		_integerValue = std::stoi(literal, NULL, 10);
	else if (literal[pos] == '.')
	{
		pos = literal.find_first_not_of("0123456789", pos + 1);
		if (pos == std::npos)
			_doubleValue = std::stod(literal, NULL);
		else if (literal[pos] == 'f' && literal.length() == pos)
			_floattingValue = std::stof(literal, NULL);
		else
		{
			std::cerr << "Unvalid format\n";
			return ;
		}
	}
	else if (((literal[pos] >= 'a' && literal[pos] <= 'z')
			|| (literal[pos] >= 'A' && literal[pos] <= 'Z')) && literal.length() == 1)
		_charValue = literal[pos];
	else
		std::cerr << "Unvalid format\n";
	
}
