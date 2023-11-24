/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:47:11 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/24 13:50:00 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	return 0;
}

// int	main(void)
// {
// 	Fixed a;
// 	Fixed c;

// 	a.setRawBits(255);
// 	c.setRawBits(16);

// 	std::cout << GREEN << a.getRawBits() << RESET << '\n';
// 	std::cout << GREEN << c.getRawBits() << RESET << '\n';

// 	c = a;

// 	std::cout << GREEN << c.getRawBits() << RESET << "\n";

// 	Fixed b( c );

// 	std::cout << GREEN << b.getRawBits() << RESET << "\n";

// 	return (0);
// }
