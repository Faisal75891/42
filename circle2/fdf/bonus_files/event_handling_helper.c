/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbaras <fbaras@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 22:55:06 by fbaras            #+#    #+#             */
/*   Updated: 2025/12/23 22:55:06 by fbaras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	is_rotate(int keysym)
{
	return (keysym == 65362 || keysym == 65364
		|| keysym == 65361 || keysym == 65363
		|| keysym == 122 || keysym == 120);
}

int	is_scale(int keysym)
{
	return (keysym == 101 || keysym == 113);
}

int	is_pan(int keysym)
{
	return (keysym == 115 || keysym == 97 || keysym == 100 || keysym == 119);
}

#ifdef BONUS

void	setup_hooks(t_mlx_data *mlx_data)
{
	mlx_loop_hook(mlx_data->mlx_ptr, &do_nothing, mlx_data);
	mlx_key_hook(mlx_data->win_ptr, &handle_events, mlx_data);
}

#else

void	setup_hooks(t_mlx_data *mlx_data)
{
	mlx_loop_hook(mlx_data->mlx_ptr, &do_nothing, mlx_data);
	mlx_key_hook(mlx_data->win_ptr, &handle_exit, mlx_data);
}

#endif
