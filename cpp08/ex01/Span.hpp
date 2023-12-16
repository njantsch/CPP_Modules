/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:18:17 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/16 18:45:06 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RESET "\033[0m"
#define RED "\033[31m"

#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

class Span
{
private:
	size_t _size;
	std::vector<int> _numbers;
	std::vector<int>::iterator _it;
public:
	Span();
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void	addNumber(unsigned int n);
	int		shortestSpan(void);
	int		longestSpan(void);
};
