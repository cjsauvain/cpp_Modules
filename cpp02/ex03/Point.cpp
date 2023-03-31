/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:56:42 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/18 12:36:47 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(Fixed()), _y(Fixed())
{
}

Point::Point(Point const & cpy) : _x(cpy._x), _y(cpy._y)
{
}

Point::Point(float const x, float const y) :
	_x(Fixed(x)), _y(Fixed(y))
{
}

Point::~Point(void)
{
}

Point &	Point::operator=(Point const & rhs)
{
	(void)rhs;
	std::cout << "Cannot assign constantes attributes" << std::endl;
	return (*this);
}

Fixed	Point::getX(void) const
{
	return (_x);
}

Fixed	Point::getY(void) const
{
	return (_y);
}
