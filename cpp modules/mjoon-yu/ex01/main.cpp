/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:36:58 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/07/31 14:57:13 by dcheng           ###   ########.fr       */
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
	cout << "=========== Deep copy test ==========" << endl;
	Animal	*cat= new Cat();

	cout << "===== Setting Cat ideas  =====" << endl;
	cat->setIdeas(0, "catch rat");
	cat->setIdeas(3, "eat fish");
	cat->setIdeas(23, "climb trees");
	cout << "===== Showing Cat ideas  =====" << endl;
	cat->showIdeas();

	Animal	*cat1 = cat->clone();
	
	cout << "===== Setting Cat idea 0 to 'fly away' =====" << endl;
	cat->setIdeas(0, "fly away");

	cout << "===== Showing Cat ideas  =====" << endl;
	cat->showIdeas();

	cout << "===== Showing Copy ideas  =====" << endl;
	cat1->showIdeas();

	delete (cat);
	delete (cat1);

	cout << "========== Animal pointer array test ==========" << endl;
	Animal *set[6] = {new Cat(), new Cat(), new Cat(), new Dog(), new Dog(), new Dog()};
	for (int i = 0; i < 6; i++)
	{
		set[i]->makeSound();
		delete (set[i]);
	}
	return (0);
}
