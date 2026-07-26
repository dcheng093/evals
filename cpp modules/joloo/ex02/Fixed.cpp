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

bool Fixed::operator>(const Fixed &param) const
{
	// std::cout << "greater than operator called" << std::endl;
	return (this->_raw > param._raw);
}

bool Fixed::operator<(const Fixed &param) const
{
	// std::cout << "lesser than operator called" << std::endl;
	return (this->_raw < param._raw);
}

bool Fixed::operator>=(const Fixed &param) const
{
	// std::cout << "greater than or equal to operator called" << std::endl;
	return (this->_raw >= param._raw);
}

bool Fixed::operator<=(const Fixed &param) const
{
	// std::cout << "lesser than  or equal to operator called" << std::endl;
	return (this->_raw <= param._raw);
}

bool Fixed::operator==(const Fixed &param) const
{
	// std::cout << "equal to operator called" << std::endl;
	return (this->_raw == param._raw);
}

bool Fixed::operator!=(const Fixed &param) const
{
	// std::cout << "not equal to operator called" << std::endl;
	return (this->_raw != param._raw);
}

Fixed Fixed::operator+(const Fixed &param) const
{
	// std::cout << "plus operator called" << std::endl;
	Fixed ret;

	ret._raw = this->_raw + param._raw;
	return (ret);
}

Fixed Fixed::operator-(const Fixed &param) const
{
	// std::cout << "minus operator called" << std::endl;
	Fixed ret;

	ret._raw = this->_raw - param._raw;
	return (ret);
}

Fixed Fixed::operator*(const Fixed &param) const
{
	// std::cout << "mult operator called" << std::endl;
	Fixed ret;

	ret._raw = (this->_raw * param._raw) / (1 << this->_fracBits);
	return (ret);
}

Fixed Fixed::operator/(const Fixed &param) const
{
	// std::cout << "div operator called" << std::endl;
	Fixed ret;

	ret._raw = (this->_raw * (1 << this->_fracBits) / param._raw);
	return (ret);
}

Fixed &Fixed::operator++()
{
	// std::cout << "pre-increment operator called" << std::endl;
	this->_raw++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	// std::cout << "post-increment operator called" << std::endl;
	Fixed temp(*this);

	this->_raw++;
	return (temp);
}

Fixed &Fixed::operator--()
{
	// std::cout << "pre-decrement operator called" << std::endl;
	this->_raw--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	// std::cout << "post-decrement operator called" << std::endl;
	Fixed temp(*this);

	this->_raw--;
	return (temp);
}

Fixed &Fixed::min(Fixed &s1, Fixed &s2)
{
	// std::cout << "min function called" << std::endl;
	if (s1._raw < s2._raw)
		return (s1);
	return (s2);
}

const Fixed &Fixed::min(const Fixed &s1, const Fixed &s2)
{
	// std::cout << "const min function called" << std::endl;
	if (s1._raw < s2._raw)
		return (s1);
	return (s2);
}

Fixed &Fixed::max(Fixed &s1, Fixed &s2)
{
	if (s1._raw > s2._raw)
		return (s1);
	return (s2);
}

const Fixed &Fixed::max(const Fixed &s1, const Fixed &s2)
{
	if (s1._raw > s2._raw)
		return (s1);
	return (s2);
}