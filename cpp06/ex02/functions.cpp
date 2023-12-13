/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:38:30 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/13 18:35:12 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	switch (std::rand() % 3)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	case 2:
		return (new C);
	default:
		return (NULL);
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << GREEN << "The base pointer is of type A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << GREEN << "The base pointer is of type B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << GREEN << "The base pointer is of type C" << RESET << std::endl;
	else
		std::cout << GREEN << "The base pointer is of type base" << RESET << std::endl;
}

void	identify(Base& p)
{
	Base tmp;
	try {
		tmp = dynamic_cast<A&>(p);
		std::cout << GREEN << "The base pointer is of type A" << RESET << std::endl;
	}
	catch(const std::exception& e) {
		try {
			tmp = dynamic_cast<B&>(p);
			std::cout << GREEN << "The base pointer is of type B" << RESET << std::endl;
		}
		catch(const std::exception& e) {
			try {
				tmp = dynamic_cast<C&>(p);
				std::cout << GREEN << "The base pointer is of type C" << RESET << std::endl;
			}
			catch(const std::exception& e) {
				std::cout << GREEN << "The base pointer is of type base" << RESET << std::endl;
			}
		}
	}
}
