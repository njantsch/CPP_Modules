/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:10:29 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/21 21:59:47 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << RED << "Please enter an input file as the argument" << RESET << std::endl;
		return (1);
	}
	try {
		BitcoinExchange obj;
		std::ifstream inputFile(av[1]);
		if (!inputFile.is_open())
			throw (std::runtime_error("Error: couldn't open inputfile"));
		obj.checkInput(inputFile);
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << '\n';
	}
	return (0);
}
