/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:22:39 by njantsch          #+#    #+#             */
/*   Updated: 2023/09/21 16:18:30 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

#include <iostream>
#include <iomanip>

std::string	check_contact_string(std::string str);

class Contact {
private:
	std::string	first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string dark_secret;
public:
	void	add_new_contact(void);
	void	display_contact(int index);
	void	display_all_expanded(int index);
};

#endif
