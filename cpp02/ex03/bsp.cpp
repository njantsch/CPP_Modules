/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:58:02 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/23 21:12:23 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	calculateArea(Point const a, Point const b, Point const c)
{
	float	area = (a.getXFloatValue() - c.getXFloatValue())
					* (b.getYFloatValue() - c.getYFloatValue())
					- (b.getXFloatValue() - c.getXFloatValue())
					* (a.getYFloatValue() - c.getYFloatValue());
	if (area < 0)
		return ((area / 2) * -1);
	return (area / 2);
}
// barycentric coordinate system
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if (point == a || point == b || point == c)
		return (false);

	float totalArea = calculateArea(a, b, c);
	float area1 = calculateArea(a, b, point);
	float area2 = calculateArea(a, c, point);
	float area3 = calculateArea(b, c, point);

	if ((area1 < 0.01 && area1 > -0.01) ||
		(area2 < 0.01 && area2 > -0.01) ||
		(area3 < 0.01 && area3 > -0.01)) {
		// Point is on the edge
		return (false);
	}
	return (totalArea == area1 + area2 + area3);
}
