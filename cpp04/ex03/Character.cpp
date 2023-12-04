/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:57:48 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/04 20:16:57 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("default name")
{
	this->_fIdx = 0;
	for (int i = 0; i < 200; i++)
		this->_floor[i] = NULL;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const& name)
{
	this->_name = name;
	this->_fIdx = 0;
	for (int i = 0; i < 200; i++)
		this->_floor[i] = NULL;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& other) { *this = other; }

Character& Character::operator=(const Character& other)
{
	if (this != &other) {
		this->_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			if (other._inventory[i] != NULL)
				this->_inventory[i] = other._inventory[i];
			else
				this->_inventory[i] = NULL;
		}
		return (*this);
	}
	std::cout << RED << "Error assigning the same value" << RESET << std::endl;
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
	while (this->_fIdx >= 0) {
		delete this->_floor[this->_fIdx];
		this->_fIdx--;
	}
}

std::string const& Character::getName() const { return (this->_name); }

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	std::cout << RED << "Character inventory is full !" << RESET << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3) {
		std::cout << RED << "Invalid inventory slot index" << RESET << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL) {
		std::cout << RED << "This slot is empty and can't be unequipped" << RESET << std::endl;
		return ;
	}
	if (this->_fIdx == 200) {
		std::cout << RED << "There are too many Materias on the floor ! Can't throw more trash on the ground" << RESET << std::endl;
		return ;
	}
	if (this->_inventory[idx] != NULL) {
		this->_floor[this->_fIdx++] = this->_inventory[idx];
		this->_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3) {
		std::cout << RED << "Invalid inventory slot index" << RESET << std::endl;
		return ;
	}
	if (this->_inventory[idx] == NULL) {
		std::cout << RED << "This slot is empty and can't be used" << RESET << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}
