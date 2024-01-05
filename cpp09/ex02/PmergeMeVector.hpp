/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:32:11 by njantsch          #+#    #+#             */
/*   Updated: 2024/01/05 20:28:50 by njantsch         ###   ########.fr       */
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
#include <vector>
#include <cctype>
#include <climits>
#include <ctime>

class PmergeMeVector
{
private:

	char**	_input;
	int		_args;
	int		_straggler;
	clock_t	_startTime;
	double	_elapsedTime;
	std::vector<int> _nbrVector;
	std::vector<int> _mainChain;
	std::vector<int> _pend;
	std::vector<size_t> _jacobsthalSequence;
	std::vector<std::pair<int, int> > _vecPaired;

	void	checkNumbers(std::string& nbr);
	bool	isNumeric(std::string& nbr);
	bool	findDuplicate(void);
	void	makePairs(void);
	void	sortPairs(std::vector<std::pair<int, int> >& vec, int begin, int end);
	void	mergePairs(std::vector<std::pair<int, int> >& vec, int begin, int mid, int end);
	void	createMainChainAndPend(void);
	void	generateJacobsthalSequence(void);
	int		generateJacobsthalIndex(int n);
	void	insertPendIntoMain(void);
	int		binarySearch(int item, int low, int high);

public:

	PmergeMeVector(char** input, int args);
	PmergeMeVector(const PmergeMeVector& other);
	PmergeMeVector& operator=(const PmergeMeVector& other);
	~PmergeMeVector();

	void	checkInputAndStore(void);
	std::vector<int> sortNumbers(void);
	void	printBefore(void);
	void	printAfter(void);
	void	displayProcessTime(void);
};
