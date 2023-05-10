/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:56:33 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/10 17:09:02 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.class.hpp"
#include <cstdlib>
#include <regex>

void	nan()

void	printOutput(std::string s_char, int* s_int, float* s_float, double* s_double)
{
	std::cout << "char: " << s_char << std::endl;
	if (s_int)
		std::cout << "int: " << s_int << std::endl;
	else
		std::cout << "impossible" << std::endl;
	if (s_float)
		std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(1) << s_float << "f" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	if (s_double)
		std::cout << "double: " << s_double << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void	ScalarConverter::convert(std::string string)
{

	std::regex printable_chars("^[ -~]+$");
	std::regex non_printable_chars("[^\x20-\x7E]");
	std::regex no_digits("^[^0-9]*$");
	std::regex is_int("^[+-]?\\d+$");
	std::regex is_double("[+-]?(([0-9]+(\\.[0-9]*)?)|(\\.[0-9]+))([eE][+-]?[0-9]+)?([fF]|(l{0,2}))");
	std::regex is_float("[+-]?(([0-9]+(\\.[0-9]*)?)|(\\.[0-9]+))");
	std::regex pseudoLiterals_float("(\\+inff|-inff|nanf)");
	std::regex pseudoLiterals_double("(\\+inf|-inf|nan)");

	double	s_double;
	(void)s_double;
	
	// SCALAR CHAR
	if (string.length() == 1 && std::regex_match(string.c_str(), non_printable_chars)) // check for non-printable char
		std::cout << "Non displayable" << std::endl;
	else if (string.length() == 1 && std::regex_match(string.c_str(), printable_chars) && std::regex_match(string.c_str(), no_digits)) // checks for printable char
		std::cout << "char: '" << static_cast<char>(string.c_str()[0]) << "'" << std::endl;

	// SCALAR INT
	
	// SCALAR FLOAT
	if (string == "-inff" || string == )

// 	a = std::strtod(string.c_str(), NULL);

// static_cast<double>(s_double) << std::endl;
	

}
