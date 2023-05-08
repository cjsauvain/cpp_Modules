/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:48:04 by jsauvain          #+#    #+#             */
/*   Updated: 2023/05/06 15:35:34 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	std::cout << "------------ Test empty array ------------\n\n";
	{
		Array<int>	tmp;

		try{
			std::cout << tmp[0] << std::endl;
		}
		catch (std::exception & e){
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << "------------ Test int array --------------\n\n";
	{
		Array<int>	tmp(5);
		
		srand(time(NULL));
		for (unsigned int i = 0; i < tmp.size(); i++)
		{
			tmp[i] = std::rand() % 10;
			std::cout << "index " << i << " : " << tmp[i] << std::endl;
		}
		std::cout << std::endl;
		try{
			std::cout << tmp[-1] << std::endl;
		}
		catch (std::exception & e){
			std::cout << e.what();
		}
		try{
			std::cout << tmp[8] << std::endl;
		}
		catch (std::exception & e){
			std::cout << e.what();
		}
		std::cout << std::endl << std::endl;
	}
	std::cout << "------------ Test char array -------------\n\n";
	{
		Array<char>	tmp(5);
		
		srand(time(NULL));
		for (unsigned int i = 0; i < tmp.size(); i++)
		{
			tmp[i] = std::rand() % 94 + 32;
			std::cout << "index " << i << " : " << tmp[i] << std::endl;
		}
		std::cout << std::endl;
		try{
			std::cout << tmp[-1] << std::endl;
		}
		catch (std::exception & e){
			std::cout << e.what();
		}
		try{
			std::cout << tmp[8] << std::endl;
		}
		catch (std::exception & e){
			std::cout << e.what();
		}
		std::cout << std::endl << std::endl;
	}
	std::cout << "------------ Test char const * array -------------\n\n";
	{
		Array<char const *>	tmp(5);
		
		tmp[0] = "oui";
		tmp[1] = "non";
		tmp[2] = "toto";
		tmp[3] = "tata";
		tmp[4] = "lala";
		for (unsigned int i = 0; i < tmp.size(); i++)
			std::cout << "index " << i << " : " << tmp[i] << std::endl;
		std::cout << std::endl;
		try{
			std::cout << tmp[-1] << std::endl;
		}
		catch (std::exception & e){
			std::cout << e.what();
		}
		try{
			std::cout << tmp[8] << std::endl;
		}
		catch (std::exception & e){
			std::cout << e.what();
		}
		std::cout << std::endl << std::endl;
	}
	std::cout << "------------------------------------------\n\n";
}
