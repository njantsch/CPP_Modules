/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:45:58 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/06 16:58:39 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("some form"), _signed(false), _signedGrade(150), _execGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, const int sGrade, const int eGrade)
	: _name(name), _signed(false)
{
	std::cout << "Form attribute constructor called" << std::endl;
	if (sGrade > 150 || eGrade > 150)
		throw (Form::GradeTooLowException);
	if (sGrade < 1 || eGrade < 1)
		throw (Form::GradeTooHighException);
	this->_signedGrade = sGrade;
	this->_execGrade = eGrade;
}

