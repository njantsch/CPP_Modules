/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:18:04 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/19 15:22:24 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(20005);

	std::cout << BOLDGREEN << "\nValid adding of elements" << RESET << std::endl;

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	try {
		sp.addNumbersSingle(10000, 42);
		sp.addNumbersRange(10000, 5);
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << '\n';
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << BOLDRED << "\nInvalid adding of elements" << RESET << std::endl;

	try {
		sp.addNumbersRange(10, 159);
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << '\n';
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << '\n' << std::endl;

	return 0;
}
