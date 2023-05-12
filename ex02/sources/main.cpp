/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:54:51 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/05/12 21:54:22 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.class.hpp"
#include "../includes/A.class.hpp"
#include "../includes/B.class.hpp"
#include "../includes/C.class.hpp"
#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>

static Base*	generate(void)
{
    srand (time(NULL));

	switch (rand() % 3) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			break ;
	}

	return NULL;
}

static void		identify(Base* p) // Explicit downcast with pointer to class
{
	A*	a = dynamic_cast<A*>(p);
	B*	b = dynamic_cast<B*>(p);
	C*	c = dynamic_cast<C*>(p);

	if (a) {
		std::cout << "identified: class A *" << std::endl;
		return ;
	}
	else if (b) {
		std::cout << "identified: class B *" << std::endl;
		return ;
	}
	else if (c) {
		std::cout << "identified: class C *" << std::endl;
		return ;
	}

	std::cout << "no type identified" << std::endl;

	return ;
}

static void		identify(Base& p) // Explicit downcast with reference to class
{
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "identified: class A &" << std::endl;
		return ;
	}
	catch (std::bad_cast &bc_a) {}
	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "identified: class B &" << std::endl;
		return ;
	}
	catch (std::bad_cast &bc_b) {}
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "identified: class C &" << std::endl;
		return ;
	}
	catch (std::bad_cast &bc_c) {}

	std::cout << "no type identified" << std::endl;

	return ;
}

int	main()
{
	Base* p = generate();

	identify(p);
	identify(*p);

	if (p)
		delete p;
	return 0;
}
