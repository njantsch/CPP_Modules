/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:31:57 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/01 14:53:55 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string Name)
{
	name = Name;
	weapon = nullptr;
}

HumanB::~HumanB() {}

void HumanB::attack( void )
{
	if (!weapon)
		std::cout << name << " can't attack because he has no weapon" << std::endl;
	else
		std::cout << name << " attacks with their weapon " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& obj)
{
	weapon = &obj;
}
