/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:02:20 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/04 19:09:02 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _materia_type("default type") {}

AMateria::AMateria(std::string const& type) { this->_materia_type = type; }

AMateria::AMateria(const AMateria& other) { *this = other; }

AMateria& AMateria::operator=(const AMateria& other)
{
	(void) other;
	return (*this);
}

AMateria::~AMateria() {}

std::string const& AMateria::getType() const { return (this->_materia_type); }

void	AMateria::use(ICharacter& target)
{
	std::cout << "* slaps " << target.getName() << " bare handed *" << std::endl;
}
