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
	t_mlx_data	*mlx_data;

	mlx_data = malloc (sizeof(t_mlx_data));
	if (!mlx_data)
		return (NULL);
	mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
		return (NULL);
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr,
			WIDTH, HEIGHT, "sigma");
	if (mlx_data->win_ptr == NULL)
	{
		free(mlx_data->mlx_ptr);
		return (NULL);
	}
	return (mlx_data);
}

// play arround with values
void	apply_default_view(t_map *map)
{
	int	initial_height;
	int	initial_width;

	initial_width = WIDTH;
	initial_height = -(HEIGHT / 4);
	map->scale = initial_width / (map->height + map->width) + map->scale_offset;
	map->offset_x = 0;
	map->offset_y = initial_height;
}

void	free_mlx_data(t_mlx_data *mlx_data)
{
	if (mlx_data->mlx_ptr && mlx_data->img)
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->img);
	if (mlx_data->mlx_ptr && mlx_data->win_ptr)
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	if (mlx_data->fdf_map)
		free_map(mlx_data->fdf_map);
	if (mlx_data->mlx_ptr)
		free(mlx_data->mlx_ptr);
	if (mlx_data)
		free(mlx_data);
}

t_mlx_data	*init_mlx_and_window_and_fdf_map(char *filename)
{
	t_mlx_data	*mlx_data;

	mlx_data = init_mlx();
	if (!mlx_data)
	{
		perror("mlx");
		return (NULL);
	}
	init_image(mlx_data);
	if (!mlx_data->img)
	{
		free_mlx_data(mlx_data);
		perror("image");
		return (NULL);
	}
	init_fdf_map(mlx_data, filename);
	if (!mlx_data->fdf_map)
	{
		free_mlx_data(mlx_data);
		perror("map");
		return (NULL);
	}
	apply_default_view(mlx_data->fdf_map);
	return (mlx_data);
}
