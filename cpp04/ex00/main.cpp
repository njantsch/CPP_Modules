/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:13:56 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/28 16:46:24 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	Animal*	base = new Animal();
	Animal*	tiger = new Cat();
	Animal*	pudel = new Dog();

	std::cout << BOLDGREEN << "\ngetType() function...\n" << RESET << std::endl;

	std::cout << GREEN << "type for Animal class: " << base->getType() << RESET << std::endl;
	std::cout << GREEN << "type for Cat class: " << tiger->getType() << RESET << std::endl;
	std::cout << GREEN << "type for animal class: " << pudel->getType() << RESET << '\n' << std::endl;

	std::cout << BOLDYELLOW << "makeSound() function...\n" << RESET << std::endl;

	std::cout << YELLOW << "what does the " << base->getType() << " say ? -> " << RESET;
	base->makeSound();
	std::cout << YELLOW << "what does the " << tiger->getType() << " say ? -> " << RESET;
	tiger->makeSound();
	std::cout << YELLOW << "what does the " << pudel->getType() << " say ? -> " << RESET;
	pudel->makeSound();
	std::cout << std::endl;

	delete base;
	delete tiger;
	delete pudel;

	WrongAnimal*	base_w = new WrongAnimal();
	WrongAnimal*	tiger_w = new WrongCat();

	std::cout << BOLDRED << "\nWrong polymorphism...\n" << RESET << std::endl;

	std::cout << RED << "what does the " << base_w->getType() << " say ? -> " << RESET;
	base_w->makeSound();
	std::cout << RED << "what does the " << tiger_w->getType() << " say ? -> " << RESET;
	tiger_w->makeSound();
	std::cout << std::endl;

	delete base_w;
	delete tiger_w;

	return (0);
}
