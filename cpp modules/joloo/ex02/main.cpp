#include "Fixed.hpp"
#include <iostream>
int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << std::endl << "Subject pdf tests end" << std::endl;
	std::cout << std::endl << "Custom tests start" << std::endl;

	Fixed c(1);

	std::cout << (c > 0) << std::endl;
	std::cout << (c < 2) << std::endl;
	std::cout << (c >= 1) << std::endl;
	std::cout << (c <= 1) << std::endl;
	std::cout << (c == 1) << std::endl;
	std::cout << (c != 2) << std::endl;

	std::cout << (c + 1 + 1) << std::endl;
	std::cout << (c - 1 - 1) << std::endl;
	std::cout << (c * 1 * 2) << std::endl;
	std::cout << (Fixed(100) / (c + 1)) << std::endl;
	std::cout << (c / (float)0.5) << std::endl;
	// std::cout << (c / 0) << std::endl; // crash

	std::cout << Fixed::min(c, -1) << std::endl;
	std::cout << Fixed::max(c, -1) << std::endl;
	
	const Fixed d(1);
	const Fixed e(2);

	const Fixed f = Fixed::min(d, e);
	// f++;
	return 0;
}