/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:46:01 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/07 14:37:56 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string _name;
	bool _signed;
	const int _signedGrade;
	const int _execGrade;
public:

	class GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	class FormAlreadySignedException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	AForm();
	AForm(const std::string name, const int sGrade, const int eGrade);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	const std::string& getName() const;
	bool getFormStatus() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(class Bureaucrat& bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream&	operator<<(std::ostream& out, const AForm& other);
