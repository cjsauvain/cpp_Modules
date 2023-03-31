/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:18:35 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/28 15:34:25 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const & source);
		~MateriaSource(void);

		MateriaSource &	operator=(MateriaSource const & source);
	
		void		learnMateria(AMateria *newMateria);
		AMateria*	createMateria(std::string const & type);
	
	private:
		AMateria*	_materiaLearned[4];
};

#endif
