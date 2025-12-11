/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 18:36:18 by fbaras            #+#    #+#             */
/*   Updated: 2025/12/11 21:34:25 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_exit(int keysym, t_mlx_data *mlx_data)
{
	if (keysym == 53)
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	ft_printf("key pressed: %d\n", keysym);
	return (0);
}

int	do_nothing (t_mlx_data *mlx_data)
{
	(void) mlx_data;
	return (0);
}

int	main(void)
{
	t_mlx_data	mlx_data;

	mlx_data.mlx_ptr = mlx_init();
	if (!mlx_data.mlx_ptr)
		return (1);
	mlx_data.win_ptr = mlx_new_window(mlx_data.mlx_ptr, HEIGHT, WIDTH, "sigma");
	if (mlx_data.win_ptr == NULL)
	{
		free(mlx_data.mlx_ptr);
		return (1);
	}

	mlx_loop_hook(mlx_data.mlx_ptr, &do_nothing, &mlx_data);
	mlx_key_hook(mlx_data.win_ptr, &handle_exit, &mlx_data);
	
	mlx_loop(mlx_data.mlx_ptr);
	mlx_destroy_window(mlx_data.mlx_ptr, mlx_data.win_ptr);
	free(mlx_data.mlx_ptr);
}
