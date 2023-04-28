/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:26:31 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/19 14:38:56 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _lengthMax(0)
{
}

Span::Span(unsigned int N) : _lengthMax(N)
{
}

Span::Span(Span const & source)
{
	*this = source;
}

Span::~Span(void)
{
}

Span &	Span::operator=(Span const & source)
{
	if (this != &source)
	{
		_lengthMax = source._lengthMax;
		_intArray = source._intArray;
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	if (_intArray.size() == _lengthMax)
		throw std::exception();
	_intArray.push_back(number);
}

void	Span::addNbRange(std::vector<int>::iterator b, std::vector<int>::iterator e)
{
	if (_intArray.size() + e - b - 1 >= _lengthMax)
		throw std::exception();
	if (_intArray.size())
		_intArray.insert(_intArray.end() - 1, b, e);
	else
		_intArray.insert(_intArray.begin(), b, e);
}

int	Span::shortestSpan() const
{
	if (_intArray.size() == 0 || _intArray.size() == 1)
		throw std::exception();

	std::vector<int>			tmp(_intArray);
	std::vector<int>::iterator	it = tmp.begin();
	int							diffMin;

	std::sort(tmp.begin(), tmp.end());
	diffMin =  *(it + 1) - *it++;
	for (; it != tmp.end() - 1; it++)
	{
		if (*(it + 1) - *it < diffMin)
			diffMin = *(it + 1) - *it;
	}
	return (diffMin);
}

int	Span::longestSpan() const
{
	if (_intArray.size() == 0 || _intArray.size() == 1)
		throw std::exception();

	std::vector<int>			tmp(_intArray);
	int							diffMax;

	std::sort(tmp.begin(), tmp.end());
	diffMax = *(tmp.end() - 1) - *tmp.begin();
	return (diffMax);
}

void	Span::printArrayInfos() const
{
	if (!_intArray.size())
	{
		std::cout << "Empty array\n";
		return ;
	}
	std::vector<int>	tmp(_intArray);
	std::vector<int>::iterator	it;

	std::cout << "Array : (";
	for (it = tmp.begin(); it != tmp.end() - 1; it++)
	{
		if (it != _intArray.end() - 1)
			std::cout << *it << ", ";
	}
	std::cout << *it << ")  ~  size : " << _intArray.size() << std::endl;
}
