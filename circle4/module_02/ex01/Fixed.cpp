#include "Fixed.h"


Fixed::Fixed() : val(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int Constructor called" << std::endl;
	val = n << f_bits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float Constructor called" << std::endl;
	val = n * (1 << f_bits);
}

float	Fixed::toFloat( void ) const
{
	int	ya = getRawBits();
	float	float_val = 0.0;

	float_val = float(ya) / (1 << f_bits);
	return (float_val);
}

int		Fixed::toInt(void) const
{	
	int	ya = getRawBits();

	ya = ya >> f_bits;
	return (int(ya));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;

	return (val);
}

void Fixed::setRawBits ( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;

	val = raw;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(src.getRawBits());
}

// copy assignment operator
Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(src.getRawBits());
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Fixed &src)
{
	os << src.toFloat();
	return (os);
}
