/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:32:01 by njantsch          #+#    #+#             */
/*   Updated: 2024/01/05 20:16:35 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeVector.hpp"
#include "PmergeMeDeque.hpp"

int	main(int ac, char **av)
{
	if (ac < 2) {
		std::cout << RED << "Error please enter an argument" << RESET << std::endl;
		return (1);
	}
	try {
		PmergeMeVector vec(av + 1, ac);
		vec.checkInputAndStore();
		vec.sortNumbers();
		vec.printBefore();
		vec.printAfter();
		vec.displayProcessTime();

		PmergeMeDeque deq(av + 1, ac);
		deq.checkInputAndStore();
		deq.sortNumbers();
		deq.displayProcessTime();
	}
	catch(const std::exception& e) {
		std::cout << RED << e.what() << RESET << '\n';
	}
	return (0);
}

// For testing: ./PmergeMe `jot -r 3000 1 100000 | awk '!x[$0]++'`
