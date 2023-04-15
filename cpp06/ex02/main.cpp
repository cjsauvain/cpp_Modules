/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:30:42 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/15 16:29:44 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base*	generate(void)
{
	int i;

	srand(time(NULL));
	i = std::rand() % 3;
	if (i == 0)
		return (new A());
	if (i == 1)
		return (new B());
	if (i == 2)
		return (new C());
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Object p is of type A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "Object p is of type B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "Object p is of type C\n";
	else
		std::cout << "Object p is neither of type A, B or C\n";
}

void	identify(Base& p)
{
	try{
		dynamic_cast<A&>(p);
		std::cout << "Object p is of type : A\n";
	}
	catch (std::exception & e) {}
	try{
		dynamic_cast<B&>(p);
		std::cout << "Object p is of type : B\n";
	}
	catch (std::exception & e) {}
	try{
		dynamic_cast<C&>(p);
		std::cout << "Object p is of type : C\n";
	}
	catch (std::exception & e) {}
}

int	main(void)
{
	Base*	p = generate();

	identify(*p);

	delete p;
}
