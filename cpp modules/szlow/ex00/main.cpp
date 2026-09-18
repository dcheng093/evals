#include "Zombie.hpp"

int	main()
{
	Zombie	*zombie = newZombie("HeapZombie");
	zombie->announce();
	delete zombie;

	randomChump("StackZombie");
	return 0;
}