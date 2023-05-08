/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:26:04 by jsauvain          #+#    #+#             */
/*   Updated: 2023/05/08 11:38:13 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cerr << "Error: missing file\n";
	else if (argc > 2)
		std::cerr << "Error: too many arguments\n";
	else
		BitcoinExchange::processExchange(argv[1], (char *)"data.csv");
}
