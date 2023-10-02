/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:01:45 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/01 18:27:32 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File(char **av, std::string file) : outfile(file + ".replace")
{
	filename = file;
	s1 = av[2];
	s2 = av[3];
}

File::~File()
{
	infile.close();
	outfile.close();
}

int	File::replace( void )
{
	std::string		line;
	size_t			index = 0;

	infile.open(filename);
	if (!infile) {
		std::cout << RED << "Error opening file" << RESET << std::endl;
		return (1);
	}
	if (!outfile)
	{
		std::cout << RED << "Error creating an outfile" << RESET << std::endl;
		return (1);
	}
	if (infile && outfile) {
		while (std::getline(infile, line)) {
			while (true) {
				index = line.find(s1, index); // find position of substr and store it in index
				if (index == std::string::npos) // if no matches were found: break
					break ;
				line.erase(index, s1.length()); // erase the substring from position index to length of s1
				line.insert(index, s2); // insert new replaced substring at position of old substring
				index += s2.length(); // move index so it won't get stuck at the substring we just added
			}
			outfile << line << "\n";
			index = 0;
		}
	}
	else {
		std::cout << RED << "Error: cannot read from file" << RESET << std::endl;
		return (1);
	}
	return (0);
}
