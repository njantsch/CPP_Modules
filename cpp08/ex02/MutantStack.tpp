/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:05:49 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/18 19:22:05 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <class T, class Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>() {}

template <class T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other) : std::stack<T>(other) {}

template <class T, class Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other)
{
	if (this != &other) {
		this->c = other.c;
		return (*this);
	}
	std::cout << RED << "Error assigning the same value" << RESET << std::endl;
	return (*this);
}

template <class T, class Container>
MutantStack<T, Container>::~MutantStack() {}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin() {
	return (this->c.begin());
}

template <class T, class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end() {
	return (this->c.end());
}
