/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 10:52:22 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/18 12:29:59 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(Point const & cpy);
		Point(float const x, float const y);
		~Point(void);

		Point &	operator=(Point const & rhs);

		Fixed getX(void) const;
		Fixed getY(void) const;

	private:
		Fixed const	_x;
		Fixed const _y;
};

#endif
