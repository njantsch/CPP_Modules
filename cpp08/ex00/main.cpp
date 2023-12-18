/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:40:58 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/18 20:05:45 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int> intVector(5);
	iota(intVector.begin(), intVector.end(), 1);
	easyFind(intVector, 4);
	try {
		std::list<int> intList(5);
		iota(intList.begin(), intList.end(), 5);
		easyFind(intList, 1);
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << '\n';
	}
	return (0);
}
