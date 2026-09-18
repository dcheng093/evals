#pragma once
#ifndef __HARL_HPP__
#define __HARL_HPP__

#include <string>
#include <iostream>
#include <cstdlib>

class Harl {
	public:
		void	complain(std::string level);

	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};


#endif
