/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:15:34 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/01 18:05:58 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

int	main(int ac, char **av)
{
	if (ac != 4) {
		std::cout << RED << "Error: invalid number of arguments" << RESET << std::endl;
		return (1);
	}
	std::string	filename = av[1];
	File		file(av, filename);
	if (file.replace() == 1)
		return (1);
	return (0);
}
