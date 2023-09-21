/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:55:56 by njantsch          #+#    #+#             */
/*   Updated: 2023/09/21 16:41:06 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::pb_class_init(void)
{
	nbr_of_contacts = 0;
}

void	PhoneBook::add_function(void)
{
	Contact contact_obj;

	if (nbr_of_contacts > 7)
		nbr_of_contacts = 0;
	contact_obj.add_new_contact();
	contacts[nbr_of_contacts] = contact_obj;
	nbr_of_contacts++;
}

void	PhoneBook::display_all(void)
{
	std::string prompt;

	std::cout << BLUE << "Would you like to expand the whole information about your contact ?" << RESET << std::endl;
	std::cout << BLUE << "yes/y or no/n" << RESET << std::endl;
	while (std::getline(std::cin, prompt))
	{
		if (prompt.compare("yes") == 0 || prompt.compare("y") == 0) {
			for (int i = 0; i < 112; i++)
				std::cout << GREEN << "-" << RESET;
			std::cout << std::endl;
			for (int i = 0; i <= 7; i++)
				contacts[i].display_all_expanded(i + 1);
			break ;
		}
		else if (prompt.compare("no") == 0 || prompt.compare("n") == 0) {
			std::cout << GREEN << "---------------------------------------------" << RESET << std::endl;
			for (int it = 0; it <= 7; it++)
				contacts[it].display_contact(it + 1);
			break ;
		}
		else
			std::cout << RED << "please enter yes/y or no/n" << RESET << std::endl;
	}
}

void	PhoneBook::search_function(void)
{
	std::string	index;
	int			check;
	int			i;

	std::cout << BLUE << "Which contact would you like to be displayed ? Enter an index between 1-8 or 'all' to display all contacts" << RESET << std::endl;
	while (std::getline(std::cin, index))
	{
		check = 0;
		if (index.size() == 1 && index[0] > '0' && index[0] < '9')
			break ;
		else if (index.size() == 3 && index.compare("all") == 0) {
			check = 1;
			break ;
		}
		else
			std::cout << RED << "please enter a valid index (between 1 and 8 or type 'all')" << RESET << std::endl;
	}
	if (check == 1) {
		display_all();
	}
	else {
		i = std::atoi(index.c_str());
		i -= 1;
		std::cout << GREEN << "---------------------------------------------" << RESET << std::endl;
		contacts[i].display_contact(i + 1);
	}
}
