/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:57:54 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/11 14:31:31 by vfuhlenb         ###   ########.fr       */
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

	ScalarConverter::convert(argv[1]);

	return 0;
}
