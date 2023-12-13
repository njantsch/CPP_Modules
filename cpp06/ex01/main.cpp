/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:50:28 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/13 16:27:57 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data obj(42);
	Data* converted_obj;
	uintptr_t address = 0;

	std::cout << GREEN << "obj data before conversion: " << obj << RESET;
	std::cout << GREEN << "obj address before conversion: " << &obj << RESET << std::endl;
	std::cout << GREEN << "address before conversion: " << address << RESET << std::endl;

	address = Serializer::serialize(&obj);

	std::cout << GREEN << "address now stores the address of obj: " << &address << RESET << std::endl;

	converted_obj = Serializer::deserialize(address);

	std::cout << BOLDGREEN << "pointer after conversion: " << *converted_obj << RESET;
	std::cout << BOLDGREEN << "pointer address after conversion: " << converted_obj << RESET << std::endl;

	return (0);
}
