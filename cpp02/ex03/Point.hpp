/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:57:48 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/23 19:20:30 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class	Point
{
private:
	const Fixed x;
	const Fixed y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point& other);
	Point& operator=(Point& other);
	~Point();

	bool operator==(const Point& other) const;
	int getXIntValue(void) const;
	int getYIntValue(void) const;
	float getXFloatValue(void) const;
	float getYFloatValue(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
