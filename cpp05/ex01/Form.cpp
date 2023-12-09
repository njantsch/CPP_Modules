/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:45:58 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/09 15:28:58 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("some form"), _signed(false), _signedGrade(150), _execGrade(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, const int sGrade, const int eGrade)
	: _name(name), _signed(false), _signedGrade(sGrade), _execGrade(eGrade)
{
	std::cout << "Form attribute constructor called" << std::endl;
	if (this->_signedGrade > 150 || this->_execGrade > 150) {
		throw (Form::GradeTooLowException());
	}
	if (this->_signedGrade < 1 || this->_execGrade < 1) {
		throw (Form::GradeTooHighException());
	}
}

Form::Form(const Form& other)
	: _name(other._name), _signedGrade(other._signedGrade), _execGrade(other._execGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = other;
}

Form& Form::operator=(const Form& other)
{
	if (this != &other) {
		this->_signed = other._signed;
		return (*this);
	}
	std::cout << RED << "Error assigning the same value" << RESET << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

const std::string& Form::getName() const { return (this->_name); }

bool Form::getFormStatus() const { return (this->_signed); }

int Form::getSignGrade() const { return (this->_signedGrade); }

int Form::getExecGrade() const { return (this->_execGrade); }

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (this->getFormStatus() == true) {
		std::cout << RED << this->getName() << " is already signed" << RESET << std::endl;
		throw (Form::FormAlreadySignedException());
		return ;
	}
	if (bureaucrat.getGrade() > this->_signedGrade) {
		std::cout << bureaucrat.getName() << " couldn't sign "
			<< this->_name << " because his grade is too low !" << std::endl;
		throw (Form::GradeTooLowException());
	}
	this->_signed = true;
	std::cout << GREEN << bureaucrat.getName() << " signed " << this->_name << RESET << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Form& other)
{
	out << other.getName() << ", required to sign: " << other.getSignGrade()
		<< ", required to execute: " << other.getExecGrade()
		<< ", signed: " << std::boolalpha << other.getFormStatus() << std::endl;
	return (out);
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade is too high !");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade is too low !");
}

const char* Form::FormAlreadySignedException::what() const throw()
{
	return ("Form has already been signed !");
}
