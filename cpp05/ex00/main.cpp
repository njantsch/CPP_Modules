/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:49:01 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/06 15:39:34 by njantsch         ###   ########.fr       */
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
	try
	{
		boss.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << BOLDGREEN << "After exception: " << boss << RESET;
	try
	{
		intern.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << BOLDGREEN << "After exception: " << intern << RESET;
	try
	{
		worker.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	std::cout << BOLDGREEN << "After valid increment: " << worker << RESET;
	return (0);
}
