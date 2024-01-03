/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:32:08 by njantsch          #+#    #+#             */
/*   Updated: 2024/01/03 17:08:09 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeVector.hpp"

PmergeMeVector::PmergeMeVector(char** input, int args)
	: _input(input), _args(args - 1), _straggler(-1) {}

PmergeMeVector::PmergeMeVector(const PmergeMeVector& other)
{
	*this = other;
}

PmergeMeVector& PmergeMeVector::operator=(const PmergeMeVector& other)
{
	if (this != &other) {
		this->_input = other._input;
		this->_args = other._args;
		this->_straggler = other._straggler;
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

void	PmergeMeVector::makePairs(void)
{
	std::pair<int, int> tmp;
	std::vector<int>::iterator it = this->_nbrVector.begin();

	for (; it != this->_nbrVector.end(); it++)
	{
		if (it + 1 != this->_nbrVector.end()) {
			if (*it > *(it + 1))
				tmp = std::make_pair(*it, *(it + 1));
			else
				tmp = std::make_pair(*(it + 1), *it);
			this->_vecPaired.push_back(tmp);
			it++;
		}
		else if (this->_nbrVector.size() % 2 != 0)
			this->_straggler = *it;
	}
}

void	PmergeMeVector::mergePairs(std::vector<std::pair<int, int> >& vec, int begin, int mid, int end)
{
	size_t firstVectorIdx = 0;
	size_t secondVectorIdx = 0;
	size_t mergedVectorIdx = begin;

	size_t firstVectorSize = mid - begin + 1;
	size_t secondVectorSize = end - mid;

	std::vector<std::pair<int, int> > firstVector(firstVectorSize);
	std::vector<std::pair<int, int> > secondVector(secondVectorSize);

	for (size_t i = 0; i < firstVectorSize; ++i)
		firstVector[i] = vec[begin + i];
	for (size_t i = 0; i < secondVectorSize; ++i)
		secondVector[i] = vec[mid + 1 + i];

	while (firstVectorIdx < firstVectorSize && secondVectorIdx < secondVectorSize)
	{
		if (firstVector[firstVectorIdx].first <= secondVector[secondVectorIdx].first)
			vec[mergedVectorIdx++] = firstVector[firstVectorIdx++];
		else
			vec[mergedVectorIdx++] = secondVector[secondVectorIdx++];
	}

	while (firstVectorIdx < firstVectorSize)
		vec[mergedVectorIdx++] = firstVector[firstVectorIdx++];

	while (secondVectorIdx < secondVectorSize)
		vec[mergedVectorIdx++] = secondVector[secondVectorIdx++];
}

void	PmergeMeVector::sortPairs(std::vector<std::pair<int, int> >& vec, int begin, int end)
{
	if (begin < end)
	{
		int mid = begin + (end - begin) / 2;
		sortPairs(vec, begin, mid);
		sortPairs(vec, mid + 1, end);
		mergePairs(vec, begin, mid, end);
	}
}

void	PmergeMeVector::createMainChainAndPend(void)
{
	size_t i = 0;
	if (this->_vecPaired[0].second <= this->_vecPaired[0].first) {
		this->_mainChain.push_back(this->_vecPaired[i].second);
		this->_mainChain.push_back(this->_vecPaired[i++].first);
	}
	for (; i < this->_vecPaired.size(); i++)
	{
		this->_mainChain.push_back(this->_vecPaired[i].first);
		this->_pend.push_back(this->_vecPaired[i].second);
	}
}

std::vector<int>	PmergeMeVector::sortNumbers(void)
{
	makePairs();
	sortPairs(this->_vecPaired, 0, this->_vecPaired.size() - 1);
	createMainChainAndPend();
	std::cout << "mainChain: ";
	for (std::vector<int>::iterator it = this->_mainChain.begin(); it != this->_mainChain.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "pendChain: ";
	for (std::vector<int>::iterator it = this->_pend.begin(); it != this->_pend.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	return (this->_mainChain);
}
