/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:56:16 by njantsch          #+#    #+#             */
/*   Updated: 2024/01/05 20:28:12 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RESET "\033[0m"
#define RED "\033[31m"
#define BOLDGREEN "\033[1m\033[32m"

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <deque>
#include <cctype>
#include <climits>
#include <ctime>

class PmergeMeDeque
{
private:

	char**	_input;
	int		_args;
	int		_straggler;
	clock_t	_startTime;
	double	_elapsedTime;
	std::deque<int> _nbrDeque;
	std::deque<int> _mainChain;
	std::deque<int> _pend;
	std::deque<size_t> _jacobsthalSequence;
	std::deque<std::pair<int, int> > _dequePaired;

	void	checkNumbers(std::string& nbr);
	bool	isNumeric(std::string& nbr);
	bool	findDuplicate(void);
	void	makePairs(void);
	void	sortPairs(std::deque<std::pair<int, int> >& deque, int begin, int end);
	void	mergePairs(std::deque<std::pair<int, int> >& deque, int begin, int mid, int end);
	void	createMainChainAndPend(void);
	void	generateJacobsthalSequence(void);
	int		generateJacobsthalIndex(int n);
	void	insertPendIntoMain(void);
	int		binarySearch(int item, int low, int high);

public:

	PmergeMeDeque(char** input, int args);
	PmergeMeDeque(const PmergeMeDeque& other);
	PmergeMeDeque& operator=(const PmergeMeDeque& other);
	~PmergeMeDeque();

	void	checkInputAndStore(void);
	std::deque<int> sortNumbers(void);
	void	printBefore(void);
	void	printAfter(void);
	void	displayProcessTime(void);
};
