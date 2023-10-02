/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:46:58 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/02 12:53:28 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << RED << "Error: invalid number of arguments\nPlease enter a warning level (DEBUG, INFO, WARNING or ERROR)" << RESET << std::endl;
		return (1);
	}
	std::string warning = av[1];
	Harl	obj;
	obj.complain(warning);
	return (0);
}
