/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:32:15 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/12 12:59:47 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDRED "\033[1m\033[31m"

#include <iostream>
#include <cctype>
#include <iomanip>
#include <cstdlib>
#include <climits>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static void	convertFromChar(const std::string& input);
	static void	convertFromInt(const std::string& input);
	static void	convertFromFloat(const std::string& input);
	static void	convertFromDouble(const std::string& input);

	static bool	isInt(const std::string& input);
	static bool	isChar(const std::string& input);
	static bool	isFloat(const std::string& input);
	static bool	isDouble(const std::string& input);
public:
	static void	convert(const std::string input);
};
