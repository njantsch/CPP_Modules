/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:57:48 by njantsch          #+#    #+#             */
/*   Updated: 2023/11/22 21:24:21 by njantsch         ###   ########.fr       */
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
	~Point();
	Fixed& operator=(const Fixed& other);
}

#endif
