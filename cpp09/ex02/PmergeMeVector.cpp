/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:32:08 by njantsch          #+#    #+#             */
/*   Updated: 2024/01/04 20:58:02 by njantsch         ###   ########.fr       */
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

	this->_mainChain.push_back(this->_vecPaired[0].second);

	for (; i < this->_vecPaired.size(); i++)
	{
		this->_mainChain.push_back(this->_vecPaired[i].first);
		this->_pend.push_back(this->_vecPaired[i].second);
	}
}

void	PmergeMeVector::generateJacobsthalSequence(void)
{
	size_t size;
	size_t jacobsthalNumber = 0;
	size_t	i = 3;

	size = this->_pend.size() + 3;

	if (this->_pend.empty())
		return ;
	for (; i < size; i++) {
		jacobsthalNumber = ((1 << i) - (i % 2 == 0 ? 1 : -1)) / 3;
		this->_jacobsthalSequence.push_back(jacobsthalNumber);
	}
}

int	PmergeMeVector::binarySearch(int item, int low, int high)
{
	if (high <= low)
		return ((item < this->_mainChain[low]) ? (low + 1) : low);

	int mid = (low + high) / 2;

	if (item > this->_mainChain[mid])
		return (binarySearch(item, mid + 1, high));

	return (binarySearch(item, low, mid - 1));
}

void	PmergeMeVector::insertPendIntoMain(void)
{
	size_t	min = 0;
	size_t	pos;
	size_t jacobsIdx;
	std::vector<size_t>::iterator it = this->_jacobsthalSequence.begin();

	while (min < this->_pend.size())
	{
		jacobsIdx = *it;
		while (--jacobsIdx > min) {
			if (jacobsIdx <= this->_pend.size() - 1) {
				std::cout << "idx: " << jacobsIdx << std::endl;
				pos = binarySearch(this->_pend[jacobsIdx], 0, this->_mainChain.size() - 1);
				// std::cout << "pos: " << pos << "item: " << this->_pend[jacobsIdx] << std::endl;
				this->_mainChain.insert(this->_mainChain.begin() + pos, this->_pend[jacobsIdx]);
			}
		}
		min = *it - 1;
		it++;
	}
	if (this->_straggler >= 0)
	{
		pos = binarySearch(this->_straggler, 0, this->_mainChain.size() - 1);
		this->_mainChain.insert(this->_mainChain.begin() + pos, this->_straggler);
	}
}

std::vector<int>	PmergeMeVector::sortNumbers(void)
{
	makePairs();
	sortPairs(this->_vecPaired, 0, this->_vecPaired.size() - 1);
	createMainChainAndPend();
	generateJacobsthalSequence();
	insertPendIntoMain();
	return (this->_mainChain);
}

	// std::cout << "mainChain: ";
	// for (std::vector<size_t>::iterator it = this->_jacobsthalSequence.begin(); it != this->_jacobsthalSequence.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
	// std::cout << "pendChain: ";
	// for (std::vector<int>::iterator it = this->_pend.begin(); it != this->_pend.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
