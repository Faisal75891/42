/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 21:37:13 by fbaras            #+#    #+#             */
/*   Updated: 2025/12/26 21:37:13 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	do_nothing(t_mlx_data *mlx_data)
{
	(void) mlx_data;
	return (0);
}

int	handle_exit(int keysym, t_mlx_data *mlx_data)
{
	if (keysym == 65307)
	{
		clear_image(mlx_data);
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->img);
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
		free_map(mlx_data->fdf_map);
		free(mlx_data->mlx_ptr);
		free(mlx_data);
		exit(0);
	}
	return (0);
}

static void	setup_hooks(t_mlx_data *mlx_data)
{
	mlx_loop_hook(mlx_data->mlx_ptr, &do_nothing, mlx_data);
	mlx_key_hook(mlx_data->win_ptr, &handle_events, mlx_data);
}

int	main(int argc, char **argv)
{
	t_mlx_data	*mlx_data;

	if (argc != 2)
		return (1);
	mlx_data = init_mlx_and_window_and_fdf_map(argv[1]);
	if (!mlx_data)
		return (1);
	draw_grid(mlx_data);
	setup_hooks(mlx_data);
	mlx_loop(mlx_data->mlx_ptr);
}
