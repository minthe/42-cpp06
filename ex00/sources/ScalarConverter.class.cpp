/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:56:33 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/11 15:35:41 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.class.hpp"
#include <cctype>
#include <cstdlib>

static bool	is_int(const char* str)
{
	int	min_range = INT_MIN;
	int	max_range = INT_MAX;
	double	d;

	if (*str == '+' || *str == '-')
		str++;
	if (!isdigit(*str))
		return false;
	while (*str && isdigit(*str))
		str++;
	if (*str && !isdigit(*str))
		return false;
	d = strtod(str, NULL);
	if (d >= min_range && d <= max_range)
		return true;
	return false;
}

static bool	is_float(const char* str)
{
	float	min_range = FLT_MIN;
	float	max_range = FLT_MAX;
	double	d;

	if (*str == '+' || *str == '-')
		str++;
	if (!isdigit(*str))
		return false;
	while (*str && isdigit(*str))
		str++;
	if (*str != '.')
		return false;
	str++;
	if (!isdigit(*str))
		return false;
	while (*str && isdigit(*str))
		str++;
	if (*str && *str != 'f')
		return false;
	d = strtod(str, NULL);
	if (d >= min_range && d <= max_range)
		return true;
	return false;
}

static bool	is_double(const char* str)
{
	double	min_range = DBL_MIN;
	double	max_range = DBL_MAX;
	double	d;

	if (*str == '+' || *str == '-')
		str++;
	if (!isdigit(*str))
		return false;
	while (*str && isdigit(*str))
		str++;
	if (*str != '.')
		return false;
	str++;
	if (!isdigit(*str))
		return false;
	while (*str && isdigit(*str))
		str++;
	if (*str == 'f')
		return false;
	d = strtod(str, NULL);
	if (d >= min_range && d <= max_range)
		return true;
	return false;
}

static bool	pseudoLiterals_float(std::string str)
{
	if (str == "+inff" || str == "-inff" || str == "nanf")
		return true;
	return false;
}

static bool	pseudoLiterals_double(std::string str)
{
	if (str == "+inf" || str == "-inf" || str == "nan")
		return true;
	return false;
}

void	ScalarConverter::convert(std::string str)
{

	double	d = strtod(str.c_str(), NULL);
	int	ascii_min = 0;
	int	ascii_max = 255;
	int	ascii_print_min = 32;
	int	ascii_print_max = 127;
	
	std::cout << d << std::endl;
	
	// CAST CHAR
	if (str.length() == 1 && str.c_str()[0] >= ascii_print_min && str.c_str()[0] <= ascii_print_max && !std::isdigit(str.c_str()[0]))
		std::cout << "char: '" << static_cast<char>(str.c_str()[0]) << "'" << std::endl;
	else if (d >= ascii_print_min && d <= ascii_print_max)
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else if (str.length() == 1 && str.c_str()[0] >= ascii_min && str.c_str()[0] <= ascii_max)
		std::cout << "char: Non displayable" << std::endl;
	else if (d >= ascii_min && d <= ascii_max)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	
	// CAST INT
	if (is_int(str.c_str()))
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else if (pseudoLiterals_float(str) == true || pseudoLiterals_double(str) == true)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	
	// CAST FLOAT
	if (is_int(str.c_str()))
		std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	else if (is_float(str.c_str()))
		std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	else if (pseudoLiterals_float(str))
		std::cout << "float: " << str << std::endl;
	else if (pseudoLiterals_double(str))
		std::cout << "float: " << str << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	
	// CAST DOUBLE
	if (is_int(str.c_str()))
		std::cout << "double: " << std::fixed << std::showpoint << static_cast<double>(d) << std::endl;
	else if (is_double(str.c_str()) || is_float(str.c_str()))
		std::cout << "double: " << std::fixed << std::showpoint << static_cast<double>(d) << std::endl;
	else if (pseudoLiterals_double(str))
		std::cout << "double: " << str << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}
