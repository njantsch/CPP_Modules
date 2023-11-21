/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:15:34 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/21 22:33:11 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
private:
	static const int _fraction;
	int				 _fixed;
public:
	// construction and destruction
	Fixed();
	Fixed( const int fixedInt);
	Fixed( const float fixedFloat);
	Fixed(const Fixed& other);
	~Fixed();
	// operator overloads
	// arithmetic operators
	Fixed& operator+(const Fixed& other);
	Fixed& operator-(const Fixed& other);
	Fixed& operator*(const Fixed& other);
	Fixed& operator/(const Fixed& other);
	// comparison operators
	Fixed& operator>(const Fixed& other);
	Fixed& operator<(const Fixed& other);
	Fixed& operator>=(const Fixed& other);
	Fixed& operator<=(const Fixed& other);
	Fixed& operator==(const Fixed& other);
	Fixed& operator!=(const Fixed& other);
	// assignment operator
	Fixed& operator=(const Fixed& other);
	// member functions
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	int toInt( void ) const;
	float toFloat( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& other);

#endif
