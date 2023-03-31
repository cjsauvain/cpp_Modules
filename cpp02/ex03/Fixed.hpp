/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:49:32 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/18 09:31:10 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & copy);
		Fixed(int const number);
		Fixed(float const toShift);
		~Fixed(void);

		Fixed&	operator=(Fixed const & rhs);
		Fixed	operator+(Fixed const & rhs);
		Fixed	operator-(Fixed const & rhs);
		Fixed	operator*(Fixed const & rhs);
		Fixed	operator/(Fixed const & rhs);
		Fixed &	operator++(void);
		Fixed	operator++(int);
		Fixed &	operator--(void);
		Fixed	operator--(int);
		bool	operator<(Fixed const & rhs);
		bool	operator>(Fixed const & rhs);
		bool	operator<=(Fixed const & rhs);
		bool	operator>=(Fixed const & rhs);
		bool	operator==(Fixed const & rhs);
		bool	operator!=(Fixed const & rhs);

		static Fixed &			min(Fixed & number1, Fixed & number2);
		static Fixed const &	min(Fixed const & number1, Fixed const & number2);
		static Fixed &			max(Fixed & number1, Fixed & number2);
		static Fixed const &	max(Fixed const & number1, Fixed const & number2);
	
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					_number;
		static int const	_toShift = 8;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif
