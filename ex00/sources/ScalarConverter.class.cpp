/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:56:33 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/10 21:58:06 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.class.hpp"
#include <cstdlib>
/*
bool	is_int(std::string str)
{
	int	i = 0;
	const char* cstr = str.c_str();
	if (str.c_str()[0] == '+' || str.c_str()[0] == '-')
		i = 1;
	while ()
	double c = strtol(str.c_str(), NULL, 10);
	return false;
}

bool	is_float(std::string str)
{
	
	return false;
}

bool	is_double(std::string str)
{
	
	return false;
}

bool	pseudoLiterals_float(std::string str)
{
	
	return false;
}

bool	pseudoLiterals_double(std::string str)
{
	
	return false;
}

static void	castChar(std::string str)
{
	double c = strtol(str.c_str(), NULL, 10);

}

void	ScalarConverter::convert(std::string str)
{

	// std::regex printable_chars("^[ -~]+$");
	// std::regex non_printable_chars("[^\x20-\x7E]");
	// std::regex no_digits("^[^0-9]*$");
	// std::regex is_digit("^[0-9]*$");
	// std::regex is_int("^[+-]?\\d+$");
	// std::regex is_double("[+-]?\\d*\\.\\d+");
	// std::regex is_float("[+-]?\\d*\\.\\d+[f]");
	// std::regex pseudoLiterals_float("(\\+inff|-inff|nanf)");
	// std::regex pseudoLiterals_double("(\\+inf|-inf|nan)");

	double	d = strtod(str.c_str(), NULL);
	
	// CAST CHAR
	
	
	// CAST INT
	if (is_int(str))
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else if (pseudoLiterals_float(str) || pseudoLiterals_double(str))
		std::cout << "int: impossible" << std::endl;
	
	// CAST FLOAT
	if (is_float(str))
		std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	else if (pseudoLiterals_float(str))
		std::cout << "float: " << str << std::endl;
	else if (pseudoLiterals_double(str))
		std::cout << "float: " << str << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	
	// CAST DOUBLE
	if (is_double(str))
		std::cout << "double: " << static_cast<double>(d) << std::endl;
	else if (is_float(str))
		std::cout << "double: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<double>(d) << std::endl;
	else if (pseudoLiterals_double(str))
		std::cout << "double: " << str << std::endl;
	else
		std::cout << "double: impossible" << std::endl;

}
*/