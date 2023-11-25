/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:42:51 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/25 20:25:18 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap Pl1("Lilith");
	ClapTrap Pl2("Roland");

	Pl1.attack(Pl2.getName());
	Pl2.takeDamage(Pl1.getAttackDamage());

	Pl2.beRepaired(12);

	std::cout << '\n' << GREEN << Pl1.getName() << " has "
			<< Pl1.getHitPoints() << " Hit Points and "
			<< Pl1.getEnergyPoints() << " Energy Points left" << RESET << "\n\n";

	std::cout << BLUE << Pl2.getName() << " has "
			<< Pl2.getHitPoints() << " Hit Points and "
			<< Pl2.getEnergyPoints() << " Energy Points left" << RESET << "\n\n";

	return (0);
}
