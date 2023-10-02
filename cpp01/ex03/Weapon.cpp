/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:32:03 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/01 14:10:14 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string Weapon )
{
	type = Weapon;
}

Weapon::~Weapon() {}

const std::string&	Weapon::getType( void )
{
	return (type);
}

void	Weapon::setType( std::string _type )
{
	type = _type;
}
