/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:02:25 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/04 19:09:48 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria() { this->_materia_type = "cure"; }

Cure::Cure(const Cure& other) : AMateria(other) { this->_materia_type = other._materia_type; }

Cure& Cure::operator=(const Cure& other)
{
	(void) other;
	return (*this);
}

Cure::~Cure() {}

AMateria* Cure::clone() const { return (new Cure(*this)); }

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
