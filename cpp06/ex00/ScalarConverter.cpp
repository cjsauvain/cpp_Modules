/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:49:27 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/28 20:01:06 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

int		ScalarConverter::isException(std::string literal)
{
	if (!literal.compare("nan") || !literal.compare("nanf"))
		return (1);
	if (!literal.compare("+inf") || !literal.compare("+inff"))
		return (1);
	if (!literal.compare("-inf") || !literal.compare("-inff"))
		return (1);
	return (0);
}

void	ScalarConverter::printException(std::string literal)
{
	if (!literal.find("nan"))
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
	else if (!literal.find("+inf"))
		std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";
	else if (!literal.compare("-inf"))
		std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf\n";
}

int		ScalarConverter::isChar(std::string literal)
{
	if (literal.length() == 1)
		return (1);
	return (0);
}

int		ScalarConverter::isInt(std::string literal)
{
	size_t	pos;
	int		i = 0;

	if (literal[0] == '-')
		i = 1;
	pos = literal.find_first_not_of("0123456789", i);
	if (pos == std::string::npos)
		return (1);
	return (0);
}

int		ScalarConverter::isFloat(std::string literal)
{
	size_t	pos;
	int		i = 0;

	if (literal[0] == '-')
		i = 1;
	pos = literal.find_first_not_of("0123456789", i);
	if (pos != std::string::npos && literal[pos] == '.')
	{
		pos = literal.find_first_not_of("0123456789", pos + 1);
		if (pos != std::string::npos && literal[pos] == 'f' && literal.length() == pos + 1)
			return (1);
	}
	return (0);
}

int		ScalarConverter::isDouble(std::string literal)
{
	size_t	pos;
	int		i = 0;

	if (literal[0] == '-')
		i = 1;
	pos = literal.find_first_not_of("0123456789", i);
	if (pos != std::string::npos && literal[pos] == '.')
	{
		pos = literal.find_first_not_of("0123456789", pos + 1);
		if (pos == std::string::npos)
			return (1);
	}
	return (0);
}

void	ScalarConverter::convertFromChar(std::string literal)
{
	if (literal[0] >= 32 && literal[0] <= 126)
		std::cout << "char: " << literal[0] << std::endl;
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << \
		static_cast<float>(literal[0]) << "f\n";
	std::cout << "double: " << std::fixed << std::setprecision(1) << \
		static_cast<double>(literal[0]) << std::endl;
}

void	ScalarConverter::convertFromInt(std::string literal)
{
	std::stringstream	ss(literal);
	int					literalValue;

	if (!(ss >> literalValue))
	{
		std::cout << "Unvalid value : overflow\n";
		return ;
	}
	if (literalValue >= 32 && literalValue < 127)
		std::cout << "char: " << static_cast<char>(literalValue) << std::endl;
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << literalValue << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << \
		static_cast<float>(literalValue) << "f\n";
	std::cout << "double: " << std::fixed << std::setprecision(1) << \
		static_cast<double>(literalValue) << std::endl;
}

void	ScalarConverter::convertFromFloat(std::string literal)
{
	std::stringstream	ss(literal);
	float				literalValue;

	if (!(ss >> literalValue))
	{
		std::cout << "Unvalid value : overflow\n";
		return ;
	}
	if (literalValue >= 32 && literalValue < 127)
		std::cout << "char: " << static_cast<char>(literalValue) << std::endl;
	else
		std::cout << "char: Non displayable\n";
	if (literalValue > INT_MAX || literalValue < INT_MIN)
		std::cout << "int: overflow\n";
	else
		std::cout << "int: " << static_cast<int>(literalValue) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << \
		literalValue << "f\n";
	std::cout << "double: " << std::fixed << std::setprecision(1) << \
		static_cast<double>(literalValue) << std::endl;
}

void	ScalarConverter::convertFromDouble(std::string literal)
{
	std::stringstream	ss(literal);
	double				literalValue;

	if (!(ss >> literalValue))
	{
		std::cout << "Unvalid value : overflow\n";
		return ;
	}
	if (literalValue >= 32 && literalValue < 127)
		std::cout << "char: " << static_cast<char>(literalValue) << std::endl;
	else
		std::cout << "char: Non displayable\n";
	if (literalValue > INT_MAX || literalValue < INT_MIN)
		std::cout << "int: overflow\n";
	else
		std::cout << "int: " << static_cast<int>(literalValue) << std::endl;
	if (literalValue > FLT_MAX)
		std::cout << "float: +inff\n";
	else if (literalValue < FLT_MIN)
		std::cout << "float: -inff\n";
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << \
			literalValue << "f\n";
	std::cout << "double: " << std::fixed << std::setprecision(1) << \
		static_cast<double>(literalValue) << std::endl;
}

void	ScalarConverter::convert(std::string literal)
{
	if (isException(literal))
		printException(literal);
	else if (isChar(literal))
		convertFromChar(literal);
	else if (isInt(literal))
		convertFromInt(literal);
	else if (isFloat(literal))
		convertFromFloat(literal);
	else if (isDouble(literal))
		convertFromDouble(literal);
	else
		std::cout << "Unvalid format\n";
}
