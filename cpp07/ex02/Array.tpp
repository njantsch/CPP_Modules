/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:14:06 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/16 12:50:36 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(), _len() {}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->_array = new T[n];
	this->_len = n;
}

template <typename T>
Array<T>::Array(const Array& other)
{
	this->_len = other._len;
	this->_array = new T[this->_len];
	for (size_t i = 0; i < this->_len; i++)
		this->_array[i] = other._array[i];
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	if (this != &other) {
		delete[] this->_array;
		this->_len = other._len;
		this->_array = new T[this->_len];
		for (size_t i = 0; i < this->_len; i++)
			this->_array[i] = other._array[i];
		return (*this);
	}
	std::cout << RED << "Error assigning the same value" << RESET << std::endl;
	return (*this);
}

template <typename T>
Array<T>::~Array() { delete[] this->_array; }

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Index is out of bounds !");
}

template <typename T>
T&	Array<T>::operator[](size_t indx)
{
	if (indx >= this->_len)
		throw(OutOfBoundsException());
	return (this->_array[indx]);
}

template <typename T>
std::size_t Array<T>::size() const { return (this->_len); }

template <typename T>
void	Array<T>::printElements(void)
{
	for (size_t i = 0; i < this->_len; i++) {
		if (this->_array != NULL)
			std::cout << this->_array[i] << ", ";
	}
	std::cout << std::endl;
}
