/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 10:37:05 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/28 13:47:50 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(std::string const & type);
		Ice(Ice const & source);
		~Ice(void);

		Ice &	operator=(Ice const & source);

		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

#endif
