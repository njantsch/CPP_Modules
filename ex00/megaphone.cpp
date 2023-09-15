/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:23:22 by njantsch          #+#    #+#             */
/*   Updated: 2023/09/15 15:25:48 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	std::string				voice;
	std::string::iterator	index;

	if (ac < 2)
	{
		std::cout << "* LOUD AND UBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	voice = av[1];
	if (voice.size() == 0)
		return (1);
	for (int i = 1; av[i]; i++)
	{
		voice = av[i];
		for (index = voice.begin(); index != voice.end(); index++)
		{
			*index = std::toupper(*index);
			std::cout << *index;
		}
	}
	std::cout << std::endl;
	return (0);
}
