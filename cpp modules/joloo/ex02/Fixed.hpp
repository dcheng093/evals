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

	bool operator>(const Fixed &param) const;
	bool operator<(const Fixed &param) const;
	bool operator>=(const Fixed &param) const;
	bool operator<=(const Fixed &param) const;
	bool operator==(const Fixed &param) const;
	bool operator!=(const Fixed &param) const;

	Fixed operator+(const Fixed &param) const;
	Fixed operator-(const Fixed &param) const;
	Fixed operator*(const Fixed &param) const;
	Fixed operator/(const Fixed &param) const;

	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	static Fixed &min(Fixed &s1, Fixed &s2);
	static const Fixed &min(const Fixed &s1, const Fixed &s2);
	static Fixed &max(Fixed &s1, Fixed &s2);
	static const Fixed &max(const Fixed &s1, const Fixed &s2);
};


std::ostream &operator<<(std::ostream& os, const Fixed &param);

#endif