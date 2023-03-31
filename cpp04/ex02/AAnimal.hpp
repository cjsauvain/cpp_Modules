/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:07:19 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/30 17:20:14 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
	public:
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(AAnimal const & source);
		virtual ~AAnimal(void);

		AAnimal &		operator=(AAnimal const & source);

		std::string		getType(void) const;
		virtual void	printIdeas(void) const;
		virtual void	makeSound(void) const = 0;

	protected:
		std::string	_type;
};

#endif
