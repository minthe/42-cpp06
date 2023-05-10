/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:57:54 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/10 22:33:23 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.class.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2 || argv[1][0] == '\0')
	{
		std::cerr << "wrong args || empty string" << std::endl;
		return 1;
	}
	std::string str = argv[1];
	double d = strtol(str.c_str(), NULL, 10);
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	// ScalarConverter::convert(argv[1]);
	return 0;
}
