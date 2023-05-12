/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.class.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:11:59 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/12 12:59:15 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_H
#define SCALAR_CONVERTER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <float.h>
#include <cstdlib>
#include <climits>
#include <cfloat>


class ScalarConverter // static class (only static members)
{
	public:
		static void convert(std::string const convert);

	private:
		ScalarConverter();
		~ScalarConverter();
};

#endif
