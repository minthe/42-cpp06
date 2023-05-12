/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:34:37 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/12 12:43:33 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_CLASS_H
#define DATA_CLASS_H

#include <iostream>

class Data
{
	public:
		Data();
		Data(const Data& src);
		Data& operator=(const Data& rhs);
		~Data();

		std::string	getName() const;

	private:
		const std::string _name;
};

#endif
