/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:18:17 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/19 15:20:38 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RESET "\033[0m"
#define RED "\033[31m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDRED "\033[1m\033[31m"

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <climits>

class Span
{
private:
	size_t _size;
	std::vector<int> _numbers;
public:
	Span();
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void	addNumber(unsigned int n);
	void	addNumbersSingle(unsigned int range, unsigned int number);
	void	addNumbersRange(unsigned int range, unsigned int number);
	int		shortestSpan(void);
	int		longestSpan(void);
};
