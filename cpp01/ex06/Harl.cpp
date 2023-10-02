/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:46:52 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/02 13:28:44 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::info( void ) {
	std::cout << GREEN << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!\n" << RESET << std::endl;
}

void	Harl::debug( void ) {
	std::cout << YELLOW << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << RESET << std::endl;
}

void	Harl::warning( void ) {
	std::cout << MAGENTA << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n" << RESET << std::endl;
}

void	Harl::error( void ) {
	std::cout << BOLDRED << "[ ERROR ]\nThis is unacceptable, I want to speak to the manager now.\n" << RESET << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i;
	void (Harl::*function_ptr[4])(void) = {&Harl::info, &Harl::debug, &Harl::warning, &Harl::error};
	std::string str_arr[4] = {"INFO", "DEBUG", "WARNING", "ERROR"};
	Harl	obj;
	for (i = 0; i < 4; i++) {
		if (str_arr[i].compare(level) == 0) {
			break ;
		}
	}
	switch (i)
	{
	case 0:
		(obj.*function_ptr[0])();
	case 1:
		(obj.*function_ptr[1])();
	case 2:
		(obj.*function_ptr[2])();
	case 3:
		(obj.*function_ptr[3])();
		break;
	default:
		std::cout << RED << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
	}
}
