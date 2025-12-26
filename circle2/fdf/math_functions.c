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

void	dda_line(t_mlx_data *mlx_data, t_point point1,
				t_point point2, int color)
{
	int		steps;
	float	x;
	float	y;
	int		i;

	if (abs((point2.x - point1.x)) > abs((point2.y - point1.y)))
		steps = abs(point2.x - point1.x);
	else
		steps = abs(point2.y - point1.y);
	i = 0;
	x = point1.x;
	y = point1.y;
	while (i <= steps)
	{
		my_pixel_put(mlx_data, (int)x, (int)y, color);
		x += (point2.x - point1.x) / (float)steps;
		y += (point2.y - point1.y) / (float)steps;
		i++;
	}
}

t_point	project_point(t_mlx_data *mlx_data, int x, int y)
{
	t_coord	p1;
	t_point	coord;

	p1.x = x - mlx_data->fdf_map->width / 2;
	p1.y = y - mlx_data->fdf_map->height / 2;
	p1.z = mlx_data->fdf_map->array[y][x].z * HEIGHT_MULTIPLIER;
	p1.color = mlx_data->fdf_map->array[y][x].color;
	p1 = rotate_point(p1, mlx_data);
	coord = isometric_projection(p1, mlx_data);
	return (coord);
}

/*
typedef struct s_coord				typedef struct s_point
{									{
	int	x;								int	x;
	int	y;				--->			int	y;
	int	z;								int	color;
	int	color;						}	t_point;
}	t_coord;						
	
	x' = (x - y) * cos(30) * scale + offset_x;
	y' = ((x + y) * sin(30) - z) * scale + offset_y;
	30degrees = 0.523599 radians.

	0.523599 (30°) = standard isometric
	0.785398 (45°)
	40 -> 0.698132
	50 -> 0.872665
*/
t_point	isometric_projection(t_coord p3d, t_mlx_data *data)
{
	t_point	p;

	p.x = (p3d.x - p3d.y) * cos(0.785398)
		* (data->fdf_map->scale + data->fdf_map->scale_offset)
		+ data->fdf_map->offset_x + data->fdf_map->translate_x + (WIDTH / 2);
	p.y = ((p3d.x + p3d.y) * sin(0.785398) - p3d.z)
		* (data->fdf_map->scale + data->fdf_map->scale_offset)
		+ data->fdf_map->offset_y + data->fdf_map->translate_y + (HEIGHT / 2);
	p.color = p3d.color;
	return (p);
}

// copied from chatgpt lol
t_coord	rotate_point(t_coord p, t_mlx_data *data)
{
	t_coord	rotated;
	float	y1;
	float	z1;
	float	x2;
	float	z2;

	y1 = p.y * cos(data->fdf_map->rotate_x * 0.0174533)
		- p.z * sin(data->fdf_map->rotate_x * 0.0174533);
	z1 = p.y * sin(data->fdf_map->rotate_x * 0.0174533)
		+ p.z * cos(data->fdf_map->rotate_x * 0.0174533);
	x2 = p.x * cos(data->fdf_map->rotate_y * 0.0174533)
		+ z1 * sin(data->fdf_map->rotate_y * 0.0174533);
	z2 = -p.x * sin(data->fdf_map->rotate_y * 0.0174533)
		+ z1 * cos(data->fdf_map->rotate_y * 0.0174533);
	rotated.x = x2 * cos(data->fdf_map->rotate_z * 0.0174533)
		- y1 * sin(data->fdf_map->rotate_z * 0.0174533);
	rotated.y = x2 * sin(data->fdf_map->rotate_z * 0.0174533)
		+ y1 * cos(data->fdf_map->rotate_z * 0.0174533);
	rotated.z = z2;
	rotated.color = p.color;
	return (rotated);
}
