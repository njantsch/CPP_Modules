/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:02:23 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/05 17:55:22 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#define RESET "\033[0m"
#define RED "\033[31m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDYELLOW "\033[1m\033[33m"
#define BOLDGREEN "\033[1m\033[32m"

#include <iostream>

class ICharacter;

class AMateria
{
protected:
	std::string _materia_type;
public:
	AMateria();
	AMateria(std::string const& type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria();

	std::string const& getType() const; //Returns materia type

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
