/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:15:32 by njantsch          #+#    #+#             */
/*   Updated: 2023/09/26 13:17:18 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string	check_contact_string(std::string str)
{
	std::string contact_prompt;
	std::string::iterator it;
	int	check;

	fflush(stdin);
	while (std::getline(std::cin, contact_prompt))
	{
		check = 0;
		for (it = contact_prompt.begin(); it != contact_prompt.end(); it++) {
			if (str.compare("Phone number: ") == 0 && std::isdigit(*it) == 0) {
				check = 2;
				break ;
			}
			if (std::isalnum(*it) == 0 && str.compare("Darkest secret 😈: ") != 0) {
				check = 1;
				break ;
			}
		}
		if (!contact_prompt.size()) {
			std::cout << RED << "Please put something in the prompt" << RESET << std::endl;
			std::cout << str;
		}
		else if (check == 2 || (str.compare("Phone number: ") == 0 && contact_prompt.size() > 15)) {
			std::cout << RED << "Please input a valid number" << RESET << std::endl;
			std::cout << str;
		}
		else if (check == 1) {
			std::cout << RED << "Please use only numbers or letters" << RESET << std::endl;
			std::cout << str;
		}
		else
			break ;
	}
	return (contact_prompt);
}

void	Contact::display_contact(int index)
{
	std::cout << GREEN << "|" << RESET << std::setfill(' ') << std::setw(10) << index;
	if (first_name.size() > 10)
		std::cout << GREEN << "|" << RESET << first_name.substr(0, 9) << ".";
	else
		std::cout << GREEN << "|" << RESET << std::setw(10) << first_name;
	if (last_name.size() > 10)
		std::cout << GREEN << "|" << RESET << last_name.substr(0, 9) << ".";
	else
		std::cout << GREEN << "|" << RESET << std::setw(10) << last_name;
	if (nickname.size() > 10)
		std::cout << GREEN << "|" << RESET << nickname.substr(0, 9) << "." << GREEN << "|" << RESET << std::endl;
	else
		std::cout << GREEN << "|" << RESET << std::setw(10) << nickname << GREEN << "|" << RESET << std::endl;
	std::cout << GREEN << "---------------------------------------------" << RESET << std::endl;
}

void	Contact::display_all_expanded(int index)
{
	std::cout << GREEN << "|" << RESET << std::setfill(' ') << std::setw(10) << index;
	if (first_name.size() > 10)
		std::cout << GREEN << "|" << RESET << first_name.substr(0, 9) << ".";
	else
		std::cout << GREEN << "|" << RESET << std::setw(10) << first_name;
	if (last_name.size() > 10)
		std::cout << GREEN << "|" << RESET << last_name.substr(0, 9) << ".";
	else
		std::cout << GREEN << "|" << RESET << std::setw(10) << last_name;
	if (nickname.size() > 10)
		std::cout << GREEN << "|" << RESET << nickname.substr(0, 9) << ".";
	else
		std::cout << GREEN << "|" << RESET << std::setw(10) << nickname;
	std::cout << GREEN << "|" << RESET << std::setw(15) << phone_number;
	if (dark_secret.size() > 50)
		std::cout << GREEN << "|" << RESET << dark_secret.substr(0, 49) << "." << GREEN << "|" << RESET << std::endl;
	else
		std::cout << GREEN << "|" << RESET << std::setw(50) << dark_secret << GREEN << "|" << RESET << std::endl;
	for (int i = 0; i < 112; i++)
		std::cout << GREEN << "-" << RESET;
	std::cout << std::endl;
}

void	Contact::add_new_contact(void)
{
	std::cout << BLUE << "Please enter the information below" << RESET << std::endl;
	std::cout << BLUE << "----------------------------------" << RESET << std::endl;
	std::cout << "First name: "; first_name = check_contact_string("First name: ");
	std::cout << "Last name: "; last_name = check_contact_string("Last name: ");
	std::cout << "Nickname: "; nickname = check_contact_string("Nickname: ");
	std::cout << "Phone number: "; phone_number = check_contact_string("Phone number: ");
	std::cout << "Darkest secret 😈: "; dark_secret = check_contact_string("Darkest secret 😈: ");
	std::cout << BLUE << "----------------------------------" << RESET << std::endl;
}
