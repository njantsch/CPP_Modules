/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeVector.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:32:11 by njantsch          #+#    #+#             */
/*   Updated: 2024/01/02 18:40:27 by njantsch         ###   ########.fr       */
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
	std::vector<int> _nbrVector;
	void	checkNumbers(std::string& nbr);
	bool	isNumeric(std::string& nbr);
public:
	PmergeMeVector(char** input, int args);
	PmergeMeVector(const PmergeMeVector& other);
	PmergeMeVector& operator=(const PmergeMeVector& other);
	~PmergeMeVector();

	void	checkInputAndStore(void);
	std::vector<int> sortNumbers(void);
};
