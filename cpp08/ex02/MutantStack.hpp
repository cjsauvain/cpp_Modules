/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:44:18 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/28 17:12:58 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef	typename std::stack<T>::container_type::iterator		iterator;
		typedef	typename std::stack<T>::container_type::const_iterator	const_iterator;
		
		//Constructors
		MutantStack(void);
		MutantStack(MutantStack const & source);
		//Destructor
		~MutantStack(void);

		//Operator Overload
		MutantStack &	operator=(MutantStack const & source);

		//Member Functions
		iterator		begin(void) { return (this->c.begin()); }
		const_iterator	begin(void) const { return (this->c.begin()); }
		iterator		end(void) { return (this->c.end()); }
		const_iterator	end(void) const { return (this->c.end()); }
};

template <typename T>
MutantStack<T>::MutantStack(void)
{
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const & source)
{
	*this = source;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}

template <typename T>
MutantStack<T> &	MutantStack<T>::operator=(MutantStack<T> const & source)
{
	if (this != &source)
		this->c = source.c;
	return (*this);
}
