
#ifndef POINT_H
#define POINT_H

#include "Fixed.h"

class Point
{
	private:
		Fixed const	x, y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &src);
		Point	&operator=(const Point &src);

		// Add getters and setters here maybe
		float	getX(void) const;
		float	getY(void) const;
		~Point();
};

std::ostream	&operator<<(std::ostream &os, const Point &in);

#endif
