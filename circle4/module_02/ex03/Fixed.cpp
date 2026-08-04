#include "Fixed.h"


Fixed::Fixed() : fixed_val(0)
{
	// std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	// std::cout << "Int Constructor called" << std::endl;
	fixed_val = n << f_bits;
}

Fixed::Fixed(const float n)
{
	// std::cout << "Float Constructor called" << std::endl;
	fixed_val = roundf(n * (1 << f_bits));
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
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;

	return (fixed_val);
}

void Fixed::setRawBits ( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;

	fixed_val = raw;
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(src.getRawBits());
}

// copy assignment operator
Fixed& Fixed::operator=(const Fixed &src)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(src.getRawBits());
	return *this;
}

bool    operator>(const Fixed &f1, const Fixed &f2)
{
	return (f1.getRawBits() > f2.getRawBits());
}

bool    operator<(const Fixed &f1, const Fixed &f2)
{
	return (f1.getRawBits() < f2.getRawBits());
}

bool    operator>=(const Fixed &f1, const Fixed &f2)
{
	return (f1.getRawBits() >= f2.getRawBits());
}

bool    operator<=(const Fixed &f1, const Fixed &f2)
{
	return (f1.getRawBits() <= f2.getRawBits());
}

bool    operator==(const Fixed &f1, const Fixed &f2)
{
	return (f1.getRawBits() == f2.getRawBits());
}

bool    operator!=(const Fixed &f1, const Fixed &f2)
{
	return (f1.getRawBits() != f2.getRawBits());
}

Fixed	operator+(const Fixed &f1, const Fixed &f2)
{
	float	sum;
	Fixed	temp;

	sum = f1.toFloat() - f2.toFloat();
	temp = sum;
	return (temp);
}

Fixed	operator-(const Fixed &f1, const Fixed &f2)
{
	float	sum;
	Fixed	temp;

	sum = f1.toFloat() - f2.toFloat();
	temp = sum;
	return (temp);
}

Fixed	operator*(const Fixed &f1, const Fixed &f2)
{
	float	sum;
	Fixed	temp;

	sum = f1.toFloat() * f2.toFloat();
	temp = sum;
	return (temp);
}

Fixed	operator/(const Fixed &f1, const Fixed &f2)
{
	float	sum;
	Fixed	temp;

	sum = f1.toFloat() / f2.toFloat();
	temp = sum;
	return (temp);
}

Fixed& Fixed::operator++(void)
{
	float n = float(this->toFloat()) + 1.0 / (1 << f_bits);
	fixed_val = n * (1 << f_bits);
	return *this;
}

Fixed& Fixed::operator--(void)
{
	float n = float(this->toFloat()) - 1.0 / (1 << f_bits);
	fixed_val = n * (1 << f_bits);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed	temp;

	temp.fixed_val = fixed_val;
	float n = float(this->toFloat()) + 1.0 / (1 << f_bits);
	fixed_val = n * (1 << f_bits);
	return temp;
}

Fixed& Fixed::operator--(int)
{
	float n = float(this->toFloat()) - 1.0 / (1 << f_bits);
	fixed_val = n * (1 << f_bits);
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Fixed &src)
{
	os << src.toFloat();
	return (os);
}
