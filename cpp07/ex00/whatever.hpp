/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 12:53:52 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/16 13:35:09 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void	swap(T & a, T & b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T const & a, T const & b)
{
	return (b<=a ? b : a);
}

template <typename T>
T max(T const & a, T const & b)
{
	return (b>=a ? b : a);
}
