/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:17:32 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/25 20:27:19 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("ClapTrap Bot"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
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
	std::cout << "ClapTrap destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		std::cout << "ClapTrap: " << this->name << " used attack on " << target << " !" << '\n';
		this->energyPoints--;
	}
	else if (this->hitPoints == 0)
		std::cout << this->name << " is lacking Hit Points to attack" << '\n';
	else if (this->energyPoints == 0)
		std::cout << this->name << " is lacking Energy Points to attack" << '\n';
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints == 0)
		std::cout << this->name << " is already dead !" << '\n';
	else
	{
		this->hitPoints -= amount;
		if (this->hitPoints < 0)
			this->hitPoints = 0;
		std::cout << this->name << " took " << amount << " damage !" << '\n';
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0) {
		std::cout << this->name << " used repair and restored " << amount << " of it's Hit Points" << '\n';
		this->energyPoints--;
		this->hitPoints += amount;
	}
	else
		std::cout << this->name << " is lacking Energy Points to repair" << '\n';
}

std::string	ClapTrap::getName() const { return (this->name); }

int	ClapTrap::getHitPoints() const {return (this->hitPoints); }

int	ClapTrap::getAttackDamage() const { return (this->attackDamage); }

int	ClapTrap::getEnergyPoints() const { return (this->energyPoints); }
