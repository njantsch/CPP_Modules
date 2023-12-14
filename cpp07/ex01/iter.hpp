/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:46:10 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/14 20:24:12 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename Func>
void	iter(T* address, std::size_t length, Func printElement) {
	for (std::size_t i = 0; i < length; i++)
		printElement(address[i]);
	std::cout << std::endl;
}

template <typename T>
void	printElement(const T& element) {
	std::cout << element << ' ';
}
