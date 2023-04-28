/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:53:51 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/19 14:38:13 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	public:
		Span(void);
		Span(unsigned int N);
		Span(Span const & source);
		~Span(void);

		Span &	operator=(Span const & source);

		void	addNumber(int number);
		void	addNbRange(std::vector<int>::iterator b, std::vector<int>::iterator e);
		int		shortestSpan() const;
		int		longestSpan() const;
		void	printArrayInfos() const;

	private:
		std::vector<int>	_intArray;
		unsigned int		_lengthMax;
};
