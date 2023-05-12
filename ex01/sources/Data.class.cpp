/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:34:46 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/12 15:53:48 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.class.hpp"

Data::Data() : _name("default name") {}
Data::~Data() {}

Data::Data(const Data& src)
{
	*this = src;
}

Data& Data::operator=(const Data& rhs)
{
	(void)rhs;
	return *this;
}

std::string Data::getName() const
{
	return _name;
}
