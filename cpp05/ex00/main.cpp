/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:49:01 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/09 15:01:33 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat worker("John", 150);
	Bureaucrat boss("Duck Dimmerdome", 1);
	Bureaucrat intern(worker);
	std::cout << GREEN << worker << RESET;
	std::cout << GREEN << boss << RESET;
	std::cout << GREEN << intern << RESET;
	// ------------------------------------------------------------------------
	std::cout << BOLDRED << "\nInvalid grade initialize" << RESET << std::endl;
	try {
		Bureaucrat impostor("sus", 0);
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << '\n';
	}
	// ------------------------------------------------------------------------
	std::cout << BOLDRED << "\nInvalid increment" << RESET << std::endl;
	try {
		boss.incrementGrade();
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << GREEN << "After exception: " << boss << RESET;
	// ------------------------------------------------------------------------
	std::cout << BOLDRED << "\nInvalid decrement" << RESET << std::endl;
	try {
		intern.decrementGrade();
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << GREEN << "After exception: " << intern << RESET;
	// ------------------------------------------------------------------------
	std::cout << BOLDGREEN << "\nValid increment" << RESET << std::endl;
	try {
		worker.incrementGrade();
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << GREEN << "After valid increment: " << worker << RESET;
	return (0);
}
