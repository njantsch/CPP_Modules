/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 20:41:37 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/14 21:17:02 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <class T>
class Array
{
private:
	T* _array;
public:
	Array()
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	class OutOfBoundsException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	int& operator[](int);
	std::size_t size(void) const;
};
