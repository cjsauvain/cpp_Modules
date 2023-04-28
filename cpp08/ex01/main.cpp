/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:41:53 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/19 14:42:04 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	Span	sp(50);

	std::srand(time(0));

	std::cout << "------------- Subject tests ------------\n\n";
	try{
		sp.addNumber(std::rand() % 50);
		sp.addNumber(-std::rand() % 50);
		sp.addNumber(std::rand() % 50);
		sp.addNumber(-std::rand() % 50);
		sp.addNumber(std::rand() % 50);
	}
	catch (std::exception & e){
		std::cout << "addNumber : " << e.what() << std::endl;
	}

	sp.printArrayInfos();

	try{
		std::cout << "Shortest path : " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::cout << "Longest path : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "---------- Complementary tests ---------\n\n";
	std::vector<int>	vec;

	vec.push_back(-std::rand() % 50);
	vec.push_back(std::rand() % 50);
	vec.push_back(-std::rand() % 50);
	vec.push_back(std::rand() % 50);
	vec.push_back(std::rand() % 50);

	try{
		sp.addNbRange(vec.begin(), vec.end());
	}
	catch (std::exception & e){
		std::cout << "addNbRange : " << e.what() << std::endl;
	}

	sp.printArrayInfos();

	try{
		std::cout << "Shortest path : " << sp.shortestSpan() << std::endl;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	try{
		std::cout << "Longest path : " << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e){
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "----------------------------------------\n";
}
