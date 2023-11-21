/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:36:45 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/21 22:04:09 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fraction = 8;

Fixed::Fixed() : _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fixedInt)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = fixedInt << _fraction;
}

Fixed::Fixed(const float fixedFloat)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = roundf(fixedFloat * (1 << _fraction));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << '\n';
	if (this != &other) {
		this->_fixed = other.getRawBits();
		return (*this);
	}
	std::cout << "Error assigning the same value" << std::endl;
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Fixed& other)
{
	out << other.toFloat();
	return (out);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	return (this->_fixed);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixed = raw;
}

int Fixed::toInt() const
{
	return (this->_fixed >> this->_fraction);
}

float Fixed::toFloat() const
{
	return ((float)_fixed / (float)(1 << _fraction));
}
