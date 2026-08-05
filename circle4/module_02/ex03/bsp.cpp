/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 22:21:39 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 22:21:39 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

float	cross_product(Point const a, Point const b, Point const p)
{
	// ab . ap
	return ( (b.getX() - a.getX()) // b.x - a.x = u1
			* (p.getY() - a.getY()) // p.y - a.y = v2
			- (b.getY() - a.getY()) // b.y - a.y = u2
			* (p.getX() - a.getX()) ); // p.x - a.x = v1
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	abp, bcp, acp;
	
	abp = cross_product(a, b, point);
	bcp = cross_product(b, c, point);
	acp = cross_product(c, a, point);

	if (abp > 0 && bcp > 0 && acp > 0)
		return (true);
	else if (abp < 0 && bcp < 0 && acp < 0)
		return (true);
	return (false);
}

/*

e.g points.
a (4, 2)
b (8, 6)
c (12, 4)

p(11, 5)
____________________                  
|                  |  9
|                  |
|                  |
|        b         | 6
|                  |
|            c     | 4
|                  |
|    a             | 2
|__________________|
0    4    8   12   18

Check if point is:
 Is to the right or to the left
 of all the vectors
 
cross product: u.v = (u1 * v2) - (u2 * v1)
->
AB = (B - A) = (B.x - A.x)(B.y - A.y)

To see if the point is inside. AP.AB && CP.CB && AC.AP are strictly +/-
AP.AB = ((B.x - A.x) * (P.y - A.y)) - (B.y - A.y) * (P.x - A.x)
			->AP
*/