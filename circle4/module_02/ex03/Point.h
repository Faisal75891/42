/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 22:23:15 by fbaras            #+#    #+#             */
/*   Updated: 2026/08/05 22:23:15 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

		// Add getters and setters here maybe - NAH
		float	getX(void) const;
		float	getY(void) const;
		~Point();
};

std::ostream	&operator<<(std::ostream &os, const Point &in);
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
