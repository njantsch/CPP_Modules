/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:33:27 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/07 22:08:54 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("home") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other)
{
	*this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other) {
		this->_target = other._target;
		return (*this);
	}
	std::cout << RED << "Error assigning the same value" << RESET << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::ofstream file(this->_target + "_shrubbery", std::ios::out);
	if (file.is_open() == false) {
		std::cout << RED << "File couldn't be opened" << RESET << std::endl;
		return ;
	}
	file << "\n\
         v          \n\
        >X<         \n\
         A          \n\
        d$b         \n\
      .d\\$$b.      \n\
    .d$i$$\\$$b.    \n\
       d$$@b        \n\
      d\\$$$ib      \n\
    .d$$$\\$$$b     \n\
  .d$$@$$$$\\$$ib.  \n\
      d$$i$$b       \n\
     d\\$$$$@$b     \n\
  .d$@$$\\$$$$$@b.  \n\
.d$$$$i$$$\\$$$$$$b.\n\
        ###         \n\
        ###         \n\
        ### mh      \n\
source: https://www.asciiart.eu/holiday-and-events/christmas/trees\n";
	file.close();
	std::cout << GREEN << executor.getName() << " executed "
		<< this->getName() << " successfully" << RESET << std::endl;
}
