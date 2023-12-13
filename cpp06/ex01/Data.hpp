/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:04:37 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/13 16:23:05 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDRED "\033[1m\033[31m"

#include <iostream>
#include <cstdint>

class Data
{
private:
	int _data;
public:
	Data();
	Data(const int data);
	Data(const Data& other);
	Data& operator=(const Data& other);
	~Data();

	int	getData() const;
};

std::ostream&	operator<<(std::ostream& out, const Data& other);

