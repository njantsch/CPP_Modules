/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:18:13 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/16 18:55:04 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size() {}

Span::Span(unsigned int n) : _size(n) {}

Span::Span(const Span& other) : _size(other._size), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other) {
		this->_numbers = other._numbers;
		this->_size = other._size;
		return (*this);
	}
	std::cout << RED << "Error assigning the same value" << RESET << std::endl;
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(unsigned int n)
{
	if (this->_numbers.size() == this->_size)
		throw (std::runtime_error("Span has already stored the maximum amount of integers"));
	this->_numbers.push_back(n);
}

int	Span::shortestSpan(void)
{
	return (0);
}

int	Span::longestSpan(void)
{
	if (this->_numbers.size() <= 1)
		throw (std::runtime_error("No span can be found"));
	std::pair <std::vector<int>::iterator,std::vector<int>::iterator> minmax(std::minmax_element(this->_numbers.begin(), this->_numbers.end()));
	std::cout << this->_numbers.size() << std::endl;
	std::cout << *minmax.second << std::endl;
	std::cout << *minmax.first << std::endl;
	return (*minmax.second - *minmax.first);
}
