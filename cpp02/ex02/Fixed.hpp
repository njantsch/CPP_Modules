/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:15:34 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/22 17:04:47 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLDGREEN "\033[1m\033[32m"

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
	Fixed(const int fixedInt);
	Fixed(const float fixedFloat);
	Fixed(const Fixed& other);
	~Fixed();

// operator overloads

	// arithmetic operators
	Fixed operator+(const Fixed& other);
	Fixed operator-(const Fixed& other);
	Fixed operator*(const Fixed& other);
	Fixed operator/(const Fixed& other);

	// comparison operators
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	// pre- increment & decrement
	Fixed& operator++();
	Fixed& operator--();

	// post- increment & decrement
	Fixed operator++(int);
	Fixed operator--(int);

	// assignment operator
	Fixed& operator=(const Fixed& other);

// member functions

	int getRawBits( void ) const;
	void setRawBits( int const raw );
	int toInt( void ) const;
	float toFloat( void ) const;
	static Fixed& min(Fixed& lhs, Fixed& rhs);
	static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
	static Fixed& max(Fixed& lhs, Fixed& rhs);
	static const Fixed& max(const Fixed& lhs, const Fixed& rhs);

};

std::ostream& operator<<(std::ostream& out, const Fixed& other);

#endif
