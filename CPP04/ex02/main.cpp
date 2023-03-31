/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:22:51 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/30 17:26:09 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	{
		std::cout << "------------- Tests : ------------" << std::endl;
		//const AAnimal	j; ---> non instanciable
		const AAnimal*	k[] = {new Dog(), new Dog(), new Cat(), new Cat()};
	
		std::cout << std::endl;
		k[0]->printIdeas();
		k[0]->makeSound();
		std::cout << std::endl;
		k[1]->printIdeas();
		k[1]->makeSound();
		std::cout << std::endl;

		delete k[0];
		delete k[1];
		delete k[2];
		delete k[3];
		std::cout << std::endl;
	}
	{
		std::cout << "------------- Complementary tests : ------------" << std::endl;
		const Dog* dog1 = new Dog();
		const Dog* dog2 = new Dog(*dog1);
		const Dog* dog3 = new Dog();

		std::cout << std::endl;
		dog1->printIdeas();
		std::cout << std::endl;
		dog2->printIdeas();
		std::cout << std::endl;
		dog3->printIdeas();
		std::cout << std::endl;
		
		delete dog1;
		delete dog2;
		delete dog3;
	}
	return (0);
}
