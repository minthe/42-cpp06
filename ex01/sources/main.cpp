/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 08:59:13 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/12 16:05:29 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.class.hpp"
#include "../includes/Data.class.hpp"
#include <iostream>

int	main()
{
	Data* bob = new Data;
	uintptr_t bob_uint = 0;

	std::cout << "&bob:\t\t\t" << bob << std::endl;
	bob_uint = Serializer::serialize(bob);
	std::cout << "serialize output:\t" << bob_uint << std::endl;
	std::cout << "deserialize output:\t" << Serializer::deserialize(bob_uint) << std::endl;

	delete bob;
	return 0;
}
