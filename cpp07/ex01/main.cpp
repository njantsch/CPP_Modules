/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:46:15 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/14 20:22:44 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int	iArr[] = {1, 2, 3, 4, 5};
	char cArr[] = "test";
	std::string strArr[] = {"this", "is", "a", "test"};

	iter(iArr, 5, printElement<int>);
	iter(cArr, 4, printElement<char>);
	iter(strArr, 4, printElement<std::string>);
}
