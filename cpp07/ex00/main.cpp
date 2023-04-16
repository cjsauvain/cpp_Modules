/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:57:18 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/16 13:35:18 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "---------- Test with ints ----------\n\n";
	{
		int a = 2;
		int b = 3;

		std::cout << "before swap : a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "after swap : a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}
	std::cout << "\n---------- Test with floats ----------\n\n";
	{
		float a = 64.42f;
		float b = 422.656f;

		std::cout << "before swap : a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "after swap : a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}
	std::cout << "\n---------- Test with doubles ----------\n\n";
	{
		double a = 265.655;
		double b = 65.5;

		std::cout << "before swap : a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "after swap : a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	}
	std::cout << "\n---------- Test with strings ----------\n\n";
	{
		std::string c = "chaine1";
		std::string d = "chaine2";

		std::cout << "before swap : c = " << c << ", d = " << d << std::endl;
		::swap(c, d);
		std::cout << "after swap : c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
}
