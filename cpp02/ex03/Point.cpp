/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:57:45 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/22 21:35:49 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() {}

Point::Point(const float x, const float y) { this->x(x); this->y(y); }

Point::Point(const Point& other) { *this = other; }

Point&	Point::operator=(const Point& other)
{
	if (this != &other) {
		this->x = other.x;
		this->y = other.y;
		return (*this);
	}
	std::cout << RED << "Error assigning the same value" << RESET << std::endl;
	return (*this);
}
