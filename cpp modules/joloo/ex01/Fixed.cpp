#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::_fracBits = 8;

Fixed::Fixed(void) : _raw(0)
{
	std::cout << "constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int param)
{
	std::cout << "int constructor called" << std::endl;
	this->_raw = param << this->_fracBits;
	return ;
}

// roundf rounds to the nearest whole number
Fixed::Fixed(const float param)
{
	std::cout << "float constructor called" << std::endl;
	this->_raw = roundf(param * (1 << this->_fracBits));
	return ;
}

Fixed::Fixed(const Fixed &param)
{
	std::cout << "copy constructor called" << std::endl;
	this->_raw = param._raw;
	return ;
}

Fixed &Fixed::operator=(const Fixed &param)
{
	std::cout << "copy assignment operator called" << std::endl;
	this->_raw = param._raw;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "destructor called" << std::endl;
	return ;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_raw);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw = raw;
	return ;
}

float Fixed::toFloat(void) const
{
	return (((float)this->_raw) / (1 << this->_fracBits));
}

int Fixed::toInt(void) const
{
	return (this->_raw / (1 << this->_fracBits));
}

std::ostream &operator<<(std::ostream& os, const Fixed &param)
{
	std::cout << param.toFloat();
	return (os);
}