/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:46:52 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/02 12:53:45 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::info( void ) {
	std::cout << GREEN << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << RESET << std::endl;
}

void	Harl::debug( void ) {
	std::cout << YELLOW << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << RESET << std::endl;
}

void	Harl::warning( void ) {
	std::cout << MAGENTA << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << RESET << std::endl;
}

void	Harl::error( void ) {
	std::cout << BOLDRED << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

void	Harl::complain(std::string level)
{
	void (Harl::*function_ptr[4])(void) = {&Harl::info, &Harl::debug, &Harl::warning, &Harl::error};
	std::string str_arr[4] = {"INFO", "DEBUG", "WARNING", "ERROR"};
	Harl	obj;
	for (int i = 0; i < 4; i++) {
		if (str_arr[i].compare(level) == 0) {
			(obj.*function_ptr[i])();
			return ;
		}
	}
	std::cout << RED << "Error: please enter a valid warning level (DEBUG, INFO, WARNING, or ERROR)" << RESET << std::endl;
}
