/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:18:17 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/18 14:15:30 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RESET "\033[0m"
#define RED "\033[31m"

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
	void	addNumbers(unsigned int range, unsigned int number);
	int		shortestSpan(void);
	int		longestSpan(void);
};
