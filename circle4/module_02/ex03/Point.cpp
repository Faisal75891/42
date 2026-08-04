#include "Point.h"

Point::Point() : x(0), y(0)
{
	// Fixed   x(0);
    // Fixed   y(0);
}

Point::Point(const float x2, const float y2) : x(x2), y(y2)
{
	// Fixed x(x2);
	// Fixed y(y2);
}

Point::Point(const Point &src) : x(src.x), y(src.y)
{
	// x = src.x;
	// y = src.y;
}

Point	&Point::operator=(const Point &src)
{
	if (this != &src)
	{
		// this->~Point();
		new (this) Point(src);
	}
	return (*this);
}

float	Point::getX(void) const
{
	return (x.toFloat());
}

float	Point::getY(void) const
{
	return (y.toFloat());
}


Point::~Point()
{
	// std::cout << "nigga\n";
}

std::ostream	&operator<<(std::ostream &os, const Point &in)
{
	os << "P(" << in.getX() << " " << in.getY() << ") ";
	return (os);
}
