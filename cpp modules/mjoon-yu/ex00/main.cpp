/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoon-yu <mjoon-yu@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 19:36:58 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/04/18 20:58:50 by mjoon-yu         ###   ########.fr       */
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
	const Animal*	meta = new Animal();
	const Animal*	c = new Cat();
	const Animal*	d = new Dog();

	c->makeSound();
	d->makeSound();
	meta->makeSound();

	const WrongAnimal*	weta = new WrongAnimal();
	const WrongAnimal*	wc = new WrongCat();

	weta->makeSound();
	wc->makeSound();

	delete (meta);
	delete (c);
	delete (d);
	delete (weta);
	delete (wc);

	return (0);
}
