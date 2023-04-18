/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:53:51 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/18 18:57:09 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
class Span
{
	public:
		Span(void);
		Span(T intArray);
		Span(Span<T> const & source);
		~Span(void);

		Span<T> &	operator=(Span<T> const & source);

		void	addNumber(int number);
		

	private:
		T	_intArray;
};
