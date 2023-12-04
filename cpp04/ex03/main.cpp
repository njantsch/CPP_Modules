/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:02:37 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/04 20:38:32 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

void	test_extended()
{
	IMateriaSource* lexicon = new MateriaSource();
	lexicon->learnMateria(new Ice());
	lexicon->learnMateria(new Cure());
	lexicon->learnMateria(new Ice());
	lexicon->learnMateria(new Cure());

	std::cout << BOLDRED << "\ninvalid (no space)" << RESET << std::endl;
	AMateria* tmp;
	tmp = new Ice();
	lexicon->learnMateria(tmp);
	delete tmp;

	ICharacter* nico = new Character("nico");
	ICharacter* eval = new Character("evaluator");

	std::cout << BOLDRED << "\ninvalid type" << RESET << std::endl;
	nico->equip(lexicon->createMateria("sword"));

	AMateria* ice(new Ice());
	AMateria* cure(new Cure());

	nico->equip(ice);
	nico->equip(lexicon->createMateria("ice"));
	nico->equip(lexicon->createMateria("ice"));
	nico->equip(lexicon->createMateria("ice"));

	std::cout << BOLDRED << "\ninvalid (no room in inventory)" << RESET << std::endl;
	AMateria* tmp2(new Ice());
	nico->equip(tmp2);

	nico->unequip(3);
	nico->equip(tmp2);
	nico->unequip(2);
	nico->unequip(1);
	nico->equip(lexicon->createMateria("ice"));
	nico->equip(lexicon->createMateria("cure"));

	eval->equip(cure);

	std::cout << BOLDRED << "\ninvalid index" << RESET << std::endl;
	nico->use(-1, *eval);
	eval->use(4, *nico);
	std::cout << std::endl;

	for (int i = 0; i < 4; i++) {
		nico->use(i, *eval);
		eval->use(i, *nico);
	}

	delete lexicon;
	delete nico;
	delete eval;
}

void	test_subj()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
}

int main(int ac, char **av)
{
	if (ac > 2) {
		std::cout << RED << "Only one or no arguments !" << RESET << std::endl;
		return (1);
	}
	if (ac == 2 && std::string(av[1]) == "1")
		test_extended();
	else if (ac == 1)
		test_subj();
	else
		std::cout << RED << "Please enter a valid argument" << RESET << std::endl;
	// system("leaks Interfaces");
	return (0);
}
