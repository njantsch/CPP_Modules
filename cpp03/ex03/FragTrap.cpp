/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:26:03 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/25 21:25:54 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->name = "FragTrap Bot";
	this->attackDamage = 30;
	this->energyPoints = 100;
	this->hitPoints = 100;
	std::cout << "FragTrap default constructor called" << '\n';
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	this->attackDamage = 30;
	this->energyPoints = 100;
	this->hitPoints = 100;
	std::cout << "FragTrap name constructor called" << '\n';
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << '\n';
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
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

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << '\n';
}

void	FragTrap::attack(const std::string& target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0) {
		std::cout << "FragTrap: " << this->name << " used attack on " << target << " !" << '\n';
		this->energyPoints--;
	}
	else if (this->hitPoints == 0)
		std::cout << this->name << " is lacking Hit Points to attack" << '\n';
	else if (this->energyPoints == 0)
		std::cout << this->name << " is lacking Energy Points to attack" << '\n';
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << BOLDGREEN << this->name << " want's to give you a high five !" << RESET << '\n';
}
