/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:17:58 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/27 13:06:37 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

void	printPl1Data(ClapTrap& Pl1)
{
	std::cout << '\n' << GREEN << Pl1.getName() << " has "
			<< Pl1.getHitPoints() << " Hit Points and "
			<< Pl1.getEnergyPoints() << " Energy Points left" << RESET << "\n\n";
}

void	printPl2Data(ScavTrap& Pl2)
{
	std::cout << BLUE << Pl2.getName() << " has "
			<< Pl2.getHitPoints() << " Hit Points and "
			<< Pl2.getEnergyPoints() << " Energy Points left" << RESET << "\n\n";
}

void	printPl3Data(FragTrap& Pl3)
{
	std::cout << RED << Pl3.getName() << " has "
			<< Pl3.getHitPoints() << " Hit Points and "
			<< Pl3.getEnergyPoints() << " Energy Points left" << RESET << "\n\n";
}

int	main(void)
{
	ClapTrap Pl1("Lilith");
	ScavTrap Pl2("Roland");
	FragTrap Pl3("Handsome Jack");

	printPl1Data(Pl1);
	printPl2Data(Pl2);
	printPl3Data(Pl3);

	for (int i = 1; (Pl1.getHitPoints() > 0
		|| Pl2.getHitPoints() > 0)
		&& Pl3.getHitPoints() > 0; ++i)
	{
		if (i % 2 == 0)
		{
			std::cout << '\n' << BOLDRED << Pl3.getName() << " strikes back !" << RESET << "\n\n";

			Pl3.attack(Pl1.getName());
			if (Pl3.getHitPoints() > 0)
				Pl1.takeDamage(Pl3.getAttackDamage());

			Pl3.attack(Pl2.getName());
			if (Pl3.getHitPoints() > 0)
				Pl2.takeDamage(Pl3.getAttackDamage());

			printPl1Data(Pl1);
			printPl2Data(Pl2);
		}
		else
		{
			std::cout << '\n' << BOLDYELLOW << Pl1.getName() << "'s and " << Pl2.getName() << "'s turn !" << RESET << "\n\n";

			Pl1.attack(Pl3.getName());
			if (Pl1.getHitPoints() > 0)
				Pl3.takeDamage(Pl1.getAttackDamage());

			Pl2.attack(Pl3.getName());
			if (Pl2.getHitPoints() > 0)
				Pl3.takeDamage(Pl2.getAttackDamage());

			std::cout << '\n';
			printPl3Data(Pl3);
		}
	}
	Pl3.highFivesGuys();
	std::cout << std::endl;
	return (0);
}
