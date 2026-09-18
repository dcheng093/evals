#include "Harl.hpp"


void	Harl::complain(std::string level)
{
	std::string	levelType[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	levelInt = -1;

	for (int i = 0; i < 4; i++)
	{
		if (levelType[i] == level)
		{
			levelInt = i;
			break ;
		}
	}

	switch (levelInt)
	{
	case 0: 
		debug();
		/* fallthrough */
	case 1:
		info();
		/* fallthrough */
	case 2:
		warning();
        /* fallthrough */
	case 3:
		error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n" << "I love having extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-special-ketchup burger. \nI really do!\n"
	<< std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]\n" << "I cannot believe adding extra bacon costs more money. \n"
	<< "You didn’t put enough bacon in my burger! "
	<< "If you did, I wouldn’t be asking for more!\n"
	<< std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\n" << "I think I deserve to have some extra bacon for free. \n"
	<< "I’ve been coming for years, whereas you started working here just last month.\n"
	<< std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]\n" << "This is unacceptable! I want to speak to the manager now.\n"
	<< std::endl;
}