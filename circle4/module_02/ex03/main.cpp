/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 22:22:04 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 22:22:04 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	a,b(5.0, 0.0), c(5.0, 10.0);

	Point	point(4, 1.0);
	Point	onEdge(5.0, 0);
	Point	outside(10.0, 3.1);

	b = Point(5.0, 0.0);
	c = Point(5.0, 10.0);

	bool is_inside = bsp(a, b, c, outside);
	bool ik_its_inside = bsp(a, b, c, point);
	bool should_be_false = bsp(a, b, c, onEdge);
	if (is_inside)
		std::cout << "the point " << outside << " is inside the triangle" << std::endl;
	else
		std::cout << "the point " << outside << " is NOT inside the triangle" << std::endl;
	if (ik_its_inside)
		std::cout << "the point " << point << " is inside the triangle" << std::endl;
	else
		std::cout << "the point " << point << " is NOT inside the triangle" << std::endl;
	if (should_be_false)
		std::cout << "the point " << onEdge << " is inside the triangle" << std::endl;
	else
		std::cout << "the point " << onEdge << " is NOT inside the triangle" << std::endl;
	return (0);
}
