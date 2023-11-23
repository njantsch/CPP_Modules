/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:15:52 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/23 11:37:01 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

// int main( void )
// {
// 	Fixed def;
// 	Fixed flt( 13.05f );
// 	Fixed dec( 5 );
// 	Fixed const flt_c( 0.05f );
// 	Fixed const dec_c( 2 );

// 	std::cout << BOLDGREEN << "\nOPERATOR OVERLOADS" << RESET << '\n' << '\n';

// 	std::cout << GREEN << "arithmetic operators" << RESET << '\n';
// 	std::cout << "flt + dec = " << (flt + dec) << '\n';
// 	std::cout << "flt - dec = " << (flt - dec) << '\n';
// 	std::cout << "flt * dec = " << (flt * dec) << '\n';
// 	std::cout << "flt / dec = " << (flt / dec) << '\n' << '\n';

// 	std::cout << GREEN << "comparison operators" << RESET << '\n';
// 	std::cout << std::boolalpha << "flt > dec = " << (flt > dec) << '\n';
// 	std::cout << std::boolalpha << "flt < dec = " << (flt < dec) << '\n';
// 	std::cout << std::boolalpha << "flt >= dec = " << (flt >= dec) << '\n';
// 	std::cout << std::boolalpha << "flt <= dec = " << (flt <= dec) << '\n';
// 	std::cout << std::boolalpha << "flt == dec = " << (flt == dec) << '\n';
// 	std::cout << std::boolalpha << "flt != dec = " << (flt != dec) << '\n' << '\n';

// 	std::cout << GREEN << "pre- increment & decrement" << RESET << '\n';
// 	std::cout << "++dec = " << (++dec) << '\n';
// 	std::cout << "--dec = " << (--dec) << '\n' << '\n';

// 	std::cout << GREEN << "post- increment & decrement" << RESET << '\n';
// 	std::cout << "increment called = " << (dec++) << '\n';
// 	std::cout << "after call = " << dec << '\n';
// 	std::cout << "decrement called = " << (dec--) << '\n';
// 	std::cout << "after call = " << dec << '\n' << '\n';

// 	std::cout << BOLDGREEN << "MEMBER FUNCTIONS" << RESET << '\n' << '\n';

// 	std::cout << GREEN << "min() max() functions" << RESET << '\n';
// 	std::cout << "min(" << flt << ", " << dec << ") = " << Fixed::min(flt, dec) << '\n';
// 	std::cout << "const min(" << flt_c << ", " << dec_c << ") = " << Fixed::min(flt_c, dec_c) << '\n';
// 	std::cout << "max(" << flt << ", " << dec << ") = " << Fixed::max(flt, dec) << '\n';
// 	std::cout << "const max(" << flt_c << ", " << dec_c << ") = " << Fixed::max(flt_c, dec_c) << '\n' << '\n';

// 	return (0);
// }
