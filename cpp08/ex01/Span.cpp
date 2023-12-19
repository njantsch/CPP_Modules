/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:18:13 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/19 15:16:56 by njantsch         ###   ########.fr       */
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

void	Span::addNumbersSingle(unsigned int range, unsigned int number)
{
	if (this->_numbers.size() + range > this->_size)
		throw (std::runtime_error("Range exceeds the vector size"));
	for (unsigned int i = 0; i < range; i++)
		addNumber(number);
}

void	Span::addNumbersRange(unsigned int range, unsigned int number)
{
	if (this->_numbers.size() + range > this->_size)
		throw (std::runtime_error("Range exceeds the vector size"));
	for (unsigned int i = 0; i < range; i++)
		addNumber(number++);
}

int	Span::shortestSpan(void)
{
	if (this->_numbers.size() <= 1)
		throw (std::runtime_error("No span can be found"));
	std::vector<int> sortedNumbers(this->_numbers);
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int minDifference = INT_MAX;
	for (size_t i = 1; i < sortedNumbers.size(); i++) {
		int	difference = sortedNumbers[i] - sortedNumbers[i - 1];
		if (difference < minDifference)
			minDifference = difference;
	}
	return (minDifference);
}

int	Span::longestSpan(void)
{
	if (this->_numbers.size() <= 1)
		throw (std::runtime_error("No span can be found"));
	std::vector<int>::iterator minElement = std::min_element(this->_numbers.begin(), this->_numbers.end());
	std::vector<int>::iterator maxElement = std::max_element(this->_numbers.begin(), this->_numbers.end());
	return (*maxElement - *minElement);
}
