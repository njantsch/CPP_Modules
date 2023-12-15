/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:46:15 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/15 14:17:27 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int	iArr[] = {1, 2, 3, 4, 5};
	char cArr[] = "test";
	std::string strArr[] = {"this", "is", "a", "test"};

	std::cout << BOLDGREEN << "\nint array" << RESET << std::endl;
	iter(iArr, 5, printElement<int>);

	std::cout << BOLDGREEN << "\nchar array" << RESET << std::endl;
	iter(cArr, 4, printElement<char>);

	std::cout << BOLDGREEN << "\nstd::string array" << RESET << std::endl;
	iter(strArr, 4, printElement<std::string>);
}
