/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:59:59 by jsauvain          #+#    #+#             */
/*   Updated: 2023/05/08 11:28:43 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<float>	calcul(std::stack<float> ints, char oper)
{
	float tmp = ints.top();

	ints.pop();
	if (oper == '+')
		ints.top() += tmp;
	else if (oper == '-')
		ints.top() -= tmp;
	else if (oper == '/')
		ints.top() /= tmp;
	else if (oper == '*')
		ints.top() *= tmp;
	return (ints);
}

void	displayResult(std::string numbers)
{
	std::stack<float>		ints;
	size_t				i;

	i = 0;
	while (i < numbers.length())
	{
		if (numbers[i] >= 48 && numbers[i] <= 57 && numbers[i + 1] == ' ')
			ints.push(numbers[i] - 48);
		else if ((numbers[i] == '+' || numbers[i] == '-' 
			|| numbers[i] == '/' || numbers[i] == '*')
			&& (numbers[i + 1] == ' ' || !numbers[i + 1])
			&& ints.size() >= 2)
			ints = calcul(ints, numbers[i]);
		else
		{
			std::cout << "Error: Invalid format\n";
			return ;
		}
		i += 2;
	}
	std::cout << std::fixed << std::setprecision(3) << ints.top() << std::endl;
}
