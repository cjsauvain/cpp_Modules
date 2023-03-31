/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:08:17 by jsauvain          #+#    #+#             */
/*   Updated: 2023/03/15 15:09:58 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void	edit_file_replace(std::string file_replace_content, std::string s1,
	std::string s2, std::string argv1)
{
	std::string		file_replace_name = argv1 + ".replace";
	std::ofstream	ofs(file_replace_name.c_str());
	size_t			i;
	size_t			j;

	i = file_replace_content.find(s1);
	j = 0;
	while (i != std::string::npos && !s1.empty() && !file_replace_content.empty())
	{
		j = file_replace_content.rfind(s1, i);
		file_replace_content.erase(i, s1.length());
		file_replace_content.insert(i, s2);
		j += s2.length();
		i = file_replace_content.find(s1, j);
	}
	ofs << file_replace_content;
	ofs.close();
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string		s1 = argv[2];
		std::string		s2 = argv[3];
		std::string 	file_replace_content;
		std::ifstream	ifs(argv[1]);
		
		if (ifs.is_open() == true)
		{
			std::getline(ifs, file_replace_content, '\0');
			edit_file_replace(file_replace_content, s1, s2, argv[1]);
			ifs.close();
		}
		else
			std::cout << "Error: cannot open file" << std::endl;
	}
	else
		std::cout << "Wrong number of arguments" << std::endl;
}
