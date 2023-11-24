/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:36:48 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/24 13:49:42 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}

// int main( void )
// {
// 	std::cout << BOLDGREEN << "\nCONSTRUCTION" << RESET << '\n' << '\n';

// 	Fixed a;
// 	Fixed const b( 10 );
// 	Fixed const c( 42.42f );
// 	Fixed const d( b );

// 	a = Fixed( 1234.4321f );

// 	std::cout << BOLDGREEN << "\nLEFT SHIFT OPERATOR" << RESET << '\n' << '\n';

// 	std::cout << "a is " << a << '\n';
// 	std::cout << "b is " << b << '\n';
// 	std::cout << "c is " << c << '\n';
// 	std::cout << "d is " << d << '\n' << '\n';

// 	std::cout << BOLDGREEN << "MEMBER FUNCTIONS" << RESET << '\n' << '\n';

// 	std::cout << GREEN << "toInt() function" << RESET << '\n';
// 	std::cout << "a is " << a.toInt() << " as integer" << '\n';
// 	std::cout << "b is " << b.toInt() << " as integer" << '\n';
// 	std::cout << "c is " << c.toInt() << " as integer" << '\n';
// 	std::cout << "d is " << d.toInt() << " as integer" << '\n' << '\n';

// 	std::cout << GREEN << "toFloat() function" << RESET << '\n';
// 	std::cout << "a is " << a.toFloat() << " as float" << '\n';
// 	std::cout << "b is " << b.toFloat() << " as float" << '\n';
// 	std::cout << "c is " << c.toFloat() << " as float" << '\n';
// 	std::cout << "d is " << d.toFloat() << " as float" << '\n' << '\n';

// 	return 0;
// }
