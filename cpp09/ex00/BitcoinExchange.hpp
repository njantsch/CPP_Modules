/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:10:06 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/21 22:02:44 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RESET "\033[0m"
#define RED "\033[31m"
#define BOLDGREEN "\033[1m\033[32m"

#include <iostream>
#include <sstream>
#include <fstream>
#include <climits>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, float> _data;
	float	convertPrice(std::string& line);
	int		checkDateRange(long yearIn);
	float	findClosestDate(std::string line);
	int		checkInput(std::string& line);
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void	checkInput(std::ifstream& inputFile);
	void	calculateResult(std::string& line);
};

