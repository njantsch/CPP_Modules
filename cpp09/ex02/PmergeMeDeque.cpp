/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:56:18 by njantsch          #+#    #+#             */
/*   Updated: 2024/01/05 20:28:40 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMeDeque.hpp"

PmergeMeDeque::PmergeMeDeque(char** input, int args)
	: _input(input), _args(args - 1), _straggler(-1) {}

PmergeMeDeque::PmergeMeDeque(const PmergeMeDeque& other)
{
	*this = other;
}

PmergeMeDeque& PmergeMeDeque::operator=(const PmergeMeDeque& other)
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

PmergeMeDeque::~PmergeMeDeque() {}

bool	PmergeMeDeque::isNumeric(std::string& nbr)
{
	for (std::string::iterator it = nbr.begin(); it != nbr.end(); it++) {
		if (!std::isdigit(*it))
			return (false);
	}
	return (true);
}

bool	PmergeMeDeque::findDuplicate(void)
{
	std::deque<int> tmp(this->_nbrDeque);

	std::sort(tmp.begin(), tmp.end());
	std::deque<int>::iterator it = std::adjacent_find(tmp.begin(), tmp.end());
	return ((it == tmp.end()) ? false : true);
}

void	PmergeMeDeque::checkNumbers(std::string& nbr)
{
	if (nbr.empty() == true) throw (std::runtime_error("Error size of argument can't be 0"));
	if (!isNumeric(nbr)) throw (std::runtime_error("Error found non numeric character"));
	if (std::atol(nbr.c_str()) > INT_MAX) throw (std::runtime_error("Error number too big"));
}

void	PmergeMeDeque::checkInputAndStore(void)
{
	this->_startTime = clock();
	std::deque<std::string> inputDeque;
	for (int i = 0; i < this->_args; i++)
		inputDeque.push_back(this->_input[i]);
	std::deque<std::string>::iterator it = inputDeque.begin();
	for (; it != inputDeque.end(); it++) {
		checkNumbers(*it);
		this->_nbrDeque.push_back(std::atoi(it->c_str()));
	}
	if (findDuplicate())
		throw (std::runtime_error("Error found duplicate number"));
}

void	PmergeMeDeque::makePairs(void)
{
	std::pair<int, int> tmp;
	std::deque<int>::iterator it = this->_nbrDeque.begin();

	for (; it != this->_nbrDeque.end(); it++)
	{
		if (it + 1 != this->_nbrDeque.end()) {
			if (*it > *(it + 1))
				tmp = std::make_pair(*it, *(it + 1));
			else
				tmp = std::make_pair(*(it + 1), *it);
			this->_dequePaired.push_back(tmp);
			it++;
		}
		else if (this->_nbrDeque.size() % 2 != 0)
			this->_straggler = *it;
	}
}

void	PmergeMeDeque::mergePairs(std::deque<std::pair<int, int> >& deque, int begin, int mid, int end)
{
	size_t firstDequeIdx = 0;
	size_t secondDequeIdx = 0;
	size_t mergedDequeIdx = begin;

	size_t firstDequeSize = mid - begin + 1;
	size_t secondDequeSize = end - mid;

	std::deque<std::pair<int, int> > firstDeque(firstDequeSize);
	std::deque<std::pair<int, int> > secondDeque(secondDequeSize);

	for (size_t i = 0; i < firstDequeSize; ++i)
		firstDeque[i] = deque[begin + i];
	for (size_t i = 0; i < secondDequeSize; ++i)
		secondDeque[i] = deque[mid + 1 + i];

	while (firstDequeIdx < firstDequeSize && secondDequeIdx < secondDequeSize)
	{
		if (firstDeque[firstDequeIdx].first <= secondDeque[secondDequeIdx].first)
			deque[mergedDequeIdx++] = firstDeque[firstDequeIdx++];
		else
			deque[mergedDequeIdx++] = secondDeque[secondDequeIdx++];
	}

	while (firstDequeIdx < firstDequeSize)
		deque[mergedDequeIdx++] = firstDeque[firstDequeIdx++];

	while (secondDequeIdx < secondDequeSize)
		deque[mergedDequeIdx++] = secondDeque[secondDequeIdx++];
}

void	PmergeMeDeque::sortPairs(std::deque<std::pair<int, int> >& deque, int begin, int end)
{
	if (begin < end)
	{
		int mid = begin + (end - begin) / 2;
		sortPairs(deque, begin, mid);
		sortPairs(deque, mid + 1, end);
		mergePairs(deque, begin, mid, end);
	}
}

void	PmergeMeDeque::createMainChainAndPend(void)
{
	size_t i = 0;

	this->_mainChain.push_back(this->_dequePaired[0].second);

	for (; i < this->_dequePaired.size(); i++)
	{
		this->_mainChain.push_back(this->_dequePaired[i].first);
		this->_pend.push_back(this->_dequePaired[i].second);
	}
}

void	PmergeMeDeque::generateJacobsthalSequence(void)
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

int	PmergeMeDeque::binarySearch(int item, int low, int high)
{
	if (high <= low)
		return ((item > this->_mainChain[low]) ? (low + 1) : low);

	int mid = (low + high) / 2;

	if (item > this->_mainChain[mid])
		return (binarySearch(item, mid + 1, high));

	return (binarySearch(item, low, mid - 1));
}

void	PmergeMeDeque::insertPendIntoMain(void)
{
	size_t	min = 0;
	size_t	pos;
	size_t jacobsIdx;
	std::deque<size_t>::iterator it = this->_jacobsthalSequence.begin();

	while (min < this->_pend.size())
	{
		jacobsIdx = *it;
		while (--jacobsIdx > min) {
			if (jacobsIdx < this->_pend.size()) {
				pos = binarySearch(this->_pend[jacobsIdx], 0, this->_mainChain.size());
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

std::deque<int>	PmergeMeDeque::sortNumbers(void)
{
	makePairs();
	sortPairs(this->_dequePaired, 0, this->_dequePaired.size() - 1);
	createMainChainAndPend();
	generateJacobsthalSequence();
	insertPendIntoMain();
	this->_elapsedTime = static_cast<double>(clock() - this->_startTime) * 1000.0 / CLOCKS_PER_SEC;
	return (this->_mainChain);
}

void	PmergeMeDeque::printBefore(void)
{
	std::deque<int>::iterator it = this->_nbrDeque.begin();

	std::cout << BOLDGREEN << "Before:	" << RESET;
	for (; it != this->_nbrDeque.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMeDeque::printAfter(void)
{
	if (this->_mainChain.empty())
		throw (std::runtime_error("Error: sort before printing after"));

	std::deque<int>::iterator it = this->_mainChain.begin();

	std::cout << BOLDGREEN << "After:	" << RESET;
	for (; it != this->_mainChain.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMeDeque::displayProcessTime(void)
{
	std::cout << "Time to process a range of	" << this->_mainChain.size() << " elements with std::deque : " \
		<< this->_elapsedTime << " ms" << std::endl;
}
