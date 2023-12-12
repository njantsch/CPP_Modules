/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:32:11 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/12 18:53:26 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { *this = other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void) other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

bool	ScalarConverter::isInt(const std::string& input)
{
	std::string::const_iterator it;

	if (std::atol(input.c_str()) > INT_MAX || std::atol(input.c_str()) < INT_MIN)
		return (false);
	for (it = input.begin(); it < input.end(); it++)
	{
		if (it == input.begin() && *it == '-')
			it++;
		if (!std::isdigit(*it))
			return (false);
	}
	std::cout << GREEN << "Is an int !" << RESET << std::endl;
	return (true);
}

bool	ScalarConverter::isChar(const std::string& input)
{
	if (input.length() == 1 && !std::isdigit(input[0])) {
		std::cout << GREEN << "Is a char!" << RESET << std::endl;
		return (true);
	}
	return (false);
}

bool	ScalarConverter::isFloat(const std::string& input)
{
	int dotCount = 0;
	std::size_t i = 0;

	if (input[i] == '-')
		i++;
	while (i < input.length()) {
		if (!std::isdigit(input[i]) && input[i] != 'f' && input[i] != '.')
			return (false);
		if (i + 1 == input.length() && input[i] != 'f')
			return (false);
		if (input[i] == '.') {
			if (!input[i + 1] || !input[i - 1] || !std::isdigit(input[i + 1]) || !std::isdigit(input[i - 1]))
				return (false);
			dotCount++;
		}
		i++;
	}
	if (dotCount != 1)
		return (false);
	std::cout << GREEN << "Is a float !" << RESET << std::endl;
	return (true);
}

bool	ScalarConverter::isDouble(const std::string& input)
{
	int dotCount = 0;
	std::size_t i = 0;

	if (input[i] == '-')
		i++;
	while (i < input.length()) {
		if (!std::isdigit(input[i]) && input[i] != '.')
			return (false);
		if (input[i] == '.') {
			if (!input[i + 1] || !input[i - 1] || !std::isdigit(input[i + 1]) || !std::isdigit(input[i - 1]))
				return (false);
			dotCount++;
		}
		i++;
	}
	if (dotCount != 1)
		return (false);
	std::cout << GREEN << "Is a double !" << RESET << std::endl;
	return (true);
}

void	ScalarConverter::convertFromChar(const std::string& input)
{
	char character = input[0];

	if (!std::isprint(character))
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "char: '" << character << "'" << '\n' \
			<< "int: " << static_cast<int>(character) << '\n' \
			<< "float: " << std::fixed << std::setprecision(1) << static_cast<float>(character) << 'f' << '\n' \
			<< "double: " << std::fixed << std::setprecision(1) << static_cast<double>(character) << std::endl;
}

void	ScalarConverter::convertFromDouble(const std::string& input)
{
	double	dbl = std::strtod(input.c_str(), NULL);
	float	flt = static_cast<float>(dbl);
	int		dec = static_cast<int>(dbl);
	char	chrctr = static_cast<char>(dbl);

	if (dbl < -127 || dbl > 127 || input == "nan")
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(chrctr))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << chrctr << "'" << std::endl;
	if (dbl >= INT_MAX || dbl < INT_MIN || input == "nan")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << dec << std::endl;
	if (fmod(flt, 1.0f) == 0.0f && flt < 1000000.0f)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float : " << flt << "f" << std::endl;
	std::cout << "double : " << dbl << std::endl;
}

void	ScalarConverter::convertFromInt(const std::string& input)
{
	int		dec = std::atoi(input.c_str());
	double	dbl = static_cast<double>(dec);
	float	flt = static_cast<int>(dec);
	char	chrctr = static_cast<char>(dec);

	if (dec < -127 || dec > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(chrctr))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << chrctr << "'" << std::endl;
	if (dbl >= INT_MAX || dbl < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << dec << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float : " << flt << "f" << '\n';
	std::cout << "double : " << dbl << std::endl;
}

void	ScalarConverter::convertFromFloat(const std::string& input)
{
	float	flt = std::atof(input.c_str());
	double	dbl = static_cast<double>(flt);
	int		dec = static_cast<int>(flt);
	char	chrctr = static_cast<char>(flt);

	if (flt < -127 || dbl > 127 || input == "nanf")
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(chrctr))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << chrctr << "'" << std::endl;
	if (dbl >= INT_MAX || dbl < INT_MIN || input == "nanf")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << dec << std::endl;
	if (fmod(flt, 1.0f) == 0.0f && flt < 1000000.0f)
		std::cout << std::fixed << std::setprecision(1);
	std::cout << "float : " << flt << "f" << std::endl;
	std::cout << "double : " << dbl << std::endl;
}

void ScalarConverter::convert(const std::string input)
{
	if (input.size() == 0) {
		std::cout << BOLDRED << "Error: input can't be empty" << RESET << std::endl;
		return ;
	}
	if (isChar(input) == true)
		convertFromChar(input);
	else if (isInt(input) == true)
		convertFromInt(input);
	else if (isFloat(input) == true || input == "-inff" || input == "+inff" || input == "nanf")
		convertFromFloat(input);
	else if (isDouble(input) == true || input == "-inf" || input == "+inf" || input == "nan")
		convertFromDouble(input);
	else
		std::cout << BOLDRED << "Error: please enter an int(42), char(a), float(42.0f) or double(42.0)" << std::endl;
}
