/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:22:51 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/24 14:33:16 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	{
		std::cout << "------------- Animal test : -------------";
		std::cout << std::endl << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		j->makeSound();
		i->makeSound(); //will output the cat sound!
		meta->makeSound();
		std::cout << std::endl;
		delete meta;
		delete j;
		delete i;
	}
	std::cout << std::endl;
	{
		std::cout << "----------- WrongAnimal test : -----------";
		std::cout << std::endl << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();

		std::cout << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		meta->makeSound();
		std::cout << std::endl;
		delete meta;
		delete i;
	}
}
