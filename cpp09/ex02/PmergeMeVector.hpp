/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:32:11 by njantsch          #+#    #+#             */
/*   Updated: 2024/01/03 17:07:44 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RESET "\033[0m"
#define RED "\033[31m"

#include <algorithm>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <cctype>
#include <climits>

class PmergeMeVector
{
private:
	char**	_input;
	int		_args;
	int		_straggler;
	std::vector<int> _nbrVector;
	std::vector<int> _mainChain;
	std::vector<int> _pend;
	std::vector<std::pair<int, int> > _vecPaired;
	void	checkNumbers(std::string& nbr);
	bool	isNumeric(std::string& nbr);
	void	makePairs(void);
	void	sortPairs(std::vector<std::pair<int, int> >& vec, int begin, int end);
	void	mergePairs(std::vector<std::pair<int, int> >& vec, int begin, int mid, int end);
	void	createMainChainAndPend(void);

public:
	PmergeMeVector(char** input, int args);
	PmergeMeVector(const PmergeMeVector& other);
	PmergeMeVector& operator=(const PmergeMeVector& other);
	~PmergeMeVector();

	void	checkInputAndStore(void);
	std::vector<int> sortNumbers(void);
};
