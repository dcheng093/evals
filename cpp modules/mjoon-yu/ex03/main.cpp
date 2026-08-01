/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcheng <dcheng@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:51:33 by mjoon-yu          #+#    #+#             */
/*   Updated: 2026/07/31 15:24:01 by dcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "define.h"

#include <iostream>

using std::endl;
using std::cout;

int	main(void)
{
	cout << BLUE << "========== Creating new materia source ==========" << WHITE << endl;
 	// Source of materia to be created
	IMateriaSource* src = new MateriaSource();

	cout << BLUE << "========== Learning Materia ==========" << WHITE << endl;
	// Source that learns materia
    AMateria *tmp = new Ice();
	src->learnMateria(tmp);
    delete tmp;
    tmp = new Cure();
	src->learnMateria(tmp);
    delete tmp;
	
	cout << BLUE << "========== Creating new Character (Held by ICharacter) ==========" << WHITE << endl;
	ICharacter* me = new Character("me");
	
	//cout << BLUE << "========== Temp Materia ==========" << WHITE << endl;

	cout << BLUE << "========== Creating materia from source and equipped by character ==========" << WHITE << endl;
	// Characters only equip from source
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	cout << BLUE << "========== Creating new Character Jim ==========" << WHITE << endl;
	Character jim("jim");

	cout << BLUE << "========== Creating materia from source and equipped by Jim ==========" << WHITE << endl;
	tmp = src->createMateria("cure");
	jim.equip(tmp);
	tmp = src->createMateria("cure");
	jim.equip(tmp);
	
	cout << BLUE << "========== Creating new Character held by ICharacter from Jim ==========" << WHITE << endl;
	ICharacter* bob = new Character(jim);
	
	cout << BLUE << "========== Using materia ==========" << WHITE << endl;
	me->use(0, *bob);
	bob->use(0, *me);
	
	delete bob;
	delete me;
	delete src;
	return (0);
}
