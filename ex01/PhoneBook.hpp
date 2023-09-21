/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:53:32 by njantsch          #+#    #+#             */
/*   Updated: 2023/09/21 16:21:14 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook {
private:
	int		nbr_of_contacts;
	Contact	contacts[8];
public:
	void	add_function(void);
	void	search_function(void);
	void	pb_class_init(void);
	void	display_all(void);
};

#endif
