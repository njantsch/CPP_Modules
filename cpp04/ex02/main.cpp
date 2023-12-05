/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:13:56 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/05 18:13:24 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{

	Animal base;
	// AAnimal base;
	std::cout << GREEN << "Type of base class " << base.getType() << RESET << std::endl;

	AAnimal* dog1 = new Dog();
	AAnimal* dog2 = new Dog();
	AAnimal* cat1 = new Cat();
	AAnimal* cat2 = new Cat();
	AAnimal* animalArr[] = {dog1, dog2, cat1, cat2};

	std::cout << BOLDGREEN << "\nArray Loop\n" << RESET << std::endl;

	for (int i = 0; i < 4; i++)
	{
		std::cout << "The animal type: " << animalArr[i]->getType()
				<< " makes the sound -> ";
		animalArr[i]->makeSound();
	}

	std::cout << BOLDYELLOW << "\nDeep Copy\n" << RESET << std::endl;

	Dog test;
	{
		Dog tmp = test;
	}
	test.makeSound();

	std::cout << BOLDRED << "\nDeletion\n" << RESET << std::endl;

	for (int i = 0; i < 4; i++) {
		delete animalArr[i];
	}
	// system("leaks Interfaces");
	return (0);
}
