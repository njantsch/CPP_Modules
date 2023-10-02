/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:03:13 by njantsch          #+#    #+#             */
/*   Updated: 2023/09/28 15:28:02 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *Horde;
	Horde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		Horde[i].setName(name);
		Horde[i].announce();
	}
	return (Horde);
}
