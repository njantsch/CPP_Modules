/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:02:20 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/30 17:16:23 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type)
{
	std::cout << "AMateria type constructor called" << std::endl;
	this->_materia_type = type;
}

AMateria::AMateria(const AMateria& other)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = other;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	this->_materia_type = other._materia_type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const& AMateria::getType() const { return (this->_materia_type) }

void	AMateria::use(ICharacter& target)
{
	std::cout << "* slaps " << target.getName() << " bare handed *" << std::endl;
}
