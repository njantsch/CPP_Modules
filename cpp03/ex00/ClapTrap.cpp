/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:42:45 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/27 13:09:59 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Bot"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other) {
		this->name = other.name;
		this->attackDamage = other.attackDamage;
		this->energyPoints = other.energyPoints;
		this->hitPoints = other.hitPoints;
		return (*this);
	}
	std::cout << RED << "Error assigning the same value" << RESET << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		std::cout << this->name << " used attack on " << target << " !" << std::endl;
		this->energyPoints--;
	}
	else if (this->hitPoints == 0)
		std::cout << this->name << " is lacking Hit Points to attack" << std::endl;
	else if (this->energyPoints == 0)
		std::cout << this->name << " is lacking Energy Points to attack" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
		std::cout << this->name << " is already dead !" << std::endl;
	else
	{
		this->hitPoints -= amount;
		if (this->hitPoints < 0)
			this->hitPoints = 0;
		std::cout << this->name << " took " << amount << " damage !" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0) {
		std::cout << this->name << " used repair and restored " << amount << " of it's Hit Points" << std::endl;
		this->energyPoints--;
		this->hitPoints += amount;
	}
	else
		std::cout << this->name << " is lacking Energy Points to repair" << std::endl;
}

std::string	ClapTrap::getName() const { return (this->name); }

int	ClapTrap::getHitPoints() const {return (this->hitPoints); }

int	ClapTrap::getAttackDamage() const { return (this->attackDamage); }

int	ClapTrap::getEnergyPoints() const { return (this->energyPoints); }
