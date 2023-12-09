/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:49:01 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/09 15:54:58 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	valid_test()
{
	try {
		Bureaucrat boss("Duck Dimmerdome", 1);
		Intern someRandomIntern;
		AForm* RRF;
		AForm* SCF;
		AForm* PPF;

		RRF = someRandomIntern.makeForm("robotomy request", "Bender");
		SCF = someRandomIntern.makeForm("shrubbery creation", "Home");
		PPF = someRandomIntern.makeForm("presidential pardon", "Criminal");

		std::cout << BOLDYELLOW << "\nShrubberyCreationForm" << RESET << std::endl;

		boss.signForm(*SCF);
		boss.executeForm(*SCF);

		std::cout << BOLDYELLOW << "\nRobotomyRequestForm" << RESET << std::endl;

		boss.signForm(*RRF);
 		boss.executeForm(*RRF);

		std::cout << BOLDYELLOW << "\nPresidentialPardonForm" << RESET << std::endl;

		boss.signForm(*PPF);
		boss.executeForm(*PPF);

		delete RRF;
		delete SCF;
		delete PPF;
	}
	catch(const std::exception& e) {
		std::cerr << RED << e.what() << RESET << '\n';
	}
}

void	invalid_test()
{
	Bureaucrat boss("Duck Dimmerdome", 1);
	Intern someRandomIntern;
	AForm* PPF;

	std::cout << BOLDRED << "Form type not recognized" << RESET << std::endl;

	PPF = someRandomIntern.makeForm("ppresidential pardon", "Criminal");
	if (PPF == NULL)
		return ;
	delete PPF;
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
