#include "Zombie.hpp"

int	main()
{
	Zombie	*zombies = zombieHorde(3, "Clone");
	delete[] zombies;
	
	return 0;
}