/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:17:58 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/25 20:44:41 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	printPl1Data(ClapTrap Pl1)
{
	std::cout << '\n' << GREEN << Pl1.getName() << " has "
			<< Pl1.getHitPoints() << " Hit Points and "
			<< Pl1.getEnergyPoints() << " Energy Points left" << RESET << "\n\n";
}

void	printPl2Data(ScavTrap Pl2)
{
	std::cout << BLUE << Pl2.getName() << " has "
			<< Pl2.getHitPoints() << " Hit Points and "
			<< Pl2.getEnergyPoints() << " Energy Points left" << RESET << "\n\n";
}

int	main(void)
{
	ClapTrap Pl1("Lilith");
	ScavTrap Pl2("Roland");

	printPl1Data(Pl1);

	printPl2Data(Pl2);

	Pl1.attack(Pl2.getName());
	Pl2.takeDamage(Pl1.getAttackDamage());

	Pl2.attack(Pl1.getName());
	Pl1.takeDamage(Pl2.getAttackDamage());

	Pl1.attack(Pl2.getName());

	printPl1Data(Pl1);

	printPl2Data(Pl2);

	Pl2.beRepaired(12);

	Pl2.guardGate();
	Pl2.guardGate();

	printPl2Data(Pl2);

	return (0);
}
