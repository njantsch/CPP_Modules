/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:04:27 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/13 16:24:42 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : _data(0) {}

Data::Data(const int data) : _data(data) {}

Data::Data(const Data& other) { *this = other; }

Data& Data::operator=(const Data& other)
{
	if (this != &other) {
		this->_data = other.getData();
		return (*this);
	}
	std::cout << RED << "Error assigning the same value" << RESET << std::endl;
	return (*this);
}

Data::~Data() {}

int	Data::getData() const { return (this->_data); }

std::ostream&	operator<<(std::ostream& out, const Data& other)
{
	out << "data: " << other.getData() << std::endl;
	return (out);
}
