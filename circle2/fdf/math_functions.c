/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 22:41:36 by fbaras            #+#    #+#             */
/*   Updated: 2025/12/23 22:41:36 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	DDA_line(t_mlx_data *mlx_data, t_point line1, t_point line2, int color)
{
	int		steps;
	float	x;
	float	y;
	int		i;

	if (fabs(delta_x) > fabs(delta_y))
		steps = fabs(delta_x);
	else
		steps = fabs(delta_y);
	i = 0;
	while (i <= steps)
	{
		my_pixel_put(mlx_data, (int)x, (int)y, color);
		x += (line2.x - line1.x) / (float)steps;
		y += (line2.y - line1.y) / (float)steps;
		i++;
	}
}

t_point	isometric_projection(t_coord p3d, int scale, int offset_x, int offset_y)
{
	t_point	p;

	p.x = (p3d.x - p3d.y) * cos(0.523599) * scale + offset_x;
	p.y = ((p3d.x + p3d.y) * sin(0.523599) - p3d.z) * scale + offset_y;

	return (p);
}

// copied from chatgpt lol
t_coord	rotate_point(t_coord p, float angle_x, float angle_y, float angle_z)
{
	t_coord	rotated;
	float	rad_x;
	float	rad_y;
	float	rad_z;
	float	y1;
	float	z1;
	float	x2;
	float	z2;

	// Convert to radians
	rad_x = angle_x * 0.0174533;
    rad_y = angle_y * 0.0174533;
    rad_z = angle_z * 0.0174533;
	y1 = p.y * cos(rad_x) - p.z * sin(rad_x);
	z1 = p.y * sin(rad_x) + p.z * cos(rad_x);
	x2 = p.x * cos(rad_y) + z1 * sin(rad_y);
	z2 = -p.x * sin(rad_y) + z1 * cos(rad_y);
	rotated.x = x2 * cos(rad_z) - y1 * sin(rad_z);
	rotated.y = x2 * sin(rad_z) + y1 * cos(rad_z);
	rotated.z = z2;
	rotated.color = p.color;
	return (rotated);
}
