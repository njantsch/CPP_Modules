/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:52:36 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/22 20:53:33 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fraction = 8;

// construction & destruction
Fixed::Fixed() : _fixed(0) {}

Fixed::Fixed(const int fixedInt) { this->_fixed = fixedInt << _fraction; }

Fixed::Fixed(const float fixedFloat) { this->_fixed = roundf(fixedFloat * (1 << _fraction)); }

Fixed::Fixed(const Fixed& other) { *this = other; }

Fixed::~Fixed() {}

// member functions
int				Fixed::getRawBits() const { return (this->_fixed); }

void			Fixed::setRawBits(int const raw) { this->_fixed = raw; }

int				Fixed::toInt() const { return (this->_fixed >> this->_fraction); }

float			Fixed::toFloat() const { return ((float)_fixed / (float)(1 << _fraction)); }

Fixed&			Fixed::min(Fixed& lhs, Fixed& rhs) { return ((lhs._fixed < rhs._fixed) ? lhs : rhs); }

Fixed&			Fixed::max(Fixed& lhs, Fixed& rhs) { return ((lhs._fixed > rhs._fixed) ? lhs : rhs); }

const Fixed&	Fixed::min(const Fixed& lhs, const Fixed& rhs)
{
	return ((lhs._fixed < rhs._fixed) ? lhs : rhs);
}

const Fixed&	Fixed::max(const Fixed& lhs, const Fixed& rhs)
{
	return ((lhs._fixed > rhs._fixed) ? lhs : rhs);
}

// assignment operator overload
Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other) {
		this->_fixed = other.getRawBits();
		return (*this);
	}
	std::cout << RED << "Error assigning the same value" << RESET << std::endl;
	return (*this);
}

// left shift operator overload
std::ostream& operator<<(std::ostream& out, const Fixed& other)
{
	out << other.toFloat();
	return (out);
}

// arithmetic operator overloads
Fixed	Fixed::operator+(const Fixed& other) { return (Fixed(toFloat() + other.toFloat())); }

Fixed	Fixed::operator*(const Fixed& other) { return (Fixed(toFloat() * other.toFloat())); }

Fixed	Fixed::operator-(const Fixed& other) { return (Fixed(toFloat() - other.toFloat())); }

Fixed	Fixed::operator/(const Fixed& other)
{
	if ((!this->_fixed && !other._fixed) || !other._fixed) {
		std::cout << RED << "Error division by 0 not possible" << RESET << std::endl;
		return (*this);
	}
	return (Fixed(toFloat() / other.toFloat()));
}

// comparison operator overloads
bool	Fixed::operator>(const Fixed& other) const { return ((this->_fixed > other._fixed) ? true : false); }

bool	Fixed::operator<(const Fixed& other) const { return ((this->_fixed < other._fixed) ? true : false); }

bool	Fixed::operator>=(const Fixed& other) const { return ((this->_fixed >= other._fixed) ? true : false); }

bool	Fixed::operator<=(const Fixed& other) const { return ((this->_fixed <= other._fixed) ? true : false); }

bool	Fixed::operator==(const Fixed& other) const { return ((this->_fixed == other._fixed) ? true : false); }

bool	Fixed::operator!=(const Fixed& other) const { return ((this->_fixed != other._fixed) ? true : false); }

// pre- increment & decrement (++fixed && --fixed)
Fixed&	Fixed::operator++() { return (++this->_fixed, *this); }

Fixed&	Fixed::operator--() { return (--this->_fixed, *this); }

// post- increment & decrement (fixed++ && fixed--)
Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->_fixed;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->_fixed;
	return (temp);
}
