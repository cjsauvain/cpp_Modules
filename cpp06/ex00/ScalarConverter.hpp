/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:03:20 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/05 18:11:17 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static class ScalarConverter
{
	public:
		static void	convert(std::string literal);
		static void	convertMembers();

	private:
		static	ScalarConverter(void);

		static char		charValue = 0;
		static int		integerValue = 0;
		static float	floattingValue = 0;
		static double	doubleValue = 0;
};
