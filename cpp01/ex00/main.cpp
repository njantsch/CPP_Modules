/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:07:35 by njantsch          #+#    #+#             */
/*   Updated: 2023/09/28 14:48:41 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
// Heap
	Zombie *heap;
	heap = newZombie("HeapZombie");
	heap->announce();
	delete heap;
// Stack
	randomChump("StackZombie");
	return (0);
}
