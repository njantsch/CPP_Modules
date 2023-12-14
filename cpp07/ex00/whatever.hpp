/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:14:32 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/14 19:42:59 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDYELLOW "\033[1m\033[33m"
#define BOLDRED "\033[1m\033[31m"

#include <iostream>

template <typename T>
T	max(T& prm1, T& prm2) {
	return ((prm1 > prm2) ? prm1 : prm2);
}

template <typename T>
T	min(T& prm1, T& prm2) {
	return ((prm1 < prm2) ? prm1 : prm2);
}

template <typename T>
void	swap(T& prm1, T& prm2) {
	T tmp;

	tmp = prm1;
	prm1 = prm2;
	prm2 = tmp;
}
