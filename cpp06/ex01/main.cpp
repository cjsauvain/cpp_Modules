/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 14:16:14 by jsauvain          #+#    #+#             */
/*   Updated: 2023/04/15 14:26:27 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data*		ptrStruct = new Data();
	Data*		ptrStructTmp;
	uintptr_t	ptr;

	std::cout << std::endl;
	std::cout << "--------------- BEFORE CAST ---------------\n\n";
	std::cout << "f = " << ptrStruct->f << std::endl;
	std::cout << "ptrStruct = " << ptrStruct << std::endl << std::endl;

	ptr = Serializer::serialize(ptrStruct);
	ptrStructTmp = Serializer::deserialize(ptr);

	std::cout << "--------------- AFTER CAST ---------------\n\n";
	std::cout << "f = " << ptrStructTmp->f << std::endl;
	std::cout << "ptrStructTmp = " << ptrStruct << std::endl << std::endl;
	std::cout << "------------------------------------------\n\n";

	delete ptrStruct;
	//delete ptrStructTmp;
}
