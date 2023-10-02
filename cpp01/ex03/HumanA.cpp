/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:31:53 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/01 14:48:09 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon& obj)
{
	name = Name;
	weapon = &obj;
}

HumanA::~HumanA() {}

void HumanA::attack( void )
{
	std::cout << name << " attacks with their weapon " << weapon->getType() << std::endl;
}
