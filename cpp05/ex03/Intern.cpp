/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:07:09 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/09 13:57:40 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { *this = other; }

Intern& Intern::operator=(const Intern& other)
{
	(void) other;
	return (*this);
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& form, const std::string& target)
{
	std::cout << "makeForm function called" << std::endl;
	int	i;
	std::string forms[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	for (i = 0; i < 3; i++) {
		if (form.compare(forms[i]) == 0)
			break;
	}
	switch(i)
	{
	case 0:
		return (new RobotomyRequestForm(target));
	case 1:
		return (new PresidentialPardonForm(target));
	case 2:
		return (new ShrubberyCreationForm(target));
	default:
		std::cout << RED << "No matching form found" << RESET << std::endl;
	}
	return (NULL);
}
