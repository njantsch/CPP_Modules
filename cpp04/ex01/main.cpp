/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:13:56 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/05 18:13:31 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	Animal*	dog1 = new Dog();
	Animal* dog2 = new Dog();
	Animal* cat1 = new Cat();
	Animal* cat2 = new Cat();
	Animal* animalArr[] = {dog1, dog2, cat1, cat2};

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
