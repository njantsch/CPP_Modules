/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:17:58 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/27 17:13:58 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	printPl1Data(DiamondTrap& Pl1)
{
	std::cout << '\n' << GREEN << Pl1.getName() << " has "
			<< Pl1.getHitPoints() << " Hit Points, "
			<< Pl1.getEnergyPoints() << " Energy Points and "
			<< Pl1.getAttackDamage() << " Attack Damage" << RESET << "\n\n";
}

int	main(void)
{
	DiamondTrap Pl("Jochen");

	printPl1Data(Pl);

	Pl.attack("enemy");
	Pl.takeDamage(10);
	Pl.beRepaired(10);
	Pl.guardGate();
	Pl.highFivesGuys();
	Pl.whoAmI();
	return (0);
}
