/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:12:11 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/17 16:10:27 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <cstdlib>

template <typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array<T> const & source);
		~Array(void);

		T &			operator[](long long int i);
		Array &	operator=(Array<T> const & source);

		unsigned int	size() const;

	private:
		T *				_array;
		unsigned int	_arrayLength;
};

template <typename T>
Array<T>::Array(void) : _arrayLength(0)
{
	_array = NULL;
}

template <typename T>
Array<T>::Array(unsigned int n) : _arrayLength(n)
{
	_array = new T[n]();
}

template <typename T>
Array<T>::Array(Array<T> const & source)
{
	*this = source;
}

template <typename T>
Array<T>::~Array(void)
{
	if (_array)
		delete []_array;
}

template <typename T>
Array<T> &	Array<T>::operator=(Array<T> const & source)
{
	if (this != &source)
	{
		_arrayLength = source._arrayLength;
		delete _array;
		_array = new T(_arrayLength);
		for (unsigned int i = 0; i < _arrayLength; i++)
			_array[i] = source._array[i];
	}
	return *this;
}

template <typename T>
T &	Array<T>::operator[](long long int i)
{
	if (i > _arrayLength)
		throw std::out_of_range("std::exception : index out");
	if (i < 0 || i > _arrayLength)
		throw std::out_of_range("std::exception : index out of range\n");
	if (_arrayLength == 0)
		throw std::out_of_range("std::exception : empty array");
	return (_array[i]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (_arrayLength);
}
