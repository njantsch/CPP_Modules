/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:52:43 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/07 22:15:32 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("nobody"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;

}

Bureaucrat::Bureaucrat(const std::string& name, const int grade) : _name(name)
{
	std::cout << "Bureaucrat attribute init constructor called" << std::endl;
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
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

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

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

void	Bureaucrat::signForm(Form& form)
{
	form.beSigned(*this);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat: Grade is too high !");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat: Grade is too low !");
}
