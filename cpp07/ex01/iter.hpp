/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:55:48 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/18 16:25:02 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T, typename K, typename U>
void	iter(T array, K length, U function)
{
	for (K i = 0; i < length; i++)
		function(array[i]);
}
