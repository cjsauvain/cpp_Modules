/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:32:42 by jsauvain          #+#    #+#             */
/*   Updated: 2023/05/09 18:13:47 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	init(char **argv)
{
	std::vector<int>	sequence;
	int					nb;

	for (int i = 0; argv[i]; i++)
	{
		if (!(std::stringstream(argv[i]) >> nb))
			throw std::out_of_range("Error: overflow\n");
		if (nb < 0)
			throw std::exception("Error: negative number\n");
		sequence.push_back(nb);
	}
	return (sequence);
}

void	display(std::vector<int> sequence, std::string str)
{
	size_t	i;

	std::cout << str;
	for (i = 0; i < sequence.size() - 1; i++)
		std::cout << sequence[i] << " ";
	std::cout << sequence[i] << std::endl;
}

int	main(int argc, char **argv)
{
	std::vector<int>	sequence;

	if (argc > 2)
	{
		try{
			sequence = init(argv + 1);
		}
		catch (std::exception & e){
			std::cerr << e.what();
		}
		display(sequence, "Before: ");
		sequence = mergeInsertSort(sequence);
	}
	display(sequence, "After: ");
}
