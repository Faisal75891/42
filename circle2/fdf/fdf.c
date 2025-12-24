/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:36:18 by fbaras            #+#    #+#             */
/*   Updated: 2025/12/18 19:51:13 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	project_point(t_mlx_data *mlx_data, int x, int y)
{
	t_coord	p1;
	t_point coord;

	p1.x = x;
	p1.y = y;
	p1.z = mlx_data->fdf_map->array[y][x].z;
	p1.color = mlx_data->fdf_map->array[y][x].color;
	p1 = rotate_point(p1, mlx_data->fdf_map->rotate_x,
			mlx_data->fdf_map->rotate_y,
			mlx_data->fdf_map->rotate_z);
	coord = isometric_projection(p1, mlx_data->fdf_map->scale, mlx_data->fdf_map->scale_offset,
			mlx_data->fdf_map->offset_x + mlx_data->fdf_map->translate_x,
			mlx_data->fdf_map->offset_y + mlx_data->fdf_map->translate_y);
	return (coord);
}

void	draw_grid(t_mlx_data *mlx_data)
{
	t_point	p1;
	t_point	p2;
	int		y;
	int		x;

	y = 0;
	while(y < mlx_data->fdf_map->height)
	{
		x = 0;
		while (x < mlx_data->fdf_map->width)
		{			
			p1 = project_point(mlx_data, x, y);
			if (x + 1< mlx_data->fdf_map->width)
			{
				p2 = project_point(mlx_data, x + 1, y);
				//DDA_line(mlx_data, p1, p2, p1.color);
				wu_line(mlx_data, p1, p2);
			}
			if (y + 1 < mlx_data->fdf_map->height)
			{
				p2 = project_point(mlx_data, x, y + 1);
				//DDA_line(mlx_data, p1, p2, p1.color);
				wu_line(mlx_data, p1, p2);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, mlx_data->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_mlx_data	*mlx_data;

	if (argc != 2)
		return (1);

	// TODO: add mouse interactions
	// TODO: fix the LINE algorithm
	mlx_data = init_mlx_and_window_and_fdf_map(argv[1]);
	draw_grid(mlx_data); // initial grid.

	mlx_loop_hook(mlx_data->mlx_ptr, &do_nothing, mlx_data);
	mlx_key_hook(mlx_data->win_ptr, &handle_exit, mlx_data);

	mlx_loop(mlx_data->mlx_ptr);
}
