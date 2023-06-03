/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <jsauvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:54:11 by jsauvain          #+#    #+#             */
/*   Updated: 2023/06/02 17:51:09 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreation", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & source) :
	AForm("ShrubberyCreation", 145, 137), _target(source._target)
{
	*this = source;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & source)
{
	if (this != &source)
		_signed = source._signed;
	return (*this);
}

void	ShrubberyCreationForm::executeFormAction(void) const
{
	std::string		fileName = _target + "_shurbbery";
	std::ofstream	ofs(fileName.c_str());

	if (ofs.is_open())
	{
		std::string		asciiTree =  "                                                         .\n"
									 "                                              .         ;\n"
									 "                 .              .              ;%     ;;\n"
									 "                   ,           ,                :;%  %;\n"
									 "                    :         ;                   :;%;'     .,\n"
									 "           ,.        %;     %;            ;        %;'    ,;\n"
									 "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
									 "              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
									 "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
									 "                `%;.     ;%;     %;'         `;%%;.%;'\n"
									 "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
									 "                    `:%;.  :;bd%;          %;@%;'\n"
									 "                      `@%:.  :;%.         ;@@%;'\n"
									 "                        `@%.  `;@%.      ;@@%;\n"
									 "                          `@%%. `@%%    ;@@%;\n"
									 "                            ;@%. :@%%  %@@%;\n"
									 "                              %@bd%%%bd%%:;\n"
									 "                                #@%%%%%:;;\n"
									 "                                %@@%%%::;\n"
									 "                                %@@@%(o);  . '\n"
									 "                                %@@@o%;:(.,'\n"
									 "                            `.. %@@@o%::;\n"
									 "                               `)@@@o%::;\n"
									 "                                %@@(o)::;\n"
									 "                               .%@@@@%::;\n"
									 "                               ;%@@@@%::;.\n"
									 "                              ;%@@@@%%:;;;.\n"
									 "                          ...;%@@@@@%%:;;;;,..\n";
											
		ofs << asciiTree;
		ofs.close();
	}
	else
		throw FormException("Couldn't open file " + _target + "_shrubbery\n");
}
