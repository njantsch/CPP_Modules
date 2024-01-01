/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasjantsch <nicolasjantsch@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:43:23 by nicolasjant       #+#    #+#             */
/*   Updated: 2023/12/31 21:20:14 by nicolasjant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RESET "\033[0m"
#define RED "\033[31m"

#include <iostream>
#include <sstream>
#include <cctype>
#include <stack>

class RPN
{
private:
	std::string _input;
	std::stack<int> _number_stk;
	bool	isOperator(char c) const;
	int		doOperation(int a, int b, char op);
public:
	RPN(std::string& input);
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	void	evaluate(void);
};
