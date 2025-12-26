/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:36:34 by fbaras            #+#    #+#             */
/*   Updated: 2025/12/26 18:36:34 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_image(t_mlx_data *mlx_data)
{
	mlx_data->img = mlx_new_image(mlx_data->mlx_ptr, WIDTH, HEIGHT);
	mlx_data->addr = mlx_get_data_addr(mlx_data->img, &mlx_data->bpp, &mlx_data->line_length, &mlx_data->endian);
}

void	init_fdf_map(t_mlx_data *mlx_data, char *filename)
{
	mlx_data->filename = filename;
	mlx_data->fdf_map = get_fdf_map(mlx_data->filename);
}

t_map	*allocate_and_init_map(char *map_name)
{
	t_map	*map;

	map = malloc (sizeof(t_map));
	map->width = 0;
	map->rotate_x = 0;
	map->rotate_y = 0;
	map->rotate_z = 0;
	map->translate_x = 0;
	map->translate_y = 0;
	map->scale_offset = 0;
	map->height = get_map_height(map_name);
	map->array = malloc(sizeof(t_coord *) * map->height);
	map->rows_filled = 0;
	return (map);
}
