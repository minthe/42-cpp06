/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:56:33 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/10 18:51:33 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.class.hpp"
#include <cstdlib>
#include <regex>

// void	castChar(std::string str)
// {
// 	double c = strtol(str.c_str(), NULL, 10);

// 	// if (str.length() == 1 && std::regex_match(str.c_str(), printable_chars) && std::regex_match(str.c_str(), no_digits)) // checks for printable char
// 	// 	std::cout << "char: '" << static_cast<char>(str.c_str()[0]) << "'" << std::endl;
// 	// else if (std::regex_match(strtol(str.c_str(), NULL, 10), non_printable_chars) // check for non-printable char
// 	// 	std::cout << "Non displayable" << std::endl;
// }

void	ScalarConverter::convert(std::string str)
{

	std::regex printable_chars("^[ -~]+$");
	std::regex non_printable_chars("[^\x20-\x7E]");
	std::regex no_digits("^[^0-9]*$");
	std::regex is_digit("^[0-9]*$");
	std::regex is_int("^[+-]?\\d+$");
	std::regex is_double("[+-]?\\d*\\.\\d+");
	std::regex is_float("[+-]?\\d*\\.\\d+[f]");
	std::regex pseudoLiterals_float("(\\+inff|-inff|nanf)");
	std::regex pseudoLiterals_double("(\\+inf|-inf|nan)");

	double	d = strtod(str.c_str(), NULL);
	
	// CAST INT
	if (std::regex_match(str.c_str(), is_int))
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else if (std::regex_match(str.c_str(), pseudoLiterals_float) || std::regex_match(str.c_str(), pseudoLiterals_double))
		std::cout << "int: impossible" << std::endl;
	
	// CAST FLOAT
	if (std::regex_match(str.c_str(), is_float))
		std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	else if (std::regex_match(str.c_str(), pseudoLiterals_float))
		std::cout << "float: " << str << std::endl;
	else if (std::regex_match(str.c_str(), pseudoLiterals_double))
		std::cout << "float: " << str << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	
	// CAST DOUBLE
	if (std::regex_match(str.c_str(), is_double))
		std::cout << "double: " << static_cast<double>(d) << std::endl;
	else if (std::regex_match(str.c_str(), is_float))
		std::cout << "double: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<double>(d) << std::endl;
	else if (std::regex_match(str.c_str(), pseudoLiterals_double))
		std::cout << "double: " << str << std::endl;
	else
		std::cout << "double: impossible" << std::endl;

}
