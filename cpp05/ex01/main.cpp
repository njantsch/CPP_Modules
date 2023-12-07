/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:49:01 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/07 15:19:03 by njantsch         ###   ########.fr       */
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
	std::cout << '\n';
	try
	{
		Form formInvalid("form_invalid", 0, 150);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << '\n';
	try
	{
		intern.signForm(formImportant);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << '\n';
	try
	{
		boss.signForm(formImportant);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << BOLDGREEN << "After valid signature: "
		<< std::boolalpha << formImportant.getFormStatus()
		<< RESET << '\n' << std::endl;
	return (0);
}
