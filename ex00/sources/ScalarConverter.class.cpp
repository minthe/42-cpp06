/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:56:33 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/10 12:58:35 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.class.hpp"

void	ScalarConverter::convert(std::string string)
{
	int	a;
	float b = 158458458.61223f;

	a = static_cast<double>(b);
	std::cout << string << a << std::endl;
}
