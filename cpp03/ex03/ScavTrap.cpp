/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:21:39 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/27 13:52:56 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->name = "ScavTrap Bot";
	this->attackDamage = 20;
	this->energyPoints = 50;
	this->hitPoints = 100;
	this->gateKeeperMode = 0;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->attackDamage = 20;
	this->energyPoints = 50;
	this->hitPoints = 100;
	this->gateKeeperMode = 0;
	std::cout << "ScavTrap name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other) {
		this->name = other.name;
		this->attackDamage = other.attackDamage;
		this->energyPoints = other.energyPoints;
		this->hitPoints = other.hitPoints;
		this->gateKeeperMode = other.gateKeeperMode;
		return (*this);
	}
	std::cout << RED << "Error assigning the same value" << RESET << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		std::cout << "ScavTrap: " << this->name << " used attack on " << target << " !" << std::endl;
		this->energyPoints--;
	}
	else if (this->hitPoints == 0)
		std::cout << "ScavTrap: " << this->name << " is lacking Hit Points to attack" << std::endl;
	else if (this->energyPoints == 0)
		std::cout << "ScavTrap: " << this->name << " is lacking Energy Points to attack" << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->gateKeeperMode)
		std::cout << this->name << " is already in gate keeper mode" << std::endl;
	else {
		this->gateKeeperMode = true;
		std::cout << this->name << " is now in gate keeper mode" << std::endl;
	}
}
