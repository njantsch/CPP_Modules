/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:15:34 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/02 17:54:58 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

int	file_checks(char **av)
{
	std::ifstream fd;
	std::string line;
	std::string whole_line;
	size_t	check;
	size_t	index;

	fd.open(av[1]);
	if (!fd)
		return (std::cout << RED << "Error opening file\n" << RESET, 1);
	std::getline(fd, line);
	if (line.empty())
		return (fd.close(), std::cout << RED << "Error: file is empty\n" << RESET, 1);
	else {
		if (line.find(av[2], 0) != std::string::npos)
			return (fd.close(), 0);
		while (std::getline(fd, line)) {
			whole_line.append(line);
			whole_line.append("\n");
		}
		if (whole_line.find(av[2], 0) == std::string::npos)
			return (fd.close(), std::cout << RED << "Error: please enter an existing character or substring to be replaced\n" << RESET, 1);
	}
	fd.close();
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 4) {
		std::cout << RED << "Error: invalid number of arguments" << RESET << std::endl;
		return (1);
	}
	if (file_checks(av) == 1)
		return (1);
	std::string	filename = av[1];
	File		file(av, filename);
	if (file.replace() == 1)
		return (1);
	return (0);
}
