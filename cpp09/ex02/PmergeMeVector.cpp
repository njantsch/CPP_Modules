/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:32:08 by njantsch          #+#    #+#             */
/*   Updated: 2024/01/02 18:46:53 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeVector.hpp"

PmergeMeVector::PmergeMeVector(char** input, int args) : _input(input), _args(args - 1) {}

PmergeMeVector::PmergeMeVector(const PmergeMeVector& other)
{
	*this = other;
}

PmergeMeVector& PmergeMeVector::operator=(const PmergeMeVector& other)
{
	if (this != &other) {
		this->_input = other._input;
		this->_args = other._args;
		return (*this);
	}
	std::cout << RED << "Error assigning the same value" << RESET << std::endl;
	return (*this);
}

PmergeMeVector::~PmergeMeVector() {}

bool	PmergeMeVector::isNumeric(std::string& nbr)
{
	for (std::string::iterator it = nbr.begin(); it != nbr.end(); it++) {
		if (!std::isdigit(*it))
			return (false);
	}
	return (true);
}

void	PmergeMeVector::checkNumbers(std::string& nbr)
{
	if (nbr.empty() == true) throw (std::runtime_error("Error size of argument can't be 0"));
	if (!isNumeric(nbr)) throw (std::runtime_error("Error found non numeric character"));
	if (std::atol(nbr.c_str()) > INT_MAX) throw (std::runtime_error("Error number too big"));
}

void	PmergeMeVector::checkInputAndStore(void)
{
	std::vector<std::string> inputVector;
	for (int i = 0; i < this->_args; i++)
		inputVector.push_back(this->_input[i]);
	std::vector<std::string>::iterator it = inputVector.begin();
	for (; it != inputVector.end(); it++) {
		checkNumbers(*it);
		this->_nbrVector.push_back(std::atoi(it->c_str()));
	}
}

std::vector<int>	PmergeMeVector::sortNumbers(void)
{
	int	struggler = -1;
	std::vector<std::pair<int, int> > grouped;
	std::vector<int>::iterator it = this->_nbrVector.begin();
	for (; it != this->_nbrVector.end(); it++)
	{
		if (it + 1 != this->_nbrVector.end()) {
			std::pair<int, int> tmp(*it, *(it + 1));
			grouped.push_back(tmp);
			it++;
		}
		else if (this->_nbrVector.size() % 2 != 0)
			struggler = *it;
	}
	std::cout << "struggler: " << struggler << std::endl;
	for (std::vector<std::pair<int, int> >::iterator it2 = grouped.begin(); it2 != grouped.end(); it2++)
		std::cout << "first: " << it2->first << " second: " << it2->second << std::endl;
	return (this->_nbrVector);
}
