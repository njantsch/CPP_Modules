/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:41:34 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/15 13:29:07 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.tpp"

int	main(void)
{
	Array<int> nbrs(5);
	Array<std::string> strings(3);

	for (int i = 0; i < 5; i++) {
		nbrs[i] = i;
	}
	strings[0] = "hello";
	strings[1] = "you";
	strings[2] = "there";

	std::cout << BOLDGREEN << "\nArray" << RESET << std::endl;

	strings.printElements();
	nbrs.printElements();

	std::cout << BOLDGREEN << "\nsize() function" << RESET << std::endl;

	std::cout << nbrs.size() << std::endl;
	std::cout << strings.size() << std::endl;

	std::cout << BOLDRED << "\nIndex out of bounds" << RESET << std::endl;

	try {
		strings[23232];
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return (0);
}
