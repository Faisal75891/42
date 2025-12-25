/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 22:48:32 by fbaras            #+#    #+#             */
/*   Updated: 2025/12/23 22:48:32 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	handle_panning(int keysym, t_mlx_data *mlx_data)
{
	if (keysym == 119)  // 'w' - move up
		mlx_data->fdf_map->translate_y -= 10;
	else if (keysym == 115)  // 's' - move down
		mlx_data->fdf_map->translate_y += 10;
	else if (keysym == 97)   // 'a' - move left
		mlx_data->fdf_map->translate_x -= 10;
	else if (keysym == 100)  // 'd' - move right (change from 'e')
		mlx_data->fdf_map->translate_x += 10;
	clear_image(mlx_data);
	draw_grid(mlx_data);
}

void	handle_rotate(int keysym, t_mlx_data *mlx_data)
{
	if (keysym == 65362)
		mlx_data->fdf_map->rotate_x += 10;
	else if (keysym == 65364)
		mlx_data->fdf_map->rotate_x -= 10;
	else if (keysym == 65361)
		mlx_data->fdf_map->rotate_y += 10;
	else if (keysym == 65363)
		mlx_data->fdf_map->rotate_y -= 10;
	else if (keysym == 122)
		mlx_data->fdf_map->rotate_z += 10;
	else if (keysym == 120)
		mlx_data->fdf_map->rotate_z -= 10;
	clear_image(mlx_data);
	draw_grid(mlx_data);
}

void	handle_scaling(int keysym, t_mlx_data *mlx_data)
{
	if (keysym == 101)
		mlx_data->fdf_map->scale_offset++;	
	else if (keysym == 113)
		mlx_data->fdf_map->scale_offset--;
	clear_image(mlx_data);
	draw_grid(mlx_data);
}
int	handle_events(int keysym, t_mlx_data *mlx_data)
{
	if (keysym == 65307)
		handle_exit(keysym, mlx_data);
	else if (is_scale(keysym))
		handle_scaling(keysym, mlx_data);
	else if (is_rotate(keysym))
		handle_rotate(keysym, mlx_data);
	else if (is_pan(keysym))
		handle_panning(keysym, mlx_data);
	return (0);
}
