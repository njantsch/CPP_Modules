/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:10:09 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/21 22:03:01 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream dataBase("./data.csv");
	if (!dataBase.is_open())
		throw (std::runtime_error("Error: couldn't open data.csv file"));
	std::string line;
	std::getline(dataBase, line);
	while (std::getline(dataBase, line))
		this->_data[line.substr(0, line.find_last_of(','))] = convertPrice(line);
	dataBase.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { *this = other; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	(void) other;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

float BitcoinExchange::convertPrice(std::string& line)
{
	size_t lastCommaPos = line.find_last_of(',');
	std::string bitcoinExchangeRate = line.substr(lastCommaPos + 1);
	float convExchangeRate = std::atof(bitcoinExchangeRate.c_str());
	return (convExchangeRate);
}

int	BitcoinExchange::checkDateRange(long yearIn)
{
	int	minYear = INT_MAX;
	int	maxYear = INT_MIN;
	std::map<std::string, float>::iterator it = this->_data.begin();
	while (it != this->_data.end())
	{
		std::istringstream sstream(it->first);
		int	year;
		char dash;
		sstream >> year >> dash;
		if (!sstream.fail() && dash == '-') {
			if (year < minYear)
				minYear = year;
			if (year > maxYear)
				maxYear = year;
		}
		it++;
	}
	if (yearIn < minYear || yearIn > maxYear)
		return (1);
	return (0);
}

int	BitcoinExchange::checkInput(std::string& line)
{
	std::istringstream sstream(line);
	long	year, month, day, value;

	char dash1, dash2, pipe;
	sstream >> year >> dash1 >> month >> dash2 >> day >> pipe >> value;
	if (sstream.fail() || dash1 != '-' || dash2 != '-' || pipe != '|') {
		std::cerr << RED << "Error: Invalid date format => " << line << RESET << std::endl;
		return (1);
	}
	if (year > INT_MAX || month > INT_MAX || day > INT_MAX || value > INT_MAX) {
		std::cerr << RED << "Error: too large a number" << RESET << std::endl;
		return (1);
	}
	if (year < 0 || month < 0 || day < 0 || value < 0) {
		std::cerr << RED << "Error: not a positiv number" << RESET << std::endl;
		return (1);
	}
	if (checkDateRange(year) == 1 || month > 12 || month < 1 || day > 31 || day < 1) {
		std::cerr << RED << "Error: Invalid date range => " \
			<< year << dash1 << month << dash2 << day << RESET << std::endl;
		return (1);
	}
	return (0);
}

float	BitcoinExchange::findClosestDate(std::string targetDate)
{
	std::map<std::string, float>::iterator it = this->_data.begin();
	float value;

	for (; it != this->_data.end(); ++it) {
		int difference = std::atoi(targetDate.substr(0, 4).c_str()) - std::atoi(it->first.substr(0, 4).c_str());
		if (difference >= 0 && (
			std::atoi(targetDate.substr(5, 2).c_str()) > std::atoi(it->first.substr(5, 2).c_str()) ||
			(std::atoi(targetDate.substr(5, 2).c_str()) == std::atoi(it->first.substr(5, 2).c_str()) &&
			std::atoi(targetDate.substr(8, 2).c_str()) > std::atoi(it->first.substr(8, 2).c_str())))) {
			value = it->second;
		}
	}
	return (value);
}

void	BitcoinExchange::calculateResult(std::string& line)
{
	std::istringstream sstream(line);
	std::string token;
	float dbValue = 0;
	float inValue = 0;

	sstream >> token;
	(!this->_data[token]) ? dbValue = findClosestDate(token) : dbValue = this->_data[token];
	std::cout << token;
	while (sstream >> token)
	{
		if (token == "|")
			std::cout << " => ";
		else {
			inValue = std::atof(token.c_str());
			std::cout << token;
		}
	}
	std::cout << " = " << (inValue * dbValue) << std::endl;
}

void	BitcoinExchange::checkInput(std::ifstream& inputFile)
{
	std::string line;
	std::getline(inputFile, line);
	while (std::getline(inputFile, line))
	{
		if (this->checkInput(line) == 1)
			continue;
		this->calculateResult(line);
	}
}
