/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:46:10 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/15 14:09:38 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RESET "\033[0m"
#define BOLDGREEN "\033[1m\033[32m"

#include <iostream>

template <typename T, typename Func>
void	iter(T* address, size_t length, Func function) {
	for (size_t i = 0; i < length; i++)
		function(address[i]);
}

template <typename T>
void	printElement(const T& element) {
	std::cout << element << std::endl;
}
