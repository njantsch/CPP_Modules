/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:14:06 by njantsch          #+#    #+#             */
/*   Updated: 2023/12/14 21:26:27 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL) {}

template <typename T>
Array<T>::Array(unsigned int n) { this->_array = new T[]; }

template <typename T>
Array<T>::Array(const Array& other)
