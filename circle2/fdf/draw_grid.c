/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:10:41 by fbaras            #+#    #+#             */
/*   Updated: 2025/12/26 18:10:41 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_grid(t_mlx_data *mlx_data)
{
	t_point	p1;
	t_point	p2;
	int		y;
	int		x;

	y = 0;
	while (y < mlx_data->fdf_map->height)
	{
		x = 0;
		while (x < mlx_data->fdf_map->width)
		{
			p1 = project_point(mlx_data, x, y);
			if (x + 1 < mlx_data->fdf_map->width)
			{
				p2 = project_point(mlx_data, x + 1, y);
				dda_line(mlx_data, p1, p2, p1.color);
			}
			if (y + 1 < mlx_data->fdf_map->height)
			{
				p2 = project_point(mlx_data, x, y + 1);
				dda_line(mlx_data, p1, p2, p1.color);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_data->mlx_ptr,
		mlx_data->win_ptr, mlx_data->img, 0, 0);
}
