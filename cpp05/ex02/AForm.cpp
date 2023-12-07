/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:45:58 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/07 15:21:53 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("some Aform"), _signed(false), _signedGrade(150), _execGrade(150) {}

AForm::AForm(const std::string name, const int sGrade, const int eGrade)
	: _name(name), _signed(false), _signedGrade(sGrade), _execGrade(eGrade)
{
	if (this->_signedGrade > 150 || this->_execGrade > 150) {
		throw (AForm::GradeTooLowException());
	}
	if (this->_signedGrade < 1 || this->_execGrade < 1) {
		throw (AForm::GradeTooHighException());
	}
}

AForm::AForm(const AForm& other)
	: _name(other._name), _signedGrade(other._signedGrade), _execGrade(other._execGrade)
{
	*this = other;
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other) {
		this->_signed = other._signed;
		return (*this);
	}
	std::cout << RED << "Error assigning the same value" << RESET << std::endl;
	return (*this);
}

AForm::~AForm() {}

const std::string& AForm::getName() const { return (this->_name); }

bool AForm::getFormStatus() const { return (this->_signed); }

int AForm::getSignGrade() const { return (this->_signedGrade); }

int AForm::getExecGrade() const { return (this->_execGrade); }

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (this->getFormStatus() == true)
		throw (AForm::FormAlreadySignedException());
	if (bureaucrat.getGrade() > this->_signedGrade) {
		std::cout << bureaucrat.getName() << " couldn't sign "
			<< this->_name << " because his grade is too low !" << std::endl;
		throw (AForm::GradeTooLowException());
	}
	this->_signed = true;
	std::cout << GREEN << bureaucrat.getName() << " signed " << this->_name << RESET << std::endl;
}

std::ostream& operator<<(std::ostream& out, const AForm& other)
{
	out << other.getName() << ", required to sign: " << other.getSignGrade()
		<< ", required to execute: " << other.getExecGrade()
		<< ", signed: " << std::boolalpha << other.getFormStatus() << std::endl;
	return (out);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high !");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low !");
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form has not been signed !");
}

const char* AForm::FormAlreadySignedException::what() const throw()
{
	return ("Form has already been signed !");
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->getFormStatus() == false)
		throw (AForm::FormNotSignedException());
	if (executor.getGrade() > this->getExecGrade()) {
		std::cout << RED << executor.getName()
			<< "'s grade is too low to execute this form" << RESET << std::endl;
		throw (AForm::GradeTooLowException());
	}
}
