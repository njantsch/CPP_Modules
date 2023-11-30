/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:57:48 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/30 18:33:55 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const& name)
{
	std::cout << "Character name constructor called" << std::endl;
	this->_name = name;
}

Character::Character(const Character& other)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = other;
}

Character& Character::operator=(const Character& other)
{
	if (this != &other) {
		this->_name = other._name;
		return (*this);
	}
	std::cout << RED << "Error assigning the same value" << RESET << std::endl;
	return (*this);
}
