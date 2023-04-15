/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:03:20 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/15 15:34:58 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <climits>
#include <cfloat>
#include <iomanip>

class ScalarConverter
{
	public:
		static void	convert(std::string literal);
		static int	isException(std::string literal);
		static void	printException(std::string literal);
		static int	isChar(std::string literal);
		static int	isInt(std::string literal);
		static int	isFloat(std::string literal);
		static int	isDouble(std::string literal);
		static void	convertFromChar(std::string literal);
		static void	convertFromInt(std::string literal);
		static void	convertFromFloat(std::string literal);
		static void	convertFromDouble(std::string literal);

	private:
		ScalarConverter(void);
};

#endif
