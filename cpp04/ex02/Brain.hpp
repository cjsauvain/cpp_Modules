/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:39:08 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/29 20:52:41 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(Brain const & source);
		~Brain(void);

		Brain &	operator=(Brain const & source);

		void	setIdeas(Brain* idea, int idx);
		void	displayIdeas(void) const;

	private:
		std::string	_ideas[100];
};

#endif
