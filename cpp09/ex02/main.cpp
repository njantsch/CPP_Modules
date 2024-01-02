/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:32:01 by njantsch          #+#    #+#             */
/*   Updated: 2024/01/02 17:23:57 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeVector.hpp"

int	main(int ac, char **av)
{
	if (ac < 2) {
		std::cout << RED << "Error please enter an argument" << RESET << std::endl;
		return (1);
	}
	try {
		PmergeMeVector obj(av + 1, ac);
		obj.checkInputAndStore();
		std::vector<int> res(obj.sortNumbers());
	}
	catch(const std::exception& e) {
		std::cout << RED << e.what() << RESET << '\n';
	}
	return (0);
}