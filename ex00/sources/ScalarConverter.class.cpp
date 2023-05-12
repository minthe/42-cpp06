/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:56:33 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/12 12:58:37 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.class.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

int	ascii_min = 0;
int	ascii_max = 255;
int	ascii_print_min = 32;
int	ascii_print_max = 127;

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
	while (isdigit(*str))
		str++;
	if (*str == 'f')
		str++;
	if (*str != '\0')
		return false;
	return true;
}

static bool	is_double(const char* str)
{
	if (*str == '+' || *str == '-')
		str++;
	if (!isdigit(*str))
		return false;
	while (*str && isdigit(*str))
		str++;
	if (*str == '\0')
		return true;
	else if (*str != '.')
		return false;
	str++;
	if (!isdigit(*str))
		return false;
	while (isdigit(*str))
		str++;
	if (*str == 'f' || !isdigit(*str))
		return false;
	return true;
}

static bool	is_int(const char* str)
{
	int	min_range = INT_MIN;
	int	max_range = INT_MAX;
	double	d = strtod(str, NULL);

	if (*str == '+' || *str == '-')
		str++;
	if (!isdigit(*str))
		return false;
	while (*str && isdigit(*str))
		str++;
	if (*str == '\0')
	{
		if (d < min_range || d > max_range)
			return false;
		else
			return true;
	}
	else if (*str != '.')
		return false;
	str++;
	if (!isdigit(*str))
		return false;
	while (isdigit(*str))
	{
		if (*str != '0')
			return false;
		str++;
	}
	if (*str && *str != 'f')
		return false;
	str++;
	if (*str != '\0')
		return false;
	if (d < min_range || d > max_range)
		return false;
	return true;
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

static void	castFloat(double const d, std::string const convert)
{
	if ((convert.length() == 1 && convert.c_str()[0] >= ascii_min && convert.c_str()[0] <= ascii_max && !std::isdigit(convert.c_str()[0])))
	{
		std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<float>(convert.c_str()[0]) << "f" << std::endl;
		return ;
	}
	else if (is_float(convert.c_str()))
	{
		std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		return ;
	}
	else if (is_double(convert.c_str()))
	{
		std::cout << "float: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		return ;
	}
	else if (pseudoLiterals_float(convert))
	{
		std::cout << "float: " << convert << std::endl;
		return ;
	}
	else if (pseudoLiterals_double(convert))
	{
		std::cout << "float: " << convert << "f" << std::endl;
		return ;
	}
	std::cout << "float: impossible" << std::endl;
}

static void	castInt(double const d, std::string const convert)
{
	if (is_int(convert.c_str()))
	{
		std::cout << "int: " << static_cast<int>(d) << std::endl;
		return ;
	}
	else if ((convert.length() == 1 && convert.c_str()[0] >= ascii_min && convert.c_str()[0] <= ascii_max && !std::isdigit(convert.c_str()[0])))
	{
		std::cout << "int: " << static_cast<int>(convert.c_str()[0]) << std::endl;
		return ;
	}
	std::cout << "int: impossible" << std::endl;
}

static void	castChar(double const d, std::string const convert)
{
	if (convert.length() == 1 && convert.c_str()[0] >= ascii_print_min && convert.c_str()[0] <= ascii_print_max && !std::isdigit(convert.c_str()[0]))
		std::cout << "char: '" << static_cast<char>(convert.c_str()[0]) << "'" << std::endl;
	else if (convert.length() == 1 && convert.c_str()[0] >= ascii_min && convert.c_str()[0] <= ascii_max)
		std::cout << "char: Non displayable" << std::endl;
	else if (d >= ascii_print_min && d <= ascii_print_max && is_int(convert.c_str()))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else if (onlyDigits(convert.c_str()) && d >= ascii_min && d <= ascii_max)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

static void castDouble(double const d, std::string const convert)
{
	if ((convert.length() == 1 && convert.c_str()[0] >= ascii_min && convert.c_str()[0] <= ascii_max && !std::isdigit(convert.c_str()[0])))
	{
		std::cout << "double: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<double>(convert.c_str()[0]) << std::endl;
		return ;
	}
	else if (is_double(convert.c_str()) || is_float(convert.c_str()))
	{
		std::cout << "double: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<double>(d) << std::endl;
		return ;
	}
	else if (is_int(convert.c_str()))
	{
		std::cout << "double: " << std::fixed << std::showpoint << std::setprecision(1) << static_cast<double>(d) << std::endl;
		return ;
	}
	else if (pseudoLiterals_double(convert))
	{
		std::cout << "double: " << convert << std::endl;
		return ;
	}
	std::cout << "double: impossible" << std::endl;
}

void	ScalarConverter::convert(std::string const convert)
{
	double	d = strtod(convert.c_str(), NULL);
	// std::cout << "input: '" << d << "'" << std::endl; // DEBUG

	castChar(d, convert);
	castInt(d, convert);
	castFloat(d, convert);
	castDouble(d, convert);
}
