/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:57:45 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/23 19:23:31 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(), y() {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point&	Point::operator=(Point& other)
{
	if (this != &other)
		return (other);
	std::cout << RED << "Error assigning the same value" << RESET << std::endl;
	return (*this);
}

Point::~Point() {}

bool	Point::operator==(const Point& other) const { return ((x == other.x && y == other.y) ? true : false); }

int	Point::getXIntValue() const { return (this->x.toInt()); }

int Point::getYIntValue() const { return (this->y.toInt()); }

float Point::getXFloatValue() const { return (this->x.toFloat()); }

float Point::getYFloatValue() const { return (this->y.toFloat()); }
