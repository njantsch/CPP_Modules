/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:35:07 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/24 13:48:21 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void	sortPoints(Point** points)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (points[j]->getXIntValue() > points[j + 1]->getXIntValue())
			{
				Point* temp = points[j];
				points[j] = points[j + 1];
				points[j + 1] = temp;
			}
		}
	}
}

void	checkBSP(Point a, Point b, Point c, Point point)
{
	if (bsp(a, b, c, point) == true) {
		for(int i = 0; i < 54; i++)
			std::cout << GREEN << '-' << RESET;
		std::cout << GREEN << "\n\tThe point is inside of the triangle 🥳" << RESET << "\n";
		for(int i = 0; i < 54; i++)
			std::cout << GREEN << '-' << RESET;
	}
	else {
		for(int i = 0; i < 55; i++)
			std::cout << RED << '-' << RESET;
		std::cout << RED << "\n\tThe point is outside of the triangle 😢" << RESET << "\n";
		for(int i = 0; i < 55; i++)
			std::cout << RED << '-' << RESET;
	}
	std::cout << '\n';
}

int	checkMultiplePointsY(Point a, Point b, Point c, Point point, int i)
{
	int	count = 0;

	if (a.getYIntValue() == i)
		count++;
	if (b.getYIntValue() == i)
		count++;
	if (c.getYIntValue() == i)
		count++;
	if (point.getYIntValue() == i)
		count++;
	return (count);
}

void	drawPoints(Point** points, Point point, Fixed maxY)
{
	int	j;
	int	largeY = maxY.toInt();

	sortPoints(points);
	std::cout << '\n';
	for (int i = 0; i < largeY + 5; i++)
	{
		j = 0;
		std::cout << i << '\t';
		for (int p = 0; p < 4; ++p)
		{
			if (points[p]->getYIntValue() == i)
			{
				int x = points[p]->getXIntValue();
				while (j++ < x)
					std::cout << ' ';
				if (x == point.getXIntValue() && i == point.getYIntValue())
					std::cout << GREEN << '.' << RESET;
				else
					std::cout << GREEN << '*' << RESET;
			}
		}
		std::cout << '\n';
	}
}

int	main(void)
{
	Point a(10.5f, 10.5f);
	Point b(30.5f, 10.5f);
	Point c(25.5f, 20.5f);
	Point point(24.5f, 15.5f);
	Point* points[] = {&a, &b, &c, &point};
	Fixed obj;
	Fixed maxY(obj.max(a.getYIntValue(), obj.max(b.getYIntValue(), c.getYIntValue())));
	drawPoints(points, point, maxY);
	checkBSP(a, b, c, point);
	return (0);
}
