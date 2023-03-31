/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:54:33 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/31 14:47:19 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _number(0)
{
}

Fixed::Fixed(Fixed const & copy) : _number(copy._number)
{
}

Fixed::Fixed(int const number)
{
	this->_number = number << this->_toShift;
}

Fixed::Fixed(float const number)
{
	this->_number = roundf(number * (1 << this->_toShift));
}

Fixed::~Fixed(void)
{
}

Fixed&	Fixed::operator=(Fixed const & rhs)
{
	this->_number = rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const & rhs)
{
	Fixed	result;

	result._number = this->_number + rhs._number;
	return (result);
}

Fixed	Fixed::operator-(Fixed const & rhs)
{
	Fixed	result;

	result._number = this->_number - rhs._number;
	return (result);
}

Fixed	Fixed::operator*(Fixed const & rhs)
{
	Fixed	result;

	result._number = toFloat() * rhs.toFloat() * (1 << _toShift);
	return (result);
}

Fixed	Fixed::operator/(Fixed const & rhs)
{
	Fixed	result;

	result._number = toFloat() / rhs.toFloat() * (1 << _toShift);
	return (result);
}

Fixed &	Fixed::operator++(void)
{
	this->_number++;
	return (*this);
}

Fixed &	Fixed::operator--(void)
{
	this->_number--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	result(*this);

	this->_number++;
	return (result);
}

Fixed	Fixed::operator--(int)
{
	Fixed	result(*this);

	this->_number--;
	return (result);
}

bool	Fixed::operator<(Fixed const & rhs)
{
	return (toFloat() < rhs.toFloat());
}

bool	Fixed::operator>(Fixed const & rhs)
{
	return (toFloat() > rhs.toFloat());
}

bool	Fixed::operator<=(Fixed const & rhs)
{
	return (toFloat() <= rhs.toFloat());
}

bool	Fixed::operator>=(Fixed const & rhs)
{
	return (toFloat() >= rhs.toFloat());
}

bool	Fixed::operator==(Fixed const & rhs)
{
	return (toFloat() == rhs.toFloat());
}

bool	Fixed::operator!=(Fixed const & rhs)
{
	return (toFloat() != rhs.toFloat());
}

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

Fixed &	Fixed::min(Fixed & number1, Fixed & number2)
{
	if (number1.toFloat() < number2.toFloat())
		return (number1);
	return (number2);
}

Fixed const &	Fixed::min(Fixed const & number1, Fixed const & number2)
{
	if (number1.toFloat() < number2.toFloat())
		return (number1);
	return (number2);
}

Fixed &	Fixed::max(Fixed & number1, Fixed & number2)
{
	if (number1.toFloat() > number2.toFloat())
		return (number1);
	return (number2);
}

Fixed const &	Fixed::max(Fixed const & number1, Fixed const & number2)
{
	if (number1.toFloat() > number2.toFloat())
		return (number1);
	return (number2);
}

int	Fixed::getRawBits(void) const
{
	return (this->_number);
}

void	Fixed::setRawBits(int const raw)
{
	this->_number = raw;
}

float	Fixed::toFloat(void) const
{
	float	value;
	int		power;

	power = 1 << this->_toShift;
	value = (float)this->_number / power;
	return (value);
}

int	Fixed::toInt(void) const
{
	return (this->_number / (1 << this->_toShift));
}
