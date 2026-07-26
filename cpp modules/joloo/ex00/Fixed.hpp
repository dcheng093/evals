#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int	_raw;
	static const int	_fracBits;

public:
	Fixed(void);
	Fixed(const Fixed &param);
	Fixed & operator=(const Fixed &param);
	~Fixed(void);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif