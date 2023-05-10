/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:11:59 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/10 19:40:45 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_H
#define SCALAR_CONVERTER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>


class ScalarConverter // static class (only static members)
{
	public:
		static void convert(std::string str);

	private:
		ScalarConverter() {}
		~ScalarConverter() {}
};

#endif
