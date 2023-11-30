/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:57:45 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/30 18:32:54 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string const _name;
	AMateria* inventory[4];
public:
	Character();
	Character(std::string const& name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	~Character();
};

#endif
