#include "Point.h"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	a,b(5.0, 0.0), c(5.0, 10.0);

	Point	point(4, 1.0);
	Point	onEdge(5.0, 0);
	Point	outside(10.0, 3.1);

	b = Point(5.0, 0.0);
	c = Point(5.0, 10.0); // ?? SEGFAUTLS?!?!

	bool is_inside = bsp(a, b, c, outside);
	if (is_inside)
		std::cout << "the point " << outside << "is inside the triangle" << std::endl;
	else
		std::cout << "the point " << outside << "is NOT inside the triangle" << std::endl; 
	return (0);
}
