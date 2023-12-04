/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:02:30 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/04 19:09:30 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria() { this->_materia_type = "ice"; }

Ice::Ice(const Ice& other) : AMateria(other) { this->_materia_type = other._materia_type; }

Ice& Ice::operator=(const Ice& other)
{
	(void) other;
	return (*this);
}

Ice::~Ice() {}

AMateria* Ice::clone() const { return (new Ice(*this)); }

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
