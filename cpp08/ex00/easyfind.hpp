/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:40:54 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/18 20:04:34 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <list>

template <typename T>
void	easyFind(T& prmT, int prmInt)
{
	typename T::iterator it = std::find(prmT.begin(), prmT.end(), prmInt);
	if (it == prmT.end())
		throw (std::runtime_error("Couldn't find integer in range"));
	std::cout << GREEN << "Element found at index: " << std::distance(prmT.begin(), it) << RESET << std::endl;
}
