/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:49:01 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/09 15:30:28 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat intern("John", 150);
	Bureaucrat boss("Duck Dimmerdome", 1);
	Form formImportant("important form", 5, 1);
	Form formStandard("standard form", 150, 140);
	std::cout << GREEN << formImportant << RESET;
	std::cout << GREEN << formStandard << RESET;
	// ------------------------------------------------------------------------
	std::cout << BOLDRED << "\nInvalid grade initialize" << RESET << std::endl;
	try
	{
		Form formInvalid("form_invalid", 0, 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	// ------------------------------------------------------------------------
	std::cout << BOLDRED << "\nInvalid signing" << RESET << std::endl;
	try
	{
		intern.signForm(formImportant);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	// ------------------------------------------------------------------------
	std::cout << BOLDGREEN << "\nValid signing" << RESET << std::endl;
	try
	{
		boss.signForm(formImportant);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << GREEN << "After valid signature: " << formImportant << RESET << std::endl;
	return (0);
}
