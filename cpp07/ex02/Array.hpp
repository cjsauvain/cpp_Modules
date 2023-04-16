/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:12:11 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/16 16:31:47 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
class Array
{
	public:
		Array<T>(void);
		Array<T>(unsigned int n);
		Array<T>(Array<T> const & source);
		~Array<T>(void);

		Array<T> & const	operator=(Array<T> const & source);

		int	size() const;

	private:
		T *	_array;
};

template <typename T>
Array<T>::Array<T>(void)
{
	_array = new T(1);
	_array[0] = 0;
}

template <typename T>
Array<T>::Array<T>(unsigned int n)
{
	_array = new T(n);
}

template <typename T>
Array<T>::Array<T>(Array<T> const & source)
{
	*this = source;
}

template <typename T>
Array<T> & const	operator=(Array<T> const & source)
{
	if (this != &source)
	{
		delete _array;
		_array = new T(source.size());
		for (int i = 0; i < 
	}
}
