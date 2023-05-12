/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:08:20 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/12 17:11:14 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_CLASS_H
#define BASE_CLASS_H

class Base
{
	public:
		~Base();
	private:
		Base*	generate(void);
		void	identify(Base* p);
		void	identify(Base& p);
};

#endif
