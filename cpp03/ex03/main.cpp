/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:17:58 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/25 23:44:46 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// void	printPl1Data(ClapTrap& Pl1)
// {
// 	std::cout << '\n' << GREEN << Pl1.getName() << " has "
// 			<< Pl1.getHitPoints() << " Hit Points and "
// 			<< Pl1.getEnergyPoints() << " Energy Points left" << RESET << "\n\n";
// }

// void	printPl2Data(ScavTrap& Pl2)
// {
// 	std::cout << BLUE << Pl2.getName() << " has "
// 			<< Pl2.getHitPoints() << " Hit Points and "
// 			<< Pl2.getEnergyPoints() << " Energy Points left" << RESET << "\n\n";
// }

// void	printPl3Data(FragTrap& Pl3)
// {
// 	std::cout << RED << Pl3.getName() << " has "
// 			<< Pl3.getHitPoints() << " Hit Points and "
// 			<< Pl3.getEnergyPoints() << " Energy Points left" << RESET << "\n\n";
// }

int	main(void)
{
	DiamondTrap Pl("Jochen");

	Pl.attack("enemy");
	Pl.beRepaired(10);
	return (0);
}
