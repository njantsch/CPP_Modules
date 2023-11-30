/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:02:23 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/30 18:14:49 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#define RESET "\033[0m"
#define RED "\033[31m"

#include <iostream>

class AMateria
{
protected:
	std::string const _materia_type;
public:
	AMateria();
	AMateria(std::string const& type);
	AMateria(const AMateria& other);
	AMateria& operator=(const AMateria& other);
	~AMateria();

	std::string const& getType() const; //Returns materia type

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
