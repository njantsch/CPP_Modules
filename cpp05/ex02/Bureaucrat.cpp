/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:52:43 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/07 21:37:27 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("nobody"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, const int grade) : _name(name)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other) {
		this->_grade = other._grade;
		return (*this);
	}
	std::cout << RED << "Error assigning the same value" << RESET << std::endl;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << std::endl;
	return (out);
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName() const { return (this->_name); }

int	Bureaucrat::getGrade() const { return (this->_grade); }

void	Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
}

void	Bureaucrat::signForm(AForm& form) { form.beSigned(*this); }

void	Bureaucrat::executeForm(AForm const & form) { form.execute(*this); }

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat grade is too high !");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat grade is too low !");
}
