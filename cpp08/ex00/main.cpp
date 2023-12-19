/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:40:58 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/19 15:01:58 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	int res = 0;
	try {
		std::vector<int> intVector(5);
		iota<std::vector<int>::iterator, int>(intVector.begin(), intVector.end(), 0);
		res = easyFind(intVector, 4);
		std::cout << GREEN << "Found number at index: " << res << RESET << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		std::deque<int> intDeque(100);
		iota<std::deque<int>::iterator, int>(intDeque.begin(), intDeque.end(), 0);
		res = easyFind(intDeque, 42);
		std::cout << GREEN << "Found number at index: " << res << RESET << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << '\n';
	}
	try {
		std::list<int> intList(5);
		iota<std::list<int>::iterator, int>(intList.begin(), intList.end(), 5);
		res = easyFind(intList, 1);
		std::cout << GREEN << "Found number at index: " << res << RESET << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << '\n';
	}

	return (0);
}
