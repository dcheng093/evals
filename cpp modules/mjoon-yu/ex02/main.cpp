/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:36:58 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/07/31 15:03:43 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#include <iostream>

using std::cout;
using std::endl;

int	main(void)
{
	// INFO: Not constructable as Animal class is abstract
	//Animal animal("Dog");

	Animal	*cat= new Cat();

	cout << "===== Setting Cat ideas  =====" << endl;
	cat->setIdeas(0, "catch rat");
	cat->setIdeas(3, "eat fish");
	cat->setIdeas(23, "climb trees");
	cout << "===== Showing Cat ideas  =====" << endl;
	cat->showIdeas();

	Animal	*cat1 = cat->clone();

	cout << "===== Setting Cat idea 0 =====" << endl;
	cat->setIdeas(0, "fly away");

	cout << "===== Showing Cat ideas  =====" << endl;
	cat->showIdeas();

	cout << "===== Showing Copy ideas  =====" << endl;
	cat1->showIdeas();

	delete (cat);
	delete (cat1);
	return (0);
}
