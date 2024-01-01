/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasjantsch <nicolasjantsch@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:43:13 by nicolasjant       #+#    #+#             */
/*   Updated: 2023/12/31 21:35:41 by nicolasjant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char** av)
{
	if (ac != 2) {
		std::cout << RED << "Error: please enter only or at least one argument" << RESET << std::endl;
		return (1);
	}
	try {
		std::string input(av[1]);
		RPN obj(input);
		obj.evaluate();
	}
	catch(const std::exception& e) {
		std::cout << RED << e.what() << RESET << '\n';
	}
	return (0);
}
