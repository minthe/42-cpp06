/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:56:33 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/11 18:00:39 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.class.hpp"

/* // decided to round values
static bool	checkFractions(const char* str)
{
	std::cout << "TEST: " << *str << std::endl;
	if (*str == '.')
	{
		str++;
		if (*str && *str == '0')
		{
			while (*str || *str != 'f')
			{
				str++;
				if (*str != '0')
					return false;
			}
			return true;
		}
		return false;
	}
	return false;
}
*/

static bool	onlyDigits(const char* str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

static bool	is_float(const char* str)
{
	float	min_range = FLT_MIN;
	float	max_range = FLT_MAX;
	double	d = strtod(str, NULL);
	

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
	str++;
	if (*str)
		return false;
	if (d >= min_range && d <= max_range)
		return true;
	return false;
}

static bool	is_double(const char* str)
{
	double	min_range = DBL_MIN;
	double	max_range = DBL_MAX;
	double	d = strtod(str, NULL);

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
	if (*str == 'f' || !isdigit(*str))
		return false;
	if (d >= min_range && d <= max_range)
		return true;
	return false;
}

static bool	is_int(const char* str)
{
	int	min_range = INT_MIN;
	int	max_range = INT_MAX;
	double	d = strtod(str, NULL);

	if ((is_float(str) || is_double(str) || onlyDigits(str)) && (d >= min_range && d <= max_range))
		return true;
	return false;
}

static bool	pseudoLiterals_float(const std::string str)
{
	if (str == "+inff" || str == "-inff" || str == "nanf")
		return true;
	return false;
}

static bool	pseudoLiterals_double(const std::string str)
{
	if (str == "+inf" || str == "-inf" || str == "nan")
		return true;
	return false;
}

/*
static int	skipWhitespace(const char* str) // decided not to use it
{
	int i = 0;
	if (str[0] == ' ')
	{
		while (str[i] == ' ')
			i++;
	}
	return i;
}
*/

void	ScalarConverter::convert(std::string const convert)
{

	double	d = strtod(convert.c_str(), NULL);
	std::string str;
	// str = &convert.c_str()[skipWhitespace(convert.c_str())];
	str = convert;
	int	ascii_min = 0;
	int	ascii_max = 255;
	int	ascii_print_min = 32;
	int	ascii_print_max = 127;
	
	// std::cout << "input: '" << str << "'" << std::endl; // DEBUG
	
	// CAST CHAR
	if (convert.length() == 1 && convert.c_str()[0] >= ascii_print_min && convert.c_str()[0] <= ascii_print_max && !std::isdigit(convert.c_str()[0]))
		std::cout << "char: '" << static_cast<char>(convert.c_str()[0]) << "'" << std::endl;
	else if (convert.length() == 1 && str.c_str()[0] >= ascii_min && str.c_str()[0] <= ascii_max)
		std::cout << "char: Non displayable" << std::endl;
	else if (d >= ascii_print_min && d <= ascii_print_max && is_int(str.c_str()))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else if (onlyDigits(str.c_str()) && d >= ascii_min && d <= ascii_max)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	
	// CAST INT
	if (is_int(str.c_str()))
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else if ((convert.length() == 1 && convert.c_str()[0] >= ascii_min && convert.c_str()[0] <= ascii_max && !std::isdigit(convert.c_str()[0])))
		std::cout << "int: " << static_cast<int>(convert.c_str()[0]) << std::endl;
	else if (pseudoLiterals_float(str) == true || pseudoLiterals_double(str) == true)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	
	// CAST FLOAT
	if (is_int(str.c_str()))
		std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	else if ((convert.length() == 1 && convert.c_str()[0] >= ascii_min && convert.c_str()[0] <= ascii_max && !std::isdigit(convert.c_str()[0])))
		std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<float>(convert.c_str()[0]) << "f" << std::setprecision(0) << std::endl;
	else if (is_float(str.c_str()))
		std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<float>(d) << "f" << std::setprecision(0) << std::endl;
	else if (pseudoLiterals_float(str))
		std::cout << "float: " << str << std::endl;
	else if (pseudoLiterals_double(str))
		std::cout << "float: " << str << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;
	
	// CAST DOUBLE
	if (is_int(str.c_str()))
		std::cout << "double: " << std::fixed << std::showpoint << static_cast<double>(d) << std::endl;
	else if ((convert.length() == 1 && convert.c_str()[0] >= ascii_min && convert.c_str()[0] <= ascii_max && !std::isdigit(convert.c_str()[0])))
		std::cout << "double: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<double>(convert.c_str()[0]) << std::setprecision(0) << std::endl;
	else if (is_double(str.c_str()) || is_float(str.c_str()))
		std::cout << "double: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<double>(d) << std::setprecision(0) << std::endl;
	else if (pseudoLiterals_double(str))
		std::cout << "double: " << str << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}
