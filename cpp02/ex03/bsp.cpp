/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:05:26 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/22 10:59:53 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	angleAPB;
	Fixed	angleBPC;
	Fixed	angleCPA;
	
	angleAPB = (a.getX() - point.getX()) * (b.getY() - point.getY())
				- (a.getY() - point.getY()) * (b.getX() - point.getX());
	angleBPC = (b.getX() - point.getX()) * (c.getY() - point.getY())
				- (b.getY() - point.getY()) * (c.getX() - point.getX());
	angleCPA = (c.getX() - point.getX()) * (a.getY() - point.getY())
				- (c.getY() - point.getY()) * (a.getX() - point.getX());
	if (angleAPB > 0 && angleBPC > 0 && angleCPA > 0)
		return (true);
	else if (angleAPB < 0 && angleBPC < 0 && angleCPA < 0)
		return (true);
	return (false);
}
