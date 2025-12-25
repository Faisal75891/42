/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:29:14 by fbaras            #+#    #+#             */
/*   Updated: 2025/12/23 23:29:14 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx_data	*init_mlx(void)
{
	t_mlx_data *mlx_data;

	mlx_data = malloc (sizeof(t_mlx_data));
	if (!mlx_data)
		return (NULL);
	mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
		return (NULL);
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, WIDTH, HEIGHT, "sigma");
	if (mlx_data->win_ptr == NULL)
	{
		free(mlx_data->mlx_ptr);
		return (NULL);
	}
	return (mlx_data);
}

void    init_image(t_mlx_data *mlx_data)
{
	mlx_data->img = mlx_new_image(mlx_data->mlx_ptr, WIDTH, HEIGHT);
	mlx_data->addr = mlx_get_data_addr(mlx_data->img, &mlx_data->bpp, &mlx_data->line_length, &mlx_data->endian);
}

void    init_fdf_map(t_mlx_data *mlx_data, char *filename)
{
	mlx_data->filename = filename;
	mlx_data->fdf_map = get_fdf_map(mlx_data->filename);
}

void	apply_default_view(t_map *map)
{
	map->scale = (WIDTH / 0.6) / (map->height + map->width) + map->scale_offset;
	map->offset_x = (WIDTH / 4);
	map->offset_y = (HEIGHT / 4);
}

t_mlx_data    *init_mlx_and_window_and_fdf_map(char *filename)
{
	t_mlx_data *mlx_data;

	mlx_data = init_mlx();
	if (!mlx_data)
	{
		ft_printf("COULDNT MLX");
		return (NULL);
	}
	init_image(mlx_data);
	if (!mlx_data->img)
	{
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
		free(mlx_data);
		ft_printf("COULDNT IMG");

		return (NULL);
	}
	init_fdf_map(mlx_data, filename);
	if (!mlx_data->fdf_map)
	{
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->img);
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
		free(mlx_data);
		ft_printf("COULDNT MAP");

		return (NULL);
	}
	apply_default_view(mlx_data->fdf_map);
	return (mlx_data);
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
	map->translate_y = -0;
	map->scale_offset = 0;
	map->height = get_map_height(map_name);
	map->array = malloc(sizeof(t_coord *) * map->height);
	map->rows_filled = 0;
	return (map);
}
