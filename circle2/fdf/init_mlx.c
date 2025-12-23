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

/*
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_coord
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_coord;

typedef struct s_map
{
	t_coord	**array;
	int		height;
	int		width;
	int		array_size;
	int		scale;
	int		offset_x;
	int		offset_y;
	int		scale_offset;
	float	rotate_x;
	float	rotate_y;
	float	rotate_z;
	int		translate_x;
	int		translate_y;
}	t_map;

typedef struct s_mlx_data
{
	void    *mlx_ptr;
	void    *win_ptr;
	t_map	*fdf_map;
	char	*filename;

	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}   t_mlx_data;

*/

void    init_mlx(t_mlx_data *mlx_data)
{
    mlx_data = malloc (sizeof(t_mlx_data));
	if (!mlx_data)
		return (1);
	mlx_data->mlx_ptr = mlx_init();
	if (!mlx_data->mlx_ptr)
		return (1);
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, WIDTH, HEIGHT, "sigma");
	if (mlx_data->win_ptr == NULL)
	{
		free(mlx_data->mlx_ptr);
		return (1);
	}
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
	if (!mlx_data->fdf_map->array)
    {
        // free something idk.
        // but id need to free everything.
        free(mlx_data);
        // probably exit and perror too
        // exit(1);
        return ;
    }
    // initialize some values
    mlx_data->fdf_map->scale = (WIDTH / 0.6) / (mlx_data->fdf_map->height + mlx_data->fdf_map->width) + mlx_data->fdf_map->scale_offset;
	mlx_data->fdf_map->offset_x = (WIDTH/ 2);
	mlx_data->fdf_map->offset_y = (HEIGHT / 2);
}

void    init_mlx_and_window_and_fdf_map(t_mlx_data *mlx_data, char *filename)
{
    init_mlx(mlx_data);
    init_image(mlx_data);
    init_fdf_map(mlx_data, filename);
}
