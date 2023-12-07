/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:49:01 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/07 22:07:56 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	valid_test()
{
	try {
		Bureaucrat boss("Duck Dimmerdome", 1);
		Bureaucrat intern("John", 144);

		std::cout << BOLDYELLOW << "\nShrubberyCreationForm" << RESET << std::endl;

		ShrubberyCreationForm SCF("garden");
		intern.signForm(SCF);
		boss.executeForm(SCF);

		std::cout << BOLDYELLOW << "\nRobotomyRequestForm" << RESET << std::endl;

		RobotomyRequestForm RRF("Mark Zuckerberg");
		boss.signForm(RRF);
		boss.executeForm(RRF);

		std::cout << BOLDYELLOW << "\nPresidentialPardonForm" << RESET << std::endl;

		PresidentialPardonForm PPF("Evaluator");
		boss.signForm(PPF);
		boss.executeForm(PPF);
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << '\n';
	}
}

void	invalid_test()
{
	Bureaucrat boss("Duck Dimmerdome", 1);
	Bureaucrat intern("John", 144);

	std::cout << BOLDRED << "\nNot signed execution" << RESET << std::endl;

	ShrubberyCreationForm SCF("home");
	try {
		boss.executeForm(SCF);
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << '\n';
	}

	std::cout << BOLDRED << "\nAlready signed" << RESET << std::endl;

	PresidentialPardonForm PPF("Criminal");
	boss.signForm(PPF);
	try {
		boss.signForm(PPF);
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << '\n';
	}

	std::cout << BOLDRED << "\nInvalid execution rights" << RESET << std::endl;

	RobotomyRequestForm RRF("Elon Musk");
	try {
		boss.signForm(RRF);
		intern.executeForm(RRF);
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << '\n';
	}
}

int main(int ac, char **av)
{
	if (ac > 2) {
		std::cout << RED << "Only one or no arguments !" << RESET << std::endl;
		return (1);
	}
	std::srand(std::time(0));
	if (ac == 2 && std::string(av[1]) == "invalid")
		invalid_test();
	else if (ac == 1)
		valid_test();
	else
		std::cout << RED << "Please enter a valid argument" << RESET << std::endl;
	return (0);
}
