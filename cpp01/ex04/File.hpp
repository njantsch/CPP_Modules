/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njantsch <njantsch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:56:33 by njantsch          #+#    #+#             */
/*   Updated: 2023/10/01 18:09:32 by njantsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIFL_HPP
#define SIFL_HPP

#define RESET "\033[0m"
#define RED "\033[31m"

#include <iostream>
#include <fstream>

class File {
private:
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		filename;
	std::string		s1;
	std::string		s2;
public:
	File(char **av, std::string file);
	~File();
	int	replace( void );
};

#endif
