/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:54:54 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/04 19:30:27 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->_learnedMaterias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) { *this = other; }

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (this->_learnedMaterias[i] != NULL)
				delete this->_learnedMaterias[i];
			if (other._learnedMaterias[i] != NULL)
				this->_learnedMaterias[i] = other._learnedMaterias[i];
			else
				this->_learnedMaterias[i] = NULL;
		}
		return (*this);
	}
	std::cout << RED << "Error assigning the same value" << RESET << std::endl;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete this->_learnedMaterias[i];
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++) {
		if (this->_learnedMaterias[i] == NULL) {
			this->_learnedMaterias[i] = materia;
			return ;
		}
	}
	std::cout << RED << "Can't learn any more Materias" << RESET << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++) {
		if (this->_learnedMaterias[i] != NULL && this->_learnedMaterias[i]->getType() == type)
			return (this->_learnedMaterias[i]->clone());
	}
	std::cout << RED << "No matching type found for creation" << RESET << std::endl;
	return (NULL);
}
