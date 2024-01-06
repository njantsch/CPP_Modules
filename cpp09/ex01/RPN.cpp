/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:43:17 by nicolasjant       #+#    #+#             */
/*   Updated: 2024/01/06 18:22:31 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string& input)
{
	if (input.empty()) throw (std::invalid_argument("Error: input string is empty"));
	int numbers = 0;
	std::string::iterator it = input.begin();
	for (; it != input.end(); it++) {
		if (isdigit(*it))
			numbers++;
	}
	if (numbers < 2) throw (std::invalid_argument("Error: not enough numbers"));
	this->_input = input;
}

RPN::RPN(const RPN& other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other) {
		this->_input = other._input;
		this->_number_stk = other._number_stk;
		return (*this);
	}
	std::cout << RED << "Error assigning the same value" << RESET << std::endl;
	return (*this);
}

RPN::~RPN() {}

bool	RPN::isOperator(char c) const
{
	switch (c)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return (true);
	default:
		return (false);
	}
}

int		RPN::doOperation(int a, int b, char op)
{
	switch (op)
	{
	case '+': return (b + a);
	case '-': return (b - a);
	case '*': return (b * a);
	case '/': return (b / a);
	default: throw (std::runtime_error("Error"));
	}
}

void	RPN::evaluate(void)
{
	int a, b;
	std::string::iterator it;

	for (it = this->_input.begin(); it != this->_input.end(); it++)
	{
		if (isOperator(*it) == true
			&& (*(it + 1) == 32 || (it + 1) == this->_input.end()))
		{
			if (this->_number_stk.size() < 2)
				throw (std::runtime_error("Error"));
			a = this->_number_stk.top();
			this->_number_stk.pop();
			b = this->_number_stk.top();
			this->_number_stk.pop();
			this->_number_stk.push(doOperation(a, b, *it));
		}
		else if (isdigit(*it) != 0 && *(it + 1) == 32)
			this->_number_stk.push(*it - '0');
		else if (*it != 32)
			throw (std::runtime_error("Error"));
	}
	std::cout << this->_number_stk.top() << std::endl;
}
