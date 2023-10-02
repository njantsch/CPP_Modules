/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:31:53 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/02 17:20:52 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon& obj) : weapon(obj)
{
	name = Name;
}

HumanA::~HumanA() {}

void HumanA::attack( void )
{
	std::cout << name << " attacks with their weapon " << weapon.getType() << std::endl;
}
