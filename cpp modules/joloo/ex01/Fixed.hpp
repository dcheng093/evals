#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int	_raw;
	static const int	_fracBits;

public:
	Fixed(void);
	Fixed(const int param);
	Fixed(const float param);
	Fixed(const Fixed &param);
	Fixed &operator=(const Fixed &param);
	~Fixed(void);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat(void) const;
	int toInt(void) const;
};


std::ostream &operator<<(std::ostream& os, const Fixed &param);

#endif