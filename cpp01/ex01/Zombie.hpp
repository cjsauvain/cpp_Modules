/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:53:19 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/17 11:26:17 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	public:

		Zombie(void);
		~Zombie(void);

		void	announce(void) const;
		void	SetName(std::string name);

	private:

		std::string	_name;
};

Zombie	*zombieHorde(int N, std::string name);

# endif
