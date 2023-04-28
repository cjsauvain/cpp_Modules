/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 10:19:30 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/28 17:28:46 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>
#include <vector>

int main(void)
{
	std::cout << "---------- Test with MutantStack ----------\n\n";
	{
		MutantStack<int>  mstack;
	
		mstack.push(1);
		mstack.push(17);

		std::cout << "top : " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "size : " << mstack.size() << std::endl << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		std::cout << *it << std::endl;
		*it = 42;
		std::cout << *it << std::endl << std::endl;
		*it = 1;
		std::cout << "position 1 : " << it[1] << std::endl;
		std::cout << "position 3 : " << it[3] << std::endl << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;
		--it;
		std::cout << *(--it) << std::endl;
		std::cout << *(++it) << std::endl << std::endl;
		std::cout << "top : " << mstack.top() << std::endl;
		std::cout << "size : " << mstack.size() << std::endl;

		std::stack<int> s(mstack);
	}
	std::cout << "\n---------- Test with List ----------\n\n";
	{
		std::list<int> mlist;
	
		mlist.push_back(1);
		mlist.push_back(17);

		std::cout << "back : " << mlist.back() << std::endl;
		mlist.pop_back();
		std::cout << "size : " << mlist.size() << std::endl << std::endl;

		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		mlist.push_back(0);

		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();

		std::cout << *it << std::endl;
		*it = 42;
		std::cout << *it << std::endl << std::endl;
		*it = 1;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;
		--it;
		std::cout << *(--it) << std::endl;
		std::cout << *(++it) << std::endl << std::endl;
		std::cout << "top : " << mlist.back() << std::endl;
		std::cout << "size : " << mlist.size() << std::endl;
	}
	std::cout << "\n---------- Test with Vector ----------\n\n";
	{
		std::vector<int> mvector;
	
		mvector.push_back(1);
		mvector.push_back(17);

		std::cout << "back : " << mvector.back() << std::endl;
		mvector.pop_back();
		std::cout << "size : " << mvector.size() << std::endl << std::endl;

		mvector.push_back(3);
		mvector.push_back(5);
		mvector.push_back(737);
		mvector.push_back(0);

		std::vector<int>::iterator it = mvector.begin();
		std::vector<int>::iterator ite = mvector.end();

		std::cout << *it << std::endl;
		*it = 42;
		std::cout << *it << std::endl << std::endl;
		*it = 1;
		std::cout << "position 1 : " << it[1] << std::endl;
		std::cout << "position 3 : " << it[3] << std::endl << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << std::endl;
		--it;
		std::cout << *(--it) << std::endl;
		std::cout << *(++it) << std::endl << std::endl;
		std::cout << "top : " << mvector.back() << std::endl;
		std::cout << "size : " << mvector.size() << std::endl;
	}
	std::cout << "\n------------------------------------\n\n";
	return (0);
}
