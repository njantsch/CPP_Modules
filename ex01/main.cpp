/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 18:12:40 by njantsch          #+#    #+#             */
/*   Updated: 2023/09/20 17:51:21 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	print_help(void)
{
	std::cout << BLUE << "--------------------------------------------------" << RESET << std::endl;
	std::cout << BLUE << "| ADD/add : adds a new contact to your phonebook |" << RESET << std::endl;
	std::cout << BLUE << "|------------------------------------------------|" << RESET << std::endl;
	std::cout << BLUE << "| SEARCH/search : displays a saved contact       |" << RESET << std::endl;
	std::cout << BLUE << "|------------------------------------------------|" << RESET << std::endl;
	std::cout << BLUE << "| EXIT/exit : exits the programm                 |" << RESET << std::endl;
	std::cout << BLUE << "--------------------------------------------------" << RESET << std::endl;
}

int	exit_function(void)
{
	std::string exit_prompt;

	std::cout << RED << "❗ All data will be lost, are you sure you want to exit ? ❗" << RESET << std::endl;
	std::cout << RED << "                      yes/y or no/n" << RESET << std::endl;
	while (1)
	{
		std::getline(std::cin, exit_prompt);
		if (exit_prompt.compare("yes") == 0 || exit_prompt.compare("y") == 0)
			return (1);
		else if (exit_prompt.compare("no") == 0 || exit_prompt.compare("n") == 0)
			return (0);
		else
			std::cout << RED << "please enter yes/y or no/n" << RESET << std::endl;
	}
}

int main(void)
{
	PhoneBook	phone_obj;
	std::string	prompt;

	phone_obj.pb_class_init();
	std::cout << BLUE << "----------------------------------------------------------------------------------" << RESET << std::endl;
	std::cout << BLUE << "|			    Welcome to my Phonebook !				 |" << RESET << std::endl;
	std::cout << BLUE << "| If you need any help, you can see the commands by typing 'help' in the console |" << RESET << std::endl;
	std::cout << BLUE << "----------------------------------------------------------------------------------" << RESET << std::endl;
	while (1)
	{
		std::cout << BLUE << "Please enter a command..." << RESET << std::endl;
		std::getline(std::cin, prompt);
		if (prompt.compare("help") == 0)
			print_help();
		else if (prompt.compare("ADD") == 0 || prompt.compare("add") == 0)
			phone_obj.add_function();
		else if (prompt.compare("SEARCH") == 0 || prompt.compare("search") == 0)
			phone_obj.search_function();
		else if (prompt.compare("EXIT") == 0 || prompt.compare("exit") == 0) {
			if (exit_function() == 1)
				break ;
		}
		else
			std::cout << RED << "please enter a valid command, see help for more info" << RESET << std::endl;
	}
	std::cout << RED << "exiting..." << RESET << std::endl;
	return (0);
}
