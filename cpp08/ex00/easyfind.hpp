/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:40:54 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/19 14:58:50 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <list>

template <typename T>
int	easyFind(T& prmT, int prmInt)
{
	typename T::iterator it = std::find(prmT.begin(), prmT.end(), prmInt);
	if (it == prmT.end())
		throw (std::runtime_error("Couldn't find integer in range"));
	return (std::distance(prmT.begin(), it));
}

template <typename Iterator, typename T>
void iota(Iterator first, Iterator last, T value)
{
	while (first != last) {
		*first = value;
		++first;
		++value;
	}
}
